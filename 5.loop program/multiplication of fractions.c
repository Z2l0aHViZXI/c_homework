#include<stdio.h>
long long gcd(long long x,long long y){for(;y!=0;){long long z=x%y;x=y;y=z;}
return x;}
main()
{long long a,b,A=1,B=1,g,i,n;
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {scanf("%lld%lld",&a,&b);
  g=gcd(a,b);a/=g,b/=g;
  g=gcd(a,B);a/=g,B/=g;
  g=gcd(b,A);b/=g,A/=g;
  A*=a,B*=b;}
 if(B==1){printf("%lld\n",A);
 }else printf("%lld/%lld\n",A,B);
return 0;
}
