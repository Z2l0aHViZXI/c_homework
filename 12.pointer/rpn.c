#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct
{int m[1000],t;
}stack;
void S(stack* s)
{s->t=-1;
}
void push(stack* s,int v)
{s->m[++s->t]=v;
}
int pop(stack* s)
{return s->m[s->t--];
}
int peek(stack* s)
{return s->m[s->t];
}
int rpn(const char* e)
{stack s;
 S(&s);
 char* token,c[1000];
 strcpy(c,e);
 token=strtok(c," ");
 while(token!=NULL)
 {if(isdigit((unsigned char)token[0])||(token[0]=='-'&&isdigit((unsigned char)token[1])))
  {int n=atoi(token);
   push(&s,n);
  }else
   {int b=pop(&s);
    int a=pop(&s);
    int r;
    switch(token[0])
    {case'+':r=a+b;break;
     case'-':r=a-b;break;
     case'*':r=a*b;break;
     case'/':r=a/b;break;
	}
	push(&s,r);
   }
   token=strtok(NULL," ");
 }
return pop(&s);
}
main()
{char e[1000];
 fgets(e,sizeof(e),stdin);
 e[strcspn(e,"\n")]='\0';
 int r=rpn(e);
 printf("%d\n",r);
return 0;
}
