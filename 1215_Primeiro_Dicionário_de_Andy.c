#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct{
    char palavra[201];
}String;

// Função de procura de uma string no dicionário;
bool stringExiste(char *str, String *dicionario, unsigned tam){
    unsigned i;

    for(i = 0; i < tam; i++)
        if(strcmp(dicionario[i].palavra, str) == 0)
            return true;

    return false;
}

// QuickSort para ordenação em ordem alfabética;
void quickSortParcialInterno(String *dicionario, int inicio, int fim){
    String pivo;
    String temp;
    int i, j;

    if(fim - inicio > 0){
        if(inicio < fim){
            i = inicio;
            j = fim;
            pivo = dicionario[(i + j) / 2];

            do{
                while(strcmp(dicionario[i].palavra, pivo.palavra) < 0)
                    i++;
                while(strcmp(dicionario[j].palavra, pivo.palavra) > 0)
                    j--;

                if(i <= j){
                    temp = dicionario[i];
                    dicionario[i] = dicionario[j];
                    dicionario[j] = temp;
                    i++;
                    j--;
                }
            } while(i <= j);

            quickSortParcialInterno(dicionario, inicio, j);
            quickSortParcialInterno(dicionario, i, fim);
        }
    }
}

// Função que dispara a chamada recursiva;
void quickSortParcial(String *dicionario, int tam) {
    quickSortParcialInterno(dicionario, 0, tam - 1);
}

int main(){
    unsigned i, j, k = 0;

    // Vetores para guardar temporariamente uma string;
    char tempEntrada[201], tempSaida[201];
    // Vetor onde irão ficar as palavras do dicionário;
    String dicionario[5050];

    memset(dicionario, 0, sizeof(dicionario));
    while (scanf(" %[^\n]", tempEntrada) != EOF) {
        i = j = 0;
        while(tempEntrada[i]) {
            // Enquanto o caractere na posição atual da string for uma letra;
            // O passe para a string temporária de saída já em minúsculo;
            while(isalpha(tempEntrada[i]))
                tempSaida[j++] = tolower(tempEntrada[i++]);

            // Se o caractere que fez o laço acima sair foi o caractere nulo
            // Significa que a string chegou ao fim
            // Por isso deve-se executar todos os procedimentos de procura e inserção no dicionário;
            // Logo em seguida, quebra-se o laço mais externo;
            if(tempEntrada[i] == '\0'){
                tempSaida[j] = '\0';

                if(!stringExiste(tempSaida, dicionario, k))
                    strcpy(dicionario[k++].palavra, tempSaida);

                j = 0;

                memset(tempSaida, 0, sizeof(tempSaida));
                break;
            }

            tempSaida[j] = '\0';

            // Enquanto o caractere atual não for uma letra, apenas avance;
            while(!isalpha(tempEntrada[i])){
                i++;
                // Caso o caractere na posição atual seja o caractere nulo;
                // Significa que a string acabou, pare o laço;
                if(tempEntrada[i] == '\0')
                    break;
            }

            // Se a palavra contida na string temporária ainda não existe
            // No struct das palavras de saída, então a coloque lá;
            if(!stringExiste(tempSaida, dicionario, k))
                strcpy(dicionario[k++].palavra, tempSaida);

            j = 0;
            memset(tempSaida, 0, sizeof(tempSaida));
        }

        memset(tempEntrada, 0, sizeof(tempEntrada));
    }

    quickSortParcial(dicionario, k);

    j = 0;
    // Pode haver uma string nula na primeira posição do dicionário, se houver
    // Inicie 'j' em 1;
    if(strcmp(dicionario[0].palavra, "\0") == 0)
        j = 1;

    for(; j < k; j++)
        printf("%s\n", dicionario[j].palavra);
}
