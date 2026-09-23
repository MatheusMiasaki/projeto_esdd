#include <stdio.h>
#include <stdlib.h>

// Funcoes dos outros arquivos
void bubble_sort(int vetor[], int tamanho);
void insertion_sort(int vetor[], int tamanho);
void selection_sort(int vetor[], int tamanho);
void merge_sort(int vetor[], int esquerda, int direita);
void quick_sort(int vetor[], int inicio, int fim);

int *criar_vetor(int tamanho, int tipo); 
int *copiar_vetor(int original[], int tamanho);
void mostrar_vetor(int vetor[], int tamanho);

void iniciar_medicao();
void finalizar_medicao();
void mostrar_metricas(int tamanho);

int main()
{
    int tamanho, tipo, algoritmo, repetir;

    printf("===> Teste de ordenacao <===\n");
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    if (tamanho <= 0)
    {
        printf("Tamanho invalido.\n");
        return 1;
    }

    printf("\nComo voce quer o vetor?\n");
    printf("1 - Aleatorio\n");
    printf("2 - Ordenado\n");
    printf("3 - Invertido\n");
    printf("Escolha: ");
    scanf("%d", &tipo);

    if (tipo < 1 || tipo > 3)
    {
        printf("Opcao invalida.\n");
        return 1;
    }

    int *vetor_original = criar_vetor(tamanho, tipo);

    if (vetor_original == NULL)
    {
        printf("Erro ao criar o vetor.\n");
        return 1;
    }

    do
    {
        printf("\nEscolha o algoritmo:\n");
        printf("1 - Bubble sort\n");
        printf("2 - Insertion sort\n");
        printf("3 - Selection sort\n");
        printf("Escolha: ");
        scanf("%d", &algoritmo);

        if (algoritmo < 1 || algoritmo > 5)
        {
            printf("Algoritmo invalido.\n");
            free(vetor_original);
            return 1;
        }

        // Cada algoritmo recebe uma copia do mesmo vetor original.
        int *vetor = copiar_vetor(vetor_original, tamanho);

        if (vetor == NULL)
        {
            printf("Erro ao copiar o vetor.\n");
            free(vetor_original); 
            return 1;
        }

        if (tamanho <= 50) // só mostra vetor menor ou igual a 5o
        {
            printf("\nVetor antes da ordenacao:\n");
            mostrar_vetor(vetor, tamanho);
        }

        iniciar_medicao();

        switch (algoritmo)
        {
            case 1:
                bubble_sort(vetor, tamanho);
                break;
            case 2:
                insertion_sort(vetor, tamanho);
                break;
            case 3:
                selection_sort(vetor, tamanho);
                break;
            case 4:
                merge_sort(vetor, 0, tamanho-1);
                break;
            case 5:
                quick_sort(vetor, 0, tamanho-1);
                break;
        }

        finalizar_medicao();

        if (tamanho <= 50)
        {
            printf("\nVetor depois da ordenacao:\n");
            mostrar_vetor(vetor, tamanho);
        }

        mostrar_metricas(tamanho);
        free(vetor);

        printf("\nDeseja testar outro metodo com o mesmo vetor?\n");
        printf("1 - Sim\n");
        printf("0 - Nao\n");
        printf("Escolha: ");
        scanf("%d", &repetir);
    } while (repetir == 1);

    free(vetor_original);
    printf("\nPrograma encerrado.\n");
    return 0;
}
