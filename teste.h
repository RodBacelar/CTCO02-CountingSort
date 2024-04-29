/*
Descrição das funções que realizarão os testes de cada algoritmo.
*/

// Struct teste que guarda atributos de um determinado teste
typedef struct teste {
  float tempo;
  unsigned long int comparacoes;
  unsigned long int trocas;
} teste;

// Função que realiza um teste em um algoritmo especifico com um vetor e retorna tempo gasto, comparações e trocas realizadas
teste testeAlgoritmo(int *v, int tam, int metodo);
