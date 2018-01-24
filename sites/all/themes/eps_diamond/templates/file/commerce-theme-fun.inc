<?php
/**
 * Themes the optional checkout review page data.
 */

function eps_diamond_commerce_checkout_review($variables) {
  $form = $variables['form'];

  // Turn the review data array into table rows.
  $rows = array();

  foreach ($form['#data'] as $pane_id => $data) {
    // First add a row for the title.
    $className = '';
    if(!empty($pane_id)){
      $className = str_replace("_", "-", trim(strtolower($pane_id)));
    }
    $rows[] = array(
      'data' => array(
        array('data' => $data['title'], 'colspan' => 2),
      ),
      'class' => array('pane-title', 'odd',$className.'-title'),
    );

    // Next, add the data for this particular section.
    if (is_array($data['data'])) {
      // If it's an array, treat each key / value pair as a 2 column row.
      foreach ($data['data'] as $key => $value) {
        $rows[] = array(
          'data' => array(
            array('data' => $key .':', 'class' => array('pane-data-key')),
            array('data' => $value, 'class' => array('pane-data-value')),
          ),
          'class' => array('pane-data', 'even'),
        );
      }
    }
    else {
      // Otherwise treat it as a block of text in its own row.
      $rows[] = array(
        'data' => array(
          array('data' => $data['data'], 'colspan' => 2, 'class' => array('pane-data-full')),
        ),
        'class' => array('pane-data', 'even',$className.'-data'),
      );
    }
  }

  return theme('table', array('rows' => $rows, 'attributes' => array('class' => array('checkout-review'))));
}
