#include<stdio.h>
main()
{int N,M,a,b=0,i;
 scanf("%d%d",&N,&M);
 int s[1000]={0};
 for(i=0;i<M;i++)
 {scanf("%d",&a);
  s[a]=1;
 }
 for(i=0;i<N;i++)
 {if(s[i]==0)
  {printf("%d ",i);
   b++;
  }
 }
 if(b==0)
 {printf("Go!");
 }
 printf("\n");
return 0;
}
