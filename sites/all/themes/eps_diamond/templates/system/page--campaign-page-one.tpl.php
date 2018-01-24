<?php
  $campaign = 1;
  $block_1 = 1;
  $youtube_content = get_youtube_video_content($campaign, $block_1);
  $theme_path = drupal_get_path('theme', 'eps_diamond');
?>

<div class="container-fluid main-bg">
    <div class="wrapper-main">
        <div class="wrapper-inner">
            <div class="row clearfix wrapper-intro">
                <div class="col-md-7 col-sm-12 col-xs-12 col-lg-7 video-wrapper">
                <?php if(user_access('edit_landing_page')) : ?>
                    <?php print l('', 'afl/add-campaign-video/1/1', array('attributes' => array('class' => 'fa fa-pencil edit-landing-content'))); ?>
                    <!-- <a href="/afl/add-campaign-video/1/1" class="fa fa-pencil edit-landing-content"></a> -->
                <?php endif ?>
                <?php print $youtube_content; ?>
                    <!-- <img class="img-responsive" src="img/video-bg.jpg" alt="video-block"/> -->
                </div>
                <div class="col-md-5 col-sm-12 col-xs-12 col-lg-5 contact-form-wrapper">
                    
                    <h2><?php print t('Contact Form'); ?></h2>
                    <?php
                        $block = module_invoke('webform', 'block_view','client-block-2');
                        print render($block['content']);
                    ?>
                </div>
            
            </div>
            
            <div class="row clearfix wrapper-about-courses">
                <?php if(user_access('edit_landing_page')) : ?>
                    <?php print l('', 'afl/add-campaign-content/1/1', array('attributes' => array('class' => 'fa fa-pencil edit-landing-content'))); ?>
                    <!-- <a href="/afl/add-campaign-content/1/1" class="fa fa-pencil edit-landing-content"></a> -->
                <?php endif ?>
                <h2><?php print t(afl_variable_get('1_1_title')); ?></h2>
                <p><?php print t(afl_variable_get('1_1_description')); ?></p>
                <?php if(arg(1)) {
                    $uname = arg(1); 
                    }else {
                    $uname = '';
                } ?>
                <?php print l(t('Join With US?'), get_join_url_from_name($uname), array('attributes' => array('class' => 'btn btn-primary'))); ?>
                
            </div>
            
            
            <div class="row clearfix wrapper-about-compensation">
                <?php if(user_access('edit_landing_page')) : ?>
                    <?php print l('', 'afl/add-campaign-content/1/2', array('attributes' => array('class' => 'fa fa-pencil edit-landing-content'))); ?>
                <?php endif ?>
                <h2><?php print t(afl_variable_get('1_2_title')); ?></h2>
                <p><?php print t(afl_variable_get('1_2_description')); ?></p>
                <ul>
                    <?php for ($i = 1; $i <= 3 ; $i++) {
                        if(afl_variable_get('1_2_bullet_'.$i)){ $image_path = $theme_path . '/img/abt-compensation-icn.png';
                        $image = array(
                            'path' => $image_path,
                            'class' => 'abt-cn',
                            );
                        ?>
                        <li><span class = 'abt-cn' ><?php print theme('image', $image); ?></span><?php print t(afl_variable_get('1_2_bullet_'.$i)); ?></li>
                        <?php }
                    } ?>
                </ul>
                     
            </div>
            <?php if(user_is_logged_in()) : ?>
            <div class="row wrapper-copy-link">
                
                <h2><?php print t('Copy Link'); ?></h2>
                <?php $campaign = 1; ?>
                <?php $path = 'campaign-page-one'; ?>
                <?php $campain_url = get_my_campaign_url($campaign, $path); ?>
                <?php print l($campain_url , get_my_campaign_url($campaign, $path), array('attributes' => array('id' => 'just-join'))); ?>
                <?php print l(t('Copy Link') , '', array('attributes' => array('id' => 'copy-campaign-url', 'class' => 'btn btn-primary'))); ?>
                                                
            </div>
            
            <div class="row wrapper-social-link">
                
                <ul class="clearfix social-icons">
                    <li><span class="landing-social-icon"><a target="_blank" href="https://www.facebook.com/sharer/sharer.php?u=<?php print $campain_url; ?>">
                        <i class="fa fa-facebook"></i></a></span>
                    </li>
                    <li><span class="landing-social-icon"><a target="_blank" href="https://twitter.com/home?status=<?php print $campain_url; ?>">
                        <i class="fa fa-twitter"></i></a> </span>
                    </li>
                    <li><span class="landing-social-icon"><a target="_blank" href="https://plus.google.com/share?url=<?php print $campain_url; ?>">
                        <i class="fa fa-google-plus"></i></a></span>
                    </li>
                    <li><span class="landing-social-icon"><a target="_blank" href="mailto:?subject=<?php print $campain_url; ?>" >
                        <i class="fa fa-at"></i></a></span>
                    </li>
                                             
                </ul>
                   
            </div> 
           <?php endif; ?>
            
        </div>
        
    </div>

        
</div>


<script type="text/javascript" >
   jQuery(document).ready(function($){
   $("#copy-campaign-url").click(function() {
     var $temp = $("<input>");
     $("body").append($temp);
     $temp.val($('#just-join').text().trim()).select();
     document.execCommand("copy");
     $temp.remove();
     return false;
   });
 });
</script>
