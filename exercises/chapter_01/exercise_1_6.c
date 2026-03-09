/**
 * 练习 1.6：奇数列范围
 * 
 * 题目：
 * 修改rearrange程序，去除输入中列标号的个数必须是偶数的限制。
 * 如果读入的列标号为奇数个，函数就会把最后一个列范围设置为
 * 最后一个列标号所指定的列到行尾之间的范围。
 * 从最后一个列标号直至行尾的所有字符都将被复制到输出字符串。
 * 
 * 难度：★★★
 */

#include <stdio.h>
#include <stdlib.h>
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