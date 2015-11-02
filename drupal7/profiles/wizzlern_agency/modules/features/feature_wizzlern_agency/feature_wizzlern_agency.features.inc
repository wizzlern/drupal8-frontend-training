<?php
/**
 * @file
 * feature_wizzlern_agency.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_wizzlern_agency_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function feature_wizzlern_agency_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function feature_wizzlern_agency_image_default_styles() {
  $styles = array();

  // Exported image style: about_round.
  $styles['about_round'] = array(
    'name' => 'about_round',
    'label' => 'About - round',
    'effects' => array(
      2 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 156,
          'height' => 156,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: portfolio_frontpage.
  $styles['portfolio_frontpage'] = array(
    'name' => 'portfolio_frontpage',
    'label' => 'Portfolio frontpage',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 360,
          'height' => 260,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: team_member_front.
  $styles['team_member_front'] = array(
    'name' => 'team_member_front',
    'label' => 'Team member frontpage',
    'effects' => array(
      3 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 239,
          'height' => 239,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function feature_wizzlern_agency_node_info() {
  $items = array(
    'about' => array(
      'name' => t('About us'),
      'base' => 'node_content',
      'description' => t('A historical episode About Us'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'portfolio' => array(
      'name' => t('Portfolio'),
      'base' => 'node_content',
      'description' => t('Portfolio item'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'services' => array(
      'name' => t('Services'),
      'base' => 'node_content',
      'description' => t('Our sevices'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'team' => array(
      'name' => t('Team member'),
      'base' => 'node_content',
      'description' => t('Our team member'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}
