#include <stdio.h>
#include <stdlib.h>
#include "../include/prova.h"

int main(){
    lista* l = NULL;
    for(int i=1;i<=20;i++){
        l = inserir(l, i);
    }
    printar(l);
    
    int a,b;
    printf("Escolha o intervalo A e B\n");
    scanf("%d%d", &a, &b);
    
    printf("%d", somar_intervalo(l,a,b));
}