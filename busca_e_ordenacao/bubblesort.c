#include <stdio.h>

int main(){
    int v[10]= {10,9,1,7,3,11,2,4,12,20};
    
    int tam=10, troca=1;
    while(troca){
        troca=0;
        for (int i=0;i<tam-1;i++){
            if (v[i]>v[i+1]){
                int aux=v[i];
                v[i]= v[i+1];
                v[i+1] = aux;
                troca = 1;
            }
        }
        tam--;
    }

    for (int i=0;i<10;i++){
        printf("%d ", v[i]);
    }
}