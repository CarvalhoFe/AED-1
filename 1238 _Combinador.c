#include <stdio.h>
#include <math.h>

//entrada de duas palavras e saida da combinaçao delas
int main() {
  int n, i, j, k;
  int len1, len2, len3;
  char vet1[50];
  char vet2[50];
  char vet3[100];

  scanf("%d", &n);

  for(int x = 0; x < n; x++){
      
    scanf("%s %s", vet1, vet2);
    len1 = strlen(vet1);
    len2 = strlen(vet2);
    len3 = len1 + len2;

    for(i = 0, j = 0, k = 0; k < len3; k++){
      if(k % 2 == 0 && i < len1){
        vet3[k] = vet1[i++];
      }
      else if(j < len2){
        vet3[k] = vet2[j++];
      }
      else{
        vet3[k] = vet1[i++];
      }
    }
    
    vet3[len3] = '\0';
    k = 0;
    j = 0;
    
    printf("%s\n", vet3);
    
      for(int y = 0; y < 100; y++){
          vet3[y] = 0;
      }
  }
    return 0;
}