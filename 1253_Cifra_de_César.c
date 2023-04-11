#include <stdio.h>

//faz a criptografia de uma palavra
int main(){
  char string[50];
  int x, n, pula, i=0;

  scanf("%d", &n);
  
  for(x = 0; x < n; x++){
    
    scanf("%s", string);
    scanf("%d", &pula);

    pula = -pula;
    i = 0;

    while(string[i]){
      string[i] += pula;
      if(string[i] > 'Z'){
        string[i] -= 'Z' - 'A'+1;
      }
      if(string[i] < 'A'){
        string[i] += 'Z' - 'A'+1;
      }
      i++;
    }

    printf("%s\n", string);
  }
    return 0;
}