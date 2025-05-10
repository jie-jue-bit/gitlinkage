#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define MAX_SIZE 200  // 结果最多存储 200 个字符串
// #define MAX_LEN 5     // 每个字符串最多 4 个字符 + 1 个 '\0'

// // 电话按键映射表
// char *phone_map[] = {
//     "", "", "abc", "def", "ghi", "jkl",
//     "mno", "pqrs", "tuv", "wxyz"
// };

// // 回溯递归函数
// void backtrack(char *digits, int index, char **result, char *path, int *count) {
//     if (digits[index] == '\0') {  // 递归终止条件：所有数字处理完毕
//         path[index] = '\0';  // **确保字符串以 '\0' 结尾**
//         result[*count] = strdup(path);  // 复制字符串存入结果
//         (*count)++;
//         return;
//     }

//     int digit = digits[index] - '0';  // 转换为整数
//     char *letters = phone_map[digit]; // 获取对应的字母

//     for (int i = 0; letters[i] != '\0'; i++) {
//         path[index] = letters[i];   // 选择一个字母
//         backtrack(digits, index + 1, result, path, count); // 递归处理下一个数字
//     }
// }

// // 主函数
// char **letterCombinations(char *digits, int *returnSize) {
//     if (digits[0] == '\0') {  // 处理空输入
//         *returnSize = 0;
//         return NULL;
//     }

//     char **result = (char **)malloc(sizeof(char *) * MAX_SIZE);  // 分配存储空间
//     char path[MAX_LEN];  // 存储当前路径
//     *returnSize = 0;

//     backtrack(digits, 0, result, path, returnSize);
//     return result;
// }

// // 测试代码
// int main() {
//     char digits[] = "2347";
//     int returnSize;
//     char **combinations = letterCombinations(digits, &returnSize);

//     printf("[");
//     for (int i = 0; i < returnSize; i++) {
//         printf("\"%s\"", combinations[i]);
//         if (i < returnSize - 1) printf(", ");
//         free(combinations[i]);  // 释放分配的内存
//     }
//     printf("]\n");
//     free(combinations);

//     return 0;
// }

#define Max_size 200
#define Max_len 5

char* phone_map[]={
    "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
};
void backtrack(char* digits,int index,char** result,char* path,int* count){
    if(digits[index]=='\0'){
        path[index]='\0';
        result[*count]=strdup(path);
        (*count)++;
        return;
    }
    int digit=digits[index]-'0';
    char* temp=phone_map[digit];
    for(int i=0;temp[i]!='\0';i++){
        path[index]=temp[i];
        backtrack(digits,index+1,result,path,count);
    }
}
char **letterCombinations(char *digits, int *returnSize){
    if(digits[0]=='\0'){
        *returnSize=0;
        return NULL;
    }
    char** result=(char**)malloc(sizeof(char*)*Max_size);
    char path[Max_len];
    *returnSize=0;
    backtrack(digits,0,result,path,returnSize);
    return result;
}

int main() {
    char digits[] = "234";
    int returnSize;
    char **combinations = letterCombinations(digits, &returnSize);

    printf("[");
    for (int i = 0; i < returnSize; i++) {
        printf("\"%s\"", combinations[i]);
        if (i < returnSize - 1) printf(", ");
        free(combinations[i]);  // 释放分配的内存
    }
    printf("]\n");
    free(combinations);

    return 0;
}