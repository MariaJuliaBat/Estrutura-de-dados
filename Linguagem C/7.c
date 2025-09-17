#include <stdio.h>
#include <stdlib.h>

int main(){
    float peso, altura;
    float imc;
    printf("Informe seu peso e sua altura:");
    scanf("%f %f", &peso, &altura);

    imc = peso / (altura * altura);
    printf("Seu IMC e: %.2f\n", imc);

    return 0;
}