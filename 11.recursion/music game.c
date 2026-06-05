#include<stdio.h>
#include<string.h>
int main(){
    int n,i;
    scanf("%d",&n);
    getchar();
    unsigned int prev_prev=0;
    unsigned int prev=0;
    int tap_count=0;
    int hold_count=0;
    int count_zero=0;
    char line[32];
    while(1){
        if(fgets(line,sizeof(line),stdin)==NULL){
            break;
        }
        int len=strlen(line);
        if(len>0&&line[len-1]=='\n'){
            line[len-1]='\0';
        }
        unsigned int current=0;
        for(i=0;i<n;++i){
            if(line[i]=='#'){
                current|=(1U<<i);
            }
        }
        if (current==0){
            count_zero++;
        }else{
            count_zero=0;
        }
        if(count_zero==3){
            break;
        }
        for(i=0;i<n;++i){
            unsigned int current_bit=(current>>i)&1U;
            unsigned int prev_bit=(prev>>i)&1U;
            unsigned int prev_prev_bit=(prev_prev>>i)&1U;
            if (current_bit==0&&prev_bit==1){
                if (prev_prev_bit==0){
                    tap_count++;
                } else {
                    hold_count++;
                }
            }
        }
        prev_prev=prev;
        prev=current;
    }
    printf("%d\n%d\n",tap_count,hold_count);
    return 0;
}
