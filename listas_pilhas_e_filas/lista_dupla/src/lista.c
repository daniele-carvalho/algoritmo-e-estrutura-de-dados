#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int vazia(lista *l){
    return (l==NULL);
}

lista* inserir (lista* l, int info){
    lista *aux = (lista*)malloc(sizeof(lista));

    aux->info=info;
    aux->prox = l;
    aux->ant = NULL;

    if (!vazia(l)){
        l->ant = aux;
    }
    return aux;
}

void printar (lista*l){
    while(l!=NULL){
        printf("%d ->", l->info);
        l= l->prox;
    }
    printf("NULL\n");
}

lista* remover(lista*l, int info){
    lista* aux = l;
    while(aux !=NULL && aux->info!=info){
        aux = aux->prox;
    }

    //nao encontrou:
    if (aux==NULL){
        return l;
    }

    //se n for o primeiro:
    if(aux->ant!=NULL){
        aux->ant->prox= aux->prox;
    }else{
        //remove o primeiro
        l = aux->prox;
    }
    //se n for o ultimo
    if (aux->prox!=NULL){
        aux->prox->ant = aux->ant;
    }
    free(aux);
    return l;
    
}