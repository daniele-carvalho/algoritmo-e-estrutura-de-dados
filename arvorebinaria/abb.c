#include <stdio.h>
#include <stdlib.h>

struct no {
    int info;
    struct no* dir;
    struct no* esq;
};

typedef struct no *arvore;

struct fila {
    arvore dado;
    struct fila* prox;
};

typedef struct fila *Fila;

//usa a estrutura fila pra enfileirar e desinfileirar os niveis.
void imprimir_por_niveis(arvore r);

/*imprime os numeros da arvore em ordem crescente q estejam
 * no intervalo ABERTO entre a e b,
 *  evitando percorrer nos desnecessarios.*/
void intervalo(arvore r, int a, int b){
    
}

/*retorna o menor valor maior que k */
int seguinte (arvore r, int k);

int somar(arvore r){
    if (r==NULL){
        return 0;
    }
    return r->info + somar(r->dir)+somar(r->esq);
}

/*imprime os numeros da arvore em ordem crescente q estejam
 * no intervalo FECHADO entre a e b,
 *  evitando percorrer nos desnecessarios.*/
void imprimir_intervalo(arvore r, int a, int b){
    if (r==NULL) return;
    if (r->info > a)
        imprimir_intervalo(r->esq, a, b);
    
    if (r->info >= a && r->info <= b)
        printf("%d ", r->info);
    
    if (r->info < b)
        imprimir_intervalo(r->dir, a, b);
}

/*retorna a diferenca entre os valores maiores que k e os menores que k */
int diferenca_ref(arvore r, int k){
    if (r==NULL) return 0;

    if (r->info>k){
        return r->info + diferenca_ref(r->dir, k)+ diferenca_ref(r->esq, k);
    }else if (r->info<k){
        return -r->info + diferenca_ref(r->dir, k)+ diferenca_ref(r->esq, k);
    }else{
        return diferenca_ref(r->dir, k)+ diferenca_ref(r->esq, k);
    }
}

//retorna o numero de nos internos (nao folhas)
int conta_nos_internos(arvore r);

//imprime raiz->esq->dir.
void preordem(arvore r){
    if (r!=NULL){
    printf("%d ", r->info);
    preordem(r->esq);
    preordem(r->dir);
    }
}

//soma maiores que k.
int somamaiores(arvore r, int k){
    if (r==NULL) return 0;
    if (r->info>k){
        return r->info+somamaiores(r->esq,k)+somamaiores(r->dir, k);
    }
    return somamaiores(r->dir, k);
}

//retorna o numero de nos q tem filho unico
int conta_nos_filho_unico(arvore r){
    if (r==NULL) return 0;
    if (r->esq==NULL && r->dir==NULL){
        return conta_nos_filho_unico(r->esq)+conta_nos_filho_unico(r->dir);
    }else if(r->esq!=NULL && r->dir!=NULL){
        return conta_nos_filho_unico(r->esq)+conta_nos_filho_unico(r->dir);
    } else{
        return 1+conta_nos_filho_unico(r->esq)+conta_nos_filho_unico(r->dir);
    }
}

arvore inserir (arvore r, int info){
    if (r==NULL){
        struct no *novo = malloc(sizeof(struct no));
        novo->info=info;
        novo->dir=NULL;
        novo->esq=NULL;
        return novo;
    }
    if (info>r->info){
        r->dir =inserir(r->dir, info);
    }else{
        r->esq=inserir(r->esq, info);
    }
    return r;
}

//imprime esquerda->raiz->direita.
void inorder(arvore r){
    if (r==NULL){
        return;
    }
    inorder(r->esq);
    printf("%d ",r->info);
    inorder(r->dir);
}

int main(){
    arvore r=NULL;
    r = inserir(r,12);
    r = inserir(r, 34);
    r = inserir(r,83);
    r = inserir(r,4);
    r = inserir(r,11);
    r = inserir (r, 5);
    r = inserir (r, 8);

    printf("EM ORDEM:\n");
    inorder(r);

    printf("\nPRE ORDEM:\n");
    preordem(r);

    printf("\nSOMA:\n");
    printf("%d",somar(r));

    printf("\nDIFERENCA ENTRE OS VALORES MAIORES QUE 15 E MENORES QUE K.\n");
    printf("%d", diferenca_ref(r, 15));
    
    printf("\nSOMA MAIORES QUE 15\n ");
    printf("%d", somamaiores(r,15));
    
    printf("\nConta nos com filho unico:\n");
    printf("%d", conta_nos_filho_unico(r));
}