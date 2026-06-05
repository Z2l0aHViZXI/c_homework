#include<stdio.h>
#include<string.h>
#include<ctype.h>
main()
{int n,l,dig,up,low,oth,i,t;char pw[21];
 scanf("%d",&n);
 getchar(); 
 while(n--)
 {scanf("%20[^\n]%*c",pw);
  pw[20]='\0';
  dig=0,up=0,low=0,oth=0; 
  l=strlen(pw);
  if(l<6)
  {printf("Not Safe\n");
   continue;
  }
  for(i=0;i<l;i++)
  {char c=pw[i];
   if(isdigit(c))
   {dig=1;
   }else if(isupper(c))
    {up=1;
	}else if(islower(c))
	 {low=1;
	 }else
	  {oth=1;
	  }
  }
  t=dig+up+low+oth;
  if(t==1)
  {printf("Not Safe\n");
  }else if(t==2)
   {printf("Medium Safe\n");
   }else
    {printf("Safe\n");
	}
 }
return 0;
}
