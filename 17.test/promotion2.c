#include<stdio.h>
main()
{int p1,p2,p3,p4,p5,t,n,n1,n2,n3,n4,n5;
 scanf("%d%d%d%d%d%d%d",&p1,&p2,&p3,&p4,&p5,&t,&n);
 for(n1=1;n1<n;n1++)
 {for(n2=1;n2<n;n2++)
  {for(n3=1;n3<n;n3++)
   {for(n4=1;n4<n;n4++)
    {n5=n-n1-n2-n3-n4; 
	 if(p1*n1+p2*n2+p3*n3+p4*n4+p5*n5==t&&n5>0)
     {printf("%d,%d,%d,%d,%d\n",n1,n2,n3,n4,n5);
	 }
    }
   }
  }
 }
return 0;
}
