#include<stdio.h>
main()
{int n;
 scanf("%d",&n);
 int t[n],i,L=0,l=0,r=0,m=0,s=0;
 for(i=0;i<n;i++)
 {scanf("%d",&t[i]);
 }
 for(i=0;i<n-1;i++)
 {if(t[i]>=t[i+1])
  {L=i+2-s;
   if(L>m)
   {m=L;
    l=s;
    r=i+1;
   }
  }else
   {s=i+1;
   }
 }
 printf("%d %d\n",l+1,r+1);
return 0;
}
