#include <stdio.h>

long long fatorial (int i, long long n){
    if (n==0){
        return 1;
    }
    if (i==0){
        return 1;
    }
    return i*(n*fatorial(i-1, n-1));
}

int main(){
    long long n; scanf("%ld", &n);
    int i=n;
    printf("%ld", fatorial(i, n));

}

/*
superfatorial: 5! * 4! * 3! * 2! * 1! 
i= começa do 5 e vai até 0
pra cada iteração i-1 até 0


*/