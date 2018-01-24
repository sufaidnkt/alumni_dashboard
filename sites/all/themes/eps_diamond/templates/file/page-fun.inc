<?php
/**
 * Implements hook_preprocess_html()
 */
// function eps_diamond_preprocess_html(&$variables) {
//   $variables['jq_script'] = drupal_get_js('jq_script');
// }

/**
 * Implements hook_preprocess_page()
 */



function eps_diamond_preprocess_page(&$vars, $hook) {
  
  //pr($vars['theme_hook_suggestions'],1);
  $theme_path = drupal_get_path('theme', 'eps_diamond');

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

  $vars['aside_width'] = theme_get_setting('aside_width') ? theme_get_setting('aside_width') : '';
  $vars['fixed_header'] = theme_get_setting('fixed_header') ? 'app-header-fixed' : '';
  $vars['fixed_aside'] = theme_get_setting('fixed_aside') ? 'app-aside-fixed' : '';
  $vars['folded_aside'] = theme_get_setting('folded_aside') ? 'app-aside-folded' : '';
  $vars['dock_aside'] = theme_get_setting('dock_aside') ? 'app-aside-dock' : '';
  $vars['boxed_layout'] = theme_get_setting('boxed_layout') ? 'container' : '';
  $vars['navbar_header_color'] = theme_get_setting('navbar_header_color');
  $vars['navbar_collapse_color'] = theme_get_setting('navbar_collapse_color');
  $vars['aside_color'] = theme_get_setting('aside_color');
  $vars['layout_color_block'] = theme_get_setting('layout_color_block');
  drupal_add_js($theme_path .'/js/jquery.cookie.min.js');

  if(theme_get_setting('color_switcher')){
    drupal_add_js($theme_path .'/js/theme-color-switcher.js',array('type' => 'file', 'scope' => 'footer'));

    drupal_add_js(array('aside_width' =>$vars['aside_width']), 'setting');
    drupal_add_js(array('fixed_header' =>$vars['fixed_header']), 'setting');
    drupal_add_js(array('fixed_aside' =>$vars['fixed_aside']), 'setting');
    drupal_add_js(array('folded_aside' =>$vars['folded_aside']), 'setting');
    drupal_add_js(array('dock_aside' =>$vars['dock_aside']), 'setting');
    drupal_add_js(array('boxed_layout' =>$vars['boxed_layout']), 'setting');
    drupal_add_js(array('navbar_header_color' =>$vars['navbar_header_color']), 'setting');
    drupal_add_js(array('navbar_collapse_color' =>$vars['navbar_collapse_color']), 'setting');
    drupal_add_js(array('aside_color' =>$vars['aside_color']), 'setting');
    drupal_add_js(array('layout_color_block' =>$vars['layout_color_block']), 'setting');

    if(!empty($_COOKIE['headerFixed']) && $_COOKIE['headerFixed'] == 'yes'){ $vars['fixed_header'] = 'app-header-fixed'; }
    if(!empty($_COOKIE['asideFixed']) && $_COOKIE['asideFixed'] == 'yes'){ $vars['fixed_aside'] = 'app-aside-fixed'; }
    if(!empty($_COOKIE['asideFolded']) && $_COOKIE['asideFolded'] == 'yes'){ $vars['folded_aside'] = 'app-aside-folded'; }
    if(!empty($_COOKIE['asideDock']) && $_COOKIE['asideDock'] == 'yes'){ $vars['dock_aside'] = 'app-aside-dock'; }
    if(!empty($_COOKIE['layoutcontainer']) && $_COOKIE['layoutcontainer'] == 'yes'){ $vars['boxed_layout'] = 'container'; }
    if(!empty($_COOKIE['navbarHeaderColor'])){ $vars['navbar_header_color'] = $_COOKIE['navbarHeaderColor']; }
    if(!empty($_COOKIE['navbarCollapseColor'])){ $vars['navbar_collapse_color'] = $_COOKIE['navbarCollapseColor']; }
    if(!empty($_COOKIE['asideColor'])){ $vars['aside_color'] = $_COOKIE['asideColor']; }
    if(!empty($_COOKIE['layoutColorBlock'])){ $vars['layout_color_block'] = $_COOKIE['layoutColorBlock']; }
  }else{
    drupal_add_js($theme_path .'/js/theme-navbar.js',array('type' => 'file', 'scope' => 'footer'));
    if(!empty($_COOKIE['asideFolded']) && $_COOKIE['asideFolded'] == 'yes'){ $vars['folded_aside'] = 'app-aside-folded'; }
  }
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

//pr($vars['theme_hook_suggestions'], 1);


}

function _page_container(){
  
  if (user_is_logged_in()) {
    if(variable_get('afl_registration_template')){
      $afl_registration_template = list_extract_allowed_values(variable_get('afl_registration_template'),'list_text',false);
      $path = current_path();
      $path_alias = drupal_lookup_path('alias', $path);
      foreach($afl_registration_template as $patterns){
        if (drupal_match_path($path, $patterns) || drupal_match_path($path_alias, $patterns)) {
          return TRUE;
        }
      }
    }
  }
  return false;
}
