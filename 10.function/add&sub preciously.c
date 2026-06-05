#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 10000
int i; 
void re(char *s, int *a, int *len) {
    *len = strlen(s);
    if (*len > MAX_LEN) {
        *len = MAX_LEN;
    }
    for (i = 0; i < *len; i++) {
        a[i] = s[*len - 1 - i] - '0';
    }
    for (i = *len; i < MAX_LEN; i++) {
        a[i] = 0;
    }
}
void add(int *a, int *b, int lena, int lenb, int *sum, int *lensum) {
    int maxlen = lena > lenb ? lena : lenb;
    int carry = 0;
    for (i = 0; i < maxlen; i++) {
        int x = i < lena ? a[i] : 0;
        int y = i < lenb ? b[i] : 0;
        int z = x + y + carry;
        sum[i] = z % 10;
        carry = z / 10;
    }
    if (carry && maxlen < MAX_LEN) {
        sum[maxlen] = carry;
        *lensum = maxlen + 1;
    } else {
        *lensum = maxlen;
    }
}
void sub(int *a, int *b, int lena, int lenb, int *diff, int *lendiff) {
    int borrow = 0;
    for (i = 0; i < lena; i++) {
        int x = a[i];
        int y = i < lenb ? b[i] : 0;
        int z = x - y - borrow;
        if (z < 0) {
            z += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        diff[i] = z;
    }
    *lendiff = lena;
    while (*lendiff > 1 && diff[*lendiff - 1] == 0) {
        (*lendiff)--;
    }
}
int compare(int *a, int *b, int lena, int lenb) {
    if (lena != lenb) {
        return lena > lenb ? 1 : -1;
    }
    for (i = lena - 1; i >= 0; i--) {
        if (a[i] != b[i]) {
            return a[i] > b[i] ? 1 : -1;
        }
    }
    return 0;
}
int main() {
    int n;
    char line[MAX_LEN * 2 + 5];
    if (scanf("%d", &n) != 1) {
        printf("ÊäÈë´íÎó\n");
        return 1;
    }
    getchar();
    while (n--) {
        char s[MAX_LEN] = {0}, t[MAX_LEN] = {0};
        char op = 0;
        int a[MAX_LEN] = {0}, b[MAX_LEN] = {0}, res[MAX_LEN] = {0};
        int lena, lenb, lenres;
        int s_pos = 0, t_pos = 0;
        if (fgets(line, sizeof(line), stdin) == NULL) {
            printf("ÊäÈë´íÎó\n");
            continue;
        }
        line[strcspn(line, "\n")] = 0;
        int i = 0;
        while (line[i] == ' ') i++;
        while (line[i] >= '0' && line[i] <= '9' && s_pos < MAX_LEN) {
            s[s_pos++] = line[i++];
        }
        s[s_pos] = '\0';
        while (line[i] == ' ') i++;
        if (line[i] == '+' || line[i] == '-') {
            op = line[i++];
        }
        while (line[i] == ' ') i++;
        while (line[i] >= '0' && line[i] <= '9' && t_pos < MAX_LEN) {
            t[t_pos++] = line[i++];
        }
        t[t_pos] = '\0';
        if (op == 0 || s_pos == 0 || t_pos == 0) {
            printf("ÊäÈë¸ñÊ½´íÎó\n");
            continue;
        }
        re(s, a, &lena);
        re(t, b, &lenb); 
        if (op == '+') {
            add(a, b, lena, lenb, res, &lenres);
        } else if (op == '-') {
            int cmp = compare(a, b, lena, lenb);
            if (cmp < 0) {
                sub(b, a, lenb, lena, res, &lenres);
                printf("-");
            } else {
                sub(a, b, lena, lenb, res, &lenres);
            }
        }
        for (i = lenres - 1; i >= 0; i--) {
            printf("%d", res[i]);
        }
        printf("\n");
    }
    return 0;
}
