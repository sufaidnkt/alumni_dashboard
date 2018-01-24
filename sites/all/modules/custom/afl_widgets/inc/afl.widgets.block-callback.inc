<?php 
	function _afl_groups () {
  	drupal_add_js(array('aflWidgets' => array('afl_my_groups_count' => url('afl/widget/ajax/my-groups'))),'setting');
		return theme('html_tag', array('element' => array('#tag' => 'div','#attributes' => array('class' => array('afl-widget-panel','afl-widget'),'widget' => 'afl_my_groups_count'),'#value' => '<div class="loader loader-bar"></div>')));
	}

	function _afl_total_messages () {
		drupal_add_js(array('aflWidgets' => array('afl_total_messages_count' => url('afl/widget/ajax/my-messages-count'))),'setting');
		return theme('html_tag', array('element' => array('#tag' => 'div','#attributes' => array('class' => array('afl-widget-panel','afl-widget'),'widget' => 'afl_total_messages_count'),'#value' => '<div class="loader loader-bar"></div>')));
	}	

	function _afl_total_send_messages () {
		drupal_add_js(array('aflWidgets' => array('_afl_total_send_messages_count' => url('afl/widget/ajax/my-send-messages-count'))),'setting');
		return theme('html_tag', array('element' => array('#tag' => 'div','#attributes' => array('class' => array('afl-widget-panel','afl-widget'),'widget' => '_afl_total_send_messages_count'),'#value' => '<div class="loader loader-bar"></div>')));
	}

	function _afl_total_received_messages () {
		drupal_add_js(array('aflWidgets' => array('afl_total_received_messages' => url('afl/widget/ajax/my-received-messages-count'))),'setting');
		return theme('html_tag', array('element' => array('#tag' => 'div','#attributes' => array('class' => array('afl-widget-panel','afl-widget'),'widget' => 'afl_total_received_messages'),'#value' => '<div class="loader loader-bar"></div>')));
	}

	function _afl_total_unread_messages () {
		drupal_add_js(array('aflWidgets' => array('afl_total_unread_messages' => url('afl/widget/ajax/my-unread-messages-count'))),'setting');
		return theme('html_tag', array('element' => array('#tag' => 'div','#attributes' => array('class' => array('afl-widget-panel','afl-widget'),'widget' => 'afl_total_unread_messages'),'#value' => '<div class="loader loader-bar"></div>')));
	}