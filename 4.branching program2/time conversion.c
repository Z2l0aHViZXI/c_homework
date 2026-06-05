#include<stdio.h>
main()
{int t,d,dm,h,hm,m,s;
 scanf("%d",&t);
 dm=t%86400,hm=dm%3600,s=hm%60;
 d=(t-dm)/86400,h=(dm-hm)/3600,m=(hm-s)/60;
 printf("%d天%d小时%d分%d秒\n",d,h,m,s);
return 0;
}
