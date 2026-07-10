#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int info;
    int fb;        // fator de balanceamento
    struct no *esq, *dir;
}No;

typedef No* avl;

int altura(avl r){
    if(r == NULL)
        return 0;

    int he = altura(r->esq);
    int hd = altura(r->dir);

    return (he > hd ? he : hd) + 1;
}

void atualizarFB(avl r){
    if(r != NULL)
        r->fb = altura(r->esq) - altura(r->dir);
}

avl rotacaoEsquerda(avl r){
    avl x = r->dir;

    r->dir = x->esq;
    x->esq = r;

    atualizarFB(r);
    atualizarFB(x);

    return x;
}

avl rotacaoDireita(avl r){
    avl x = r->esq;

    r->esq = x->dir;
    x->dir = r;

    atualizarFB(r);
    atualizarFB(x);

    return x;
}

avl rotacaoDuplaEsquerda(avl r){
    r->dir = rotacaoDireita(r->dir);
    return rotacaoEsquerda(r);
}

avl rotacaoDuplaDireita(avl r){
    r->esq = rotacaoEsquerda(r->esq);
    return rotacaoDireita(r);
}

avl inserir(avl r, int info){
    if(r == NULL){
        avl novo = malloc(sizeof(No));

        novo->info = info;
        novo->fb = 0;
        novo->esq = NULL;
        novo->dir = NULL;

        return novo;
    }

    if(info < r->info)
        r->esq = inserir(r->esq, info);
    else if(info > r->info)
        r->dir = inserir(r->dir, info);
    else
        return r;

    atualizarFB(r);

    // Caso Esquerda-Esquerda
    if(r->fb == -2 && r->esq->fb <= 0)
        return rotacaoDireita(r);

    // Caso Direita-Direita
    if(r->fb == 2 && r->dir->fb >= 0)
        return rotacaoEsquerda(r);

    // Caso Esquerda-Direita
    if(r->fb == -2 && r->esq->fb > 0)
        return rotacaoDuplaDireita(r);

    // Caso Direita-Esquerda
    if(r->fb == 2 && r->dir->fb < 0)
        return rotacaoDuplaEsquerda(r);

    return r;
}

void imprimir(avl r){
    if(r != NULL){
        imprimir(r->esq);
        printf("%d (%d)\n", r->info, r->fb);
        imprimir(r->dir);
    }
}

int main(){
    avl raiz = NULL;

    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 35);

    imprimir(raiz);

    return 0;
}