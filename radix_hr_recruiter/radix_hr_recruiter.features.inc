<?php
/**
 * @file
 * radix_hr_recruiter.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function radix_hr_recruiter_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function radix_hr_recruiter_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function radix_hr_recruiter_flag_default_flags() {
  $flags = array();
  // Exported flag: "CV Bookmarks".
  $flags['cv_bookmarks'] = array(
    'entity_type' => 'profile2',
    'title' => 'CV Bookmarks',
    'global' => 0,
    'types' => array(
      0 => 'cv',
    ),
    'flag_short' => 'Bookmark CV',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Unmark CV',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'account' => 'account',
      'page' => 'page',
      'teaser' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'api_version' => 3,
    'module' => 'radix_hr_recruiter',
    'locked' => array(
      0 => 'name',
    ),
  );
  return $flags;

}

/**
 * Implements hook_default_rules_link().
 */
function radix_hr_recruiter_default_rules_link() {
  $items = array();
  $items['job_application_reject'] = entity_import('rules_link', '{
    "settings" : {
      "text" : "Reject application",
      "link_type" : "confirm",
      "bundles" : { "application" : "application" },
      "entity_link" : 1,
      "confirm_question" : "Reject application",
      "confirm_description" : ""
    },
    "name" : "job_application_reject",
    "label" : "Job application Reject",
    "path" : "job_application_reject",
    "entity_type" : "node",
    "rdf_mapping" : []
  }');
  $items['job_application_shortlist'] = entity_import('rules_link', '{
    "settings" : {
      "text" : "Shortlist Application",
      "link_type" : "token",
      "bundles" : { "application" : "application" },
      "entity_link" : 1
    },
    "name" : "job_application_shortlist",
    "label" : "Job Application Shortlist",
    "path" : "job_application_shortlist",
    "entity_type" : "node",
    "rdf_mapping" : []
  }');
  $items['job_publish'] = entity_import('rules_link', '{
    "settings" : {
      "text" : "Publish",
      "link_type" : "confirm",
      "bundles" : { "job" : "job" },
      "entity_link" : 1,
      "confirm_question" : "Are you sure?",
      "confirm_description" : "This job will be published."
    },
    "name" : "job_publish",
    "label" : "Job Publish",
    "path" : "job_publish",
    "entity_type" : "node",
    "rdf_mapping" : []
  }');
  $items['job_unpublish'] = entity_import('rules_link', '{
    "settings" : {
      "text" : "Unpublish",
      "link_type" : "confirm",
      "bundles" : { "job" : "job" },
      "entity_link" : 1,
      "confirm_question" : "Are you sure?",
      "confirm_description" : "This job will be unpublished."
    },
    "name" : "job_unpublish",
    "label" : "Job Unpublish",
    "path" : "job_unpublish",
    "entity_type" : "node",
    "rdf_mapping" : []
  }');
  return $items;
}
