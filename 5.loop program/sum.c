#include<stdio.h>
main()
{int m,n,i,s=0;
 scanf("%d%d",&n,&m);
 for(i=n;i<=m;i++)
 {s+=i;}
 printf("The sum from %d to %d is %d.\n",n,m,s);
return 0;
}
