<?php
function material_dashboard_preprocess_table(&$variables) {
  if (isset($variables['attributes']['class']) && is_string($variables['attributes']['class'])) {
    // Convert classes to an array.
    $variables['attributes']['class'] = explode(' ', $variables['attributes']['class']);
  }
  $variables['attributes']['class'][] = 'table';
  if (!in_array('table-no-striping', $variables['attributes']['class']) && theme_get_setting('table_striped')) {
    $variables['attributes']['class'][] = 'table-striped';
  }
  if(theme_get_setting('table_bordered')){
    $variables['attributes']['class'][] = 'table-bordered';
  }
  if(theme_get_setting('table_condensed')){
    $variables['attributes']['class'][] = 'table-condensed';
  }
  if(theme_get_setting('table_hover')){
    $variables['attributes']['class'][] = 'table-hover';
  }
}


function material_dashboard_preprocess_views_view_table(&$vars) {
  $vars['classes_array'][] = 'table';
  if (!in_array('table-no-striping', $vars['classes_array']) && theme_get_setting('table_striped')) {
    $vars['classes_array'][] = 'card table-striped';
  }

  if(theme_get_setting('table_bordered')){
    $vars['classes_array'][] = 'table-bordered';
  }
  if(theme_get_setting('table_condensed')){
    $vars['classes_array'][] = 'table-condensed';
  }
  if(theme_get_setting('table_hover')){
    $vars['classes_array'][] = 'table-hover';
  }
}

function material_dashboard_views_flipped_table(&$vars) {
  $vars['classes_array'][] = 'table';
  if (!in_array('table-no-striping', $vars['classes_array']) && theme_get_setting('table_striped')) {
    $vars['classes_array'][] = 'table-striped';
  }

  if(theme_get_setting('table_bordered')){
    $vars['classes_array'][] = 'table-bordered';
  }
  if(theme_get_setting('table_condensed')){
    $vars['classes_array'][] = 'table-condensed';
  }
  if(theme_get_setting('table_hover')){
    $vars['classes_array'][] = 'table-hover';
  }
}
