#include<stdio.h>
main()
{int m=1,n,i,j,k,k0,a;
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {for(j=0;j<n;j++)
  {k=i<j?i:j;
   k=k<n-1-i?k:n-1-i;
   k=k<n-1-j?k:n-1-j;
   k0=4*k*(n-k)+1;
   a=n-2*k;
   if(i==k)
   {m=k0+j-k;
   }else if(j==n-1-k)
    {m=k0+a-1+i-k;
	}else if(i==n-1-k)
	 {m=k0+2*a+n-k-j-3;
	 }else
	  {m=k0+3*a+n-k-i-4;
	  }
   printf("%3d",m);
  }
  printf("\n");
 }
return 0;
} 
