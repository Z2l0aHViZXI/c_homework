#include<stdio.h>
main()
{int a[6][6],b[6][6],i,j;
 for(i=0;i<6;i++)
 {for(j=0;j<6;j++)
  {scanf("%d",&a[i][j]);
  }
 }
 for(i=0;i<6;i++)
 {for(j=0;j<6;j++)
  {b[i][j]=a[j][5-i];
   printf("%d%s",b[i][j],(j==5)?"\n":" ");
  }
 }
return 0;
} 
