#include "geraVetor.h"
#include "teste.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ALGORITMOS 5
#define NUM_TAMANHOS 5
#define NUM_EXECUCOES 1

void executarTeste(int algoritmo, int tamanho, int *vetor);
void imprimirResultados(float tempoMedio, unsigned long int compMedias,
                        unsigned long int trocMedias);

int main() {
  int sair;
  int algoritmo;
  printf("Escolha o algoritmo a ser testado:\n");
  printf("0 - Selection\n1 - Insertion\n2 - Merge\n3 - Quick\n4 - Counting\n");
  scanf("%d", &algoritmo);

  int tamanhos[NUM_TAMANHOS] = {1000, 10000, 100000, 1000000, 10000000};
  int i, j;

  for (i = 0; i < NUM_TAMANHOS; i++) {
    printf("\n\nTamanho do vetor: %d\n", tamanhos[i]);
    for (j = 0; j < NUM_EXECUCOES; j++) {
      int *vetor = geraAleatorios(
          tamanhos[i], time(NULL) + j); // Semente diferente para cada execução
      executarTeste(algoritmo, tamanhos[i], vetor);
      free(vetor);
    }
  }

  printf("Digite um número para fechar: ");
  scanf("%d", &sair);
  return 0;
}

void executarTeste(int algoritmo, int tamanho, int *vetor) {
  teste resultado;
  float tempoTotal = 0; // Variável para acumular o tempo total das execuções
  unsigned long int compTotal = 0, trocTotal = 0;
  int *vetorCrescente, *vetorDecrescente, *vetorQuaseOrdenado, *vetorAleatorio;

  // Aleatório (executa apenas 5 vezes)
  float mediaAleatorio = 0;
  unsigned long int compAleatorio = 0, trocAleatorio = 0;
  for (int i = 0; i < 5; i++) {
    vetorAleatorio = geraAleatorios(tamanho, i);
    resultado = testeAlgoritmo(vetorAleatorio, tamanho, algoritmo);
    printf("Aleatorio - Comparacoes: %lu, Trocas: %lu, Tempo: %.2f ms\n",
           resultado.comparacoes, resultado.trocas, resultado.tempo * 1000);
    tempoTotal += resultado.tempo;
    mediaAleatorio += resultado.tempo;      // Acumula os tempos
    compAleatorio += resultado.comparacoes; // Acumula as comparações
    trocAleatorio += resultado.trocas;      // Acumula as trocas
  }
  mediaAleatorio /= 5; // Calcula a média dos tempos
  compAleatorio /= 5;  // Calcula a média das comparações
  trocAleatorio /= 5;  // Calcula a média das trocas
  printf("Media Aleatorio - Tempo: %.2f ms, Comparacoes: %lu, Trocas: %lu\n",
         mediaAleatorio * 1000, compAleatorio, trocAleatorio);

  // Crescente
  vetorCrescente = geraOrdenados(tamanho, 0);
  resultado = testeAlgoritmo(vetorCrescente, tamanho, algoritmo);
  printf("\nCrescente - Comparacoes: %lu, Trocas: %lu, Tempo: %.2f ms\n",
         resultado.comparacoes, resultado.trocas, resultado.tempo * 1000);
  tempoTotal += resultado.tempo;
  compTotal += resultado.comparacoes;
  trocTotal += resultado.trocas;
  free(vetorCrescente);

  // Decrescente
  vetorDecrescente = geraOrdenados(tamanho, 1);
  resultado = testeAlgoritmo(vetorDecrescente, tamanho, algoritmo);
  printf("\nDecrescente - Comparacoes: %lu, Trocas: %lu, Tempo: %.2f ms\n\n",
         resultado.comparacoes, resultado.trocas, resultado.tempo * 1000);
  tempoTotal += resultado.tempo;
  compTotal += resultado.comparacoes;
  trocTotal += resultado.trocas;
  free(vetorDecrescente);

  // Quase Ordenado (executa apenas 5 vezes)
  float mediaQuaseOrdenado = 0;
  unsigned long int compQuaseOrdenado = 0, trocQuaseOrdenado = 0;
  for (int i = 0; i < 5; i++) {
    vetorQuaseOrdenado = geraQuaseOrdenados(tamanho, 10);
    resultado = testeAlgoritmo(vetorQuaseOrdenado, tamanho, algoritmo);
    printf("Quase Ordenado - Comparacoes: %lu, Trocas: %lu, Tempo: %.2f ms\n",
           resultado.comparacoes, resultado.trocas, resultado.tempo * 1000);
    tempoTotal += resultado.tempo;
    mediaQuaseOrdenado += resultado.tempo;      // Acumula os tempos
    compQuaseOrdenado += resultado.comparacoes; // Acumula as comparações
    trocQuaseOrdenado += resultado.trocas;      // Acumula as trocas
    free(vetorQuaseOrdenado);
  }
  mediaQuaseOrdenado /= 5; // Calcula a média dos tempos
  compQuaseOrdenado /= 5;  // Calcula a média das comparações
  trocQuaseOrdenado /= 5;  // Calcula a média das trocas
  printf(
      "Media Quase Ordenado - Tempo: %.2f ms, Comparacoes: %lu, Trocas: %lu\n",
      mediaQuaseOrdenado * 1000, compQuaseOrdenado, trocQuaseOrdenado);

  // Imprimir médias
  imprimirResultados(tempoTotal / 15, compTotal / 15,
                     trocTotal /
                         15); // Dividido por 15 pois são 15 execuções no total
}

void imprimirResultados(float tempoMedio, unsigned long int compMedias,
                        unsigned long int trocMedias) {
  printf("\nMedia dos resultados:\n");
  printf("Tempo medio: %.2f ms\n", tempoMedio * 1000);
  printf("Comparacoes medias: %lu\n", compMedias);
  printf("Trocas medias: %lu\n", trocMedias);

}
