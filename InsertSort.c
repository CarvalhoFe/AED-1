#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM_1 5000
#define TAM_2 10000
#define TAM_3 15000
#define TAM_4 20000

void InsertSort(int n, int v[]){
	int i, j, x;
	for (j = 1; j < n; j++){
		x = v[j];
		for(i = j-1; i >= 0 && v[i] > x; i--)
			v[i+1] = v[i];
		v[i+1] = x;
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
    InsertSort(TAM_4, vet);  
    fim = clock();

    tempo = (((double) (fim - inicio)) / CLOCKS_PER_SEC) *1000;
    printf("Tempo: %lf milissegundos\n", tempo);

  return 0;
}