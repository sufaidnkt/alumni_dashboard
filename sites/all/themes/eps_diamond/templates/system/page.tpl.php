<div class="app <?php print $fixed_header.' '.$fixed_aside.' '.$folded_aside.' '.$dock_aside.' '.$boxed_layout.' '.$aside_width ?>">
  <!-- header -->
  <header id="header" class="app-header navbar" role="menu">
    <!-- navbar header -->
    <div class="navbar-header <?php print $navbar_header_color;?> text-center logo-wrapper" id="navbar-header">
      <button class="pull-right visible-xs dk" ui-toggle-class="show" target=".navbar-collapse">
        <i class="glyphicon glyphicon-cog"></i>
      </button>
      <button class="pull-right visible-xs" ui-toggle-class="off-screen" target=".app-aside" ui-scroll="app">
        <i class="glyphicon glyphicon-align-justify"></i>
      </button>
      <!-- brand -->
      <!--  Logo block -->

      <?php

        if (!empty($logo)):
          $log_img = theme('image', array('path' => $logo,'alt' => $site_name,'title' => $site_name, 'attributes' => array('class'=>array('full-logo'))));
          $log_img .= theme('image', array('path' => $logo_icon,'alt' => $site_name,'title' => $site_name,'attributes' => array('class'=>'logo-icon')));
          print l($log_img, '<front>',  array('html' => TRUE,'attributes' => array('title' => $site_name,'class'=>array("navbar-brand","text-lt"))));
        elseif (!empty($site_name)):
          print l('<span>'.$site_name.'</span>', '<front>',  array('attributes' => array('title' => $site_name)));
        endif;
      ?>
      <!--  END -> Logo block -->

      <!-- / brand -->
    </div>
    <!-- / navbar header -->
    <!-- navbar collapse -->
    <div class="collapse pos-rlt navbar-collapse box-shadow <?php print $navbar_collapse_color;?>" id="navbar-collapse">
      <?php require_once(dirname(__FILE__)."/header-block.inc.php"); ?>
      <!-- Header Block -->
      <?php if (!empty($page['header'])): print render($page['header']); endif; ?>
      <!-- END -> Header Block -->
    </div>
    <!-- / navbar collapse -->
  </header>
  <!-- / header -->



  <?php if(!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation']) || !empty($page['profile']) || !empty($page['navigation_bottom'])): ?>
  <!-- aside -->
  <aside id="aside" class="app-aside hidden-xs <?php print $aside_color;?>">
      <div class="aside-wrap">
        <div class="navi-wrap">
          <?php if(!empty($page['profile'])): ?>
          <!-- user profile -->
          <div class="clearfix hidden-xs text-center hide" id="aside-user">
            <?php print render($page['profile']); ?>
          </div>
          <!-- / user profile-->
          <?php endif; ?>
          <?php if(!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
          <!-- nav -->
          <nav ui-nav class="navi clearfix">
            <?php if (!empty($primary_nav)):  print render($primary_nav); endif; ?>
            <?php if (!empty($secondary_nav)):  print render($secondary_nav); endif; ?>
            <?php if (!empty($page['navigation'])): print render($page['navigation']); endif; ?>
          </nav>
          <!-- nav -->
          <?php endif; ?>
          <?php if(!empty($page['navigation_bottom'])): ?>
          <!-- aside footer -->
          <div class="wrapper m-t"><?php print render($page['navigation_bottom']);?></div>
          <!-- / aside footer -->
          <?php endif; ?>
        </div>
      </div>
  </aside>
  <!-- / aside -->
  <?php endif; ?>

  <!-- content -->
  <div id="content" class="app-content" role="main">
    <div class="app-content-body ">
      <div class="hbox hbox-auto-xs hbox-auto-sm">
        <?php if (!empty($page['sidebar_first']) || !empty($page['sidebar_first_footer'])): ?>
          <div class="col w-md lter b-r">
              <?php if(!empty($page['sidebar_first'])): print render($page['sidebar_first']); endif; ?>
              <?php if(!empty($page['sidebar_first_footer'])): print render($page['sidebar_first_footer']); endif; ?>
          </div>
        <?php endif;?>

        <?php if (!empty($page['title_extra']) || !empty($page['content_top']) || !empty($page['content']) || !empty($page['analytics_left'])  || !empty($page['analytics_right']) || !empty($page['notifications']) || !empty($page['statitics_left']) || !empty($page['statitics_right'])|| !empty($page['content_bottom'])): ?>
          <div class="col">
          <?php if(!empty($title) || !empty($title_prefix) || !empty($title_suffix) || !empty($page['title_extra'])): ?>
          <!-- main header -->
          <div class="bg-light lter b-b wrapper-md">
            <div class="row">
              <div class="<?php print $title_class; ?>">
                <?php if (!empty($title_prefix)): ?>
                  <small class="text-muted"><?php print render($title_prefix); ?></small>
                <?php endif; ?>
                <?php if (!empty($title)): ?>
                  <h1 class="m-n h3"><?php print $title; ?></h1>
                <?php endif; ?>
                <?php if (!empty($title_suffix)): ?>
                  <small class="text-muted"><?php print render($title_suffix); ?></small>
                <?php endif; ?>
                <?php if(!empty($breadcrumb)): print $breadcrumb; endif; ?>
              </div>
              <?php if(!empty($page['title_extra'])): ?>
                <div class="<?php print $title_extra_class; ?>">
                  <?php print render($page['title_extra']); ?>
                </div>
              <?php endif; ?>
              <!-- sreeram -->
             
            </div>
          </div>
          <!-- / main header -->
          <?php endif;?>

          <!-- main content -->
          <div class="wrapper-md <?php print $user_profile_class; ?>">
            <?php if(!empty($page['announcements']) || !empty($page['help'])): ?>

            <div class="row">
                <div class="row">
                  <?php print render($page['announcements']); ?>
                  <?php print render($page['help']); ?>
                </div>
            </div>
            <?php endif; ?>
            <?php if(!empty($page['panel_grid']) || !empty($page['analytics_right'])): ?>
            <!-- stats -->

            <div class="row">
              <?php if(!empty($page['panel_grid'])): ?>
              <div class="<?php print $panel_grid_class; ?>">
                <div class="row text-center">
                  <?php print render($page['panel_grid']); ?>
                </div>
              </div>
              <?php endif; ?>

              <?php if(!empty($page['analytics_right'])): ?>
              <div class="<?php print $analytics_right_class; ?>">
                <?php print render($page['analytics_right']); ?>
              </div>
              <?php endif; ?>
            </div>
            <!-- / stats -->
            <?php endif; ?>

            <?php if(!empty($page['analytics_left']) || !empty($page['notifications'])): ?>
            <!-- service -->
            <div class="panel hbox hbox-auto-xs no-border">
              <?php if(!empty($page['analytics_left'])): ?>
              <div class="col wrapper">
                <?php print render($page['analytics_left']); ?>
              </div>
              <?php endif; ?>
              <?php if(!empty($page['notifications'])): ?>
              <div class="col wrapper-lg w-lg bg-light dk r-r">
                <?php print render($page['notifications']); ?>
              </div>
              <?php endif; ?>
            </div>
            <!-- / service -->
            <?php endif;?>

            <?php if(!empty($page['statitics_left']) || !empty($page['statitics_right'])): ?>
            <!-- statitics -->
            <div class="panel wrapper">
              <div class="row">
                <?php if(!empty($page['statitics_left'])): ?>
                <div class="<?php print $statitics_left_class; ?>">
                  <?php print render($page['statitics_left']); ?>
                </div>
                <?php endif; ?>

                <?php if(!empty($page['statitics_right'])): ?>
                <div class="  dk r-r <?php print $statitics_right_class; ?>">
                  <?php print render($page['statitics_right']); ?>
                </div>
                <?php endif; ?>
              </div>
            </div>
            <!-- / statitics -->
            <?php endif;?>

            <?php if(!empty($page['grid_block_left']) || !empty($page['grid_block_right'])): ?>
            <!-- grid block -->
            <div class="panel wrapper">
              <div class="row">
                <?php if(!empty($page['grid_block_left'])): ?>
                <div class="<?php print $grid_block_left_class; ?>">
                  <?php print render($page['grid_block_left']); ?>
                </div>
                <?php endif; ?>

                <?php if(!empty($page['grid_block_right'])): ?>
                <div class="<?php print $grid_block_right_class; ?>">
                  <?php print render($page['grid_block_right']); ?>
                </div>
                <?php endif; ?>
              </div>
            </div>
            <!-- / grid block -->
            <?php endif;?>

            <?php if(!empty($page['content_top']) || !empty($page['content']) || !empty($page['content_bottom'])): ?>
            <!-- content -->
            <div class="row">
              <div class="col-md-12">
              <?php $page_container_class_status = _page_container(); ?>
              <?php if(!empty($page_container_class_status)) { print '<div class="mw-650 mr-auto">';} ?>
              <?php if(!empty($page['content_top'])): print render($page['content_top']); endif; ?>
              <?php $arg_1 = arg(0); $arg_2 = arg(1); if(!(user_is_logged_in() && !empty($arg_1) && $arg_1=='user' && (empty($arg_2) || is_numeric($arg_2)))){ ?>
                <?php if ($tabs): print render($tabs); endif; ?>
              <?php } ?>
              <?php if(!empty($page['content'])): print render($page['content']); endif; ?>
              <?php if(!empty($page['content_bottom'])): print render($page['content_bottom']); endif; ?>
              <?php if(!empty($page_container_class_status)) { print '</div>';} ?>
              </div>
            </div>
            
            <!-- / content -->
            <?php endif;?>
          </div>
          <!-- / main content -->
          </div>
        <?php endif;?>

        <?php if (!empty($page['sidebar_second']) || !empty($page['sidebar_second_footer']) ): ?>
          <div class="col w-md bg-white-only b-l bg-auto no-border-xs">
            <?php if(!empty($page['sidebar_second'])): print render($page['sidebar_second']); endif; ?>
            <?php if(!empty($page['sidebar_second_footer'])): print render($page['sidebar_second_footer']); endif; ?>

          </div>
        <?php endif;?>


      </div>
    </div>

  </div>
  <!-- /content -->
  <?php print $messages; ?>
  <?php if (!empty($page['footer'])): ?>
  <!-- footer -->
  <footer id="footer" class="app-footer" role="footer">
    <div class="wrapper b-t bg-light">
      <?php print render($page['footer']); ?>
       <p class="text-muted"><?php print date('Y-M-d h:i A', afl_date()); ?></p>

    </div>
  </footer>
  <!-- / footer -->
  <?php endif; ?>
  <?php if(theme_get_setting('color_switcher') && (current_path()=='afl/dashboard')){ require_once(dirname(__FILE__) ."/../file/color-switcher-block.inc"); } ?>
</div>




