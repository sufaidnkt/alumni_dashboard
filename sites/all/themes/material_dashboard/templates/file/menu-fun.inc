<?php
/**
 * @file
 * menu-func.inc
 */

/**
 * Overrides theme_menu_tree().
 */
function material_dashboard_menu_tree(&$variables) {
  return '<ul class="nav">' . $variables['tree'] . '</ul>';
}
/**
 * Overrides theme_menu_link().
 */
function material_dashboard_menu_link(array $variables) {
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

      // $element['#below']['attributes']['class'][] = '';
      $sub_menu = '<ul class="dropdown-menu dropdown-menu-right">' . drupal_render($element['#below']) . '</ul>';
      $title_prefix .= '<b class="caret"></b><div class="ripple-container"></div>';

      $element['#attributes']['class'][] = 'dropdown';
      $element['#localized_options']['attributes']['class'][] = 'dropdown-toggle';
      $element['#localized_options']['attributes']['data-toggle'] = 'dropdown';
      $element['#localized_options']['attributes']['role'] = 'tab';
    }
  }
  // On primary navigation menu, class 'active' is not set on active menu item.
  if (($element['#href'] == $_GET['q'] || ($element['#href'] == '<front>' && drupal_is_front_page())) && (empty($element['#localized_options']['language']))) {
    // $element['#attributes']['class'][] = 'active';

  }


  //check the current menu is active
  $active_menu = menu_get_active_trail();

  if (!empty($active_menu[0]['title']) && $active_menu[0]['title'] == $element['#title']) {
    // $element['#attributes']['class'][] = 'active';
  }

  $output = l($title_prefix.$element['#title'], $element['#href'], $element['#localized_options']);

  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}
/**
 * Overrides Email menu().
 */
function material_dashboard_menu_tree__menu_messages_link($variables) {
   return '<div class="wrapper hidden-sm hidden-xs" id="email-menu"><ul class="nav nav-pills nav-stacked nav-sm">'.$variables['tree'] . '</ul></div>';
}

function material_dashboard_menu_item($link, $has_children, $menu = '', $in_active_trail = FALSE, $extra_class = NULL) {
 // Add class for li.
  $variables['element']['#attributes']['class'][] = 'menu-' . $variables['element']['#original_link']['mlid'];
  $variables['element']['#attributes']['class'][] = 'active';
  // Add class for a.
  $variables['element']['#localized_options']['attributes']['class'][] = 'menu-' . $variables['element']['#original_link']['mlid'];
  return theme_menu_link($variables);
}