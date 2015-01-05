<?php
/**
 * @file
 * Administration settings page definition.
 */

/**
 * The administration settings form info.
 */
function lagotto_services_submit_admin_settings() {
  // DOI Record creation/deletion settings.
  $form['doiadmin'] = array(
    '#type' => 'fieldset',
    '#title' => t('Submission and removal'),
    '#group' => 'settings',
    '#weight' => 10,
  );
  $form['doiadmin']['lagotto_services_submit_add_doi_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable DOI Create'),
    '#description' => t('Enable or Disable creation of records on the Lagotto Server for new DOIs.'),
    '#default_value' => variable_get('lagotto_services_submit_add_doi_enabled', FALSE),
  );
  $form['doiadmin']['lagotto_services_submit_remove_doi_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable DOI Delete'),
    '#description' => t('Enable or Disable deletion of records on the Lagotto server for existing DOIs.'),
    '#default_value' => variable_get('lagotto_services_submit_remove_doi_enabled', FALSE),
  );
  $form['doiadmin']['lagotto_services_adminuser'] = array(
    '#type' => 'textfield',
    '#title' => t('Admin Username'),
    '#description' => t('The administrator username to use when creating new DOI records.'),
    '#default_value' => variable_get('lagotto_services_adminuser', ''),
  );
  $form['doiadmin']['lagotto_services_adminpass'] = array(
    '#type' => 'textfield',
    '#title' => t('Admin Password'),
    '#description' => t('The API key to use to access the Lagotto server.'),
    '#default_value' => variable_get('lagotto_services_adminpass', ''),
  );
  return $form;
}
