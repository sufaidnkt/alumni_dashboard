(function($){
  Drupal.behaviors.aflcurrencyrate = {
    attach: function(context, settings) {
      $(document).ready(function() {
      if($('.panel-currency').length) {
        $(".panel-currency").each(function(index,element) {
          var obj = $(element);
          var curr_fr = $(element).attr('currfr');
          var curr_to = $(element).attr('currto');
          var title = $(element).attr('title');
          var ajax_url = "https://min-api.cryptocompare.com/data/price?fsym="+curr_fr+"&tsyms="+curr_to;

          $.getJSON(ajax_url,function (jsonData) {
            if(jsonData){
              var html_tag = Drupal.theme('currencyrateBlock', title, jsonData);
              obj.children('.hbox').html(html_tag);
            }else{
              obj.children('.hbox').html('<p class="m-md">'+Drupal.t('Some error occurred')+'</p>');
            }
          }).fail(function() {
            obj.children('.hbox').html('<p class="m-md">'+Drupal.t('Some error occurred')+'</p>');
          });


        });
      }
      });
    },
  };

  
  Drupal.theme.currencyrateBlock = function (title,currencyrate) {
    var html_tag = '';
    /* Currency Rates */
    if(title) {
      html_tag += '<div class="col w-xs v-middle hidden-md text-center">';
      html_tag += '<div class="sparkline inline h3 text-white">';
      html_tag += title;
      html_tag +='</div>';
      html_tag +='</div>';
    }

    if(currencyrate) {
      html_tag += '<div class="col dk padder-v r-r">';
      html_tag += '<div class="hbox">';
      $.each(currencyrate, function (currency_name, rate) {
        html_tag += '<div class="currency-box text-center col">';
        if(currency_name) {
          html_tag += '<div class="currency-name text-white dk">';
          html_tag += currency_name;
          html_tag += '</div>';
        }
        if(rate) {
          html_tag += '<div class="currency-rate text-white">';
          html_tag += rate;
          html_tag += '</div>';
        }
        html_tag += '</div>';
      });
      html_tag += '</div>';
      html_tag += '</div>';
    }
    return html_tag;
  };
})(jQuery);