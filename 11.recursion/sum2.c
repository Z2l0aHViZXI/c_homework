#include<stdio.h>
int s(int n,int m)
{if(n==m)
 {return n;
 }else
 {return n+s(n+1,m);
 }
}
main()
{int n,m,i;
 scanf("%d%d",&n,&m);
 printf("The sum from %d to %d is %d.\n",n,m,s(n,m));
return 0;
}
