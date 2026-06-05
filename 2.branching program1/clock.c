#include<stdio.h>
main()
{int a,b;float c,d,e;
 scanf("%d%d",&a,&b);
 c=(a==12)?b/2.0:30*a+b/2.0;
 d=6*b;
 e=(c>=d)?c-d:d-c;
 e=(e>180)?360-e:e;
 printf("At %d:%02d the angle is %.1f degrees.\n",a,b,e);
return 0;
} 
