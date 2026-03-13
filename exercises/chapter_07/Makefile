PROJECT_DIR := /Users/chanh/Documents/C_Learning/C_Pointers
BUILD_DIR := $(PROJECT_DIR)/build/chapter_07
SRC_DIR := $(PROJECT_DIR)/exercises/chapter_07

CC := gcc
CFLAGS := -Wall -Wextra

.PHONY: all clean exercise_7_1 exercise_7_2 exercise_7_3 exercise_7_4 exercise_7_5 exercise_7_6

all: exercise_7_1 exercise_7_2 exercise_7_3 exercise_7_4 exercise_7_5 exercise_7_6

exercise_7_1: $(BUILD_DIR)/exercise_7_1
	@$(BUILD_DIR)/exercise_7_1

$(BUILD_DIR)/exercise_7_1: $(BUILD_DIR)/exercise_7_1.o
	$(CC) $(CFLAGS) -o $@ $^

exercise_7_2: $(BUILD_DIR)/exercise_7_2
	@$(BUILD_DIR)/exercise_7_2

$(BUILD_DIR)/exercise_7_2: $(BUILD_DIR)/exercise_7_2.o
	$(CC) $(CFLAGS) -o $@ $^

exercise_7_3: $(BUILD_DIR)/exercise_7_3
	@$(BUILD_DIR)/exercise_7_3

$(BUILD_DIR)/exercise_7_3: $(BUILD_DIR)/exercise_7_3.o
	$(CC) $(CFLAGS) -o $@ $^

exercise_7_4: $(BUILD_DIR)/exercise_7_4
	@$(BUILD_DIR)/exercise_7_4

$(BUILD_DIR)/exercise_7_4: $(BUILD_DIR)/exercise_7_4.o
	$(CC) $(CFLAGS) -o $@ $^

exercise_7_5: $(BUILD_DIR)/exercise_7_5
	@$(BUILD_DIR)/exercise_7_5

$(BUILD_DIR)/exercise_7_5: $(BUILD_DIR)/exercise_7_5.o
	$(CC) $(CFLAGS) -o $@ $^

exercise_7_6: $(BUILD_DIR)/exercise_7_6
	@$(BUILD_DIR)/exercise_7_6

$(BUILD_DIR)/exercise_7_6: $(BUILD_DIR)/exercise_7_6.o
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
