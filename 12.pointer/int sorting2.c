#include <stdio.h>  
void sort(int *p, int n, int (*pf)(int a, int b))
{int i,j,t;
 for(i=0;i<n;i++)
 {for(j=0;j<n-1-i;j++)
  {if(pf(p[j],p[j+1])<0)
   {t=p[j];
    p[j]=p[j+1];
    p[j+1]=t;
   }
  }
 }
}
int input(int *p, int n)
{int i;
 for(i=0;i<n;i++)
 {scanf("%d",&p[i]); 
 }
}
int output(int *p, int n)
{int i;
 for(i=0;i<n;i++)
 {printf("%d,",p[i]);
 }
 printf("\n");
}
int up(int a, int b)
{return a<b?1:(a>b?-1:0);
}
int down(int a, int b)
{return a<b?-1:(a>b?1:0);
}
int main()  
{  
    int n, flag, a[100];  
    scanf("%d%d", &n, &flag);
    input(a, n);  
    if ( flag==0 )  
        sort(a, n, up);
    else   
        sort(a, n, down);  
    output(a, n);  
    return 0;  
}
