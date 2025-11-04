#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_COMPONENTES 20

// -----------------------------
// Struct do componente
// -----------------------------
typedef struct {
    char nome[30];
    char tipo[20];
    int prioridade;
} Componente;

// -----------------------------
// Funções de ordenação
// -----------------------------

// Bubble Sort por nome
int bubbleSortNome(Componente arr[], int n) {
    int comparacoes = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparacoes++;
            if (strcmp(arr[j].nome, arr[j + 1].nome) > 0) {
                Componente temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return comparacoes;
}

// Insertion Sort por tipo
int insertionSortTipo(Componente arr[], int n) {
    int comparacoes = 0;
    for (int i = 1; i < n; i++) {
        Componente key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            comparacoes++;
            if (strcmp(arr[j].tipo, key.tipo) > 0) {
                arr[j + 1] = arr[j];
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
    return comparacoes;
}

// Selection Sort por prioridade
int selectionSortPrioridade(Componente arr[], int n) {
    int comparacoes = 0;
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            comparacoes++;
            if (arr[j].prioridade < arr[min_idx].prioridade)
                min_idx = j;
        }
        if (min_idx != i) {
            Componente temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
    return comparacoes;
}

// -----------------------------
// Busca binária por nome
// -----------------------------
int buscaBinariaPorNome(Componente arr[], int n, char chave[], int *comparacoes) {
    int inicio = 0, fim = n - 1;
    *comparacoes = 0;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        (*comparacoes)++;
        int cmp = strcmp(arr[meio].nome, chave);
        if (cmp == 0) return meio;
        else if (cmp < 0) inicio = meio + 1;
        else fim = meio - 1;
    }
    return -1;
}

// -----------------------------
// Função para mostrar componentes
// -----------------------------
void mostrarComponentes(Componente arr[], int n) {
    printf("\n=== Componentes da Torre ===\n");
    printf("%-25s %-15s %-10s\n", "Nome", "Tipo", "Prioridade");
    for (int i = 0; i < n; i++) {
        printf("%-25s %-15s %-10d\n", arr[i].nome, arr[i].tipo, arr[i].prioridade);
    }
}

// -----------------------------
// Função principal
// -----------------------------
int main() {
    Componente componentes[MAX_COMPONENTES];
    int n = 0;

    printf("Quantos componentes deseja cadastrar (max 20)? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Entrada invalida! Encerrando programa.\n");
        return 1;
    }
    getchar(); // limpa buffer

    if (n > MAX_COMPONENTES) n = MAX_COMPONENTES;

    // Cadastro dos componentes
    for (int i = 0; i < n; i++) {
        printf("\nComponente %d\n", i + 1);

        printf("Nome: ");
        fgets(componentes[i].nome, sizeof(componentes[i].nome), stdin);
        componentes[i].nome[strcspn(componentes[i].nome, "\n")] = 0;

        printf("Tipo: ");
        fgets(componentes[i].tipo, sizeof(componentes[i].tipo), stdin);
        componentes[i].tipo[strcspn(componentes[i].tipo, "\n")] = 0;

        printf("Prioridade (1 a 10): ");
        if (scanf("%d", &componentes[i].prioridade) != 1) {
            printf("Entrada invalida! Encerrando programa.\n");
            return
        }

