#include <stdio.h>
#include <stdlib.h>

struct no {
  int info;
  struct no* dir;
  struct no* esq;
  int fb;
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

void fb (avl r){
    if (r==NULL) return;
    r->fb = altura(r->esq)-altura(r->dir);
}

avl rotacaoEsq(avl r){
    avl x= r->dir;
    r->dir = x->esq;
    x->esq = r;

    fb(r);
    fb(x);

    return x;
}

avl rotacaoDir(avl r){
    avl x= r->esq;
    r->esq = x->dir;
    x->dir = r;

    fb(r);
    fb(x);
    return x;
}

avl rotacaoduplaDir(avl r){
    r->esq = rotacaoEsq(r->esq);
    return rotacaoDir(r);
}

avl rotacaoduplaEsq(avl r){
    r->dir = rotacaoDir(r->dir);
    return rotacaoEsq(r);
}