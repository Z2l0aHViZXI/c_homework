#include <stdio.h>

int main() {
    int N;
    // 读取数列长度
    scanf("%d", &N);
    
    // 长度不足2时，直接输出无等值段
    if (N < 2) {
        printf("No equal number list\n");
        return 0;
    }
    
    int A[51]; // 题目限制N<=50，数组长度设为51足够
    // 读取数列元素
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    
    int max_len = 0;    // 最长等值段的长度
    int start = -1;     // 最长等值段的起始下标
    int end = -1;       // 最长等值段的结束下标
    int current_start = 0; // 当前连续段的起始下标
    int current_val = A[0]; // 当前连续段的元素值
    
    // 遍历数列，跟踪连续段
    for (int i = 1; i < N; i++) {
        if (A[i] == current_val) {
            continue; // 元素相同，保持当前连续段
        } else {
            // 计算当前连续段的长度
            int length = i - current_start;
            // 若当前段是更长的有效等值段，更新最长段信息
            if (length >= 2 && length > max_len) {
                max_len = length;
                start = current_start;
                end = i - 1;
            }
            // 重置当前连续段
            current_start = i;
            current_val = A[i];
        }
    }
    
    // 处理数列末尾的最后一段连续元素（避免遗漏）
    int last_length = N - current_start;
    if (last_length >= 2 && last_length > max_len) {
        max_len = last_length;
        start = current_start;
        end = N - 1;
    }
    
    // 输出结果
    if (max_len >= 2) {
        printf("The longest equal number list is from %d to %d.\n", start, end);
    } else {
        printf("No equal number list.\n");
    }
    
    return 0;
}
