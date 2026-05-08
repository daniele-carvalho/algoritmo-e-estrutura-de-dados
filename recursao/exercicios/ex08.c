#include <stdio.h>

/*Projetar algoritmo recursivo que inverta a ordem dos elementos de um vetor*/

void inverte ( int v[], int i, int j){
     if (i>=j){
        return;
     } 

    int temp= v[i];
    v[i]=v[j];
    v[j]=temp;

     inverte(v, i+1, j-1);
}


int main(){
    int vetor[10];
    for (int i=0;i<10;i++){
        scanf("%d", &vetor[i]);
    }
    int tamanhoj = 9;
    inverte(vetor, 0, tamanhoj);
    for(int i=0;i<10;i++){
        printf("%d ", vetor[i]);
    }
    
}   