#include "metodosOrd.h"
#include "utilidades.h"
#include <stdio.h>
#include <stdlib.h>

// Função que encontra o menor elemento (selection sort)
int menorElemento(int *v, int i, int tam, unsigned long int *comp) {
  int menor, j;
  menor = i; // Toma menor como i inicialmente
  for(j=i+1;j<tam;j++) {
    if(v[j] < v[menor]) { // Se achar um menor
      menor = j;          // Atualiza menor
    }
    *comp = *comp + 1; // + 1 comparação de elementos
  }
  return menor;
}

// Função da ordenação Selection Sort
void selecao(int *v, int tam, unsigned long int *comp, unsigned long int *troc) {
  int i, j, menor, aux;
  for(i=0;i<tam-1;i++) {
    menor = menorElemento(v, i, tam, comp);  // Acha o menor elemento da lista desordenada
    if(v[menor] < v[i]) {  // Se encontrar um elemento menor
      troca(v,i,menor);    // Troca os dois
      *troc = *troc + 1;  // + 1 troca de elementos
    } 
    *comp = *comp + 1; // + 1 comparação de elementos
  }
  return;
}
