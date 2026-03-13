PROJECT_DIR := /Users/chanh/Documents/C_Learning/C_Pointers
BUILD_DIR := $(PROJECT_DIR)/build/chapter_05
SRC_DIR := $(PROJECT_DIR)/exercises/chapter_05

CC := gcc
CFLAGS := -Wall -Wextra

.PHONY: all clean exercise_5_1 exercise_5_2 exercise_5_3 exercise_5_4 exercise_5_5

all: exercise_5_1 exercise_5_2 exercise_5_3 exercise_5_4 exercise_5_5

exercise_5_1: $(BUILD_DIR)/exercise_5_1
	@$(BUILD_DIR)/exercise_5_1

$(BUILD_DIR)/exercise_5_1: $(BUILD_DIR)/exercise_5_1.o
	$(CC) $(CFLAGS) -o $@ $^

exercise_5_2: $(BUILD_DIR)/exercise_5_2
	@$(BUILD_DIR)/exercise_5_2

$(BUILD_DIR)/exercise_5_2: $(BUILD_DIR)/exercise_5_2.o
	$(CC) $(CFLAGS) -o $@ $^

exercise_5_3: $(BUILD_DIR)/exercise_5_3
	@$(BUILD_DIR)/exercise_5_3

$(BUILD_DIR)/exercise_5_3: $(BUILD_DIR)/exercise_5_3.o
	$(CC) $(CFLAGS) -o $@ $^

exercise_5_4: $(BUILD_DIR)/exercise_5_4
	@$(BUILD_DIR)/exercise_5_4

$(BUILD_DIR)/exercise_5_4: $(BUILD_DIR)/exercise_5_4.o
	$(CC) $(CFLAGS) -o $@ $^

exercise_5_5: $(BUILD_DIR)/exercise_5_5
	@$(BUILD_DIR)/exercise_5_5

$(BUILD_DIR)/exercise_5_5: $(BUILD_DIR)/exercise_5_5.o
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
