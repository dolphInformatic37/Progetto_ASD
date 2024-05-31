/* Libreria per operazioni su grafi: */
/* acquisizione dei dati da file di testo */
/* visita in profondità del grafo */
/* stampa ordinata rispettando le dipendenze */

#include <stdio.h>

/* definizione dei tipi di dati */

typedef enum
{
    bianco, /* vertice non ancora visitato */
    grigio, /* vertice visitato, con vertici adiacenti non ancora visitati */
    nero
} colore_t; /* vertice visitato, con tutti i vertici adiacenti visitati */

typedef struct vertice_grafo
{
    int valore;                           /* valore contenuto nel vertice (numero vertice) */
    struct vertice_grafo *vertice_succ_p; /* puntatore al vertice successivo nella lista di adiacenza */
    struct arco_grafo *lista_archi_p;     /* puntatore alla lista secondaria */
    colore_t colore;                      /* indicatore dello stato di visita del vertice */
    struct vertice_grafo *padre_p;        /* puntatore al vertice padre nell'albero coprente */
} vertice_grafo_t;

typedef struct arco_grafo
{
    struct vertice_grafo *vertice_adiac_p; /* puntatore al vertice adiacente */
    struct arco_grafo *arco_succ_p;        /* puntatore all'arco successivo */
} arco_grafo_t;

/* dichiarazione delle funzioni esportate */

extern vertice_grafo_t *acquisisci_grafo(int *,
                                         FILE *);

extern void visita_prof(vertice_grafo_t *,
                        int);
