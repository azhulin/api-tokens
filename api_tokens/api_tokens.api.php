<?php

/**
 * @file
 * Hooks provided by the API-Tokens module.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Register API tokens
 *
 * Token example:
 *   [api:demo["param1", {"param2": {"inner1": "value1"}}]/]
 * Parameters part must be a valid JSON array.
 *
 * Extra spaces are allowed:
 *  [  api  :  demo  [  "param1"  ,   {  "param2"  :   {  "inner1"  :   "value1"  }  }  ]  /  ]
 *
 * @return
 *   Array of tokens to register.
 */
function hook_api_tokens_api_tokens_info() {
  $tokens = array();

  // Token key must be lowercase, may contain "a-z", "-", "_", ":"
  $tokens['demo'] = array(
    // Title of the token
    // If omitted, token key will be used
    // Optional
    'title' => t('Demo'),

    // Description of the token
    // Optional
    'description' => t('Demo API token description'),

    // Name of the token process function
    // Must be defined within the module or its include file
    // If omitted, will be set to [%module_name]_apitoken_[%token_name]
    // Optional
    'handler' => 'modulename_apitoken_demo',

    // Relative path to token process function without extension.
    // If omitted, means that the process function located in .module file
    // Optional
    'inc' => 'includes/handlers',

    // Number of required parameters of the process function
    // If omitted, api_tokens_param_info() will be used to determine number of required parameters
    // Optional
    'params' => 2,

    // Determines caching method for the output of the token process function
    // Allowed values:
    //   DRUPAL_NO_CACHE [default]
    //   DRUPAL_CACHE_PER_ROLE
    //   DRUPAL_CACHE_PER_USER
    //   DRUPAL_CACHE_PER_PAGE
    //   DRUPAL_CACHE_GLOBAL
    // If omitted, DRUPAL_NO_CACHE will be used
    // Optional
    'cache' => DRUPAL_CACHE_PER_PAGE | DRUPAL_CACHE_PER_ROLE,

    // Makes sence when cache is set to other then DRUPAL_NO_CACHE
    // Allowed values:
    //   CACHE_PERMANENT (0)
    //   CACHE_TEMPORARY (-1) [default]
    //   Cache lifetime number in seconds
    // If omitted, CACHE_TEMPORARY will be used
    // Optional
    'cache_expire' => 300, // 5 minutes
  );

  return $tokens;
}

/**
 * @} End of "addtogroup hooks".
 */

/**
 * Process function for the Demo API Token.
 */
function modulename_apitoken_demo($arg1, $arg2) {
  // Some processing
  // ...

  return $result;
}
