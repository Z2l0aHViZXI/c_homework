#include <stdio.h>
#include <stdbool.h>
typedef struct {
    int year;
    int month;
    int day;
} Date;
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
int getDaysInMonth(int year, int month) {
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return days[month];
}
int getDaysDiff(Date start, Date end) {
    int days1 = 0;
    for (int y = 1; y < start.year; y++) {
        days1 += isLeapYear(y) ? 366 : 365;
    }
    for (int m = 1; m < start.month; m++) {
        days1 += getDaysInMonth(start.year, m);
    }
    days1 += start.day;
    int days2 = 0;
    for (int y = 1; y < end.year; y++) {
        days2 += isLeapYear(y) ? 366 : 365;
    }
    for (int m = 1; m < end.month; m++) {
        days2 += getDaysInMonth(end.year, m);
    }
    days2 += end.day;
    return days2 - days1;
}
int getWeekday(Date date) {
    int d = date.day;
    int m = date.month;
    int y = date.year;
    if (m < 3) {
        m += 12;
        y--;
    }
    int h = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400 + 1) % 7;
    return h;
}
int main() {
    Date initial = {2012, 4, 9};
    Date input;
    scanf("%d%d%d", &input.year, &input.month, &input.day);
    int daysDiff = getDaysDiff(initial, input);
    int weekday = getWeekday(input);
    if (weekday == 0 || weekday == 6) {
        printf("Free.\n");
        return 0;
    }
    int cycle = daysDiff / 91;
    int initial_rules[5][2] = {
        {3, 8},
        {4, 9},
        {5, 0},
        {1, 6},
        {2, 7}
    };
    int current_weekday = weekday - 1;
    int offset = cycle % 5;
    int rule_index = (current_weekday - offset + 5) % 5;
    
    int a = initial_rules[rule_index][0];
    int b = initial_rules[rule_index][1];
    
    printf("%d and %d.\n", a, b);
    
    return 0;
}
