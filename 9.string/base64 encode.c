#include<stdio.h>
#include<string.h>
#include<stdint.h>
const char b[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
main()
{int i,l;char a[71];
 scanf("%s",a);
 l=strlen(a);
 for(i=0;i<l;i+=3)
 {char b1=a[i],b2=(i+1<l)?a[i+1]:0,b3=(i+2<l)?a[i+2]:0;
  char g1=b1>>2,g2=((b1&0x03)<<4)|(b2>>4),g3=((b2&0x0F)<<2)|(b3>>6),g4=b3&0x3F;
  putchar(b[g1]);
  putchar(b[g2]);
  if(i+1<l)
  {putchar(b[g3]);
   if(i+2<l)
   {putchar(b[g4]);
   }else
    {putchar('=');
	}
  }else
   {putchar('=');putchar('=');
   }
 }
putchar('\n');
return 0;
}
