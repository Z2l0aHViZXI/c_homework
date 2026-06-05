#include <stdio.h>
main() {
    int a,n,i,row,s,num;
    scanf("%d%d",&n,&a);
    int top=3*n-2;
    for (i=0;i<top;i++){//1
        if(i<=3*(n-1)/2){
            num=(a+i)%10;
        }
        else{
            num=(a+3*n-3-i)%10;
        }
        printf("%d",num);
        if(i!=top-1)printf(" ");
    }
    printf("\n");
    for(row=2;row<=n-1;row++){//2~n-1
        for(s=0;s<2*(row-1);s++){
            printf(" ");
        }
        int now=(a+row-1)%10;
        printf("%d",now);
        int mid = 2*top-4*row+1;
        for(s=0;s<mid;s++){
            printf(" ");
        }

        printf("%d\n",now);
    }
    for(s=0;s<2*(n-1);s++){
        printf(" ");
    }
    for(i=0;i<n&&n>1;i++){//n
        if(i<=(n-1)/2){
            num=(a+n-1+i)%10;
        }
        else{
            num=(a+2*n-2-i)%10;
        }
        printf("%d",num);
        if(i!=n-1)printf(" ");
    }
    if(n!=1)printf("\n");
    return 0;
}
