#include <stdio.h>
#include <stdlib.h>
#include "prova.h"

int vazia(lista* l){
    return (l == NULL);
}

lista* inserir (lista*l, int info){
    lista *aux = (lista*)malloc(sizeof(lista));
    aux->info=info;
    aux->prox= l;
    return aux;
}

void printar(lista *l){
    while(l!=NULL){
        printf("%d -> ", l->info);
        l = l->prox;
    }
    printf("NULL\n");
}

int somar_intervalo(lista*l, int a, int b){
    if (l==NULL){
        return 0;
    }
    if (l->info>=a && l->info<=b){
        return l->info + somar_intervalo(l->prox,a,b);
        
    }
    
    return somar_intervalo(l->prox, a,b);
}