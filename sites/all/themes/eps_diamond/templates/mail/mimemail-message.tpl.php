<?php $site_name = variable_get('site_name','Epixel MLM Software'); ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<title><?php print $site_name; ?></title>
</head>
<body leftmargin="0" marginwidth="0" topmargin="0" marginheight="0" offset="0">
<center>
  <table align="center" border="0" cellpadding="0" cellspacing="0" height="100%" width="100%" id="bodyTable">
    <tr>
      <td align="center" valign="top" id="bodyCell"><!-- BEGIN TEMPLATE // -->

        <table border="0" cellpadding="0" cellspacing="0" id="templateContainer">
          <tr>
            <td align="center" valign="top"><!-- BEGIN PREHEADER // -->

              <table border="0" cellpadding="0" cellspacing="0" width="100%" id="templatePreheader">
                <tr>
                  	<td valign="top" class="preheaderContent" style="padding-top:28px; padding-right:20px; padding-bottom:11px; padding-left:20px; text-align:left; display: inline-block !important; width: 50%;" mc:edit="preheader_content00">

                    <?php
                      global $base_url;
                      $themes_path = drupal_get_path('theme', 'eps_diamond');

                    	$logo = theme_get_setting('logo');

                      if (isset($logo)):
                        $options = array('path' => $logo,'alt' => $site_name,'title' => $site_name, 'attributes' => array('style'=>"width : 75%"));
                      	$appName = theme('image', $options);
                      else:
												$appName = $site_name;
                      endif;
                      print l($appName, $base_url, array('absolute' => TRUE, 'attributes' => array(), 'html' => true));
                    ?>
                 		</td>
  					        <!-- *|IFNOT:ARCHIVE_PAGE|* -->
  	                <td valign="top" width="180px !important;" class="preheaderContent" style="padding-top:32px; padding-right:0; display: inline-block !important; width: 40%; text-align: right;" mc:edit="preheader_content01"><a href="<?php print $base_url; ?>" target="_blank" class="btn" style="text-decoration:none;color:#fff;font-size:14px;width:132px;height:35px;background:#166db6;border-radius:5px;display:inherit;text-align:center;line-height:35px; margin-right: 6px;">Home</a></td>
      	            <!-- *|END:IF|* -->

                </tr>
              </table>

              <!-- // END PREHEADER --></td>
          </tr>
          <tr>
            <td align="center" valign="top"><!-- BEGIN HEADER // -->

							<table border="0" cellpadding="0" cellspacing="0" width="100%" id="templateHeader">
                <tbody>
                	<tr>
                  	<td valign="top" class="headerContent" style="background:#166db6;text-align:center;padding:40px;"><h2 style="font-family:Arial, Helvetica, sans-serif;font-size: 28px;font-weight:bold;line-height:30px;text-align:center;color:#fff !important;"><?php print $subject ?></h2></td>
                	</tr>
              	</tbody>
             	</table>

              <!-- // END HEADER --></td>
          </tr>

          <tr>
            <td align="center" valign="top"><!-- BEGIN BODY // -->

              <table border="0" cellpadding="0" cellspacing="0" width="100%" id="templateBody">
                <tr>
                  <td valign="top" class="bodyContent" mc:edit="body_content" style="padding:20px 25px 40px 20px;font-family:Arial, Helvetica, sans-serif;font-size:14px;color:#535252;text-align:justify;margin-top:30px; background-color:#EEEEEE; border:1px solid #535252" >
                    <?php print nl2br($body); ?>
                  </td>
                </tr>
              </table>

              <!-- // END BODY --></td>
          </tr>
          <tr>
            <td align="center" valign="top"><!-- BEGIN PREHEADER // -->

              <table width="100%" cellspacing="0" cellpadding="0" border="0" style="background:#166db6;" id="templatePreheader">
                <tbody>
                  <tr>
                    <td valign="top" class="preheaderContent" style="background: #166db6; padding-top:10px; padding-right:20px; padding-bottom:10px; padding-left:20px;" mc:edit="preheader_content00">

                      <p style="color:#fff;font-size:13px;text-align:center;">Copyright <?php print date('Y').' - '.$site_name; ?></p>
                      <ul style="text-align:center;padding-left:0;">
                        <li style="list-style:none;display:inline-block;">
                          <?php
                            $options = array('alt' => $site_name,'path' => file_create_url($themes_path.'/img/newsletter/fb.png'));
                            $img = theme('image', $options);
                            print l($img,variable_get('generic_facebook', ''), array('absolute' => TRUE, 'attributes' => array("target"=>"_blank"),'title'=>"Facebook", 'html' => true));
                          ?>
                        </li>
                        <li style="list-style:none;display:inline-block;">
                          <?php
                            $options = array('alt' => $site_name,'path' => file_create_url($themes_path.'/img/newsletter/linkedin.png'));
                            $img = theme('image', $options);
                            print l($img,variable_get('generic_linkedin', ''), array('absolute' => TRUE, 'attributes' => array("target"=>"_blank",'title'=>"LinkedIn"), 'html' => true));
                          ?>
                        </li>
                        <li style="list-style:none;display:inline-block;">
                          <?php
                            $options = array('alt' => $site_name,'path' => file_create_url($themes_path.'/img/newsletter/twitter.png'));
                            $img = theme('image', $options);
                            print l($img,variable_get('generic_twitter', ''), array('absolute' => TRUE, 'attributes' => array("target"=>"_blank",'title'=>"Twitter"), 'html' => true));
                          ?>
                        </li>
                        
                        <li style="list-style:none;display:inline-block;">
                          <?php
                            $options = array('alt' => $site_name,'path' => file_create_url($themes_path.'/img/newsletter/youtube.png'));
                            $img = theme('image', $options);
                            print l($img,variable_get('generic_youtube', ''), array('absolute' => TRUE, 'attributes' => array("target"=>"_blank",'title'=>"YouTube"),'html' => true));
                          ?>
                        </li>
                      </ul></td>
                  </tr>
                </tbody>
              </table>

              <!-- // END PREHEADER --></td>
          </tr>
          <tr>
            <td align="center" valign="top"><!-- BEGIN PREHEADER // -->

              <table width="100%" cellspacing="0" cellpadding="0" border="0" style="background:#fff;" id="templatePreheader">
                <tbody>
                  <tr>
                    <td valign="top" class="preheaderContent" style="padding-top:10px; padding-right:20px; padding-bottom:10px; padding-left:20px;" mc:edit="preheader_content00"> <ul style="text-align:center; padding-left:0;">
                        <li style="list-style:none;display:inline-block;font-size:12px;">
                          <?php print l('Home |','<front>',array('absolute' => TRUE, 'attributes' => array('style'=>"text-decoration:none;color:#aaa8a8;","target"=>"_blank",'title'=>"Home")));?>
                        </li>
                        <li style="list-style:none;display:inline-block;font-size:12px;">
                          <?php print l('Privacy Policy |','terms-and-conditions',array('absolute' => TRUE, 'attributes' => array('style'=>"text-decoration:none;color:#aaa8a8;","target"=>"_blank",'title'=>"Privacy Policy")));?>
                        </li>
                        <li style="list-style:none;display:inline-block;font-size:12px;">
                          <?php print l('Terms of Use |','terms-and-conditions',array('absolute' => TRUE, 'attributes' => array('style'=>"text-decoration:none;color:#aaa8a8;","target"=>"_blank",'title'=>"Terms of Use")));?>
                        </li>
                        <li style="list-style:none;display:inline-block;font-size:12px;">
                          <?php print l('About Us','about-us',array('absolute' => TRUE, 'attributes' => array('style'=>"text-decoration:none;color:#aaa8a8;","target"=>"_blank",'title'=>"About Us")));?>
                        </li>
                      </ul></td>
                  </tr>
                </tbody>
              </table>

              <!-- // END PREHEADER --></td>
          </tr>
        </table>

        <!-- // END TEMPLATE --></td>
    </tr>
  </table>
</center>
</body>
</html>
