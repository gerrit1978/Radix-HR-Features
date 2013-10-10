<?php
/**
 * @file
 * radix_hr_job_search.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function radix_hr_job_search_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'use search_api_saved_searches'.
  $permissions['use search_api_saved_searches'] = array(
    'name' => 'use search_api_saved_searches',
    'roles' => array(
      'administrator' => 'administrator',
      'applicant' => 'applicant',
      'recruiter' => 'recruiter',
    ),
    'module' => 'search_api_saved_searches',
  );

  return $permissions;
}
