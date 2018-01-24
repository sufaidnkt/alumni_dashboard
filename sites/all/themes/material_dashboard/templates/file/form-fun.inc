<?php

function material_dashboard_form($variables) {

  $element = $variables['element'];

 
 
  if (isset($element['#action'])) {
    $element['#attributes']['action'] = drupal_strip_dangerous_protocols($element['#action']);
  }
  element_set_attributes($element, array('method', 'id'));
  if (empty($element['#attributes']['accept-charset'])) {
    $element['#attributes']['accept-charset'] = "UTF-8";
  }
  $suffix = $prefix = '';
  if(!empty($element['#title'])){
    $prefix = '<div class="panel panel-default"><div class="panel-heading font-bold">'.$element['#title'].'</div><div class="panel-body">';
    $suffix = '</div></div>';
  }

  $div_class =  (empty($element['#attributes']['class']) && empty($element['#title'])) ? ' class="from-panel"' : '';
  $div_class =  (empty($div_class) && !empty($element['#inner_div'])) ? ' class="'.$element['#inner_div'].'"' : $div_class;

  // Anonymous DIV to satisfy XHTML compliance.
  return $prefix.'<form' . drupal_attributes($element['#attributes']) . '><div'.$div_class.'>' . $element['#children'] . '</div></form>'.$suffix;
}



