<?php


function material_dashboard_status_messages($variables) {
  $display = $variables['display'];
  $output = '';

  $status_heading = array(
    'success' => t('Success message'),
    'status' => t('Status message'),
    'error' => t('Error message'),
    'warning' => t('Warning message'),
    'info' => t('Informative message'),
  );

  // Map Drupal message types to their corresponding Bootstrap classes.
  // @see http://twitter.github.com/bootstrap/components.html#alerts
  $status_class = array(
    'success' => 'alert-success',
    'status' => 'alert-success',
    'error' => 'alert-danger',
    'warning' => 'alert-warning',
    // Not supported, but in theory a module could send any type of message.
    // @see drupal_set_message()
    // @see theme_status_messages()
    'info' => 'alert-info',
  );

  foreach (drupal_get_messages($display) as $type => $messages) {
    $class = (isset($status_class[$type])) ? $status_class[$type] : '';

    $type = ($type == 'error' ) ? 'danger' : $type;
    $type = ($type == 'status' ) ? 'success' : $type;

    if (count($messages) > 1) {

      $output .= " <ul>";
      foreach ($messages as $message) {
        $output .= '  <li>' . $message . "</li>";
      }
      $output .= " </ul>";
    }
    else {
      $output .= $messages[0];
    }
  }

  $html_data = null;
  if(!empty($output)){
    //drupal_add_css(drupal_get_path('theme', 'material_dashboard') . '/css/toastr.min.css', array('group' => CSS_DEFAULT, 'every_page' => TRUE));
    drupal_add_js('jQuery(document).ready(function ($){$( ".alert-close-button" ).click(function() {$(this).parent("div.alert").remove();});});',array('type' => 'inline','scope' => 'footer','weight' =>5));

    // drupal_add_js('jQuery(document).ready(function ($){demo.showNotification("top","right", "k");});',array('type' => 'inline','scope' => 'footer','weight' =>5));

    drupal_add_js("$.notify({
            icon: 'notifications',
            message: '".$output." '

        }, {
            type: '".$type."',
            timer: 4000,
            placement: {
                from: 'top',
                align: 'right'
            }
        });",array('type' => 'inline','scope' => 'footer','weight' =>5));

    // $html_data = "<div id=\"alert-container\" class=\"alert-wrapper\">\n";
    // $html_data .= $output;
    // $html_data .= "</div>\n";
  }
  return $html_data;
}



