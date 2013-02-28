<?php


/**
 * Defines date API tokens handler.
 */
function api_token_provider_handle_user_link() {
  global $user;

  $output = $user->uid ? l($user->name, 'user/' . $user->uid) : t('Anonimous');
  $output = '<strong>' . $output . '</strong>';

  return $output;
}


function api_token_provider_apitoken_node_list() {
  $query = db_select('node', 'N');
  $query->join('node_type', 'T', 'N.type = T.type');
  $query->leftJoin('users', 'U', 'U.uid = N.uid');
  $query->addField('T', 'name', 'type');
  $data = $query->fields('N', array('nid', 'title'))
    ->fields('U', array('uid', 'name'))
    ->condition('N.status', 1)
    ->condition('U.uid', 0, '<>')
    ->orderBy('N.created', 'DESC')
    ->range(0, 10)
    ->execute()
    ->fetchAll();

  $rows = array();
  foreach ($data as $row) {
    $rows[] = array(
      l($row->title, 'node/' . $row->nid),
      $row->type,
      l($row->name, 'user/' . $row->uid),
    );
  }

  $vars = array(
    'header' => array(
      t('Title'),
      t('Content Type'),
      t('Author'),
    ),
    'rows' => $rows,
  );

  $content = theme('table', $vars);

  return $content;
}


function api_token_provider_apitoken_test_token() {
  $content = '<strong>TEST TOKEN CONTENT</strong>';

  return $content;
}