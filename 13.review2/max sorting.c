#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{return *(char*)b-*(char*)a;
} 
main()
{char n[200];
 fgets(n,200,stdin);
 n[strcspn(n,"\n")]='\0';
 qsort(n,strlen(n),sizeof(char),cmp);
 printf("%s\n",n);
}
