#include<stdio.h>
main()
{int a,b,c,d,w,x,y,z,n;
 scanf("%d,%d,%d,%d",&a,&b,&c,&d);
 scanf("%d",&n);
 for(w=1;w<=n/a;w++)
 {for(x=w;x<=n/b;x++)
  {for(y=x;y<=n/c;y++)
   {for(z=y;z<=n/d;z++)
    {if(a*w+b*x+c*y+d*z==n)
     {printf("%d,%d,%d,%d\n",w,x,y,z);
	 }
	}
   }
  }
 }
return 0;
}
