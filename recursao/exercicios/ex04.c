#include <stdio.h>
#define ll long long
/* Projetar uma função recursiva que calcule o superfatorial. Ex:
Entrada: 4
Função retorna o resultado de: (4! * 3! * 2! * 1!)
*/
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

