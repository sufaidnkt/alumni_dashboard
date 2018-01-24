 (function ($) {
  jQuery('html').removeClass('no-js');
  Drupal.behaviors.material_dashboard = {
    attach: function(context, settings) {
      $(document).ready(function() {
        
       if($('#user-register-form .form-item-field-department-und  .form-type-radio  input:radio').length){
          //if the radio already selected
          if($('#user-register-form .form-item-field-department-und  .form-type-radio  input:radio').is(':checked')) {
            $('#user-register-form .form-item-field-department-und  .form-type-radio  input:radio:checked').parent().parent().addClass("active-package");

          }
          //in logged user add mbr
          $('#user-register-form .form-item-field-department-und  .form-type-radio  input:radio').on('click',function() {
            $('#user-register-form .form-item-field-department-und').removeClass("active-package");
            if($(this).is(":checked")) {
                $(this).parent().parent().addClass("active-package");
            }
          });
        }
  
      });
    }
  };
}(jQuery));




       