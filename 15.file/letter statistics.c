#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
    char str[501];
    int count[52] = {0}; // 0-25 for A-Z, 26-51 for a-z
    int exists[26] = {0}; // 标记字母是否出现过（不区分大小写）
    int max_count = 0;
    int letter_pairs[26][2] = {0}; // 存储出现的字母对
    int pair_count = 0;
    int i,height; 
    // 读取输入字符串
    fgets(str, sizeof(str), stdin);
    // 统计每个字母出现的次数
    for (i = 0; str[i] != '\0'; i++) {
        if (isupper(str[i])) {
            int idx = str[i] - 'A';
            count[idx]++;
            exists[idx] = 1;
            if (count[idx] > max_count) {
                max_count = count[idx];
            }
        } else if (islower(str[i])) {
            int idx = str[i] - 'a' + 26;
            count[idx]++;
            exists[idx - 26] = 1;
            if (count[idx] > max_count) {
                max_count = count[idx];
            }
        }
    }
    // 生成字母对列表
    for (i = 0; i < 26; i++) {
        if (exists[i]) {
            letter_pairs[pair_count][0] = i; // 大写字母索引
            letter_pairs[pair_count][1] = i + 26; // 小写字母索引
            pair_count++;
        }
    }
    // 绘制柱状图
    for (height = max_count; height >= 1; height--) {
        int first = 1;
        for (i = 0; i < pair_count; i++) {
            int upper_idx = letter_pairs[i][0];
            int lower_idx = letter_pairs[i][1];
            int has_upper = (count[upper_idx] > 0);
            int has_lower = (count[lower_idx] > 0);
            // 不同字母对之间空一格
            if (!first) {
                printf(" ");
            }
            first = 0;
            // 输出大写字母的柱子（如果有）
            if (has_upper) {
                if (count[upper_idx] >= height) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
            // 输出小写字母的柱子（如果有）
            if (has_lower) {
                if (count[lower_idx] >= height) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
        }
        printf(" \n");
    }
    // 输出字母标签
    int first = 1;
    for (i = 0; i < pair_count; i++) {
        int upper_idx = letter_pairs[i][0];
        int lower_idx = letter_pairs[i][1];
        int has_upper = (count[upper_idx] > 0);
        int has_lower = (count[lower_idx] > 0);
        // 不同字母对之间空一格
        if (!first) {
            printf(" ");
        }
        first = 0;
        // 输出大写字母标签（如果有）
        if (has_upper) {
            printf("%c", 'A' + upper_idx);
        }
        // 输出小写字母标签（如果有）
        if (has_lower) {
            printf("%c", 'a' + (lower_idx - 26));
        }
    }
    printf(" \n");
    return 0;
}
