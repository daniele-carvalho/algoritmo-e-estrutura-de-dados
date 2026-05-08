#include <stdio.h>
#include <string.h>

int palindromo(char str[], int j, int i){
    if (i>j){
        return 1;
    }
    if ((str[i])==str[j]){
        return palindromo(str, i++, j--);
    }
    return 0;
}

int main(){
    char str[50]; scanf("%[^\n]",str);
    int tam = strlen(str);

    if (palindromo(str, tam-1, 0)){
        printf("Palindromo");
    }else{
        printf("Não palindromo");
    }
}