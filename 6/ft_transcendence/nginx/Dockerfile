FROM nginx:alpine

RUN rm -r /etc/nginx/conf.d/default.conf

RUN apk upgrade --no-cache &&               \
    apk add --no-cache  openssl             \
                        nginx               \
                        curl 

  
RUN openssl	req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/ssl/private/nginx_pem.pem \
    -out /etc/ssl/certs/nginx_cer.crt \
    -subj "/C=KR/ST=Seoul/L=Gaepo/O=42Seoul/OU=./CN=junhylee.42.fr/emailAddress=junhylee@student.42seoul.kr"

COPY --chmod=644 ./nginx.conf /etc/nginx/nginx.conf


CMD ["nginx", "-g", "daemon off;"]

