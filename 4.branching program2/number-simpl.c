#include<stdio.h>
main()
{int i,a,b;
 scanf("%d",&i);
 b=i%10,a=(i-b)/10;
 char*teens[]={"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
 char*tens[]={"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
 char*ones[]={"","-one","-two","-three","-four","-five","-six","-seven","-eight","-nine"};
 if(a==1){printf("%s",teens[b]);
 }else{printf("%s",tens[a]);
  printf("%s",ones[b]);}
printf("\n");
return 0;
}
