#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "bircd.h"

// 클라이언트 연결을 수락하는 함수
void srv_accept(t_env *e, int s)
{
    int cs;
    struct sockaddr_in csin;
    socklen_t csin_len;

    csin_len = sizeof(csin);
    cs = X(-1, accept(s, (struct sockaddr*)&csin, &csin_len), "accept");
    printf("New client #%d from %s:%d\n", cs,
           inet_ntoa(csin.sin_addr), ntohs(csin.sin_port));
    clean_fd(&e->fds[cs]);
    e->fds[cs].type = FD_CLIENT;
    e->fds[cs].fct_read = client_read;
    e->fds[cs].fct_write = client_write;
}

이와 같은 주석은 각 코드의 기능과 역할을 이해하는 데 도움이 됩니다. 필요에 따라 더 자세한 설명이나 추가 주석을 달 수 있습니다.