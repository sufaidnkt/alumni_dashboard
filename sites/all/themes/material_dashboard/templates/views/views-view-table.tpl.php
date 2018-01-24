<?php

/**
 * @file
 * Template to display a view as a table.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $header: An array of header labels keyed by field id.
 * - $caption: The caption for this table. May be empty.
 * - $header_classes: An array of header classes keyed by field id.
 * - $fields: An array of CSS IDs to use for each field id.
 * - $classes: A class or classes to apply to the table, based on settings.
 * - $row_classes: An array of classes to apply to each row, indexed by row
 *   number. This matches the index in $rows.
 * - $rows: An array of row items. Each row is an array of content.
 *   $rows are keyed by row number, fields within rows are keyed by field ID.
 * - $field_classes: An array of classes to apply to each field, indexed by
 *   field id, then row number. This matches the index in $rows.
 * @ingroup views_templates
 */
?>
<div class="panel panel-default aaaa">
  <?php if (!empty($title) || !empty($caption)) : ?>
    <div class="panel-heading"><?php print $caption . $title; ?></div>
  <?php endif; ?>
  <div class="table-responsive">
    <table <?php if ($classes) { print 'class="'. $classes . '" '; } ?><?php print $attributes; ?>>
      <?php if (!empty($header)) : ?>
        <thead>
          <tr>
            <?php foreach ($header as $field => $label): ?>
              <th <?php if ($header_classes[$field]) { print 'class="'. $header_classes[$field] . '" '; } ?>>
                <?php print $label; ?>
              </th>
            <?php endforeach; ?>
          </tr>
        </thead>
      <?php endif; ?>
      <tbody>
        <?php foreach ($rows as $row_count => $row): ?>
          <tr <?php if ($row_classes[$row_count]) { print 'class="' . implode(' ', $row_classes[$row_count]) .'"';  } ?>>
            <?php foreach ($row as $field => $content): ?>
              <td <?php if ($field_classes[$field][$row_count]) { print 'class="'. $field_classes[$field][$row_count] . '" '; } ?><?php print drupal_attributes($field_attributes[$field][$row_count]); ?>>
                <?php print $content; ?>
              </td>
            <?php endforeach; ?>
          </tr>
        <?php endforeach; ?>
      </tbody>
    </table>
  </div>
</div>
<!-- 
<div class="card">
      <div class="card-header" data-background-color="purple">
          <h4 class="title">Simple Table</h4>
          <p class="category">Here is a subtitle for this table</p>
      </div>
      <div class="card-content table-responsive">
          <table class="table">
              <thead class="text-primary">
                  <tr>
                    <?php foreach ($header as $field => $label): ?>
                      <th <?php if ($header_classes[$field]) { print 'class="'. $header_classes[$field] . '" '; } ?>>
                        <?php print $label; ?>
                      </th>
                    <?php endforeach; ?>
                  </tr>
                </thead>
              <tbody>
                  <?php foreach ($rows as $row_count => $row): ?>
                    <tr <?php if ($row_classes[$row_count]) { print 'class="' . implode(' ', $row_classes[$row_count]) .'"';  } ?>>
                      <?php foreach ($row as $field => $content): ?>
                        <td <?php if ($field_classes[$field][$row_count]) { print 'class="'. $field_classes[$field][$row_count] . '" '; } ?><?php print drupal_attributes($field_attributes[$field][$row_count]); ?>>
                          <?php print $content; ?>
                        </td>
                      <?php endforeach; ?>
                    </tr>
                  <?php endforeach; ?>
              </tbody>
          </table>
      </div>
  </div>
 -->