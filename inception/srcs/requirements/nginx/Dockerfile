FROM alpine:3.14

RUN apk update && apk add nginx openssl

COPY ./conf/nginx.conf /etc/nginx/nginx.conf

RUN mkdir -p /run/nginx

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]