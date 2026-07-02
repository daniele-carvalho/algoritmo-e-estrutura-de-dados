#include <stdio.h>
#include <stdlib.h>

struct no {
    int info;
    struct no * esq; //subarvore esquerda
    struct no * dir; //subarvore direita
};

typedef struct no * arvore;

int vazia (arvore r){
    return (r==NULL);
}

void in_ordem (arvore r){ //esquerda->raiz->direita
    if (!vazia(r)){
        in_ordem(r->esq);
        printf("%d ", r->info);
        in_ordem(r->dir);
    }
}

void pre_ordem (arvore r){ //raiz->esquerda->direita
    if (!vazia(r)){
        printf("%d ", r->info);
        pre_ordem(r->esq);
        pre_ordem(r->dir);
    }
}

void pos_ordem(arvore r){ //esquerda->direita->raiz
    if (!vazia(r)){
        pos_ordem(r->esq);
        pos_ordem(r->dir);
        printf("%d ", r->info);
    }
}

arvore inserir (int info, arvore r){
    if (vazia(r)){
        arvore novo = malloc(sizeof(struct no));
        novo->info=info;
        novo->dir=NULL;
        novo->esq=NULL;
        return novo;
    } else{
        if (info < r->info){
            r->esq= inserir(info,r->esq);
        }else{
            r->dir= inserir(info, r->dir);
        }
    }
    return r;
}

arvore buscar(int info, arvore r){
    if (vazia(r)){
        return NULL;
    }

    if (r->info>info)
        return buscar(info, r->esq);
    if (r->info<info)
        return buscar(info,r->dir);

    return r;
}

int maximo(arvore r){
    while (r->dir!=NULL){
        r=r->dir;
    }
    return r->info;
}

int minimo(arvore r){
    while(r->esq!=NULL){
        r=r->esq;
    }
    return r->info;
}

int soma(arvore r){
    if (r==NULL){
        return 0;
    }
    return r->info + soma(r->esq)+soma(r->dir);
}

void imprimir_intervalo(arvore r, int a, int b){
    if (r==NULL){
        return;
    }

    if (r->info<a){
        imprimir_intervalo(r->dir,a,b);
    } else if(r->info>b){
        imprimir_intervalo(r->esq, a, b);
    }else{
        imprimir_intervalo(r->esq,  a,  b);
        printf("%d ", r->info);
        imprimir_intervalo(r->dir,  a,  b);
    }  
}

int diferenca_ref(arvore r, int k){
    if (r == NULL)
        return 0;

    if (r->info > k){
        return r->info + diferenca_ref(r->esq, k) + diferenca_ref(r->dir, k);
    }else{
        return -r->info + diferenca_ref(r->esq, k) + diferenca_ref(r->dir, k);  
    }
}

void imprimir_niveis(arvore r){
    if (r==NULL){
        return;
    }

    printf("%d ", r->info);
    
}


int main(){
    arvore r=NULL;
    r= inserir(9,r);
    r= inserir(11,r);
    r=inserir(7,r); //faltou
    r=inserir(2,r);
    r=inserir(14,r);
    r=inserir(5,r);
    r=inserir(8, r);
    r=inserir(27,r);
    r=inserir(25,r);

    in_ordem(r);
    printf("\n");
    pre_ordem(r);
    printf("\n");
    pos_ordem(r);
    printf("\n");

    printf("Maior valor da arvore binaria: %d\n", maximo(r));
    printf("Menor valor da arvore binaria: %d\n", minimo(r));

    printf("Soma de todos os valores: %d\n", soma(r));

    int a,b;
    printf("Escolha um intervalo a e b:");
    scanf("%d%d", &a, &b);
    printf("Os numeros da arvore entre %d e %d sao:", a,b);
    imprimir_intervalo(r,a,b);
    
}