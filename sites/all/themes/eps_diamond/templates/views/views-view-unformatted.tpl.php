<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<div class="panel panel-default">
  <?php if (!empty($title)) : ?>
    <div class="panel-heading"><?php print $title; ?></div>
  <?php endif; ?>
  <div class="panel-body">
    <?php foreach ($rows as $id => $row): ?>
      <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
        <?php print $row; ?>
      </div>
    <?php endforeach; ?>
  </div>
</div>
