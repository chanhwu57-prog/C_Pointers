PROJECT_DIR := /Users/chanh/Documents/C_Learning/C_Pointers
BUILD_DIR := $(PROJECT_DIR)/build/chapter_08
SRC_DIR := $(PROJECT_DIR)/exercises/chapter_08

CC := gcc
CFLAGS := -Wall -Wextra

.PHONY: all clean exercise_8_1 exercise_8_2 exercise_8_3 exercise_8_4 exercise_8_5 exercise_8_6 exercise_8_7 exercise_8_8

all: exercise_8_1 exercise_8_2 exercise_8_3 exercise_8_4 exercise_8_5 exercise_8_6 exercise_8_7 exercise_8_8

exercise_8_1: $(BUILD_DIR)/exercise_8_1
	@$(BUILD_DIR)/exercise_8_1

$(BUILD_DIR)/exercise_8_1: $(BUILD_DIR)/exercise_8_1.o
	$(CC) $(CFLAGS) -o $@ $^

exercise_8_2: $(BUILD_DIR)/exercise_8_2
	@$(BUILD_DIR)/exercise_8_2

$(BUILD_DIR)/exercise_8_2: $(BUILD_DIR)/exercise_8_2.o
	$(CC) $(CFLAGS) -o $@ $^

exercise_8_3: $(BUILD_DIR)/exercise_8_3
	@$(BUILD_DIR)/exercise_8_3

$(BUILD_DIR)/exercise_8_3: $(BUILD_DIR)/exercise_8_3.o
	$(CC) $(CFLAGS) -o $@ $^

exercise_8_4: $(BUILD_DIR)/exercise_8_4
	@$(BUILD_DIR)/exercise_8_4

$(BUILD_DIR)/exercise_8_4: $(BUILD_DIR)/exercise_8_4.o
	$(CC) $(CFLAGS) -o $@ $^

exercise_8_5: $(BUILD_DIR)/exercise_8_5
	@$(BUILD_DIR)/exercise_8_5

$(BUILD_DIR)/exercise_8_5: $(BUILD_DIR)/exercise_8_5.o
	$(CC) $(CFLAGS) -o $@ $^

exercise_8_6: $(BUILD_DIR)/exercise_8_6
	@$(BUILD_DIR)/exercise_8_6

$(BUILD_DIR)/exercise_8_6: $(BUILD_DIR)/exercise_8_6.o
	$(CC) $(CFLAGS) -o $@ $^

exercise_8_7: $(BUILD_DIR)/exercise_8_7
	@$(BUILD_DIR)/exercise_8_7

$(BUILD_DIR)/exercise_8_7: $(BUILD_DIR)/exercise_8_7.o
	$(CC) $(CFLAGS) -o $@ $^

exercise_8_8: $(BUILD_DIR)/exercise_8_8
	@$(BUILD_DIR)/exercise_8_8

$(BUILD_DIR)/exercise_8_8: $(BUILD_DIR)/exercise_8_8.o
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
