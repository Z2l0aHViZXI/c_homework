#include<stdio.h>
main()
{int a;
 scanf("%d",&a);
 a%100==0?(a%400==0?printf("%d is a leap year.\n",a):printf("%d is not a leap year.\n",a)):(a%4==0?printf("%d is a leap year.\n",a):printf("%d is not a leap year.\n",a));
return 0;
}
