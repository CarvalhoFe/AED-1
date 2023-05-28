#include <stdio.h>

#define MAX_SIZE 100

char s[MAX_SIZE][MAX_SIZE];
int vis[MAX_SIZE][MAX_SIZE];
int n, m, x, y, eixX, eixY;

int valida(int x, int y){
    return x > -1 && y > -1 && x < n && y < m;
}

int main(){
    scanf("%d%d", &m, &n);

    for(int i = 0; i < n; i++){
        scanf("%s", s[i]);
    }

    while(valida(x, y)){
        if (vis[x][y]) {
            printf("!\n");
            return 0;
        }

        if(s[x][y] == '*'){
            printf("*\n");
            return 0;
        }

        if (s[x][y] == '>') {
            eixX = 0;
            eixY = 1;
        } else if (s[x][y] == '<') {
            eixX = 0;
            eixY = -1;
        } else if (s[x][y] == 'v') {
            eixX = 1;
            eixY = 0;
        } else if (s[x][y] == '^') {
            eixX = -1;
            eixY = 0;
        }

        vis[x][y] = 1;
        x += eixX;
        y += eixY;
    }

    return 0;
}