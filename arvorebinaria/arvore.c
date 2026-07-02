#include <stdio.h>
#include <stdlib.h>

struct no {
    int info;
    struct no* dir;
    struct no* esq;
};

typedef struct no * arvore;

arvore inserir(arvore r, int info){
    if (r==NULL){
        struct no *novo = malloc(sizeof(struct no));
        novo->dir=NULL;
        novo->esq=NULL;
        novo->info=info;
        return novo;
    }else{
        if (info>r->info)
            r->dir=inserir(r->dir, info);
        if (info<r->info)
            r->esq =inserir(r->esq, info);
    }
    return r;
}

void printar (arvore r){ //esquerda->raiz->direita
    if (r!=NULL){
    printar(r->esq);
    printf("%d ", r->info);
    printar(r->dir);
    }
}

int somar(arvore r){
    if (r!=NULL){
        return r->info+somar(r->dir)+somar(r->esq);
    }
}

int main(){
    arvore r=NULL;
    r= inserir(r, 12);
    r= inserir(r, 8);
    r= inserir(r, 14);
    r= inserir(r, 13);
    r= inserir(r, 29);
    r= inserir(r, 1);
    r= inserir(r, 5);

    printar(r);
    printf("SOMA: %d", somar(r));
}