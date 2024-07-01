#include "bircd.h"

// 파일 디스크립터를 체크하고 처리하는 함수
void check_fd(t_env *e)
{
    int i;

    i = 0;
    while ((i < e->maxfd) && (e->r > 0))
    {
        if (FD_ISSET(i, &e->fd_read))
            e->fds[i].fct_read(e, i);
        if (FD_ISSET(i, &e->fd_write))
            e->fds[i].fct_write(e, i);
        if (FD_ISSET(i, &e->fd_read) || FD_ISSET(i, &e->fd_write))
            e->r--;
        i++;
    }
}
