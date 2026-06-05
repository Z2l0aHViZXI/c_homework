#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getSize(int n) {
    return 8 * (1 << (n - 1));
}

void drawJiong(char **canvas, int size, int startRow, int startCol, int n);

int main() {
    int n, size, i, j;
    char **canvas = NULL;
    if (scanf("%d", &n) != 1 || n < 1 || n > 7) {
        printf("请输入1到7之间的整数\n");
        return 0;
    }
    
    size = getSize(n);
    
    canvas = (char **)malloc(size * sizeof(char *));
    if (canvas == NULL) {
        printf("内存分配失败\n");
        return 0;
    }
    
    for (i = 0; i < size; i++) {
        canvas[i] = (char *)malloc((size + 1) * sizeof(char));
        if (canvas[i] == NULL) {
            while (--i >= 0) {
                free(canvas[i]);
            }
            free(canvas);
            printf("内存分配失败\n");
            return 0;
        }
        memset(canvas[i], ' ', size);
        canvas[i][size] = '\0';
    }
    
    drawJiong(canvas, size, 0, 0, n);
    
    for (i = 0; i < size; i++) {
        printf("%s\n", canvas[i]);
        free(canvas[i]);
    }
    
    if (canvas != NULL) {
        free(canvas);
    }
    
    return 0;
}

void drawJiong(char **canvas, int size, int startRow, int startCol, int n) {
    int i, j;
    
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            int absRow = startRow + i;
            int absCol = startCol + j;
            
            if (i == 0 || i == size - 1) {
                if (j == 0 || j == size - 1) {
                    canvas[absRow][absCol] = '+';
                } else {
                    canvas[absRow][absCol] = '-';
                }
            } else if (j == 0 || j == size - 1) {
                canvas[absRow][absCol] = '|';
            }
        }
    }
    
    if (size == 8) {
        int center = size / 2;
        
        canvas[startRow + 2][startCol + 2] = '/';
        canvas[startRow + 2][startCol + 5] = '\\';
        
        canvas[startRow + 4][startCol + 2] = '+';
        canvas[startRow + 4][startCol + 3] = '-';
        canvas[startRow + 4][startCol + 4] = '-';
        canvas[startRow + 4][startCol + 5] = '+';
        
        canvas[startRow + 5][startCol + 2] = '|';
        canvas[startRow + 5][startCol + 5] = '|';
        
        canvas[startRow + 6][startCol + 2] = '|';
        canvas[startRow + 6][startCol + 5] = '|';
        
        canvas[startRow + 7][startCol + 2] = '+';
        canvas[startRow + 7][startCol + 3] = '-';
        canvas[startRow + 7][startCol + 4] = '-';
        canvas[startRow + 7][startCol + 5] = '+';
    } else {
        int halfSize = size / 2;
        int center = size / 2;
        
        int i;
        for (i = 1; i <= size / 2-3; i++) {
            int row = startRow + i+1;
            int leftCol = startCol + center - i - 1;
            int rightCol = startCol + center + i;
            
            if (row >= 0 && row < startRow + size && leftCol >= startCol && leftCol < startCol + size) {
                canvas[row][leftCol] = '/';
            }
            if (row >= 0 && row < startRow + size && rightCol >= startCol && rightCol < startCol + size) {
                canvas[row][rightCol] = '\\';
            }
        }
        
        drawJiong(canvas, halfSize, startRow + halfSize, startCol + (size - halfSize) / 2, n - 1);
    }
}
