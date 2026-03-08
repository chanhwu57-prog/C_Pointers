# 第1章：快速上手C语言

## 学习目标

- 了解C语言的基本特点
- 掌握第一个C程序的编写和运行
- 理解编译、链接的基本过程

## 核心概念

### 1. C语言简介
- C语言的历史和特点
- C语言的应用领域
- C语言与其他编程语言的关系

### 2. 第一个C程序

```c
#include <stdio.h>

int main(void) {
    printf("Hello, World!\n");
    return 0;
}
```

### 3. 程序结构
- 预处理指令 (#include)
- main函数
- 语句和表达式
- 注释

### 4. 编译和运行
- 编译过程：预处理 → 编译 → 汇编 → 链接
- 常用编译器：GCC, Clang, MSVC
- 编译命令：`gcc -o program program.c`

## 重要知识点

### 预处理指令
- `#include <stdio.h>` - 包含标准输入输出库
- `#define` - 定义宏

### main函数
- 程序的入口点
- 返回类型 int
- 返回值 0 表示成功

### 基本语法
- 每条语句以分号结尾
- 代码块用花括号包围
- 区分大小写

## 常见问题

1. **编译错误**：语法错误、缺少分号等
2. **链接错误**：找不到库函数
3. **运行错误**：逻辑错误、内存问题

## 练习要点

- [ ] 编写并运行第一个C程序
- [ ] 尝试不同的printf输出格式
- [ ] 理解编译错误信息
- [ ] 使用调试器单步执行

## 扩展阅读

- C语言标准（C89/C90, C99, C11, C17）
- 编译器优化选项
- 代码风格指南

## 实践练习

### 练习1.1：输出个人信息
- 学习使用 `printf` 输出多行文本
- 文件：[exercise_1_1.c](../exercises/chapter_01/exercise_1_1.c)

### 练习1.2：转义字符
- `\n` - 换行
- `\t` - 制表符
- `\\` - 反斜杠
- `\"` - 双引号
- `\'` - 单引号
- 文件：[exercise_1_2.c](../exercises/chapter_01/exercise_1_2.c)

### 练习1.3：格式化输出
- `%d` - 整数
- `%f` - 浮点数
- `%c` - 字符
- `%s` - 字符串
- 宽度控制：`%5d`, `%-10d`
- 精度控制：`%.2f`
- 文件：[exercise_1_3.c](../exercises/chapter_01/exercise_1_3.c)

### 练习1.4：基本运算
- 加减乘除：`+`, `-`, `*`, `/`
- 取模运算：`%`
- 注意：整数除法会截断小数部分
- 文件：[exercise_1_4.c](../exercises/chapter_01/exercise_1_4.c)

## 编译命令速查

```bash
# 基本编译
gcc -o program program.c

# 启用警告
gcc -Wall -Wextra -o program program.c

# 指定标准
gcc -std=c11 -o program program.c

# 包含调试信息
gcc -g -o program program.c

# 完整推荐命令
gcc -Wall -Wextra -std=c11 -g -o program program.c
```

## 常见错误及解决

1. **缺少分号**
   ```c
   printf("Hello")  // 错误：缺少分号
   printf("Hello"); // 正确
   ```

2. **main函数声明错误**
   ```c
   void main() {}      // 不推荐
   int main() {}       // 可以
   int main(void) {}   // 推荐
   ```

3. **格式说明符错误**
   ```c
   printf("%d", 3.14);  // 错误：类型不匹配
   printf("%f", 3.14);  // 正确
   ```

## 心得体会

通过第1章的学习，掌握了C语言程序的基本结构：
1. 理解了预处理指令的作用
2. 掌握了main函数的标准写法
3. 学会了使用printf进行格式化输出
4. 了解了常用的转义字符
5. 完成了基本的算术运算练习

下一步：学习第2章的基本数据类型
