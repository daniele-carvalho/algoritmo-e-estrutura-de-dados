#include <stdio.h>

int somatorio(int n){
    if (n==0){
        return 0;
    }
    return n+(somatorio(n-1));
}
int main(){
    int n; scanf("%d", &n);
    printf("%d", somatorio(n));
}