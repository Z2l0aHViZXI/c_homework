#include<stdio.h>
int GCD(int n,int m)
{if(m<=n&&n%m==0)
 {return m;
 }else if(n<m)
  {return GCD(m,n);
  }else
   {return GCD(m,n%m);
   }
}
main()
{int m,n;
 scanf("%d%d",&m,&n);
 printf("%d\n",GCD(m,n));
return 0;
}
