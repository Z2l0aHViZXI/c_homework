#include<stdio.h>
#include<math.h>
double Sqrt(double x,double p,double e)
{if(fabs(p*p-x)<e)
 {return p;
 }else
  {return Sqrt(x,(p+x/p)/2,e);
  }
}
main()
{double x,p,e;
 scanf("%lf%lf",&x,&e);
 printf("%.8f\n",Sqrt(x,x,e));
return 0;
}
