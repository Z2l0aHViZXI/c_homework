#include<stdio.h>
main()
{int i,j=0,e[128]={0};char s[101],r[101];
 scanf("%100s",s);
 while(s[i])
 {unsigned c=s[i];
  if(!e[c])
  {e[c]=1;
   putchar(c);
  }
  i++;
 }
 putchar('\n');
return 0;
}
