/*
Descrição das funções relacionadas aos algoritmos de ordenação
comp e troc são ponteiros que serão usados de parâmetro na chamada dos metodos, que guardarão a quantidade de comparações
e trocas de uma determinada ordenação
*/

// Função que encontra o menor elemento (selection sort)
int menorElemento(int *v, int i, int tam, unsigned long int *comp);

// Função da ordenação Selection Sort
void selecao(int *v, int tam, unsigned long int *comp, unsigned long int *troc);

// Função da ordenação Insertion Sort
void insercao(int *v, int tam, unsigned long int *comp, unsigned long int *troc);

// Função da ordenação Merge Sort
void mergeSort(int *v, int inicio, int fim, unsigned long int *comp, unsigned long int *troc);

// Função que faz a fusão de dois vetores pré-ordenados e os copia para o vetor original (mergeSort)
void merge(int *v, int inicio, int meio, int fim, unsigned long int *comp, unsigned long int *troc);

// Função da ordenação Quick Sort
void quickSort(int *v, int inicio, int fim, unsigned long int *comp, unsigned long int *troc);

// Função que encontra a posição do vetor e faz as trocas necesssárias (quickSort)
int particiona(int *v, int inicio, int fim, unsigned long int *comp, unsigned long int *troc);

// Função da ordenação Counting Sort
unsigned long int countingSort(int *vetor, int tam);
