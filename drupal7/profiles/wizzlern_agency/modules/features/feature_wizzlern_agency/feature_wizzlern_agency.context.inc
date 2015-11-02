<?php
/**
 * @file
 * feature_wizzlern_agency.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function feature_wizzlern_agency_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'frontpage';
  $context->description = '';
  $context->tag = 'General';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-service_frontpage-block' => array(
          'module' => 'views',
          'delta' => 'service_frontpage-block',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-portfolio_frontpage-block' => array(
          'module' => 'views',
          'delta' => 'portfolio_frontpage-block',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-about_frontpage-block' => array(
          'module' => 'views',
          'delta' => 'about_frontpage-block',
          'region' => 'content',
          'weight' => '-8',
        ),
        'views-team_frontpage-block' => array(
          'module' => 'views',
          'delta' => 'team_frontpage-block',
          'region' => 'content',
          'weight' => '-7',
        ),
        'contact_form_blocks-0' => array(
          'module' => 'contact_form_blocks',
          'delta' => '0',
          'region' => 'content',
          'weight' => '-6',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('General');
  $export['frontpage'] = $context;

  return $export;
}
