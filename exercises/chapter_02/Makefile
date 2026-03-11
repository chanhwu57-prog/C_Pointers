# 第2章练习 Makefile
# 编译结果保存到 build 目录，不会污染练习文件夹

PROJECT_DIR := /Users/chanh/Documents/C_Learning/C_Pointers
BUILD_DIR := $(PROJECT_DIR)/build/chapter_02
SRC_DIR := /Users/chanh/Documents/C_Learning/C_Pointers/exercises/chapter_02

CC := gcc
CFLAGS := -Wall -Wextra

# ========== 编译练习2.1 ==========
.PHONY: main
main: $(BUILD_DIR)/main
	@$(BUILD_DIR)/main

$(BUILD_DIR)/main: $(BUILD_DIR)/main.o $(BUILD_DIR)/increment.o $(BUILD_DIR)/negate.o
	$(CC) $(CFLAGS) -o $@ $^

# ========== 编译练习2.2 ==========
.PHONY: exercise_2_2
exercise_2_2: $(BUILD_DIR)/exercise_2_2
	@echo "运行 exercise_2_2 (测试花括号匹配)..."
	@echo -e "int main() {\n  return 0;\n}" | $(BUILD_DIR)/exercise_2_2

$(BUILD_DIR)/exercise_2_2: $(BUILD_DIR)/exercise_2_2.o
	$(CC) $(CFLAGS) -o $@ $^

# ========== 编译规则 ==========
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# ========== 清理 ==========
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
