# 第4章：语句

## 学习目标

- 掌握C语言各种语句的语法和使用
- 理解表达式语句和空语句
- 学会使用条件语句和循环语句

---

## 4.1 空语句

空语句只包含一个分号 `;`，本身不执行任何任务。

```c
;  // 空语句
```

**适用场合**：语法要求出现语句，但不需要执行任务。

---

## 4.2 表达式语句

在表达式后面加分号就变成语句：

```c
x = y + 3;       // 赋值表达式语句
ch = getchar();  // 函数调用表达式语句
printf("Hello"); // 返回值被忽略
a++;             // 自增表达式语句
```

**副作用(side effect)**：表达式执行时产生的实际效果。

---

## 4.3 代码块

代码块是位于 `{}` 内的声明和语句列表：

```c
{
    int temp = a;
    a = b;
    b = temp;
}
```

---

## 4.4 if语句

```c
if (expression)
    statement

if (expression)
    statement1
else
    statement2
```

**悬空else问题**：else属于最近的未配对if。

```c
if (a > 0)
    if (b > 0)
        x = 1;
    else      // 属于内层if
        x = 2;
```

**解决方案**：使用花括号：

```c
if (a > 0) {
    if (b > 0)
        x = 1;
} else {
    x = 2;
}
```

---

## 4.5 while语句

```c
while (expression)
    statement
```

执行流程：
1. 计算表达式
2. 若为真，执行循环体，回到步骤1
3. 若为假，退出循环

```c
while ((ch = getchar()) != EOF)
    putchar(ch);
```

---

## 4.6 for语句

```c
for (expr1; expr2; expr3)
    statement
```

等价于：

```c
expr1;
while (expr2) {
    statement
    expr3;
}
```

```c
for (int i = 0; i < 10; i++)
    printf("%d\n", i);
```

---

## 4.7 do-while语句

```c
do
    statement
while (expression);
```

**特点**：循环体至少执行一次。

---

## 4.8 switch语句

```c
switch (expression) {
    case value1:
        statements
        break;
    case value2:
        statements
        break;
    default:
        statements
}
```

**注意**：
- case标签必须是整型常量表达式
- break跳出switch，否则继续执行下一个case（fall-through）
- default处理所有未匹配的情况

```c
switch (ch) {
    case 'a': case 'A':
        printf("A\n");
        break;
    case 'b': case 'B':
        printf("B\n");
        break;
    default:
        printf("Other\n");
}
```

---

## 4.9 goto语句

```c
goto label;
...
label: statement
```

**建议**：尽量避免使用goto。

---

## 4.10 总结

| 语句 | 用途 |
|------|------|
| 空语句 | 语法需要但无操作 |
| 表达式语句 | 执行表达式 |
| 代码块 | 组合声明和语句 |
| if | 条件分支 |
| while | 前测试循环 |
| for | 计数循环 |
| do-while | 后测试循环 |
| switch | 多路分支 |
| goto | 无条件跳转 |

---

## 课后问题

### 问题 4.1

**问**：下面的语句是否合法？

```c
if (x > 0);
```

**答**：合法。if后面是空语句，什么都不做。

---

### 问题 4.2

**问**：下面的代码有什么问题？

```c
if (x = 5)
    printf("x is 5\n");
```

**答**：`=` 是赋值，不是比较。应该用 `==`。这个if永远为真。

---

### 问题 4.3

**问**：如何避免悬空else问题？

**答**：使用花括号明确代码块边界。

---

## 编程练习

详见 exercises/chapter_04/README.md

---

## 心得体会

- 理解了表达式语句和空语句的区别
- 掌握了各种循环语句的使用场景
- 学会了避免悬空else问题
- 理解了switch的fall-through特性
