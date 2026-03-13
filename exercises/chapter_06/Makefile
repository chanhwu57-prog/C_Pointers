PROJECT_DIR := /Users/chanh/Documents/C_Learning/C_Pointers
BUILD_DIR := $(PROJECT_DIR)/build/chapter_06
SRC_DIR := $(PROJECT_DIR)/exercises/chapter_06

CC := gcc
CFLAGS := -Wall -Wextra

.PHONY: all clean exercise_6_1 exercise_6_2 exercise_6_3 exercise_6_4 exercise_6_5 exercise_6_6

all: exercise_6_1 exercise_6_2 exercise_6_3 exercise_6_4 exercise_6_5 exercise_6_6

exercise_6_1: $(BUILD_DIR)/exercise_6_1
	@$(BUILD_DIR)/exercise_6_1

$(BUILD_DIR)/exercise_6_1: $(BUILD_DIR)/exercise_6_1.o
	$(CC) $(CFLAGS) -o $@ $^

exercise_6_2: $(BUILD_DIR)/exercise_6_2
	@$(BUILD_DIR)/exercise_6_2

$(BUILD_DIR)/exercise_6_2: $(BUILD_DIR)/exercise_6_2.o
	$(CC) $(CFLAGS) -o $@ $^

exercise_6_3: $(BUILD_DIR)/exercise_6_3
	@$(BUILD_DIR)/exercise_6_3

$(BUILD_DIR)/exercise_6_3: $(BUILD_DIR)/exercise_6_3.o
	$(CC) $(CFLAGS) -o $@ $^

exercise_6_4: $(BUILD_DIR)/exercise_6_4
	@$(BUILD_DIR)/exercise_6_4

$(BUILD_DIR)/exercise_6_4: $(BUILD_DIR)/exercise_6_4.o
	$(CC) $(CFLAGS) -o $@ $^

exercise_6_5: $(BUILD_DIR)/exercise_6_5
	@$(BUILD_DIR)/exercise_6_5

$(BUILD_DIR)/exercise_6_5: $(BUILD_DIR)/exercise_6_5.o
	$(CC) $(CFLAGS) -o $@ $^

exercise_6_6: $(BUILD_DIR)/exercise_6_6
	@$(BUILD_DIR)/exercise_6_6

$(BUILD_DIR)/exercise_6_6: $(BUILD_DIR)/exercise_6_6.o
	$(CC) $(CFLAGS) -o $@ $^ -lm

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
