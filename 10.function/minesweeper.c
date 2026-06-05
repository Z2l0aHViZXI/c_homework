#include<stdio.h>
main()
{int n,m,i,j,k,I,J,N=1,C,x[]={-1,-1,-1,0,0,1,1,1},y[]={-1,0,1,-1,1,-1,0,1};char g[100][100];
 while(scanf("%d%d",&n,&m)==2&&n!=0&&m!=0)
 {if(N>1)putchar('\n');
  for(i=0;i<n;i++)
  {scanf("%s",g[i]);
  }
   printf("Field #%d:\n",N++);
   for(i=0;i<n;i++)
   {for(j=0;j<m;j++)
    {if(g[i][j]=='*')
     {putchar('*');
	 }else
	  {C=0;
	   for(k=0;k<8;k++)
	   {I=i+x[k];J=j+y[k];
	    if(I>=0&&I<n&&J>=0&&J<m)
	    {if(g[I][J]=='*')C++;
		}
	   }
	   printf("%d",C);
	  }
	}
	putchar('\n');
   }
 }
return 0;
}
