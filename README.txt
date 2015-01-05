Overview
========
This module provides a PHP wrapper for the web services supplied by the
article metrics server Lagotto[1], used by journal publishing companies to track
metrics of journal use such as page views, PubMed and Scopus references,
Facebook likes, and Mendeley article 'saves'.

The module encapsulates the basic "fetch information", complete with access
control, and provides an admin page where the base url and api keys can be
managed. The complete results from the remote server are made available to the
client.

The submodule lagotto_services_submit enables the add, modify and delete
operations for articles on the server.

REQUIREMENTS
============
 - Runs on PHP 5.3.x
 - Drupal 7.x (x > 27)
 - Accessible Lagotto server and appropriate user api keys

RESTRICTIONS
============
Although Lagotto servers do support the use of PubMed and Mendeley IDs to
discover articles, this module does not currently attempt to support lookup
using them; only DOIs are supported. PubMed and Mendeley IDs are still included
in the returned results.

INSTALLATION
============
  1. Extract the module to sites/all/modules or sites/xx/modules depending on
     whether or not you have a multisite installation.

  2. Enable the module at admin/modules or use drush, e.g.:

     drush pm-enable lagotto_services

CONFIGURATION
=============
The module's administration page is at admin/config/services/lagotto_services
with additional role-based access permissions on the admin/people/permissions
page.

The module requires an external server running the Lagotto software. Provide
the base URL for this server on the configuration form.

USAGE
=====
There are no out-of-the-box visible elements provided in this module. Software
must call one of the php API functions, of which the main ones are:

  lagotto_services_fetch_doi
  lagotto_services_service_host
  lagotto_services_service_key
  lagotto_services_service_url

Refer to the function comments for additional information on these calls.

AUTHORS
=======
rivimey - https://www.drupal.org/u/rivimey
nlisgo - https://www.drupal.org/u/nlisgo

[1] Lagotto development is sponsored by CrossRef and the Public Library of
Science:
 - http://www.crossref.org
 - http://www.plos.org
 - http://articlemetrics.github.io/docs
