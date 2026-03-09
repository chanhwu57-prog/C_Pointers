/**
 * 练习 1.4：最长行
 * 
 * 题目：
 * 编写一个程序，一行行地读取输入行，直至到达文件尾。
 * 算出每行输入行的长度，然后把最长的那行打印出来。
 * 为了简单起见，你可以假定所有的输入行均不超过1000个字符。
 * 
 * 难度：★★
 */

#include <stdio.h>

int main(void) {
    char* line = NULL;
    size_t bufsize = 0;
    ssize_t chars_read;
    int line_number = 1;
    int max_length = 0;
    int current_length = 0;

    while ((chars_read = getline(&line, &bufsize, stdin)) != -1) {
        current_length = chars_read - 1; // 减去换行符
        if (current_length > max_length) {
            max_length = current_length;
        }
        line_number++;
    }

    printf("最长的行长度为：%d\n", max_length);

    free(line);
    return 0;
}
