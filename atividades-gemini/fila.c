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
    No *ult;
};

Fila* criaFila(){
    Fila *p = (Fila*) malloc(sizeof(Fila));
    p->prim = NULL;
    p->ult = NULL;
    return p;
}

void adiciona(Fila* f, int valor){
    No *novoNo = (No*) malloc(sizeof(No));
    novoNo->item = valor;
    novoNo->prox = NULL; //novo nó passa a ser o último
    if (f->ult != NULL){
        f->ult->prox = novoNo; //O antigo último elemento agora deve apontar para o novo nó 
    }else{
        f->prim = novoNo; // Se a fila estava vazia, o novo nó é também o INÍCIO da fila.
    }
    f->ult=novoNo; //fila aponta para novo elemento

}

int desinfileira(Fila* f){
    if (f->prim == NULL){
        return -1;
    }
    No *t = f->prim;
    int v = t->item;
    f->prim = t->prox; // O início da fila agora passa a ser o próximo elemento que estava na lista.
    if (f->prim == NULL){
        f->ult = NULL;
    }
    free(t);
    return v;
}


void exibir(Fila *f){
    No* atual = f->prim;
    while (atual != NULL){
        printf("%d\n", atual->item);
        atual = atual->prox;
    }
}





int main(){
    Fila *minhaFila;
    minhaFila = criaFila();
    char comando;
    int senha;

      while (scanf(" %c", &comando) == 1 && comando != 'X') {
        switch (comando) {
            case 'E':
                scanf("%d", &senha);
                adiciona(minhaFila, senha);
                break;

            case 'D':
                if (minhaFila->prim == NULL) {
                    printf("vazia\n");
                } else {
                    printf("%d\n", desinfileira(minhaFila));
                }
                break;

            case 'P':
                if (minhaFila->prim == NULL) {
                    printf("vazia\n");
                } else {
                    printf("%d\n", minhaFila->prim->item);
                }
                break;
        }
    }

    printf("\n");
    exibir(minhaFila);

    while (minhaFila->prim != NULL) {
        desinfileira(minhaFila);
    }

    free(minhaFila);

    return 0;
}