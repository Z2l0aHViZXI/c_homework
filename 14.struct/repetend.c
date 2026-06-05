#include <stdio.h>  
#include <stdlib.h>  
typedef struct node  
{   int         data;  
    struct node * next;  
} NODE;  
void change(int n, int m, NODE *head)
 {int k; 
     // 余数范围0~m-1，用数组记录每个余数首次出现的节点
     NODE **array = (NODE **)malloc(sizeof(NODE *) * m);
     NODE *p = head; // 链表遍历指针
     // 初始化余数节点数组为NULL
     for (k = 0; k < m; k++)
         array[k] = NULL;
     while (n != 0)
     {
         int temp = n * 10;
         int quotient = temp / m;   // 小数位的商
         int remainder = temp % m;  // 新的余数
         if (remainder == 0)
         {
             // 有限小数：生成最后一个节点，next为NULL
             p->next = (NODE *)malloc(sizeof(NODE));
             p->next->data = quotient;
             p->next->next = NULL;
             n = 0; // 终止循环
         }
         else
         {
             if (array[n] == NULL)
             {
                 // 余数首次出现：记录节点并继续
				 array[n]=p->next = (NODE *)malloc(sizeof(NODE));
                 p->next->data = quotient;
                 p = p->next;
                 n = remainder; // 更新n为新余数
             }
             else
             {
                 // 余数重复：形成循环链表（循环节起点为余数首次出现的节点）
                 p->next = array[n];
                 n = 0; // 终止循环
             }
         }
     }
     free(array); // 释放余数节点数组
 }
 // 找循环节起点+计算长度（核心：Floyd快慢指针找环）
 NODE *find(NODE *head, int *n)
 {int i;
     if (head == NULL || head->next == NULL)
     {
         *n = 0;
         return NULL;
     }
     NODE *slow = head->next; // 慢指针（步长1）
     NODE *fast = head->next; // 快指针（步长2）
     // 步骤1：找快慢指针相遇点（判断是否有环）
     while (fast != NULL && fast->next != NULL)
     {
         slow = slow->next;
         fast = fast->next->next;
         if (slow == fast)
             break; // 找到相遇点，存在环
     }
     // 无环情况
     if (fast == NULL || fast->next == NULL)
     {
         *n = 0;
         return NULL;
     }
     // 步骤2：计算环的长度
     int cycle_len = 1;
     fast = fast->next;
     while (fast != slow)
     {
         fast = fast->next;
         cycle_len++;
     }
     // 步骤3：找环的入口（循环节起点）
     slow = head->next;
     fast = head->next;
     // 快指针先前进环长步
     for (i = 0; i < cycle_len; i++)
         fast = fast->next;
     // 快慢指针同步前进，相遇处为环入口
     while (slow != fast)
     {
         slow = slow->next;
         fast = fast->next;
     }
     *n = cycle_len; // 赋值循环节长度
     return slow;    // 返回循环节起点
 }
void outputring( NODE * pring )  
{   NODE * p;  
    p = pring;  
    if ( p == NULL )  
        printf("NULL");  
    else  
        do  
        {   printf("%d", p->data);  
            p = p->next;  
        } while ( p != pring );  
    printf("\n");  
    return;  
}  
int main()  
{   int n, m;  
    NODE * head, * pring;  
    scanf("%d%d", &n, &m);  
    head = (NODE *)malloc( sizeof(NODE) );  
    head->next = NULL;  
    head->data = -1;  
    change( n, m, head );  
    pring = find( head, &n );  
    printf("ring=%d\n", n);  
    outputring( pring );  
    return 0;  
}
