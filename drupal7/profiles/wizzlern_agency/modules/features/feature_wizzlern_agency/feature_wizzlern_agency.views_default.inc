<?php
/**
 * @file
 * feature_wizzlern_agency.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_wizzlern_agency_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'about_frontpage';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'About frontpage';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'About';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'timeline';
  $handler->display->display_options['style_options']['wrapper_class'] = 'col-lg-12';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Hidden: Subtitle */
  $handler->display->display_options['fields']['field__subtitle']['id'] = 'field__subtitle';
  $handler->display->display_options['fields']['field__subtitle']['table'] = 'field_data_field__subtitle';
  $handler->display->display_options['fields']['field__subtitle']['field'] = 'field__subtitle';
  $handler->display->display_options['fields']['field__subtitle']['ui_name'] = 'Hidden: Subtitle';
  $handler->display->display_options['fields']['field__subtitle']['label'] = '';
  $handler->display->display_options['fields']['field__subtitle']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field__subtitle']['element_label_colon'] = FALSE;
  /* Field: Hidden: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Hidden: Title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Hidden: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['ui_name'] = 'Hidden: Body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_about_image']['id'] = 'field_about_image';
  $handler->display->display_options['fields']['field_about_image']['table'] = 'field_data_field_about_image';
  $handler->display->display_options['fields']['field_about_image']['field'] = 'field_about_image';
  $handler->display->display_options['fields']['field_about_image']['label'] = '';
  $handler->display->display_options['fields']['field_about_image']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_about_image']['element_class'] = 'timeline-image';
  $handler->display->display_options['fields']['field_about_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_about_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_about_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_about_image']['settings'] = array(
    'image_style' => 'about_round',
    'image_link' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="timeline-panel">
  <div class="timeline-heading">
    <h4>[field__subtitle]</h4>
    <h4 class="subheading">[title]</h4>
  </div>
  <div class="timeline-body text-muted">
    [body]
  </div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'about' => 'about',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['about_frontpage'] = $view;

  $view = new view();
  $view->name = 'portfolio_frontpage';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Portfolio frontpage';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Portfolio';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'col-md-4 col-sm-6 portfolio-item';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Hidden: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Hidden: Title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Hidden: Subtitle */
  $handler->display->display_options['fields']['field__subtitle']['id'] = 'field__subtitle';
  $handler->display->display_options['fields']['field__subtitle']['table'] = 'field_data_field__subtitle';
  $handler->display->display_options['fields']['field__subtitle']['field'] = 'field__subtitle';
  $handler->display->display_options['fields']['field__subtitle']['ui_name'] = 'Hidden: Subtitle';
  $handler->display->display_options['fields']['field__subtitle']['label'] = '';
  $handler->display->display_options['fields']['field__subtitle']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field__subtitle']['element_label_colon'] = FALSE;
  /* Field: Content: Screenshot */
  $handler->display->display_options['fields']['field_portfolio_screenshot']['id'] = 'field_portfolio_screenshot';
  $handler->display->display_options['fields']['field_portfolio_screenshot']['table'] = 'field_data_field_portfolio_screenshot';
  $handler->display->display_options['fields']['field_portfolio_screenshot']['field'] = 'field_portfolio_screenshot';
  $handler->display->display_options['fields']['field_portfolio_screenshot']['label'] = '';
  $handler->display->display_options['fields']['field_portfolio_screenshot']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_portfolio_screenshot']['alter']['text'] = '<div class="portfolio-link">
  <div class="portfolio-hover">
    <div class="portfolio-hover-content">
      <i class="fa fa-plus fa-3x"></i>
    </div>
  </div>
  [field_portfolio_screenshot]
</div>';
  $handler->display->display_options['fields']['field_portfolio_screenshot']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_portfolio_screenshot']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_portfolio_screenshot']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_portfolio_screenshot']['settings'] = array(
    'image_style' => 'portfolio_frontpage',
    'image_link' => '',
  );
  /* Field: Custom: Portfolio caption */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Custom: Portfolio caption';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="portfolio-caption">
  <h4>[title]</h4>
  <p class="text-muted">[field__subtitle]</p>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'portfolio' => 'portfolio',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['portfolio_frontpage'] = $view;

  $view = new view();
  $view->name = 'service_frontpage';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Service frontpage';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Services';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'col-md-4';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Social icons */
  $handler->display->display_options['fields']['field__font']['id'] = 'field__font';
  $handler->display->display_options['fields']['field__font']['table'] = 'field_data_field__font';
  $handler->display->display_options['fields']['field__font']['field'] = 'field__font';
  $handler->display->display_options['fields']['field__font']['label'] = '';
  $handler->display->display_options['fields']['field__font']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'services' => 'services',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['service_frontpage'] = $view;

  $view = new view();
  $view->name = 'team_frontpage';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Our team frontpage';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Our amazing team';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'col-sm-4';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: HIdden: Image */
  $handler->display->display_options['fields']['field_team_image']['id'] = 'field_team_image';
  $handler->display->display_options['fields']['field_team_image']['table'] = 'field_data_field_team_image';
  $handler->display->display_options['fields']['field_team_image']['field'] = 'field_team_image';
  $handler->display->display_options['fields']['field_team_image']['ui_name'] = 'HIdden: Image';
  $handler->display->display_options['fields']['field_team_image']['label'] = '';
  $handler->display->display_options['fields']['field_team_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_team_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_team_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_team_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_team_image']['settings'] = array(
    'image_style' => 'team_member_front',
    'image_link' => '',
  );
  /* Field: Hidden: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Hidden: Title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Hidden: Occupation */
  $handler->display->display_options['fields']['field__subtitle']['id'] = 'field__subtitle';
  $handler->display->display_options['fields']['field__subtitle']['table'] = 'field_data_field__subtitle';
  $handler->display->display_options['fields']['field__subtitle']['field'] = 'field__subtitle';
  $handler->display->display_options['fields']['field__subtitle']['ui_name'] = 'Hidden: Occupation';
  $handler->display->display_options['fields']['field__subtitle']['label'] = '';
  $handler->display->display_options['fields']['field__subtitle']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field__subtitle']['element_type'] = 'p';
  $handler->display->display_options['fields']['field__subtitle']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field__subtitle']['element_default_classes'] = FALSE;
  /* Field: Hidden: Social icons */
  $handler->display->display_options['fields']['field__font']['id'] = 'field__font';
  $handler->display->display_options['fields']['field__font']['table'] = 'field_data_field__font';
  $handler->display->display_options['fields']['field__font']['field'] = 'field__font';
  $handler->display->display_options['fields']['field__font']['ui_name'] = 'Hidden: Social icons';
  $handler->display->display_options['fields']['field__font']['label'] = '';
  $handler->display->display_options['fields']['field__font']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field__font']['element_label_colon'] = FALSE;
  /* Field: Custom: Team member */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Custom: Team member';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="team-member">
  [field_team_image]
  <h4>[title]</h4>
  <p class="text-muted">[field__subtitle]</p>
  [field__font]
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'team' => 'team',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['team_frontpage'] = $view;

  return $export;
}
