#include <stdio.h>

int main(){
    int v[10] = {10, 1, 40, 6, 20, 80, 37, 21, 90, 4};
    int menor;
    for (int i=0;i<10;i++){
        menor = i;
        for (int j=i+1; j<10;j++){
            if (v[j]<v[menor]){
                menor =j;
            }
        }
        int aux = v[i];
        v[i] = v[menor];
        v[menor]=aux;
    }
    
    for (int i=0;i<10;i++){
        printf("%d " , v[i]);
    }
}