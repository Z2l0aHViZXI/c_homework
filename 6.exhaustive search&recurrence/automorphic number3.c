#include <stdio.h>
#include<math.h>
typedef unsigned long long ull;
ull pull(ull a,int n)
{ull m=1;int i;
 for(i=0;i<n;i++)
 {m*=a;
 }
return m;
}
int main()
{int n,m=0,i,j;
 scanf("%d",&n);
 ull pow2=pull(2,n),pow5=pull(5,n),A=pull(10,n-1),B=pull(10,n),x,a[3]={0},t;
 for(x=pow2;x<B;x+=pow2)
 {if((x-1)%pow5==0&&x>=A)
  a[m++]=x;
 }
 for(x=pow5;x<B;x+=pow5)
 {if((x-1)%pow2==0&&x>=A)
  a[m++]=x;
 }
 if(n==1){a[m++]=1;}
 for(i=0;i<m-1;i++)
 {for(j=0;j<m-1-i;j++)
  {if(a[j]>a[j+1])
   {t=a[j];
    a[j]=a[j+1];
    a[j+1]=t;}
  }
 }
 for(i=0;i<m;i++)
 {printf("%llu\n",a[i]);
 }
return 0;
}
