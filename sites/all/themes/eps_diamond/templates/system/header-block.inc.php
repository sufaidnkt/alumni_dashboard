<!-- collapse buttons -->
<?php if(theme_get_setting('collapse_menu')){ ?>
<div class="nav navbar-nav hidden-xs">
  <?php print l('<i class="fa fa-dedent fa-fw text"></i><i class="fa fa-indent fa-fw text-active"></i>', '#', array('external' => TRUE,'html' => TRUE,'attributes' => array('title' => variable_get('site_name', 'EPS Diamond'),'class'=>array("btn","no-shadow","navbar-btn","btn-aside-folded",$folded_aside ? 'active':NULL),'ui-toggle-class'=>"app-aside-folded"))); ?>
  <?php print l('<i class="icon-user fa-fw"></i>', '#', array('external' => TRUE,'html' => TRUE,'attributes' => array('title' => variable_get('site_name', 'EPS Diamond'),'class'=>array("btn","no-shadow","navbar-btn"),'ui-toggle-class'=>"show",'target'=>"#aside-user"))); ?>
</div>
<?php } ?>
<!-- END -> collapse buttons -->

<!-- link and dropdown -->
<?php if(!empty($page['quick_link']) || theme_get_setting('new_link_name')){ ?>
<ul class="nav navbar-nav hidden-sm">
  <?php if(!empty($page['quick_link'])){ ?>
  <li class="dropdown pos-stc">
    <?php print l('<span>'.t(theme_get_setting('quick_link_name')).'</span><span class="caret"></span>', '#', array('external' => TRUE,'html' => TRUE,'attributes' => array('title' => variable_get('site_name', 'EPS Diamond'),'class'=>array("dropdown-toggle"),"data-toggle"=>"dropdown"))); ?>
    <div class="dropdown-menu wrapper w-full bg-white">
      <div class="row"><?php print render($page['quick_link']); ?></div>
    </div>
  </li>
  <?php } ?>
  <?php if(theme_get_setting('new_link_name') && theme_get_setting('new_link_menu')){ ?>
  <?php $menu = menu_navigation_links(theme_get_setting('new_link_menu')); ?>
  <?php if(!empty($menu)){ ?>
  <li class="dropdown">
    <?php print l('<i class="fa fa-fw fa-plus visible-xs-inline-block"></i><span translate="header.navbar.new.'.t(theme_get_setting('new_link_name')).'">'.t(theme_get_setting('new_link_name')).'</span> <span class="caret"></span>', '#', array('external' => TRUE,'html' => TRUE,'attributes' => array('title' => variable_get('site_name', 'EPS Diamond'),'class'=>array("dropdown-toggle"),"data-toggle"=>"dropdown"))); ?>
      <?php
        print theme('links__system_main_menu', array('links' => $menu,'attributes' => array('role'=>"menu",'class'=>array('dropdown-menu'))));
      ?>
  </li>
  <?php } ?>
  <?php } ?>
</ul>
<?php } ?>
<!-- / link and dropdown -->
