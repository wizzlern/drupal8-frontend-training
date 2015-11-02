<?php

/**
 * @file
 * Preprocessors and hook implementations for the agency theme.
 */

/**
 * Implements hook_preprocess_html().
 */
function agency_preprocess_html(&$variables) {

  // Add body class and body ID.
  $variables['attributes_array']['id'] = 'page-top';
  $variables['classes_array'][] = 'index';
}

/**
 * Implements hook_preprocess().
 */
function agency_preprocess(&$variables) {

  // Add meta tags.
  $metatags = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'http-equiv' => 'X-UA-Compatible',
      'content' => 'IE=edge',
    ),
  );
  drupal_add_html_head($metatags, 'my_meta');

  // Add external scripts.
  drupal_add_js('http://cdnjs.cloudflare.com/ajax/libs/jquery-easing/1.3/jquery.easing.min.js', 'external');
  drupal_add_js('http://cdnjs.cloudflare.com/ajax/libs/jquery-easing/1.3/jquery.easing.min.js', 'external');
  drupal_add_js('http://cdnjs.cloudflare.com/ajax/libs/jquery-easing/1.3/jquery.easing.min.js', 'external');
  drupal_add_js('http://cdnjs.cloudflare.com/ajax/libs/jquery-easing/1.3/jquery.easing.min.js', 'external');
  drupal_add_js('http://cdnjs.cloudflare.com/ajax/libs/jquery-easing/1.3/jquery.easing.min.js', 'external');

  // Add external stylesheets.
  drupal_add_css('http://fonts.googleapis.com/css?family=Montserrat:400,700', 'external');
  drupal_add_css('http://fonts.googleapis.com/css?family=Kaushan+Script', 'external');
  drupal_add_css('http://fonts.googleapis.com/css?family=Droid+Serif:400,700,400italic,700italic', 'external');
  drupal_add_css('http://fonts.googleapis.com/css?family=Roboto+Slab:400,100,300,700', 'external');

  // Add style sheet for authenticated users.
  if ($variables['logged_in']) {
    drupal_add_css(drupal_get_path('theme', 'agency') . '/css/agency-authenticated.css', array('group' => CSS_THEME));
  }
}

/**
 * Implements hook_preprocess_page().
 */
function agency_preprocess_page(&$variables) {
  // Remove the default 'no content' message.
  unset($variables['page']['content']['system_main']['default_message']);

  // Add Tell me more link.
  $variables['tell_more_link'] = l(
    t('Tell Me More'),
    '#services',
    array('attributes' => array(
      'class' => array(
        'page-scroll',
        'btn',
        'btn-xl'
      ),
    ))
  );
}

/**
 * Overrides theme_menu_tree().
 */
function agency_menu_tree($variables) {
  // This overrides all menu trees, but luckily this design only uses one.
  return '<ul class="nav navbar-nav navbar-right">' . $variables['tree'] . '</ul>';
}

/**
 * Overrides theme_menu_link().
 *
 * Hard code the link class.
 */
function agency_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li class="page-scroll">' . $output . $sub_menu . "</li>\n";
}

/**
 * Implements hook_js_alter().
 */
function agency_js_alter(&$javascript) {

  $path = drupal_get_path('theme', 'agency');
  $footer_scripts = array(
    $path . '/js/bootstrap.min.js',
    $path . '/js/classie.js',
    $path . '/js/cbpAnimatedHeader.min.js',
    $path . '/js/jqBootstrapValidation.js]',
    $path . '/js/agency.js',
    'http://cdnjs.cloudflare.com/ajax/libs/jquery-easing/1.3/jquery.easing.min.js',
  );

  // Place all specified scripts in the footer.
  foreach (array_keys($javascript) as $key) {
    if (in_array($key, $footer_scripts)) {
      $javascript[$key]['scope'] = 'footer';
    }
  }
}

/**
 * Implements hook_preprocess_views_view_list().
 */
