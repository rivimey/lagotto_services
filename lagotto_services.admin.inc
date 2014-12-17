<?php
/**
 * @file
 * Administration settings page definition for the ALM metrics service.
 */

/**
 * Menu callback; Displays the administration settings.
 */
function lagotto_services_admin_settings() {
  $form = array();
  $form['lagotto_services_url'] = array(
    '#type' => 'textfield',
    '#title' => t('ALM Server URL'),
    '#description' => t('The URL of the Lagotto Server (excluding /api/...).'),
    '#default_value' => variable_get('lagotto_services_url', LAGOTTO_SERVICES_DEFAULT_DOMAIN),
  );
  $form['lagotto_services_apikey'] = array(
    '#type' => 'textfield',
    '#title' => t('User API Key'),
    '#description' => t('The API key to use to access the Lagotto Server.'),
    '#default_value' => variable_get('lagotto_services_apikey', LAGOTTO_SERVICES_DEFAULT_KEY),
  );

  $form['settings'] = array(
    '#type' => 'vertical_tabs',
    '#weight' => 50,
  );
  // DOI Record creation/deletion settings.
  $form['doiadmin'] = array(
    '#type' => 'fieldset',
    '#title' => t('DOI Administration'),
    '#group' => 'settings',
  );
  $form['doiadmin']['lagotto_services_create_doi_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable DOI Create'),
    '#description' => t('Enable or Disable creation of records on the Lagotto Server for new DOIs.'),
    '#default_value' => variable_get('lagotto_services_create_doi_enabled', FALSE),
  );
  $form['doiadmin']['lagotto_services_delete_doi_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable DOI Delete'),
    '#description' => t('Enable or Disable deletion of records on the Lagotto Server for existing DOIs.'),
    '#default_value' => variable_get('lagotto_services_delete_doi_enabled', FALSE),
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
    '#description' => t('The API key to use to access the ALM Server.'),
    '#default_value' => variable_get('lagotto_services_adminpass', ''),
  );
  return system_settings_form($form);
}
