<?php
function eps_diamond_menu_local_tasks(&$variables) {
  $output = '';

  if (!empty($variables['primary'])) {
    $variables['primary']['#prefix'] = '<div class="tab-container">';
    $variables['primary']['#prefix'] .= '<h2 class="hide">' . t('Primary tabs') . '</h2>';
    $variables['primary']['#prefix'] .= '<ul class="tabs--primary nav nav-tabs">';
    $variables['primary']['#suffix'] = '</ul>';
    $variables['primary']['#suffix'] .= '</div>';
    $output .= drupal_render($variables['primary']);
  }

  if (!empty($variables['secondary'])) {
    $variables['secondary']['#prefix'] = '<div class="tab-container">';
    $variables['secondary']['#prefix'] .= '<h2 class="hide">' . t('Secondary tabs') . '</h2>';
    $variables['secondary']['#prefix'] .= '<ul class="tabs--secondary pagination pagination-sm">';
    $variables['secondary']['#suffix'] = '</ul>';
    $variables['secondary']['#suffix'] .= '</div>';
    $output .= drupal_render($variables['secondary']);
  }
  return $output;
}
