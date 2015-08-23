<?php

/**
 * @file
 * Drush commands provided by Patch Info module.
 */

/**
 * Implements hook_drush_command().
 */
function patchinfo_drush_command() {
  $items = array();

  $items['patchinfo-list'] = array(
    'description' => 'Show a report of patches applied to Drupal core and contrib projects.',
    'arguments' => array(
      'projects' => 'Optional. A list of installed projects to show.',
    ),
    'options' => array(
      'pipe' => 'Return a list of the projects with any patches applied, one project per line.',
    ),
    'outputformat' => array(
      'default' => 'table',
      'pipe-format' => 'list',
      'field-labels' => array(
        'name' => 'Name',
        'label' => 'Title',
        'delta' => '#',
        'info' => 'Info',
      ),
      'fields-default' => array('label', 'delta', 'info'),
      'fields-pipe' => array('name'),
      'output-data-type' => 'format-table',
    ),
    'aliases' => array('pil', 'pi-list'),
  );

  return $items;
}

/**
 * Command callback for patchinfo-list command.
 *
 * Displays patch info for installed projects.
 *
 * @param string $limit_projects
 *   Comma-separated list of machine-readable project names.
 */
function drush_patchinfo_list($limit_projects = '') {
  $table = array();

  $limit_projects = !empty($limit_projects) ? explode(',', $limit_projects) : array();

  $patch_info = _patchinfo_get_info(TRUE);
  if (count($patch_info) > 0) {
    module_load_include('inc', 'update', 'update.compare');
    $projects = update_get_projects();
    $has_limit_projects = (count($limit_projects) > 0);
    foreach ($projects as $project) {
      if ($has_limit_projects && !in_array($project['name'], $limit_projects)) {
        continue;
      }
      $patches = _patchinfo_get_patches($patch_info, $project);
      if (count($patches) > 0) {
        $label = $project['info']['name'] . ' (' . $project['name'] . ')';
        if ($project['name'] == 'drupal') {
          $label = 'Drupal (drupal)';
        }
        foreach ($patches as $delta => $patch) {
          $table[$project['name'] . '-' . $delta] = array(
            'name' => $project['name'],
            'label' => $label,
            'delta' => $delta,
            'info' => chunk_split($patch['info']) . $patch['url'],
          );
        }
      }
    }
  }

  return $table;
}
