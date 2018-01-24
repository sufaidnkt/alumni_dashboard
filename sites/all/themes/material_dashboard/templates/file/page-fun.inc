<?php

/**
 * Registers overrides for various functions.
 *
 * In this case, overrides three user functions
 */
function material_dashboard_theme() {
  return array(
  );
}

function material_dashboard_preprocess_page(&$vars, $hook) {
  
  //pr($vars['theme_hook_suggestions'],1);
  $theme_path = drupal_get_path('theme', 'material_dashboard');

  $header = drupal_get_http_header("status");

  if($header == "404 Not Found") {
    $vars['theme_hook_suggestions'][] = 'page__404';
    return;
  }
  if($header == "403 Forbidden") {
    $vars['theme_hook_suggestions'][] = 'page__404';
    return;
  }
  


  
  $logo_icon = theme_get_setting('logo_icon_checkbox') ? $theme_path.'/logo-icon.png': theme_get_setting('logo_icon');
  $vars['logo_icon'] = file_create_url($logo_icon);

  $vars['analytics_right_class'] = 'col-md-7';
  $vars['panel_grid_class'] = 'col-md-5';
  if(empty($vars['page']['panel_grid']) || empty($vars['page']['analytics_right'])){
    $vars['analytics_right_class'] = 'col-md-12';
    $vars['panel_grid_class'] = 'col-md-12';
  }

  $vars['statitics_left_class'] = 'col-md-6  no-border-xs';
  $vars['statitics_right_class'] = 'col-md-6';
  if(empty($vars['page']['statitics_left']) || empty($vars['page']['statitics_right'])){
    $vars['statitics_left_class'] = 'col-md-12';
    $vars['statitics_right_class'] = 'col-md-12';
  }

  $vars['title_class'] = 'col-sm-6 col-xs-12';
  $vars['title_extra_class'] = 'col-sm-6 text-right hidden-xs';
  if(empty($vars['page']['title_extra'])){
    $vars['title_class'] = 'col-sm-12 col-xs-12';
    $vars['title_extra_class'] = 'col-sm-12 text-right hidden-xs';
  }

  $vars['grid_block_left_class'] = 'col-md-6';
  $vars['grid_block_right_class'] = 'col-md-6';
  if(empty($vars['page']['grid_block_left']) || empty($vars['page']['grid_block_right'])){
    $vars['grid_block_left_class'] = 'col-md-12';
    $vars['grid_block_right_class'] = 'col-md-12';
  }

  // Primary nav.
  $vars['primary_nav'] = FALSE;
  if ($vars['main_menu']) {
    // Build links.
    $vars['primary_nav'] = menu_tree(variable_get('menu_main_links_source', 'main-menu'));
    // Provide default theme wrapper function.
    $vars['primary_nav']['#theme_wrappers'] = array('menu_tree__primary');
  }

  // Secondary nav.
  $vars['secondary_nav'] = FALSE;
  if ($vars['secondary_menu']) {
    // Build links.
    $vars['secondary_nav'] = menu_tree(variable_get('menu_secondary_links_source', 'user-menu'));
    // Provide default theme wrapper function.
    $vars['secondary_nav']['#theme_wrappers'] = array('menu_tree__secondary');
  }





/*
  // Primary nav.
  $vars['primary_nav'] = FALSE;
  if (!empty($vars['main_menu'])) {
    $vars['primary_nav'] = $vars['main_menu'];
    $vars['primary_nav']['#theme_wrappers'] = array('menu_tree__primary');
  }

  // Secondary nav.
  $vars['secondary_nav'] = FALSE;
  if (!empty($vars['secondary_menu'])) {
    $vars['secondary_nav'] = $vars['secondary_menu'];
    $vars['secondary_nav']['#theme_wrappers'] = array('menu_tree__secondary');
  }*/
  drupal_add_js(array('theme_path' =>$theme_path), 'setting');

  $current_path = current_path();
  $vars['user_profile_class'] = '';

  if (!user_is_logged_in()) {
    $vars['container_class'] = 'mw-650';
    if(! variable_get('afl_enable_multi_theme', FALSE) ){

      if($current_path=='afl/join' || (strpos($current_path, 'checkout') !== false) ){ $vars['container_class'] .= ' form-wrapper-main'; }
      if($current_path=='user/login' || $current_path=='user' || $current_path=='user/password' || $current_path==variable_get('site_frontpage','')){ $vars['container_class'] = 'w-xxl'; }
      $vars['theme_hook_suggestions'][] = 'page__anonymoususer';
    }

  }else{
    $vars['container_class'] = 'w-xxl';
    if(! variable_get('afl_enable_multi_theme', FALSE) ){
      $header = drupal_get_http_header("status");

      if ($header == "404 Not Found" || $header == "403 Forbidden") {
        $vars['theme_hook_suggestions'][] = 'page__anonymoususer';
      }
    }

    $vars['user_profile_class'] = (strpos($current_path, 'user') !== false) ? 'user-profile-wrapper' : '';
  }

  if(isset($vars['node']) && $vars['node']->type == 'lead_capture_page'){

      if(arg(2) != 'edit' && arg(2) != 'delete' && arg(2) != 'clone' ){
        $vars['theme_hook_suggestions'][] = 'page__leadcapture';
      }
     
   }

}