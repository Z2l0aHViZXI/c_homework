#include<stdio.h>
main()
{int n,m=1,i;
 scanf("%d",&n);
 for(i=n-1;i>=1;i--)
 {m=2*(m+i);}
 if(m==1)
 {printf("The monkey got 1 peach in the first day.\n");}
 else printf("The monkey got %d peaches in the first day.\n",m);
return 0;
}
