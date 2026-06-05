#include<stdio.h>
#include<ctype.h>
main()
{char p[6],c;
 scanf("%s",p);
 int m=isdigit(p[4]),b=0,i,n;
 for(i=0;i<4;i++)
 {c=p[i];
  if(isupper(c)&&c!='I'&&c!='O')
  {n++;
  }
 }
  if(m&&n>=2)
  {printf("ok.\n"); 
  }else
  {printf("no.\n");
  }
return 0;
}
