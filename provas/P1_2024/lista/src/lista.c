#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int vazia(lista*l){
    return (l==NULL);
}

lista* inserir (lista*l, int info){
    lista* aux = (lista*)malloc(sizeof(lista));
    aux->info=info;
    aux->prox=l;
    
    return aux;
}

void printar(lista*l){
    while(l!=NULL){
        printf("%d ->", l->info);
        l = l->prox;
    }
    printf("NULL\n");
}

int existe (lista*l, int info){
    while(l!=NULL){
        if (l->info == info){
            return 1;
        }
        l=l->prox;
    }
    return 0;
}

int distintos (lista*l){
    int c=0;
    if (l==NULL){
        return 0;
    }
    if (!existe(l->prox, l->info)){
        return 1 + distintos(l->prox);
    }
    return distintos(l->prox);
}

lista* tira_repetidos(lista*l){
    lista* aux= NULL;
    while( l!=NULL){
        if (!existe(aux, l->info)){
            aux = inserir(aux, l->info);
        }
        l=l->prox;
    }
    return aux;
}