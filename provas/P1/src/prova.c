#include <stdio.h>
#include <stdlib.h>
#include "../include/prova.h"

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

int tam(lista* l){
    int t=0;
    while (l!= NULL){
        t++;
    }
    return t;
}

lista* intercalar(lista *l1, lista *l2){
    lista* l3=NULL;
    if (tam(l1)!=tam(l2)){
        printf("Não é possível intercalar. Tamanhos de listas diferentes.\n");
        return 0;
    }
    while (l2!= NULL){
        l3 = inserir(l3, l1->info);
        l3 = inserir(l3, l2->info);

        l1=l1->prox;
        l2=l2->prox;
    }


}