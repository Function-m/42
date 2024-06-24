### 완벽한 프로젝트 지침: 초심자를 위한 한글 설명 포함

#### 1. 프로젝트 디렉터리 생성 및 파일 생성

먼저 프로젝트 디렉터리와 필요한 파일들을 생성합니다.

```sh
# 디렉터리 및 파일 생성
mkdir -p ~/suham/srcs/requirements/{mariadb,nginx,wordpress}/conf
mkdir -p ~/suham/srcs/requirements/nginx/certs
touch ~/suham/{Makefile,srcs/.env,srcs/docker-compose.yml}
touch ~/suham/srcs/requirements/{mariadb,Dockerfile,wordpress,Dockerfile,nginx,Dockerfile}
touch ~/suham/srcs/requirements/mariadb/conf/my.cnf
touch ~/suham/srcs/requirements/wordpress/conf/www.conf
touch ~/suham/srcs/requirements/nginx/conf/nginx.conf
touch ~/suham/srcs/requirements/mariadb/tools/create_users.sql
```

**설명**:
- `mkdir -p`는 중첩된 디렉터리를 생성합니다.
- `touch`는 파일을 생성합니다.

#### 2. 파일 권한 설정

```sh
# 필요한 파일 권한 설정
chmod 600 ~/suham/srcs/.env
```

**설명**:
- `chmod 600`은 파일 소유자에게 읽기 및 쓰기 권한을 부여하고, 다른 사용자에게는 접근을 차단합니다.

#### 3. 프로젝트 파일 작성

##### 3.1 .env 파일
환경 변수는 .env 파일에서 관리됩니다. 

`~/suham/srcs/.env`
```plaintext
# .env
DOMAIN_NAME=suham.42.fr
CERTS_=./srcs/requirements/nginx/certs
MYSQL_ROOT_PASSWORD=suham_root_password  # 사용자가 직접 입력
MYSQL_USER=suham_user  # 사용자가 직접 입력
MYSQL_PASSWORD=suham_password  # 사용자가 직접 입력
MYSQL_DATABASE=wordpress
DATA_PATH_HOST=/home/suham/data
```

**설명**:
- `.env` 파일은 환경 변수를 저장하여 Docker Compose에서 사용합니다.
- 데이터베이스 비밀번호와 사용자 등 민감한 정보를 포함합니다.

##### 3.2 Makefile
`Makefile`은 프로젝트를 자동화하는 스크립트입니다. 이 파일은 Docker Compose 명령을 쉽게 실행할 수 있도록 합니다.

`~/suham/Makefile`
```Makefile
# Makefile

all: certs build up

certs:
	@mkdir -p srcs/requirements/nginx/certs
	openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
		-keyout srcs/requirements/nginx/certs/server.key \
		-out srcs/requirements/nginx/certs/server.crt \
		-subj "/C=US/ST=State/L=Locality/O=Organization/OU=Unit/CN=${DOMAIN_NAME}"

build:
	docker-compose -f srcs/docker-compose.yml build

up:
	docker-compose -f srcs/docker-compose.yml up -d

down:
	docker-compose -f srcs/docker-compose.yml down

clean:
	docker-compose -f srcs/docker-compose.yml down -v --rmi all

re: clean all
```

**설명**:
- `certs`: SSL 인증서를 생성합니다.
- `build`: Docker 이미지를 빌드합니다.
- `up`: Docker Compose를 사용하여 컨테이너를 백그라운드에서 실행합니다.
- `down`: 실행 중인 컨테이너를 중지하고 삭제합니다.
- `clean`: 컨테이너, 볼륨 및 이미지를 모두 삭제합니다.
- `re`: clean 후 다시 모든 작업을 수행합니다.

##### 3.3 docker-compose.yml
`docker-compose.yml`은 여러 Docker 컨테이너를 정의하고 구성합니다.

