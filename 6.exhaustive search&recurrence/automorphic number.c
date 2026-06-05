#include <stdio.h>
#include <math.h>
int Automorphic(int num) {
    long long square = (long long)num * num;
    int count = 0;
    int temp = num;
    while (temp != 0) {
        count++;
        temp /= 10;
    }
    int divisor = pow(10, count);
    int last_digits = square % divisor;
    return (last_digits == num);
}
int main() {
    int n;
	scanf("%d",&n);
    unsigned long long a=pow(10,n-1),b=pow(10,n)-1,i;
    for (i = a; i <= b; i++) {
        if (Automorphic(i)) {
            printf("%llu\n", i);
        }
    }
    return 0;
}
