#include<stdio.h>
main()
{int year,month,day,week,a;
 scanf("%d%d%d",&year,&month,&day);
 if(month==1||month==2){year--;
 month+=12;}
 week=(day+26*(month+1)/10+year%100+(year%100)/4+(year/100)/4+5*(year/100))%7;
 if (week==0){a=6;
 }else{a=week-1;}
 printf("%d\n",a);
return 0;
}
