<?php
/**
 * @file
 * feature_wizzlern_agency.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function feature_wizzlern_agency_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  return $roles;
}
