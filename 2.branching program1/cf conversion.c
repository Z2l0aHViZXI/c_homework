#include<stdio.h>
main()
{char m;float a,b;
 scanf(" %c%f",&m,&a);
 if (m=='F'){b=a*9/5+32;
    printf("The Fahrenheit is %.2f\n",b);
 }else if (m=='C'){b=(a-32)*5/9;
		  printf("The Centigrade is %.2f\n",b);
		  }else{};
return 0;
}
