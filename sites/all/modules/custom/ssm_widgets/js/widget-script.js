(function($){
  Drupal.behaviors.alumniWidgets = { 
      attach: function(context, settings) {
      $(document).ready(function() { 

        /* My Groups*/ 
        if($("#block-ssm-widgets-alumni-total-members").length){  
            var ajaxURL = settings.alumniWidgets._alumni_total_members;

            Drupal.fun.panelDashWidgets($("#block-ssm-widgets-alumni-total-members"),ajaxURL);
        }
        /* END -> My Groups */
         if($("#block-ssm-widgets-alumni-my-class").length){   
            var ajaxURL = settings.alumniWidgets._alumni_my_class_members;   
            Drupal.fun.panelDashWidgets($("#block-ssm-widgets-alumni-my-class"),ajaxURL);
        }
        if($("#block-ssm-widgets-alumni-my-batch").length){   
            var ajaxURL = settings.alumniWidgets._alumni_my_batch_members;   
            Drupal.fun.panelDashWidgets($("#block-ssm-widgets-alumni-my-batch"),ajaxURL);
        }

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
