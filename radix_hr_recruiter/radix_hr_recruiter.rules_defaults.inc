<?php
/**
 * @file
 * radix_hr_recruiter.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function radix_hr_recruiter_default_rules_configuration() {
  $items = array();
  $items['rules_link_condition_job_application_reject'] = entity_import('rules_config', '{ "rules_link_condition_job_application_reject" : {
      "LABEL" : "Rules link: Job application reject condition",
      "PLUGIN" : "and",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "AND" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "application" : "application" } }
          }
        },
        { "NOT data_is" : { "data" : [ "node:field-application-state" ], "value" : "rejected" } },
        { "OR" : [
            { "user_has_role" : {
                "account" : [ "site:current-user" ],
                "roles" : { "value" : { "30037204" : "30037204" } }
              }
            },
            { "data_is" : {
                "data" : [ "site:current-user" ],
                "value" : [ "node:field-application-job-ref:author" ]
              }
            }
          ]
        }
      ]
    }
  }');
  $items['rules_link_condition_job_application_shortlist'] = entity_import('rules_config', '{ "rules_link_condition_job_application_shortlist" : {
      "LABEL" : "Rules link: Job Application Shortlist condition",
      "PLUGIN" : "and",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "AND" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "application" : "application" } }
          }
        },
        { "NOT data_is" : { "data" : [ "node:field-application-state" ], "value" : "shortlisted" } },
        { "OR" : [
            { "user_has_role" : {
                "account" : [ "site:current-user" ],
                "roles" : { "value" : { "30037204" : "30037204" } }
              }
            },
            { "data_is" : {
                "data" : [ "node:field-application-job-ref:author" ],
                "value" : [ "site:current-user" ]
              }
            }
          ]
        }
      ]
    }
  }');
  $items['rules_link_condition_job_publish'] = entity_import('rules_config', '{ "rules_link_condition_job_publish" : {
      "LABEL" : "Rules link: Job Publish condition",
      "PLUGIN" : "and",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "AND" : [
        { "OR" : [
            { "user_has_role" : {
                "account" : [ "site:current-user" ],
                "roles" : { "value" : { "30037204" : "30037204" } }
              }
            },
            { "AND" : [
                { "user_has_role" : {
                    "account" : [ "site:current-user" ],
                    "roles" : { "value" : { "100482362" : "100482362" } }
                  }
                },
                { "data_is" : { "data" : [ "node:author" ], "value" : [ "site:current-user" ] } }
              ]
            }
          ]
        },
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "job" : "job" } } } },
        { "data_is" : { "data" : [ "node:field-job-workflow-state" ], "value" : "unpublished" } }
      ]
    }
  }');
  $items['rules_link_condition_job_unpublish'] = entity_import('rules_config', '{ "rules_link_condition_job_unpublish" : {
      "LABEL" : "Rules link: Job Unpublish condition",
      "PLUGIN" : "and",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "AND" : [
        { "OR" : [
            { "user_has_role" : {
                "account" : [ "site:current-user" ],
                "roles" : { "value" : { "30037204" : "30037204" } }
              }
            },
            { "AND" : [
                { "user_has_role" : {
                    "account" : [ "site:current-user" ],
                    "roles" : { "value" : { "100482362" : "100482362" } }
                  }
                },
                { "data_is" : { "data" : [ "node:author" ], "value" : [ "site:current-user" ] } }
              ]
            }
          ]
        },
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "job" : "job" } } } },
        { "data_is" : { "data" : [ "node:field-job-workflow-state" ], "value" : "published" } }
      ]
    }
  }');
  $items['rules_link_set_job_application_reject'] = entity_import('rules_config', '{ "rules_link_set_job_application_reject" : {
      "LABEL" : "Rules link: Job application Reject rules set",
      "PLUGIN" : "rule set",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "type" : "node", "label" : "node" } },
      "RULES" : [
        { "RULE" : {
            "IF" : [
              { "node_is_of_type" : {
                  "node" : [ "node" ],
                  "type" : { "value" : { "application" : "application" } }
                }
              }
            ],
            "DO" : [
              { "data_set" : { "data" : [ "node:field-application-state" ], "value" : "rejected" } },
              { "drupal_message" : { "message" : "Application has been rejected.", "repeat" : 0 } }
            ],
            "LABEL" : "Set to rejected"
          }
        }
      ]
    }
  }');
  $items['rules_link_set_job_application_shortlist'] = entity_import('rules_config', '{ "rules_link_set_job_application_shortlist" : {
      "LABEL" : "Rules link: Job Application Shortlist rules set",
      "PLUGIN" : "rule set",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "type" : "node", "label" : "node" } },
      "RULES" : [
        { "RULE" : {
            "IF" : [
              { "node_is_of_type" : {
                  "node" : [ "node" ],
                  "type" : { "value" : { "application" : "application" } }
                }
              }
            ],
            "DO" : [
              { "data_set" : { "data" : [ "node:field-application-state" ], "value" : "shortlisted" } },
              { "drupal_message" : { "message" : "This application has been shortlisted." } }
            ],
            "LABEL" : "Set to shortlisted"
          }
        }
      ]
    }
  }');
  $items['rules_link_set_job_publish'] = entity_import('rules_config', '{ "rules_link_set_job_publish" : {
      "LABEL" : "Rules link: Job Publish rules set",
      "PLUGIN" : "rule set",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "type" : "node", "label" : "node" } },
      "RULES" : [
        { "RULE" : {
            "IF" : [
              { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "job" : "job" } } } }
            ],
            "DO" : [
              { "drupal_message" : { "message" : "Job will be published" } },
              { "data_set" : { "data" : [ "node:field-job-workflow-state" ], "value" : "published" } }
            ],
            "LABEL" : "Publish Job"
          }
        }
      ]
    }
  }');
  $items['rules_link_set_job_unpublish'] = entity_import('rules_config', '{ "rules_link_set_job_unpublish" : {
      "LABEL" : "Rules link: Job Unpublish rules set",
      "PLUGIN" : "rule set",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "type" : "node", "label" : "node" } },
      "RULES" : [
        { "RULE" : {
            "IF" : [
              { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "job" : "job" } } } }
            ],
            "DO" : [
              { "drupal_message" : { "message" : "Job will be unpublished" } },
              { "data_set" : { "data" : [ "node:field-job-workflow-state" ], "value" : "unpublished" } }
            ],
            "LABEL" : "Unpublish Job"
          }
        }
      ]
    }
  }');
  return $items;
}
