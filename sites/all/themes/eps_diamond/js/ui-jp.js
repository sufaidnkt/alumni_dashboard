+function ($) {
  Drupal.behaviors.epsdiamondUiJp = {
    attach: function(context, settings) {
      $(function(){
        $("[ui-jq]").each(function(){
          var self = $(this);
          var options = eval('[' + self.attr('ui-options') + ']');

          if ($.isPlainObject(options[0])) {
            options[0] = $.extend({}, options[0]);
          }

          uiLoad.load(Drupal.settings.theme_path+'/'+jp_config[self.attr('ui-jq')]).then( function(){
            self[self.attr('ui-jq')].apply(self, options);
          });
        });
      });
    }
  };
}(jQuery);
