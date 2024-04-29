#include "metodosOrd.h"
#include "utilidades.h"
#include <stdio.h>
#include <stdlib.h>

// Função da ordenação Insertion Sort
void insercao(int *v, int tam, unsigned long int *comp, unsigned long int *troc) {
  int i, pos, aux;
  for(i=1;i<tam;i++) {
    pos = i-1;  // Posição é igual a posição do ultimo elemento ordenado
    aux = v[i]; // aux é igual ao valor do primeiro elemento desordenado
    *comp = *comp + 1;  // + 1 comparação de elementos
    while(pos >= 0 && aux < v[pos]) {  // Se ainda existir ordenados e o elemento desordenado for menor que o ordenado
      v[pos+1] = v[pos];               // Posição do elemento desordenado passa a guardar o elemento ordenado
      pos = pos-1;                     // Posição passa ser o próxima elemento ordenado, se houver
      *troc = *troc + 1;               // + 1 troca de elementos
      *comp = *comp + 1;               // + 1 comparação de elementos
    }
    v[pos+1] = aux;  // Posição do elemento ordenado passa a guardar o elemento desordenado
  }
  return;
}