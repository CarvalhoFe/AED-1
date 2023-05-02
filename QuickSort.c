#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM_1 5000
#define TAM_2 10000
#define TAM_3 15000
#define TAM_4 20000

int Separa(int p, int r, int v[]){
	int c, j, k, t;
	c = v[r];
	j = p;
	for (k = p; k < r; k++)
		if(v[k]<=c){
			t = v[j];
      v[j] = v[k];
      v[k] = t;
			j++;
		}
	v[r] = v[j], v[j] = c;
	return j;
}

void QuickSort(int p, int r, int v[]){
	int j;
	if (p < r) {
		j = Separa(p, r, v);
		QuickSort(p, j-1, v);
		QuickSort(j+1, r, v);
	}
}

int main() {
	  int vet[TAM_1];
    clock_t inicio, fim;
    double tempo;
		int i;
  
		// cria um vetor aleatório
    srand(73); 

    for (i = 0; i < TAM_1; i++) {
      vet[i] = rand() % 1000;
    }

    inicio = clock();
    QuickSort(0, TAM_1, vet);  
    fim = clock();

    tempo = (((double) (fim - inicio)) / CLOCKS_PER_SEC) *1000;
    printf("Tempo: %lf milissegundos\n", tempo);

  return 0;
}