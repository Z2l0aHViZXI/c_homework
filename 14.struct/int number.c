#include <stdio.h>  
struct nn  
{  int no;     
   int num;     
}; 
typedef struct nn DATA;  
#include<string.h>
#include<stdlib.h> 
int number( char * str, DATA a[])
{int i,j,c=0,id[100];
 char *t=strtok(str," ");
 while(t!=NULL&&c<100)
 {a[c].num=atoi(t);
  id[c]=c;
  a[c].no=0;
  c++;
  t=strtok(NULL," ");
 }
 for(i=0;i<c-1;i++)
 {for(j=0;j<c-1-i;j++)
  {int i1=id[j],i2=id[j+1],I;
   if(a[i1].num>a[i2].num)
   {I=i1;
    id[j]=id[j+1];
    id[j+1]=I;
   }
  }
 }
 for(i=0;i<c;i++)
 {a[id[i]].no=i+1;
 }
return c;
}
int main( )  
{     
   DATA b[100];    
   char sa[500];    
   int i, n;    
   gets( sa );   
   n = number( sa, b );   
   for ( i=0; i<n; i++ )   
       printf("%d %d\n", b[i].num, b[i].no );   
   return 0;  
}
