#include<stdio.h>
#include<string.h>
main()
{char n[10],s[100];
 int i,l,lc,f;
 scanf("%s%d",n,&l);
 FILE *fp=fopen(n,"r");
 if(fp==NULL)
 {printf("File Name Error.\n");
  return 1;
 }
 for(lc=1;fgets(s,sizeof(s),fp)!=NULL;lc++)
 {if(lc==l)
  {s[strcspn(s,"\n")]=0;
   puts(s);
   return 0;
  }
 }
 printf("Line No Error.\n");
 fclose(fp);
}
