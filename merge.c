#include "metodosOrd.h"
#include "utilidades.h"
#include <stdio.h>
#include <stdlib.h>

// Função da ordenação Merge Sort
void mergeSort(int *v, int inicio, int fim, unsigned long int *comp, unsigned long int *troc) {
    int meio;
    meio = (inicio+fim)/2;  // Obtem o valor do "meio"
    if(inicio < fim) {  // Enquanto houver mais de um elemento
        mergeSort(v, inicio, meio, comp, troc);  // Chama mergeSort para a primeira metade
        mergeSort(v, meio+1, fim, comp, troc);   // Chama mergeSort para a segunda metade
        merge(v, inicio, meio, fim, comp, troc); // Junta as duas metades de forma ordenada com merge
    }
    return;
}

// Função que faz a fusão de dois vetores pré-ordenados e os copia para o vetor original
void merge(int *v, int inicio, int meio, int fim, unsigned long int *comp, unsigned long int *troc) {
  int ini1, ini2, iniAux, tam;
  int *vAux;
  ini1 = inicio; ini2 = meio+1; iniAux = 0; tam = fim-inicio+1;  // Criação de váriaveis para melhor leitura do código
  vAux = (int*)malloc(tam * sizeof(int));

  while(ini1 <= meio && ini2 <= fim) {  // Enquanto há elementos nas duas metades
    if(v[ini1] < v[ini2]) {             // Se o elemento da metade 1 for menor que da metade 2
      vAux[iniAux] = v[ini1];           // Vetor auxiliar recebe o elemento da metade 1
      ini1++;  // próximo elemento
    } 
    else {                              // Se o elemento da metade 2 for maior
      vAux[iniAux] = v[ini2];           // Vetor auxiliar recebe o elemento da metade 2
      ini2++;  // próximo elemento
    }
    iniAux++; // próximo elemento do vetor auxiliar
    *comp = *comp + 1;  // + 1 comparação de elementos
    *troc = *troc + 1;  // + 1 troca de elementos
  }

  while(ini1 <= meio) {                 //Caso ainda haja elementos na primeira metade
    vAux[iniAux] = v[ini1];             // Vetor auxiliar recebe o elemento da metade 1
    iniAux++;  // próximo elemento do vetor auxiliar
    ini1++;    // próximo elemento
    *troc = *troc + 1;  // + 1 troca de elementos
  }

  while(ini2 <= fim) {                  //Caso ainda haja elementos na segunda metade
    vAux[iniAux] = v[ini2];             // Vetor auxiliar recebe o elemento da metade 2
    iniAux++;  // próximo elemento do vetor auxiliar
    ini2++;    // próximo elemento
    *troc = *troc + 1;  // + 1 troca de elementos
  }

  for(iniAux = inicio; iniAux <= fim; iniAux++) {  // Move os elementos de volta para o v original
    v[iniAux] = vAux[iniAux-inicio];               // Elemento de v recebe o elemento equivalente em vAux
    *troc = *troc + 1;  // + 1 troca de elementos
  }
  free(vAux);
}