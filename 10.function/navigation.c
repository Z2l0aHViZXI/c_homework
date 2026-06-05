#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int map2[10][10];
int map1[10][10];
int visited2[10][10];
int visited1[10][10];
int i,x,y;
struct Point {
    int level;
    int x;
    int y;
};
struct Point path[200];
int path_len = 0;
int m223_x, m223_y;
int garden_x, garden_y;
int dfs(int level, int x, int y, int len) {
    if (level == 1 && x == garden_x && y == garden_y) {
        path[len].level = level;
        path[len].x = x;
        path[len].y = y;
        path_len = len + 1;
        return 1;
    }
    if (level == 1) {
        visited1[y][x] = 1;
    } else {
        visited2[y][x] = 1;
    }
    path[len].level = level;
    path[len].x = x;
    path[len].y = y;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    for (i = 0; i < 4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];      
        if (new_x >= 0 && new_x < 10 && new_y >= 0 && new_y < 10) {
            if (level == 1) {
                if ((map1[new_y][new_x] == 1 || map1[new_y][new_x] == 2 || map1[new_y][new_x] == 7) && visited1[new_y][new_x] == 0) {
                    if (dfs(1, new_x, new_y, len + 1)) {
                        return 1;
                    }
                }
            } else {
                if ((map2[new_y][new_x] == 1 || map2[new_y][new_x] == 2 || map2[new_y][new_x] == 223) && visited2[new_y][new_x] == 0) {
                    if (dfs(2, new_x, new_y, len + 1)) {
                        return 1;
                    }
                }
            }
        }
    }
    if (level == 1) {
        if (map1[y][x] == 2) {
            if (map2[y][x] == 2 && visited2[y][x] == 0) {
                if (dfs(2, x, y, len + 1)) {
                    return 1;
                }
            }
        }
    } else {
        if (map2[y][x] == 2) {
            if (map1[y][x] == 2 && visited1[y][x] == 0) {
                if (dfs(1, x, y, len + 1)) {
                    return 1;
                }
            }
        }
    }
    if (level == 1) {
        visited1[y][x] = 0;
    } else {
        visited2[y][x] = 0;
    }
    return 0;
}
int main() {
    for (y = 0; y < 10; y++) {
        for (x = 0; x < 10; x++) {
            scanf("%d", &map2[y][x]);
        }
    }
    char c;
    while ((c = getchar()) == '\n');
    if (c != EOF) {
        ungetc(c, stdin);
    }
    for (y = 0; y < 10; y++) {
        for (x = 0; x < 10; x++) {
            scanf("%d", &map1[y][x]);
        }
    }
    for (y = 0; y < 10; y++) {
        for (x = 0; x < 10; x++) {
            if (map2[y][x] == 223) {
                m223_x = x;
                m223_y = y;
            }
            if (map1[y][x] == 7) {
                garden_x = x;
                garden_y = y;
            }
        }
    }
    memset(visited1, 0, sizeof(visited1));
    memset(visited2, 0, sizeof(visited2));
    int found = dfs(2, m223_x, m223_y, 0);
    if (!found) {
        printf("世上本没有路......\n");
        return 0;
    }
    int result[10][10];
    memset(result, 0, sizeof(result));
    for (i = 0; i < path_len; i++) {
        int level = path[i].level;
        int x = path[i].x;
        int y = path[i].y;
        if (level == 2) {
            if (result[y][x] == 0) {
                result[y][x] = 2;
            } else if (result[y][x] == 1) {
                result[y][x] = 12;
            }
        } else {
            if (result[y][x] == 0) {
                result[y][x] = 1;
            } else if (result[y][x] == 2) {
                result[y][x] = 12;
            }
        }
    }
    for (i = 1; i < path_len; i++) {
        int curr_level = path[i].level;
        int curr_x = path[i].x;
        int curr_y = path[i].y;
        int prev_level = path[i-1].level;
        int prev_x = path[i-1].x;
        int prev_y = path[i-1].y;
        if (curr_level != prev_level && curr_x == prev_x && curr_y == prev_y) {
            result[curr_y][curr_x] = -1;
        }
    }
    result[m223_y][m223_x] = -2;
    result[garden_y][garden_x] = 7;
    for (y = 0; y < 10; y++) {
        for (x = 0; x < 10; x++) {
            switch (result[y][x]) {
                case -2:
                    printf("  xx");
                    break;
                case 7:
                    printf("   7");
                    break;
                case -1:
                    printf("   +");
                    break;
                case 12:
                    printf("  12");
                    break;
                case 1:
                case 2:
                    printf("   %d", result[y][x]);
                    break;
                default:
                    printf("   0");
                    break;
            }
        }
        printf("\n");
    }   
    return 0;
}
