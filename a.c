#include <stdio.h>
#include <stdlib.h>

//Revisando ALOCAÇÃO DINÂMICA.

int main(){
    int *x;
    x= calloc(1, sizeof(int));

    if (x){
        printf("memoria alocada");
    }else{
        printf("erro");
    }

}