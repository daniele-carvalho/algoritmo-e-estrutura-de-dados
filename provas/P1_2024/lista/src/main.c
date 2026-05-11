#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
    lista* l =NULL;
    for (int i=1;i<=10;i++){
        l = inserir(l, 2);
        l= inserir(l,1);
        l=inserir(l,4);
    }
    printar(l);

    printf("Quantidade de numeros distintos: %d\n", distintos(l));
    printf("Tira repetidos:\n ");
    printar(tira_repetidos(l));
    
}