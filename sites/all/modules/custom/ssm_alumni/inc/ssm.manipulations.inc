<?php
/*
* Delete User Account
* Delete user details from Genealogy table
* Or
* Change the status is blocked	
*/

function _ssm_cancel_member_account($row){
	$uid = $row->uid;
	global $user;

	ssm_change_role_to_role($uid,'Unverified User', 'Blocked Users');

	$num_updated = db_update('alumni_user_genealogy') // Table name no longer needs {}
  		->fields(array(
			    'status' => -1,
			    'approved_by' => $user->uid,
			    'modified' => afl_date(),
  		))
		  ->condition('uid', $uid, '=')
		  ->execute();
}

/*
* Remove the unverified member role
* Add the role into Member from Unverified Member
* Change the genealogy status into member
* 	
*/

function _ssm_approve_user_account($row){
	$uid = $row->uid;
	global $user;

	ssm_change_role_to_role($uid,'Unverified User', 'Member');

	$num_updated = db_update('alumni_user_genealogy') // Table name no longer needs {}
  		->fields(array(
			    'status' => 1,
			    'approved_by' => $user->uid,
			    'modified' => afl_date(),
  		))
		  ->condition('uid', $uid, '=')
		  ->execute();
}