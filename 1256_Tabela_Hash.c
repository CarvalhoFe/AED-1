#include <stdio.h>
#include <stdlib.h>

typedef struct No {
  int info;
  struct No* prox;
}No;

typedef struct Lista {
  No* primeiro;
  No* ultimo;
}Lista;

void insere(Lista* hash, int chave, int tam){
  int resto;
  No* novoNo = (No*)malloc(sizeof(No));
  resto = chave % tam;

  if (hash[resto].primeiro){
    hash[resto].ultimo->prox = novoNo;
  }else{
    hash[resto].primeiro = novoNo;
  }
  
  hash[resto].ultimo = novoNo;
  novoNo->prox = NULL;
  novoNo->info = chave;
}

int main(){
  int qntd, caso, M, C;
  int i, n;

  scanf("%d", &qntd);

  for(caso = 0; caso < qntd; ++caso){
    scanf("%d %d", &M, &C);
    Lista* hash = (Lista*)malloc(M * sizeof(Lista));

    for(i = 0; i < M; ++i){
      hash[i].primeiro = NULL, hash[i].ultimo = NULL;
    }
    
    for(i = 0; i < C; ++i){
      scanf("%d", &n);
      insere(hash, n, M);
    }

    for(i = 0; i < M; ++i){
      printf("%d -> ", i);
      No* no = hash[i].primeiro;
      
      while(no){
        printf("%d -> ", no->info);
        no = no->prox;
      }
      
      printf("\\\n");
    }
    
    free(hash);
    
    if(caso < qntd - 1){
      printf("\n");
    }
    
  }
  
  return 0;
}