<?php
/**
 * @file
 * Rules extension file.
 */

/**
 * Implements hook_rules_action_info().
 */
function lagotto_services_rules_action_info() {
  $defaults = array(
    'group' => t('Services'),
  );

  return array(
    'lagotto_services_rules_doi_update' => $defaults + array(
      'parameter' => array(
        'doi' => array(
          'type' => 'text',
          'label' => t('doi'),
          'description' => t(
            'A publication DOI in the form "10.nnnn/*". URL forms (doi: and dx.doi.org) are accepted and converted.'
          ),
        ),
        'date' => array(
          'type' => 'date',
          'label' => t('Publication date'),
        ),
        'title' => array(
          'type' => 'text',
          'label' => t('Title of publication'),
          'translatable' => TRUE,
        ),
        'autoupdate' => array(
          'type' => 'boolean',
          'label' => t('Update if already exists?'),
        ),
      ),
      'provides' => array(
        'data_returned' => array(
          'type' => 'text',
          'label' => t('Returned data'),
        ),
      ),
      'label' => t('Submit article info to Lagotto server'),
    ),
    'lagotto_services_rules_doi_delete' => $defaults + array(
      'parameter' => array(
        'doi' => array(
          'type' => 'text',
          'label' => t('doi'),
          'description' => t(
            'A publication DOI in the form "10.nnnn/*". URL forms (doi: and dx.doi.org) are accepted and converted.'
          ),
        ),
      ),
      'provides' => array(
        'data_returned' => array(
          'type' => 'text',
          'label' => t('Returned data'),
        ),
      ),
      'label' => t('Delete article info on Lagotto server'),
    ),
  );
}

/**
 * Submit request to the ALM server to add/update article info.
 */
function lagotto_services_rules_doi_update($doi, $date, $title, $autoupdate) {
  $data = lagotto_services_submit_add_doi($doi, $date, $title, $autoupdate);

  return array('data_returned' => var_export($data, TRUE));
}

/**
 * Submit request to the ALM server to delete article info.
 */
function lagotto_services_rules_doi_delete($doi) {
  $data = lagotto_services_submit_remove_doi($doi);

  return array('data_returned' => var_export($data, TRUE));
}
