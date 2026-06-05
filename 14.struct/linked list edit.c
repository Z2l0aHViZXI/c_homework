#include <stdio.h>  
#include <stdlib.h>  
typedef struct sdata  
{  int num;  
   struct sdata *next;  
} ;  
typedef struct sdata SNODE;  
void movenode( SNODE *head, int m)
{if(head->next==NULL||m<1)
 {return;
 }
 SNODE *p=head,*c=head->next;
 int i;
 for(i=1;i<m&&c!=NULL;i++)
 {p=p->next;
  c=c->next;
 }
 if(c==NULL||p==head)
 {return;
 }
 p->next=c->next;
 c->next=head->next;
 head->next=c;
}
void setlink( SNODE * head, int n )  
{     
    SNODE *p;  
    while ( n > 0 )  
    {   p = ( SNODE * ) malloc( sizeof( SNODE ) );  
        p->num = n;  
        p->next = head->next;  
        head->next = p;  
        n --;  
    }  
}  
void outlink( SNODE * head )  
{  
    while( head->next != NULL )  
    {  
        head = head->next;  
        printf( "%d,", head->num );  
    }  
    return;  
} 
int main( )  
{   int n, m;  
    SNODE * head = NULL;  
  
    scanf("%d%d", &n, &m );  
    head = ( SNODE * ) malloc( sizeof( SNODE ) );  
    head->num = -1;  
    head->next = NULL;  
    setlink( head, n );  
    movenode( head, m );
    outlink( head );  
    printf("\n");  
    return 0;  
}
