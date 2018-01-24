<?php
    $nid = arg(1);
    $campaign_style = array();
    $data = node_load($nid);
    $bid = $data->field_page_contents['und'][0]['bid'];
    $background = $data->field_background['und'][0]['value'];
    $background_color = $data->field_campaign_background_color['und'][0]['rgb'] ? $data->field_campaign_background_color['und'][0]['rgb'] : '#fff';
    if($data->field_campaign_background_image['und'][0]['fid']) {
        $background_image_id = $data->field_campaign_background_image['und'][0]['fid'];
        $file = file_load($background_image_id);
        $uri = $file->uri;
        $background_image_url = file_create_url($uri);
    }
    $width = $data->field_content_width['und'][0]['value'];
    if(!empty($data->field_custom_css['und'][0]['value'])){
        drupal_add_css($data->field_custom_css['und'][0]['value'], array('type' => 'inline', 'group' => CSS_THEME, 'weight' => 999));
    }
?>
<style>
    <?php if ($background == 0) : ?>
        #campaign-background{ background:<?php print $background_color; ?>;}
    <?php else : ?>
        #campaign-background{ color: rgb(255, 255, 255); position: relative; min-height: 350px; background: url(<?php print $background_image_url; ?>)no-repeat scroll 0px 100% / cover transparent;}
     <?php endif; ?>
</style>

