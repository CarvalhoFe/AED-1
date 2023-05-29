#include <stdio.h>
#include <stdbool.h>

#define MAX 1200
#define INF 9999999

typedef unsigned int uint;

uint dist[MAX];
uint graph[MAX][MAX];

void dijkstra(int s, int n, uint g[MAX][MAX], uint *d){
  bool vis[MAX] = {false};
  int i, j, v;
    
  for (i = 0; i <= n; ++i){
    d[i] = INF;
  }
  
  d[s] = 0;

  for(i = 0; i <= n; ++i){
    v = -1;
    for(j = 0; j <= n; ++j){
      if(!vis[j] && (v == -1 || d[j] < d[v])){
        v = j;
      }
    }

    if(d[v] == INF){
      break;
    }

    vis[v] = true;
    for(j = 0; j <= n; ++j){
      if(d[v] + g[v][j] < d[j]){
        d[j] = g[v][j] + d[v];
      }
    }
  }
}

int main(){
  int n, m, u, v, r, e, c, i, j;

  while(scanf("%d %d", &n, &m) != EOF){
    for(i = 0; i <= n; ++i){
      for(j = 0; j <= n; ++j){
          graph[i][j] = INF;
      }
    }

    for(i = 0; i < m; ++i){
      scanf("%d %d", &u, &v);
      graph[u][v] = graph[v][u] = 1;
    }

    scanf("%d %d %d", &c, &r, &e);

    for(i = 0; i <= n; ++i){
      graph[e][i] = graph[i][e] = INF;
    }

    dijkstra(c, n, graph, dist);
    printf("%d\n", dist[r]);
  }

  return 0;
}
