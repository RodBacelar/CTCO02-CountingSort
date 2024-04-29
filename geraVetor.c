#include "geraVetor.h"
#include <stdio.h>
#include <stdlib.h>

// Função para Gerar um Vetor de Números Aleatórios
int *geraAleatorios(int tam, int semente) {
  int *vetor;
  int i;

  // Aloca o vetor
  vetor = (int *)malloc(tam * sizeof(int));
  if (vetor == NULL)
    return NULL;

  // Preenche o vetor com números aleatórios
  srand(semente);
  for (i = 0; i < tam; i++) {
    vetor[i] = rand() % tam;
  }

  return vetor;
}

// Função para Gerar um Vetor de Números Quase Ordenados
int *geraQuaseOrdenados(int tam, int porcentagem) {
  int *vetor;
  int i;
  int nDesor;
  int aux;
  int posA;

  // Calcula o número de elementos desordenados
  nDesor = tam * porcentagem / 100;

  vetor = geraOrdenados(tam, 0);

  // Não pode haver apenas UM elemento desordenado	
  if (nDesor == 1)
    return vetor;

  for (i = 0; i < nDesor; i++) {

    // Procura uma posição aleatória dentro da parte que será desordenada do vetor
    do {
      posA = rand() % nDesor;

    } while (vetor[posA] == i);

    // Troca o elemento na posição aleatória com o elemento na posição i
    aux = vetor[i];
    vetor[i] = vetor[posA];
    vetor[posA] = aux;
  }

  return vetor;
}

// Função para Gerar um Vetor de Números Ordenados
int *geraOrdenados(int tam, int ordem) {
  int *vetor;
  int i;

  // Aloca o vetor
  vetor = (int *)malloc(tam * sizeof(int));
  if (vetor == NULL)
    return NULL;

  // Ordem Crescente
  if (ordem == 0) {
    for (i = 0; i < tam; i++) {
      vetor[i] = i;
    }
  }

  // Ordem Decrescente
  if (ordem == 1) {
    for (i = 0; i < tam; i++) {
      vetor[tam - i - 1] = i;
    }
  }

  return vetor;
};
