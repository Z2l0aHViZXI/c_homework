#include<stdio.h>
main()
{int h,i,j;
 scanf("%d",&h);
 for(i=1;i<=h;i++)
 {for(j=0;j<i-1;j++)
  {printf(" ");
  }
  if(i==1||i==h)
  {for(j=1;j<=2*h+1-2*i;j++)
   {printf("*");
   }
  }
  else
  {printf("*");
   for(j=1;j<=2*h-1-2*i;j++)
   {printf(" ");
   }
   printf("*");
  }
  printf("\n");
 }
return 0;
}
