#include<stdio.h>
main()
{int n,a=1,i,j;
 scanf("%d",&n);
 for(i=1;i<=n*n;i++)
 {printf("%3d",a);
  a++;
  if(i%n==0)
  {printf("\n");
  }
 }
return 0;
} 
