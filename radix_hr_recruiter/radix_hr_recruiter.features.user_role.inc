<?php
/**
 * @file
 * radix_hr_recruiter.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function radix_hr_recruiter_user_default_roles() {
  $roles = array();

  // Exported role: recruiter.
  $roles['recruiter'] = array(
    'name' => 'recruiter',
    'weight' => 4,
    'machine_name' => 'recruiter',
  );

  return $roles;
}
