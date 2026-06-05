#include<stdio.h>
main()
{int m,n,i;
 scanf("%d",&n);
 for(i=1;i<=20&&n!=1;i++)
 {if(n%2!=0)
  {m=3*n+1;
   printf("%d*3+1=%d\n",n,m);}
  else{m=n/2;
       printf("%d/2=%d\n",n,m);}
  n=m;}
return 0;
} 
