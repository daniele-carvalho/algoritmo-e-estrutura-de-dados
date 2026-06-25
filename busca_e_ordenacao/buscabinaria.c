#include <stdio.h>

int buscabinaria(int v[], int x){
    int d= 100;
    int e=-1, m;

    while (e<d-1){
        m=(d+e)/2;
        if (v[m]<x){
            e=m;
        }else{
            d=m;
        }
    }
    return d;
}

int main(){
    int x; scanf("%d", &x);
    int v[100];
    for (int i=0;i<100;i++){
        v[i] = i;
    }
    printf("%d", buscabinaria( v, x));
}