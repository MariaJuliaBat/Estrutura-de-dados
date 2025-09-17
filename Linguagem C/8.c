#include <stdio.h>
#include <stdlib.h>

struct Cadastro {
    char nome[100];
    int idade;
    char endereco[200];
};

// 2. Função que recebe N, aloca o vetor, solicita os dados e retorna o ponteiro
struct Cadastro* criaVetorDeCadastros(int N) {
    // Aloca dinamicamente um vetor de N estruturas 'Cadastro'
    struct Cadastro *vetor = (struct Cadastro*) malloc(N * sizeof(struct Cadastro));

    // Verifica se a alocação de memória foi bem-sucedida
    if (vetor == NULL) {
        printf("Erro: Falha na alocação de memória!\n");
        return NULL;
    }

    printf("\n--- Preencha os dados abaixo ---\n");

    // Loop para solicitar os dados de cada pessoa
    for (int i = 0; i < N; i++) {
        printf("\n--- Cadastro %d ---\n", i + 1);

        printf("Nome: ");
        scanf(" %99[^\n]", vetor[i].nome);

        printf("Idade: ");
        scanf("%d", &vetor[i].idade);

        printf("Endereço: ");
        scanf(" %199[^\n]", vetor[i].endereco);
    }

    // Retorna o ponteiro para o início do vetor alocado
    return vetor;
}

int main() {
    int n_pessoas;
    struct Cadastro *meuVetor;

    printf("Digite o número de pessoas que deseja cadastrar: ");
    scanf("%d", &n_pessoas);

    if (n_pessoas <= 0) {
        printf("O número deve ser positivo.\n");
        return 1;
    }

    // Chama a função para criar e preencher o vetor
    meuVetor = criaVetorDeCadastros(n_pessoas);

    if (meuVetor != NULL) {
        printf("\n\n--- DADOS CADASTRADOS ---\n");
        // Loop apenas para exibir os dados que foram inseridos
        for (int i = 0; i < n_pessoas; i++) {
            printf("\n--- Pessoa %d ---\n", i + 1);
            printf("Nome: %s\n", meuVetor[i].nome);
            printf("Idade: %d\n", meuVetor[i].idade);
            printf("Endereço: %s\n", meuVetor[i].endereco);
        }

        // Libera a memória alocada
        free(meuVetor);
    }

    return 0;
}