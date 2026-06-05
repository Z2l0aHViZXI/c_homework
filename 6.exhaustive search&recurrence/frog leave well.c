#include<stdio.h>
main()
{int m,n,x,d,h=0;
 scanf("%d%d%d",&n,&m,&x);
 for(d=1;;d++&&n--)
 {h+=n;
  if(h>=x)
  {printf("青蛙能爬出井，且第 %d 天爬出井。\n",d);
   goto out;}
  else
  {h-=m;
   if(h<0)
   {printf("青蛙不能爬出井。\n");
    goto out;}
  }
 }
out:return 0;
}
