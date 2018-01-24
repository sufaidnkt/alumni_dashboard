<?php
/**
 * Implements hook_js_alter()
 */
function eps_diamond_js_alter(&$javascript) {
  // if(!empty($javascript)){
  //   $javascript_key_valu = preg_grep("/jquery/", array_keys($javascript));
  //   if(!empty($javascript_key_valu)){
  //     foreach ($javascript_key_valu as $array_key_name) {
  //       $javascript[$array_key_name]['scope'] = 'jq_script';
  //     }
  //   }
  // }
  // Add CDN.
  if (theme_get_setting('bootstrap_cdn')) {
    $cdn = '//netdna.bootstrapcdn.com/bootstrap/' . theme_get_setting('bootstrap_cdn')  . '/js/bootstrap.min.js';
    $javascript[$cdn] = drupal_js_defaults();
    $javascript[$cdn]['data'] = $cdn;
    $javascript[$cdn]['type'] = 'external';
    $javascript[$cdn]['every_page'] = TRUE;
    $javascript[$cdn]['weight'] = -100;
  }else{
    $bootstrap_custom_js_url = theme_get_setting('bootstrap_custom_js_url');
    if(!empty($bootstrap_custom_js_url)){
      if (!filter_var($bootstrap_custom_js_url, FILTER_VALIDATE_URL) === false) {
        $javascript[$bootstrap_custom_js_url] = drupal_js_defaults();
        $javascript[$bootstrap_custom_js_url]['data'] = $bootstrap_custom_js_url;
        $javascript[$bootstrap_custom_js_url]['type'] = 'external';
        $javascript[$bootstrap_custom_js_url]['every_page'] = TRUE;
        $javascript[$bootstrap_custom_js_url]['weight'] = -100;
      }else {
        $javascript[$bootstrap_custom_js_url] = drupal_js_defaults();
        $javascript[$bootstrap_custom_js_url]['data'] = $bootstrap_custom_js_url;
        $javascript[$bootstrap_custom_js_url]['type'] = 'file';
        $javascript[$bootstrap_custom_js_url]['every_page'] = TRUE;
        $javascript[$bootstrap_custom_js_url]['weight'] = -100;
      }
    }else{
      $bootstrap_path = drupal_get_path('theme', 'eps_diamond').'/libs/jquery/bootstrap/dist/js/bootstrap.min.js';
      $javascript[$bootstrap_path] = drupal_js_defaults();
      $javascript[$bootstrap_path]['data'] = $bootstrap_path;
      $javascript[$bootstrap_path]['type'] = 'file';
      $javascript[$bootstrap_path]['every_page'] = TRUE;
      $javascript[$bootstrap_path]['weight'] = -100;
    }
  }
}

/**
 * Implements hook_css_alter().
 */