<div class="container-fluid campaign-banner"   id = "campaign-background">
    <!-- main content -->
    <div class="wrapper_all campaign-popup main_section">
        <div class="wrapper-inner description-text <?php if($width == 0) print 'container'?>" id ="panel-null">
            
            <?php
            // Sponser User id from url arg(2)
            $url = get_my_url(request_path());
            $current_url = request_path();
            
            
            $uid = '';
            if(arg(2)){
              $uid_arr = json_decode(base64_decode(arg(2)));
              $uid = $uid_arr->id;
            }

            //select node id from url arg(1)
            if(arg(1)){
                $nid = arg(1);
            }
            // if((arg(2) == 'edit') || (arg(2) == 'delete') || (arg(2) == 'clone')){
            //     print render($page['content']);
            // }else{
    
            
            $status =  views_embed_view('lead_capture', 'block_1',$nid);
            ?>
        <div class="text-center heading title-size"> 
            <?php //print main heading and logo
            echo views_embed_view('lead_capture', 'block_2',$nid); ?>
        </div>

        <div class="row" id = "content-box">
            <?php 
            //$uid = 0;
            
            $status = $data->field_campaign_status['und'][0]['value'];
            $position = $data->field_form_position['und'][0]['value'];
            $end_date = $data->field_campaign_date['und'][0]['value2'];
            $end_date = strtotime($end_date);
            $curr_date = afl_date();

            print render($page['content']);
            // pr($page['content']);
                    // check the status of campaign and valid date

            if(($status == 'Closed') || ($curr_date > $end_date)){ ?>

                <div class='text-center text-danger'><h2><b>Campaign Closed.</b></h2></div>
                <?php
            //}else{
                // check the form position
                //if($position == 'Right'){  ?>
                  <!--<div class="col-md-7 text-center ">
                    <?php /*print campain image*/ //echo views_embed_view('lead_capture', 'block_3',$nid);  ?>   
                  <!--</div>
                  <div class ="col-md-4">
                    <div class ="campaign-form" id = "self-joiing-form">
                        <?php 
                        // echo views_embed_view('lead_capture', 'block_4',$nid);
                        //  //check the user is logged in, else print form for registration
                        // if($uid){
                        //     module_load_include('inc', 'node', 'node.pages');
                        //     $form = node_add('leads');
                        //     unset($form['additional_settings']);
                        //     print drupal_render($form);
                        //     print $variables['tearms'];
                        // }
                        // else{ 

                            // //print share links
                            // $current_url = request_path();
                            //  $mPath =get_my_url($current_url);
                            //  $mTitle ='lead_capture';

                         ?>
                         
                        <!-- AddToAny BEGIN -->
                        <!--<div class="a2a_kit a2a_kit_size_100 a2a_default_style" style="float:left;" data-a2a-url="<?php //echo $mPath.'/fb';?>" data-a2a-title="<?php //echo $mTitle;?>">
                        <!-- <a class="a2a_dd" href="https://www.addtoany.com/share"></a> -->
                        <!--<a class="a2a_button_facebook" ></a>
                        </div>
                        <div class="a2a_kit a2a_kit_size_100 a2a_default_style" style="float:left;" data-a2a-url="<?php //echo $mPath.'/twt';?>" data-a2a-title="<?php //echo $mTitle;?>">
                        <!-- <a class="a2a_dd" href="https://www.addtoany.com/share"></a> -->
                        <!--<a class="a2a_button_twitter"></a>
                        </div>
                        <div class="a2a_kit a2a_kit_size_100 a2a_default_style"  style="float:left;" data-a2a-url="<?php //echo $mPath.'/google+';?>" data-a2a-title="<?php //echo $mTitle;?>">
                        <!-- <a class="a2a_dd" href="https://www.addtoany.com/share"></a> -->
                        <!--<a class="a2a_button_google_plus"></a>
                        </div>
                        <div class="a2a_kit a2a_kit_size_100 a2a_default_style share-button" style="float:left;" data-a2a-url="<?php //echo $mPath.'/email';?>" data-a2a-title="<?php //echo $mTitle;?>">
                        <!--<a class="a2a_button_email"></a>
                        </div>
                        <?php //drupal_add_js('/'.path_to_theme('eps_diamond').'/js/page.js'); ?>
                         <!-- <script async src="https://static.addtoany.com/menu/page.js"></script> -->
                             <!-- AddToAny END -->
                        <?php //}  ?>
                    <!--</div>
                   </div>

                <?php /*form position*/ } else{   ?>
                <div class="text-center">
                    <a target="_blank" href="https://www.facebook.com/sharer/sharer.php?u=<?php print get_my_url($current_url, 'fb'); ?>" class="btn btn-social-icon btn-facebook facebook">
                    <i class="fa fa-facebook"></i></a>

                    <a target="_blank" href="https://twitter.com/home?status=<?php print get_my_url($current_url, 'twt'); ?>" class="btn btn-social-icon btn-twitter twitter">
                    <i class="fa fa-twitter"></i></a> 

                    <a target="_blank" href="https://plus.google.com/share?url=<?php print get_my_url($current_url, 'google+'); ?>" class="btn btn-social-icon btn-google-plus google_plus">
                    <i class="fa fa-google-plus"></i></a> 

                    <a target="_blank" href="mailto:?subject=<?php print $referela_link; ?>&title=Referral-link&summary=Please use this link to create an affiliate account" class="btn btn-social-icon btn-linkedin email">
                    <i class="fa fa-at"></i></a> 

                </div>
                        <!-- <div class="a2a_kit a2a_kit_size_100 a2a_default_style" style="float:left;" data-a2a-url="<?php //print get_my_url($current_url, 'fb');?>" data-a2a-title="<?php //echo $mTitle;?>">
                        <!-- <a class="a2a_dd" href="https://www.addtoany.com/share"></a> -->
                        <!-- <a class="a2a_button_facebook" ></a>
                        </div>
                        <div class="a2a_kit a2a_kit_size_100 a2a_default_style" style="float:left;" data-a2a-url="<?php //print get_my_url($current_url, 'twt') ;?>" data-a2a-title="<?php //echo $mTitle;?>">
                        <!-- <a class="a2a_dd" href="https://www.addtoany.com/share"></a> -->
                       <!--  <a class="a2a_button_twitter"></a>
                        </div>-->
                        <!--<div class="a2a_kit a2a_kit_size_100 a2a_default_style"  style="float:left;" data-a2a-url="<?php print get_my_url($current_url, 'google+');?>" data-a2a-title="<?php echo $mTitle;?>">
                        <!-- <a class="a2a_dd" href="https://www.addtoany.com/share"></a> -->
                        <!--<a class="a2a_button_google_plus"></a>
                        </div>-->
                       <!-- <div class="a2a_kit a2a_kit_size_100 a2a_default_style share-button" style="float:left;" data-a2a-url="<?php get_my_url($current_url, 'email');?>" data-a2a-title="<?php echo $mTitle;?>">
                        <!--<a class="a2a_button_email"></a>
                        </div>
                        </div>
                        <?php drupal_add_js('/'.path_to_theme('eps_diamond').'/js/page.js'); ?>
                        
                         <!-- <script async src="https://static.addtoany.com/menu/page.js"></script> -->
                             <!-- AddToAny END -->
                        <?php }  ?>
                    <!--<div class ="col-md-1"></div>
                   <!-- <div class ="col-md-4">
                       <!-- <div class ="campaign-form" id = "self-joiing-form">
                            <?php 
                            // echo views_embed_view('lead_capture', 'block_4',$nid);
                            //  //check the user is logged in, else print form for registration
                            // if($uid){
                            //     module_load_include('inc', 'node', 'node.pages');
                            //     $form = node_add('leads');
                            //     unset($form['additional_settings']);
                            //     print drupal_render($form);
                            //     print $variables['tearms'];
                            // }
                            // else{ 
                            //     //print share links
                            //     $current_url = request_path();
                            //      $mPath =get_my_url($current_url);
                            //      $mTitle ='lead_capture';
                            //      $first = key($row);
                             ?>
                            <!-- AddToAny BEGIN -->
                            <!--<div class="a2a_kit a2a_kit_size_10 a2a_default_style" style="float:left;" data-a2a-url="<?php// echo $mPath.'/fb';?>" data-a2a-title="<?php //echo $mTitle;?>">
                            <!-- <a class="a2a_dd" href="https://www.addtoany.com/share"></a> -->
                            <!--<a class="a2a_button_facebook" ></a>
                            </div>
                            <div class="a2a_kit a2a_kit_size_10 a2a_default_style" style="float:left;" data-a2a-url="<?php //echo $mPath.'/twt';?>" data-a2a-title="<?php //echo $mTitle;?>">
                            <!-- <a class="a2a_dd" href="https://www.addtoany.com/share"></a> -->
                            <!--<a class="a2a_button_twitter"></a>
                            </div>
                            <div class="a2a_kit a2a_kit_size_10 a2a_default_style"  style="float:left;" data-a2a-url="<?php //echo $mPath.'/gp';?>" data-a2a-title="<?php //echo $mTitle;?>">
                            <!-- <a class="a2a_dd" href="https://www.addtoany.com/share"></a> -->
                            <!-- <a class="a2a_button_google_plus"></a>
                            </div>
                            <div class="a2a_kit a2a_kit_size_10 a2a_default_style share-button" style="float:left;" data-a2a-url="<?php //echo $mPath.'/email';?>" data-a2a-title="<?php //echo $mTitle;?>">
                            <!-- <a class="a2a_button_email"></a>
                            </div>
                            <!-- <script async src="https://static.addtoany.com/menu/page.js"></script> -->
                            <?php //drupal_add_js(path_to_theme('eps_diamond').'/js/page.js'); ?>
                                 <!-- AddToAny END -->
                            <?php //}  ?>
                        <!--</div>
                    </div>
                    <div class="col-md-7 text-center ">
                       <?php
                       /*print campain image*/
                        //echo views_embed_view('lead_capture', 'block_3',$nid);
                        ?>
                    <!--</div>-->
                <?php //}  }?>
                <?php // }?>

            </div>
        </div>

  

    <!-- footer -->
    <?php if(!empty($page['footer'])){ ?>
    <div class="row">
        <div class="wrapper-inner text-center">
            <div class="footer">
                <?php print render($page['footer']); ?>
            </div>
        </div>
    </div>
    <?php } ?>
    <!-- footer end -->
    <?php print $messages; ?>
</div>
</div>
