#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct CODE{
	char org;
	char rep;
}code;
main()
{code t[100];
 char n[10],c[10],r[4],s[100];
 scanf("%s%s",n,c);
 int i,j,count=0;
 FILE *fp1=fopen(n,"r"),*fp2=fopen(c,"r");
 while(fgets(r,sizeof(r),fp1)!=NULL)
 {if(r[1]==',')
  {t[count].org=r[0];
   t[count].rep=r[2];
   count++;
  }
 }
 while(fgets(s,sizeof(s),fp2)!=NULL)
 {for(i=0;s[i]!='\0';i++)
  {for(j=0;j<count;j++)
   {if(t[j].org==s[i])
    {s[i]=t[j].rep;
     break;
	}
   }
  }
  printf("%s",s);
 }
 fclose(fp1);
 fclose(fp2);
return 0;
}
