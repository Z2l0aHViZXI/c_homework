#include <stdio.h>  
void sort(int *a, int n,int flag)
{int i,j,t;
 for(i=0;i<n;i++)
 {for(j=0;j<n-1-i;j++)
  {if(flag==0)
   {if(a[j]>a[j+1])
    {t=a[j];
     a[j]=a[j+1];
     a[j+1]=t;
	}
   }else if(flag==1)
    {if(a[j]<a[j+1])
     {t=a[j];
      a[j]=a[j+1];
      a[j+1]=t;
	 }
	}
  }
 }
} 
int input(int *a,int n)
{int i;
 for(i=0;i<n;i++)
 {scanf("%d",&a[i]);
 }
}
int output(int *a,int n)
{int i;
 for(i=0;i<n;i++)
 {printf("%d,",a[i]);
 }
 printf("\n");
}
int main()  
{  
    int n, flag, a[100];  
    scanf("%d%d", &n, &flag);  
    input(a, n);  
    sort(a, n, flag);
    output(a, n);  
    return 0;  
}
