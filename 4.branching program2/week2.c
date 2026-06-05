#include<stdio.h>
main()
{int year,month,day,week,maxday,a;
 scanf("%d%d%d",&year,&month,&day);
 switch(month){
 	case 1:case 3:case 5:case 7:case 8:case 10:case 12:maxday=31;break;
 	case 4:case 6:case 9:case 11:maxday=30;break;
 	case 2:maxday=(year%4==0&&year%100!=0||year%400==0)?29:28;break;
 	default:maxday=31;}
 if(month<1||month>12)
 {if(day<1||day>maxday){printf("month and day are wrong.\n");
  }else{printf("month is wrong.\n");}}
 else if(day<1||day>maxday){printf("day is wrong.\n");}
      else{if(month==1||month==2){year--;
      month+=12;}
      week=(day+26*(month+1)/10+year%100+(year%100)/4+(year/100)/4+5*(year/100))%7;
      if(week==0){a=6;
      }else{a=week-1;}
      printf("%d\n",a);}
return 0;
}
