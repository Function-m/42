# FROM node:21-alpine3.18
FROM node:18.17.0-alpine

WORKDIR /usr/src/

COPY ./package.json ./
COPY ./srcs ./srcs

# RUN apk add --no-cache python3
# RUN apk add --no-cache python3 make g++
RUN apk upgrade --no-cache
RUN apk add --no-cache python3 make g++ linux-headers
RUN apk add --no-cache util-linux

# RUN apk add --no-cache python3 make g++ linux-headers
	
RUN npm install
# RUN npm config set strict-ssl false

CMD ["npm", "run", "--prefix", "/usr/src", "dev"]
