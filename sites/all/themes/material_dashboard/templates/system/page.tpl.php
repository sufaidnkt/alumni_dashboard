 <?php 
if(user_is_logged_in()){
  $website_home_page = 'afl/dashboard';
}
else{
  $website_home_page = $front_page;
}

 ?>

 <link rel="stylesheet" href="https://fonts.googleapis.com/icon?family=Material+Icons" />
    <link rel="stylesheet" type="text/css" href="https://fonts.googleapis.com/css?family=Roboto:300,400,500,700" />
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/latest/css/font-awesome.min.css" />
 <div class="wrapper">
   <div class="text-center">

   <?php 
        if (!empty($logo) && !user_is_logged_in()):

            $log_img = theme('image', array('path' => $logo,'alt' => $site_name,'title' => $site_name, 'attributes' => array('class'=>array('logo-icon'))));
            print l($log_img, '<front>',  array('html' => TRUE,'attributes' => array('title' => $site_name,'class'=>array("navbar-brand logo-icon","text-lt"))));
          elseif (!empty($site_name) && empty($logo)):
            print l('<span>'.$site_name.'</span>', '<front>',  array('attributes' => array('title' => $site_name)));
          endif; ?>
  </div>


    <?php if (user_is_logged_in()) :  ?>
        <div class="sidebar" data-color="purple" data-image="../assets/img/sidebar-1.jpg">
            <div class="logo">
               <?php
              if (!empty($logo)):
                $log_img = theme('image', array('path' => $logo,'alt' => $site_name,'title' => $site_name,'attributes' => array('class'=>'logo-icon')));
                print l($log_img, '<front>',  array('html' => TRUE,'attributes' => array('title' => $site_name,'class'=>array("navbar-brand","text-lt"))));
              elseif (!empty($site_name)):
                print l('<span>'.$site_name.'</span>', '<front>',  array('attributes' => array('title' => $site_name)));
              endif;
            ?>
            </div>
              <div class="sidebar-wrapper">
                  <?php if(!empty($primary_nav) ): ?>
                        <div class="section text-center section-navigation-menu">
                          <?php if (!empty($primary_nav)):  print render($primary_nav); endif; ?>
                        </div>
                  <?php endif; ?>
              </div>
        </div>
    <?php endif; ?>
    <?php if(user_is_logged_in()) :?>
        <div class="main-panel">
            <nav class="navbar navbar-transparent navbar-absolute">
                <div class="container-fluid">
                    <div class="navbar-header">
                        <button type="button" class="navbar-toggle" data-toggle="collapse">
                            <span class="sr-only">Toggle navigation</span>
                            <span class="icon-bar"></span>
                            <span class="icon-bar"></span>
                            <span class="icon-bar"></span>
                        </button>
                      <!--   <a class="navbar-brand" href="#"> Material Dashboard </a> -->
                    </div>
                    <?php 
                     if ( !empty($page['header_top_bar_left'])){
                      print render($page['header_top_bar_left']);
                     }
                    ?>
                    <div class="collapse navbar-collapse">
                      <?php if(!empty($secondary) ): ?>
                            <div class="section text-center section-navigation-menu">
                              <?php if (!empty($secondary)):  print render($secondary); endif; ?>
                            </div>
                      <?php endif; ?>

                       <?php 
                         if ( !empty($page['header_top_bar_right'])){
                          print render($page['header_top_bar_right']);
                         }
                        ?>

                    </div>
                </div>
            </nav>
         <?php endif; ?>   

            <div class="content">
                <div class="container-fluid">
                  <?php if(!empty($messages)) { ?>
                    <?php print $messages; ?>
                  <?php } ?>
                    <div class="row">
                       <?php 
                        if ( !empty( $page['highlighted'])) {
                          print render($page['highlighted']);
                        }
                       ?>
                    </div>
                    <div class="row">
                        <?php 
                          if ( !empty($page['anallytics'])) {
                            print render($page['anallytics']);
                          }
                        ?>
                    </div>
                    <div class="row">
                        <?php 
                          if ( !empty($page['content_top'])) {
                            print render($page['content_top']);
                          }
                        ?>
                    </div>
                    <div class="row">
                        <?php 
                          if ( !empty($page['content'])) {
                            print render($page['content']);
                          }
                        ?>
                    </div>
                      <div class="row">
                         <?php if (!empty($page['testimonials'])):  ?>
                          
                            <div class="">   
                                <?php print render($page['testimonials']); endif; ?>       
                           
                          </div>
                       
                    </div>
                     <div class="row">
                          <?php 
                          if ( !empty($page['news_events'])) {
                            print render($page['news_events']);
                          }
                          ?>  
                        </div> 
                    <div class="row">
                        <?php 
                          if ( !empty($page['content_bottom'])) {
                            print render($page['content_bottom']);
                          }
                        ?>
                    </div>
                </div>
            </div>
            <footer class="footer">
                <div class="container-fluid">
                    <p class="copyright pull-right">
                        &copy;
                        <script>
                            document.write(new Date().getFullYear())
                        </script>
                        <a href="#">Sufaid.PP</a>, made with love for a better web
                    </p>
                </div>
            </footer>
        </div>
    </div>

    <script type="text/javascript">
      
        (function($){

              /* Selected package in add new member */
        if($('.form-item-field-department-und .form-radios input:radio').length){
          //if the radio already selected
          if($('.form-item-field-department-und .form-radios input:radio').is(':checked')) {
            $('.form-item-field-department-und .form-radios input:radio:checked').parent().parent().addClass("active-package");

          }
          //in logged user add mbr
          $(' .form-item-field-department-und .form-radios input:radio').on('change',function() {
            $(' .form-item-field-department-und').removeClass("active-package");
            if($(this).is(":checked")) {
                $(this).parent().parent().addClass("active-package");
            }
          });
        }
          $(".rslides").responsiveSlides({
             pause: true,     // Boolean: Pause on hover, true or false
            // nav: true,             // Boolean: Show navigation, true or false

          });
        })(jQuery);
    </script>

    <script>
 
</script>