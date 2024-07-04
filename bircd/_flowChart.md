┌───────────────────────────────────────────────────────────────┐
│                           main                                │
│   ┌───────────────────────────────────────────────────────┐   │
│   │                1. init_env 호출                        │   │
│   │    - 환경 초기화: getrlimit, malloc, clean_fd 호출        │   │
│   └───────────────────────────────────────────────────────┘   │
│   ┌───────────────────────────────────────────────────────┐   │
│   │                2. get_opt 호출                         │   │
│   │    - 명령줄 옵션 파싱: 인자 개수 확인, 포트 번호 설정            │   │
│   └───────────────────────────────────────────────────────┘   │
│   ┌───────────────────────────────────────────────────────┐   │
│   │                3. srv_create 호출                      │   │
│   │    - 서버 소켓 생성: getprotobyname, socket,             │   │
│   │      bind, listen 호출                                 │   │
│   └───────────────────────────────────────────────────────┘   │
│   ┌───────────────────────────────────────────────────────┐   │
│   │                4. main_loop 호출                       │   │
│   │    - 메인 루프 시작                                      │   │
│   └───────────────────────────────────────────────────────┘   │
└───────────────────────────────────────────────────────────────┘
        │
        ▼
┌───────────────────────────────────────────────────────────────┐
│                       main_loop                               │
│   ┌───────────────────────────────────────────────────────┐   │
│   │               1. init_fd 호출                          │   │
│   │    - 파일 디스크립터 초기화: FD_ZERO, FD_SET 호출            │   │
│   └───────────────────────────────────────────────────────┘   │
│   ┌───────────────────────────────────────────────────────┐   │
│   │               2. do_select 호출                        │   │
│   │    - select 시스템 콜 호출                               │   │
│   └───────────────────────────────────────────────────────┘   │
│   ┌───────────────────────────────────────────────────────┐   │
│   │               3. check_fd 호출                         │   │
│   │    - 파일 디스크립터 체크 및 처리                            │   │
│   │    - srv_accept 또는 client_read 호출                   │   │
│   └───────────────────────────────────────────────────────┘   │
└───────────────────────────────────────────────────────────────┘
        │
        ▼
┌───────────────────────────────────────────────────────────────┐
│                        init_fd                                │
│   ┌───────────────────────────────────────────────────────┐   │
│   │        1. 읽기 및 쓰기 파일 디스크립터 세트를                 │   │
│   │           초기화: FD_ZERO 호출                           │   │
│   └───────────────────────────────────────────────────────┘   │
│   ┌───────────────────────────────────────────────────────┐   │
│   │        2. 읽기 및 쓰기 파일 디스크립터를                     │   │
│   │           세트에 추가: FD_SET 호출                        │   │
│   └───────────────────────────────────────────────────────┘   │
└───────────────────────────────────────────────────────────────┘
        │
        ▼
┌───────────────────────────────────────────────────────────────┐
│                       do_select                               │
│   ┌───────────────────────────────────────────────────────┐   │
│   │         1. select 시스템 콜 호출                         │   │
│   │         - 파일 디스크립터 상태 확인                         │   │
│   └───────────────────────────────────────────────────────┘   │
└───────────────────────────────────────────────────────────────┘
        │
        ▼
┌───────────────────────────────────────────────────────────────┐
│                        check_fd                               │
│   ┌───────────────────────────────────────────────────────┐   │
│   │         1. FD_ISSET 호출                               │   │
│   │         - 파일 디스크립터가 설정되었는지 확인                  │   │
│   └───────────────────────────────────────────────────────┘   │
│   ┌───────────────────────────────────────────────────────┐   │
│   │         2. srv_accept 또는 client_read 호출             │   │
│   │         - 클라이언트 연결 수락 또는 데이터 처리                │   │
│   └───────────────────────────────────────────────────────┘   │
└───────────────────────────────────────────────────────────────┘
        │
        ├─────────────────────────────────────────────────────────────┐
        ▼                                                             ▼
┌───────────────────────────────────────────────────────────────┐      ┌───────────────────────────────────────────────────────────────┐
│                       srv_accept                              │      │                       client_read                             │
│   ┌───────────────────────────────────────────────────────┐   │      │   ┌───────────────────────────────────────────────────────┐   │
│   │         1. 클라이언트 연결 수락: accept 호출                │   │      │   │         1. 클라이언트로부터 데이터 수신: recv 호출             │   │
│   └───────────────────────────────────────────────────────┘   │      │   └───────────────────────────────────────────────────────┘   │
│   ┌───────────────────────────────────────────────────────┐   │      │   ┌───────────────────────────────────────────────────────┐   │
│   │         2. 클라이언트 파일 디스크립터 초기화:                 │   │      │   │         2. 연결이 끊긴 경우 처리: close 호출                 │   │
│   │            clean_fd 호출                               │   │      │   └───────────────────────────────────────────────────────┘   │
│   └───────────────────────────────────────────────────────┘   │      │   ┌───────────────────────────────────────────────────────┐   │
│   ┌───────────────────────────────────────────────────────┐   │      │   │         3. 다른 클라이언트에게 데이터 전송: send 호출          │   │
│   │         3. 클라이언트 파일 디스크립터 설정                    │   │      │   └───────────────────────────────────────────────────────┘   │
│   │            - fct_read: client_read 설정                │   │      │                                                               │
│   │            - fct_write: client_write 설정              │   │      │                                                               │
│   └───────────────────────────────────────────────────────┘   │      └───────────────────────────────────────────────────────────────┘
└───────────────────────────────────────────────────────────────┘
        │
        ▼
┌───────────────────────────────────────────────────────────────┐
│                      client_write                             │
│   ┌───────────────────────────────────────────────────────┐   │
│   │         1. 클라이언트로 데이터를 씀 (현재 빈 함수)             │   │
│   └───────────────────────────────────────────────────────┘   │
└───────────────────────────────────────────────────────────────┘