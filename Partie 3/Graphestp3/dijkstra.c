#include "graphes.h"
#include "graphaux.h"
#include <stdlib.h>

#define MAX 6
#define DIJKSTRA

#define INFINI LONG_MAX

/* ====================================================================== */
/*! \fn void Dijkstra(graphe * g, int i)
    \param g (entrée) : un graphe pondéré. La pondération de chaque arc doit 
                        se trouver dans le champ v_arc de la structure cell .
    \param i (entrée) : un sommet de g.
    \brief calcule, pour chaque sommet x de g, la longueur d'un plus court
           chemin de i vers x. Cette longueur est stockée dans le champ
           v_sommets de g.
*/
/* ====================================================================== */
void Dijkstra(graphe * g, int i){


    int n = g->nsom ;
    boolean* S = EnsembleVide(n) ;
    S[i] = TRUE ;
    g->v_sommets[i] = 0 ;
    int k = 1 ; 
    int xk = i ; 

    for(int x = 0 ; x < n ; x++){
      if(i == x) continue ;
      g->v_sommets[x] = INFINI ;
    }

    while(k < n && g->v_sommets[xk] < INFINI){
      
      /*
      boolean* tempo = (boolean*) calloc(g->nsom, sizeof(boolean));
      tempo[xk] = TRUE;
      boolean* successeurs = dilatation(g, tempo) ;
      */

      //printf("----\n") ;

      int min_sommet = -1 ;
      int min_value = INFINI ;

      pcell cell = g->gamma[xk] ;
      while(cell != NULL){
          int y = cell->som ;
          if(S[y] == FALSE){

            //g->v_sommets[y] = min(g->v_sommets[y], g->v_sommets[xk] + cell->v_arc) ;
            //printf("> %d, %d, %d\n", g->v_sommets[y], g->v_sommets[xk] + cell->v_arc, -1) ;
            
            int new_val = g->v_sommets[xk] + cell->v_arc ;
            

            if(new_val < g->v_sommets[y]) {
              //printf("DEBUG : %ld : %d (%d)\n", g->v_sommets[y], cell->som ,new_val) ;
              g->v_sommets[y] = new_val ; 
              if(min_value > g->v_sommets[y]) {
                min_sommet = cell->som ;
                min_value = g->v_sommets[y] ;
                //printf("New min sommet = %d\n", min_sommet); 
              }
            }
            /*

            //printf(">> %d, %d\n", g->v_sommets[y], new_val) ;
            if(g->v_sommets[y] >= new_val){
              g->v_sommets[y] = new_val ;
              min_sommet = cell->som ;
              //printf("new Sommet : %d (%ld)\n", min_sommet,g->v_sommets[y]) ;
            }
            */
            
          }
          cell = cell->next ;
      }

      //printf("Minimum sommet : %d\n", min_sommet) ;

      if(min_sommet == -1) return ;

      k++ ;
      xk = min_sommet ;
      S[xk] = TRUE ;


      //printf("xk = %d : ", xk) ;
      /*
      printf("> %ld\n", g->gamma[i]->v_arc) ;

      for(int y = 0 ; y < n ; y++){
        if(successeurs[y] == TRUE && S[y] == FALSE){
          g->v_sommets[y] = min(g->v_sommets[y], g->v_sommets[xk] + g->gamma[xk]->) ;
        }
        //printf("%s ", successeurs[t] ? "V" : "F") ;
      }
      */
      //printf("\n") ;

    }


/*
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

/* ====================================================================== */
/*! \fn graphe * PCC(graphe * g, int d, int a)
    \param g (entrée) : un graphe pondéré. La pondération de chaque arc doit 
                        se trouver dans le champ v_arc de la structure cell .
    \param d (entrée) : un sommet (départ).
    \param a (entrée) : un sommet (arrivée).
    \return un plus court chemin de d vers a dans g , représenté par un graphe.
    \brief retourne un plus court chemin de d vers a dans g .
*/
/* ====================================================================== */
graphe* PCC(graphe * g, int d, int a){

  

}

int main(int argc, char const *argv[])
{

    if(argc < 3){
        printf("Usage : ./dijkstra [file_name] [sommet]\n") ;
        return 0 ; 
    }
    
    char* c = strdup(argv[1]) ;
    int u = atoi(argv[2]);

    graphe* G = ReadGraphe(c) ;
    
    Dijkstra(G, u) ;

    for(int i = 0 ; i < G->nsom ; i++)
      printf("\nDistance from %d to %d: %ld", u, i, G->v_sommets[i]);

    printf("\n") ;

    return 0;
}
