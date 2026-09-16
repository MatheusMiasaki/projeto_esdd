// Contadores definidos em metrica.c
extern long long comparacoes;
extern long long movimentacoes;

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
                int auxiliar = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = auxiliar;
                movimentacoes++;
                trocou = 1;
            }
        }
    }
}

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
                vetor[j + 1] = vetor[j];
                movimentacoes++;
                j--;
            }
        }
        vetor[j + 1] = valor; 
        movimentacoes++;
    }
}


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
            int auxiliar = vetor[i];
            vetor[i] = vetor[posicao_menor];
            vetor[posicao_menor] = auxiliar;
            movimentacoes++;
        }
    }
}
