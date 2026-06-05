#include<stdio.h>
main()
{int a,b,c=1,i;
 scanf("%d/%d",&a,&b);
 printf("0.");
 for(i=0;c!=0&&i<200;i++)
 {c=(10*a)%b;
  printf("%d",(10*a-c)/b);
  a=c;}
 printf("\n");
return 0; 
}
