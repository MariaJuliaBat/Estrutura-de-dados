#include <stdio.h>
#include <stdlib.h> // Essencial para malloc() e free()

int main() {
    // --- PASSO 1: Declarar variáveis e perguntar o tamanho ---
    int tamanho;
    int *vetor; // Um ponteiro para um inteiro. Ele vai guardar o "endereço" do nosso vetor.
    int i;      // Variável para usar nos loops (for)

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    // --- PASSO 2: Alocação Dinâmica ---
    // Pedimos ao sistema operacional um bloco de memória que caiba 'tamanho' números inteiros.
    // malloc retorna o endereço do início desse bloco de memória.
    vetor = (int*) malloc(tamanho * sizeof(int));

 
    // --- PASSO 3: Ler os valores do vetor ---
    printf("\nDigite os %d valores do vetor:\n", tamanho);
    for (i = 0; i < tamanho; i++) {
        printf("Elemento %d: ", i);
        scanf("%d", &vetor[i]); // Lê um número e guarda na posição i do vetor
    }

    // --- PASSO 4: Imprimir o vetor ---
    printf("\nO vetor que você digitou foi:\n");
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]); // Imprime o valor da posição i, seguido de um espaço
    }
    printf("\n");

    // --- PASSO 5: Liberar a memória alocada ---
    // A regra de ouro: Toda memória alocada com malloc() DEVE ser liberada com free().
    free(vetor);

    return 0; // Indica que o programa terminou com sucesso
}