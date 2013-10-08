<?php
/**
 * @file
 * radix_hr_applicant_search.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function radix_hr_applicant_search_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'cvs';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_cv_index';
  $view->human_name = 'CVs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'CVs';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    30037204 => '30037204',
    100482362 => '100482362',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Opnieuw instellen';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* Veld: Indexed Profiel: Profiel ID */
  $handler->display->display_options['fields']['pid']['id'] = 'pid';
  $handler->display->display_options['fields']['pid']['table'] = 'search_api_index_cv_index';
  $handler->display->display_options['fields']['pid']['field'] = 'pid';
  /* Filter criterion: Indexed Profiel: CV status */
  $handler->display->display_options['filters']['field_cv_state']['id'] = 'field_cv_state';
  $handler->display->display_options['filters']['field_cv_state']['table'] = 'search_api_index_cv_index';
  $handler->display->display_options['filters']['field_cv_state']['field'] = 'field_cv_state';
  $handler->display->display_options['filters']['field_cv_state']['value'] = array(
    'visible' => 'visible',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/recruiter/search/cv';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'CVs zoeken';
  $handler->display->display_options['menu']['weight'] = '100';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['cvs'] = array(
    t('Master'),
    t('CVs'),
    t('more'),
    t('Apply'),
    t('Opnieuw instellen'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Profiel ID'),
    t('.'),
    t(','),
    t('Page'),
  );
  $export['cvs'] = $view;

  return $export;
}
