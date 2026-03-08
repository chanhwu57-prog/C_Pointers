#include <stdio.h>

int main(void) {
    printf("=== C语言编译过程演示 ===\n\n");
    
    printf("源代码 -> 预处理 -> 编译 -> 汇编 -> 链接 -> 可执行文件\n\n");
    
    printf("各阶段说明：\n");
    printf("1. 预处理：处理 #include, #define 等指令\n");
    printf("2. 编译：将C代码转换为汇编代码\n");
    printf("3. 汇编：将汇编代码转换为目标文件\n");
    printf("4. 链接：将目标文件和库文件链接成可执行文件\n");
    
    return 0;
}