function agency_preprocess_views_view_list(&$variables) {

  // Add a static last item to the 'About us' list.
  if ($variables['view']->name == 'about_frontpage') {
    $variables['rows'][] = '<div class="timeline-image"><h4>' . t('Be Part<br />Of Our<br />Story!') . '</h4></div>';
    $variables['classes_array'][] = 'timeline-inverted';
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function agency_form_contact_site_form_alter(&$form, $form_state) {

  // Add wrapper divs for form layout.
  $form['name']['#prefix'] = '<div class="row"><div class="col-md-6">';
  $form['mail']['#suffix'] = '</div>';
  $form['message']['#prefix'] = '<div class="col-md-6">';
  $form['message']['#suffix'] = '</div></div>';

  // Changes to message field.
  $form['message']['#resizable'] = FALSE;

  // Hide the field labels.
  // Note that '#title_display' must be set at the lowest child level.
  $form['name']['#title_display'] = 'invisible';
  $form['mail']['#title_display'] = 'invisible';
  $form['message']['#title_display'] = 'invisible';
  $form['message']['#title'] = t('Your message');

  // Hide subject and copy fields.
  $form['subject']['#access'] = FALSE;
  $form['copy']['#access'] = FALSE;
  $form['copy']['#default_value'] = 1;

  // Add classes for button style.
  $form['actions']['#attributes']['class'][] = 'col-lg-12';
  $form['actions']['#attributes']['class'][] = 'text-center';
  $form['actions']['submit']['#attributes']['class'][] = 'btn';
  $form['actions']['submit']['#attributes']['class'][] = 'btn-xl';
}

/**
 * Overrides theme_form_element().
 *
 * Replace the form-* classes.
 */
function agency_form_element(&$variables) {
  $element = &$variables['element'];

  // This function is invoked as theme wrapper, but the rendered form element
  // may not necessarily have been processed by form_builder().
  $element += array(
    '#title_display' => 'before',
  );

  // Add element #id for #type 'item'.
  if (isset($element['#markup']) && !empty($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  // Add element's #type and #name as class to aid with JS/CSS selectors.
/* --- Start changes --- */
  $attributes['class'] = array('form-group');
//  $attributes['class'] = array('form-item');
//  if (!empty($element['#type'])) {
//    $attributes['class'][] = 'form-type-' . strtr($element['#type'], '_', '-');
//  }
//  if (!empty($element['#name'])) {
//    $attributes['class'][] = 'form-item-' . strtr($element['#name'], array(' ' => '-', '_' => '-', '[' => '-', ']' => ''));
//  }
  /* --- End changes --- */
  // Add a class for disabled elements to facilitate cross-browser styling.
  if (!empty($element['#attributes']['disabled'])) {
    $attributes['class'][] = 'form-disabled';
  }
  $output = '<div' . drupal_attributes($attributes) . '>' . "\n";

  // If #title is not set, we don't display any label or required marker.
  if (!isset($element['#title'])) {
    $element['#title_display'] = 'none';
  }
  $prefix = isset($element['#field_prefix']) ? '<span class="field-prefix">' . $element['#field_prefix'] . '</span> ' : '';
  $suffix = isset($element['#field_suffix']) ? ' <span class="field-suffix">' . $element['#field_suffix'] . '</span>' : '';

  switch ($element['#title_display']) {
    case 'before':
    case 'invisible':
      $output .= ' ' . theme('form_element_label', $variables);
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;

    case 'after':
      $output .= ' ' . $prefix . $element['#children'] . $suffix;
      $output .= ' ' . theme('form_element_label', $variables) . "\n";
      break;

    case 'none':
    case 'attribute':
      // Output no label and no required marker, only the children.
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;
  }

  if (!empty($element['#description'])) {
    $output .= '<div class="description">' . $element['#description'] . "</div>\n";
  }

  $output .= "</div>\n";

  return $output;
}

/**
 * Implements hook_preprocess_input().
 */
function agency_preprocess_textfield(&$variables) {

  // Set attributes and classes.
  _agency_modify_input_elements($variables);
}

/**
 * Implements hook_preprocess_textarea().
 */
function agency_preprocess_textarea(&$variables) {

  // Set attributes and classes.
  _agency_modify_input_elements($variables);
}

/**
 * Modifies form input fields for styling and usability.
 *
 * @param $variables
 *   Array of form element values.
 */
function _agency_modify_input_elements(&$variables) {

  // Add class for styling.
  $variables['element']['#attributes']['class'][] = 'form-control';

  // When the field label is hidden, add placeholder attribute for in-field label.
  if ($variables['element']['#title_display'] == 'invisible') {
    if ($variables['element']['#required'] == TRUE) {
      $variables['element']['#attributes']['placeholder'] = t('!label *', array('!label' => $variables['element']['#title']));
    }
    else {
      $variables['element']['#attributes']['placeholder'] = $variables['element']['#title'];
    }
  }
}

