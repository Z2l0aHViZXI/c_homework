#include<stdio.h>
#include<math.h>
typedef unsigned long long ull;
int ga(ull now[],ull next[],int count,int k)
{ull K=pow(10,k),i,I,nextc=0;
 for(i=0;i<count;i++)
 {ull a=now[i],m=(a*a-a)/K;
  for(I=0;I<K;I++)
  {if(((2*a-1)*I)%K==(K-m%K)%K)
   {next[nextc]=a+I*K;
    nextc++;
   }
  }
 }
return nextc;
}
int main()
{int n,m=0,count=3,i,j,k=1,nowc,nextc;
 scanf("%d",&n);
 ull now[100]={1,5,6},next[100],r[100];
 while(k<n)
 {nextc=ga(now,next,count,k);
 for(i=0;i<count;i++)
 {now[i]=next[i];
 }
 k*=2;
 }
 ull min=(ull)pow(10,n-1),max=(ull)(pow(10,n)-1),N=(ull)pow(10,n);
 for(i=0;i<count;i++)
 {ull num=now[i]%N;
  if(num>=min&&num<=max)
  {unsigned sq=num*num;
   if(sq%N==num)
   {r[m++]=num;
   }
  }
 }
 for(i=0;i<m-1;i++)
 {for(j=0;j<m-1-i;j++)
  {if(r[j]>r[j+1])
   {ull t=r[j];
    r[j]=r[j+1];
    r[j+1]=t;
   }
  }
 }
 for(i=0;i<m;i++)
 {printf("%llu\n",r[i]);
 }
return 0;
} 