function material_dashboard_file_managed_file($variables) {
  $element = $variables['element'];
  $attributes = array();
  if (isset($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  if (!empty($element['#attributes']['class'])) {
    $attributes['class'] = (array) $element['#attributes']['class'];
  }
  $attributes['class'][] = 'form-managed-file';
  $attributes['class'][] = 'form-control';
  $attributes['class'][] = 'managed-file';

  // This wrapper is required to apply JS behaviors and CSS styling.
  $output = '';
  $output .= '<div' . drupal_attributes($attributes) . '>';
  $output .= drupal_render_children($element);
  $output .= '</div>';
  return $output;
}


function material_dashboard_file($variables) {
$element = $variables['element'];
  // $element['#attributes']['ui-jq'] = 'filestyle';
  // $element['#attributes']['data-icon'] = "false";
  // $element['#attributes']['data-classButton'] = 'btn btn-default';
  // $element['#attributes']['data-classInput'] = 'form-control inline v-middle input-s';
  // element_set_attributes($element, array('id', 'name', 'size'));
  // _form_set_class($element, array('form-file'));

  $element = $variables['element'];
  $element['#attributes']['type'] = 'file';
  element_set_attributes($element, array('id', 'name', 'size'));
  _form_set_class($element, array('form-file'));

  return '<input' . drupal_attributes($element['#attributes']) . ' />';
}

function material_dashboard_date($variables) {
  $element = $variables['element'];

  $attributes = array();
  if (isset($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  if (!empty($element['#attributes']['class'])) {
    $attributes['class'] = (array) $element['#attributes']['class'];
  }
  $attributes['class'][] = 'container-inline dates';

  return '<div' . drupal_attributes($attributes) . '>' . drupal_render_children($element) . '</div>';
}

function material_dashboard_form_element_label($variables) {
  global $bootstrap_form;

  $element = $variables['element'];
  // This is also used in the installer, pre-database setup.
  $t = get_t();

  // If title and required marker are both empty, output no label.
  if ((!isset($element['#title']) || $element['#title'] === '') && empty($element['#required'])) {
    return '';
  }

  // If the element is required, a required marker is appended to the label.
  $required = !empty($element['#required']) ? theme('form_required_marker', array('element' => $element)) : '';

  $title = filter_xss_admin($element['#title']);

  $attributes = array();
  // Style the label as class option to display inline with the element.
  if ($element['#title_display'] == 'after') {
    $attributes['class'] = 'option';
  }
  // Show label only to screen readers to avoid disruption in visual flows.
  elseif ($element['#title_display'] == 'invisible') {
    $attributes['class'] = 'element-invisible';
  }

  if (!empty($element['#id'])) {
    $attributes['for'] = $element['#id'];
  }
  if(isset($element['#bootstrap']['form_horizontal']) && !empty($element['#bootstrap']['form_horizontal'])){
    $attributes['class'] = !empty($element['#bootstrap']['grid_label']) ? $element['#bootstrap']['grid_label']: 'col-lg-2';
  }elseif(!empty($bootstrap_form['form_horizontal']) && !empty($element['#type']) && ($element['#type']!='radio' &&  $element['#type']!='checkbox')){
    $attributes['class'] = !empty($bootstrap_form['grid_label']) ? $bootstrap_form['grid_label']: 'col-lg-2';
  }
  // The leading whitespace helps visually separate fields from inline labels.
  return ' <label' . drupal_attributes($attributes) . '>' . $t('!title !required', array('!title' => $title, '!required' => $required)) . "</label>\n";
}



/** Theme form element **/
function material_dashboard_form_element($variables) {
  
  global $bootstrap_form;
  $element = &$variables['element'];
 
  // This function is invoked as theme wrapper, but the rendered form element
  // may not necessarily have been processed by form_builder().
  $element += array(
    '#title_display' => 'before',
  );

  // Add element #id for #type 'item'.
  if (isset($element['#markup']) && !empty($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  // Add element's #type and #name as class to aid with JS/CSS selectors.
  if(!empty($element['#wrapper_attributes'])){
    $attributes = $element['#wrapper_attributes'];
  }else{
    $attributes['class'] = array('form-item');
  }
  if(!empty($element['#autocomplete_path'])){
    $attributes['class'][] = 'form-autocomplete';
  }
  if(empty($element['#bootstrap']['form_horizontal']) && empty($bootstrap_form['form_horizontal'])){
    $attributes['class'][] = 'clearfix';
  }
  if (!empty($element['#type'])) {
    $attributes['class'][] = 'form-type-' . strtr($element['#type'], '_', '-');
  }
  if (!empty($element['#name'])) {
    $attributes['class'][] = 'form-item-' . strtr($element['#name'], array(' ' => '-', '_' => '-', '[' => '-', ']' => ''));
  }
  // Add a class for disabled elements to facilitate cross-browser styling.
  if (!empty($element['#attributes']['disabled'])) {
    $attributes['class'][] = 'form-disabled';
  }
  if (isset($element['#parents']) && form_get_error($element)) {
    $attributes['class'][] = 'has-error';
  }
  if($element['#type']== 'radio'){
    if(isset($element['#bootstrap']['form_horizontal']) && !empty($element['#bootstrap']['form_horizontal']) && $element['#title_display'] == 'after'){
      $element['#title_display'] = 'before';
      $attributes['class'][] = 'form-group';
    }else{
      $attributes['class'][] = 'radio';
    }
  }elseif($element['#type']== 'checkbox'){
    if(isset($element['#bootstrap']['form_horizontal']) && !empty($element['#bootstrap']['form_horizontal']) && $element['#title_display'] == 'after'){
      $element['#title_display'] = 'before';
      $attributes['class'][] = 'form-group';
    }


  }else{
    $attributes['class'][] = 'form-group';
  }

  $description = FALSE;
  $tooltip = FALSE;
  // Convert some descriptions to tooltips.
  // @see bootstrap_tooltip_descriptions setting in _bootstrap_settings_form()
  if (!empty($element['#description'])) {
    $description = $element['#description'];
    if (theme_get_setting('bootstrap_tooltip_enabled') &&  strlen($description) <= 300) {
      $tooltip = TRUE;
      $attributes['data-toggle'] = 'tooltip';
      $attributes['title'] = strip_tags($description);
    }
  }

  $output = '<div' . drupal_attributes($attributes) . '>' . "\n";

  // If #title is not set, we don't display any label or required marker.
  if (!isset($element['#title'])) {
    $element['#title_display'] = 'none';
  }
  $prefix = isset($element['#field_prefix']) ? '<span class="field-prefix">' . $element['#field_prefix'] . '</span> ' : '';
  $suffix = isset($element['#field_suffix']) ? ' <span class="field-suffix">' . $element['#field_suffix'] . '</span>' : '';

  switch ($element['#title_display']) {
    case 'before':
    case 'invisible':
        $output .= ' ' . theme('form_element_label', $variables);

        if(isset($element['#bootstrap']['form_horizontal']) && !empty($element['#bootstrap']['form_horizontal'])){
          $grid_field['class'] = !empty($element['#bootstrap']['grid_field']) ? $element['#bootstrap']['grid_field']: 'col-lg-10';
          $output .= '<div' . drupal_attributes($grid_field) . '>' . "\n";
        }elseif(!empty($bootstrap_form['form_horizontal'])){
          $grid_field['class'] = !empty($bootstrap_form['grid_field']) ? $bootstrap_form['grid_field']: 'col-lg-10';
          $output .= '<div' . drupal_attributes($grid_field) . '>' . "\n";
        }
        $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";

        if (!empty($element['#description']) && !$tooltip) {
          $output .= '<div class="description text-gray">' . $element['#description'] . "</div>\n";
        }
        if((isset($element['#bootstrap']['form_horizontal']) && !empty($element['#bootstrap']['form_horizontal'])) || !empty($bootstrap_form['form_horizontal'])){
          $output .= "</div>\n";
        }

      break;

    case 'after':
      if(isset($element['#bootstrap']['form_horizontal']) && !empty($element['#bootstrap']['form_horizontal'])){
        $grid_field['class'] = !empty($element['#bootstrap']['grid_field']) ? $element['#bootstrap']['grid_field']: 'col-lg-10';
        $output .= '<div' . drupal_attributes($grid_field) . '>' . "\n";
      }elseif(!empty($bootstrap_form['form_horizontal']) && !empty($element['#array_parents']) && count($element['#array_parents'])<2){
        $grid_field['class'] = !empty($bootstrap_form['grid_field']) ? $bootstrap_form['grid_field']: 'col-lg-10';
        $output .= '<div' . drupal_attributes($grid_field) . '>' . "\n";
      }
      $output .= ' ' . $prefix . $element['#children'] . $suffix;
      if (!empty($element['#description']) && !$tooltip) {
        $output .= '<div class="description text-gray">' . $element['#description'] . "</div>\n";
      }
      if((isset($element['#bootstrap']['form_horizontal']) && !empty($element['#bootstrap']['form_horizontal'])) || (!empty($bootstrap_form['form_horizontal'])  && !empty($element['#array_parents']) && count($element['#array_parents'])<2)){
        $output .= "</div>\n";
      }
      $output .= ' ' . theme('form_element_label', $variables) . "\n";
      break;

    case 'none':
    case 'attribute':
      // Output no label and no required marker, only the children.
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;
  }
  // remove description we'll use placeholder.


  $output .= "</div>\n";

  return $output;
}

//add class to buttons
function material_dashboard_button($variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'submit';
  element_set_attributes($element, array('id', 'name', 'value'));

  $element['#attributes']['class'][] = 'form-' . $element['#button_type'];
  $element['#attributes']['class'][] = 'btn';
  // adding bootstrap classes.
  if($element['#button_type'] == 'submit'){
    $element['#attributes']['class'][] =  _material_dashboard_colorize_button($element['#value']);
  }

  if (!empty($element['#attributes']['disabled'])) {
    $element['#attributes']['class'][] = 'form-button-disabled';
  }

  return '<input' . drupal_attributes($element['#attributes']) . ' />';
}
function material_dashboard_radio($variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'radio';
  element_set_attributes($element, array('id', 'name', '#return_value' => 'value'));

  if (isset($element['#return_value']) && $element['#value'] !== FALSE && $element['#value'] == $element['#return_value']) {
    $element['#attributes']['checked'] = 'checked';
  }
  _form_set_class($element, array('form-radio','radio'));

  return '<label class="i-checks"><input' . drupal_attributes($element['#attributes']) . ' /><i></i></label>';
}

function material_dashboard_radios($variables) {
  $element = $variables['element'];
  $attributes = array();
  if (isset($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  $attributes['class'] = 'form-radios';
  if (!empty($element['#attributes']['class'])) {
    $attributes['class'] .= ' ' . implode(' ', $element['#attributes']['class']);
  }
  if (isset($element['#attributes']['title'])) {
    $attributes['title'] = $element['#attributes']['title'];
  }
  return '<div' . drupal_attributes($attributes) . '>' . (!empty($element['#children']) ? $element['#children'] : '') . '</div>';
}
/**** theme form textfields. ***/
function material_dashboard_textfield($variables) {
  $element = $variables['element'];
  $output = '';

  // force type.
  $element['#attributes']['type'] = 'text';
  // set placeholder.
  // if(isset($variables['element']['#description'])){
  //   $element['#attributes']['placeholder'] = $variables['element']['#description'];
  // }

  element_set_attributes($element, array('id', 'name', 'value', 'size', 'maxlength'));
  // adding bootstrap classes.
 _form_set_class($element, array('form-text', 'form-control', 'input-lg-3'));

  $extra = '';
  if ($element['#autocomplete_path'] && drupal_valid_path($element['#autocomplete_path'])) {
    drupal_add_library('system', 'drupal.autocomplete');
    $element['#attributes']['class'][] = 'form-autocomplete';

    $attributes = array();
    $attributes['type'] = 'hidden';
    $attributes['id'] = $element['#attributes']['id'] . '-autocomplete';
    $attributes['value'] = url($element['#autocomplete_path'], array('absolute' => TRUE));
    $attributes['disabled'] = 'disabled';
    $attributes['class'][] = 'autocomplete';

    $extra = '<span class="icon glyphicon glyphicon-refresh form-control-feedback" aria-hidden="true"></span>';



    $extra .= '<input' . drupal_attributes($attributes) . ' />';

  }

  if(isset($element['#attributes']['groupfields']) ){
    $output .= '<div class="input-group m-b">';
  }
  if(isset($element['#attributes']['groupfields']['prefix']) ){
    $output .= '<span class="input-group-addon">'.$element['#attributes']['groupfields']['prefix'].'</span>';
  }
  $output .= '<input' . drupal_attributes($element['#attributes']) . ' />';
  if(isset($element['#attributes']['groupfields']['suffix']) ){
    $output .= '<span class="input-group-addon">'.$element['#attributes']['groupfields']['suffix'].'</span>';
  }
  if(isset($element['#attributes']['groupfields']) ){
     $output .= '</div>';
  }
  if(!empty($element['#attributes']['currency'])){
      $output ='';
      $output .= '<div class="input-group m-b">';
      $output .=    '<span class="input-group-addon">$</span>';
      $output .= '<input' . drupal_attributes($element['#attributes']) . ' />';
      $output .=  '<span class="input-group-addon">.00</span>';
      $output .=  '</div>';
  
 }
  return $output . $extra;
}

function material_dashboard_select($variables) {
  $element = $variables['element'];
  element_set_attributes($element, array('id', 'name', 'size'));
  _form_set_class($element, array('form-select','form-control'));

  return '<select' . drupal_attributes($element['#attributes']) . '>' . form_select_options($element) . '</select>';
}
function material_dashboard_checkbox($variables) {
   $element = $variables['element'];
  $element['#attributes']['type'] = 'checkbox';
  element_set_attributes($element, array('id', 'name', '#return_value' => 'value'));

  // Unchecked checkbox has #value of integer 0.
  if (!empty($element['#checked'])) {
    $element['#attributes']['checked'] = 'checked';
  }
  _form_set_class($element, array('form-checkbox','checkbox'));
  if(!empty($element['#attributes']['switch'])){
    return '<label class="i-switch m-t-xs m-r"><input' . drupal_attributes($element['#attributes']) . ' /><i></i></label>';
  }
  return '<label class="i-checks"><input' . drupal_attributes($element['#attributes']) . ' /><i></i></label>';
}
function material_dashboard_checkboxes($variables) {
  $element = $variables['element'];
  $attributes = array();
  if (isset($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  $attributes['class'][] = 'form-checkboxes';
  if (!empty($element['#attributes']['class'])) {
    $attributes['class'] = array_merge($attributes['class'], $element['#attributes']['class']);
  }
  if (isset($element['#attributes']['title'])) {
    $attributes['title'] = $element['#attributes']['title'];
  }
  return '<div' . drupal_attributes($attributes) . '>' . (!empty($element['#children']) ? $element['#children'] : '') . '</div>';
}
/*** theme password field ***/
function material_dashboard_password($variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'password';
  element_set_attributes($element, array('id', 'name', 'size', 'maxlength'));
  _form_set_class($element, array('form-text', 'form-control'));

  return '<input' . drupal_attributes($element['#attributes']) . ' />';
}

function material_dashboard_textarea($variables) {
  $element = $variables['element'];
  element_set_attributes($element, array('id', 'name', 'cols', 'rows'));
  _form_set_class($element, array('form-textarea','form-control'));

  $wrapper_attributes = array(
    'class' => array('form-textarea-wrapper'),
  );

  // Add resizable behavior.
  if (!empty($element['#resizable'])) {
    drupal_add_library('system', 'drupal.textarea');
    $wrapper_attributes['class'][] = 'resizable';
  }

  $output = '<div' . drupal_attributes($wrapper_attributes) . '>';
  $output .= '<textarea' . drupal_attributes($element['#attributes']) . '>' . check_plain($element['#value']) . '</textarea>';
  $output .= '</div>';
  return $output;
}

function _material_dashboard_colorize_button($text) {
  $generic_strings[drupal_strtolower(t('Download feature'))] = 'btn-primary';
  $generic_strings[drupal_strtolower(t('Save'))] = 'btn-primary';
  $generic_strings[drupal_strtolower(t('Confirm'))] = 'btn-primary';
  $generic_strings[drupal_strtolower(t('Submit'))] = 'btn-primary';
  $generic_strings[drupal_strtolower(t('Search'))] = 'btn-primary';

  $generic_strings[drupal_strtolower(t('Add effect'))] = 'btn-success';
  $generic_strings[drupal_strtolower(t('Add and configure'))] = 'btn-success';
  $generic_strings[drupal_strtolower(t('Add'))] = 'btn-success';
  $generic_strings[drupal_strtolower(t('Create'))] = 'btn-success';
  $generic_strings[drupal_strtolower(t('Write'))] = 'btn-success';

  $generic_strings[drupal_strtolower(t('Export'))] = 'btn-warning';
  $generic_strings[drupal_strtolower(t('Import'))] = 'btn-warning';
  $generic_strings[drupal_strtolower(t('Restore'))] = 'btn-warning';
  $generic_strings[drupal_strtolower(t('Rebuild'))] = 'btn-warning';

  $generic_strings[drupal_strtolower(t('Apply'))] = 'btn-info';
  $generic_strings[drupal_strtolower(t('Update'))] = 'btn-info';
  $generic_strings[drupal_strtolower(t('Save and add'))] = 'btn-info';
  $generic_strings[drupal_strtolower(t('Add another item'))] = 'btn-info';
  $generic_strings[drupal_strtolower(t('Update style'))] = 'btn-info';
  $generic_strings[drupal_strtolower(t('Preview'))] = 'btn-info';
  $generic_strings[drupal_strtolower(t('Clear'))] = 'btn-info';

  $generic_strings[drupal_strtolower(t('Delete'))] = 'btn-danger';
  $generic_strings[drupal_strtolower(t('Remove'))] = 'btn-danger';

  return !empty($generic_strings[drupal_strtolower($text)]) ? $generic_strings[drupal_strtolower($text)] : 'btn-primary';
}
 /**
 * Theme function for a CAPTCHA element.
 *
 * Render it in a fieldset if a description of the CAPTCHA
 * is available. Render it as is otherwise.
 */
function material_dashboard_captcha($variables) {
  $element = $variables['element'];
  if (!empty($element['#description']) && isset($element['captcha_widgets'])) {
    $html_tag = array('#tag' => 'div','#attributes' => array('class' => array('captcha','form-group','form-captcha-group')));
    $html_tag['#value']  = '<h4>'.t('Security code').'</h4>';
    $html_tag['#value'] .= '<div class="captcha-description">'.$element['#description'].'</div>';
    $html_tag['#value'] .= drupal_render_children($element);
    return theme('html_tag', array('element' => $html_tag));
  }
  else {
    return '<div class="captcha">' . drupal_render_children($element) . '</div>';
  }
}