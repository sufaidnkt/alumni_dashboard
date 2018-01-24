(function ($) {
  Drupal.behaviors.epsdiamondThemeNavbar = {
    attach: function(context, settings) {
      $(document).ready(function () {
        if($('.navbar-nav .btn-aside-folded').length){
          $( ".navbar-nav .btn-aside-folded" ).click(function() {
            if($(this).is(".active")){
              $.cookie("asideFolded", 'no',{ path: '/' });
              $('body > .app').removeClass('app-aside-folded');
            }else{
              $.removeCookie('asideFolded');
              $.cookie("asideFolded", 'yes',{ path: '/' });
              $('body > .app').addClass('app-aside-folded');
            }
          });
        }
      });
    }
  };
}(jQuery));
