<?php

/**
 * @file
 * Contains Drupal\contact_block\Plugin\Block\ContactBlock.
 */

namespace Drupal\contact_block\Plugin\Block;

use Drupal\Core\Access\AccessResult;
use Drupal\Core\Block\BlockBase;
use Drupal\Core\Entity\EntityFormBuilder;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Plugin\ContainerFactoryPluginInterface;
use Drupal\Core\Render\Renderer;
use Drupal\Core\Session\AccountInterface;
use Symfony\Component\DependencyInjection\ContainerInterface;
use Drupal\Core\Entity\EntityManager;
use Drupal\Core\Config\ConfigFactory;

/**
 * Provides a 'ContactBlock' block.
 *
 * @Block(
 *  id = "contact_block",
 *  admin_label = @Translation("Contact block"),
 * )
 */
class ContactBlock extends BlockBase implements ContainerFactoryPluginInterface {

  /**
   * The EntityManager.
   *
   * @var \Drupal\Core\Entity\EntityManager
   */
  protected $entityManager;

  /**
   * The ConfigFactory.
   *
   * @var \Drupal\Core\Config\ConfigFactory
   */
  protected $configFactory;

  /**
   * The EntityFormBuilder.
   *
   * @var \Drupal\Core\Entity\EntityFormBuilder
   */
  protected $entityFormBuilder;

  /**
   * The Renderer.
   *
   * @var \Drupal\Core\Render\Renderer
   */
  protected $renderer;

  /**
   * Constructor for ContactBlock block class.
   *
   * @param array $configuration
   *   A configuration array containing information about the plugin instance.
   * @param string $plugin_id
   *   The plugin_id for the plugin instance.
   * @param string $plugin_definition
   *   The plugin implementation definition.
   * @param EntityManager $entity_manager
   *   The entity manager.
   * @param ConfigFactory $config_factory
   *   The config factory.
   * @param EntityFormBuilder $entity_form_builder
   *   The entity form builder.
   * @param Renderer $renderer
   *   The renderer.
   */
  public function __construct(array $configuration, $plugin_id, $plugin_definition, EntityManager $entity_manager, ConfigFactory $config_factory, EntityFormBuilder $entity_form_builder, Renderer $renderer) {
    parent::__construct($configuration, $plugin_id, $plugin_definition);

    $this->entityManager = $entity_manager;
    $this->configFactory = $config_factory;
    $this->entityFormBuilder = $entity_form_builder;
    $this->renderer = $renderer;
  }

  /**
   * {@inheritdoc}
   */
  public static function create(ContainerInterface $container, array $configuration, $plugin_id, $plugin_definition) {
    return new static(
      $configuration,
      $plugin_id,
      $plugin_definition,
      $container->get('entity.manager'),
      $container->get('config.factory'),
      $container->get('entity.form_builder'),
      $container->get('renderer')
    );
  }

  /**
   * {@inheritdoc}
   */
  protected function blockAccess(AccountInterface $account) {

    $this->entity = $this->entityManager
      ->getStorage('contact_form')
      ->load($this->configuration['contact_form']);

    if (empty($this->entity)) {
      return AccessResult::forbidden();
    }
    else {
      return AccessResult::allowed();
    }
  }

  /**
   * {@inheritdoc}
   */
  public function defaultConfiguration() {
    return array(
      'label' => t('Contact block'),
      'contact_form' => 'personal',
    );
  }

  /**
   * {@inheritdoc}
   */
  public function blockForm($form, FormStateInterface $form_state) {

    $options = $this->entityManager
      ->getStorage('contact_form')
      ->loadMultiple();
    foreach ($options as $key => $option) {
      $options[$key] = $option->label();
    }

    $form['contact_form'] = array(
      '#type' => 'select',
      '#title' => $this->t('Contact form'),
      '#options' => $options,
      '#default_value' => $this->configuration['contact_form'],
      '#required' => TRUE,
    );

    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function blockSubmit($form, FormStateInterface $form_state) {
    $this->configuration['contact_form'] = $form_state->getValue('contact_form');
  }

  /**
   * {@inheritdoc}
   */
  public function build() {
    $form = array();
    $config = $this->configFactory->get('contact.settings');

    /** @var \Drupal\contact\Entity\ContactForm $contact_form */
    $contact_form = $this->entityManager
      ->getStorage('contact_form')
      ->load($this->configuration['contact_form']);

    if ($contact_form) {
      $message = $this->entityManager->getStorage('contact_message')
        ->create(['contact_form' => 'feedback']);

      $form = $this->entityFormBuilder->getForm($message);
      $form['#cache']['contexts'][] = 'user.permissions';
      $this->renderer->addCacheableDependency($form, $config);
    }

    return $form;
  }

}
