#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100000

int BoyerMoore1 (char a[], int m, char b[], int n){
  int T1[256], i, k, r, ocorrs;
  
/* pré-processamento da palavra a */
  for (i = 0; i < 256; i++){
    T1[i] = m;
  }
  for (i = 0; i < m; i++){
    T1[tolower(a[i])] = m - i - 1;
  }
  
/* busca da palavra a no texto b */
  ocorrs = 0;
  k = m-1;
  while (k < n) {
    r = 0;
    while (r < m && tolower(a[m-r-1]) == tolower(b[k-r])){
      r += 1;
    }
    if (r == m){
      ocorrs += 1;
    }
    if (k == n-1){
      k += 1;
    } 
      else{
        k += T1[tolower(b[k+1])] + 1;
      }
  }
  return ocorrs;
}

int main(){
  char a[6] = "zelda"; 
  char b[MAX];
  int m, n, i;

  fgets(b, MAX, stdin);
  b[strcspn(b, "\n")] = '\0';
  
  m = strlen(a);
  n = strlen(b);
  
  for(i = 0; i < n; i++){
    b[i] = tolower(b[i]);
  }

  if(BoyerMoore1(a, m, b, n) >= 1){
    printf("Link Bolado\n");
  }else{
    printf("Link Tranquilo\n");
  }
  
  return 0;
}
