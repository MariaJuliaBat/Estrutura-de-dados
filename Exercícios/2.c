#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// --- Funções Auxiliares (Não precisam ser alteradas) ---

void inverter(char str[]) {
    int tamanho = strlen(str);
    for (int i = 0; i < tamanho / 2; i++) {
        char temp = str[i];
        str[i] = str[tamanho - 1 - i];
        str[tamanho - 1 - i] = temp;
    }
}

void removerZerosEsquerda(char str[]) {
    if (strcmp(str, "0") == 0) return;
    int i = 0, j = 0;
    while (str[i] == '0' && str[i+1] != '\0') {
        i++;
    }
    if (i > 0) {
        while (str[i] != '\0') {
            str[j++] = str[i++];
        }
        str[j] = '\0';
    }
}

int comparar(char num1[], char num2[]) {
    char temp1[2001], temp2[2001];
    strcpy(temp1, num1);
    strcpy(temp2, num2);
    removerZerosEsquerda(temp1);
    removerZerosEsquerda(temp2);
    int tam1 = strlen(temp1);
    int tam2 = strlen(temp2);
    if (tam1 > tam2) return 1;
    if (tam1 < tam2) return -1;
    return strcmp(temp1, temp2);
}


// --- Funções de Operação (Corrigidas e Revisadas) ---

void subtrairNucleo(char num1[], char num2[], char resultado[]) {
    char n1[2001], n2[2001];
    strcpy(n1, num1);
    strcpy(n2, num2);
    inverter(n1); inverter(n2);
    int tam1 = strlen(n1);
    int tam2 = strlen(n2);
    int borrow = 0;
    int k = 0;
    for (int i = 0; i < tam1; i++) {
        int digito1 = n1[i] - '0';
        int digito2 = (i < tam2) ? n2[i] - '0' : 0;
        int sub = digito1 - digito2 - borrow;
        if (sub < 0) {
            sub += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        resultado[k++] = sub + '0';
    }
    resultado[k] = '\0';
    inverter(resultado);
    removerZerosEsquerda(resultado);
}

void subtrair(char num1[], char num2[], char resultado[]) {
    int cmp = comparar(num1, num2);
    if (cmp == 0) {
        strcpy(resultado, "0");
        return;
    }
    if (cmp > 0) {
        subtrairNucleo(num1, num2, resultado);
    } else {
        subtrairNucleo(num2, num1, resultado);
        char temp[4002];
        sprintf(temp, "-%s", resultado);
        strcpy(resultado, temp);
    }
}

void somar(char num1[], char num2[], char resultado[]) {
    char n1[2001], n2[2001];
    strcpy(n1, num1);
    strcpy(n2, num2);
    inverter(n1); inverter(n2);
    int tam1 = strlen(n1);
    int tam2 = strlen(n2);
    int tam_max = (tam1 > tam2) ? tam1 : tam2;
    int carry = 0;
    int k = 0;
    for (int i = 0; i < tam_max; i++) {
        int digito1 = (i < tam1) ? n1[i] - '0' : 0;
        int digito2 = (i < tam2) ? n2[i] - '0' : 0;
        int soma_digitos = digito1 + digito2 + carry;
        resultado[k++] = (soma_digitos % 10) + '0';
        carry = soma_digitos / 10;
    }
    if (carry > 0) {
        resultado[k++] = carry + '0';
    }
    resultado[k] = '\0';
    inverter(resultado);
}

void multiplicar(char num1[], char num2[], char resultado[]) {
    if (strcmp(num1, "0") == 0 || strcmp(num2, "0") == 0) {
        strcpy(resultado, "0");
        return;
    }
    int tam1 = strlen(num1);
    int tam2 = strlen(num2);
    int res_int[tam1 + tam2];
    memset(res_int, 0, sizeof(res_int));
    for (int i = tam1 - 1; i >= 0; i--) {
        for (int j = tam2 - 1; j >= 0; j--) {
            int mult = (num1[i] - '0') * (num2[j] - '0');
            int soma = mult + res_int[i + j + 1];
            res_int[i + j] += soma / 10;
            res_int[i + j + 1] = soma % 10;
        }
    }
    int k = 0;
    int i = 0;
    while (i < tam1 + tam2 - 1 && res_int[i] == 0) {
        i++;
    }
    while (i < tam1 + tam2) {
        resultado[k++] = res_int[i++] + '0';
    }
    resultado[k] = '\0';
}

void dividir(char num1[], char num2[], char resultado[]) {
    if (strcmp(num2, "0") == 0) {
        strcpy(resultado, "Erro"); return;
    }
    if (comparar(num1, num2) < 0) {
        strcpy(resultado, "0"); return;
    }
    char quociente[2001] = "";
    char dividendo_parcial[2001];
    strcpy(dividendo_parcial, "");
    char temp[2001];
    int tam1 = strlen(num1);
    int idx_dividendo = 0;
    int idx_quociente = 0;

    while (idx_dividendo < tam1) {
        int len_parcial = strlen(dividendo_parcial);
        dividendo_parcial[len_parcial] = num1[idx_dividendo];
        dividendo_parcial[len_parcial + 1] = '\0';
        removerZerosEsquerda(dividendo_parcial);
        
        int count = 0;
        while (comparar(dividendo_parcial, num2) >= 0) {
            subtrair(dividendo_parcial, num2, temp);
            strcpy(dividendo_parcial, temp);
            count++;
        }
        if (idx_quociente > 0 || count > 0 || strlen(quociente) > 0) {
           quociente[idx_quociente++] = count + '0';
        }
        idx_dividendo++;
    }
    quociente[idx_quociente] = '\0';
    if(strlen(quociente) == 0) strcpy(quociente, "0");
    removerZerosEsquerda(quociente);
    strcpy(resultado, quociente);
}


// --- Função Principal ---
int main() {
    char operacao[20];
    char num1[2001];
    char num2[2001];
    char resultado[4002];

    // Lê a operação, o primeiro número e o segundo número
    scanf("%s", operacao);
    scanf("%s", num1);
    scanf("%s", num2);

    // Escolhe a função correta
    if (strcmp(operacao, "SOMA") == 0) {
        somar(num1, num2, resultado);
    } else if (strcmp(operacao, "SUBTRACAO") == 0) {
        subtrair(num1, num2, resultado);
    } else if (strcmp(operacao, "MULTIPLICACAO") == 0) {
        multiplicar(num1, num2, resultado);
    } else if (strcmp(operacao, "DIVISAO") == 0) {
        dividir(num1, num2, resultado);
    } else {
        strcpy(resultado, "Operacao invalida");
    }

    // Imprime APENAS o resultado final
    printf("%s\n", resultado);

    return 0;
}