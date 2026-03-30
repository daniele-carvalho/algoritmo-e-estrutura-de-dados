#include <stdio.h> 

/* Algoritmo que calcula o catalão de um número n
Fórmula disponível em: https://en.wikipedia.org/wiki/Catalan_number
*/

long long catalan (long long n){
    if (n<=0){
        return 1;
    }
    return ((2*(2*n-1))*(catalan(n-1)))/(n+1);
}

int main(){
   long long n; scanf("%lld", &n);
    printf("%lld", catalan(n));
}