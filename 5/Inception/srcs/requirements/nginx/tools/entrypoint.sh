#!/bin/bash

# Create the certificate files from environment variables
echo "$CERTS_CRT" > /etc/ssl/certs/nginx.crt
echo "$CERTS_KEY" > /etc/ssl/certs/nginx.key

# Substitute environment variables in the template configuration file
envsubst '${DOMAIN_NAME}' < /etc/nginx/conf.d/default.conf.template > /etc/nginx/conf.d/default.conf

# Run the original entrypoint script for NGINX
nginx -g 'daemon off;'
