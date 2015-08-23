CONTENTS OF THIS FILE
---------------------

 * Introduction
 * Requirements
 * Recommended modules
 * Installation
 * Configuration
 * Maintainers


INTRODUCTION
------------

The Patch Info module allows you to add information about patches to a
modules .info file. It will show the information prominently in the
update report and on the update manager form.

 * For a full description of the module, visit the project page:
   https://www.drupal.org/sandbox/feyp/2556153

 * To submit bug reports and feature suggestions, or to track changes:
   https://www.drupal.org/node/add/project-issue/2556153


REQUIREMENTS
------------

This module does not depend on any other modules.


RECOMMENDED MODULES
-------------------

 * Drush (https://github.com/drush-ops/drush):
   When enabled, you can use drush patchinfo-list to get a list of
   patches applied to Drupal core or contributed modules on your system.
   Refer to drush help patchinfo-list for a list of available options.


INSTALLATION
------------

 * Install as you would normally install a contributed Drupal module. See:
   https://drupal.org/documentation/install/modules-themes/modules-7
   for further information.


CONFIGURATION
-------------

 * Add information about a patch

   In the .info file of a patched module, add a new entry like the one
   shown below:

   patch[] = https://www.drupal.org/node/1739718 Issue 1739718, Patch #32

   You can add multiple entries. Each entry should start with the URL
   of the issue or patch followed by any kind of information about the
   patch. The URL is optional.

   You can use any URL or description, that is convenient to you.

   If you are patching a submodule, you may add the patch entry to the
   .info file of the submodule.

 * Exclude module from update check

   The module will extend the update report settings form at Reports »
   Available Updates » Settings with a textarea, where you can list
   modules, that should be excluded from the update check. List one
   module per line. Use the machine readable module name of the module.
   Modules, which are excluded from the update check will be displayed
   prominently above the update report.


MAINTAINERS
-----------

Current maintainers:
 * Patrick Fey (feyp) - https://drupal.org/u/feyp
 * David Franke (mirroar) - https://drupal.org/u/mirroar

This project has been partly sponsored by:
 * werk21 GmbH
   werk21 is a full service agency from Berlin, Germany, for politics,
   government, organizations and NGOs. Together with its customers,
   werk21 has realized over 60 Drupal web sites (since version 5).
   Visit http://www.werk21.de for more information.
