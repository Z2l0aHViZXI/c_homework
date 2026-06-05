#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{return (*(int*)a-*(int*)b);
}
main()
{int N,i,*x,*y,*x1;
 scanf("%d",&N);
 x=(int*)malloc(N*sizeof(int));
 y=(int*)malloc(N*sizeof(int));
 x1=(int*)malloc(N*sizeof(int));
 for(i=0;i<N;i++)
 {scanf("%d%d",&x[i],&y[i]);
 }
 qsort(y,N,sizeof(int),cmp);
 long long c1=0;
 int Y=y[N/2];
 for(i=0;i<N;i++)
 {c1+=abs(y[i]-Y);
 }
 qsort(x,N,sizeof(int),cmp);
 for(i=0;i<N;i++)
 {x1[i]=x[i]-i;
 }
 qsort(x1,N,sizeof(int),cmp);
 int X=x1[N/2];
 long long c2=0;
 for(i=0;i<N;i++)
 {int X1=X+i;
  c2+=abs(x[i]-X1);
 }
 long long c=c1+c2;
 printf("%lld\n",c);
free(x);free(y);free(x1);
return 0;
}
