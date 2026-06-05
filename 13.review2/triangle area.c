#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_TRIS 100
#define MAX_POINTS 300
#define MAX_SCANLINES 100000
#define EPS 1e-9
#define MAX_SUBDIVISIONS 1000 // 最大细分数

typedef struct Point {
    double x, y;
} Point;

typedef struct Triangle {
    Point p1, p2, p3;
} Triangle;

typedef struct Interval {
    double l, r;
} Interval;

Triangle tris[MAX_TRIS];
Point points[MAX_POINTS];
Interval intervals[MAX_TRIS];
int n, m;

int compareDoubles(const void *a, const void *b) {
    double *da = (double *)a;
    double *db = (double *)b;
    if (*da < *db) return -1;
    if (*da > *db) return 1;
    return 0;
}

int compareIntervals(const void *a, const void *b) {
    Interval *ia = (Interval *)a;
    Interval *ib = (Interval *)b;
    if (ia->l < ib->l) return -1;
    if (ia->l > ib->l) return 1;
    return 0;
}

// 判断点是否在三角形内
int pointInTriangle(Point p, Triangle t) {
    double ax = t.p1.x, ay = t.p1.y;
    double bx = t.p2.x, by = t.p2.y;
    double cx = t.p3.x, cy = t.p3.y;
    double px = p.x, py = p.y;
    
    double v0x = cx - ax, v0y = cy - ay;
    double v1x = bx - ax, v1y = by - ay;
    double v2x = px - ax, v2y = py - ay;
    
    double dot00 = v0x * v0x + v0y * v0y;
    double dot01 = v0x * v1x + v0y * v1y;
    double dot02 = v0x * v2x + v0y * v2y;
    double dot11 = v1x * v1x + v1y * v1y;
    double dot12 = v1x * v2x + v1y * v2y;
    
    double invDenom = 1.0 / (dot00 * dot11 - dot01 * dot01);
    double u = (dot11 * dot02 - dot01 * dot12) * invDenom;
    double v = (dot00 * dot12 - dot01 * dot02) * invDenom;
    
    return (u >= -EPS) && (v >= -EPS) && (u + v <= 1.0 + EPS);
}

// 计算三角形在指定y坐标处的水平区间
int getTriangleInterval(double y, Triangle t, Interval *interval) {
    Point p1 = t.p1, p2 = t.p2, p3 = t.p3;
    double x[2];
    int count = 0;
    
    // 检查边p1-p2
    if ((p1.y <= y + EPS && p2.y >= y - EPS) || (p1.y >= y - EPS && p2.y <= y + EPS)) {
        if (fabs(p1.y - p2.y) < EPS) {
            // 水平边，跳过
        } else {
            double x_val = p1.x + (y - p1.y) * (p2.x - p1.x) / (p2.y - p1.y);
            x[count++] = x_val;
        }
    }
    
    // 检查边p2-p3
    if ((p2.y <= y + EPS && p3.y >= y - EPS) || (p2.y >= y - EPS && p3.y <= y + EPS)) {
        if (fabs(p2.y - p3.y) < EPS) {
            // 水平边，跳过
        } else {
            double x_val = p2.x + (y - p2.y) * (p3.x - p2.x) / (p3.y - p2.y);
            x[count++] = x_val;
        }
    }
    
    // 检查边p3-p1
    if ((p3.y <= y + EPS && p1.y >= y - EPS) || (p3.y >= y - EPS && p1.y <= y + EPS)) {
        if (fabs(p3.y - p1.y) < EPS) {
            // 水平边，跳过
        } else {
            double x_val = p3.x + (y - p3.y) * (p1.x - p3.x) / (p1.y - p3.y);
            x[count++] = x_val;
        }
    }
    
    if (count < 2) {
        // 三角形在该y坐标处没有水平区间
        return 0;
    }
    
    // 确保区间左小右大
    if (x[0] > x[1]) {
        double temp = x[0];
        x[0] = x[1];
        x[1] = temp;
    }
    
    interval->l = x[0];
    interval->r = x[1];
    return 1;
}

