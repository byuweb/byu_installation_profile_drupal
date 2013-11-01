<?php

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Allows the profile to alter the site configuration form.
 */
function byu_form_install_configure_form_alter(&$form, $form_state) {
	// Pre-populate the site name with the server name.
	$form['site_information']['site_name']['#default_value'] = $_SERVER['SERVER_NAME'];
	
	//Add Fields for CAS Admin user
	$form['admin_account']['account']['cas_name'] = array(
	'#type' 	=> 'textfield', 
	'#title' 	=> t('CAS Admin Username'), 
	'#description' => t('CAS Username to be attached to the Administrator account'), 
	'#required' => TRUE,
	'#element_validate' => array('_cas_name_element_validate'),
	'#weight' 	=> $form['admin_account']['account']['name']['#weight']+1);

}