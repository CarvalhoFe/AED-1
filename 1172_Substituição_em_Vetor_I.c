#include <stdio.h>

//todo numero <= 0 é substituido por 1
int main(){
  int X[10];
  int x, i;

  for(i = 0; i < 10; i++){
    scanf("%d", &x);
    X[i] = x;
    if(x <= 0){
      X[i] = 1;
    }
    else{
      X[i] = x;
    }
  }
  for(i = 0; i < 10; i++){
    printf("X[%d] = %d\n",i, X[i]);
  }
  
  return 0;
}