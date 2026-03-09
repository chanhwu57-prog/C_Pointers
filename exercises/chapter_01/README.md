# 第1章 - 编程练习

## 练习 1.1：Hello World
**难度**：★

编写一个程序，在标准输出打印 "Hello world!"，并添加换行符。

---

## 练习 1.2：带行号的输入复制
**难度**：★★

编写一个程序，从标准输入读取几行输入。每行输入都要打印到标准输出上，前面要加上行号。在编写这个程序时要试图让程序能够处理的输入行的长度没有限制。

**参考解答**：
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    char *input = NULL;
    size_t bufsize = 0;
    int line_number = 1;

    while (getline(&input, &bufsize, stdin) != -1) {
        printf("%d %s", line_number, input);
        line_number++;
    }

    free(input);
    return 0;
}
```

**要点**：
- 使用 `getline()` 处理任意长度行
- `getline(&ptr, &size, stdin)` 会自动分配内存

---

## 练习 1.3：Checksum 计算
**难度**：★★

编写一个程序，从标准输入读取一些字符，并把它们写到标准输出上。它同时应该计算checksum值，并写在字符的后面。

- checksum 初始为 -1
- 每个字符的值被加到 checksum 中
- 溢出被忽略
- 最后打印 checksum（可能是负值），并加换行符

**预期输出**（输入 "Hello world!"）：
```
Hello world!
102
```

**参考解答**：
```c
#include <stdio.h>

int main(void) {
    int ch;
    signed char checksum = -1;

    while ((ch = getchar()) != EOF) {
        putchar(ch);
        checksum += (signed char)ch;
    }

    printf("%d\n", checksum);
    return 0;
}
```

---

## 练习 1.4：最长行
**难度**：★★

编写一个程序，一行行地读取输入行，直至到达文件尾。算出每行输入行的长度，然后把最长的那行打印出来。假定所有输入行不超过1000个字符。

**参考解答**：
```c
#include <stdio.h>

#define MAX_LINE 1000

int main(void) {
    char line[MAX_LINE];
    char longest[MAX_LINE];
    int len, max_len = 0;

    while (fgets(line, MAX_LINE, stdin) != NULL) {
        len = 0;
        while (line[len] != '\0' && line[len] != '\n') {
            len++;
        }
        if (line[len] == '\n') {
            line[len] = '\0';
        } else {
        }

        if (len > max_len) {
            max_len = len;
            for (int i = 0; i <= len; i++) {
                longest[i] = line[i];
            }
        }
    }

    if (max_len > 0) {
        printf("%s\n", longest);
    }

    return 0;
}
```

**要点**：
- 使用固定大小数组存储行（题目限定1000字符）
- 手动计算行长度（不含换行符）
- 记录最长行并最后输出

---

## 练习 1.5：rearrange 改进
**难度**：★★★

修改 rearrange 程序中的语句，使其在列范围不是按顺序读取时也能正确工作。

**参考解答**：
```c
#include <stdio.h>
#include <string.h>

void rearrange(char* output, char* str, int columns[], int n) {
    int col, beg, end, len;
    int outpos = 0;
    len = strlen(str);

    for (col = 0; col < n; col += 2) {
        beg = columns[col] - 1;
        end = (col + 1 < n) ? columns[col + 1] : len;

        if (beg >= len) {
            continue;
        }
        if (end > len) {
            end = len;
        }

        for (int i = beg; i < end; i++) {
            output[outpos++] = str[i];
        }
    }
    output[outpos] = '\0';
}

int main(void) {
    char str[] = "abcdefghij";
    char output[1000];
    int columns[] = {8, 10, 1, 5};
    int n = sizeof(columns) / sizeof(columns[0]);

    rearrange(output, str, columns, n);
    printf("Input:  %s\n", str);
    printf("Output: %s\n", output);
    printf("Expected: hijabcde (columns 8-10 + 1-5)\n");

    return 0;
}
```

**要点**：
- 原代码使用 `break` 会在列不按顺序时过早终止
- 修改方案：使用 `continue` 跳过超出范围的列，而不是中断循环
- 需要检查 `beg >= len` 跳过不存在的列

---

## 练习 1.6：奇数列范围
**难度**：★★★

修改 rearrange 程序，去除输入中列标号的个数必须是偶数的限制。

**参考解答**：
```c
#include <stdio.h>
#include <string.h>

void rearrange(char* output, char* str, int columns[], int n) {
    int col, beg, end, len;
    int outpos = 0;
    len = strlen(str);

    for (col = 0; col < n; col += 2) {
        beg = columns[col] - 1;

        if (col + 1 < n) {
            end = columns[col + 1];
        } else {
            end = len;
        }

        if (beg >= len) {
            continue;
        }
        if (end > len) {
            end = len;
        }

        for (int i = beg; i < end; i++) {
            output[outpos++] = str[i];
        }
    }
    output[outpos] = '\0';
}

int main(void) {
    char str[] = "abcdefghij";
    char output[1000];
    int columns[] = {1, 5, 9};
    int n = sizeof(columns) / sizeof(columns[0]);

    rearrange(output, str, columns, n);
    printf("Input:  %s\n", str);
    printf("Output: %s\n", output);

    return 0;
}
```

**要点**：
- 关键修改：`if (col + 1 < n)` 检查是否还有结束列
- 如果没有结束列（奇数个列标号），默认从起始列到行尾
- 代码已经兼容了偶数和奇数两种情况

---

## 运行方法

```bash
# 编译并运行
./run.sh exercises/chapter_01/exercise_1_2.c

# 使用管道测试
echo "hello" | ./run.sh exercises/chapter_01/exercise_1_2.c
```
