<?php
function material_dashboard_preprocess_block(&$vars) {
  $block_id = $vars['block']->module . '-' . $vars['block']->delta;
  if(theme_get_setting('block_class')){
    $block_class = list_extract_allowed_values(theme_get_setting('block_class'),'list_text',false);
    $block_id = str_replace("_", "-", trim($block_id));
    if(!empty($block_class[$block_id])){
      $vars['classes_array'][] = $block_class[$block_id];
    }else{
      $vars['classes_array'][] = 'clearfix';
    }
  }else{
    $vars['classes_array'][] = 'clearfix';
  }
}
