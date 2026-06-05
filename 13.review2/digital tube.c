#include<stdio.h>
#include<string.h>
const unsigned char code[]={0x7D,0x50,0x37,0x57,0x5A,0x4F,0x6F,0x54,0x7F,0x5F};
main()
{int a,i,d;
 while(scanf("%d",&a)==1)
 {if(a==0){break;}
  char n[6];
  sprintf(n,"%05d",a);
  for(i=0;i<5;i++)
  {d=n[i]-'0';
   printf("%02X%c",code[d],i==4?'\n':' ');
  }
 }
return 0;
}
