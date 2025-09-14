#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (){
    char nome [10];
    int dia, mes, ano;
    printf ("Digite seu nome e a data que voce nasceu\n");
    scanf ("%s%d%d%d", nome, &dia, &mes, &ano);
    printf ("%s Nasceu no dia %d/%d/%d \n",nome,dia,mes,ano);
    return 0;
}

