<?php
/**
 * @file
 * menu-func.inc
 */

/**
 * Overrides theme_menu_tree().
 */
function eps_diamond_menu_tree(&$variables) {
  return '<ul class="nav menu-navigation">' . $variables['tree'] . '</ul>';
}
/**
 * Overrides theme_menu_link().
 */
function eps_diamond_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';
  $title_prefix = '';
  if ($element['#below']) {
    // Prevent dropdown functions from being added to management menu so it
    // does not affect the navbar module.
    if (($element['#original_link']['menu_name'] == 'management') && (module_exists('navbar'))) {
      $sub_menu = drupal_render($element['#below']);
    }
    elseif ((!empty($element['#original_link']['depth'])) && ($element['#original_link']['depth'] == 1)) {
      // Add our own wrapper.
      unset($element['#below']['#theme_wrappers']);
      $sub_menu = '<ul class="nav nav-sub dk">' . drupal_render($element['#below']) . '</ul>';
      // Generate as standard dropdown.
      $title_prefix .= ' <span class="pull-right text-muted">';
      $title_prefix .= ' <i class="fa fa-fw fa-angle-right text"></i>';
      $title_prefix .= ' <i class="fa fa-fw fa-angle-down text-active"></i>';
      $title_prefix .= ' </span>';
      $element['#localized_options']['html'] = TRUE;
      $element['#localized_options']['attributes']['class'][] = 'auto';
    }
  }
  // On primary navigation menu, class 'active' is not set on active menu item.
  if (($element['#href'] == $_GET['q'] || ($element['#href'] == '<front>' && drupal_is_front_page())) && (empty($element['#localized_options']['language']))) {
    $element['#attributes']['class'][] = 'active';
  }
  $output = l($title_prefix.$element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}
/**
 * Overrides Email menu().
 */
function eps_diamond_menu_tree__menu_messages_link($variables) {
   return '<div class="wrapper hidden-sm hidden-xs" id="email-menu"><ul class="nav nav-pills nav-stacked nav-sm">'.$variables['tree'] . '</ul></div>';
}
