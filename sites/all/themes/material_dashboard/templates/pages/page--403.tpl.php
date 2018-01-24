<div class="app app-header-fixed ">
  <div class="container w-xxl w-auto-xs">
    <?php 
      if (!empty($logo)):
        $log_img = theme('image', array('path' => $logo,'alt' => $site_name,'title' => $site_name,'class'=>'full-logo'));
        print l($log_img, $front_page,  array('html' => TRUE,'attributes' => array('title' => $site_name,'class'=>array("navbar-brand","block m-t","logo-block"))));
      elseif (!empty($site_name)):
        print l('<span>'.$site_name.'</span>', $front_page,  array('attributes' => array('title' => $site_name)));
      endif;
    ?>
    <div class="m-b-lg">
      <?php if(!empty($messages)) { print $messages; } ?>
      <?php if(!empty($page['content_top'])): print render($page['content_top']); endif; ?>
      <?php if(!empty($page['content'])): print render($page['content']); endif; ?>
      <?php if(!empty($page['content_bottom'])): print render($page['content_bottom']); endif; ?>
    </div>
    <?php if (!empty($page['footer'])): ?>
      <div class="text-center"><?php print render($page['footer']); ?></div>
    <?php endif;?>
  </div>
</div>