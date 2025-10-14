#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;
typedef struct listano ListaNo;

struct listaNo{
    int elem;
    ListaNo *prox;
    ListaNo *ant;
}

struct lista{
    Lista *prim;
    Lista *ult;
}

Lista* cria_lista(void){
    Lista *l = (Lista*) malloc (sizeof(Lista));
    l -> prim = NULL;
    l -> ult = NULL;
}


 

