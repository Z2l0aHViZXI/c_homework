#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{return *(int*)a-*(int*)b;
}
main()
{int n,m,a[100],b[100],A=0,B=0,i,j;
 scanf("%d%d",&n,&m);
 for(i=0;i<n;i++)
 {scanf("%d",&a[i]);
 }
 for(i=0;i<m;i++)
 {scanf("%d",&b[i]);
 }
 qsort(a,n,sizeof(int),cmp);
 qsort(b,m,sizeof(int),cmp);
 i=0,j=0; 
 while(i<n&&j<m)
 {if(b[j]>=a[i])
  {A++;
   B+=b[j];
   i++;
   j++;
  }else
   {j++;
   }
 }
 if(A>=n)
 {printf("%d\n",B);
 }
 else
 {printf("bit is doomed!\n");
 }
return 0;
} 
