#include <stdio.h>
#include <math.h>

//calcula a area de um cirulo
int main() {
    
    double area, n, raio;
    
    n = 3.14159;
    scanf("%lf", &raio);
    
    area = n * pow(raio,2);
    printf("A=%.4lf\n", area);

 
    return 0;
}
