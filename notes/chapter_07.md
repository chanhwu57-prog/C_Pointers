# 第7章：函数

## 学习目标

- 掌握函数的定义和声明
- 理解函数参数传递机制
- 学会使用递归和可变参数函数

---

## 7.1 函数定义

```c
类型 函数名(形式参数列表)
{
    代码块
}
```

**示例**：

```c
int *
find_int(int key, int array[], int array_len)
{
    int i;
    for (i = 0; i < array_len; i++) {
        if (array[i] == key)
            return &array[i];
    }
    return NULL;
}
```

**return语句**：

```c
return expression;    // 返回值
return;               // 无返回值（void函数）
```

---

## 7.2 函数声明（原型）

```c
int func(int a, float b);    // 函数原型
```

**作用**：告诉编译器函数的参数类型、数量和返回类型。

**建议**：在头文件中声明函数原型，供多个源文件使用。

---

## 7.3 函数参数

### 值传递

C语言中所有函数参数都是值传递：

```c
void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;    // 只交换了副本，不影响原变量
}
```

### 指针参数

通过指针可以修改原变量：

```c
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = *temp;
}

// 调用
swap(&x, &y);
```

---

## 7.4 ADT和黑盒

**抽象数据类型(ADT)**：将数据和操作封装在一起，用户只能通过接口访问。

**黑盒设计原则**：
- 模块内部数据对外不可见
- 只通过函数接口访问
- 实现细节可以改变而不影响使用者

---

## 7.5 递归

**递归**：函数直接或间接调用自身。

**示例：阶乘**：

```c
int factorial(int n) {
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}
```

**示例：斐波那契数列**：

```c
int fibonacci(int n) {
    if (n <= 2)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
```

**递归的问题**：
- 效率低（重复计算）
- 栈空间消耗大

**迭代版本更高效**：

```c
int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++)
        result *= i;
    return result;
}
```

---

## 7.6 可变参数函数

使用 `<stdarg.h>` 中的宏：

```c
#include <stdarg.h>

float average(int n_values, ...) {
    va_list var_arg;
    int count;
    float sum = 0;

    va_start(var_arg, n_values);
    for (count = 0; count < n_values; count++) {
        sum += va_arg(var_arg, int);
    }
    va_end(var_arg);

    return sum / n_values;
}

// 调用
float avg = average(5, 10, 20, 30, 40, 50);
```

**宏说明**：
- `va_list`：声明可变参数列表变量
- `va_start`：初始化可变参数列表
- `va_arg`：获取下一个参数
- `va_end`：清理可变参数列表

---

## 7.7 总结

| 概念 | 说明 |
|------|------|
| 函数定义 | 函数体的实现 |
| 函数声明 | 告诉编译器函数信息 |
| 值传递 | 参数是值的副本 |
| 指针参数 | 通过指针修改原变量 |
| 递归 | 函数调用自身 |
| 可变参数 | 使用stdarg.h处理 |

---

## 课后问题

### 问题 7.1

**问**：下面的代码有什么问题？

```c
int func() {
    return 3.14;
}
```

**答**：返回类型是int，但返回了double值。会发生隐式类型转换，丢失小数部分。

---

### 问题 7.2

**问**：递归和迭代哪个更好？

**答**：取决于问题：
- 递归：代码简洁，适合树/图遍历
- 迭代：效率更高，适合简单循环

---

### 问题 7.3

**问**：如何避免递归导致的栈溢出？

**答**：
- 使用迭代代替递归
- 限制递归深度
- 使用尾递归优化（如果编译器支持）

---

## 编程练习

详见 exercises/chapter_07/README.md

---

## 心得体会

- 理解了函数参数的值传递机制
- 学会了使用指针参数修改原变量
- 掌握了递归的基本用法和注意事项
- 学会了可变参数函数的实现
