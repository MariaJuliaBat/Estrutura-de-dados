#include <stdio.h>
#include <stdlib.h>


int main(){
    int x, y;
    printf("digite dois numeros:");
    scanf("%d %d", &x, &y );


    if (x > y){
        printf("%d e maior", x);
    }else{
        printf("%d e maior", y);
    }

    return 0;
}