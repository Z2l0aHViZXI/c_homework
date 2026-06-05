#include <stdio.h>  
void swap(int *x,int *y)
{int t=*x;
 *x=*y;
 *y=t;
}
int input(int *a,int n)
{int i;
 for(i=0;i<n;i++)
 {scanf("%d",&a[i]);
 }
 return 0;
}
int output(int *a,int n)
{int i;
 for(i=0;i<n;i++)
 {printf("%d,",a[i]);
 }
 printf("\n");
return 0;
}
int main()  
{int n,k,a[100],b[100];  
 scanf("%d",&n);  
 input(a,n);  
 input(b,n);  
 for(k=0;k<n;k++)  
 {if(a[k]>b[k])   
  swap(&a[k],&b[k]);   
 }  
 output(a,n);  
 output(b,n);   
 return 0;  
}
