#include <stdlib.h>
#include "bircd.h"

// 파일 디스크립터를 초기화하는 함수
void clean_fd(t_fd *fd)
{
    fd->type = FD_FREE;
    fd->fct_read = NULL;
    fd->fct_write = NULL;
}
