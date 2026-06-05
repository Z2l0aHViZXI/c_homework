#include<stdio.h>
main()
{int a,b;double x,y,k,t;
 scanf("%d%d%lf%lf",&a,&b,&x,&y);
 if(x*x/a+y*y/b!=1){printf("Input error!\n");
 }else{if(y==0){printf("x=%.6f\n",x);
       }else{k=-1.0*b*x/(a*y),t=y-k*x;
            if(k==0){printf("y=%.6f\n",y);
		    }else{if(t>0){printf("y=%.6fx+%.6f\n",k,t);
		          }else printf("y=%.6fx%.6f\n",k,t);}}}
return 0;
}
