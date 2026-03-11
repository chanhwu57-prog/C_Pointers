/**
 * 练习 2.1：多文件函数
 * 
 * 题目：
 * main函数分别用参数10, 0和10调用increment和negate，并打印出结果。
 */

#include <stdio.h>

int increment(int value);
int negate(int value);

int main(void) {
    printf("increment(10) = %d, negate(10) = %d\n", increment(10), negate(10));
    printf("increment(0) = %d, negate(0) = %d\n", increment(0), negate(0));
    printf("increment(10) = %d, negate(10) = %d\n", increment(10), negate(10));
    
    return 0;
}
