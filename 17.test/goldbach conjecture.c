#include<stdio.h>
int isprime(int x)
{int i;
 if(x<=1){return 0;}
 if(x==2){return 1;}
 for(i=2;i*i<=x;i++)
 {if(x%i==0)
  {return 0;
  }
 }
 return 1;
}
main()
{int n,i;
 scanf("%d",&n);
 for(i=2;i<=n/2;i++)
 {if(isprime(i)&&isprime(n-i))
  {printf("%d=%d+%d\n",n,i,n-i);
   return 0;
  }
 }
return 1;
}
