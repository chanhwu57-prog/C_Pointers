# 多文件编译 Makefile
# 用法: make          编译
#       make clean   清理

# 获取当前目录名作为目标名
TARGET := $(shell basename $$(pwd))

# 查找所有 .c 文件，排除 main.c
SRCS := $(filter-out main.c, $(wildcard *.c))

# 对应的 .o 文件
OBJS := $(SRCS:.c=.o)

# C 编译器
CC := gcc
CFLAGS := -Wall -Wextra

# 默认目标
all: $(TARGET)

# 链接
$(TARGET): main.o $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# 编译 .o 文件
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# 清理
clean:
	rm -f $(TARGET) *.o

.PHONY: all clean
