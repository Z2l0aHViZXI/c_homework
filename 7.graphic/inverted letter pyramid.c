#include<stdio.h>
main()
{int a,h,i,j,m=0;char x,n;
 scanf("%c%d%d",&x,&a,&h);
 char z=(x>='A'&&x<='Z')?'Z':'z';
 for(i=1;i<=h;i++)
 {for(j=1;j<=h-i;j++)
  {printf(" ");
  }
  n=x;
  for(j=1;j<=a+2*i-2;j++)
  {printf("%c",n);
   if(n==z){m++;}
   (j<(a+2*i-1)/2)?n--:((a%2==0&&j==a/2+i-1)?:n++);
   if(z=='Z')
   {n=(n<'A')?'Z':n;
    n=(n>'Z')?'A':n;
   }else{
   n=(n<'a')?'z':n;
   n=(n>'z')?'a':n;
   }
  }
  printf("\n");
 }
 printf("所建金字塔共使用%d个字母砖块%c\n",m,z);
return 0;
}
