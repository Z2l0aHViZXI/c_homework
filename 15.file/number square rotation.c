#include<stdio.h>
main()
{int n,i,j;
 scanf("%d",&n);
 for(i=0;i<2*n-1;i++)
 {for(j=0;j<(i<n?i+1:2*n-1-i);j++)
  {printf("%3d",i<n?n-i+(n+1)*j:(i+1-n)*n+1+(n+1)*j);
  }
  printf("\n");
 }
 return 0;
}
