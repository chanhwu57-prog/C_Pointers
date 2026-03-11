# 第3章：数据

## 学习目标

- 掌握C语言基本数据类型（整型、浮点型、指针）
- 理解数据存储和内存表示
- 学会正确声明和初始化变量

---

## 3.1 基本数据类型

C语言只有4种基本数据类型：

| 类型 | 说明 |
|------|------|
| 整型 | 整数（char, short, int, long） |
| 浮点型 | 小数（float, double） |
| 指针 | 内存地址 |
| 聚合类型 | 数组、结构等 |

### 3.1.1 整型家族

**整型分类**：

```
整型家族
├── 字符型 (char)
├── 短整型 (short)
├── 整型 (int)
└── 长整型 (long)
```

**有符号 vs 无符号**：

| 关键字 | 说明 |
|--------|------|
| signed | 有符号（默认） |
| unsigned | 无符号 |

**整型大小**（常见平台）：

| 类型 | 大小 | 取值范围 |
|------|------|----------|
| char | 1字节 | -128 ~ 127 或 0 ~ 255 |
| short | 2字节 | -32768 ~ 32767 |
| int | 4字节 | -21亿 ~ 21亿 |
| long | 8字节(64位) | 极大 |
| unsigned char | 1字节 | 0 ~ 255 |
| unsigned int | 4字节 | 0 ~ 42亿 |

**查看整型范围**：

```c
#include <stdio.h>
#include <limits.h>

int main() {
    printf("int max: %d\n", INT_MAX);
    printf("int min: %d\n", INT_MIN);
    printf("unsigned int max: %u\n", UINT_MAX);
    return 0;
}
```

### 3.1.2 浮点型

| 类型 | 大小 | 精度 |
|------|------|------|
| float | 4字节 | 6-7位 |
| double | 8字节 | 15-16位 |
| long double | 16字节 | 18-19位 |

**示例**：

```c
float f = 3.14f;      // 注意后缀f
double d = 3.14;
```

### 3.1.3 指针

**指针是一种特殊的数据类型，存储变量的内存地址**。

```c
int a = 10;
int *p = &a;    // p 存储 a 的地址

printf("%p", p);   // 打印地址
printf("%d", *p);  // 解引用，获取值 10
```

**指针的四个要点**：

1. **指针变量**：存储地址的变量
2. **解引用**：通过 `*` 访问指针指向的内容
3. **取地址**：通过 `&` 获取变量的地址
4. **指针类型**：指针类型决定了如何解释内存中的数据

**指针与字符串**：

```c
char *str = "hello";  // 字符串常量
```

---

## 3.2 基本声明

### 声明语法

```c
type variable_name;
type variable_name = value;
type array_name[size];
type *pointer_name;
```

### 初始化

```c
int a = 0;           // 初始化为0
int b;               // 未初始化（值不确定）
int arr[5] = {1,2,3,4,5};  // 数组初始化
int arr2[5] = {0};   // 全部初始化为0
```

---

## 3.3 typedef

**typedef** 为现有类型创建别名：

```c
typedef int Integer;
typedef unsigned int UInteger;

Integer a = 10;   // 等价于 int a = 10;
```

**常用场景**：

```c
typedef unsigned long ulong;
typedef int *IntPtr;
typedef char *String;
```

---

## 3.4 常量

### #define 宏

```c
#define MAX 100
#define PI 3.14159
```

### const 常量

```c
const int MAX = 100;
int const MAX = 100;   // 两种写法等价
```

**#define vs const**：

| 特性 | #define | const |
|------|---------|-------|
| 类型检查 | 无 | 有 |
| 内存 | 无（预处理替换） | 有 |
| 调试 | 困难 | 容易 |

### enum 枚举

```c
enum Color { RED, GREEN, BLUE };
enum Color c = RED;  // c = 0
```

---

## 3.5 作用域

### 代码块作用域

在 `{}` 内声明的变量，只在该代码块内有效：

