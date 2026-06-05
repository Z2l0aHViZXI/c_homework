#include<stdio.h>
#include<stdlib.h>
main()
{int a,b,c,d,e,f,l1,r1,l2,r2,lt,rt;
 scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
 if(b==0){b=(e>a)?1:2;}
 if(d==0){d=(e>c)?1:2;}
 if(b==1){l1=(f>e&&e>a)?(e-a):(20-a-e);
 	l2=(e<a&&e<f)?(e+f-2):abs(e-f);
 }else if(b==2){
 	l1=(a>e&&e>f)?(a-e):(a+e-2);
 	l2=(e>a&&e>f)?(20-e-f):abs(e-f);}
 lt=l1+l2;
 if(d==1){r1=(f>e&&e>c)?(e-c):(20-c-e);
 	r2=(e<c&&e<f)?(e+f-2):abs(e-f);
 }else if(d==2){
 	r1=(c>e&&e>f)?(c-e):(c+e-2);
 	r2=(e>c&&e>f)?(20-e-f):abs(e-f);}
 rt=r1+r2;
 if(lt<rt){printf("left one\n");
 }else if(lt>rt){printf("right one\n");
       }else{printf("left one or right one\n");}
return 0;
}
