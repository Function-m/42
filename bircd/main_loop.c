#include "bircd.h"

// 메인 루프 함수
void main_loop(t_env *e)
{
    while (1)
    {
        init_fd(e);
        do_select(e);
        check_fd(e);
    }
}
