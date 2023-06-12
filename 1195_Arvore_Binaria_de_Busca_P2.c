#include <stdio.h>
#include <stdlib.h>

typedef struct noArv{
	int numero;
	struct noArv *esq;
	struct noArv *dir;
} noArv;

noArv* insere(noArv *arvore, int numero){
	if(!arvore){
		arvore = (noArv *) malloc(sizeof(noArv));
		arvore->numero = numero;
		arvore->esq = arvore->dir = NULL;
	}
	else if(arvore->numero > numero){
		arvore->esq = insere(arvore->esq, numero);
	}else{
		arvore->dir = insere(arvore->dir, numero);
	}
	
	return arvore;
}

void Prefixa(noArv *arvore){
	if(arvore){
	    printf(" %d", arvore->numero);
		Prefixa(arvore->esq);
		Prefixa(arvore->dir);
	}
}

void Infixa(noArv *arvore){
	if(arvore){
		Infixa(arvore->esq);
		printf(" %d", arvore->numero);
		Infixa(arvore->dir);
	}
}

void Posfixa(noArv *arvore){
	if(arvore){
		Posfixa(arvore->esq);
		Posfixa(arvore->dir);
		printf(" %d", arvore->numero);
	}
}

void limpa(noArv *arvore){
	if(arvore){
		limpa(arvore->esq);
	  limpa(arvore->dir);
		free(arvore);
		arvore = NULL;
	}
}

int main(){
	int numero, Qcasos, Qnos, Ncaso = 0;

	scanf("%d", &Qcasos);

	while(Qcasos--){
		noArv *arvore = NULL;
		scanf("%d", &Qnos);

		for (int i = 0; i < Qnos; i++){
			scanf("%d", &numero);
			arvore = insere(arvore, numero);
		}

		printf("Case %d:\n", ++Ncaso);
		printf("Pre.:");
		Prefixa(arvore);
		printf("\n");
		printf("In..:");
		Infixa(arvore);
		printf("\n");
		printf("Post:");
		Posfixa(arvore);
		printf("\n\n");
		limpa(arvore);
	}
 
 
    return 0;
}