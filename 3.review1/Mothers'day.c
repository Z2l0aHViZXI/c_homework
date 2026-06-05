#include<stdio.h>
main()
{int year,i,week;
 scanf("%d",&year);
 for(i=8;i<=14;i++)
 {week=(i+2*5+3*6/5+year+year/4-year/100+year/400)%7;
 if(week==6){
 printf("%d年的母亲节是5月%d日。\n",year,i);}}
return 0;
}
