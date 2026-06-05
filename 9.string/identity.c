#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int leap(int a)
{return (a%4==0&&a%100!=0)||(a%400==0);
}
int date(int year,int month,int day)
{if(month<1||month>12)return 0;
 int a[]={31,28,31,30,31,30,31,31,30,31,30,31};
 if(month==2&&leap(year))a[1]=29;
 return day>=1&&day<=a[month-1];
}
char code(char* a)
{int w[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2},s=0,i,r;
 char c[]={'1','0','X','9','8','7','6','5','4','3','2'};
 for(i=0;i<17;i++)
 {s+=(a[i]-'0')*w[i];
 } 
 return c[s%11];
}
char* conv(char* a)
{char* b=(char*)malloc(19);
 strncpy(b,a,6);
 strncpy(b+6,(atoi(a+12)>=996?"18":"19"),2);
 strncpy(b+8,a+6,2);
 strncpy(b+10,a+8,4);
 strncpy(b+14,a+12,3);
 b[17]=code(b),b[18]='\0';
return b;
}
int valid(char* b)
{int i;
 if(strlen(b)!=18)return 0;
 for(i=0;i<17;i++)
 if(!(isdigit(b[i])))return 0;
 char x=b[17];
 if(!(isdigit(x)||x=='X'))return 0;
 int year=atoi(strncpy((char[5]){0},b+6,4));
 int month=atoi(strncpy((char[3]){0},b+10,2));
 int day=atoi(strncpy((char[3]){0},b+12,2));
 if(!date(year,month,day))return 0;
 if(x!=code(b))return 0;
return 1;
}
main()
{int n,i;char id[20];
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {scanf("%s",id);
  int l=strlen(id);
  if(l==15)
  {char* b=conv(id);
   printf("%s\n",b);
   free(b);
  }else if(l==18)
   {printf(valid(id)?"Valid\n":"Invalid\n");
   }else
    {printf("Invalid\n");
	}
 }
return 0;
}
