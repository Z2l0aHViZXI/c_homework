#include<stdio.h>  
long long gcd(long long a, long long b) {   
    while (b != 0)  
    {  
        long long  temp = b;  
        b = a % b;  
        a = temp;  
    }  
    return a;  
}  
int main()  
{  
    int n,i,j;  
    long long a[100],b[100],fz=1,fm=1;  
    scanf("%d",&n);  
    for(i=0;i<n;i++) scanf("%lld%lld",&a[i],&b[i]);  
    for(i=0;i<n;i++)  
    {  
        for(j=0;j<n;j++)  
        {  
            if(a[i]==b[j])  
            {  
                a[i]=b[j]=1;  
                break;  
            }  
        }  
    }  
    for(i=0;i<n;i++)  
    {  
        fz*=a[i];  
        fm*=b[i];  
    }  
    if (fm < 0)  
    {  
        fm = -fm;  
        fz = -fz;  
    }  
    long c=gcd(fz,fm);  
    fz/=c;  
    fm/=c;  
    if(fm==1) printf("%lld\n",fz);  
    else printf("%lld/%lld\n",fz,fm);  
    return 0;  
}
