# 第8章 - 数组

## 课后问题

### 问题 8.1
根据声明和数据，计算表达式的值。

**答案**：这是一个大型练习，需要逐个计算表达式值。

---

### 问题 8.2-8.16
（需要查看具体代码）

---

### 问题 8.17
解释下面两种const关键字用法的显著区别：
```c
void function(int const a, int const b[]);
```

**答案**：
- `int const a`：a是常量整数，函数内不能修改a的值
- `int const b[]`：b是常量整数数组，函数内不能修改数组元素的值

---

### 问题 8.18
下面的函数原型可以改写为什么形式？
```c
void function(int array[3][2][5]);
```

**答案**：
```c
void function(int (*array)[2][5]);
```
数组参数在函数声明中等价于指针。

---

### 问题 8.19
矩阵方案如何修改使其不需要知道表的长度？

**答案**：可以使用一个特殊的值（如空指针或特殊标记）来标记矩阵的结束。

---

## 编程练习

### 练习 8.1 - 多维数组初始化
编写一个数组的声明，把数组的某些特定位置初始化为特定的值。

**文件**: [exercise_8_1.c](exercise_8_1.c)

---

### 练习 8.2 - 个人所得税计算
编写函数single_tax，计算个人所得税。

```c
float single_tax(float income);
```

**文件**: [exercise_8_2.c](exercise_8_2.c)

---

### 练习 8.3 - 单位矩阵判断
编写函数identity_matrix，判断矩阵是否为单位矩阵。

```c
int identity_matrix(int matrix[10][10]);
```

**文件**: [exercise_8_3.c](exercise_8_3.c)

---

### 练习 8.4 - 通用单位矩阵判断
修改identity_matrix函数，接受任意大小的矩阵。

```c
int identity_matrix(int *matrix, int size);
```

**文件**: [exercise_8_4.c](exercise_8_4.c)

---

### 练习 8.5 - 矩阵乘法
编写函数matrix_multiply，执行两个矩阵的乘法。

```c
void matrix_multiply(int *m1, int *m2, int *r, int x, int y, int z);
```

**文件**: [exercise_8_5.c](exercise_8_5.c)

---

### 练习 8.6 - 伪数组下标计算
编写函数array_offset，计算伪数组的偏移量。

```c
int array_offset(int arrayinfo[], ...);
```

**文件**: [exercise_8_6.c](exercise_8_6.c)

---

### 练习 8.7 - 列主序伪数组
修改array_offset函数，访问以列主序存储的伪数组。

```c
int array_offset2(int arrayinfo[], ...);
```

**文件**: [exercise_8_7.c](exercise_8_7.c)

---

### 练习 8.8 - 八皇后问题
编写程序找到八皇后问题的所有答案。

**文件**: [exercise_8_8.c](exercise_8_8.c)
