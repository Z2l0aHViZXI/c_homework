#include<stdio.h>
#include<ctype.h>
main()
{int n,i,j,x;
 char c;
 scanf("%d %c",&n,&c);
 if(islower(c))
 {c-=32;
 }
 if(n%2==0||!isupper(c))
 {printf("Input error!\n");
  return 0;
 }
 for(i=0;i<n;i++)
 {for(j=0;j<n;j++)
  {if(i==0||i==n-1)
   {x=c+i+j;
   }else
    {if(j==0||j==n/2||j==n-1)
     {x=c+i+j;
	 }else
	  {x=' ';
	  }
	}
	if(x!=' ')
	{x='A'+(x-'A')%26;
    }
	 printf("%c",(char)x);
  }
  printf("\n");
 }
return 0;
}
