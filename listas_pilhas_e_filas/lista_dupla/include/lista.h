#ifndef LISTA_H
#define LISTA_H

typedef struct no{
    int info;
    struct no *ant;
    struct no *prox;
}lista;

int vazia(lista* l);
lista* inserir(lista*l, int info);
lista* remover (lista*l, int info);
void printar (lista* l);
lista* inverter (lista*l);
lista* concatena(lista*l1, lista*l2);
lista* intercala(lista*l1, lista*l2);




#endif