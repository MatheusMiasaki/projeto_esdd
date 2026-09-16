#include <stdio.h>
#include <time.h>
// Auxilio de I.A para trabalhar com o tempo de execução do programa.


// Os algoritmos alteram estes contadores durante a ordenacao.
long long comparacoes = 0; //long long é um tipo de dado inteiro que pode armazenar valores maiores do que o tipo int padrão. Ele é usado para contar o número de comparações feitas durante a execução dos algoritmos de ordenação.
long long movimentacoes = 0;
clock_t inicio;
double tempo;

// Zera os contadores e comeca a contar o tempo.
void iniciar_medicao()
{
    comparacoes = 0;
    movimentacoes = 0;
    inicio = clock();
}

// Para o relogio assim que a ordenacao termina.
void finalizar_medicao()
{
    clock_t fim = clock();
    tempo = (double)(fim - inicio) * 1000 / CLOCKS_PER_SEC;
}

// Mostra os dados que foram coletados durante o teste.
void mostrar_metricas(int tamanho)
{
    printf("\n=== Resultado do teste ===\n");
    printf("Quantidade de itens: %d\n", tamanho);
    printf("Tempo gasto: %.10f ms\n", tempo);
    printf("Comparacoes: %lld\n", comparacoes); //Long long int é um tipo de dado inteiro que pode armazenar valores maiores do que o tipo int padrão. 
    printf("Movimentacoes: %lld\n", movimentacoes);
}
