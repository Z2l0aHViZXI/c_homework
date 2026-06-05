#include<stdio.h>
main()
{int n,i,j;char a,m;
 scanf("%d %c",&n,&a);
 if(a<'A'||a>'Z')
 {printf("input error.\n");
   return 0;
 }
 m=a+n-1;
  for(i=1;i<=2*n-1;i++)
   {if(i<=n)
    {for(j=1;j<=i-1;j++)
    {printf(" ");
	}
    }else
     {for(j=1;j<=2*n-1-i;j++)
      {printf(" ");
      }
     }
	if(m<'A')
    {m+=26;
	}
	if(m>'Z')
	{m-=26;
	}
    printf("%c",m);
    if(i<=n)
    {for(j=1;j<=2*n-1-2*i;j++)
     {printf(" ");
	 }
    }else
    {for(j=1;j<=-2*n-1+2*i;j++)
     {printf(" ");
     }
    }
    if(i!=n)
	{printf("%c",m);}
	printf("\n");
    m--;
    }
  return 0;
} 
