#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_LEN 100
#define MAX_OUTPUT_LEN 200

// 移除字符串前导零
void remove_leading_zeros(char *str) {
    int len = strlen(str);
    if (len <= 1) return;
    
    // 特殊处理：如果字符串以小数点开头，添加前导零
    if (*str == '.') {
        memmove(str + 1, str, len + 1);
        *str = '0';
        len++;
    }
    
    int first_non_zero = 0;
    while (first_non_zero < len - 1 && str[first_non_zero] == '0') {
        first_non_zero++;
    }
    
    if (first_non_zero > 0) {
        memmove(str, str + first_non_zero, len - first_non_zero + 1);
    }
}

// 移除字符串尾随零
void remove_trailing_zeros(char *str) {
    int len = strlen(str);
    if (len <= 1) return;
    
    char *dot = strchr(str, '.');
    if (dot == NULL) return;
    
    char *end = str + len - 1;
    while (end > dot && *end == '0') {
        *end-- = '\0';
    }
    
    if (*end == '.') {
        *end = '\0';
    }
}

// 高精度整数乘法
void multiply_int(const char *a, const char *b, char *result) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    int i,j;
    // 初始化结果数组
    int *res = (int *)calloc(len_a + len_b, sizeof(int));
    if (res == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    
    // 执行乘法
    for (i = len_a - 1; i >= 0; i--) {
        for (j = len_b - 1; j >= 0; j--) {
            int product = (a[i] - '0') * (b[j] - '0');
            int sum = product + res[i + j + 1];
            res[i + j] += sum / 10;
            res[i + j + 1] = sum % 10;
        }
    }
    
    // 转换为字符串
    int idx = 0;
    int start = 0;
    while (start < len_a + len_b - 1 && res[start] == 0) {
        start++;
    }
    
    for (i = start; i < len_a + len_b; i++) {
        result[idx++] = res[i] + '0';
    }
    result[idx] = '\0';
    
    free(res);
    
    // 如果结果为空，设置为"0"
    if (strlen(result) == 0) {
        strcpy(result, "0");
    }
}

// 小数乘法主函数
void decimal_multiply(const char *num1, const char *num2, char *result) {
    // 处理符号
    int sign1 = 1; // 1表示正数，-1表示负数
    int sign2 = 1;
    char temp1[MAX_INPUT_LEN], temp2[MAX_INPUT_LEN];
    
    // 处理第一个数的符号
    if (num1[0] == '-') {
        sign1 = -1;
        strcpy(temp1, num1 + 1);
    } else {
        strcpy(temp1, num1);
    }
    
    // 处理第二个数的符号
    if (num2[0] == '-') {
        sign2 = -1;
        strcpy(temp2, num2 + 1);
    } else {
        strcpy(temp2, num2);
    }
    
    char int_part1[MAX_INPUT_LEN], int_part2[MAX_INPUT_LEN];
    int dec1 = 0, dec2 = 0;
    int i, j;
    
    // 处理第一个数
    // 特殊处理：如果字符串以小数点开头，添加前导零
    if (*temp1 == '.') {
        memmove(temp1 + 1, temp1, strlen(temp1) + 1);
        *temp1 = '0';
    }
    
    for (i = 0, j = 0; temp1[i] != '\0'; i++) {
        if (temp1[i] == '.') {
            dec1 = strlen(temp1) - i - 1;
        } else {
            int_part1[j++] = temp1[i];
        }
    }
    int_part1[j] = '\0';
    
    // 处理第二个数
    // 特殊处理：如果字符串以小数点开头，添加前导零
    if (*temp2 == '.') {
        memmove(temp2 + 1, temp2, strlen(temp2) + 1);
        *temp2 = '0';
    }
    
    for (i = 0, j = 0; temp2[i] != '\0'; i++) {
        if (temp2[i] == '.') {
            dec2 = strlen(temp2) - i - 1;
        } else {
            int_part2[j++] = temp2[i];
        }
    }
    int_part2[j] = '\0';
    
    // 移除整数部分的前导零
    remove_leading_zeros(int_part1);
    remove_leading_zeros(int_part2);
    
    // 执行整数乘法
    char int_result[MAX_OUTPUT_LEN];
    multiply_int(int_part1, int_part2, int_result);
    
    // 计算总小数位数
    int total_dec = dec1 + dec2;
    
    // 处理结果
    int len_result = strlen(int_result);
    
    if (total_dec == 0) {
        // 结果为整数
        strcpy(result, int_result);
    } else if (len_result <= total_dec) {
        // 需要添加前导零
        int zeros_needed = total_dec - len_result;
        sprintf(result, "0.%0*d%s", zeros_needed, 0, int_result);
    } else {
        // 插入小数点
        memmove(int_result + len_result - total_dec + 1,
               int_result + len_result - total_dec,
               total_dec + 1);
        int_result[len_result - total_dec] = '.';
        strcpy(result, int_result);
    }
    
    // 移除尾随零
    remove_trailing_zeros(result);
    
    // 添加结果符号
    if (sign1 * sign2 == -1 && strcmp(result, "0") != 0) {
        // 结果为负，且不是0
        memmove(result + 1, result, strlen(result) + 1);
        *result = '-';
    }
}

int main() {
    char num1[MAX_INPUT_LEN], num2[MAX_INPUT_LEN];
    char result[MAX_OUTPUT_LEN];
    
    // 读取输入
    fgets(num1, sizeof(num1), stdin);
    fgets(num2, sizeof(num2), stdin);
    
    // 去除换行符
    num1[strcspn(num1, "\n")] = '\0';
    num2[strcspn(num2, "\n")] = '\0';
    
    // 执行乘法
    decimal_multiply(num1, num2, result);
    
    // 输出结果
    printf("%s\n", result);
    
    return 0;
}
