#include<stdio.h>
main()
{int n;
 scanf("%d",&n);
 if(n%8==0)
   {printf("%d,%d,%d\n",n*25/4,n*15/2,n*45/8);
   }else{printf("No change.\n");}
return 0;
}
