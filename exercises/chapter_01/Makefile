# 第1章练习 Makefile
# 编译结果保存到 build 目录，不会污染练习文件夹

PROJECT_DIR := /Users/chanh/Documents/C_Learning/C_Pointers
BUILD_DIR := $(PROJECT_DIR)/build/chapter_01
SRC_DIR := /Users/chanh/Documents/C_Learning/C_Pointers/exercises/chapter_01

CC := gcc
CFLAGS := -Wall -Wextra

# ========== 练习1.1: Hello World ==========
.PHONY: exercise_1_1
exercise_1_1: $(BUILD_DIR)/exercise_1_1
	@$(BUILD_DIR)/exercise_1_1

$(BUILD_DIR)/exercise_1_1: $(BUILD_DIR)/exercise_1_1.o
	$(CC) $(CFLAGS) -o $@ $^

# ========== 练习1.2: 带行号的输入复制 ==========
.PHONY: exercise_1_2
exercise_1_2: $(BUILD_DIR)/exercise_1_2
	@$(BUILD_DIR)/exercise_1_2

$(BUILD_DIR)/exercise_1_2: $(BUILD_DIR)/exercise_1_2.o
	$(CC) $(CFLAGS) -o $@ $^

# ========== 练习1.3: Checksum计算 ==========
.PHONY: exercise_1_3
exercise_1_3: $(BUILD_DIR)/exercise_1_3
	@$(BUILD_DIR)/exercise_1_3

$(BUILD_DIR)/exercise_1_3: $(BUILD_DIR)/exercise_1_3.o
	$(CC) $(CFLAGS) -o $@ $^

# ========== 练习1.4: 最长行 ==========
.PHONY: exercise_1_4
exercise_1_4: $(BUILD_DIR)/exercise_1_4
	@$(BUILD_DIR)/exercise_1_4

$(BUILD_DIR)/exercise_1_4: $(BUILD_DIR)/exercise_1_4.o
	$(CC) $(CFLAGS) -o $@ $^

# ========== 练习1.5: rearrange改进 ==========
.PHONY: exercise_1_5
exercise_1_5: $(BUILD_DIR)/exercise_1_5
	@$(BUILD_DIR)/exercise_1_5

$(BUILD_DIR)/exercise_1_5: $(BUILD_DIR)/exercise_1_5.o
	$(CC) $(CFLAGS) -o $@ $^

# ========== 练习1.6: 奇数列范围 ==========
.PHONY: exercise_1_6
exercise_1_6: $(BUILD_DIR)/exercise_1_6
	@$(BUILD_DIR)/exercise_1_6

$(BUILD_DIR)/exercise_1_6: $(BUILD_DIR)/exercise_1_6.o
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
