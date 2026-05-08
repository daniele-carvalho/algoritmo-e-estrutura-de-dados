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

lista* gerar_intervalo(lista*l, int a, int b){
    lista* aux=NULL;
    
    while(l!=NULL){
        if (l->info>=a && l->info <=b){
            aux = inserir(aux, l->info);
        }
        l=l->prox;
    }
    
    lista* inverte = NULL;
    while(aux!=NULL){
        inverte = inserir(inverte, aux->info);
        aux= aux->prox;
    }
    return inverte;
}

int tam(lista*l){
    int tamanho=0;
    while(l!=NULL){
        tamanho++;
        l= l->prox;
    }
    return tamanho;
}
    
void intercalar (lista*l1,lista*l2){
    lista* l3 = NULL;
    if (tam(l1)!=tam(l2)){
        printf("\nNao eh possivel intercalar listas\n");
    }
    
    printf("\nLista intercalada: \n");
    while (l2!=NULL){
        l3 = inserir(l3,l1->info);
        l3 = inserir(l3,l2->info);
        l1= l1->prox;
        l2 = l2->prox;
    }
    
    printar(l3);
 }
 
 
