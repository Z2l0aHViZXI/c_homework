#include<stdio.h>
typedef struct{
	int D[100],l;
}N;
void Num(N *n,long long v)
{n->l=0;
 while(v>0)
 {n->D[n->l++]=v%10;
 v/=10;
 }
}
N add(N a,N b)
{N r;int c=0,i;
 r.l=0;
 for(i=0;i<a.l||i<b.l||c;i++)
 {int s=c;
  if(i<a.l)s+=a.D[i];
  if(i<b.l)s+=b.D[i];
  r.D[r.l++]=s%10;
  c=s/10;
 }
return r;
}
main()
{int a,b,d,i;N n;
 scanf("%d%d",&a,&b);
 d=b-a;
 if(d==1)
 {printf("1\n");
  return 0;
 }if(d==2)
  {printf("2\n");
   return 0;
  }
  N p,c;
  Num(&p,1);
  Num(&c,2); 
  for(i=3;i<=d;i++)
  {n=add(p,c);
     p=c;
     c=n;
  }
 for(i=c.l-1;i>=0;i--)
 {printf("%d",c.D[i]);
 }
 printf("\n");
return 0;
}
