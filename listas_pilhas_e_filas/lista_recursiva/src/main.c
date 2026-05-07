#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
    lista *l1 =NULL;
    for (int i=5;i>0;i++){
        l1 = inserir(l1, i);
    }
    printf("teste");
    printa(l1);
}