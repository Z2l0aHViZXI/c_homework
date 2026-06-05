#include<stdio.h>
main()
{int a,b,c,d,e,f,g,m,n;
 scanf("%d%d%d%d",&a,&b,&c,&d);
 e=a*d+b*c,f=b*d;
 if(e==1||e==-1){e=1;
 }else for(;f!=0;)
 {g=e%f;
  e=f;
  f=g;}
 m=(a*d+b*c)/e,n=b*d/e;
 printf("%d/%d\n",m,n);
return 0;
}