function material_dashboard_form_alter(&$form, &$form_state,$form_id) { 
  // pr($form_id);
  if($form_id == 'views_exposed_form'){
    $form['#attributes']['class'] = 'exposed-form-margin';
  }
  if(($form_id == 'user_login_block' || $form_id == 'user_login') && !user_is_logged_in()){
    $form['#attributes']['class'][] = 'card-content form-validation';
    $form['actions']['submit']['#attributes']['class'][] = 'btn btn-lg';
    $form['actions']['submit']['#attributes']['class'][] = 'btn-primary';
    $form['actions']['submit']['#attributes']['class'][] = 'btn-block';

    $form['join_link']['#weight'] = 510;
    $form['join_link']['#markup'] = '<p class="text-center"><small>'.t('Do not have an account?').'</small></p>'.l(t('Create an account'), 'user/register', array('attributes' => array('class' => array('btn btn-lg','btn-default','btn-block'))));

     
    $form['lost_password']['#weight'] = 509;
    $form['lost_password']['#markup'] = '<div class="text-center m-t m-b">' . l(t('Forgot password?'), 'user/password',array('attributes'=>array('title'=>t('Request new password')))) . '</div>';

    if(!empty($form['name']['#title'])){
      $form['name']['#attributes']['placeholder'] = $form['name']['#title'];
      $form['name']['#description'] = '';
      $form['name']['#attributes']['class'][] = 'no-border form-control';
      unset($form['name']['#title']);
      $form['name']['#wrapper_attributes']['class'][] = 'list-group-item';
    }
    if(!empty($form['pass']['#title'])){
      $form['pass']['#attributes']['placeholder'] = $form['pass']['#title'];
      $form['pass']['#attributes']['class'][] = 'no-border form-control';
      unset($form['pass']['#title']);
      $form['pass']['#wrapper_attributes']['class'][] = 'list-group-item';
      $form['pass']['#wrapper_attributes']['class'][] = 'm-b';
    }

    $form['resend_verification']['#weight'] = 508;
    $form['resend_verification']['#markup'] = '<div class="text-center resend-verification-class wrapper-sm">';
    $form['resend_verification']['#markup'] .= l(t('Resend verification Mail'), 'afl/resend-verification-mail', array('absolute' => TRUE));
    $form['resend_verification']['#markup'] .= '</div>';
    $form['#prefix'] = '<div class="col-md-offset-3 col-md-6"><div class="card">';
    $form['#suffix'] = '</div></div>';
  }
  
  //alter re-send password form
  if ( $form_id == 'user_pass' || $form_id == 'user_profile_form') {

    $form['#attributes']['class'][] = 'card-content form-validation';
    $form['actions']['submit']['#attributes']['class'][] = 'btn btn-lg';
    $form['actions']['submit']['#attributes']['class'][] = 'btn-primary';
    $form['actions']['submit']['#attributes']['class'][] = 'btn-block';
    
    $form['join_link']['#weight'] = 510;
    $form['join_link']['#markup'] = '<p class="text-center"><small>'.t('Do not have an account?').'</small></p>'.l(t('Create an account'), 'user/register', array('attributes' => array('class' => array('btn btn-lg','btn-default','btn-block'))));

     if(!empty($form['name']['#title'])){
      $form['name']['#attributes']['placeholder'] = $form['name']['#title'];
      $form['name']['#description'] = '';
      $form['name']['#attributes']['class'][] = 'no-border form-control';
      unset($form['name']['#title']);
      $form['name']['#wrapper_attributes']['class'][] = 'list-group-item';
    }
    
    $form['#prefix'] = '<div class="col-md-offset-3 col-md-6"><div class="card">';
    $form['#suffix'] = '</div></div>';
  }


  //alter the registrtion form
  if ( $form_id == 'user_register_form') {
    $form['#attributes']['class'][] = 'card-content form-validation';
    $form['actions']['submit']['#attributes']['class'][] = 'btn btn-lg';
    $form['actions']['submit']['#attributes']['class'][] = 'btn-primary';
    $form['actions']['submit']['#attributes']['class'][] = 'btn-block';
    
    $form['join_link']['#weight'] = 510;
    $form['join_link']['#markup'] = '<p class="text-center"><small>'.t('Already have an account?').'</small></p>'.l(t('Sign in'), 'user', array('attributes' => array('class' => array('btn btn-lg','btn-default','btn-block'))));

    if(!empty($form['account']['name']['#title'])){
      $form['account']['name']['#attributes']['placeholder'] = $form['account']['name']['#title'];
      $form['account']['name']['#description'] = '';
      $form['account']['name']['#attributes']['class'][] = 'no-border form-control';
      unset($form['account']['name']['#title']);
      $form['account']['name']['#wrapper_attributes']['class'][] = 'list-group-item';
    }

    if(!empty($form['account']['pass'])){
      // $form['account']['pass']['#attributes']['placeholder'] = $form['pass']['#title'];
      $form['account']['pass']['#attributes']['class'][] = 'no-border form-control';
      unset($form['pass']['#title']);
      $form['account']['pass']['#wrapper_attributes']['class'][] = 'list-group-item';
      $form['account']['pass']['#wrapper_attributes']['class'][] = 'm-b';
    }

    if(!empty($form['account']['mail']['#title'])){
      $form['account']['mail']['#attributes']['placeholder'] = $form['account']['mail']['#title'];
      $form['account']['mail']['#description'] = '';
      $form['account']['mail']['#attributes']['class'][] = 'no-border form-control';
      unset($form['account']['mail']['#title']);
      $form['account']['mail']['#wrapper_attributes']['class'][] = 'list-group-item';
    }
    
    $form['#prefix'] = '<div class="col-md-offset-3 col-md-6"><div class="card">';
    $form['#suffix'] = '</div></div>';



  }


}

function material_dashboard_links__locale_block(&$vars) {
  $vars['attributes']['class'][] = 'dropdown-menu';
  $vars['attributes']['class'][] = 'animated';
  $vars['attributes']['class'][] = 'fadeInRight';
  $vars['attributes']['class'][] = 'w';
  return theme_links($vars);
}
