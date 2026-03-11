# 第2章 - 编程练习

## 练习 2.1：多文件函数
**难度**：★

编写一个程序，它由3个函数组成，每个函数分别保存在一个单独的源文件中。函数increment接受一个整型参数，它的返回值是该参数的值加1。increment函数应该位于文件increment.c中。第2个函数称为negate，它也接受一个整型参数，它的返回值是该参数的负值（例如，如果参数是25，函数返回-25；如果参数是-612，函数返回612）。最后一个函数是main，保存于文件main.c中，它分别用参数10, 0和10调用另外两个函数，并打印出结果。

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
gcc -c increment.c
gcc -c negate.c
gcc -o main main.c increment.o negate.o
./main
```

**要点**：
- 函数原型必须在调用前声明
- 多文件编译：先分别编译为 .o 文件，再链接

---

## 练习 2.2：花括号匹配检测
**难度**：★★

编写一个程序，它从标准输入读取C源代码，并验证所有的花括号都正确地成对出现。注意：你不必担心注释内部、字符串常量内部和字符常量形式的花括号。

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

**要点**：
- 计数器法：遇到 `{` 加1，遇到 `}` 减1
- 计数器为负 = 多了 `}`
- 循环结束计数器为正 = 多了 `{`

---

## 运行方法

```bash
# 编译多文件程序
gcc -c increment.c
gcc -c negate.c
gcc -o main main.c increment.o negate.o

# 运行花括号检测
echo -e "int main() {\n  return 0;\n}" | ./run.sh exercises/chapter_02/exercise_2_2.c
```
