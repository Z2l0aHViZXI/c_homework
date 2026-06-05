#include <stdio.h>
#include <stdbool.h>
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
int daysFromStart(int year, int month, int day) {
    int total = 0,y;
    for (y = 1900; y < year; y++) {
        if (isLeapYear(y)) {
            total += 366;
        } else {
            total += 365;
        }
    }
    int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},m;
    for (m = 0; m < month - 1; m++) {
        total += months[m];
        if (m == 1 && isLeapYear(year)) {
            total += 1;
        }
    }
    total += day;
    return total;
}

int main() {
    int startYear, startMonth, startDay;
    int endYear, endMonth, endDay;
    scanf("%d %d %d", &startYear, &startMonth, &startDay);
    scanf("%d %d %d", &endYear, &endMonth, &endDay);
    int startTotal = daysFromStart(startYear, startMonth, startDay);
    int endTotal = daysFromStart(endYear, endMonth, endDay);
    printf("%d\n", endTotal - startTotal);
    return 0;
}
