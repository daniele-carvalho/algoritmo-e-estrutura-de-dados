#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void printa(lista* l){
    if (l==NULL){
        printf(" NULL\n");
        return;
    }
    printf("%d -> ", l->info);
    printa(l->prox);
}

lista *inserir (lista *l, int info){
    
    if (l==NULL){
        lista *aux = (lista*) malloc(sizeof(lista));
        aux->info=info;
        aux->prox=NULL;
        return aux;
    }
    
    l->prox= inserir(l->prox, info);
    return l;
}

