#include<stdio.h>
main()
{long long a,b,t,s;
 scanf("%lld*%lld%lld",&a,&b,&t);
 s=a*b*30*24*60*t/(8*1024);
 printf("%lld\n",s);
return 0;
}
