<?php
function _afl_widgets_menus(){
  

  $items['afl/widget/ajax/my-groups'] = array(
    'title' => t('My Groups'),
    'type'=> MENU_CALLBACK,
    'page callback' => '_afl_groups_ajax_callback',
    'page arguments' => array(3),
    'access arguments' => array('my groups'),
    'file' => 'inc/afl.menu.callback.widgets.inc',
    'file path' => drupal_get_path('module', 'afl_widgets'),
  );
  
  $items['afl/widget/ajax/my-messages-count'] = array(
    'title' => t('My Total Messages'),
    'type'=> MENU_CALLBACK,
    'page callback' => '_afl_my_total_messages',
    'page arguments' => array(3),
    'access arguments' => array('total messages'),
    'file' => 'inc/afl.menu.callback.widgets.inc',
    'file path' => drupal_get_path('module', 'afl_widgets'),
  );

  $items['afl/widget/ajax/my-send-messages-count'] = array(
    'title' => t('Total Send Messages'),
    'type'=> MENU_CALLBACK,
    'page callback' => '_afl_total_send_messages',
    'page arguments' => array(3),
    'access arguments' => array('total send messages'),
    'file' => 'inc/afl.menu.callback.widgets.inc',
    'file path' => drupal_get_path('module', 'afl_widgets'),
  );

  $items['afl/widget/ajax/my-received-messages-count'] = array(
    'title' => t('Total Received Messages'),
    'type'=> MENU_CALLBACK,
    'page callback' => '_afl_total_received_messages',
    'page arguments' => array(3),
    'access arguments' => array('total receive messages'),
    'file' => 'inc/afl.menu.callback.widgets.inc',
    'file path' => drupal_get_path('module', 'afl_widgets'),
  );
  
  $items['afl/widget/ajax/my-unread-messages-count'] = array(
    'title' => t('Total Unread Messages'),
    'type'=> MENU_CALLBACK,
    'page callback' => '_afl_total_unread_messages',
    'page arguments' => array(3),
    'access arguments' => array('total unread messages'),
    'file' => 'inc/afl.menu.callback.widgets.inc',
    'file path' => drupal_get_path('module', 'afl_widgets'),
  );
  return $items;
}
