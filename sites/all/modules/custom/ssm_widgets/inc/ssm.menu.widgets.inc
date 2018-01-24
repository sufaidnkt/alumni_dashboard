<?php
function _ssm_widgets_menus(){

  $items['alumni/widget/ajax/total-members'] = array(
    'title' => t('Total Alumni Members'),
    'type'=> MENU_CALLBACK,
    'page callback' => '_alumni_total_members',
    'page arguments' => array(3),
    'access arguments' => array('alumni dashboard widgets'),
    'file' => 'inc/ssm.menu.callback.widgets.inc',
    'file path' => drupal_get_path('module', 'ssm_widgets'),
  );

  $items['alumni/widget/ajax/my-class'] = array(
    'title' => t('My Class Members'),
    'type'=> MENU_CALLBACK,
    'page callback' => '_alumni_my_class_members',
    'page arguments' => array(3),
    'access arguments' => array('alumni dashboard widgets'),
    'file' => 'inc/ssm.menu.callback.widgets.inc',
    'file path' => drupal_get_path('module', 'ssm_widgets'),
  );

  $items['alumni/widget/ajax/my-batch'] = array(
    'title' => t('My Batch Members'),
    'type'=> MENU_CALLBACK,
    'page callback' => '_alumni_my_batch_members',
    'page arguments' => array(3),
    'access arguments' => array('alumni dashboard widgets'),
    'file' => 'inc/ssm.menu.callback.widgets.inc',
    'file path' => drupal_get_path('module', 'ssm_widgets'),
  );

  return $items;
}
