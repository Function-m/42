#!/bin/bash
set -e

sh /setup.sh

exec php-fpm83 -F
