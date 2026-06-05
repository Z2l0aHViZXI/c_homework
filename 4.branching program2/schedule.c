#include<stdio.h>
main()
{int a;
 printf("--小明作息时间表--\n  1. 起床洗漱\n  2. 锻炼身体\n  3. 早餐\n  4. 上课\n  5. 午餐休息\n  6. 上课\n  7. 自由活动\n  8. 晚餐\n  9. 晚自习\n 10. 上床休息\n请输入选项：");
 scanf("%d",&a);
 switch(a){
 	case 1:printf("起床洗漱 6:20\n");break;
 	case 2:printf("锻炼身体 6:30\n");break;
 	case 3:printf("早餐 7:30\n");break;
 	case 4:printf("上午上课 8:00\n");break;
 	case 5:printf("午餐休息 12:00\n");break;
 	case 6:printf("下午上课 13:20\n");break;
 	case 7:printf("自由活动 16:00\n");break;
 	case 8:printf("晚餐 17:30\n");break;
 	case 9:printf("晚自习 19:30\n");break;
 	case 10:printf("上床休息 23:00\n");break;
 	default:printf("选项错误\n");}
return 0;
}
