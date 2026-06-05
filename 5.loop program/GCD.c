#include<stdio.h>
main()
{int a,b,c,A,B; 
 scanf("%d%d",&a,&b);
 A=a,B=b;
 for(;b!=0;)
 {c=a%b;
  a=b;
  b=c;}
 printf("GCD(%d,%d)=%d\n",A,B,a);
return 0;
}
