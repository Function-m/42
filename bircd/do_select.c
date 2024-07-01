#include <stdlib.h>
#include "bircd.h"

// select 시스템 콜을 호출하는 함수
void do_select(t_env *e)
{
    e->r = select(e->max + 1, &e->fd_read, &e->fd_write, NULL, NULL);
}
