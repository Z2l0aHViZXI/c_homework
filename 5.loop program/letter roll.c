#include<stdio.h>
main()
{char a;
 scanf("%c",&a);
 for(int i=0;i<26;i++)
 {printf("%c",a);
 a++;
 if((a>'Z'&&a<'a')||a>'z')
 {a=(a<='Z'+1)?'A':'a';}}
 printf("\n");
return 0;
}
