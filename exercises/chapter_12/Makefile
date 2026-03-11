# 模板 Makefile
# 请根据实际练习文件修改

PROJECT_DIR := /Users/chanh/Documents/C_Learning/C_Pointers
BUILD_DIR := $(PROJECT_DIR)/build/chapter_XX
SRC_DIR := $(PROJECT_DIR)/exercises/chapter_XX

CC := gcc
CFLAGS := -Wall -Wextra

# ========== 添加你的练习 ==========
# 格式:
# .PHONY: exercise_X_Y
# exercise_X_Y: $(BUILD_DIR)/exercise_X_Y
# 	@$(BUILD_DIR)/exercise_X_Y
#
# $(BUILD_DIR)/exercise_X_Y: $(BUILD_DIR)/exercise_X_Y.o
# 	$(CC) $(CFLAGS) -o $@ $^

# ========== 编译规则 ==========
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# ========== 清理 ==========
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
