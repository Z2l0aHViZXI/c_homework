#include<stdio.h>
#include<string.h>
int p(char *s,int l,int r)
{if(l>=r)
 {return 1;
 }
 if(s[l]!=s[r])
 {return 0;
 }
 return p(s,l+1,r-1);
}
main()
{char s[100];
 scanf("%s",s);
 int l=strlen(s);
 if(p(s,0,l-1)==1)
 {printf("Yes\n");
 }else
  {printf("No\n");
  }
return 0;
}
