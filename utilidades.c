#include "utilidades.h"
#include <stdio.h>
#include <stdlib.h>

// Função que faz a troca entre dois elementos de um vetor
void troca(int *v, int i, int j) {
  int aux;
  aux = v[i];
  v[i] = v[j];
  v[j] = aux;
  return;
}

// Função que imprime os dados de um vetor
void imprimeVet(int *v, int tam) {
  int i;
  for(i=0;i<tam;i++) {
    printf("%d\n", v[i]);
  }
  return;
}