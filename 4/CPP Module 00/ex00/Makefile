# 글자 ANSI 정의
BOLD        =   \033[1m
GREEN       =   \033[0;32m
INIT_ANSI   =   \033[0m     # 초기화

# 실행 파일 이름
EXECUTABLE = megaphone

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
.PHONY: all clean re

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

# 'make clean' 규칙
clean:
	@echo "\n$(GREEN)Cleaning...$(INIT_ANSI)"
	rm -rf $(BUILD_DIR) $(EXECUTABLE)
	@echo "\n$(GREEN)$(BOLD)Cleaned.$(INIT_ANSI)"

# 'make re' 규칙
re:
	$(MAKE) clean
	$(MAKE) all

# 의존성 파일 포함
-include $(DEPENDS)
