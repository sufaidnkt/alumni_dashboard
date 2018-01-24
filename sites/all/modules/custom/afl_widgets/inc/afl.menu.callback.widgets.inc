<?php
function _afl_groups_ajax_callback(){
  global $user;

  $data['text'] = !empty($_get_count_downline) ? $_get_count_downline : 0;
  $data['title'] = t('My Groups');
  $data['link'] = url('#');
  $data['box_color'] = 'bg-primary';
  $data['icon'] = 'material-icons';
  $data['icon_text'] = 'group_work';
  $data['data_bg'] = 'orange';


  drupal_json_output($data);

}

function _afl_my_total_messages(){
  global $user;

  $data['text'] = !empty($_get_count_downline) ? $_get_count_downline : 0;
  $data['title'] = t('OverAll');
  $data['link'] = url('#');
  $data['box_color'] = 'bg-primary';
  $data['icon'] = 'material-icons';
  $data['icon_text'] = 'import_export';
  $data['data_bg'] = 'green';


  drupal_json_output($data);

}

function _afl_total_send_messages(){
  global $user;


  $data['text'] = !empty($_get_count_downline) ? $_get_count_downline : 0;
  $data['title'] = t('Send');
  $data['link'] = url('#');
  $data['box_color'] = 'bg-primary';
  $data['icon'] = 'material-icons';
  $data['icon_text'] = 'present_to_all';
  $data['data_bg'] = 'red';


  drupal_json_output($data);

}

function _afl_total_received_messages(){
  global $user;

   $data['text'] = !empty($_get_count_downline) ? $_get_count_downline : 0;
  $data['title'] = t('Received');
  $data['link'] = url('#');
  $data['box_color'] = 'bg-primary';
  $data['icon'] = 'material-icons';
  $data['icon_text'] = 'move_to_inbox';
  $data['data_bg'] = 'blue';


  drupal_json_output($data);

}

function _afl_total_unread_messages(){
  global $user;


  $data['text'] = !empty($_get_count_downline) ? $_get_count_downline : 0;
  $data['title'] = t('Unread');
  $data['link'] = url('#');
  $data['box_color'] = 'bg-primary';
  $data['icon'] = 'material-icons';
  $data['icon_text'] = 'inbox';
  $data['data_bg'] = '';

  drupal_json_output($data);

}

