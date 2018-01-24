<div class="app app-header-fixed ">
    <div class="container <?php print $container_class;?>  w-auto-xs">
      <?php
        if (!empty($logo)):
          $log_img = theme('image', array('path' => $logo,'alt' => $site_name,'title' => $site_name,'class'=>'full-logo'));
          print l($log_img, $front_page,  array('html' => TRUE,'attributes' => array('title' => $site_name,'class'=>array("navbar-brand","block m-t","logo-block"))));
        elseif (!empty($site_name)):
          print l('<span>'.$site_name.'</span>', $front_page,  array('attributes' => array('title' => $site_name)));
        endif;
      ?>
      <div class="m-b-lg">
        <div class="wrapper text-center">
          <?php if (!empty($title_prefix)): ?>
            <span class="text-muted"><?php print render($title_prefix); ?></span>
          <?php endif; ?>
          <?php if (!empty($title) && (arg(0) && arg(1) ) ): ?>
            <strong><?php print $title; ?></strong>
          <?php endif; ?>
          <?php if (!empty($title_suffix)): ?>
            <span class="text-muted"><?php print render($title_suffix); ?></span>
          <?php endif; ?>
        </div>
          <?php print $messages; ?>
          <?php if(!empty($page['content_top'])): print render($page['content_top']); endif; ?>
          <?php if(!empty($tabs['#primary']) && isset($tabs['#primary'][1]['#link']['path']) && $tabs['#primary'][1]['#link']['path'] == 'user/password'): hide($tabs); ?>
          <?php elseif ($tabs): print render($tabs); endif; ?>
          <?php if(!empty($page['content'])): print render($page['content']); endif; ?>
          <?php if(!empty($page['content_bottom'])): print render($page['content_bottom']); endif; ?>
      </div>
      <?php if (!empty($page['footer'])): ?>
        <div class="text-center"><?php print render($page['footer']); ?></div>
      <?php endif;?>

    </div>
</div>
