### 1. VirtualBox에서 네트워크 설정

1. **VirtualBox 네트워크 어댑터 설정**:
   - VirtualBox를 실행하고 설치한 루분투 가상 머신을 선택합니다.
   - "설정"을 클릭합니다.
   - "네트워크" 탭으로 이동하고 미사용 중인 어댑터를 선택합니다.
   - "어댑터 사용"을 체크하고 "어댑터 유형"을 "브리지 어댑터(Bridged Adapter)"로 설정합니다.
   - "네트워크 이름"에서 호스트 컴퓨터가 연결된 네트워크 인터페이스를 선택합니다. 일반적으로는 이더넷 인터페이스를 선택합니다.
   - 설정을 저장합니다.

### 2. 루분투 SSH 서버 설정

1. **SSH 서버 설치 및 설정**:
   - 루분투 터미널에서 다음 명령을 실행하여 SSH 서버를 설치합니다:
     ```
     sudo apt update
     sudo apt install openssh-server
     ```
   - SSH 서버가 정상적으로 실행 중인지 확인합니다:
     ```
     sudo systemctl status ssh
     ```
   - 만약 서버가 실행 중이지 않다면 다음 명령으로 시작합니다:
     ```
     sudo systemctl start ssh
     ```

2. **루분투 IP 주소 확인**:
   - 루분투에서 SSH 접속을 위해 사용할 IP 주소를 확인합니다.
   - 터미널에서 `ip a` 또는 `ifconfig` 명령어를 사용하여 IP 주소를 확인합니다. 일반적으로 `enp0s3` 또는 `eth0` 인터페이스에서 IP 주소를 찾을 수 있습니다.

### 3. SSH 연결 및 VSC에서 사용

1. **Remote - SSH 확장 설치**:
   - Visual Studio Code(VSC)를 열고 왼쪽 사이드바에서 "Extensions" (Ctrl+Shift+X)를 클릭하여 "Remote - SSH" 확장을 설치합니다.

2. **SSH 구성 파일 생성**:
   - VSC 상단 메뉴에서 `View` -> `Command Palette` (또는 Ctrl+Shift+P)를 열고 `SSH`를 검색하여 "Connect to Host"를 선택합니다.
   - 루분투의 아이피를 입력해서 연결합니다.

### 추가 팁

- **파일 시스템 탐색**: VSC의 왼쪽 사이드바에서 루분투 파일 시스템에 접근하여 파일을 탐색하고 편집할 수 있습니다.
- **터미널 사용**: VSC 내에서 루분투 터미널을 열고 SSH를 통해 원격으로 명령을 실행할 수 있습니다.
- **확장 기능 사용**: 필요에 따라 VSC에 추가적인 확장 기능을 설치하여 개발 환경을 보완할 수 있습니다.

이렇게 하면 VirtualBox에서 브리지 모드로 설정한 네트워크를 통해 루분투를 설치하고, Visual Studio Code를 사용하여 SSH로 원격으로 접속하는 방법을 완료할 수 있습니다.