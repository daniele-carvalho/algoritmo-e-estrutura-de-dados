#include <stdio.h>

//Algoritmo que faz ordem crescente recursivamente.

void crescente (int cont, int n){
    if (cont==0){
        printf("%d", n);
        return;
    }
    printf("%d ", n-cont);

    crescente(cont-1, n);


}

int main(){
    int numero;
    scanf("%d", &numero);
    int cont = numero-1;
    (crescente(cont, numero));

}