<?php 
	function _alumni_total_members () { 
  	drupal_add_js(array('alumniWidgets' => array('_alumni_total_members' => url('alumni/widget/ajax/total-members'))),'setting');
		return theme('html_tag', array('element' => array('#tag' => 'div','#attributes' => array('class' => array('afl-widget-panel','afl-widget'),'widget' => '_alumni_total_members'),'#value' => '<div class="loader loader-bar"></div>')));
	}

	function _alumni_my_class_members(){

			drupal_add_js(array('alumniWidgets' => array('_alumni_my_class_members' => url('alumni/widget/ajax/my-class'))),'setting');
		return theme('html_tag', array('element' => array('#tag' => 'div','#attributes' => array('class' => array('afl-widget-panel','afl-widget'),'widget' => '_alumni_my_class_members'),'#value' => '<div class="loader loader-bar"></div>')));

	}
	function _alumni_my_batch_members(){

			drupal_add_js(array('alumniWidgets' => array('_alumni_my_batch_members' => url('alumni/widget/ajax/my-batch'))),'setting');
		return theme('html_tag', array('element' => array('#tag' => 'div','#attributes' => array('class' => array('afl-widget-panel','afl-widget'),'widget' => '_alumni_my_batch_members'),'#value' => '<div class="loader loader-bar"></div>')));

	}

	