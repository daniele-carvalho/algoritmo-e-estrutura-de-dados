#include <stdio.h>

int insection(int v[], int inicio, int tam){
    int menor = inicio;
    if (inicio==tam){
        return 0;
    }

    for (int j=inicio+1; j<tam;j++){
        if (v[j]<v[menor]){
            menor = j;
        }
    }

    int aux = v[inicio];
    v[inicio] = v[menor];
    v[menor] = aux;

    return insection(v, inicio+1, tam);
}

int main(){
    int v[10] = {10, 1, 40, 6, 20, 80, 37, 21, 90, 4};
    insection(v, 0, 10);
}