#include <stdio.h>
#include <string.h>
int main() {
    int m, n,i,j;
    int matrix[100][100];
    int row[100] = {0};
    int col[100] = {0};
    int rowcount = 0;
    int colcount = 0;
    scanf("%d %d", &m, &n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf(" %d", &matrix[i][j]);
        }
    }
    for (i = 0; i < m; i++) {
        int sum = 0;
        for (j = 0; j < n; j++) {
            sum +=matrix[i][j];
        }
        if (sum % 2 != 0) {
            row[i] = 1;
            rowcount++;
        }
    }
    for (j = 0; j < n; j++) {
        int sum = 0;
        for (i = 0; i < m; i++) {
            sum +=matrix[i][j];
        }
        if (sum % 2 != 0) {
            col[j] = 1;
            colcount++;
        }
    }
    int min_errors;
    if (rowcount == 0 && colcount == 0) {
        min_errors = 0;
    } else if (rowcount == 1 && colcount == 1) {
        int r= -1, c= -1,i,j;
        for (i = 0; i < m; i++) {
            if (row[i]) {
                r= i;
                break;
            }
        }
        for (j = 0; j < n; j++) {
            if (col[j]) {
                c= j;
                break;
            }
        }
        int row_sum = 0;
        for (j = 0; j < n; j++) {
            row_sum +=matrix[r][j];
        }
        int col_sum = 0;
        for (i = 0; i < m; i++) {
            col_sum +=matrix[i][c];
        }
        if ((row_sum % 2 != 0) && (col_sum % 2 != 0)) {
            min_errors = 1;
        } else {
            min_errors = rowcount + colcount;
        }
    } else {
        min_errors = rowcount + colcount;
    }
    printf("%d\n", min_errors);
    return 0;
}