```c
int main() {
    int x = 10;
    if (x > 5) {
        int y = 20;
        printf("%d", y);  // 正确
    }
    printf("%d", y);  // 错误：y未定义
}
```

### 文件作用域

在函数外部声明的变量，全局可见：

```c
int global_var;  // 文件作用域

void func() {
    global_var = 10;  // 可以访问
}
```

### 原型作用域

函数原型中的参数名：

```c
void func(int x, int y);  // x, y 只在原型中有效
```

---

## 3.6 链接属性

| 属性 | 说明 |
|------|------|
| external | 可在其他文件访问（extern） |
| internal | 仅当前文件可见（static） |
| none | 独立个体，每次声明都是新变量 |

---

## 3.7 存储类型

### auto（自动存储）

```c
auto int x;  // 默认，大部分情况省略
```

### static（静态存储）

- 生命周期：程序开始到结束
- 作用域：代码块内

```c
void counter() {
    static int count = 0;  // 只初始化一次
    count++;
    printf("%d\n", count);
}
```

### register（寄存器存储）

```c
register int i;  // 建议存储在寄存器中
```

### extern（外部引用）

```c
// file1.c
int global = 100;

// file2.c
extern int global;  // 引用file1.c中的global
```

---

## 3.8 总结

1. **基本数据类型**：整型、浮点型、指针、聚合类型
2. **整型家族**：char, short, int, long + signed/unsigned
3. **指针**：存储地址，通过 * 解引用
4. **typedef**：创建类型别名
5. **常量**：#define, const, enum
6. **作用域**：代码块、文件、原型、函数
7. **存储类型**：auto, static, register, extern

---

## 课后问题

### 问题 3.1

**问**：在你的机器上，字符型和整型的范围是多少？

**答**：

```c
#include <stdio.h>
#include <limits.h>

int main() {
    printf("char: %d ~ %d\n", CHAR_MIN, CHAR_MAX);
    printf("int: %d ~ %d\n", INT_MIN, INT_MAX);
    printf("short: %d ~ %d\n", SHRT_MIN, SHRT_MAX);
    printf("long: %ld ~ %ld\n", LONG_MIN, LONG_MAX);
    return 0;
}
```

常见64位 Mac/Linux：
- char: -128 ~ 127
- int: -2147483648 ~ 2147483647
- long: -9223372036854775808 ~ 9223372036854775807

---

### 问题 3.2

**问**：假定你要写一个程序要在两台机器上都能运行，它们的默认整型大小不同，分别是16位和32位，长整型大小分别是32位和64位。你如何声明这些变量使他们在两种机器上都能运行？

**答**：使用 typedef 定义固定宽度类型，或创建条件编译：

```c
// 方案1：使用固定宽度类型
#include <stdint.h>
int8_t  a;   // 8位
int16_t b;   // 16位
int32_t c;   // 32位
int64_t d;   // 64位

// 方案2：条件编译
#ifdef SIXTEEN_BIT_MACHINE
    typedef short int16;
    typedef int int32;
    typedef long int64;
#else
    typedef short int16;
    typedef int int32;
    typedef long long int64;
#endif
```

---

### 问题 3.3

**问**：假定你有一个程序，它把一个 long 整型变量赋值给一个 short 整型变量。编译和运行时会发生什么？

**答**：

```c
long l = 100000;
short s = s;  // 截断

// 编译：无警告（隐式转换）
// 运行时：高位丢失，结果可能不正确
```

- **编译**：可能会有警告，但通常不报错
- **运行**：如果值超过 short 范围，会发生截断
- **建议**：使用强制类型转换显式转换

---

## 练习要点

本章为**概念章节**，无编程练习。重点理解：
- 数据类型的大小和范围
- 指针的概念和使用
- 作用域和存储类型

---

## 心得体会

- 理解了C语言基本数据类型的分类
- 掌握了整型家族的取值范围
- 学会了使用 sizeof 和 limits.h 查看类型范围
- 理解了指针是存储地址的特殊类型
- 区分了 #define 和 const 的区别
- 掌握了作用域规则和存储类型的作用
