#include "teste.h"
#include "geraVetor.h"
#include "metodosOrd.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função que realiza um teste em um algoritmo especifico com um vetor e retorna tempo gasto, comparações e trocas realizadas
teste testeAlgoritmo(int *v, int tam, int metodo) {
  unsigned long int comp, troc;
  float temp;
  teste t;
  clock_t relogio;  // variavel que guarda clocks do processador
  comp = 0;
  troc = 0;

  relogio = clock();
  if(metodo==0)  // Selection Sort
    selecao(v,tam,&comp,&troc);
  if(metodo==1)  // Insertion Sort
    insercao(v,tam,&comp,&troc);
  if(metodo==2)  // Merge Sort
    mergeSort(v,0,tam - 1,&comp,&troc);
  if(metodo==3)  // Quick Sort
    quickSort(v,0,tam - 1,&comp,&troc);
  if(metodo==4)  // Counting Sort
    troc = countingSort(v, tam);

  relogio = clock() - relogio;  // clock atual - clock registrado anteriormente
  temp = ((float)relogio)/CLOCKS_PER_SEC; // convertendo valor de clock para valor de tempo

  // Atualizando valores da struct teste que será retornada
  t.tempo = temp;
  t.comparacoes = comp;
  t.trocas = troc;
  return t;
}