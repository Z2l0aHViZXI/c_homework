#include<stdio.h>
#include<math.h>
main()
{int a,b,c;double delta,x1,x2;
 scanf("%d%d%d",&a,&b,&c);
 if(a==0){if(b==0){printf("Input error!\n");
          }else{x1=-1.0*c/b;if(c==0){x1=0;
           }printf("x=%.6f\n",x1);}
 }else {delta=b*b-4.0*a*c;double sqrt_delta=sqrt(fabs(delta));
       if(fabs(delta)<1e-6){x1=-b/(2.0*a);
       printf("x1=x2=%.6f\n",x1);
       }else if(delta>1e-6){x1=(-b+sqrt_delta)/(2.0*a),x2=(-b-sqrt_delta)/(2.0*a);
       printf("x1=%.6f\nx2=%.6f\n",x1,x2);
	   }else{double real=-b/(2.0*a),imag=sqrt_delta/(2.0*a);
	         if(fabs(real)<1e-6){printf("x1=%.6fi\nx2=-%.6fi\n",imag,imag);
	         }else printf("x1=%.6f+%.6fi\nx2=%.6f-%.6fi\n",real,imag,real,imag);}}
return 0;
}
