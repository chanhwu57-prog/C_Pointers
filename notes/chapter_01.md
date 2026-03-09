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

---

## 本节重点：memcpy 函数

### 函数原型
```c
#include <string.h>
void *memcpy(void *dest, const void *src, size_t n);
```

### 参数说明
| 参数 | 含义 |
|------|------|
| `dest` | 目标缓冲区 |
| `src` | 源缓冲区 |
| `n` | 复制的字节数 |

### 使用示例
```c
char src[] = "hello";
char dest[10];

memcpy(dest, src, 5);        // 复制5个字节
dest[5] = '\0';               // 手动添加结束符
```

### 注意事项
- 不检查重叠，重叠用 memmove
- 不会自动添加 `\0`
- 按字节复制

---

## 本节重点：getline 函数

### 函数原型
```c
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
```

### 参数说明

| 参数 | 含义 |
|------|------|
| `lineptr` | 指向字符指针的指针，用于存放读取的行 |
| `n` | 指向 size_t 变量的指针，存放缓冲区大小 |
| `stream` | 输入源（stdin 表示标准输入） |

### 返回值
- **成功**: 返回读取的字符数（不包括结尾的 `\0`）
- **失败或到达文件尾**: 返回 `-1`

### 使用示例
```c
char *line = NULL;
size_t bufsize = 0;

// 第一次调用：自动分配内存
getline(&line, &bufsize, stdin);

// 后续调用：如果已有足够空间会复用，不够会自动扩容
while (getline(&line, &bufsize, stdin) != -1) {
    printf("%s", line);
}

free(line);  // 释放内存
```

### 为什么 buf_size 是 size_t？

1. **size_t 是无符号整数类型**，专门表示内存大小
2. 内存大小不能是负数，用无符号类型更安全
3. 与 malloc/free、sizeof 等函数兼容

---

## 本节重点：fgets vs getline

| 特性 | fgets | getline |
|------|-------|---------|
| 头文件 | stdio.h | stdio.h |
| 缓冲区 | 需要手动分配固定大小 | 自动分配/扩容 |
| 读取限制 | 最多 n-1 个字符 | 无限长度 |

### fgets（固定缓冲区）
```c
char buf[100];
fgets(buf, 100, stdin);  // 最多读99个字符
```

### getline（自动扩容）
```c
char *line = NULL;
getline(&line, &bufsize, stdin);  // 自动处理任意长度
```

---

## 本节重点：stdin/stdout/stderr

| 名称 | 含义 | 用途 |
|------|------|------|
| stdin | 标准输入 | 键盘/文件/管道输入 |
| stdout | 标准输出 | 正常输出 |
| stderr | 标准错误 | 错误信息 |

### 输入来源示例
```bash
# 从键盘输入
./program

# 从文件重定向
./program < input.txt

# 管道输入
echo "hello" | ./program
```

---

## 练习要点

- [x] 练习 1.1：Hello World - 基础输出
- [x] 练习 1.2：带行号的输入复制 - 使用 getline 实现无限长度行读取
- [x] 练习 1.3：Checksum 计算 - 字符值累加，溢出自动忽略
- [x] 练习 1.4：最长行 - 固定大小数组记录最长行
- [x] 练习 1.5：rearrange 改进 - continue 替代 break，跳过超范围列
- [x] 练习 1.6：奇数列范围 - 检查列标号是否成对

---

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

---

## 项目使用说明

### 运行脚本
项目根目录下的 `run.sh` 可以方便地编译和运行练习：

```bash
# 在项目根目录执行
cd /Users/chanh/Documents/C_Learning/C_Pointers

# 编译运行
./run.sh exercises/chapter_01/exercise_1_2.c

# 管道测试
echo "hello world" | ./run.sh exercises/chapter_01/exercise_1_3.c

# 从文件读取
./run.sh exercises/chapter_01/exercise_1_2.c < input.txt
```

### 输出位置
- 可执行文件生成在 `build/` 目录
- 不会污染源代码目录

---

## 常见错误及解决

1. **gets() 缓冲区溢出**
   - 原因：gets() 不检查缓冲区大小
   - 解决：使用 getline() 或 fgets()

2. **printf 缺少换行符**
   - 原因：输出挤在一起
   - 解决：加 `\n`

3. **未释放内存**
   - 原因：getline 分配的内存未释放
   - 解决：使用 free()

---

## 心得体会

通过第1章的学习和练习：
1. 理解了 C 语言程序的基本结构
2. 掌握了 getline() 处理任意长度输入
3. 学会了 stdin/stdout 的使用
4. 了解了 size_t 的作用
5. 能够使用 run.sh 脚本进行测试

下一步：继续学习后续章节的编程练习
