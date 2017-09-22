BYU Drupal Install Profile
======================
BYU Installation profile for Drupal 7
Updated with the 2016 Brand and component-based modules.
Installs and configures a Drupal site with the BYU theme as well as a number of necessary modules and settings.

###This package includes Drupal 7.56 with the following modules:

####BYU Modules
* BYU Calendar (displays categorized events from calendar.byu.edu in various styles)
* Views Card (allows BYU Card display type in views)
* Menu Landing Page Views (generates landing page blocks)
* BYU Views News
* Youtube (BYU Youtube Hero)
* Hero (BYU Style Hero)

#### General Drupal Modules
* A11y - analyzes your site for accessibility compliance
* Backup and Migrate - backup regularly and automatically, every site should use this.
* CAS (Library and Module)
* Features - save parts of your website / displays and export or share them with another website.
* Field Formatter Class - add classes and settings per field for custom formatting
* Fontawesome - easily add google fonts (including BYU suggested ones)
* Honeypot, Captcha, and Recaptcha - options for preventing spam
* Views
* Webform
* So many more! 

##Installation Instructions
1. You'll need to configure your server to run drupal. See [Drupal Requirements](https://drupal.org/requirements/php) for more details. Don't forget to enable the PHP cURL extension.
2. Create a database for your Drupal installation
3. Copy the entire folder to your web server's root directory
4. Run the installation script by visiting your site in a web browser(e.g. example.byu.edu/install.php)
5. Configure the site settings
6. Configure your site header in 'Admin > Appearance > Settings' according to organizational level.
7. CAS should be enabled and configured. You will need to set your CAS username as admin under 'Admin > People'
8. Populate the site content and build a great site!
