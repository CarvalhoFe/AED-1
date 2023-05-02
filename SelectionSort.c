#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM_1 5000
#define TAM_2 10000
#define TAM_3 15000
#define TAM_4 20000

void SelectionSort(int n, int v[]){
  int i, j, min, x;
  for(i = 0; i < n-1; i++){
    min = i;
    for(j = i+1; j < n; j++){
      if(v[j] < v[min]){
        min = j;
      }
    }
    x = v[i];
    v[i] = v[min];
    v[min] = x;
  }
}

int main() {
	  int vet[TAM_4];
    clock_t inicio, fim;
    double tempo;
		int i;
  
		// cria um vetor aleatório
    srand(73); 

    for (i = 0; i < TAM_4; i++) {
      vet[i] = rand() % 1000;
    }

    inicio = clock();
    SelectionSort(TAM_4, vet);  
    fim = clock();

    tempo = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo: %lf segundos\n", tempo);

  return 0;
}