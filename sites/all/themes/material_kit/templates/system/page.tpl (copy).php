<!-- Navbar -->
  <!--     Fonts and icons     -->
  <link rel="stylesheet" href="https://fonts.googleapis.com/icon?family=Material+Icons" />
    <link rel="stylesheet" type="text/css" href="https://fonts.googleapis.com/css?family=Roboto:300,400,500,700" />
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/latest/css/font-awesome.min.css" />
<body class="index-page">

  <!-- 
    Navigation bar
   -->
  <nav class="navbar navbar-info">
    <div class="container">
      <div class="navbar-header">
        <button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#example-navbar-primary">
          <span class="sr-only">Toggle navigation</span>
          <span class="icon-bar"></span>
          <span class="icon-bar"></span>
          <span class="icon-bar"></span>
        </button>
        <a class="navbar-brand" href="#pablo">
           <!--  Logo block -->

      <?php

        if (!empty($logo)):
          $log_img = theme('image', array('path' => $logo_icon,'alt' => $site_name,'title' => $site_name,'attributes' => array('class'=>'logo-icon')));
          print l($log_img, '<front>',  array('html' => TRUE,'attributes' => array('title' => $site_name,'class'=>array("navbar-brand","text-lt"))));
        elseif (!empty($site_name)):
          print l('<span>'.$site_name.'</span>', '<front>',  array('attributes' => array('title' => $site_name)));
        endif;
      ?>
      <!--  END -> Logo block -->
        </a>
      </div>

      <div class="collapse navbar-collapse" id="example-navbar-primary">
       <?php 
        if ( !empty($page['navigation'])) {
          print render($page['navigation']);
        }

        if (!empty($page['header_right'])) {
          print render($page['header_right']);
        } 

       ?>
      </div>
    </div>
  </nav>
  


  <div class="container">
      <?php if(!empty($primary_nav) ): ?>
            <div class="section text-center section-navigation-menu">
              <?php if (!empty($primary_nav)):  print render($primary_nav); endif; ?>
            </div>
      <?php endif; ?>

  </div>


  <div class="wrapper">
    <div class="main main">
        <div class="container">
            <div class="section text-center section-landing">
    <?php print $messages; ?>

          <?php 
           if ( !empty($page['content'])) {
            print render($page['content']);
           }
          ?>
        </div>
      </div>
    </div>
  </div>


  <footer class="footer">
    <div class="container">
        <nav class="pull-left">
            <ul>
        <li>
          <a href="http://www.creative-tim.com">
            Creative Tim
          </a>
        </li>
        <li>
          <a href="http://presentation.creative-tim.com">
             About Us
          </a>
        </li>
        <li>
          <a href="http://blog.creative-tim.com">
             Blog
          </a>
        </li>
        <li>
          <a href="http://www.creative-tim.com/license">
            Licenses
          </a>
        </li>
            </ul>
        </nav>
        <div class="copyright pull-right">
            &copy; 2016, made with <i class="material-icons">favorite</i> by Creative Tim for a better web.
        </div>
    </div>
  </footer>
</body>