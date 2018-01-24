(function ($) {
  Drupal.behaviors.epsdiamondThemeColorSwitcher = {
    attach: function(context, settings) {
      $(document).ready(function () {
        if($('.navbar-nav .btn-aside-folded').length){
          $( ".navbar-nav .btn-aside-folded" ).click(function() {
            if($(this).is(".active")){
              $.cookie("asideFolded", 'no', { path: '/' });
              $('body > .app').removeClass('app-aside-folded');
              $('.theme-layout-settings .layout-conf input[value="app-aside-folded"]').prop('checked',false);
            }else{
              $.cookie("asideFolded", 'yes', { path: '/' });
              $('body > .app').addClass('app-aside-folded');
              $('.theme-layout-settings .layout-conf input[value="app-aside-folded"]').prop('checked',true);
            }
          });
        }

        if($('.theme-layout-settings .layout-conf input[type="checkbox"]').length){
          $('.theme-layout-settings .layout-conf input[type="checkbox"]').click(function() {
            var cookie_name = $(this).attr('cookiekey');
            if($(this).is(':checked')){
              $.cookie(cookie_name, 'yes', { path: '/' });
              $('body > .app').addClass($(this).val());
              $(this).prop('checked',true);
            }else{
              $.cookie(cookie_name, 'no', { path: '/' });
              $('body > .app').removeClass($(this).val());
              $(this).prop('checked',false);
            }
          });
        }

        if($('.theme-layout-settings .color-block input[type="radio"]').length){
          $('.theme-layout-settings .color-block input[type="radio"]').click(function() {
            var navbarheadercolor = $(this).attr('navbarheadercolor');
            var navbarcollapsecolor = $(this).attr('navbarcollapsecolor');
            var asidecolor = $(this).attr('asidecolor');
            $.cookie('navbarHeaderColor', navbarheadercolor, { path: '/' });
            $.cookie('navbarCollapseColor', navbarcollapsecolor, { path: '/' });
            $.cookie('asideColor', asidecolor, { path: '/' });
            $.cookie('layoutColorBlock', $(this).val(), { path: '/' });
            $('body .app #navbar-header').removeClass().addClass('navbar-header text-center '+navbarheadercolor);
            $('body .app #navbar-collapse').removeClass().addClass('collapse pos-rlt navbar-collapse box-shadow '+navbarcollapsecolor);
            $('body .app #aside').removeClass().addClass('app-aside hidden-xs '+asidecolor);
          });
        }

        if($('.theme-layout-settings a.reset-setting').length){
          $('.theme-layout-settings a.reset-setting').click(function() {
            $('body > .app').removeClass().addClass('app '+Drupal.settings.boxed_layout+' '+Drupal.settings.dock_aside+' '+Drupal.settings.fixed_aside+' '+Drupal.settings.fixed_header+' '+Drupal.settings.folded_aside+' '+Drupal.settings.aside_width);
            $('.theme-layout-settings .color-block input[value="'+Drupal.settings.layout_color_block+'"]').prop('checked',true);

            $('body .app #navbar-header').removeClass().addClass('navbar-header text-center '+Drupal.settings.navbar_header_color);
            $('body .app #navbar-collapse').removeClass().addClass('collapse pos-rlt navbar-collapse box-shadow '+Drupal.settings.navbar_collapse_color);
            $('body .app #aside').removeClass().addClass('app-aside hidden-xs '+Drupal.settings.aside_color);

            $('.theme-layout-settings .layout-conf input[type="checkbox"]').prop('checked',false);
            if(Drupal.settings.boxed_layout.length && Drupal.settings.folded_aside!=''){
              $('.theme-layout-settings .layout-conf input[value="'+Drupal.settings.folded_aside+'"]').prop('checked',true);
            }
            if(Drupal.settings.boxed_layout.length && Drupal.settings.fixed_header!=''){
              $('.theme-layout-settings .layout-conf input[value="'+Drupal.settings.fixed_header+'"]').prop('checked',true);
            }
            if(Drupal.settings.boxed_layout.length && Drupal.settings.fixed_aside!=''){
              $('.theme-layout-settings .layout-conf input[value="'+Drupal.settings.fixed_aside+'"]').prop('checked',true);
            }
            if(Drupal.settings.boxed_layout.length && Drupal.settings.dock_aside!=''){
              $('.theme-layout-settings .layout-conf input[value="'+Drupal.settings.dock_aside+'"]').prop('checked',true);
            }
            if(Drupal.settings.boxed_layout.length && Drupal.settings.boxed_layout!=''){
              $('.theme-layout-settings .layout-conf input[value="'+Drupal.settings.boxed_layout+'"]').prop('checked',true);
            }
            $.removeCookie('navbarHeaderColor');
            $.removeCookie('navbarCollapseColor');
            $.removeCookie('asideColor');
            $.removeCookie('layoutColorBlock');
            $.removeCookie('headerFixed');
            $.removeCookie('asideFixed');
            $.removeCookie('asideFolded');
            $.removeCookie('asideDock');
            $.removeCookie('layoutcontainer');
          });
        }

      });
    }
  };
}(jQuery));
