#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
main()
{int i,j;char *w[5],t[99];
 for(i=0;i<5;i++)
 {scanf("%s",t);
  w[i]=(char*)malloc(strlen(t)+1);
  strcpy(w[i],t);
 }
 for(i=0;i<5;i++)
 {for(j=0;j<4-i;j++)
  {if(strcmp(w[j+1],w[j])>0)
   {char *W=w[j];
    w[j]=w[j+1];
    w[j+1]=W;
   }
  }
 }
 for(i=0;i<5;i++)
 {printf("%s\n",w[i]);
  free(w[i]);
 }
return 0;
}
