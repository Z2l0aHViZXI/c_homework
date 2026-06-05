#include<stdio.h>
#include<string.h> 
#include<ctype.h>
int cmp(const void *a,const void *b)
{char c1=*(const char*)a,c2=*(const char*)b;
 int t1,t2;
 if(isdigit(c1))
  {t1=0;
  }else if(islower(c1))
   {t1=1;
   }else if(isupper(c1))
    {t1=2;
	}
 if(isdigit(c2))
  {t2=0;
  }else if(islower(c2))
   {t2=1;
   }else if(isupper(c2))
    {t2=2;
	}
 return t1==t2?c2-c1:t1-t2;
}
main()
{char s[50];
 gets(s);
 qsort(s,strlen(s),sizeof(char),cmp);
 printf("%s\n",s);
return 0;
}
