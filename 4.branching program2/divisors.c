#include<stdio.h>
main()
{long N,M,a,b,i;
 scanf("%ld%ld",&N,&M);
 b=N%M,a=(N-b)/M;
 i=(N-N%a)/a-(N-N%(a+1))/(a+1);
 printf("%d\n",i);
return 0;
}
