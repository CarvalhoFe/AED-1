#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

//define uma estrutura de nó
typedef struct No{
  char info[50];
  struct No *proximo_no;
}No;

//define uma estrutura de lista
typedef struct{
  No *primeiro_no, *ultimo_no;
}Lista;

//icinializa a lista
void inicializar(Lista *lista){
  lista->primeiro_no = NULL;
  lista->ultimo_no = NULL;
}

//insere nó no fim da lista
void inserir_no_fim(Lista *lista, char nome[]){
  No *novo = (No*)malloc(sizeof(No));
  strcpy(novo->info, nome);
  novo->proximo_no = NULL;
//caso nao tenha nada na lista ainda
  if(lista->primeiro_no == NULL){
    lista->primeiro_no = novo;
    lista->ultimo_no = novo;
  }
//caso ja tenha algo na lista
  else{
    lista->ultimo_no->proximo_no=novo;
    lista->ultimo_no = novo;
  }
}

//busca indicacao e coloca a lista2 atras dele
void busca_indicacao(Lista *lista1, Lista *lista2, char indicacao[]){
  No *aux = lista1->primeiro_no;
  No *guardaindicado;

  while(strcmp(aux->proximo_no->info, indicacao) != 0){
    aux = aux->proximo_no;
  }
  guardaindicado = aux->proximo_no;
  aux->proximo_no = lista2->primeiro_no;
  lista2->ultimo_no->proximo_no = guardaindicado;
}

//insere uma lista em outra lista
void junta_lista(Lista *lista1, Lista *lista2){
  if(lista1->primeiro_no == NULL){
    lista1->primeiro_no = lista2->primeiro_no;
  }
  else{
    lista1->ultimo_no->proximo_no = lista2->primeiro_no;
    lista1->ultimo_no = lista2->primeiro_no;
  } 
}

//printa a lista final
void print(Lista *lista){
  No *aux_print = lista->primeiro_no; 
  
  while (aux_print->proximo_no != NULL) {
    printf("%s ", aux_print->info);
    aux_print = aux_print->proximo_no;
  }
  aux_print = aux_print->info;
  printf("%s", aux_print);
  printf("\n");  
}

int main(){
  char* primeira_lista[MAX];
  char* segunda_lista[MAX];
  char indicacao[50];
  Lista listaAmigos, listaNovosAmigos;

  inicializar(&listaAmigos);
  inicializar(&listaNovosAmigos); 

//lê o vetor1 e coloca em listaamigos sendo cada nome um nó
  fgets(primeira_lista, MAX, stdin);
  char* nome = strtok(primeira_lista, " \n");
  while(nome != NULL){
    inserir_no_fim(&listaAmigos, nome);
    nome = strtok(NULL, " \n");
  }
  
//lê o vetor2 e coloca em listanovosamigos sendo cada nome um nó
  fgets(segunda_lista, MAX, stdin);
  nome = strtok(segunda_lista, " \n");
  while(nome != NULL){
    inserir_no_fim(&listaNovosAmigos, nome);
    nome = strtok(NULL, " \n");
  }
  
//le indicacao
  fgets(indicacao, 50, stdin);
  indicacao[strcspn(indicacao, "\n")] = '\0';
  
  if(strcmp(indicacao, "nao") == 0){
    junta_lista(&listaAmigos,&listaNovosAmigos);
    print(&listaAmigos);
  }else{
    if(strcmp(listaAmigos.primeiro_no, indicacao)==0){
      junta_lista(&listaNovosAmigos, &listaAmigos);
      print(&listaNovosAmigos);
    }
    else{
  busca_indicacao(&listaAmigos,&listaNovosAmigos,indicacao);
      print(&listaAmigos);
    }
  }
  return 0;
}