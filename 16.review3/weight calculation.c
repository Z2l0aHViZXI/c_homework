#include<stdio.h>
int sum(int w,int n,int *p)
{int i;
 for(i=0;i<n;i++)
 {w+=(n-i)*p[i];
 } 
 return w;
}
main()
{int w,n,p[30000],i,s;
 scanf("%d%d",&w,&n);
 for(i=0;i<n;i++)
 {scanf("%d",&p[i]);
 }
 for(i=0;i<n;i++)
 {s=sum(w,i+1,p);
  printf("%d%c",s,i<n-1?' ':'\n');
 }
return 0;
}
