#include<stdio.h>
#include<string.h>
#include<ctype.h>
int cmp(const void *a,const void *b)
{char A=*(char*)a,B=*(char*)b;
 if(islower(A)&&isupper(B))
 {return -1;
 }
 if(isupper(A)&&islower(B))
 {return 1;
 }
 return A-B;
}
void sort(char *s,char *r)
{int i,j=0;
 for(i=0;s[i]!='\0';i++)
 {char c=s[i];
  if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
  {r[j++]=c;
  }
 }
 r[j]='\0';
 qsort(r,j,sizeof(char),cmp);
}
main()
{char s[1000],r[1000];
 fgets(s,sizeof(s),stdin);
 sort(s,r);
 printf("%s\n",r);
return 0;
}
