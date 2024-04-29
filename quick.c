#include "metodosOrd.h"
#include "utilidades.h"
#include <stdio.h>
#include <stdlib.h>

// Função da ordenação Quick Sort
void quickSort(int *v, int inicio, int fim, unsigned long int *comp, unsigned long int *troc) {
  int pivo;
  if(inicio<fim){  // Enquanto houver mais de um elemento no vetor
    pivo = particiona(v,inicio,fim, comp, troc);  // Será feito a partição do vetor e atribuido ao pivô seu valor
    quickSort(v, inicio, pivo-1, comp, troc);     // Chama quickSort para a parte do vetor anterior ao pivô
    quickSort(v, pivo+1, fim, comp, troc);        // Chama quickSort para a parte do vetor posterior ao pivô
  }
  return;
}

// Função que encontra a posição do vetor e faz as trocas necesssárias
int particiona(int *v, int inicio, int fim, unsigned long int *comp, unsigned long int *troc) {
  int pivo, pos, i, aux;
  pivo = v[inicio];  // Seleciona pivô como o primeiro elemento
  pos = inicio;      // Posição recebe o índice do inicio
  for(i=inicio+1;i<=fim;i++) {
    if(v[i]<pivo) {        // Se o elemento for menor que o pivô
      pos = pos+1;         // Posição é incrementada
      *comp = *comp + 1;   // + 1 comparação de elementos
      if(i!=pos) {         // Se o indice atual for diferente de posição
        troca(v,i,pos);    // Troca o elemento i com o elemento posição
        *troc = *troc + 1; // + 1 troca de elementos
      }
    }
  }
  troca(v,inicio,pos);     // Coloca pivô em sua posição certa
  *troc = *troc + 1;       // + 1 troca de elementos
  return pos;
}