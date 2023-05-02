#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM_1 5000
#define TAM_2 10000
#define TAM_3 15000
#define TAM_4 20000

void Intercala(int p, int q, int r, int v[]){
	int i, j, k, *w;
	w = malloc ((r - p) * sizeof(int));
	i = p;
	j = q; 
	k = 0;
  
	while(i < q && j < r){
		if (v[i] <= v[j]){
      w[k++] = v[i++];
    }
		else w[k++] = v[j++];
	}
  
	while(i < q){
    w[k++] = v[i++];
  }
	while(j < r){
    w[k++] = v[j++];
  }
	for (i=p; i<r; i++){
    v[i] = w[i-p];
  }
	free(w);
}

void MergeSort(int p, int r, int v[]){
	if (p < r-1) {
		int q = (p+r)/2;
		MergeSort(p, q, v);
		MergeSort(q, r, v);
		Intercala(p, q, r, v);
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
    MergeSort(0, TAM_4, vet);  
    fim = clock();

    tempo = (((double) (fim - inicio)) / CLOCKS_PER_SEC) *1000;
    printf("Tempo: %lf milissegundos\n", tempo);

  return 0;
}