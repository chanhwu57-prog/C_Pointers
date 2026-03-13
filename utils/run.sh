#!/bin/bash

# C与指针 - 练习运行脚本

PROJECT_DIR="$(cd "$(dirname "$0")/.." && pwd)"
BUILD_DIR="$PROJECT_DIR/build"

# 创建 build 目录
mkdir -p "$BUILD_DIR"

# 解析参数
if [ $# -lt 1 ]; then
    echo "用法: ./run.sh <源文件.c> [输入]"
    echo "示例: ./run.sh exercises/chapter_01/exercise_1_2.c"
    echo "     ./run.sh exercises/chapter_01/exercise_1_2.c < test.txt"
    echo "     echo 'hello' | ./run.sh exercises/chapter_01/exercise_1_2.c"
    exit 1
fi

# 获取源文件路径
SRC_FILE="$1"
FULL_SRC="$PROJECT_DIR/$SRC_FILE"

# 检查文件是否存在
if [ ! -f "$FULL_SRC" ]; then
    echo "错误: 文件不存在: $FULL_SRC"
    exit 1
fi

# 从源文件名生成可执行文件名
EXE_NAME=$(basename "$SRC_FILE" .c)
EXE_PATH="$BUILD_DIR/$EXE_NAME"

# 编译
echo "编译: $SRC_FILE ..."
gcc "$FULL_SRC" -o "$EXE_PATH"

if [ $? -ne 0 ]; then
    echo "编译失败!"
    exit 1
fi

echo "编译成功!"

# 运行（如果有额外参数或管道输入）
if [ $# -gt 1 ]; then
    # 有额外参数（输入重定向）
    shift
    "$EXE_PATH" "$@"
elif [ ! -t 0 ]; then
    # 有管道输入
    "$EXE_PATH"
else
    # 交互式运行，按 Ctrl+D 结束
    echo "运行 (按 Ctrl+D 结束输入):"
    "$EXE_PATH"
fi
