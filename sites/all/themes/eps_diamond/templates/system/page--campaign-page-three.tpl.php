<?php
  $image_content = '';
  $campaign = 3;
  $block_1 = 1;
  $block_2 = 2;
  if(afl_variable_get($campaign.'_'.$block_1.'_content') == "image") {
    $image_content_1 = get_image_content($campaign, $block_1);
  }elseif (afl_variable_get($campaign.'_'.$block_1.'_content') == "video") {
    $youtube_content_1 = get_youtube_video_content($campaign, $block_1);
  }
  if(afl_variable_get($campaign.'_'.$block_2.'_content') == "image") {
    $image_content_2 = get_image_content($campaign, $block_2);
  }elseif (afl_variable_get($campaign.'_'.$block_2.'_content') == "video") {
    $youtube_content_2 = get_youtube_video_content($campaign, $block_2);
  }
?>
<div class="container-fluid main-bg">
    <div class="wrapper-main">
        <div class="wrapper-inner">
            <div class="row wrapper-video-detail">
                <?php if(user_access('edit_landing_page')) : ?>
                    <?php print l('', 'afl/select-campaign-media-video/3/1', array('attributes' => array('class' => 'fa fa-pencil edit-landing-content'))); ?>
                <?php endif ?>
                <?php if(afl_variable_get('3_1_content') == "image") : ?>
                    <div class="video-heads">
                        <h4><?php print t(afl_variable_get('3_1_image_title')); ?></h4>
                    </div>
                   
                    <div class="video-details-inner">
                        <?php print $image_content_1; ?>
                       
                    </div>
                <?php elseif(afl_variable_get('3_1_content') == "video") : ?>
                    <div class="video-heads">
                       <h4><?php print t(afl_variable_get('3_1_video_title')); ?></h4>
                       
                    </div>
                   
                    <div class="video-details-inner">
                        <?php print $youtube_content_1; ?>
                       
                    </div>
                <?php endif;?>
                <div class="video-detail-submit">
                    <?php 
                    $uname = '';
                    if(arg(1)) {
                        $uname = arg(1);
                    }
                    ?>
                    <?php print l(t('Click Here To Grow Your Digital Altitude Business Faster!'), get_join_url_from_name($uname), array('attributes' => array('class' => 'vid-detail-btn'))); ?>
                </div>
                   
            </div>
               
               
               
            <div class="row wrapper-video-detail">
                <?php if(user_access('edit_landing_page')) : ?>
                <?php print l('', 'afl/select-campaign-media-video/3/2', array('attributes' => array('class' => 'fa fa-pencil edit-landing-content'))); ?>
                <?php endif ?>
                <?php if(afl_variable_get('3_2_content') == "image") : ?>
                    <div class="video-heads">
                        <h4><?php print t(afl_variable_get('3_2_image_title')); ?></h4>
                    </div>
                   
                    <div class="video-details-inner">
                        <?php print $image_content_2; ?>  
                    </div>
                <?php elseif(afl_variable_get('3_2_content') == "video") : ?>
                    <div class="video-heads">
                        <h4><?php print t(afl_variable_get('3_2_video_title')); ?></h4>
                       
                    </div>
                   
                    <div class="video-details-inner">
                        <?php print $youtube_content_2; ?>
                       
                    </div>
                <?php endif;?>                         
            </div>
               
           <?php if(user_is_logged_in()) : ?>
               <div class="row wrapper-copy-link">
                    <h2>Copy Link</h2>
                    <?php $campaign = 3; ?>
                    <?php $path = 'campaign-page-three'; ?>
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


<script type="text/javascript">
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