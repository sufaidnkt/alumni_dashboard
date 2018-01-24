<?php
function _alumni_total_members(){

  global $user;
  $count = alumni_widget_data_details($user->uid);
  $data['text'] =  ($count) ? $count : 0;
  $data['title'] = t('Total Members');
  $data['link'] = url('#');
  $data['box_color'] = 'bg-primary';
  $data['icon'] = 'material-icons';
  $data['icon_text'] = 'group_work';
  $data['data_bg'] = 'green';


  drupal_json_output($data);

}
function _alumni_my_class_members(){

  global $user;
  $count = alumni_widget_data_details($user->uid,TRUE,TRUE);
  $data['text'] =  ($count) ? $count : 0;
  $data['title'] = t('My class');
  $data['link'] = url('#');
  $data['box_color'] = 'bg-primary';
  $data['icon'] = 'material-icons';
  $data['icon_text'] = 'home';
  $data['data_bg'] = 'green';


  drupal_json_output($data);

}

function _alumni_my_batch_members(){
    global $user;
  $count = alumni_widget_data_details($user->uid,TRUE);
  $data['text'] =  ($count) ? $count : 0;
  $data['title'] = t('My Batch');
  $data['link'] = url('#');
  $data['box_color'] = 'bg-primary';
  $data['icon'] = 'material-icons';
  $data['icon_text'] = 'supervisor_account';
  $data['data_bg'] = 'orange';


  drupal_json_output($data);
}



