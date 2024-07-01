#include <stdlib.h>
#include <sys/resource.h>
#include "bircd.h"

// 환경을 초기화하는 함수
void init_env(t_env *e)
{
    int i;
    struct rlimit rlp;

    // 파일 디스크립터의 최대 개수를 가져옴
    X(-1, getrlimit(RLIMIT_NOFILE, &rlp), "getrlimit");
    e->maxfd = rlp.rlim_cur;
    // 파일 디스크립터 배열 할당
    e->fds = (t_fd*)Xv(NULL, malloc(sizeof(*e->fds) * e->maxfd), "malloc");
    i = 0;
    while (i < e->maxfd)
    {
        clean_fd(&e->fds[i]);
        i++;
    }
}
