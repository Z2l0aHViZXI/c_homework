#include<stdio.h>
#include<string.h>
void abb(char *s,char *r)
{int i,j,c;
 for(i=0;i<strlen(s);i++)
 {if(islower(s[i]))
  {c=1;
   while(s[i]==s[i+1])
   {c++;
    i++;
   }
   if(c>1){printf("%d%c",c,s[i]);}
   else{putchar(s[i]);
   }
  }else
   {putchar(s[i]); 
   }
 }
 printf("\n");
}
main()
{char s[100],r[100];
 scanf("%s",s);
 abb(s,r);
return 0;
}