`~/suham/srcs/docker-compose.yml`
```yaml
version: '3.8'

services:
  mariadb:
    container_name: mariadb
    build: ./requirements/mariadb
    environment:
      MYSQL_ROOT_PASSWORD: ${MYSQL_ROOT_PASSWORD}
      MYSQL_DATABASE: ${MYSQL_DATABASE}
      MYSQL_USER: ${MYSQL_USER}
      MYSQL_PASSWORD: ${MYSQL_PASSWORD}
    volumes:
      - ${DATA_PATH_HOST}/mariadb:/var/lib/mysql
    networks:
      - wp_network
    restart: always

  wordpress:
    container_name: wordpress
    build: ./requirements/wordpress
    environment:
      WORDPRESS_DB_HOST: mariadb
      WORDPRESS_DB_USER: ${MYSQL_USER}
      WORDPRESS_DB_PASSWORD: ${MYSQL_PASSWORD}
      WORDPRESS_DB_NAME: ${MYSQL_DATABASE}
    volumes:
      - ${DATA_PATH_HOST}/wordpress:/var/www/html
    depends_on:
      - mariadb
    networks:
      - wp_network
    restart: always

  nginx:
    container_name: nginx
    build: ./requirements/nginx
    ports:
      - "443:443"
    volumes:
      - ${DATA_PATH_HOST}/wordpress:/var/www/html:ro
      - ${CERTS_}:/etc/nginx/certs
    depends_on:
      - wordpress
    networks:
      - wp_network
    restart: always

volumes:
  mariadb_data:
  wordpress_data:

networks:
  wp_network:
```

**설명**:
- `services`: 각 서비스(mariadb, wordpress, nginx)에 대한 설정을 정의합니다.
- `volumes`: 데이터가 지속되도록 호스트 경로와 컨테이너 경로를 연결합니다.
- `networks`: 컨테이너 간 통신을 위한 네트워크를 정의합니다.
- `restart: always`: 컨테이너가 충돌 시 자동으로 재시작합니다.

##### 3.4 Dockerfiles
각 서비스는 자체 Dockerfile을 통해 빌드됩니다.

###### 3.4.1 MariaDB Dockerfile
`~/suham/srcs/requirements/mariadb/Dockerfile`
```Dockerfile
# requirements/mariadb/Dockerfile

FROM alpine:3.14

RUN apk update && apk add mariadb mariadb-client openrc

COPY ./conf/my.cnf /etc/mysql/my.cnf
COPY ./tools/create_users.sql /docker-entrypoint-initdb.d/

RUN mysql_install_db --user=mysql --datadir=/var/lib/mysql && \
    mkdir -p /run/mysqld && \
    chown -R mysql:mysql /run/mysqld /var/lib/mysql /etc/mysql /docker-entrypoint-initdb.d/

EXPOSE 3306

CMD ["mysqld"]
```

**설명**:
- `FROM alpine:3.14`: Alpine 리눅스를 기반 이미지로 사용합니다.
- `RUN apk update && apk add`: 패키지를 업데이트하고 MariaDB를 설치합니다.
- `RUN mysql_install_db --user=mysql --datadir=/var/lib/mysql`: MariaDB 데이터 디렉터리를 초기화합니다.
- `COPY`: 설정 파일을 컨테이너로 복사합니다.
- `CMD ["mysqld"]`: MariaDB 데몬을 실행합니다.

###### 3.4.2 WordPress Dockerfile
`~/suham/srcs/requirements/wordpress/Dockerfile`
```Dockerfile
# requirements/wordpress/Dockerfile

FROM alpine:3.14

RUN apk update && apk add php7 php7-fpm php7-opcache php7-gd php7-mysqli php7-zlib php7-curl php7-mbstring php7-json php7-session

RUN mkdir -p /run/php-fpm7 && \
    sed -i "s/;daemonize = yes/daemonize = no/g" /etc/php7/php-fpm.conf && \
    sed -i "s/;cgi.fix_pathinfo=1/cgi.fix_pathinfo=0/g" /etc/php7/php.ini

COPY ./conf/www.conf /etc/php7/php-fpm.d/www.conf

RUN wget https://wordpress.org/latest.tar.gz && \
    tar -xzvf latest.tar.gz && \
    rm latest.tar.gz && \
    mv wordpress /var/www/html

EXPOSE 9000

CMD ["php-fpm7", "-F"]
```

