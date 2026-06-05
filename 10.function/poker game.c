#include<stdio.h>
#include<stdlib.h>
const int H[]={0,-50,-2,-3,-4,-5,-6,-7,-8,-9,-10,-20,-30,-40};
typedef struct{
	int S12;
	int D11;
	int C10;
	int hs;
	int hn;
	int s;
}S;
main()
{while(1){
 S p[4]={0};int n,C[4],hp,i,j,o;char c[4],t;
 for(i=0;i<4;i++)
 {scanf("%d",&C[i]);
  for(j=0;j<C[i];j++)
  {scanf("%s",c);
   t=c[0];
   n=atoi(c+1);
   switch(t)
   {case'S':
        if(n==12)p[i].S12=1;
		break;
    case'H':
    	p[i].hs+=H[n];
    	p[i].hn++;
    	break;
    case'D':
    	if(n==11)p[i].D11=1;
    	break;
    case'C':
    	if(n==10)p[i].C10=1;
    	break;
   }
  }
 }
 if(C[0]==0&&C[1]==0&&C[2]==0&&C[3]==0)break;
 j=0;
 for(i=0;i<4;i++)
 {if(p[i].hn>0)
  {hp=i;
   j++;
  }
 }
 int allH=(j==1);
 for(i=0;i<4;i++)
 {if(allH)
  {p[i].s=(i==hp)?200:0;
    if(p[i].S12&&p[i].D11)
    {p[i].s+=500;
	}
	p[i].s+=p[i].D11*100-p[i].S12*100;
  }else
   {p[i].s=p[i].hs+p[i].D11*100-p[i].S12*100;
   }
   if(p[i].C10)
   {o=(p[i].S12==0&&p[i].D11==0&&p[i].hn==0);
    p[i].s=o?p[i].s+50:2*p[i].s;
   }
   if(p[i].s>0){printf("+%d",p[i].s);}
   else{printf("%d",p[i].s);}
   printf("%c",i<3?' ':'\n');
 }
}
return 0;
}
