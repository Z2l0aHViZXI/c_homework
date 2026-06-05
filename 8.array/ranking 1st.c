#include<stdio.h>
main()
{int a[10],i,j,m=0;
 for(i=0;i<10;i++)
 {scanf("%d",&a[i]);
 }
 for(i=0;i<10;i++)
 {if(a[i]>m)
  {m=a[i];
  }
 }
 for(i=0;i<10;i++)
 {if(a[i]==m)
  {printf("%d\n",i+1);
  }
 }
return 0;
} 
