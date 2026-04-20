#include "lista.h"
#include <stdio.h>
#include <stdlib.h> //pra aloc dinamica

/*typedef struct no{
    int info;
    struct no *prox;
}lista;*/

lista* inserir (lista *l, int info){
    lista* aux= (lista*)malloc(sizeof(lista));
    aux->info= info;
    aux->prox=l;
    return aux;
}

lista* remover(lista*l, int info){
    lista* ant = l;
    lista* r = l;

    while (r!= NULL && r->info!=info){
        ant = r;
        r = r->prox;
    }

    if (r!=NULL){
        if (r==l){
            l = l->prox;
        }else{
            ant->prox = r->prox;
        } 
        free(r);
    }else{
        printf("Elemento não está na lista.\n");
    }
    return l;
}

void printa(lista *l){
    
    while(l != NULL){
        printf("%d -> ", l->info);
        l =l->prox;
    }
    printf("NULL\n");
}

int tam(lista*l){
    int tam=0;
    while(l!=NULL){
        tam++;
        l = l->prox;
    }
    return tam;
}

lista* inverter (lista* l){
    lista* anterior = NULL;
    lista* atual = l;
    lista* seguinte;

    while (atual!=NULL){
        seguinte = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = seguinte;
    }
    return anterior;
}

int main(){
    lista *l = NULL;
    for (int i=10;i>=1;i--){
        l =inserir(l,i);
    }

    printf("\nLISTA INICIAL: \n");
    printa(l);

    remover(l, 8);
    remover(l, 9);
    remover(l, 10);
    remover(l, 6);
    remover(l, 7);
    printf("\nLISTA COM ITENS REMOVIDOS: \n");
    printa(l);

    printf("\nTAMANHO DA LISTA: %d\n", tam(l));

    l = inverter(l);
    printf("\n LISTA INVERTIDA: \n");
    printa(l);

}