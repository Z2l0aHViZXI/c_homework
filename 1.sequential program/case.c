#include<stdio.h>
main()
{char ch;
 scanf("%c",&ch);
 ch=ch^(32*((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')));
 printf("%c\n",ch);
 return 0;
}
