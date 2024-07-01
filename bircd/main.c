#include "bircd.h"

// 메인 함수
int main(int ac, char **av)
{
    t_env e;

    // 환경 초기화
    init_env(&e);
    // 옵션 파싱
    get_opt(&e, ac, av);
    // 서버 소켓 생성
    srv_create(&e, e.port);
    // 메인 루프 실행
    main_loop(&e);
    return (0);
}
