#ifndef PROVA_H
#define PROVA_H

//estrutura
typedef struct no{
    int info;
    struct no *prox;
}lista;

int vazia(lista*l);
void printar (lista*l);
lista * inserir(lista *l, int info);
int somar_intervalo (lista *l, int a, int b);
lista* gerar_intervalo (lista *l, int a, int b);
lista* intercalar(lista *l1, lista *l2);

#endif