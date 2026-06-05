#include<stdio.h>
main()
{int n,i,j;char a,m,o;
 scanf("%d %c",&n,&a);
 if(a>='A'&&a<='Z'){
 }else if(a>='a'&&a<='z')
 {a+='A'-'a';
 }else{printf("Input error!\n");
 return 0;}
 for(i=1;i<=n;i++)
 {if(i==1||i==n)
  {for(j=1;j<=n;j++)
   {m=a+i+j-2;
    if(m>'Z'){m-=26;}
    printf("%c",m);
    if(j!=n)
    {printf(" ");
	}else
	 {printf("\n");
	 }
   }
  }else
   {m=a+i-1;
    if(m>'Z'){m-=26;}
    printf("%c",m);
    for(j=1;j<=2*n-3;j++)
    {printf(" ");
	}
	o=(m+n-1>'Z')?m+n-27:m+n-1;
	printf("%c\n",o);
   }
 }
return 0;
} 
