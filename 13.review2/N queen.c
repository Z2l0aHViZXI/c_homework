#include<stdio.h>
int m=0,ux[20]={0},uy[20]={0},uz[20]={0};
void b(int x,int n)
{if(x==n)
 {m++;
  return;
 }
 int i;
 for(i=0;i<n;i++)
 {int d1=x-i+n-1,d2=x+i;
  if(!ux[i]&&!uy[d1]&&!uz[d2])
  {ux[i]=1,uy[d1]=1,uz[d2]=1;
   b(x+1,n);
   ux[i]=0,uy[d1]=0,uz[d2]=0;
  }
 }
}
main()
{int n;
 scanf("%d",&n);
 b(0,n);
 printf("%d\n",m);
return 0;
}
