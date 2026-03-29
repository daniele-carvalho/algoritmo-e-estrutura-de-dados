#include <stdio.h>
#include <stdlib.h>
int main(){
    int *x;
    x= calloc(1, sizeof(int));

    if (x){
        printf("memoria alocada");
    }else{
        printf("erro");
    }

}