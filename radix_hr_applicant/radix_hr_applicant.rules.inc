<?php

/**
 * @file
 * Rules integration for BB HR Applicant (CV).
 */

/**
 * Implements hook_rules_condition_info().
 */
function radix_hr_applicant_rules_condition_info() {
  return array(
    'radix_hr_applicant_cv_complete' => array(
      'label' => t('The resume is complete'),
      'group' => t('BB HR Applicant'),
      'parameter' => array(
        'profile' => array(
          'label' => t('CV'),
          'description' => t('The resume (CV) that will be checked.'),
          'type' => 'profile2',
        ),
      ),
      'base' => 'radix_hr_applicant_cv_is_complete',
    ),
  );
}