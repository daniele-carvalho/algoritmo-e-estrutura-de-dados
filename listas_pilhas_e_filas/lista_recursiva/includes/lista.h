#ifndef LISTA_H
#define LISTA_H

typedef struct no{
    int info;
    struct no *prox;
} lista;

//AS LISTAS ORIGINAIS NÃO DEVEM SER ALTERADAS.
lista* inserir(lista *l, int info);
int vazia (lista *l);
lista* remover (lista *l, int info);
void printa (lista *l);
lista* inverte (lista* l);
lista* concatena (lista *l1, lista* l2);
lista* intercala (lista *l1, lista *l2);

#endif