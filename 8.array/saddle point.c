#include<stdio.h>
main()
{int m,n,a[100][100],i,j,x,y,s=0;
 scanf("%d%d",&m,&n);
 for(i=0;i<m;i++)
 {for(j=0;j<n;j++)
  {scanf("%d",&a[i][j]);
  }
 }
 for(i=0;i<m;i++)
 {int r=a[i][0],t;
  for(j=1;j<n;j++)
  {if(a[i][j]>r)
   {r=a[i][j];
    x=j;
   }
  }
  for(j=0;j<m;j++)
  {if(a[j][x]<r)
   break;
   if(j==m-1)
   {printf("Point:a[%d][%d]==%d\n",i,x,r);
    s++;
   }
  }
 }
  if(!s)printf("No Point\n");
return 0; 
}