function eps_diamond_css_alter(&$css) {
  /*
  unset($css['modules/aggregator/aggregator.css']);
  unset($css['modules/book/book.css']);
  unset($css['modules/comment/comment.css']);
  unset($css['modules/filter/filter.css']);
  unset($css['modules/system/admin.css']);
  unset($css['misc/vertical-tabs.css']);
  */
  unset($css['modules/dblog/dblog.css']);
  unset($css['modules/block/block.css']);
  unset($css['modules/field/theme/field.css']);
  unset($css['modules/file/file.css']);
  unset($css['modules/forum/forum.css']);
  unset($css['modules/help/help.css']);
  unset($css['modules/menu/menu.css']);
  unset($css['modules/node/node.css']);
  unset($css['modules/openid/openid.css']);
  unset($css['modules/poll/poll.css']);
  unset($css['modules/profile/profile.css']);
  unset($css['modules/search/search.css']);
  unset($css['modules/statistics/statistics.css']);
  unset($css['modules/syslog/syslog.css']);
  unset($css['modules/system/maintenance.css']);
  unset($css['modules/system/system.css']);
  unset($css['modules/system/system.admin.css']);
  if($_GET['q'] != 'admin/structure/menu/manage/menu-affiliate-menu'
    && $_GET['q'] != 'admin/structure/menu/manage/main-menu' && $_GET['q']  != 'admin/config/regional/language'){
    unset($css['modules/system/system.base.css']);
  }

  unset($css['modules/system/system.maintenance.css']);
  unset($css['modules/system/system.messages.css']);
  unset($css['modules/system/system.menus.css']);
  unset($css['modules/system/system.theme.css']);
  unset($css['modules/taxonomy/taxonomy.css']);
  unset($css['modules/tracker/tracker.css']);
  unset($css['modules/update/update.css']);
  unset($css['modules/user/user.css']);
  unset($css[drupal_get_path('module', 'views') . '/css/views.css']);


  $theme_path = drupal_get_path('theme', 'eps_diamond');
  // Exclude specified CSS files from theme.
  // Add Bootstrap CDN file and overrides.
  if (theme_get_setting('bootstrap_cdn')) {
    // Add CDN.
    if (theme_get_setting('bootstrap_bootswatch')) {
      $cdn = '//netdna.bootstrapcdn.com/bootswatch/' . theme_get_setting('bootstrap_cdn')  . '/' . theme_get_setting('bootstrap_bootswatch') . '/bootstrap.min.css';
    }
    else {
      $cdn = '//netdna.bootstrapcdn.com/bootstrap/' . theme_get_setting('bootstrap_cdn')  . '/css/bootstrap.min.css';
    }
    $css[$cdn] = array(
      'data' => $cdn,
      'type' => 'external',
      'every_page' => TRUE,
      'media' => 'all',
      'preprocess' => FALSE,
      'group' => CSS_THEME,
      'browsers' => array('IE' => TRUE, '!IE' => TRUE),
      'weight' => -2,
    );
    // Add overrides.
    $override = $theme_path . '/css/overrides.css';
    $css[$override] = array(
      'data' => $override,
      'type' => 'file',
      'every_page' => TRUE,
      'media' => 'all',
      'preprocess' => TRUE,
      'group' => CSS_THEME,
      'browsers' => array('IE' => TRUE, '!IE' => TRUE),
      'weight' => -1,
    );
  }else{
    $bootstrap_custom_css_url = theme_get_setting('bootstrap_custom_css_url');
    if(!empty($bootstrap_custom_css_url)){
      if (!filter_var($bootstrap_custom_css_url, FILTER_VALIDATE_URL) === false) {
        $css[$bootstrap_custom_css_url] = array(
          'data' => $bootstrap_custom_css_url,
          'type' => 'external',
          'every_page' => TRUE,
          'media' => 'all',
          'preprocess' => FALSE,
          'group' => CSS_THEME,
          'browsers' => array('IE' => TRUE, '!IE' => TRUE),
          'weight' => -2,
        );

      }else {
        $css[$bootstrap_custom_css_url] = array(
          'data' => $bootstrap_custom_css_url,
          'type' => 'file',
          'every_page' => TRUE,
          'media' => 'all',
          'preprocess' => FALSE,
          'group' => CSS_THEME,
          'browsers' => array('IE' => TRUE, '!IE' => TRUE),
          'weight' => -2,
        );
      }
    }else{
      $bootstrap_css = $theme_path.'/libs/jquery/bootstrap/dist/css/bootstrap.min.css';
      $css[$bootstrap_css] = array(
        'data' => $bootstrap_css,
        'type' => 'file',
        'every_page' => TRUE,
        'media' => 'all',
        'preprocess' => FALSE,
        'group' => CSS_THEME,
        'browsers' => array('IE' => TRUE, '!IE' => TRUE),
        'weight' => -2,
      );
    }
    global $language;
    if(!empty($language->dir) && $language->dir == 'rtl'){
      unset($css['modules/system/system.menus-rtl.css']);
      $bootstrap_css = $theme_path.'/libs/jquery/bootstrap/dist/css/bootstrap-rtl.min.css';
      $css[$bootstrap_css] = array(
        'data' => $bootstrap_css,
        'type' => 'file',
        'every_page' => TRUE,
        'media' => 'all',
        'preprocess' => FALSE,
        'group' => CSS_THEME,
        'browsers' => array('IE' => TRUE, '!IE' => TRUE),
        'weight' => -1,
      );
      $app_rtl = $theme_path.'/css/app.rtl.css';
      $css[$app_rtl] = array(
        'data' => $app_rtl,
        'type' => 'file',
        'every_page' => TRUE,
        'media' => 'all',
        'preprocess' => FALSE,
        'group' => CSS_THEME,
        'browsers' => array('IE' => TRUE, '!IE' => TRUE),
        'weight' => 5,
      );
      $app_rtl = $theme_path.'/css/main-style.rtl.css';
      $css[$app_rtl] = array(
        'data' => $app_rtl,
        'type' => 'file',
        'every_page' => TRUE,
        'media' => 'all',
        'preprocess' => FALSE,
        'group' => CSS_THEME,
        'browsers' => array('IE' => TRUE, '!IE' => TRUE),
        'weight' => 6,
      );
    }


  }


  // if (!empty($excludes)) {
  //   $css = array_diff_key($css, drupal_map_assoc($excludes));
  // }
}

