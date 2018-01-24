<?php
/**
 * Implements hook_breadcrumb()
 */
function eps_diamond_breadcrumb($variables) {

  if(theme_get_setting('breadcrumbs')){
    $breadcrumb = $variables['breadcrumb'];
    if (!empty($breadcrumb)) {
      // Provide a navigational heading to give context for breadcrumb links to
      // screen-reader users. Make the heading invisible with .element-invisible.
      $crumbs = '<ul class="breadcrumb">';
      $array_size = count($breadcrumb);
      if ($array_size > 1) {
          $array_size = $array_size - 1;
      }
      $i = 0;
      while ($i < $array_size) {
          $crumbs .= '<li class="m_right_10 current">';
          $crumbs .= $breadcrumb[$i];
          $crumbs .= '</li>';
          $i++;
      }
      $crumbs .= '<li>'.drupal_get_title() . '</li></ul>';
      return $crumbs;
    }
  }else{
    return false;
  }
}
/**
 * Implements theme_system_powered_by()
 */
function eps_diamond_system_powered_by() {
  return '<span> &copy; '.date('Y').' '.variable_get('site_name', 'Epixel Solutions Pvt.Ltd').'. '. t("All Rights Reserved").'. ' .theme_get_setting('poweredby').'</span>';
}