**설명**:
- `apk add php7 php7-fpm`: PHP와 PHP-FPM을 설치합니다.
- `sed -i`: 설정 파일을 수정합니다.
- `wget https://wordpress.org/latest.tar.gz`: WordPress를 다운로드하여 설치합니다.
- `CMD ["php-fpm7", "-F"]`: PHP-FPM 데몬을 실행합니다.

###### 3.4.3 NGINX Dockerfile
`~/suham/srcs/requirements/nginx/Dockerfile`
```Dockerfile
# requirements/nginx/Dockerfile

FROM alpine:3.14

RUN apk update && apk add nginx openssl

COPY ./conf/nginx.conf /etc/nginx/nginx.conf

RUN mkdir -p /run/nginx

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]
```

**설명**:
- `apk add nginx openssl`: NGINX와 OpenSSL을 설치합니다.
- `COPY ./conf/nginx.conf /etc/nginx/nginx.conf`: NGINX 설정 파일을 복사합니다.
- `CMD ["nginx", "-g", "daemon off;"]`: NGINX를 실행합니다.

#### 4. 설정 파일 작성

##### 4.1 MariaDB 설정 파일
`~/suham/srcs/requirements/mariadb/conf/my.cnf`
```ini
[mysqld]
user

=mysql
datadir=/var/lib/mysql
port=3306
skip-networking=0
skip-bind-address
```

**설명**:
- MariaDB 서버의 기본 설정 파일입니다.

##### 4.2 WordPress PHP-FPM 설정 파일
`~/suham/srcs/requirements/wordpress/conf/www.conf`
```ini
[www]
user = nobody
group = nobody
listen = 9000
listen.owner = nobody
listen.group = nobody
pm = dynamic
pm.max_children = 10
pm.start_servers = 3
pm.min_spare_servers = 2
pm.max_spare_servers = 5
```

**설명**:
- PHP-FPM의 기본 설정 파일입니다.

##### 4.3 NGINX 설정 파일
`~/suham/srcs/requirements/nginx/conf/nginx.conf`
```nginx
user  nginx;
worker_processes  1;

error_log  /var/log/nginx/error.log warn;
pid        /var/run/nginx.pid;

events {
    worker_connections  1024;
}

http {
    include       /etc/nginx/mime.types;
    default_type  application/octet-stream;

    log_format  main  '$remote_addr - $remote_user [$time_local] "$request" '
                      '$status $body_bytes_sent "$http_referer" '
                      '"$http_user_agent" "$http_x_forwarded_for"';

    access_log  /var/log/nginx/access.log  main;

    sendfile        on;
    #tcp_nopush     on;

    keepalive_timeout  65;

    #gzip  on;

    server {
        listen       443 ssl;
        server_name  ${DOMAIN_NAME};

        ssl_certificate     /etc/nginx/certs/server.crt;
        ssl_certificate_key /etc/nginx/certs/server.key;
        ssl_protocols       TLSv1.2 TLSv1.3;
        ssl_ciphers         HIGH:!aNULL:!MD5;

        location / {
            root   /var/www/html;
            index  index.php index.html index.htm;
        }

        location ~ \.php$ {
            root           /var/www/html;
            fastcgi_pass   wordpress:9000;
            fastcgi_index  index.php;
            fastcgi_param  SCRIPT_FILENAME  /var/www/html$fastcgi_script_name;
            include        fastcgi_params;
        }
    }
}
```

