  <?php
  $theme_path = drupal_get_path('theme', 'eps_diamond');
  ?>
    <style>
.maintenance-wrapper{background: url(<?php print '/'.$theme_path ?>/img/bg-org.png) no-repeat 800px bottom #f3f3f3;min-height:780px;border-bottom:solid 65px #3f4454;}
.maintenance-wrapper.with-glass-worker{background: url(<?php print '/'.$theme_path ?>/img/work-with-glass.png) no-repeat 500px bottom #f3f3f3;}
.maintenance-wrapper.with-worker{background: url(<?php print '/'.$theme_path ?>/img/yellow-worker.png) no-repeat 100px bottom #f3f3f3;}
.maintenance-wrapper.with-worker.pc{background: url(<?php print '/'.$theme_path ?>/img/with-pc.png) no-repeat 100px bottom #f3f3f3;}
.dashboard .maintenance-wrapper.with-worker h1.logo{width:100%;text-align: right;}
.dashboard .maintenance-wrapper.with-worker h1.logo a{float: right;width:170px;margin:0 -13px 0 0;}
.maintenance-wrapper.with-worker .maintenance-inner{text-align: right;}
.maintenance-inner{padding:100px;}
.dashboard .maintenance-wrapper h1.logo{float: none;background: none;}
.dashboard .maintenance-wrapper h2{width:100%;color: #3f4454;font-family: 'latolight';font-size:30px;text-transform: uppercase;padding-top:20px;}
.dashboard .maintenance-wrapper h2 span{display: block;width:100%;font-family: 'latoblack';font-size:48px;}
.dashboard .counter span{font-family: 'latoblack';font-size:100px;color: #fb6730;padding-bottom:20px;display: block;}
.maintenance-wrapper.with-worker span{font-size:50px;}
.dashboard .counter .days-wrapper,.dashboard .counter .hours-wrapper,.dashboard .counter .minutes-wrapper,.dashboard .counter .seconds-wrapper{display:inline-block;vertical-align: middle;text-align: center;padding:0 65px;font-size:30px;color: #3f4454;text-transform: uppercase;font-family: 'latolight';}
.dashboard .with-worker .counter .days-wrapper,.dashboard .with-worker .counter .hours-wrapper,.dashboard .with-worker .counter .minutes-wrapper,.dashboard .with-worker .counter .seconds-wrapper{font-size:20px;}
.dashboard .counter{padding:100px 0 0;}


@media only screen and (max-width:1366px) {
    .dashboard .counter .days-wrapper, .dashboard .counter .hours-wrapper, .dashboard .counter .minutes-wrapper, .dashboard .counter .seconds-wrapper{padding:0 55px;}
}
@media only screen and (max-width:1280px) {
    .dashboard .counter .days-wrapper, .dashboard .counter .hours-wrapper, .dashboard .counter .minutes-wrapper, .dashboard .counter .seconds-wrapper{padding:0 45px;}
}
@media only screen and (max-width:1024px) {
    .dashboard .counter .days-wrapper, .dashboard .counter .hours-wrapper, .dashboard .counter .minutes-wrapper, .dashboard .counter .seconds-wrapper{padding:0 20px;}
    .maintenance-wrapper{background: #f3f3f3 url("../img/bg-org.png") no-repeat scroll 540px bottom;}
}
@media only screen and (max-width:980px) {
    .image-area-uc{display: none;}
    .maintenance-wrapper.with-worker,.maintenance-wrapper.with-worker.pc{background-image:none;}
    .maintenance-wrapper.with-worker .maintenance-inner,.maintenance-wrapper.with-worker.pc .maintenance-inner{text-align: center;}
}
@media only screen and (max-width:640px) {
    .maintenance-wrapper{background:none;}
    .maintenance-inner {padding: 100px 0;text-align: center;}
}
@media only screen and (max-width:480px) {
    .dashboard .counter span{font-size:30px;}
    .dashboard .counter .days-wrapper,.dashboard .counter .hours-wrapper,.dashboard .counter .minutes-wrapper,.dashboard .counter .seconds-wrapper{font-size:15px;}
}
@media only screen and (max-width:320px) {
    .dashboard .counter .days-wrapper,.dashboard .counter .hours-wrapper,.dashboard .counter .minutes-wrapper,.dashboard .counter .seconds-wrapper{padding:0 5px;}
}
    </style>
    <div class="dashboard">
    <div class="wrapper_all">
        <main class="maintenance-wrapper with-worker">
            <div class="maintenance-inner">
                <div class="wrapper_inner clearfix">
                    <div class="col-md-12">
                        <?php print render($page['content']); ?>
                    </div>
                </div>
            </div>
        </main>
    </div>
    </div>



