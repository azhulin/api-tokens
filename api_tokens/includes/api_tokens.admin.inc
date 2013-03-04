<?php


function api_tokens_page_format_description($token) {
  return $token['description'] ? $token['description'] : '<small><i>' . t('No description.') . '</i></small>';
}


function api_tokens_page_format_params($token) {
  if (api_tokens_prepare_handler($token['key'])) {

    $params = api_tokens_param_info($token['key'], TRUE);
    $content = $params ? print_r($params, 1) : '-';
  }
  else {
    $content = '<strong>' . t('Token handler not found') . '</strong>';
  }

  return $content;
}


function api_tokens_page_format_cache($token) {
  $cache = $token['cache'];
  $content = array();

  if (0 < $cache) {
    DRUPAL_CACHE_PER_ROLE & $cache && $content[] = t('Per user role');
    DRUPAL_CACHE_PER_USER & $cache && $content[] = t('Per user');
    DRUPAL_CACHE_PER_PAGE & $cache && $content[] = t('Per page');
    DRUPAL_CACHE_GLOBAL & $cache && !$content && $content[] = t('Global');
  }
  else {
    $content[] = '<em>' . t('No caching') . '</em>';
  }

  return implode('<br/>', $content);
}


function api_tokens_page_format_expiration($token) {
  if (DRUPAL_NO_CACHE != $token['cache']) {
    $expire = $token['cache_expire'];
    // If cache isn't set to CACHE_PERMANENT (0) or CACHE_TEMPORARY (-1)
    if (0 < $expire) {
      if (31536000 <= $expire) {
        $content = t('More then one year');
      }
      else {
        $date = new DateTime('@' . $expire, new DateTimeZone('UTC'));
        $date = array(
          'month' => $date->format('n') - 1,
          'day' => $date->format('j') - 1,
          'hour' => $date->format('G'),
          'minute' => $date->format('i'),
          'second' => $date->format('s'),
        );
        foreach ($date as $key => $value) {
          if (0 < $value) {
            $content = format_plural((int) $value, '1 ' . $key, '@count ' . $key . 's');
            break;
          }
        }
      }
    }
    elseif (CACHE_PERMANENT == $expire) {
      $content = t('Permanent');
    }
    else {
      $content = t('Temporary');
    }
  }
  else {
    $content = '-';
  }

  return $content;
}


function api_tokens_page_build_row($token) {
  $row = array(
    $token['title'],
    api_tokens_page_format_description($token),
    api_tokens_page_format_params($token),
    api_tokens_page_format_cache($token),
    api_tokens_page_format_expiration($token),
  );

  return $row;
}


function api_tokens_page_list() {
  $module_list = system_rebuild_module_data();


  $tokens = api_tokens_collect_tokens();

  $tokens_info = array();
  foreach ($tokens as $token) {
    $tokens_info[$token['module']][] = $token;
  }

  $rows = array();
  $row_number = 0;
  foreach ($tokens_info as $module => &$tokens) {
    $token = array_shift($tokens);

    $rows[$row_number] = array(
      $module => array(
        'data' => $module_list[$module]->info['name'],
        'rowspan' => count($tokens) + 1,
      ),
    );

    $rows[$row_number++] += api_tokens_page_build_row($token);
    foreach ($tokens as $token) {
      $rows[$row_number++] = api_tokens_page_build_row($token);
    }
  }

  $vars = array(
    'header' => array(
      t('Provider'),
      t('Token'),
      t('Description'),
      t('Parameters'),
      t('Cache'),
      t('Expiration'),
    ),
    'rows' => $rows,
  );

  $content = theme('table', $vars);

  return $content;
}
