# 第3章练习 Makefile
# 编译结果保存到 build 目录，不会污染练习文件夹

PROJECT_DIR := /Users/chanh/Documents/C_Learning/C_Pointers
BUILD_DIR := $(PROJECT_DIR)/build/chapter_03
SRC_DIR := $(PROJECT_DIR)/exercises/chapter_03

CC := gcc
CFLAGS := -Wall -Wextra

# ========== 编译规则 ==========
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# ========== 清理 ==========
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
