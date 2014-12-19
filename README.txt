Overview
================

This module provides a PHP wrapper for the web services supplied by the
article metrics server Lagotto, which is used by journal publishing companies
to track metrics of journal use such as page views, Facebook likes, and Mendeley
article 'saves'.

The module encapsulates the basic "fetch information", "delete article" and
"add article" operations, complete with access control, and provides an admin
page where the base url and api keys can be managed. The complete results from
the remote server are made available to the client.


REQUIREMENTS
================

 - Runs on PHP 5.3.x
 - Drupal 7.x (x > 27)
 - Accessible Lagotto server and appropriate user api keys


INSTALLATION
================

  1. Extract the module to sites/all/modules or sites/xx/modules depending on
     whether or not you have a multisite installation.
  2. Enable the module at admin/modules or use drush.


CONFIGURATION
================

The module's administration page is at admin/config/services/lagotto_services
with additional role-based access permissions on the admin/people/permissions
page.

The module requires an external server running the Lagotto software. Provide
the URL to this server on the configuration form.


USAGE
================

There are no out-of-the-box visible elements provided in this module. Software
must call one of the php API functions, of which the main ones are:

  lagotto_services_add_doi *
  lagotto_services_remove_doi *
  lagotto_services_fetch_doi
  lagotto_services_service_host
  lagotto_services_service_creds
  lagotto_services_service_key
  lagotto_services_service_url

Refer to the function comments for additional information on these calls. The
two calls marked '*' have additional execution protection accessed using the
configuration page.


AUTHORS
================

rivimey - https://www.drupal.org/u/rivimey
nlisgo - https://www.drupal.org/u/nlisgo
