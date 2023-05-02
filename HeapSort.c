#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM_1 5000
#define TAM_2 10000
#define TAM_3 15000
#define TAM_4 20000

void InsereEmHeap(int m, int v[]){
	int t, f = m+1;
	while(f > 1 && v[f/2] < v[f]){
		t = v[f/2];
    v[f/2] = v[f];
    v[f] = t;
    f = f/2;
  }
}

void SacodeHeap(int m, int v[]){
	int t, f = 2;
	while(f <= m){
    if(f < m && v[f] < v[f+1]){
      ++f;
    }
    if(v[f/2] >= v[f]){
      break;
    }
    t = v[f/2];
    v[f/2] = v[f];
    v[f] = t;
    f *= 2;
  }
}

void HeapSort(int n, int v[]){
	int m, t;
	for (m = 1; m < n; m++){
		InsereEmHeap(m, v);
  }
	for(m = n; m > 1; m--){
		t = v[1];
    v[1] = v[m];
    v[m] = t;
    SacodeHeap(m-1, v);
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
    HeapSort(TAM_1, vet);  
    fim = clock();

    tempo = (((double) (fim - inicio)) / CLOCKS_PER_SEC) *1000;
    printf("Tempo: %lf milissegundos\n", tempo);

  return 0;
}