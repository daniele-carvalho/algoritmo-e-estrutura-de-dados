#include <stdio.h>

int buscabin(int x, int v[], int e, int d){
    if (e==d-1){
        return 0;
    }
    
    int m=(e+d)/2;
    if (v[m]==x){
        return m;
    }
    
    if (v[m]<x){
        return buscabin(x, v, m, d);
    }else{
        return buscabin(x, v, e, m);
    }
}

int main(){
    int v[5]={1,8,15,20,37}, x; scanf("%d",&x);
    printf("%d", buscabin(x, v,-1, 5));
}