#include <stdio.h>
#include <stdlib.h>

void merge(int v[], int ini, int meio, int fim){
    int i=0,j=0;
    int n1 = meio-ini+1, n2 = fim - meio;
    int *esq=malloc(n1*sizeof(int));
    int *dir = malloc(n2*sizeof(int));

    for (i=0;i<n1;i++){
        esq[i] = v[ini+i];
    }
    for(j=0;j<n2;j++){
        dir[j] = v[meio+1+j];
    }

    i=0,j=0;
    int k=ini;
    while(i<n1 && j<n2){
        if (esq[i]<=dir[j]){
            v[k++] = esq[i++];
        }else{
            v[k++]=dir[j++];
        }
    }
    while(i<n1){
        v[k++]=esq[i++];
    }
    while(j<n2){
        v[k++]=dir[j++];
    }
    free (esq);
    free(dir);
}

void mergesort(int v[], int ini, int fim){
    if (ini<fim){
        int meio=ini+(fim-ini)/2;
        mergesort(v, ini, meio);
        mergesort(v, meio+1, fim);
        merge(v, ini, meio, fim);
        
    }
}
int main(){
    int v[50];
    for (int i=0;i<50;i++){
        v[i] = 50-i;
    
    }

    mergesort(v, 0,49);
    for(int i=0;i<50;i++){
        printf("%d ", v[i]);
    }
}