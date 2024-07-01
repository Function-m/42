#ifndef BIRCD_H_
# define BIRCD_H_

# include <sys/select.h>

// 파일 디스크립터 상태 상수
# define FD_FREE    0
# define FD_SERV    1
# define FD_CLIENT  2

// 버퍼 크기 상수
# define BUF_SIZE   4096

// 매크로 정의
# define Xv(err,res,str)    (x_void(err,res,str,__FILE__,__LINE__))
# define X(err,res,str)     (x_int(err,res,str,__FILE__,__LINE__))
# define MAX(a,b)   ((a > b) ? a : b)

# define USAGE      "Usage: %s port\n"

// 파일 디스크립터 구조체 정의
typedef struct  s_fd
{
    int type;
    void (*fct_read)();
    void (*fct_write)();
    char buf_read[BUF_SIZE + 1];
    char buf_write[BUF_SIZE + 1];
}       t_fd;

// 환경 구조체 정의
typedef struct  s_env
{
    t_fd        *fds;
    int         port;
    int         maxfd;
    int         max;
    int         r;
    fd_set      fd_read;
    fd_set      fd_write;
}       t_env;

// 함수 선언
void    init_env(t_env *e);
void    get_opt(t_env *e, int ac, char **av);
void    main_loop(t_env *e);
void    srv_create(t_env *e, int port);
void    srv_accept(t_env *e, int s);
void    client_read(t_env *e, int cs);
void    client_write(t_env *e, int cs);
void    clean_fd(t_fd *fd);
int     x_int(int err, int res, char *str, char *file, int line);
void    *x_void(void *err, void *res, char *str, char *file, int line);
void    init_fd(t_env *e);
void    do_select(t_env *e);
void    check_fd(t_env *e);

#endif /* !BIRCD_H_ */
