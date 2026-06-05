#include <stdio.h>
int leap_year( int );     
int year_days( int );     
int days(int,int,int);    
int leap_year( int year )  
{   return ( (year%4==0 && year%100!=0) || year%400==0 ) ? 1 : 0;  
}   
int year_days(int year)
{   return leap_year( year ) ? 366 : 365;  
}  
int days( int year, int month, int day )
{   int months[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31}, i;  
      
    if  ( leap_year( year ) && month >2 )  
        day++;  
      
    for ( i=1; i<month; i++ )  
        day += months[i];  
  
    return day;  
}
int main() 
{int sy,sm,sd,ey,em,ed,d=0,i;
 scanf("%d%d%d%d%d%d",&sy,&sm,&sd,&ey,&em,&ed);
 if(ey>sy)
 {d+=year_days(sy)-days(sy,sm,sd);
  for(i=sy+1;i<ey;i++)
  {d+=year_days(i);}
  d+=days(ey,em,ed);
 }else
  {d=days(ey,em,ed)-days(sy,sm,sd);}
  if(d==1){printf("%d day\n",d);}
  else{printf("%d days\n",d);}
return 0;
}
