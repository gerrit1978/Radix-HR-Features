<?php
/**
 * @file
 * radix_hr_applicant_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function radix_hr_applicant_search_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function radix_hr_applicant_search_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_index().
 */
function radix_hr_applicant_search_default_search_api_index() {
  $items = array();
  $items['cv_index'] = entity_import('search_api_index', '{
    "name" : "CV index",
    "machine_name" : "cv_index",
    "description" : null,
    "server" : "db_server",
    "item_type" : "profile2",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "field_cv_state" : { "type" : "string" },
        "search_api_language" : { "type" : "string" },
        "search_api_viewed" : { "type" : "text" },
        "field_cv_job_preferences:field_cv_pref_career_status" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_cv_job_preferences:field_cv_pref_field_of_work" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_cv_work_experience:field_cv_pref_field_of_work" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_cv_work_experience:field_cv_workxp_company_name" : { "type" : "list\\u003Cstring\\u003E" },
        "field_cv_education:field_cv_edu_field_of_study:parents_all" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_cv_languages:field_cv_languages_language:term" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_cv_general_skills:field_cv_gen_skills_skills_level:term:parents_all" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_cv_it_skills:field_cv_it_skills_skills_level:term:parents_all" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : { "default" : "0", "bundles" : { "cv" : "cv" } }
        },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 1, "weight" : "0", "settings" : { "mode" : "page" } },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : { "status" : 1, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : { "search_api_viewed" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : { "fields" : [], "spaces" : "[^[:alnum:]]", "ignorable" : "[\\u0027]" }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : [],
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}
