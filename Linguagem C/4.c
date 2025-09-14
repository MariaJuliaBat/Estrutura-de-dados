#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int num;
    printf("Digite um numero\n");
    scanf("%d", &num);

    while (num >= 0){
        printf("%d ", num);
        num--;
    }
    printf("\n");
    return 0;
}