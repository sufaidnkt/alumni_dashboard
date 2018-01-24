<?php
function afl_advanced_config(){
  $header = array(t('Features'), t('Settings'));
  $form['table'] = array(
    '#theme' => 'afl_table_form',
    '#header' => $header,
    'rows' => array(
      '#tree' => TRUE,
    ),
  );

  $i = 0;

$form['table']['rows'][$i]['c1']['afl_enable_test_mode']= array(
    '#type' => 'markup',
    '#markup' => t('Enable Test Mode'),
  );
  $form['table']['rows'][$i++]['c2']['afl_enable_test_mode']= array(
    '#type' => 'checkbox',
    '#attributes' => array('switch' => 'switch'),
    '#default_value' => afl_variable_get('afl_enable_test_mode', FALSE),
  );


  $form['table']['rows'][$i]['c1']['afl_enable_test_date']= array(
    '#type' => 'markup',
    '#markup' => t('Override system date with test date'),
  );
  $form['table']['rows'][$i++]['c2']['afl_enable_test_date']= array(
    '#type' => 'checkbox',
    '#attributes' => array('switch' => 'switch'),
    '#default_value' => afl_variable_get('afl_enable_test_date', FALSE),
  );

  $form['table']['rows'][$i]['c1']['afl_testing_date']= array(
    '#type' => 'markup',
    '#markup' => t('Override Testing date'),
  );
  $form['table']['rows'][$i++]['c2']['afl_testing_date']= array(
    '#type' => 'date_popup',
    '#default_value' => afl_variable_get('afl_testing_date'),
    '#timepicker' => 'timepicker',
    '#timepicker_options' => array(
      'rows' => 6,
      'minutes' => array(
        'starts' => 0,
        'ends' => 56,
        'interval' => 4,
      ),
      'showCloseButton' => TRUE,
      'closeButtonText' => t('Close'),
    ),
  );

  $form['table']['rows'][$i]['c1']['afl_enable_demo_mode']= array(
    '#type' => 'markup',
    '#markup' => t('Enable Demo Mode'),
  );
  $form['table']['rows'][$i++]['c2']['afl_enable_demo_mode']= array(
    '#type' => 'checkbox',
    '#attributes' => array('switch' => 'switch'),
    '#default_value' => afl_variable_get('afl_enable_demo_mode', FALSE),
  );

  $form['table']['rows'][$i]['c1']['afl_enable_live_mode']= array(
    '#type' => 'markup',
    '#markup' => t('Enable Live Mode'),
  );
  $form['table']['rows'][$i++]['c2']['afl_enable_live_mode']= array(
    '#type' => 'checkbox',
    '#attributes' => array('switch' => 'switch'),
    '#default_value' => afl_variable_get('afl_enable_live_mode', FALSE),
  );

  $form['table']['rows'][$i]['c1']['afl_approved_payment_methods']= array(
    '#type' => 'markup',
    '#markup' => t('Approved Payment Methods'),
  );

  $afl_available_payment_methods = afl_variable_get('afl_available_payment_methods', '');
  $afl_approved_payment_methods = array();
  if(! empty($afl_available_payment_methods)){

    $afl_available_payment_method_array = list_extract_allowed_values($afl_available_payment_methods,'list_text',FALSE);
    foreach($afl_available_payment_method_array as $payment_key => $payment_val){
      $afl_available_payment_method_splits = explode('###', $payment_val);

    $afl_approved_payment_methods[$payment_key] = $afl_available_payment_method_splits[0];
    }

    $form['table']['rows'][$i++]['c2']['afl_approved_payment_methods']= array(
      '#type' => 'select',
      '#multiple' => TRUE,
      '#options' => $afl_approved_payment_methods,
      '#default_value' => afl_variable_get('afl_approved_payment_methods', FALSE),
    );




  }

  $form['submit']= array(
      '#type' => 'submit',
      '#value' => t('Save Configurations'),
    );


  return $form;
}


