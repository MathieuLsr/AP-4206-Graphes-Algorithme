#include "graphes.h"
#include "graphaux.h"
#include <stdlib.h>

#define MAX 6
#define DIJKSTRA
#define TEST

#ifndef TEST
// https://www.programiz.com/dsa/dijkstra-algorithm

/* ====================================================================== */
/*! \fn void Dijkstra(graphe * g, int i)
    \param g (entrée) : un graphe pondéré. La pondération de chaque arc doit 
                        se trouver dans le champ v_arc de la structure cell .
    \param i (entrée) : un sommet de g.
    \brief calcule, pour chaque sommet x de g, la longueur d'un plus court
           chemin de i vers x. Cette longueur est stockée dans le champ
           c  q sd de g .
*/
/* ====================================================================== */
void Dijkstra(graphe * g, int i){

    int E = g->nsom ;
    int cost[E][E] ;
    //int* distance = malloc(E * sizeof(int)) ;
    int SB[E] ;
    boolean* tabBool = EnsembleVide(E) ;

    printf("0.0\n") ;
    printf("E = %d\n", E) ;

    for(int j=0 ; j < E ; j++){
        printf("- j=%d\n", j) ; 
        pcell c = g->gamma[j] ;

        if(c == NULL) continue ;
        
        printf("i=%d, c.som=%d\n", i, c->som) ;
        cost[i][c->som] = INFINITY ;
        SB[c->som] = TRUE ; 
    }


    for(int a = 0 ; a<g->nsom ; a++){
        printf("%d ", cost[i][a]) ;
    }

    printf("\n") ;
    printf("1.0\n") ;

    cost[i][i] = 0 ; 

    int k = 1 ; 
    //int* U = (int *) calloc(E, sizeof(int));
    pcell xk = g->gamma[k] ;
    xk->som = i ; 
    int val = INFINITY ;

    while(k < E && cost[i][xk->som] != INFINITY){

        
        
        int val_xk = xk->som ;
        xk = g->gamma[val_xk] ;

        printf("k=%d, E = %d, cost[i][xm.som]=%d, val_xk = %d\n", k, E, cost[i][xk->som], val_xk) ;

        while(xk != NULL){

            if(SB[xk->som] == FALSE){
                //cost[i][xk->som] = ... ;
                val = min(val, cost[i][val_xk] + cost[val_xk][xk->som] ) ;
            }

            printf(">> %d\n", xk->som) ;
            xk = xk->next ;
            
        }

        k++ ; 

        printf("val = %d\n", val) ;
        xk = g->gamma[k] ;
        if(xk == NULL) break ; 
    }



    /*
    int* distance = malloc(g->nsom * sizeof(int)) ;
    int* previous = malloc(g->nsom * sizeof(int)) ;
    int* SB = malloc(g->nsom * sizeof(int)) ;

    for(int j=0 ; j < g->nsom ; j++){

        pcell c = g->gamma[j] ;

        distance[c->som] = INFINITY ;
        previous[c->som] = NULL ;

        if(c->som != i){

        }

    }
    */
}

#else

void Dijkstra(int Graph[MAX][MAX], int n, int start) {
  int cost[MAX][MAX], distance[MAX], pred[MAX];
  int visited[MAX], count, mindistance, nextnode, i, j;

  // Creating cost matrix
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (Graph[i][j] == 0)
        cost[i][j] = INFINITY;
      else
        cost[i][j] = Graph[i][j];

  for (i = 0; i < n; i++) {
    distance[i] = cost[start][i];
    pred[i] = start;
    visited[i] = 0;
  }

  distance[start] = 0;
  visited[start] = 1;
  count = 1;

  while (count < n - 1) {
    mindistance = INFINITY;

    for (i = 0; i < n; i++)
      if (distance[i] < mindistance && !visited[i]) {
        mindistance = distance[i];
        nextnode = i;
      }

    visited[nextnode] = 1;
    for (i = 0; i < n; i++)
      if (!visited[i])
        if (mindistance + cost[nextnode][i] < distance[i]) {
          distance[i] = mindistance + cost[nextnode][i];
          pred[i] = nextnode;
        }
    count++;
  }

  // Printing the distance
  for (i = 0; i < n; i++)
    if (i != start) {
      printf("\nDistance from source to %d: %d", i, distance[i]);
    }
}
#endif

int main(int argc, char const *argv[])
{

    if(argc < 3){
        printf("Usage : ./dijkstra [file_name] [sommet]\n") ;
        return 0 ; 
    }
    
    char* c = strdup(argv[1]) ;
    int u = atoi(argv[2]);

    #define SIZE 15
    int Graph[SIZE][SIZE], i, j, n;
    n = 6;

    for(int x=0 ; x<SIZE ; x++)
        for(int y=0 ; y<SIZE ; y++)
            Graph[x][y] = 0 ; 

    Graph[0][1] = 2 ;
    Graph[0][2] = 8 ;
    Graph[1][2] = 5 ;
    Graph[1][3] = 1 ;
    Graph[2][4] = 1 ;
    Graph[3][2] = 4 ;
    Graph[4][1] = 3 ;
    Graph[3][4] = 1 ;
    Graph[3][5] = 1 ;
    Graph[4][5] = 1 ;

    Dijkstra(Graph, n, u);
    printf("\n") ;
    return 0 ; 

    #ifndef TEST

    
    
    
    graphe* G = ReadGraphe(c) ;
    //graphe* G = ReadGraphe(argv[1]); 
    

    Dijkstra(G, x) ;
    #endif

    return 0;
}
