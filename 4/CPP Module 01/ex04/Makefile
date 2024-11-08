# 글자 ANSI 정의
BOLD        =   \033[1m
GREEN       =   \033[0;32m
INIT_ANSI   =   \033[0m     # 초기화

# 실행 파일 이름
EXECUTABLE = executable

# 소스 파일 및 오브젝트 파일 찾기 및 정의
SRC_DIR = .
INCLUDE_DIR = .
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/objs
DEP_DIR = $(BUILD_DIR)/deps
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPENDS = $(OBJECTS:$(OBJ_DIR)/%.o=$(DEP_DIR)/%.d)

# 컴파일러 설정
CXX = c++
CXXFLAGS = -g -Wall -Wextra -Werror -std=c++98 -I$(INCLUDE_DIR)

# 기본 타겟 설정
.PHONY: all clean re test

# 'make all' 또는 'make' 규칙
all: $(EXECUTABLE)
	@echo "\n$(GREEN)$(BOLD)Build complete.$(INIT_ANSI)"

# 실행 파일 빌드 규칙
$(EXECUTABLE): $(OBJECTS)
	@echo "\n$(GREEN)Linking...$(INIT_ANSI)"
	$(CXX) $(CXXFLAGS) -o $@ $^

# 오브젝트 파일 및 의존성 파일 빌드 규칙
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "\n$(GREEN)Compiling $< and generating dependencies...$(INIT_ANSI)"
	@mkdir -p $(OBJ_DIR) $(DEP_DIR)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@ -MF $(DEP_DIR)/$*.d

# 테스트 파일 이름 변수 정의
NORMAL_FILE=_normal
NON_EXISTING_FILE=_non_existing
NO_PERMISSION_FILE=_no_permission
EMPTY_FILE=_empty
SPACE_FILE=_space
LARGE_FILE=_large
SPECIAL_FILE=_special

# 테스트 실행
test: all
	@echo "\n$(GREEN)일반적인 텍스트 파일 생성 및 테스트 실행$(INIT_ANSI)"
	@echo "This is a test file." > $(NORMAL_FILE)
	./$(EXECUTABLE) $(NORMAL_FILE) "test" "TEST"

	@echo "\n$(GREEN)존재하지 않는 파일에 대한 테스트$(INIT_ANSI)"
	@rm -f $(NON_EXISTING_FILE)
	./$(EXECUTABLE) $(NON_EXISTING_FILE) "test" "TEST" || true

	@echo "\n$(GREEN)접근할 수 없는 파일에 대한 테스트$(INIT_ANSI)"
	@touch $(NO_PERMISSION_FILE)
	@chmod 000 $(NO_PERMISSION_FILE)
	./$(EXECUTABLE) $(NO_PERMISSION_FILE) "test" "TEST" || true
	@chmod 644 $(NO_PERMISSION_FILE)

	@echo "\n$(GREEN)비어 있는 파일에 대한 테스트$(INIT_ANSI)"
	@touch $(EMPTY_FILE)
	./$(EXECUTABLE) $(EMPTY_FILE) "test" "TEST"

	@echo "\n$(GREEN)공백만 있는 파일에 대한 테스트$(INIT_ANSI)"
	@echo "          " > $(SPACE_FILE)
	./$(EXECUTABLE) $(SPACE_FILE) " " "_"

	@echo "\n$(GREEN)대용량 파일에 대한 테스트$(INIT_ANSI)"
	@rm -f $(LARGE_FILE)
	@for i in {1..10000}; do \
    echo "This is a long string to simulate a large file content $$i." >> $(LARGE_FILE); \
	done
	./$(EXECUTABLE) $(LARGE_FILE) "long" "short"

	@echo "\n$(GREEN)특수 문자가 포함된 파일에 대한 테스트$(INIT_ANSI)"
	@echo "Special characters: !@#$%^&*()" > $(SPECIAL_FILE)
	./$(EXECUTABLE) $(SPECIAL_FILE) "&" "and"

# 'make clean' 규칙
clean:
	@echo "\n$(GREEN)Cleaning...$(INIT_ANSI)"
	rm -rf $(BUILD_DIR) $(EXECUTABLE)
	rm -rf $(NORMAL_FILE) $(NON_EXISTING_FILE) $(NO_PERMISSION_FILE) $(EMPTY_FILE) $(SPACE_FILE) $(LARGE_FILE) $(SPECIAL_FILE) $(NORMAL_FILE).replace $(NON_EXISTING_FILE).replace $(NO_PERMISSION_FILE).replace $(EMPTY_FILE).replace $(SPACE_FILE).replace $(LARGE_FILE).replace $(SPECIAL_FILE).replace
	@echo "\n$(GREEN)$(BOLD)Cleaned.$(INIT_ANSI)"

# 'make re' 규칙
re:
	$(MAKE) clean
	$(MAKE) all

# 의존성 파일 포함
-include $(DEPENDS)