function afl_advanced_config_submit($form, &$form_state){
  $conf = array();
  if(isset($form_state['values']['rows']) ){
    $conf  = $form_state['values']['rows'];
  }


  foreach($conf as $key => $val){
    $keys_array = array_keys($val['c2']);
    $conf_key = end($keys_array);
    if(isset($val['c2'][$conf_key])){
      if(! is_array($val['c2'][$conf_key])){
        afl_variable_set(trim($conf_key), trim($val['c2'][$conf_key]) );
      }
      else{
        afl_variable_set(trim($conf_key), $val['c2'][$conf_key] );
      }

    }
  }

  drupal_set_message(t('The configurations has been saved'), 'status', FALSE);
}


function afl_advanced_config_extra(){
  $header = array(t('Features'), t('Settings'));
  $form['table'] = array(
    '#theme' => 'afl_table_form',
    '#header' => $header,
    'rows' => array(
      '#tree' => TRUE,
    ),
  );

  $i = 0;
  $form['table']['rows'][$i]['c1']['afl_registration_template']= array(
    '#type' => 'markup',
    '#markup' => t('Account creation URLs'),
  );
  $form['table']['rows'][$i++]['c2']['afl_registration_template']= array(
    '#type' => 'textarea',
    '#row' => 4,
    '#cols' => 5,
    '#default_value' => afl_variable_get('afl_registration_template', FALSE),
  );


  $form['table']['rows'][$i]['c1']['visitor_landing_page_url']= array(
    '#type' => 'markup',
    '#markup' => t('Anonymous user landing page URL'),
  );
  $form['table']['rows'][$i++]['c2']['visitor_landing_page_url']= array(
    '#type' => 'textfield',
    '#default_value' => afl_variable_get('visitor_landing_page_url', FALSE),
  );

  $form['table']['rows'][$i]['c1']['member_landing_page_url']= array(
    '#type' => 'markup',
    '#markup' => t('Member Landing URL'),
  );
  $form['table']['rows'][$i++]['c2']['member_landing_page_url']= array(
    '#type' => 'textfield',
    '#default_value' => afl_variable_get('member_landing_page_url', FALSE),
  );

  $form['table']['rows'][$i]['c1']['afl_enable_multi_theme']= array(
    '#type' => 'markup',
    '#markup' => t('Enable Multiple Theme'),
  );
  $form['table']['rows'][$i++]['c2']['afl_enable_multi_theme']= array(
    '#type' => 'checkbox',
    '#attributes' => array('switch' => 'switch'),
    '#default_value' => afl_variable_get('afl_enable_multi_theme', FALSE),
  );

  $form['table']['rows'][$i]['c1']['afl_admin_theme_url']= array(
    '#type' => 'markup',
    '#markup' => t('Admin Theme URL(Dashboard)'),
  );
  $form['table']['rows'][$i++]['c2']['afl_admin_theme_url']= array(
    '#type' => 'textarea',
    '#row' => 4,
    '#cols' => 5,
    '#default_value' => afl_variable_get('afl_admin_theme_url', FALSE),
  );

  $form['table']['rows'][$i]['c1']['forece_dfault_theme_urls']= array(
    '#type' => 'markup',
    '#markup' => t('Force default theme URLs'),
  );

  $form['table']['rows'][$i++]['c2']['forece_dfault_theme_urls']= array(
    '#type' => 'textarea',
    '#row' => 4,
    '#cols' => 5,
    '#default_value' => afl_variable_get('forece_dfault_theme_urls', FALSE),
  );

  $form['submit']= array(
      '#type' => 'submit',
      '#value' => t('Save Configurations'),
    );


  return $form;
}


function afl_advanced_config_extra_submit($form, &$form_state){
  $conf = array();
  if(isset($form_state['values']['rows']) ){
    $conf = $form_state['values']['rows'];
  }

  foreach($conf as $key => $val){
    $keys_array = array_keys($val['c2']);
    $conf_key = end($keys_array);
    if(isset($val['c2'][$conf_key])){
      if(! is_array($val['c2'][$conf_key])){
        afl_variable_set(trim($conf_key), trim($val['c2'][$conf_key]) );
      }
      else{
        afl_variable_set(trim($conf_key), $val['c2'][$conf_key] );
      }

    }
  }

  drupal_set_message(t('The configurations has been saved'), 'status', FALSE);
}