**설명**:
- NGINX의 기본 설정 파일로, SSL 설정과 WordPress에 대한 리버스 프록시 설정을 포함합니다.

##### 4.4 MariaDB 사용자 생성 스크립트
`~/suham/srcs/requirements/mariadb/tools/create_users.sql`
```sql
-- create_users.sql

CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE};
USE ${MYSQL_DATABASE};

-- Admin user
CREATE USER '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';
FLUSH PRIVILEGES;

-- Regular user
CREATE USER 'regular_user'@'%' IDENTIFIED BY 'regular_password';
GRANT SELECT, INSERT, UPDATE, DELETE ON ${MYSQL_DATABASE}.* TO 'regular_user'@'%';
FLUSH PRIVILEGES;
```

**설명**:
- MariaDB에 필요한 사용자를 생성하는 SQL 스크립트입니다.

#### 5. SSL 인증서 생성

Makefile에서 SSL 인증서 생성을 포함합니다.

```Makefile
certs:
	@mkdir -p srcs/requirements/nginx/certs
	openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
		-keyout srcs/requirements/nginx/certs/server.key \
		-out srcs/requirements/nginx/certs/server.crt \
		-subj "/C=US/ST=State/L=Locality/O=Organization/OU=Unit/CN=${DOMAIN_NAME}"
```

**설명**:
- `openssl req -x509`: 자체 서명된 SSL 인증서를 생성합니다.
- `-days 365`: 인증서 유효기간을 365일로 설정합니다.
- `-newkey rsa:2048`: 새로운 2048비트 RSA 키를 생성합니다.
- `-keyout` 및 `-out`: 키와 인증서의 출력 파일 경로를 지정합니다.

#### 6. Docker Compose 실행

프로젝트 디렉터리에서 다음 명령을 실행합니다.

```sh
cd ~/suham
make all
```

**설명**:
- `cd ~/suham`: 프로젝트 디렉터리로 이동합니다.
- `make all`: 인증서 생성, 빌드 및 Docker Compose로 컨테이너를 실행합니다.

### 전체 동작 방식 설명

1. **디렉터리 및 파일 생성**:
   - 필요한 디렉터리와 파일을 생성하고, 적절한 권한을 설정합니다.

2. **환경 변수 설정**:
   - .env 파일을 사용하여 데이터베이스 설정 및 도메인 이름 등을 정의합니다.

3. **Makefile**:
   - Makefile을 통해 인증서 생성, Docker 이미지 빌드, 컨테이너 시작/중지 등의 작업을 자동화합니다.

4. **docker-compose.yml**:
   - Docker Compose 파일에서 MariaDB, WordPress, NGINX 컨테이너를 정의하고, 이들 간의 네트워크를 설정합니다.

5. **Dockerfiles**:
   - 각 서비스(MariaDB, WordPress, NGINX)에 대한 Docker 이미지를 정의합니다.

6. **설정 파일**:
   - MariaDB, PHP-FPM, NGINX에 대한 설정 파일을 정의합니다.

7. **SSL 인증서 생성**:
   - Makefile을 통해 SSL 인증서를 생성하여 NGINX 컨테이너에서 사용합니다.

8. **Docker Compose 실행**:
   - Makefile을 사용하여 모든 컨테이너를 빌드하고 실행합니다.

9. **서비스 동작**:
   - NGINX는 443 포트를 통해 HTTPS 요청을 받아 WordPress 컨테이너로 전달합니다.
   - WordPress는 PHP-FPM을 사용하여 PHP 코드를 실행하고, MariaDB와 통신하여 데이터를 처리합니다.
   - 모든 데이터는 호스트의 볼륨에 저장되어 지속성을 유지합니다.

이 가이드를 따르면, 모든 과정이 올바르게 수행되고, 프로젝트가 정상적으로 실행될 것입니다. 추가적인 질문이 있거나 특정 설정에 대한 도움이 필요하면 언제든지 요청해 주세요.