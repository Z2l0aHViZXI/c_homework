#include<stdio.h>
#include<string.h>
main()
{int a,r,s;char R[50],S[50];
 scanf("%d",&a);
 s=a%10,r=(a-s)/10;
 if(r==1){strcpy(R,"unreadable");
 }else if(r==2){strcpy(R,"barely readable, occasional words distinguishable");
 }else if(r==3){strcpy(R,"readable with considerable difficulty");
 }else if(r==4){strcpy(R,"readable with practically no difficulty");
 }else if(r==5){strcpy(R,"perfectly readable");
 }else{};
 if(s==1){strcpy(S,"Faint signals, barely perceptible");
 }else if(s==2){strcpy(S,"Very weak signals");
 }else if(s==3){strcpy(S,"Weak signals");
 }else if(s==4){strcpy(S,"Fair signals");
 }else if(s==5){strcpy(S,"Fairly good signals");
 }else if(s==6){strcpy(S,"Good signals");
 }else if(s==7){strcpy(S,"Moderately strong signals");
 }else if(s==8){strcpy(S,"Strong signals");
 }else if(s==9){strcpy(S,"Extremely strong signals");
 }else{};
 printf("%s, %s.\n",S,R);
return 0;
}
