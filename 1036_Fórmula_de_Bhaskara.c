#include <stdio.h>
#include <math.h>

//formula de bhaskara 
int main() {
    
    double A, B, C, x, y, delta;
    
    scanf("%lf %lf %lf", &A, &B, &C);
    
    delta = pow(B,2) - 4 * A * C;
    
    x = (-B + sqrt(delta)) / (2 * A);
    y = (-B - sqrt(delta)) / (2 * A);
  
    if(A <= 0 || delta < 0){
      printf("Impossivel calcular\n");
    }
    else{
      printf("R1 = %.5lf\nR2 = %.5lf\n", x, y);
      
    }
 
    return 0;
}