#include <stdio.h>
#include <stdlib.h> // 用于abs函数（处理负数）

// 判断数字是否包含数字7
int has_seven(int num) {
    num = abs(num); // 将负数转为正数后判断
    while (num > 0) {
        if (num % 10 == 7) { // 检查最后一位是否为7
            return 1;
        }
        num = num / 10; // 去掉最后一位，继续检查
    }
    return 0;
}

int main() {
    int A, B;
    // 读取起始数字A和结束数字B
    scanf("%d %d", &A, &B);
    
    // 确定遍历的范围（处理A > B的情况）
    int start = (A < B) ? A : B;
    int end = (A > B) ? A : B;
    
    int count = 0; // 记录拍手次数
    
    // 遍历范围内的每个数字
    for (int n = start; n <= end; n++) {
        // 满足“7的倍数”或“包含数字7”任意一个条件则计数
        if (n % 7 == 0 || has_seven(n)) {
            count++;
        }
    }
    
    // 输出结果
    printf("%d\n", count);
    return 0;
}
