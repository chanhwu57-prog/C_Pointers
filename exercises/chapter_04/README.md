# 第4章 - 语句

## 课后问题

### 问题 4.1
下面的表达式是否合法？如果合法，它执行了什么任务？
```c
3 * x * x - 4 * x + 6;
```

**答案**：合法。这是一个表达式语句，计算多项式的值但丢弃结果。它没有副作用，所以这条语句没有实际意义。

---

### 问题 4.2
赋值语句的语法是怎样的？

**答案**：C没有专门的赋值语句。赋值是通过表达式语句实现的：
```c
variable = expression;
```

---

### 问题 4.3
用下面这种方法使用代码块是否合法？
```c
statement
{
    statement
    statement
}
statement
```

**答案**：合法。代码块可以在任何允许语句的地方使用，用于创建新的作用域。

---

### 问题 4.4
当你编写if语句时，如果在then子句中没有语句，但在else子句中有语句，你该如何编写？

**答案**：
```c
if (condition)
    ;   // 空语句
else
    statement
```
或者更好的方式：
```c
if (!(condition))
    statement
```

---

### 问题 4.5
下面的循环将产生什么样的输出？
```c
int i;
for (i = 0; i < 10; i += 1)
    printf("%d\n", i);
```

**答案**：输出 0 到 9，每行一个数字。

---

### 问题 4.6
什么时候使用while语句比使用for语句更加合适？

**答案**：当循环条件不是简单的计数器时，或者不需要初始化和更新步骤时，使用while更合适。

---

### 问题 4.7
下面的代码片段用于把标准输入复制到标准输出，并计算字符的检验和，它有什么错误吗？

**答案**：（需要查看具体代码）常见问题包括：
- 没有正确处理EOF
- 变量未初始化
- 检验和计算逻辑错误

---

### 问题 4.8
什么时候使用do语句比使用while语句更加合适？

**答案**：当循环体至少需要执行一次时，使用do-while更合适，如菜单选择、输入验证等。

---

### 问题 4.9
下面的代码片段将产生什么样的输出？

**答案**：（需要查看具体代码）

---

### 问题 4.10
编写一些语句，从标准输入读取一个整型值，然后打印一些空白行，空白行的数量由这个值指定。

**答案**：
```c
int n;
scanf("%d", &n);
for (int i = 0; i < n; i++)
    printf("\n");
```

---

### 问题 4.11
编写一些语句，用于对一些已经读入的值进行检验和报告。如果x小于y，打印单词WRONG。同样，如果a大于或等于b，也打印WRONG。在其他情况下，打印RIGHT。

**答案**：
```c
if (x < y || a >= b)
    printf("WRONG\n");
else
    printf("RIGHT\n");
```

---

### 问题 4.12
能够被4整除的年份是闰年，但其中能够被100整除的却不是闰年，除非它同时能够被400整除。请编写一些语句，判断year这个年份是否为闰年。

**答案**：
```c
int leap_year;
if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    leap_year = 1;
else
    leap_year = 0;
```

---

### 问题 4.13
新闻记者都受过训练，善于提问谁？什么？何时？何地？为什么？请编写一些语句，如果变量which_word的值是1，就打印who；如果值为2，打印what，依次类推。

**答案**：
```c
switch (which_word) {
    case 1: printf("who"); break;
    case 2: printf("what"); break;
    case 3: printf("when"); break;
    case 4: printf("where"); break;
    case 5: printf("why"); break;
    default: printf("don't know"); break;
}
```

---

### 问题 4.14
假定由一个"程序"来控制你，而且这个程序包含两个函数：eat_hamberger()用于让你吃汉堡包，hungry()函数根据你是否饥饿返回真值或假值。请编写一些语句，允许你在饥饿感得到满足之前爱吃多少汉堡包就吃多少。

**答案**：
```c
while (hungry())
    eat_hamberger();
```

---

### 问题 4.15
修改你对问题14的答案，使它能够让你的祖母满意——就是你已经吃过一些东西了。也就是说，你至少必须吃一个汉堡包。

**答案**：
```c
do
    eat_hamberger();
while (hungry());
```

---

### 问题 4.16
编写一些语句，根据变量precipitating和temperature的值打印当前天气的简单总结。

| precipitating | temperature | 打印 |
|---------------|-------------|------|
| true | <32 | snowing |
| true | >=32 | raining |
| false | <60 | cold |
| false | >=60 | warm |

**答案**：
```c
if (precipitating) {
    if (temperature < 32)
        printf("snowing\n");
    else
        printf("raining\n");
} else {
    if (temperature < 60)
        printf("cold\n");
    else
        printf("warm\n");
}
```

---

## 编程练习

### 练习 4.1 - 平方根计算
编写一个程序，读入一个值，计算并打印出它的平方根。

**文件**: [exercise_4_1.c](exercise_4_1.c)

---

### 练习 4.2 - 质数打印
编写一个程序，打印出1～100之间的所有质数。

**文件**: [exercise_4_2.c](exercise_4_2.c)

---

### 练习 4.3 - 三角形类型判断
编写一个程序，判断三角形是什么类型。

**文件**: [exercise_4_3.c](exercise_4_3.c)

---

### 练习 4.4 - 字符串复制函数
编写函数copy_n，复制指定数量的字符。

**文件**: [exercise_4_4.c](exercise_4_4.c)

---

### 练习 4.5 - 打印重复行
编写一个程序，打印相邻的重复行。

**文件**: [exercise_4_5.c](exercise_4_5.c)

---

### 练习 4.6 - 子字符串提取
编写函数substr，从字符串中提取子字符串。

**文件**: [exercise_4_6.c](exercise_4_6.c)

---

### 练习 4.7 - 去除多余空格
编写函数deblank，去除字符串中多余的空格。

**文件**: [exercise_4_7.c](exercise_4_7.c)
