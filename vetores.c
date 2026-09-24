#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Cria e preenche o vetor do jeito escolhido pelo usuario.
int *criar_vetor(int tamanho, int tipo)
{
    int *vetor = malloc(tamanho * sizeof(int));

    if (vetor == NULL)
        return NULL;

    srand(time(NULL));

    for (int i = 0; i < tamanho; i++)
    {
         if (tipo == 4)
        {
            printf("Digite o valor da posicao %d: ", i + 1);
            if (scanf("%d", &vetor[i]) != 1)
            {
                free(vetor);
                return NULL;
            }
        }
        else if (tipo == 1)
            vetor[i] = rand() % 100; 
        else if (tipo == 2)
            vetor[i] = i + 1;
        else
            vetor[i] = tamanho - i;
    }

    return vetor;
}

// Faz uma copia para cada algoritmo testar os mesmos numeros.
int *copiar_vetor(int original[], int tamanho)
{
    int *copia = malloc(tamanho * sizeof(int)); //malloc reserva um bloco de memória do tamanho especificado.

    if (copia == NULL)
        return NULL;

    for (int i = 0; i < tamanho; i++)
        copia[i] = original[i];

    return copia;
}

// Mostra os numeros do vetor na tela.
void mostrar_vetor(int vetor[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
        printf("%d ", vetor[i]);

    printf("\n");
}
