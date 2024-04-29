#include "metodosOrd.h"
#include <stdio.h>
#include <stdlib.h>

// Função CountingSort
unsigned long int countingSort(int *vetor, int tam) {
  int *count, *aux, i, max, atribuicoes;
  max = 0;
  atribuicoes = 0;

  /*
  No counting Sort, não são feitas trocas e comparações da maneira tradicional de um algoritmo de ordenação.
  Para fim de comparação no benchmarking, consideraremos número de "atribuições" como número de "trocas"
  */

  // Acha o maior elemento do vetor
  for(i = 0; i < tam; i++) {
    if (vetor[i] > max) {
      max = vetor[i];
    }
  }

  // Cria um vetor de contagem com tamanho igual ao maior elemento do vetor
  count = (int *)malloc((max + 1) * sizeof(int));
  if(count == NULL)
    return 0;

  // Inicializa o vetor de contagem com zeros
  for(i = 0; i < max + 1; i++) {
    count[i] = 0;
    atribuicoes += 1;
  }

  // Conta a frequência de cada elemento do vetor
  for(i = 0; i < tam; i++) {
    count[vetor[i]]++;
    atribuicoes += 1;  // + 1 atribuição de elemento
  }

  // Acumula as contagens
  for(i = 1; i < max + 1; i++) {
    count[i] += count[i - 1];
    atribuicoes += 1;  // + 1 atribuição de elemento
  }

  // Cria um vetor auxiliar para armazenar os elementos ordenados
  aux = (int *)malloc(tam * sizeof(int));

  // Preenche o vetor auxiliar com os elementos ordenados
  for(i = 0; i < tam; i++) {
    aux[count[vetor[i]] - 1] = vetor[i];
    count[vetor[i]]--;
    atribuicoes += 2;  // + 2 atribuições de elementos
  }

  // Copia o vetor auxiliar para o vetor original
  for(i = 0; i < tam; i++) {
    vetor[i] = aux[i];
    atribuicoes += 1;  // + 1 atribuição de elemento
  }

  free(count);
  free(aux);

  return atribuicoes;  // Retorno é o total de atribuições de elementos
}