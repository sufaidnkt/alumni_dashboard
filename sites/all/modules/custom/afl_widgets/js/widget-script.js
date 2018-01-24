(function($){
  Drupal.behaviors.aflWidgets = {
    attach: function(context, settings) {
      $(document).ready(function() {

        /* My Groups*/
        if($("#block-afl-widgets-afl-groups").length){
            var ajaxURL = settings.aflWidgets.afl_my_groups_count;
            Drupal.fun.panelDashWidgets($("#block-afl-widgets-afl-groups"),ajaxURL);
        }
        /* END -> My Groups */

        /* My total Groups*/
        if($("#block-afl-widgets-afl-total-messages").length){
            var ajaxURL = settings.aflWidgets.afl_total_messages_count;
            Drupal.fun.panelDashWidgets($("#block-afl-widgets-afl-total-messages"),ajaxURL);
        }
        /* END -> My total Groups */

         /* My total send Groups*/
        if($("#block-afl-widgets-afl-total-send-messages").length){
            var ajaxURL = settings.aflWidgets._afl_total_send_messages_count;
            Drupal.fun.panelDashWidgets($("#block-afl-widgets-afl-total-send-messages"),ajaxURL);
        }
        /* END -> My total send Groups */


         /* My total received Groups*/
        if($("#block-afl-widgets-afl-total-received-messages").length){
            var ajaxURL = settings.aflWidgets.afl_total_received_messages;
            Drupal.fun.panelDashWidgets($("#block-afl-widgets-afl-total-received-messages"),ajaxURL);
        }
        /* END -> My total received Groups */

         /* My total unread Groups*/
        if($("#block-afl-widgets-afl-total-unread-messages").length){
            var ajaxURL = settings.aflWidgets.afl_total_unread_messages;
            Drupal.fun.panelDashWidgets($("#block-afl-widgets-afl-total-unread-messages"),ajaxURL);
        }
        /* END -> My total unread Groups */

      }); 

    },
  };

  Drupal.theme.panelGrid = function (jsonData,v_type) {
    
    html_tag = '';
    
    html_tag +='<div class="card card-stats">';

    html_tag += '<div class="card-header" data-background-color="'+jsonData.data_bg+'">';
    html_tag += '<i class="'+jsonData.icon+'">'+jsonData.icon_text+'</i>';
    html_tag += '</div>';
    html_tag += '<div class="card-content">';
    html_tag += '<p class="category">'+jsonData.title+'</p>';
    html_tag += '<h3 class="title">'+jsonData.text;
    // html_tag += '<small>GB</small>';
    html_tag += '</h3>';
    html_tag += '</div>';
    html_tag += '<div class="card-footer">';
    html_tag += '<div class="stats">';
    html_tag += '<i class="material-icons text-info">info</i>';
    html_tag += '<a href="#pablo">View</a>';
    html_tag += '</div>';
    html_tag += '</div>';
    html_tag += '</div>';
    
    return html_tag;
  };

  Drupal.theme.panelError = function (text) {
    var html_tag = '<div class="block panel padder-v item bg-danger">';
    html_tag += '<div class="h1 font-thin h1 text-white"><i class="glyphicon glyphicon-warning-sign"></i></div>';
    html_tag += '<div class="text-muted text-xs text-muted">'+((text) ? text : Drupal.t('some error occurred'));+'</div>';
    html_tag += '</div>';
    return html_tag;
  };


  Drupal.fun = function (){};

  Drupal.fun.panelDashWidgets = function (obj,ajax_url) {
    if(obj && ajax_url){
      $.getJSON(ajax_url,function (jsonDatas) {
        if(jsonDatas){
          var html_tag = Drupal.theme('panelGrid', jsonDatas);
          obj.find('.afl-widget-panel').replaceWith(html_tag);
        }else{
          var html_tag = Drupal.theme('panelError', Drupal.t('Some error occurred'));
          obj.children('.afl-widget-panel').replaceWith(html_tag);
        }
      }).fail(function() {
        var html_tag = Drupal.theme('panelError', Drupal.t('Some error occurred'));
        obj.children('.afl-widget-panel').replaceWith(html_tag);
      });
    }
  };

  
})(jQuery);
