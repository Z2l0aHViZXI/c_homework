#include<stdio.h>
main()
{int m,n,a,b,c,i=0;
 scanf("%d%d",&n,&m);
 for(a=m/20;a>=0;a--)
 {for(b=m/12;b>=0;b--)
  {c=n-a-b; 
   if(20*a+12*b+8*c==m&&c>=0)
    {if(i==0){printf("KFC  McDonald  PissaHut\n");
                i=1;} 
	 printf("%d %d %d\n",a,b,c);
	}
  }
 }
if(i==0){printf("No Solution£¡\n");}
return 0;
} 
