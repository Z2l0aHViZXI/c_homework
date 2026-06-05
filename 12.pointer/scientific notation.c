#include <stdio.h>
#include <string.h>
#include <ctype.h>
void process_scientific(const char* input, char* output) {
    char compact[100] = {0};  // 紧凑格式的输入
    char* base;              // 底数部分
    char* exponent;          // 指数部分
    int exp_val;             // 指数值
    int sign = 1;            // 符号
    char digits[100] = {0};  // 所有数字
    int digits_len = 0;
    int dot_pos = -1;        // 小数点位置
    int new_dot_pos;         // 新的小数点位置
    int i, j;
    char integer_part[100] = {0};  // 整数部分
    char decimal_part[100] = {0};  // 小数部分
    int int_part_len = 0;
    int dec_part_len = 0;
    int is_negative = 0;   
    // 1. 构建紧凑格式，跳过空格
    j = 0;
    for (i = 0; input[i]; i++) {
        if (!isspace((unsigned char)input[i])) {
            compact[j++] = input[i];
        }
    }    
    // 2. 检查符号
    if (compact[0] == '-') {
        is_negative = 1;
        base = compact + 1;
    } else if (compact[0] == '+') {
        base = compact + 1;
    } else {
        base = compact;
    }  
    // 3. 分割底数和指数
    exponent = strchr(base, 'E');
    if (!exponent) {
        exponent = strchr(base, 'e');
    }
    if (exponent) {
        *exponent = '\0';
        exponent++;
        // 解析指数
        exp_val = 0;
        sign = 1;
        if (*exponent == '-') {
            sign = -1;
            exponent++;
        } else if (*exponent == '+') {
            exponent++;
        }
        for (; *exponent; exponent++) {
            if (isdigit((unsigned char)*exponent)) {
                exp_val = exp_val * 10 + (*exponent - '0');
            }
        }
        exp_val *= sign;
    } else {
        exp_val = 0;
    }
    // 4. 提取所有数字和小数点位置
    for (i = 0; base[i]; i++) {
        if (base[i] == '.') {
            dot_pos = digits_len;
        } else if (isdigit((unsigned char)base[i])) {
            digits[digits_len++] = base[i];
        }
    }
    
    // 5. 计算新的小数点位置
    if (dot_pos == -1) {
        dot_pos = digits_len;
    }
    new_dot_pos = dot_pos + exp_val;
    
    // 6. 构建整数部分和小数部分
    if (new_dot_pos <= 0) {
        // 小于1的数，如 0.00123
        integer_part[0] = '0';
        int_part_len = 1;
        
        // 添加前导零
        dec_part_len = 0;
        for (i = 0; i < -new_dot_pos; i++) {
            decimal_part[dec_part_len++] = '0';
        }
        // 添加数字
        for (i = 0; i < digits_len; i++) {
            decimal_part[dec_part_len++] = digits[i];
        }
    } else if (new_dot_pos >= digits_len) {
        // 大于等于10^n的数，如 123000
        // 整数部分
        for (i = 0; i < digits_len; i++) {
            integer_part[int_part_len++] = digits[i];
        }
        // 添加尾随零
        for (i = digits_len; i < new_dot_pos; i++) {
            integer_part[int_part_len++] = '0';
        }
        dec_part_len = 0;
    } else {
        // 普通情况，如 123.456
        // 整数部分
        for (i = 0; i < new_dot_pos; i++) {
            integer_part[int_part_len++] = digits[i];
        }
        // 小数部分
        for (i = new_dot_pos; i < digits_len; i++) {
            decimal_part[dec_part_len++] = digits[i];
        }
    }  
    // 7. 格式化输出
    j = 0;   
    // 添加符号
    if (is_negative) {
        output[j++] = '-';
    }  
    // 添加整数部分（确保不带前导零，除非是0）
    if (int_part_len == 0) {
        output[j++] = '0';
    } else {
        // 跳过前导零
        i = 0;
        while (i < int_part_len - 1 && integer_part[i] == '0') {
            i++;
        }
        // 复制剩余部分
        while (i < int_part_len) {
            output[j++] = integer_part[i++];
        }
    }   
    // 添加小数点
    output[j++] = '.';
    
    // 添加小数部分，最多8位
    for (i = 0; i < 8; i++) {
        if (i < dec_part_len) {
            output[j++] = decimal_part[i];
        } else {
            output[j++] = '0';
        }
    }  
    // 结束字符串
    output[j] = '\0';
}

int main() {
    char input[100];
    char output[100];
    fgets(input, sizeof(input), stdin);    
    // 移除换行符
    input[strcspn(input, "\n")] = '\0';  
    process_scientific(input, output);   
    printf("%s\n", output); 
    return 0;
}
