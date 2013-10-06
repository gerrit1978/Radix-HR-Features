<?php
/**
 * @file
 * radix_hr_application.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function radix_hr_application_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function radix_hr_application_node_info() {
  $items = array(
    'application' => array(
      'name' => t('Sollicitatie'),
      'base' => 'node_content',
      'description' => t('Een sollicitatie.'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  return $items;
}
