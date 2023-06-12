#include <stdio.h>
#include <stdlib.h>

typedef struct noArv {
	char info;
	struct noArv* esq;
	struct noArv* dir;
} noArv;

noArv* criarNo(char info) {
	noArv* novoNo = (noArv*)malloc(sizeof(noArv));
	novoNo->info = info;
	novoNo->esq = NULL;
	novoNo->dir = NULL;
	return novoNo;
}

noArv* inserirNo(noArv* raiz, char info) {
	if (raiz == NULL) {
		return criarNo(info);
	}

	if (info < raiz->info) {
		raiz->esq = inserirNo(raiz->esq, info);
	} else if (info > raiz->info) {
		raiz->dir = inserirNo(raiz->dir, info);
	}

	return raiz;
}

void Infixa(noArv* raiz) {
	if (raiz != NULL) {
		Infixa(raiz->esq);
		printf("%c ", raiz->info);
		Infixa(raiz->dir);
	}
}

void Prefixa(noArv* raiz) {
	if (raiz != NULL) {
		printf("%c ", raiz->info);
		Prefixa(raiz->esq);
		Prefixa(raiz->dir);
	}
}

void Posfixa(noArv* raiz) {
	if(raiz != NULL){
		Posfixa(raiz->esq);
		Posfixa(raiz->dir);
		printf("%c ", raiz->info);
	}
}

noArv* buscarNo(noArv* raiz, char info) {
	if (raiz == NULL || raiz->info == info) {
		return raiz;
	}

	if (info < raiz->info) {
		return buscarNo(raiz->esq, info);
	}

	return buscarNo(raiz->dir, info);
}

void liberarArvore(noArv* raiz) {
	if (raiz != NULL) {
		liberarArvore(raiz->esq);
		liberarArvore(raiz->dir);
		free(raiz);
	}
}

int main() {
	char comando[20], info;
	noArv* raiz = NULL;

	while (scanf("%s%*c", comando) != EOF) {
		if (strcmp(comando, "I") == 0) {
			scanf("%c", &info);
			raiz = inserirNo(raiz, info);
		} else if (strcmp(comando, "INFIXA") == 0) {
			Infixa(raiz);
			printf("\n");
		} else if (strcmp(comando, "PREFIXA") == 0) {
			Prefixa(raiz);
			printf("\n");
		} else if (strcmp(comando, "P") == 0) {
			scanf("%c", &info);
			noArv* noEncontrado = buscarNo(raiz, info);
			if (noEncontrado != NULL) {
				printf("%c existe\n", info);
			} else {
				printf("%c nao existe\n", info);
			}
		} else if (strcmp(comando, "POSFIXA") == 0) {
			Posfixa(raiz);
			printf("\n");
		}
	}

	liberarArvore(raiz);
	return 0;
}
