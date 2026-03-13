PROJECT_DIR := /Users/chanh/Documents/C_Learning/C_Pointers
BUILD_DIR := $(PROJECT_DIR)/build/chapter_04
SRC_DIR := $(PROJECT_DIR)/exercises/chapter_04

CC := gcc
CFLAGS := -Wall -Wextra

.PHONY: all clean exercise_4_1 exercise_4_2 exercise_4_3 exercise_4_4 exercise_4_5 exercise_4_6 exercise_4_7

all: exercise_4_1 exercise_4_2 exercise_4_3 exercise_4_4 exercise_4_5 exercise_4_6 exercise_4_7

exercise_4_1: $(BUILD_DIR)/exercise_4_1
	@$(BUILD_DIR)/exercise_4_1

$(BUILD_DIR)/exercise_4_1: $(BUILD_DIR)/exercise_4_1.o
	$(CC) $(CFLAGS) -o $@ $^ -lm

exercise_4_2: $(BUILD_DIR)/exercise_4_2
	@$(BUILD_DIR)/exercise_4_2

$(BUILD_DIR)/exercise_4_2: $(BUILD_DIR)/exercise_4_2.o
	$(CC) $(CFLAGS) -o $@ $^

exercise_4_3: $(BUILD_DIR)/exercise_4_3
	@$(BUILD_DIR)/exercise_4_3

$(BUILD_DIR)/exercise_4_3: $(BUILD_DIR)/exercise_4_3.o
	$(CC) $(CFLAGS) -o $@ $^

exercise_4_4: $(BUILD_DIR)/exercise_4_4
	@$(BUILD_DIR)/exercise_4_4

$(BUILD_DIR)/exercise_4_4: $(BUILD_DIR)/exercise_4_4.o
	$(CC) $(CFLAGS) -o $@ $^

exercise_4_5: $(BUILD_DIR)/exercise_4_5
	@$(BUILD_DIR)/exercise_4_5

$(BUILD_DIR)/exercise_4_5: $(BUILD_DIR)/exercise_4_5.o
	$(CC) $(CFLAGS) -o $@ $^

exercise_4_6: $(BUILD_DIR)/exercise_4_6
	@$(BUILD_DIR)/exercise_4_6

$(BUILD_DIR)/exercise_4_6: $(BUILD_DIR)/exercise_4_6.o
	$(CC) $(CFLAGS) -o $@ $^

exercise_4_7: $(BUILD_DIR)/exercise_4_7
	@$(BUILD_DIR)/exercise_4_7

$(BUILD_DIR)/exercise_4_7: $(BUILD_DIR)/exercise_4_7.o
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
