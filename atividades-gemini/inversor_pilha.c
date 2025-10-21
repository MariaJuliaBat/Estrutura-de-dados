#include <stdio.h>
#include <stdlib.h>

typedef struct pilha Pilha;
typedef struct no No;

struct no{
    int item;
    No *prox;
};

struct pilha{
    No *topo;
};


Pilha* criaPilha(){
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}



void push(Pilha* p, int valor){
    No *novoNo = (No*) malloc(sizeof(No));
    novoNo->item = valor;
    novoNo->prox = p->topo;
    p->topo = novoNo;
}


int pop(Pilha* p){
    if (p->topo == NULL){
        return -1;
    };

    
}
