#include <stdio.h>
#include <stdlib.h>

typedef struct No{
  char letra;
  struct No *esq;
  struct No *dir;
} no;

int indice;

void imprime (no *No){
  if(No == NULL){
    return;
  }
  imprime (No->esq);
  imprime (No->dir);
  printf("%c", No->letra);
}

int buscar(int inicio, int fim, char string[], char s){
  int i = inicio;
  while (string[i] != s && i <= fim){
    i++;
  }
  return i;
}

no* fazno(char s){
  no* novo = malloc(sizeof(no));
  novo->letra = s;
  novo->esq = novo->dir = NULL;
  return novo;
}

no* fazarvore(char pre[], char in[], int inicio, int fim){
  if(fim < inicio){
    return NULL;
  }
  int indiceInf = buscar(inicio, fim, in, pre[indice]); //indice da raiz
  no* no = fazno(pre[indice++]); // fez raiz
  if (inicio == fim){
    return no;
  }
  no->esq = fazarvore(pre, in, inicio, indiceInf - 1);
  no->dir = fazarvore(pre, in, indiceInf + 1, fim);
  return no;
}


int main(void) {
  int i, x, n;
  scanf("%d", &x);
  char prefix[52];
  char infix[52];
  for(i = 0; i < x; i++){
    scanf ("%d", &n);
    scanf("%s", prefix);
    scanf("%s", infix);
    indice = 0;
    no *arv = fazarvore(prefix, infix, 0, n-1);
    imprime(arv);
    printf("\n");
  }
  return 0;
}
