#include "stdio.h"  
#include "stdlib.h"  
struct node  
{   int data;  
    struct node * next;  
} ;  
typedef struct node NODE;  
typedef struct node * PNODE;  
void outlist( PNODE head )  
{   PNODE p;  
    p = head->next;  
    while ( p != NULL )  
    {   printf("%d\n", p->data);  
        p = p->next;  
    }  
}
void sortlist( PNODE h, int n)
{PNODE p=h,c=h->next,x=(PNODE)malloc(sizeof(NODE));
 while(c!=NULL&&c->data<=n)
 {if(c->data==n)
  {return;
  }
  p=p->next,c=c->next;
 }
 p->next=x;
 x->next=c;
 x->data=n;
}
int main ( )  
{   int num=1;  
    PNODE head;  
    head = (PNODE)malloc( sizeof(NODE) );  
    head->next = NULL;  
    head->data = -1;  
    while ( num!=0 )  
    {   scanf("%d", &num);  
        if ( num!=0 )  
            sortlist( head, num);  
    }  
    outlist( head );  
    return 0;  
}  

