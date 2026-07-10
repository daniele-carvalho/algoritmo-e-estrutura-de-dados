#include <stdio.h>
#include <stdlib.h>

struct no {
    int fb;
    int info;
    struct no* dir;
    struct no*esq;
};

typedef struct no* avl;

int altura (avl r){
    if (r==NULL){
        return 0;
    }
    int he = altura(r->esq);
    int hd = altura(r->dir);

    return (he>hd? he:hd)+1;
}

void atualizarFB (avl r){
    if (r==NULL){
        return;
    }
    r->fb= altura(r->dir)-altura(r->esq);
}