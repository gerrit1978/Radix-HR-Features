<?php
/**
 * @file
 * radix_hr_applicant_search.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function radix_hr_applicant_search_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'cv_search';
  $context->description = 'Resume (CV) search blocks';
  $context->tag = 'Radix';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'cvs' => 'cvs',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'facetapi-WL0kqei4KMLnhPjToM8QoegQ81LNt0Yq' => array(
          'module' => 'facetapi',
          'delta' => 'WL0kqei4KMLnhPjToM8QoegQ81LNt0Yq',
          'region' => 'content',
          'weight' => '-10',
        ),
        'facetapi-cP1XhxsueQ9wP41iDOFYvIH6Zn7ek6iE' => array(
          'module' => 'facetapi',
          'delta' => 'cP1XhxsueQ9wP41iDOFYvIH6Zn7ek6iE',
          'region' => 'content',
          'weight' => '-9',
        ),
        'facetapi-s11nW6SMC0RkefDyecCod10JLqE4Y3Z2' => array(
          'module' => 'facetapi',
          'delta' => 's11nW6SMC0RkefDyecCod10JLqE4Y3Z2',
          'region' => 'content',
          'weight' => '-8',
        ),
        'facetapi-RSyJnFUNWYW0ZwvUiWVJDs0XQFNY6bw7' => array(
          'module' => 'facetapi',
          'delta' => 'RSyJnFUNWYW0ZwvUiWVJDs0XQFNY6bw7',
          'region' => 'content',
          'weight' => '-7',
        ),
        'facetapi-h0ha0YGev69ZaTdv5GHvqXnUYYQlCaZb' => array(
          'module' => 'facetapi',
          'delta' => 'h0ha0YGev69ZaTdv5GHvqXnUYYQlCaZb',
          'region' => 'content',
          'weight' => '-6',
        ),
        'facetapi-IDC8lQzrEb1kt0SJbKXR0Qxzs0k6vWlv' => array(
          'module' => 'facetapi',
          'delta' => 'IDC8lQzrEb1kt0SJbKXR0Qxzs0k6vWlv',
          'region' => 'content',
          'weight' => '-5',
        ),
        'facetapi-0luSsbhlWYgSpGR1UFBLKm1lWTx8NnrV' => array(
          'module' => 'facetapi',
          'delta' => '0luSsbhlWYgSpGR1UFBLKm1lWTx8NnrV',
          'region' => 'content',
          'weight' => '-4',
        ),
        'facetapi-a6JyMIBhYqLNDBDn1zbIrwPB9mgrM6r6' => array(
          'module' => 'facetapi',
          'delta' => 'a6JyMIBhYqLNDBDn1zbIrwPB9mgrM6r6',
          'region' => 'content',
          'weight' => '-3',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Radix');
  t('Resume (CV) search blocks');
  $export['cv_search'] = $context;

  return $export;
}
