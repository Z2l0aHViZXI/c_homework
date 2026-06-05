#include <stdio.h>  
#include <math.h>  
int main()  
{  
    int n, m;  
    int isPrime( int );  
      
    scanf("%d%d", &n, &m);  
    while ( n < m-1 )  
    {  
        if ( isPrime(n) && isPrime(n+2) )  
        {  
            printf("%d,%d\n", n, n+2);  
        }  
        n++;  
    }  
    return 0;  
}   
int isPrime(int x) 
{if(x<=1||x%2==0||x%3==0){return 0;}
 if(x==2||x==3){return 1;}
 int i;
 for(i=5;i*i<x;i+=6)
 {if(x%i==0||x%(i+2)==0)return 0;
 }
return 1; 
}
