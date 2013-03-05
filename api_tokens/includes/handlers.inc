<?php


/**
 * Implements hook_api_tokens_info().
 *
 * Escaped with "_" because it will be called directly.
 *
 * @return
 *   Array of tokens to register.
 */
function _api_tokens_api_tokens_info() {
  $tokens = array();

  $tokens['link'] = array(
    'title' => t('Link'),
    'description' => t('Renders a link'),
    'inc' => 'includes/api_tokens',
    'params' => 2,
  );

  return $tokens;
}


/**
 * Process function of the Link API Token.
 *
 * Token example: [api:link["Test", "node/1", {}, true]/]
 * Result: <a href="http://api-tokens-dev.localhost:8082/content/test">Test</a>
 *
 * Token example: [api:link["Drupal", "http://drupal.org", {"attributes": {"target": "_blank", "class": ["button"]}}]/]
 * Result: <a class="button" target="_blank" href="http://drupal.org">Drupal</a>
 *
 * @param string $text
 *   Not translated link text for the anchor tag.
 * @param string $path
 *   The same as for l() function.
 * @param array $options
 *   The same as for l() function.
 * @param bollean $force_absolute
 *   Determines whether the path to be absolute.
 * @return string
 *   An HTML string containing a link to the given path.
 */
function api_tokens_apitoken_link($text, $path, array $options = array(), $force_absolute = FALSE) {
  $text = t($text);
  if ($force_absolute) {
    $path = url($path, array('absolute' => TRUE));
  }
  $content = l($text, $path, $options);

  return $content;
}
