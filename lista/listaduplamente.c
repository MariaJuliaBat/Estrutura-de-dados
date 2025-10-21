#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;
typedef struct listano ListaNo;

struct lista{
    ListaNo *prim;
    ListaNo *ult;
};

struct listano {
    int elem;
    ListaNo *prox;
    ListaNo *ant;
};

Lista* cria_lista(void){
    Lista* l = (Lista*) malloc(sizeof(Lista));
    l->prim = NULL;
    l->ult = NULL;

    return l;
}

void cria_no(Lista* l, int valor){
    ListaNo *novo = (ListaNo*) malloc(sizeof(ListaNo));
    novo->elem = valor;
    novo->prox = l->prim;
    novo->ant = NULL;

    if(l->prim != NULL){
        l->prim->ant = novo;
    }else{
        l->ult = novo;
    }
    l->prim = novo;
}

void imprime(Lista* l){
    ListaNo* p = l->prim;

    if(p == NULL){
        printf("Lista vazia \n");
    }else{
        for (p = l->prim; p != NULL; p = p->prox){
            printf("Item = %d\n", p->elem);
        }
    }    
}

ListaNo* busca(Lista* l, int valor){
    for (ListaNo* p = l->prim; p != NULL; p = p->prox){
        if (p->elem == valor){
            return p;
        }
    }
    return NULL;
}

int vazia(Lista *l){
    return (l->prim == NULL);
}

void excluir(Lista* l, int valor){
    ListaNo* p = busca(l, valor);

    if(p == NULL){
        return;
    }

    if (p == l->prim){
        l->prim = p->prox;
        p->prox->ant = NULL;
    }else{
        p->ant->prox = p->prox;
    }

    if(p == l->ult){
        l->ult = p->ant;
        p->ant->prox = NULL;
    }else{
        p->prox->ant = p->ant;
    }
    free(p);
}

void libera(Lista* l){
    ListaNo* p = l->prim;

    while (p != NULL){
        ListaNo* t = p->prox;      //guarda referência para próximo elemento
        free(p);                   //libera a memória apontada por p
        p = t;                     //faz p apontar para o próximo elemento
    }
    free(l);    
}

int main(void){
    Lista* l = cria_lista();

    cria_no(l, 23);
    cria_no(l, 45);
    cria_no(l, 56);
    cria_no(l, 78);

    printf("Lista com elementos inseridos \n");
    imprime(l);

    excluir(l,78);

    printf("Lista após exclusão do elemento 78 \n");
    imprime(l);

    excluir(l, 45);

    printf("Lista após exclusão do elemento 45 \n");
    imprime(l);

    libera(l);
    imprime(l);

    return 0;
}
