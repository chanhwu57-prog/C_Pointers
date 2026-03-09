CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g
LDFLAGS =

BUILD_DIR = build

# 编译exercises/chapter_01下的所有.c文件
EXERCISE_DIR = exercises/chapter_01
EXERCISE_SOURCES = $(wildcard $(EXERCISE_DIR)/*.c)
EXERCISE_TARGETS = $(patsubst $(EXERCISE_DIR)/%.c,$(BUILD_DIR)/%,$(EXERCISE_SOURCES))

.PHONY: all clean run hello exercise_1_1 exercise_1_2 exercise_1_3 exercise_1_4

all: $(EXERCISE_TARGETS)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%: $(EXERCISE_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

# 单独运行各个练习
hello: $(BUILD_DIR)/hello
	./$(BUILD_DIR)/hello

exercise_1_1: $(BUILD_DIR)/exercise_1_1
	./$(BUILD_DIR)/exercise_1_1

exercise_1_2: $(BUILD_DIR)/exercise_1_2
	./$(BUILD_DIR)/exercise_1_2

exercise_1_3: $(BUILD_DIR)/exercise_1_3
	./$(BUILD_DIR)/exercise_1_3

exercise_1_4: $(BUILD_DIR)/exercise_1_4
	./$(BUILD_DIR)/exercise_1_4

clean:
	rm -rf $(BUILD_DIR)

run: all
	@echo "可用的练习程序："
	@echo "  make hello        - 运行 hello"
	@echo "  make exercise_1_1 - 运行 exercise_1_1"
	@echo "  make exercise_1_2 - 运行 exercise_1_2"
	@echo "  make exercise_1_3 - 运行 exercise_1_3"
	@echo "  make exercise_1_4 - 运行 exercise_1_4"
