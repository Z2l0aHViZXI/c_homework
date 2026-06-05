#include<stdio.h>
main()
{int a,i,n=0;
 scanf("%d",&a);
 for(i=0;i<32;i++)
 {n+=a&1;
  a>>=1;
 }
 printf("%d\n",n);
return 0;
}
