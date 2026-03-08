#include <stdio.h>

int main(void) {
    printf("习题1.3：格式化输出\n");
    printf("========================\n\n");
    
    printf("整数输出：%d\n", 42);
    printf("浮点数输出：%f\n", 3.14159);
    printf("字符输出：%c\n", 'A');
    printf("字符串输出：%s\n", "Hello C");
    
    printf("\n格式化宽度控制：\n");
    printf("整数（宽度5）：%5d\n", 42);
    printf("浮点数（2位小数）：%.2f\n", 3.14159);
    printf("左对齐：%-10d结束\n", 42);
    
    return 0;
}
