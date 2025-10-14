#include <stdio.h>
#include <stdlib.h>

typedef struct pilha Pilha;
typedef struct pilhano PilhaNo;

struct pilhano{
    int item;
    PilhaNo *prox;
};

struct pilha{
    PilhaNo *topo;
};

void inicia(Pilha *p){
    p -> topo = NULL;
}


void push(Pilha *p, int valor){
    PilhaNo *novoNo = (PilhaNo*) malloc (sizeof(PilhaNo));
    novoNo -> item = valor;  //Preenche o novo nó com o valor
    novoNo -> prox = p -> topo;  // O "próximo" do novo nó aponta para o antigo topo
    p -> topo = novoNo; //O topo da pilha agora é o novo nó
}


int pop(Pilha *p){
    if (p -> topo == NULL){
        return -1;
    }
    PilhaNo* t = p -> topo; //Cria um ponteiro temporário 't' para guardar o endereço do topo.
    int v = t -> item; //Salva o valor do item que será removido.
    p -> topo = t -> prox; //O topo da pilha agora passa a ser o próximo da lista.
    free(t);
    return v;
}


int topo(Pilha* p){
    if (p -> topo!= NULL){
        return p -> topo -> item;
    }
    return -1;
}



void exibir(Pilha *p){
    PilhaNo * atual = p -> topo;
    while (atual != NULL){
        printf("%d\n", atual->item);
        atual = atual -> prox;
    }
}


int main(){
    Pilha minhaPilha;
    inicia(&minhaPilha);

    char comando;
    int valor;

    while (scanf(" %c", &comando) == 1 && comando != 'X'){
        switch (comando) {
            case 'E': 
                scanf("%d", &valor);//Lê o valor a ser empilhado
                push(&minhaPilha, valor);
                break;

            case 'D': 
                //Verifica se a pilha está vazia antes de chamar a função pop
                if (minhaPilha.topo == NULL) {
                    printf("vazia\n");
                } else {
                    //Se não estiver vazia, chama pop e imprime o resultado
                    printf("%d\n", pop(&minhaPilha));
                }
                break;

            case 'T': 
                //Verifica se a pilha está vazia antes de chamar a função topo
                if (minhaPilha.topo == NULL) {
                    printf("vazia\n");
                } else {
                    //Se não estiver vazia, chama topo e imprime o resultado
                    printf("%d\n", topo(&minhaPilha));
                }
                break;
        }
    }

    //Quando o loop termina (após ler 'X'), imprime a saída final
    printf("\n");             // Imprime a linha em branco obrigatória
    exibir(&minhaPilha);    // Usa a sua função para mostrar o estado final da pilha

    return 0;
}