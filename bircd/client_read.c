#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include "bircd.h"

// 클라이언트로부터 데이터를 읽는 함수
void client_read(t_env *e, int cs)
{
    int r;
    int i;

    // 클라이언트로부터 데이터 수신
    r = recv(cs, e->fds[cs].buf_read, BUF_SIZE, 0);
    if (r <= 0)
    {
        // 연결이 끊긴 경우
        close(cs);
        clean_fd(&e->fds[cs]);
        printf("client #%d gone away\n", cs);
    }
    else
    {
        // 다른 클라이언트에게 데이터 전송
        i = 0;
        while (i < e->maxfd)
        {
            if ((e->fds[i].type == FD_CLIENT) && (i != cs))
                send(i, e->fds[cs].buf_read, r, 0);
            i++;
        }
    }
}