function eps_diamond_status_messages($variables) {
  $display = $variables['display'];
  $output = '';

  $status_heading = array(
    'status' => t('Status message'),
    'error' => t('Error message'),
    'warning' => t('Warning message'),
    'info' => t('Informative message'),
  );

  // Map Drupal message types to their corresponding Bootstrap classes.
  // @see http://twitter.github.com/bootstrap/components.html#alerts
  $status_class = array(
    'status' => 'toast-success',
    'error' => 'toast-error',
    'warning' => 'toast-warning',
    // Not supported, but in theory a module could send any type of message.
    // @see drupal_set_message()
    // @see theme_status_messages()
    'info' => 'toast-info',
  );

  foreach (drupal_get_messages($display) as $type => $messages) {
    $class = (isset($status_class[$type])) ? $status_class[$type] : '';
    $output .= "<div class=\"toast $class\">\n";
    $output .= "<button type=\"button\" class=\"toast-close-button\" role=\"button\">×</button>\n";

    if (!empty($status_heading[$type])) {
      $output .= '<div class="toast-title hide">' . $status_heading[$type] . "</div>\n";
    }

    if (count($messages) > 1) {

      $output .= " <div class=\"toast-message\">\n";
      $output .= " <ul>\n";
      foreach ($messages as $message) {
        $output .= '  <li>' . $message . "</li>\n";
      }
      $output .= " </ul>\n";
      $output .= "</div>\n";
    }
    else {
      $output .= " <div class=\"toast-message\">\n";
      $output .= $messages[0];
      $output .= "</div>\n";
    }

    $output .= "</div>\n";
  }
  $html_data = null;
  if(!empty($output)){
    drupal_add_css(drupal_get_path('theme', 'eps_diamond') . '/css/toastr.min.css', array('group' => CSS_DEFAULT, 'every_page' => TRUE));
    drupal_add_js('jQuery(document).ready(function ($){$( ".toast-close-button" ).click(function() {$(this).parent("div.toast").remove();});
    setTimeout(function() {$("#toast-container").fadeOut(5000, function(){$(this).remove();});}, 29000);});',array('type' => 'inline','scope' => 'footer','weight' =>5));
    $html_data = "<div id=\"toast-container\" class=\"toast-top-right\">\n";
    $html_data .= $output;
    $html_data .= "</div>\n";
  }
  return $html_data;
}



