/**
 * 练习 1.5：rearrange 改进
 * 
 * 题目：
 * rearrange程序中的下列语句
 *     if( columns[col] >= len ... )
 *         break;
 * 
 * 当字符的列范围超出输入行的末尾时就停止复制。
 * 这条语句只有当列范围以递增顺序出现时才是正确的，
 * 但事实上并不一定如此。请修改这条语句，即使列范围
 * 不是按顺序读取时也能正确完成任务。
 * 
 * 难度：★★★
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rearrange(char* output, const char* input, int* columns, int num_columns) {
    int col;
    int len = strlen(input);
    int outpos = 0;
    for (col = 0; col < num_columns; col += 2){
        int start = columns[col] - 1;
        if (start >= len) {
            continue;
        }
        int end = columns[col + 1] - 1;
        if (end >= len) {
            end = len - 1;
        }
        memcpy(output + outpos, input + start, end - start + 1);
        outpos += end - start + 1;
    }
    output[outpos] = '\0';
}

int main(void) {
    char input[] = "abcdefghij";
    char output[100];
    int columns[] = {8, 10, 1, 5};
    int num_columns = sizeof(columns) / sizeof(columns[0]);
    
    rearrange(output, input, columns, num_columns);
    
    printf("Input:  %s\n", input);
    printf("Output: %s\n", output);
    printf("Expected: hjabcde (columns 8-10 + 1-5)\n");
    
    return 0;
}
