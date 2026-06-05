#include<stdio.h>
main()
{char n[80];
 int a,b;
 scanf("%s",n);
 FILE *fp=fopen(n,"r");
 fscanf(fp,"%d%d",&a,&b);
 printf("%d\n",a+b);
 fclose(fp);
 return 0; 
}
