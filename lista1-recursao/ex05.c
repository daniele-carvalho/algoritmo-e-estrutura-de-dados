#include <stdio.h>
#include <math.h>
//Calcular o fatorial exponencial de um número


long long fatorialexponencial(long long
 x){
    if (x==0){
        return 1;
    }
    return pow(x, fatorialexponencial(x-1));
}

long long main(){
    long long x;
    scanf("%d", &x);
    printf("%d", fatorialexponencial(x));
}