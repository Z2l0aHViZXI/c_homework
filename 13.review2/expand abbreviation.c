#include<stdio.h>
#include<string.h>
#include<ctype.h>
int T(char a,char b)
{if(((isupper(a)&&isupper(b))||(islower(a)&&islower(b))||(isdigit(a)&&isdigit(b)))&&a<b)return 1;
 return 0;
}
main()
{char s[1000],r[1000];
 int i,j=0,k,l;
 fgets(s,sizeof(s),stdin);
 l=strlen(s);
 for(i=0;i<l;i++)
 {if(s[i]=='-'&&i>0&&i<l-1&&T(s[i-1],s[i+1])>0)
  {for(k=s[i-1]+1;k<s[i+1];k++)
    {r[j++]=k;
	}
  }else
   {r[j++]=s[i];
   }
 }
 r[j]='\0';
 printf("%s",r);
return 0;
}
