#include <stdio.h>
#include <string.h>
// 检查是否是元音字母
int is_vowel(char c) {
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}
// 获取下一个有效字符（跳过元音，循环）
char get_next_char(char c) {
    do {
        c++;
        if (c > 'Z') {
            c = 'A';
        }
    } while (is_vowel(c));
    return c;
}
int main() {
    int n,i,j;
    char start_char;
    // 读取输入
    scanf("%d %c", &n, &start_char);
    // 计算X图形的总行数和总列数
    int total_rows = 2 * n - 1;
    int total_cols = 2 * n - 1;
    // 初始化字符数组
    char output[200][200];
    memset(output, ' ', sizeof(output));
    // 起始字符处理
    char current_char = start_char;
    // 如果起始字符是元音，先找到第一个非元音
    if (is_vowel(current_char)) {
        current_char = get_next_char(current_char);
    }
    // 填充X图形的上半部分（包括中间行）
    for (i = 0; i < n; i++) {
        // 计算当前行的左右边界位置
        int left = i;
        int right = total_cols - 1 - i; 
        // 如果是第一行或最后一行，填充整行
        if (i == 0) {
            for (j = 0; j < total_cols; j++) {
                output[i][j] = current_char;
                current_char = get_next_char(current_char);
            }
        } 
        // 如果是中间行（第n行），只填充中间一个字符
        else if (i == n - 1) {
            output[i][left] = current_char;
            current_char = get_next_char(current_char);
        } 
        // 其他行填充左右两个字符
        else {
            output[i][left] = current_char;
            current_char = get_next_char(current_char);
            output[i][right] = current_char;
            current_char = get_next_char(current_char);
        }
    }
    // 填充X图形的下半部分（从n行到total_rows-1行）
    for (i = n; i < total_rows; i++) {
        // 计算当前行的左右边界位置（与上半部分对称）
        int mirror_i = total_rows - 1 - i;
        int left = mirror_i;
        int right = total_cols - 1 - mirror_i;
        // 如果是最后一行，填充整行
        if (i == total_rows - 1) {
            for (j = 0; j < total_cols; j++) {
                output[i][j] = current_char;
                current_char = get_next_char(current_char);
            }
        } 
        // 其他行填充左右两个字符
        else {
            output[i][left] = current_char;
            current_char = get_next_char(current_char);
            output[i][right] = current_char;
            current_char = get_next_char(current_char);
        }
    }
    // 输出结果
    for (i = 0; i < total_rows; i++) {
        // 找到每行的最后一个非空格字符
        int last_char_pos = total_cols - 1;
        while (last_char_pos >= 0 && output[i][last_char_pos] == ' ') {
            last_char_pos--;
        }
        // 输出当前行，直到最后一个非空格字符
        for (j = 0; j <= last_char_pos; j++) {
            printf("%c", output[i][j]);
        }
        printf("\n");
    }
    return 0;
}
