#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "graphes.h"

/* ci-dessous trois macros pour pouvoir utiliser les termes, booleens, VRAI et FAUX dans les programmes */
#define booleen unsigned char
#define VRAI 1
#define FAUX 0



/***************************************************************************/
/* retourne le dilate D de l'ensemble E dans le graphe G                   */
/* les ensembles E et D sont repr�sent�s par des tableaux booleens         */
/* - la m�moire pour E est suppos�e allou�e avec autant de case            */
/*   que de sommets dans G                                                 */
/* - la m�moire pour D est allou�e a l'int�rieur de la fonction            */
/***************************************************************************/
booleen * dilatation(graphe* G, booleen *E){
  booleen *D; /* tableau boolen pour stocker le r�sultat de ma dilatation */
  int x; /* pour parcourir les sommets de G */
  pcell p ; /* pointeur-maillon pour parcourir des listes de successeurs */
  
  /* comme D est un sous ensemble des sommets de D on a besoin
     d'autant de cases que de sommets de G */
  D = (booleen *) calloc(G->nsom, sizeof(booleen));

  /* A completer ici, peut se faire en 4 lignes, en tout cas en au plus 7 :-) */

  for(x = 0 ; x < G->nsom - 1 ; x++)
    if(E[x] == VRAI){
      p = G->gamma[x] ;
      while(p != NULL){
        D[p->som] = VRAI ;
        p = p->suivant ;
      }
    }

  return D;
}

booleen* dilatation_partielle(graphe* G, booleen *E, int nb_etape){
  
  for(int i=0 ; i<nb_etape ; i++){
      E = dilatation(G, E) ;
  }

  return E; 
}


/* ====================================================================== */
int main(int argc, char **argv)
/* ====================================================================== */
{
  graphe *G;
  int nd;         /* nombre d'etapes de dilatation */
  int x;          /* sommet de depart � explorer */
  booleen *E, *D; /* tableau pour stocker les ensembles successifs et leurs dilates */
  int i; /* indice muet*/
  
  if (argc != 4)
  {
    fprintf(stderr, "usage: %s <donnee.graphe> <sommet_initial_a_explorer> <nb_dilatation>\n", argv[0]);
    fprintf(stderr, "            ou %s explore le graphe donnee.grahe en faisant nb_dilatation etapes de dilatation a partir de l'ensemble contenant sommet_initial_a_explorer\n", argv[0]);
    exit(0);
  }

  /**********************************************************/
  /* Lecture des arguments passes au programmme             */
  /**********************************************************/
  
  G = litGraphe(argv[1]);       /* Lit un graphe stock�e dans un fichier */
  
  x = atoi(argv[2]);

  if(x >= G->nsom){
    fprintf(stderr, "Erreur: pas de sommet d'indice %d dans %s\n", x, argv[1]);
    exit(0);
  }

  nd = atoi(argv[3]);

  if(nd < 0){
    fprintf(stderr, "Erreur : le nombre d'etapes d'exploration doit etre positif.\n");
    exit(0);
  }


  /**********************************************************/
  /* Debut de l'exploration                                 */
  /**********************************************************/
  printf("Explorartion (%d �tapes de dilatation) du graphe %s a partir du sommet %d\n\n\n", nd, argv[1],x);

  
  /* initialisation de l'ensemble E : E := {x}*/
  E = (booleen*) calloc(G->nsom, sizeof(booleen));
  E[x] = VRAI;

  

  E = dilatation_partielle(G, E, nd);

  printf("Résultat : {") ;

  for(int i=0 ; i < G->nsom ; i++){
      if(E[i] == VRAI) printf("%d, ", i) ;
  }

    printf("}\n\n") ;

  free(D);
  return 0;
} /* main() */

