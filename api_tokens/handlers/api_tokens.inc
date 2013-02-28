<?php


function _api_tokens_api_tokens_info() {
  $tokens = array(
    'link' => array(
      'title' => t('Link'),
      'handler' => 'api_tokens_apitoken_link',
      'inc' => 'handlers/api_tokens',
      'params' => 1,
      // no sense to cache lightweight or dynamic handlers
      'cache' => DRUPAL_NO_CACHE,
    ),
  );

  return $tokens;
}


function api_tokens_apitoken_link($url, $title = FALSE) {
  $content = '<a href="' . $url . '">' . ($title ? $title : $url) . '</a>';

  return $content;
}
