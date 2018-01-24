<?php 
function ssm_admin_configuration($form, &$form_state){
	pr("ssm_admin_configuration");
}

function ssm_reset_members($form,$form_state){
	$form['submit'] = [
		'#type' =>'submit',
		'#value' => 'Reset',

	];

	return $form;


}
function ssm_reset_members_submit($form, $form_state){
	$db_transaction = db_transaction();
  try{
		$users_array = array(0=>0, 1 => 1);
		$uids = db_select('users', 'u')
	     ->fields('u', array('uid'))
	     ->condition('uid', $users_array, 'NOT IN')
	     ->range(0,100)
	     ->execute()
	     ->fetchCol();


		  if(!empty($uids)){
		   user_delete_multiple($uids);
		   db_query("ALTER TABLE users AUTO_INCREMENT = 10");
		   drupal_set_message("Success");
		  }
		 db_truncate('alumni_user_genealogy')->execute();
     
        
	}
	catch (Exception $e) {
      $db_transaction->rollback();
      drupal_set_message("Some error occured: ".$e);
      watchdog_exception('Clear Test Data', $e);
    }

}
