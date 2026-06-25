#include <stdio.h>

void bubblerec( int tam, int v[]){
    if (tam<2){
        return;
    }
    for (int i=0;i<tam-1;i++){
        if (v[i]>v[i+1]){
            int aux= v[i];
            v[i]=v[i+1];
            v[i+1]=aux;
        }
    }
    return bubblerec(tam-1, v);
}

int main(){
     int v[10]= {10,9,1,7,3,11,2,4,12,20};
     bubblerec(10, v);
     for(int i=0;i<10;i++){
         printf("%d ", v[i]);
     }
}