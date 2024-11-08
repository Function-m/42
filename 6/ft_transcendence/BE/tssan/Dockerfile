FROM python:3.12.4

ENV PYTHONDONTWRITEBYTECODE 1
ENV PYTHONUNBUFFERED 1

COPY . /usr/src/api/
COPY --chmod=777 ./migrate.sh /
WORKDIR /usr/src/api

RUN pip3 install --upgrade pip
RUN pip3 install -r requirements.txt

ENTRYPOINT ["/migrate.sh"]