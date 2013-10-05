<?php
/**
 * @file
 * radix_hr_applicant.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function radix_hr_applicant_default_rules_configuration() {
  $items = array();
  $items['rules_cv_initialize'] = entity_import('rules_config', '{ "rules_cv_initialize" : {
      "LABEL" : "CV initialize",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_update" : [], "user_insert" : [] },
      "IF" : [
        { "user_has_role" : {
            "account" : [ "account" ],
            "roles" : { "value" : { "30037204" : "30037204", "115362423" : "115362423" } },
            "operation" : "OR"
          }
        },
        { "data_is_empty" : { "data" : [ "account:profile-cv" ] } }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : { "type" : "profile2", "param_type" : "cv", "param_user" : [ "account" ] },
            "PROVIDE" : { "entity_created" : { "cv" : "CV" } }
          }
        },
        { "entity_save" : { "data" : [ "cv" ], "immediate" : 1 } }
      ]
    }
  }');
  $items['rules_cv_set_label'] = entity_import('rules_config', '{ "rules_cv_set_label" : {
      "LABEL" : "CV Set label",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "profile2" ],
      "ON" : { "profile2_update" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "profile2:type" ], "value" : "cv" } },
        { "NOT data_is_empty" : { "data" : [ "profile2:field-cv-job-preferences" ] } },
        { "NOT data_is" : {
            "data" : [ "profile2:label" ],
            "value" : [ "profile2:field-cv-job-preferences:field-cv-pref-desired-job-title" ]
          }
        }
      ],
      "DO" : [
        { "data_set" : {
            "data" : [ "profile2:label" ],
            "value" : [ "profile2:field-cv-job-preferences:field-cv-pref-desired-job-title" ]
          }
        }
      ]
    }
  }');
  $items['rules_cv_update_status'] = entity_import('rules_config', '{ "rules_cv_update_status" : {
      "LABEL" : "CV update status",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "radix_hr_applicant", "profile2" ],
      "ON" : { "profile2_update" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "profile2:type" ], "value" : "cv" } },
        { "data_is" : { "data" : [ "profile2:field-cv-state" ], "value" : "incomplete" } },
        { "radix_hr_applicant_cv_complete" : { "profile" : [ "profile2" ] } }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "profile2:field-cv-state" ], "value" : "visible" } },
        { "drupal_message" : { "message" : "All required fields have been completed. The public data of your resume is now visible to recruiters." } }
      ]
    }
  }');
  return $items;
}
