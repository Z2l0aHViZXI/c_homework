#include<stdio.h>
#include<string.h>
#include<ctype.h>
int getd(char c)
{if(isdigit(c))
  {return c-'0';
  }
  if(isupper(c))
  {return c-'A'+10;
  }
return -1; 
}
long long c2d(const char *s,int b)
{long long D=0;int l=strlen(s),i,d;
 for(i=0;i<l;i++)
 {d=getd(s[i]);
  D=D*b+d;
 }
return D; 
}
int getm(const char *s)
{int maxd=-1,i,l=strlen(s),d;
 for(i=0;i<l;i++)
 {d=getd(s[i]);
  if(d>maxd)
  {maxd=d;
  }
 }
return maxd;
}
main()
{char m[20],n[20];int bM,bN,s=0;long long dM,dN;
 scanf("%s%s",m,n);
 int M=getm(m),N=getm(n);
 for(bM=M+1;bM<=36;bM++)
 {dM=c2d(m,bM);
  for(bN=N+1;bN<=36;bN++)
  {dN=c2d(n,bN);
  if(dM==dN)
  {printf("%s (base %d) = %s (base %d)\n",m,bM,n,bN);
   s++;
   goto end;
  }
  }
 }
end:
if(!s)
	{printf("%s is not equal to %s in any base 2..36\n",m,n);
	} 
return 0;
}

