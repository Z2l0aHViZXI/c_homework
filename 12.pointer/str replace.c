#include<stdio.h>
#include<string.h>
void replace(char *r,const char *s,const char *t,const char *str)
{int lt=strlen(t),lstr=strlen(str),c=0;
 char tp[200],*p;
 strncpy(tp,s,200);
 tp[200]='\0';
 if(lt==0)
 {strncpy(r,s,200);
  r[200]='\0';
  return;
 }
 while((p=strstr(tp,t))!=NULL&&c<200)
 {int pi=p-tp;
  strncpy(r+c,tp,pi);
  c+=pi;
  strncpy(r+c,str,lstr);
  c+=lstr;
  memmove(tp,tp+pi+lt,strlen(tp)-pi-lt+1);
 }
 strncpy(r+c,tp,strlen(tp));
 c+=strlen(tp);
 r[c]='\0';
}
main()
{char r[200],s[200],t[20],str[20];
 fgets(s,200,stdin);
 s[strcspn(s,"\n")]='\0';
 fgets(t,20,stdin);
 t[strcspn(t,"\n")]='\0';
 fgets(str,20,stdin);
 str[strcspn(str,"\n")]='\0';
 replace(r,s,t,str);
 printf("%s\n",r);
return 0;
}
