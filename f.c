#include <stdio.h>
#define ll long long

ll fatorial(ll x){
    if (x <=1 ){
        return 1;
    }
    else{
        return x*fatorial(x-1);
    }
}

ll superfatorial(ll x){
    if (x==1){
        return 1;
    } else{
        return fatorial(x)*superfatorial(x-1);
    }
}

int main(){
    ll x; 
    scanf("%lld", &x);
    printf("%lld", superfatorial(x));
}

