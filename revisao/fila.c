#include <stdio.h>
#include <stdlib.h>

typedef struct fila Fila;
typedef struct no No;

struct no{
    int item;
    No *prox;
};

struct fila{
    No *prim;
    No *ult
};


Fila* cria(void){
    Fila* f = (Fila*) malloc (sizeof(Fila));
    f->prim = NULL;
    f->ult = NULL;
    
    return f;
}


void adiciona(Fila* f, int valor){
    No *novo = (Fila*) malloc (sizeof(Fila));
    novo->item = valor;
    novo->prox = NULL;

    if (f->prim != NULL){
        f->ult->prox = novo;
    }else{
        f->prim = novo;
    }

    f->ult = novo;
}



int remove(Fila* f){
    No* aux = f->prim;
    int valor;

    if (f->prim == NULL){
        return 0;
    }else{
        valor = aux->item;
        f->prim = aux->prox;
    }
    
    if(f->prim = NULL){
        f->ult = NULL;
    }

    free(aux);
    return valor;
}