#include<stdio.h>
main()
{int n,m,k,i,s=1;
 scanf("%d%d%d",&n,&m,&k);
 int a[n],b[n];double c[n]; 
 for(i=1;i<n;i++)
 {scanf("%d%d",&a[i],&b[i]);
  k+=a[i]-b[i];
  c[i]=(double)k/m;
 }
 for(i=1;i<n;i++)
 {printf("%.3f\n",c[i]);
  if(c[i]<c[s])
  {s=i;
  }
 }
 for(i=1;i<n;i++)
 {if(c[i]==c[s])
  {printf("%d,",i);
  }
 }
 printf("\n");
return 0; 
} 
