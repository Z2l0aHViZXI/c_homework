#include<stdio.h>
#include<stdlib.h>
char* read(int *l)
{int b=512;*l=0;
 char *s=(char*)malloc(b*sizeof(char)),c;
 while((c=getchar())!='\n'&&c!=EOF)
 {if(*l>=b-1){b*=2;s=(char*)realloc(s,b);
 }
 s[(*l)++]=c;
 }
 s[*l]='\0';
return s;
}
main()
{
 int l1,l2,i=0,j=0,k;
 char *s1=read(&l1);
 char *s2=read(&l2);
 char *r=(char*)malloc(l1+l2+1);
 for(k=0;k<l1+l2;k++)
 {r[k]=(i<l1&&j<l2)?(s1[i]<s2[j]?s1[i++]:s2[j++]):(i<l1?s1[i++]:s2[j++]);
 } 
r[l1+l2]='\0';
printf("%s\n",r);
free(s1);free(s2);free(r);
return 0;
}
