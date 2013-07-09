<?php
function pn_nid_admin() {
  return drupal_render(drupal_get_form('pn_nid_settings_form')) . drupal_render(drupal_get_form('pn_nid_clear_form'));
}

function pn_nid_clear_form() {
  $form['description']['#markup'] = '<h2>Cleared Previous/Next Cache</h2><p>Use this button to manually remove all cached Previous/Next Node IDs. They will be rebuilt the next time they are requested. This is useful if nodes have been added, deleted or published to/from a given sequence.</p>';

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Clear cached Previous/Next Node IDs',
  );

  return $form;
}

function pn_nid_clear_form_submit($form, &$form_state) {
  pn_nid_clear();
}

function pn_nid_settings_form() {
  $form['description']['#markup'] = '<h2>Settings</h2><p>Choose when the Previous/Next Node ID Cache is emptied. For most sites, the third option will be the most appropriate because Creating/Updating/Deleting nodes can affect the next or previous node in a given sequence.</p>';

  $form['pn_nid_cache_clear'] = array(
    '#type' => 'radios',
    '#default_value' => variable_get('pn_nid_cache_clear', 2),
    '#title' => t('When to delete the Previous/Next Cache.'),
    '#options' => array(
      '0' => t('Do not automatically clear the cache. I will manually manage the cache contents.'),
      '1' => t('Clear the Previous/Next NID Cache on cron.'),
      '2' => t('Clear the Previous/Next NID Cache every time a node is created, updated or deleted (recommended).'),
    ),
  );

  return system_settings_form($form);
}