function eps_diamond_form_alter(&$form, &$form_state,$form_id) {

  if(($form_id == 'user_login_block' || $form_id == 'user_login') && !user_is_logged_in()){
    $form['#attributes']['class'][] = 'form-validation';
    $form['#attributes']['class'][] = 'user-eps-diamond-block';
    $form['actions']['submit']['#attributes']['class'][] = 'btn btn-lg';
    $form['actions']['submit']['#attributes']['class'][] = 'btn-primary';
    $form['actions']['submit']['#attributes']['class'][] = 'btn-block';

    $form['join_link']['#weight'] = 510;
    $form['join_link']['#markup'] = '<p class="text-center"><small>'.t('Do not have an account?').'</small></p>'.l(t('Create an account'), 'afl/join', array('attributes' => array('class' => array('btn btn-lg','btn-default','btn-block'))));
    $form['lost_password']['#weight'] = 509;
    $form['lost_password']['#markup'] = '<div class="text-center m-t m-b">' . l(t('Forgot password?'), 'user/password',array('attributes'=>array('title'=>t('Request new password')))) . '</div>';


    if(!empty($form['name']['#title'])){
      $form['name']['#attributes']['placeholder'] = $form['name']['#title'];
      $form['name']['#description'] = $form['name']['#title'];
      $form['name']['#attributes']['class'][] = 'no-border';
      unset($form['name']['#title']);
      $form['name']['#wrapper_attributes']['class'][] = 'list-group-item';
    }
    if(!empty($form['pass']['#title'])){
      $form['pass']['#attributes']['placeholder'] = $form['pass']['#title'];
      $form['pass']['#attributes']['class'][] = 'no-border';
      unset($form['pass']['#title']);
      $form['pass']['#wrapper_attributes']['class'][] = 'list-group-item';
      $form['pass']['#wrapper_attributes']['class'][] = 'm-b';
    }
  }

  if($form_id == 'user_pass' && !user_is_logged_in()){
    $form['#attributes']['class'][] = 'form-validation';
    $form['#attributes']['class'][] = 'user-eps-diamond-block';
    $form['actions']['submit']['#attributes']['class'][] = 'btn btn-lg';
    $form['actions']['submit']['#attributes']['class'][] = 'btn-primary';
    $form['actions']['submit']['#attributes']['class'][] = 'btn-block';
    $form['links']['#weight'] = 500;

    if(!empty($form['name']['#title'])){
      $form['name']['#attributes']['placeholder'] = $form['name']['#title'];
      $form['name']['#attributes']['class'][] = 'no-border';
      unset($form['name']['#title']);
      $form['name']['#wrapper_attributes']['class'][] = 'list-group-item';
      $form['name']['#wrapper_attributes']['class'][] = 'm-b';
    }

    $form['join_link']['#type'] = 'markup';
    $form['join_link']['#weight'] = 510;
    $form['join_link']['#markup'] = '<p class="text-center m-t"><small>'.t('Do not have an account?').'</small></p>'.l(t('Create an account'), 'afl/join', array('attributes' => array('class' => array('btn btn-lg','btn-default','btn-block'))));
    $form['join_link']['#markup'] .= '<div class="text-center m-t m-b">'.l(t('Sign in'), 'user', array('attributes' => array('class' => array('btn btn-lg','btn-success','btn-block')))).'</div>';
  }

  if (drupal_multilingual()) {
    if ($form_id == 'user_register_form' || ($form_id == 'user_profile_form' && $form['#user_category'] == 'account')) {
      if (count(element_children($form['locale'])) > 1) {
        $form['locale']['language']['#weight'] = 999;
      }
      else {
        $form['locale']['#weight'] = 999;
      }
      $form['actions']['#weight'] = 1000;
    }
    //pr($form['actions'], 1);

  }

  if(!empty($form['#bootstrap']['form_horizontal'])){
    global $bootstrap_form;
    $bootstrap_form = $form['#bootstrap'];
    if(empty($form['#attributes']['class'])){ $form['#inner_div'] = 'from-panel'; }
    $form['#attributes']['class'][] = 'form-horizontal';
  }
}

function eps_diamond_links__locale_block(&$vars) {
  $vars['attributes']['class'][] = 'dropdown-menu';
  $vars['attributes']['class'][] = 'animated';
  $vars['attributes']['class'][] = 'fadeInRight';
  $vars['attributes']['class'][] = 'w';
  return theme_links($vars);
}
