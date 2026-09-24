#include <stdio.h>

// Contadores definidos em metrica.c
extern long long comparacoes;
extern long long movimentacoes;

// Seção Bubblesort
// compara os pares de vizinhos e troca de posição se o da esquerda for maior que o da direita.
void bubble_sort(int vetor[], int tamanho)
{
    int trocou = 1;

    for (int i = tamanho - 1; i > 0 && trocou == 1; i--)
    {
        trocou = 0;
        for (int j = 0; j < i; j++)
        {
            comparacoes++;
            if (vetor[j] > vetor[j + 1])
            {
                printf("Trocou %d (pos %d) com %d (pos %d)\n", vetor[j], j, vetor[j+1], j+1);
                int auxiliar = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = auxiliar;
                movimentacoes++;
                trocou = 1;
            }
        }
    }
}

// Seção Insertionsort
// percorre a lista pegando o elemento da direita e comparando com os elementos da esquerda, se for menor, muda de posição.
void insertion_sort(int vetor[], int tamanho)
{
    for (int i = 1; i < tamanho; i++)
    {
        int valor = vetor[i];
        int j = i - 1;
        int continuar = 1;

        while (j >= 0 && continuar == 1)
        {
            comparacoes++;

            if (vetor[j] <= valor)
                continuar = 0;
            else
            {
                printf("Trocou %d (pos %d) com %d (pos %d)\n", vetor[j+1], j+1, vetor[j], j);
                vetor[j + 1] = vetor[j];
                movimentacoes++;
                j--;
            }
        }
        if ((j+1) != i){
            printf("Trocou %d (pos %d) com %d (pos %d)\n", vetor[j+1], j+1, valor, i);
            vetor[j + 1] = valor; 
            movimentacoes++;
        }
    }
}

// Seção Selectionsort
// Divide a lista em 2 partes a parte ordenada e a não ordenada, pega o menor elemento da desordenada e move para ordenada.
void selection_sort(int vetor[], int tamanho)
{
    for (int i = 0; i < tamanho - 1; i++)
    {
        int posicao_menor = i;
        for (int j = i + 1; j < tamanho; j++)
        {
            comparacoes++;
            if (vetor[j] < vetor[posicao_menor])
                posicao_menor = j;
        }
        if (posicao_menor != i) 
        {
            printf("Trocou %d (pos %d) com %d (pos %d)\n", vetor[i], i, vetor[posicao_menor], posicao_menor);
            int auxiliar = vetor[i];
            vetor[i] = vetor[posicao_menor];
            vetor[posicao_menor] = auxiliar;
            movimentacoes++;
        }
    }
}

// Seção Mergesort
// Função para intercalar (mesclar) duas metades ordenadas
void intercalar(int vetor[], int esquerda, int meio, int direita) {
    int i, j, k;
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    // Vetores temporários para armazenar as duas metades
    int vetor_esquerda[n1];
    int vetor_direita[n2];

    // Cópia dos dados para os vetores divididos
    for (i = 0; i < n1; i++)
        vetor_esquerda[i] = vetor[esquerda + i];
    for (j = 0; j < n2; j++)
        vetor_direita[j] = vetor[meio + 1 + j];

    // Restauração dos índices iniciais dos vetores
    i = 0; 
    j = 0; 
    k = esquerda; 

    // Intercalação dos elementos no vetor original
    while (i < n1 && j < n2) {
        comparacoes++;
        if (vetor_esquerda[i] <= vetor_direita[j]) {
            printf("Trocou %d (pos %d) com %d (pos %d)\n", vetor[k], k, vetor_esquerda[i], i);
            vetor[k] = vetor_esquerda[i];
            movimentacoes++;
            i++;
        } else {
            printf("Trocou %d (pos %d) com %d (pos %d)\n", vetor[k], k, vetor_direita[j], j);
            vetor[k] = vetor_direita[j];
            movimentacoes++;
            j++;
        }
        k++;
    }

    // Cópia dos elementos restantes do vetor à esquerda, se houver
    while (i < n1) {
        vetor[k] = vetor_esquerda[i];
        i++;
        k++;
    }

    // Cópia dos elementos restantes do vetor à direita, se houver
    while (j < n2) {
        vetor[k] = vetor_direita[j];
        j++;
        k++;
    }
}

// Função principal do Mergesort
void merge_sort(int vetor[], int esquerda, int direita) {
    comparacoes++;
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        merge_sort(vetor, esquerda, meio);
        merge_sort(vetor, meio + 1, direita);

        comparacoes++;
        if (vetor[meio] > vetor[meio+1])
            intercalar(vetor, esquerda, meio, direita);
    }
}

// Seção Quicksort
// Função de particionamento usando o PRIMEIRO elemento como pivo
int particionar(int vetor[], int inicio, int fim) {
    int pivo = vetor[inicio];
    int i = fim + 1;

    for (int j = fim; j >= inicio + 1; j--) {
        comparacoes++;
        if (vetor[j] > pivo) {
            i--;
            if (i != j){
                printf("Trocou %d (pos %d) com %d (pos %d)\n", vetor[i], i, vetor[j], j);
                int temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
                movimentacoes++;
            }
        }
    }
    
    // Troca o pivo para a sua posição correta (i - 1)
    int temp = vetor[i - 1];
    vetor[i - 1] = vetor[inicio];
    vetor[inicio] = temp;

    return (i - 1);
}

// Função principal do Quicksort
void quick_sort(int vetor[], int inicio, int fim){
    comparacoes++;
    if (inicio < fim) {
        int pivo = particionar(vetor, inicio, fim);
        quick_sort(vetor, inicio, pivo - 1);
        quick_sort(vetor, pivo + 1, fim);
    }
}

