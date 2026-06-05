#include <stdio.h>
#include <stdlib.h>
main()
{int x,y,a,a0,b,A=0,B=1,n,dt;
 scanf("%d%d%d",&x,&y,&n);
 long long D=abs((long long)A*y-(long long)x*B);
     for(b=1;b<=n;++b){
         a0=(long long)x*b/y;
         for(dt=-1;dt<=1;++dt){
         a=a0+dt;
         if(a<0)continue;
         long long d=abs((long long)a*y-(long long)x*b);
         if(d*B<D*b){ //||(d*B==D*b&&b<B)||(d*B==D*b&&b==B&&a<A)ÎÞÐèÅÐ¶Ï 
         D=d;A=a;B=b;}}}
 printf("%d/%d\n",A,B);
return 0;
}

