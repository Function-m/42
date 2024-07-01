# 소스 파일 목록
SRCS = main.c init_env.c clean_fd.c get_opt.c x.c main_loop.c \
       init_fd.c do_select.c check_fd.c \
       srv_create.c srv_accept.c \
       client_read.c client_write.c

# 오브젝트 파일 목록
OBJS = ${SRCS:.c=.o}

# 실행 파일 이름
NAME = bircd

# 컴파일 옵션
CFLAGS = -I. -g3 -Wall -Werror
LDFLAGS = 

# 컴파일러 및 클린 명령
CC = gcc
RM = rm -f

# 실행 파일 생성 규칙
${NAME}:    ${OBJS}
            ${CC} -o ${NAME} ${OBJS} ${LDFLAGS}

# 기본 규칙 (모두 컴파일)
all:        ${NAME}

# 오브젝트 파일 삭제 규칙
clean:
            ${RM} ${OBJS} *~ #*#

# 실행 파일 및 오브젝트 파일 삭제 규칙
fclean:     clean
            ${RM} ${NAME}

# 재컴파일 규칙
re:         fclean all
