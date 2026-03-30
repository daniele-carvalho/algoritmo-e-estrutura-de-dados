#include <stdio.h>

//Algoritmo que faz ordem decrescente recursivamente.

void decrescente (int n){
    if (n==0){
        return;
    }
    printf("%d", n);
    decrescente(n-1);
}
int main(){
    int n; scanf("%d", &n);
    decrescente(n);

}