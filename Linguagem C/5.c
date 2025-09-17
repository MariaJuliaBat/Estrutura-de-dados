#include <stdio.h>
#include <stdlib.h>


int main(){
    int num;
    int i;
    printf("Digite um numero:");
    scanf("%d", &num);

    printf("Os divisores de %d sao:", num);


    for (i = 1; i <= num; i++){
        if (num % i == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0; 
}

