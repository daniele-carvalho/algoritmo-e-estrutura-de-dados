#include <stdio.h>
#include <stdlib.h>
#include "../include/lista.h"

int main(){
    lista* l =NULL;

    for (int i=1;i<=7;i++){
        l = inserir(l, i);
    }
    printar(l);
    remover(l,1 );
    remover(l,2);
    remover(l,3);
    printar(l);
}


