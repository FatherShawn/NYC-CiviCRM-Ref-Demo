<?php
/**
 * @file nyc_ref_demo.views.inc
 * 
 * @author Shawn P. Duncan <shawn@c3design.org>
 * @date   4/3/14,  11:43 AM
 *
 * @brief auto-included views file
 *
 * Copyright 2014 by Shawn P. Duncan.  This code is
 * released under the GNU General Public License.
 * Which means that it is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 * http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt
 */

function nyc_ref_demo_views_data_alter(&$data) {
  /*
   * Create relationship between our civicrm_contact_ref field and CiviCRM contact id - nets us
   * all the other related tables.  The first key in the $data array entry below is
   * field_data_field_MACHINE-NAME.  So if the machine name of the drupal field is obiwan then the line would read
   * $data['field_data_field_obiwan']['civicrm_contact'] = array(
   * */
  $data['field_data_field_crm']['civicrm_contact'] = array(
    'group' => 'CiviCRM',
    'title' => t('CiviCRM Contact'),
    'help' => t('The fields in the record of the contact referenced.'),
    'relationship' => array(
      // Table to join to.
      'base' => 'civicrm_contact',
      // Field in that table to join with.
      'base field' => 'id',
      /*Field in the field_data_field_crm table to join with.
       * If the machine name of the drupal field is obiwan then this value will be
       * field_obiwan_contact_id
       * */
      'field' => 'field_crm_contact_id',
      'handler' => 'views_handler_relationship',
      'label' => t('Related Contact'),
      'title' => t('Related CiviCRM Contact'),
      'help' => t('The fields in the record of the contact referenced.'),
    ),
  );
}