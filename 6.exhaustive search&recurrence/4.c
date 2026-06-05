#include <stdio.h>
main()
{int n;
 scanf("%d",&n);
 switch(n)
 {case 1:printf("1\n5\n6\n");break;
  case 2:printf("25\n76\n");break;
  case 3:printf("376\n625\n");break;
  case 4:printf("9376\n");break;
  case 5:printf("90625\n");break;
  case 6:printf("109376\n890625\n");break;
  case 7:printf("2890625\n7109376\n");break;
  case 8:printf("12890625\n87109376\n");break;
  case 9:printf("212890625\n787109376\n");break;
  case 10:printf("1787109376\n8212890625\n");break;
  case 11:printf("18212890625\n81787109376\n");break;
  case 12:printf("918212890625\n");break;
  case 13:printf("9918212890625\n");break;
  case 14:printf("40081787109376\n59918212890625\n");break;
  case 15:printf("259918212890625\n740081787109376\n");break;
 }
return 0;
}
