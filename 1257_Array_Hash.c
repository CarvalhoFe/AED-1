#include <stdio.h>
#include <string.h>

int main(){
  int N, L;
  int i, qtsCaso;
  int qtsLetra;
  int soma;

  char str[60];

  scanf("%d", &N);

  while(N > 0){
    scanf("%d", &L);
    qtsCaso = 0;
    soma = 0;

    while(L > 0){
      scanf(" %s", str);
      qtsLetra = 0;

      i = 0;
      while (str[i] != '\0'){
        soma += (str[i] - 65) + qtsCaso + qtsLetra++;
        i++;
      }

      qtsCaso++;
      L--;
    }

    printf("%d\n", soma);
    N--;
  }

    return 0;
}
