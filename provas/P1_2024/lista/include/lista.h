#ifndef LISTA_H
#define LISTA_H

typedef struct no{
    int info;
    struct no *prox;
}lista;

lista*inserir(lista*l, int info);
void printar(lista*l);
int vazia(lista*l);
int distintos(lista*l);
lista* tira_repetidos(lista*l);


#endif