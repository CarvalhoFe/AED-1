/* Recebe uma string de nomes, coloca em ordem alfabetica e
imprime a posicao desejada */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define MAX2 21

void Ordena(int n, char vet[n][MAX2]){
	int i, j;
	char aux[MAX2];

	for(i = 0; i < n-1; i++){
		for(j = 0; j < n-1; j++){
			if(strcmp(vet[j], vet[j+1]) > 0){
				strcpy(aux, vet[j]);
				strcpy(vet[j], vet[j+1]);
				strcpy(vet[j+1], aux);
			}
		}
	}
}

int main(){
	int n, k;
	int i;
	char vet[MAX][MAX2];
	scanf("%d %d", &n, &k);

	for(i = 0; i < n; i++){
		scanf("%s", vet[i]);
	}
	
	Ordena(n, vet);

	printf("%s\n", vet[k-1]);	

	
  return 0;
}