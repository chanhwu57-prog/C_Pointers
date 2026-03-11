# 第2章：基本概念

## 学习目标

- 理解C语言的翻译环境和执行环境
- 掌握词法规则（字符、注释、标识符等）
- 了解程序的形式和风格

---

## 2.1 环境

### 2.1.1 翻译环境

C翻译程序的过程分为4个阶段：

```
源代码 → 预处理 → 编译 → 汇编 → 链接 → 可执行文件
```

#### 编译步骤

1. **预处理**：处理 `#include`、`#define` 等指令
2. **编译**：将C代码翻译成汇编代码
3. **汇编**：将汇编代码翻译成机器码（.o文件）
4. **链接**：将多个.o文件合并成可执行文件

#### 文件名约定

| 文件后缀 | 含义 |
|----------|------|
| `.c` | C源代码文件 |
| `.h` | 头文件 |
| `.o` | 目标文件（机器码） |
| `.a` | 静态库 |
| `.so` / `.dylib` | 动态库 |

#### 多文件编译示例

```bash
# 编译多个源文件
gcc main.c func1.c func2.c -o program

# 编译为目标文件（分开编译）
gcc -c main.c      # → main.o
gcc -c func1.c     # → func1.o
gcc -c func2.c     # → func2.o

# 链接目标文件
gcc main.o func1.o func2.o -o program
```

### 2.1.2 执行环境

程序执行过程：

1. **加载**：操作系统将可执行文件加载到内存
2. **执行**：从 `main` 函数开始执行
3. **终止**：返回操作系统

---

## 2.2 词法规则

### 2.2.1 字符

C语言使用的字符集：
- **字母**：A-Z, a-z
- **数字**：0-9
- **空白符**：空格、制表符、换行符
- **标点符号**：() {} [] , ; : . = + - * / % < > & | ! ~ ^ ? " ' \ #
- **下划线**：_

#### 转义字符

| 字符 | 含义 |
|------|------|
| `\n` | 换行 |
| `\t` | 制表符 |
| `\r` | 回车 |
| `\\` | 反斜杠 |
| `\"` | 双引号 |
| `\'` | 单引号 |
| `\a` | 警告音 |
| `\b` | 退格 |

### 2.2.2 注释

C语言注释有两种形式：

```c
/* 这是多行注释 
   可以跨多行 */

// 这是C99/C++风格的单行注释
```

**注意**：
- C语言没有 `//` 注释风格（C99才引入）
- 注释不嵌套

### 2.2.3 自由形式的源代码

C是**自由形式**语言：
- 语句以分号 `;` 结束
- 空格和换行可以随意放置
- 一个语句可以跨多行

```c
int 
main
(
void
)
{
    return 0;
}
```

### 2.2.4 标识符

**标识符**：变量名、函数名、宏名等

规则：
1. 由字母、数字、下划线组成
2. 第一个字符不能是数字
3. 区分大小写
4. 不能使用关键字

```c
int age;          // 合法
int _private;     // 合法（但不推荐）
int 2fast;        // 非法：数字开头
int int;          // 非法：关键字
```

**关键字**（32个）：

```
auto       break      case       char       const
continue   default    do         double     else
enum       float      for        goto       if
int        long       register   return     short
signed     sizeof     static     struct     switch
typedef    union      unsigned   void       volatile
while
```

### 2.2.5 程序的形式

C程序由**函数**组成，必须有一个 `main` 函数作为入口：

```c
#include <stdio.h>

int main(void) {
    printf("Hello!\n");
    return 0;
}
```

---

## 2.3 程序风格

### 代码规范建议

1. **缩进**：使用4个空格或Tab缩进
2. **命名**：
   - 变量用小写：`int count;`
   - 常量用大写：`#define MAX 100`
   - 函数用动词开头：`int get_value();`
3. **注释**：
   - 解释"为什么"，而不是"是什么"
   - 保持注释更新
4. **空行**：逻辑段落之间使用空行分隔

---

## 练习要点

- [x] 练习 2.1：多文件函数调用 - increment, negate, main
- [x] 练习 2.2：花括号匹配检测

---

## 练习答案

### 练习 2.1：多文件函数

**题目**：编写一个程序，由3个函数组成，分别位于不同文件。increment返回参数+1，negate返回参数的负值，main函数分别用参数10, 0, 10调用并打印结果。

**increment.c**：
```c
int increment(int value) {
    return value + 1;
}
```

**negate.c**：
```c
int negate(int value) {
    return -value;
}
```

**main.c**：
```c
#include <stdio.h>

int increment(int value);
int negate(int value);

int main(void) {
    printf("increment(10) = %d, negate(10) = %d\n", increment(10), negate(10));
    printf("increment(0) = %d, negate(0) = %d\n", increment(0), negate(0));
    printf("increment(10) = %d, negate(10) = %d\n", increment(10), negate(10));
    return 0;
}
```

**编译运行**：
```bash
gcc main.c increment.c negate.c -o main
./main
```

**解析**：
- 函数原型必须在调用前声明
- 多文件编译：直接列出所有源文件

---

### 练习 2.2：花括号匹配检测

**题目**：从标准输入读取C源代码，验证所有花括号是否成对出现。

**参考解答**：
```c
#include <stdio.h>

int main(void) {
    int ch;
    int brace_count = 0;
    int line = 1;
    int error = 0;

    while ((ch = getchar()) != EOF) {
        if (ch == '\n') {
            line++;
        }
        
        if (ch == '{') {
            brace_count++;
        } else if (ch == '}') {
            brace_count--;
            if (brace_count < 0) {
                error = 1;
                printf("Error: 缺少 '{' at line %d\n", line);
                break;
            }
        }
    }

    if (brace_count > 0) {
        printf("Error: 缺少 '}' at end of file\n");
        error = 1;
    }

    if (!error && brace_count == 0) {
        printf("花括号匹配正确！\n");
    }

    return error;
}
```

**解析**：
- 计数器法：遇到 `{` +1，遇到 `}` -1
- 计数器为负 = 多了 `}`
- 循环结束计数器为正 = 多了 `{`

---

## 常见错误

1. **注释嵌套**
   ```c
   /* 外层 /* 内层 */ 注释 */
   ```
   错误：C语言注释不嵌套

2. **标识符以数字开头**
   ```c
   int 123abc;  // 错误
   ```

3. **忘记分号**
   ```c
   int a = 10  // 错误：缺少分号
   ```

4. **忘记函数原型声明**
   ```c
   int main(void) {
       foo();  // 错误：foo 未声明
   }
   void foo() { }
   ```

---

## 心得体会

第二章学习了C语言的基本概念：
1. 理解了程序的翻译过程（预处理→编译→汇编→链接）
2. 掌握了词法规则（字符、注释、标识符）
3. 了解了关键字和标识符的区别
4. 学会了多文件编译方法
