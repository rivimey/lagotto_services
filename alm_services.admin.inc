<?php
/**
 * @file
 * Administration settings page definition for the ALM metrics service.
 */

/**
 * Menu callback; Displays the administration settings.
 */
function alm_services_admin_settings() {
  $form = array();
  $form['alm_services_url'] = array(
    '#type' => 'textfield',
    '#title' => t('ALM Server URL'),
    '#description' => t('The URL of the ALM Server (excluding /api/...).'),
    '#default_value' => variable_get('alm_services_url', ALM_SERVICES_DEFAULT_DOMAIN),
  );
  $form['alm_services_apikey'] = array(
    '#type' => 'textfield',
    '#title' => t('User API Key'),
    '#description' => t('The API key to use to access the ALM Server.'),
    '#default_value' => variable_get('alm_services_apikey', ALM_SERVICES_DEFAULT_KEY),
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
  $form['doiadmin']['alm_services_create_doi_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable DOI Create'),
    '#description' => t('Enable or Disable creation of records on the ALM Server for new DOIs.'),
    '#default_value' => variable_get('alm_services_create_doi_enabled', FALSE),
  );
  $form['doiadmin']['alm_services_delete_doi_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable DOI Delete'),
    '#description' => t('Enable or Disable deletion of records on the ALM Server for existing DOIs.'),
    '#default_value' => variable_get('alm_services_delete_doi_enabled', FALSE),
  );
  $form['doiadmin']['alm_services_adminuser'] = array(
    '#type' => 'textfield',
    '#title' => t('Admin Username'),
    '#description' => t('The administrator username to use when creating new DOI records.'),
    '#default_value' => variable_get('alm_services_adminuser', ''),
  );
  $form['doiadmin']['alm_services_adminpass'] = array(
    '#type' => 'textfield',
    '#title' => t('Admin Password'),
    '#description' => t('The API key to use to access the ALM Server.'),
    '#default_value' => variable_get('alm_services_adminpass', ''),
  );
  return system_settings_form($form);
}
