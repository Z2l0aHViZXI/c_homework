#include<stdio.h>
main()
{int a,b,a1[10][10],a2[10][10],m,n[10][10]={0},i,j,r=0;
 scanf("%d*%d",&a,&b);
 for(j=0;j<b;j++)
 {for(i=0;i<a;i++)
  {scanf("%d",&a1[i][j]);
  }
 }
 for(j=0;j<b;j++)
 {for(i=0;i<a;i++)
  {scanf("%d",&a2[i][j]);
  }
 }
 for(j=0;j<b;j++)
 {for(i=0;i<a;i++)
  {m=a1[i][j]||a2[i][j];
   n[i][j]=a1[i][j]&&a2[i][j];
   if(m>0){r++;}
  }
 }
  printf("ÑÌ»¨±¬Õ¨·¶Î§Îª%d.\n",r);
 for(j=0;j<b;j++)
 {for(i=0;i<a;i++)
  {printf("%d%s",n[i][j],(i==a-1)?"\n":" ");
  }
 }
return 0;
}
