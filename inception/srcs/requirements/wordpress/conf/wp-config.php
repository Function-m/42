<?php
define('DB_NAME', getenv('WORDPRESS_DB_NAME'));
define('DB_USER', getenv('WORDPRESS_DB_USER'));
define('DB_PASSWORD', getenv('WORDPRESS_DB_PASSWORD'));
define('DB_HOST', getenv('WORDPRESS_DB_HOST'));
define('DB_CHARSET', 'utf8');
define('DB_COLLATE', '');

define('AUTH_KEY',         '42Seoul');
define('SECURE_AUTH_KEY',  '42Seoul');
define('LOGGED_IN_KEY',    '42Seoul');
define('NONCE_KEY',        '42Seoul');
define('AUTH_SALT',        '42Seoul');
define('SECURE_AUTH_SALT', '42Seoul');
define('LOGGED_IN_SALT',   '42Seoul');
define('NONCE_SALT',       '42Seoul');

$table_prefix  = 'wp_';

define('WP_DEBUG', false);

if ( !defined('ABSPATH') )
	define('ABSPATH', dirname(__FILE__) . '/');

require_once(ABSPATH . 'wp-settings.php');
?>