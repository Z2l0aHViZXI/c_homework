#include <stdio.h>  
#include <stdlib.h>  
typedef struct numLink  
{  
    int no;  
    struct numLink *next;  
}NODE;
NODE * moveNode( NODE *head, int m )
{NODE *c=head,*t=c,*h=head->next;
 int i;
 while(t->next!=NULL)
 {t=t->next;
 }
 for(i=0;i<m&&c->next!=NULL;i++)
 {c=c->next;
 }
 if(c->next==NULL)
 {return head;
 }
 head->next=c->next;
 c->next=NULL;
 t->next=h;
return head;
}
void SetLink( NODE *h, int n )  
{  
    NODE *p=NULL, *q=NULL;  
    int i;  
    for ( i=0; i<n; i++)  
    {  
        p = (NODE *)malloc(sizeof(NODE));  
        p->no = i+1;  
        p->next = NULL;  
        if( h->next == NULL )  
        {  
            h->next = p;  
            q = p;  
        }  
        else  
        {  
            q->next = p;  
            q = q->next;  
        }  
    }  
    return;  
}  
int main( )  
{  
    int n,m;  
    NODE *head=NULL, *q=NULL;  
    scanf("%d%d",&n,&m);  
    head = (NODE *)malloc(sizeof(NODE));  
    head->no = -1;  
    head->next = NULL;  
  
    SetLink( head, n );  
    q = moveNode( head, m );  
    do  
    {  
        printf("%d ",q->next->no);  
        q = q->next;  
    } while( q->next != NULL );   
    printf("\n");  
    return 0;  
}
