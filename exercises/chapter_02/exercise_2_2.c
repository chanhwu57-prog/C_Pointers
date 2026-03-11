/**
 * 练习 2.2：花括号匹配检测
 * 
 * 题目：
 * 编写一个程序，它从标准输入读取C源代码，并验证所有的花括号都正确地成对出现。
 * 注意：你不必担心注释内部、字符串常量内部和字符常量形式的花括号。
 * 
 * 难度：★★
 */

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