int main() {
    scanf("%d", &n);
    
    double min_y = 1e9, max_y = -1e9;
    
    for (int i = 0; i < n; i++) {
        scanf("%lf%lf%lf%lf%lf%lf", 
              &tris[i].p1.x, &tris[i].p1.y,
              &tris[i].p2.x, &tris[i].p2.y,
              &tris[i].p3.x, &tris[i].p3.y);
        
        // 更新y坐标范围
        min_y = fmin(min_y, fmin(tris[i].p1.y, fmin(tris[i].p2.y, tris[i].p3.y)));
        max_y = fmax(max_y, fmax(tris[i].p1.y, fmax(tris[i].p2.y, tris[i].p3.y)));
        
        // 收集所有顶点
        points[m++] = tris[i].p1;
        points[m++] = tris[i].p2;
        points[m++] = tris[i].p3;
    }
    
    // 添加所有三角形边的中点
    for (int i = 0; i < n; i++) {
        Point p1 = tris[i].p1, p2 = tris[i].p2, p3 = tris[i].p3;
        points[m++] = (Point){(p1.x + p2.x) / 2, (p1.y + p2.y) / 2};
        points[m++] = (Point){(p2.x + p3.x) / 2, (p2.y + p3.y) / 2};
        points[m++] = (Point){(p3.x + p1.x) / 2, (p3.y + p1.y) / 2};
    }
    
    // 提取所有唯一的y坐标
    double ys[MAX_POINTS * 2];
    int k = 0;
    for (int i = 0; i < m; i++) {
        ys[k++] = points[i].y;
    }
    qsort(ys, k, sizeof(double), compareDoubles);
    
    // 去重
    int new_k = 1;
    for (int i = 1; i < k; i++) {
        if (ys[i] - ys[new_k - 1] > EPS) {
            ys[new_k++] = ys[i];
        }
    }
    k = new_k;
    
    // 确保覆盖整个范围
    if (k == 0) {
        printf("0.00\n");
        return 0;
    }
    
    // 加密扫描线：在每对相邻y坐标之间插入更多采样点
    double dense_ys[MAX_SCANLINES];
    int dense_k = 0;
    double max_step = 0.01; // 最大步长，控制精度
    
    for (int i = 0; i < k - 1; i++) {
        double y1 = ys[i];
        double y2 = ys[i + 1];
        double dy = y2 - y1;
        
        dense_ys[dense_k++] = y1;
        
        if (dy > max_step + EPS) {
            int steps = (int)(dy / max_step) + 1;
            double step = dy / steps;
            
            for (int j = 1; j < steps; j++) {
                dense_ys[dense_k++] = y1 + j * step;
            }
        }
    }
    
    dense_ys[dense_k++] = ys[k - 1];
    
    // 使用加密后的扫描线计算面积
    double area = 0;
    for (int i = 0; i < dense_k - 1; i++) {
        double y1 = dense_ys[i];
        double y2 = dense_ys[i + 1];
        double mid_y = (y1 + y2) / 2;
        double dy = y2 - y1;
        
        if (dy < EPS) continue;
        
        // 收集所有三角形在mid_y处的区间
        int interval_count = 0;
        for (int j = 0; j < n; j++) {
            Interval interval;
            if (getTriangleInterval(mid_y, tris[j], &interval)) {
                intervals[interval_count++] = interval;
            }
        }
        
        if (interval_count == 0) continue;
        
        // 合并区间
        qsort(intervals, interval_count, sizeof(Interval), compareIntervals);
        double total_length = 0;
        double current_l = intervals[0].l;
        double current_r = intervals[0].r;
        
        for (int j = 1; j < interval_count; j++) {
            if (intervals[j].l <= current_r + EPS) {
                current_r = fmax(current_r, intervals[j].r);
            } else {
                total_length += current_r - current_l;
                current_l = intervals[j].l;
                current_r = intervals[j].r;
            }
        }
        total_length += current_r - current_l;
        
        area += total_length * dy;
    }
    
    printf("%.2lf\n", area);
    
    return 0;
}
