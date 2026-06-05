#include<stdio.h>
#include<string.h>
main()
{char s1[100],s2[100];
 scanf("%s%s",s1,s2);
 int l1=strlen(s1),l2=strlen(s2),i,l,s;
 for(l=(l1<l2)?l1:l2;l>=1;l--)
 {s=1;
  for(i=0;i<l;i++)
  {if(s1[l1-l+i]!=s2[i])
   {s=0;
    {break;
    }
   }
  }
  if(s==1)
  break;
 }
 for(i=0;i<l;i++)
 {putchar(s2[i]);
 }
 putchar('\n');
return 0;
}
