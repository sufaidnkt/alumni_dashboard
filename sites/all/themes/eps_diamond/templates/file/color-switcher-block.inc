<!-- settings -->
<div class="settings panel panel-default theme-layout-settings">
  <button class="btn btn-default no-shadow pos-abt" ui-toggle-class="active" target=".settings">
    <i class="fa fa-gear"></i>
  </button>
  <div class="panel-heading">
    <a class="pull-right btn btn-xs btn-rounded btn-danger reset-setting" href="#"><?php print t('RESET');?></a>
    <?php print t('Settings'); ?>
  </div>
  <div class="panel-body layout-conf">
    <div class="m-b-sm">
      <label class="i-switch bg-info pull-right">
        <input type="checkbox" <?php print $fixed_header ? 'checked':NULL;?> value="app-header-fixed" cookiekey="headerFixed">
        <i></i>
      </label>
      <?php print t('Fixed header'); ?>
    </div>
    <div class="m-b-sm">
      <label class="i-switch bg-info pull-right">
        <input type="checkbox" <?php print $fixed_aside ? 'checked':NULL;?> value="app-aside-fixed" cookiekey="asideFixed">
        <i></i>
      </label>
      <?php print t('Fixed aside'); ?>
    </div>
    <div class="m-b-sm">
      <label class="i-switch bg-info pull-right">
        <input type="checkbox" <?php print $folded_aside ? 'checked':NULL;?> value="app-aside-folded" cookiekey="asideFolded">
        <i></i>
      </label>
      <?php print t('Folded aside'); ?>
    </div>
    <div class="m-b-sm">
      <label class="i-switch bg-info pull-right">
        <input type="checkbox" <?php print $dock_aside ? 'checked':NULL;?> value="app-aside-dock" cookiekey="asideDock">
        <i></i>
      </label>
      <?php print t('Dock aside'); ?>
    </div>
    <div>
      <label class="i-switch bg-info pull-right">
        <input type="checkbox" <?php print $boxed_layout ? 'checked':NULL;?> value="container" cookiekey="layoutcontainer">
        <i></i>
      </label>
      <?php print t('Boxed layout'); ?>
    </div>
  </div>
  <div class="wrapper b-t b-light bg-light lter r-b color-block">
    <div class="row row-sm">
      <div class="col-xs-6">
        <label class="i-checks block m-b-sm">
          <input type="radio" name="theme-color" navbarheadercolor="bg-black" navbarcollapsecolor="bg-white-only" asidecolor="bg-black" value="1" <?php print ($layout_color_block==1) ? 'checked':NULL;?>>
          <span class="block bg-light clearfix pos-rlt">
            <span class="active pos-abt w-full h-full bg-black-opacity text-center">
              <i class="glyphicon glyphicon-ok text-white m-t-xs"></i>
            </span>
            <b class="bg-black header"></b>
            <b class="bg-white header"></b>
            <b class="bg-black"></b>
          </span>
        </label>

        <label class="i-checks block m-b-sm">
          <input type="radio" name="theme-color" navbarheadercolor="bg-dark" navbarcollapsecolor="bg-white-only" asidecolor="bg-dark" value="2" <?php print ($layout_color_block==2) ? 'checked':NULL;?>>
          <span class="block bg-light clearfix pos-rlt">
            <span class="active pos-abt w-full h-full bg-black-opacity text-center">
              <i class="glyphicon glyphicon-ok text-white m-t-xs"></i>
            </span>
            <b class="bg-dark header"></b>
            <b class="bg-white header"></b>
            <b class="bg-dark"></b>
          </span>
        </label>

        <label class="i-checks block m-b-sm">
          <input type="radio" name="theme-color" navbarheadercolor="bg-white-only" navbarcollapsecolor="bg-white-only" asidecolor="bg-black" value="3" <?php print ($layout_color_block==3) ? 'checked':NULL;?>>
          <span class="block bg-light clearfix pos-rlt">
            <span class="active pos-abt w-full h-full bg-black-opacity text-center">
              <i class="glyphicon glyphicon-ok text-white m-t-xs"></i>
            </span>
            <b class="bg-white header"></b>
            <b class="bg-white header"></b>
            <b class="bg-black"></b>
          </span>
        </label>

        <label class="i-checks block m-b-sm">
          <input type="radio" name="theme-color" navbarheadercolor="bg-primary" navbarcollapsecolor="bg-white-only" asidecolor="bg-dark" value="4" <?php print ($layout_color_block==4) ? 'checked':NULL;?>>
          <span class="block bg-light clearfix pos-rlt">
            <span class="active pos-abt w-full h-full bg-black-opacity text-center">
              <i class="glyphicon glyphicon-ok text-white m-t-xs"></i>
            </span>
            <b class="bg-primary header"></b>
            <b class="bg-white header"></b>
            <b class="bg-dark"></b>
          </span>
        </label>

        <label class="i-checks block m-b-sm">
          <input type="radio" name="theme-color" navbarheadercolor="bg-info" navbarcollapsecolor="bg-white-only" asidecolor="bg-black" value="5" <?php print ($layout_color_block==5) ? 'checked':NULL;?>>
          <span class="block bg-light clearfix pos-rlt">
            <span class="active pos-abt w-full h-full bg-black-opacity text-center">
              <i class="glyphicon glyphicon-ok text-white m-t-xs"></i>
            </span>
            <b class="bg-info header"></b>
            <b class="bg-white header"></b>
            <b class="bg-black"></b>
          </span>
        </label>

        <label class="i-checks block m-b-sm">
          <input type="radio" name="theme-color" navbarheadercolor="bg-success" navbarcollapsecolor="bg-white-only" asidecolor="bg-dark" value="6" <?php print ($layout_color_block==6) ? 'checked':NULL;?>>
          <span class="block bg-light clearfix pos-rlt">
            <span class="active pos-abt w-full h-full bg-black-opacity text-center">
              <i class="glyphicon glyphicon-ok text-white m-t-xs"></i>
            </span>
            <b class="bg-success header"></b>
            <b class="bg-white header"></b>
            <b class="bg-dark"></b>
          </span>
        </label>

        <label class="i-checks block">
          <input type="radio" name="theme-color" navbarheadercolor="bg-danger" navbarcollapsecolor="bg-white-only" asidecolor="bg-dark" value="7" <?php print ($layout_color_block==7) ? 'checked':NULL;?>>
          <span class="block bg-light clearfix pos-rlt">
            <span class="active pos-abt w-full h-full bg-black-opacity text-center">
              <i class="glyphicon glyphicon-ok text-white m-t-xs"></i>
            </span>
            <b class="bg-danger header"></b>
            <b class="bg-white header"></b>
            <b class="bg-dark"></b>
          </span>
        </label>
      </div>
      <div class="col-xs-6">
        <label class="i-checks block m-b-sm">
          <input type="radio" name="theme-color" navbarheadercolor="bg-black" navbarcollapsecolor="bg-black" asidecolor="bg-white b-r" value="8" <?php print ($layout_color_block==8) ? 'checked':NULL;?>>
          <span class="block bg-light clearfix pos-rlt">
            <span class="active pos-abt w-full h-full bg-black-opacity text-center">
              <i class="glyphicon glyphicon-ok text-white m-t-xs"></i>
            </span>
            <b class="bg-black header"></b>
            <b class="bg-black header"></b>
            <b class="bg-white"></b>
          </span>
        </label>

        <label class="i-checks block m-b-sm">
          <input type="radio" name="theme-color" navbarheadercolor="bg-dark" navbarcollapsecolor="bg-dark" asidecolor="bg-light" value="9" <?php print ($layout_color_block==9) ? 'checked':NULL;?>>
          <span class="block bg-light clearfix pos-rlt">
            <span class="active pos-abt w-full h-full bg-black-opacity text-center">
              <i class="glyphicon glyphicon-ok text-white m-t-xs"></i>
            </span>
            <b class="bg-dark header"></b>
            <b class="bg-dark header"></b>
            <b class="bg-light"></b>
          </span>
        </label>

        <label class="i-checks block m-b-sm">
          <input type="radio" name="theme-color" navbarheadercolor="bg-info dker" navbarcollapsecolor="bg-info dker" asidecolor="bg-light dker b-r" value="10" <?php print ($layout_color_block==10) ? 'checked':NULL;?>>
          <span class="block bg-light clearfix pos-rlt">
            <span class="active pos-abt w-full h-full bg-black-opacity text-center">
              <i class="glyphicon glyphicon-ok text-white m-t-xs"></i>
            </span>
            <b class="bg-info dker header"></b>
            <b class="bg-info dker header"></b>
            <b class="bg-light dker"></b>
          </span>
        </label>

        <label class="i-checks block m-b-sm">
          <input type="radio" name="theme-color" navbarheadercolor="bg-primary" navbarcollapsecolor="bg-primary" asidecolor="bg-dark" value="11" <?php print ($layout_color_block==11) ? 'checked':NULL;?>>
          <span class="block bg-light clearfix pos-rlt">
            <span class="active pos-abt w-full h-full bg-black-opacity text-center">
              <i class="glyphicon glyphicon-ok text-white m-t-xs"></i>
            </span>
            <b class="bg-primary header"></b>
            <b class="bg-primary header"></b>
            <b class="bg-dark"></b>
          </span>
        </label>

        <label class="i-checks block m-b-sm">
          <input type="radio" name="theme-color" navbarheadercolor="bg-info dker" navbarcollapsecolor="bg-info dk" asidecolor="bg-black" value="12" <?php print ($layout_color_block==12) ? 'checked':NULL;?>>
          <span class="block bg-light clearfix pos-rlt">
            <span class="active pos-abt w-full h-full bg-black-opacity text-center">
              <i class="glyphicon glyphicon-ok text-white m-t-xs"></i>
            </span>
            <b class="bg-info dker header"></b>
            <b class="bg-info dk header"></b>
            <b class="bg-black"></b>
          </span>
        </label>

        <label class="i-checks block m-b-sm">
          <input type="radio" name="theme-color" navbarheadercolor="bg-success" navbarcollapsecolor="bg-success" asidecolor="bg-dark" value="13" <?php print ($layout_color_block==13) ? 'checked':NULL;?>>
          <span class="block bg-light clearfix pos-rlt">
            <span class="active pos-abt w-full h-full bg-black-opacity text-center">
              <i class="glyphicon glyphicon-ok text-white m-t-xs"></i>
            </span>
            <b class="bg-success header"></b>
            <b class="bg-success header"></b>
            <b class="bg-dark"></b>
          </span>
        </label>

        <label class="i-checks block">
          <input type="radio" name="theme-color" navbarheadercolor="bg-danger dker bg-gd" navbarcollapsecolor="bg-danger dker bg-gd" asidecolor="bg-dark" value="14" <?php print ($layout_color_block==14) ? 'checked':NULL;?>>
          <span class="block bg-light clearfix pos-rlt">
            <span class="active pos-abt w-full h-full bg-black-opacity text-center">
              <i class="glyphicon glyphicon-ok text-white m-t-xs"></i>
            </span>
            <b class="bg-danger dker header"></b>
            <b class="bg-danger dker header"></b>
            <b class="bg-dark"></b>
          </span>
        </label>
      </div>
    </div>
  </div>
</div>
<!-- /settings -->
