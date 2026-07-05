#include <stdio.h>
#include <stdlib.h>

struct no{
    int info;
    struct no* dir;
    struct no* esq;
    short fb;
};

typedef struct no* avl;

avl novono (avl r, int info){
    struct no* novo = malloc(sizeof(struct no));
    novo->dir=NULL;
    novo->esq=NULL;
    novo->fb=0;
    novo->info=info;
    return novo;
}

short maior(short a, short b){
    return (a>b)? a:b;
}

int main(){
    avl r=NULL;
    

    
}

