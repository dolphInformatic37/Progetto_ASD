/* Implementazione della libreria per operazioni su grafi: */
/* acquisizione dei dati da file di testo */
/* visita in profondità del grafo */
/* stampa ordinata rispettando le dipendenze */

/* Inclusione delle librerie */

#include <stdlib.h>
#include <stdio.h>
#include "operazioni_task.h"

/* dichiarazione delle funzioni */
vertice_grafo_t *cerca_in_lista(vertice_grafo_t *testa_p,
                                int valore);

void avvia_visita_grafo_prof(vertice_grafo_t *grafo_p,
                             int n);

void visita_grafo_prof(vertice_grafo_t *vertice_p,
                       int *matrix,
                       int *indice);

/* definizione della funzione per acquisire il grafo da file */
vertice_grafo_t *acquisisci_grafo(int *nvg, FILE *fptr)
{
    int n,
        num_vertici,
        i,
        origine,
        dest,
        esito_lettura;

    char genitore[6];

    vertice_grafo_t *nuovovert_p,
                    *grafo_p = NULL,
                    *vertice_p;
    arco_grafo_t *arco_p = NULL,
                 *nuovoarco_p;

    esito_lettura = fscanf(fptr, "%d", &n);
    if (esito_lettura != 1)
    {
        printf("Errore di lettura\n");
    }else{
        *nvg = n;

        /* costruire la prima la lista primaria, senza liste secondarie */
        for (i = n; i > 0; i--)
        {
            nuovovert_p = (vertice_grafo_t *)malloc(sizeof(vertice_grafo_t));
            nuovovert_p->valore = i;
            nuovovert_p->lista_archi_p = NULL;
            nuovovert_p->vertice_succ_p = grafo_p;
            grafo_p = nuovovert_p;
        }

        vertice_p = grafo_p;

        while (fscanf(fptr, "%s%d", genitore, &num_vertici) != EOF)
        {
            arco_p = NULL;
            for (i = 0; i < num_vertici; i++)
            {
                esito_lettura = fscanf(fptr, "%*[^0-9]%d %*[^0-9]%d", &origine, &dest);
                /*cerca nella lista primaria il vertice con etichetta origine*/
                vertice_p = cerca_in_lista(grafo_p,
                                           origine);
                nuovoarco_p = malloc(sizeof(arco_grafo_t));
                /*cerca nella lista primaria il vertice con etichetta dest*/
                nuovoarco_p->vertice_adiac_p = cerca_in_lista(grafo_p,
                                                              dest);
                /* costruire la lista secondaria */
                nuovoarco_p->arco_succ_p = arco_p;
                arco_p = nuovoarco_p;
                vertice_p->lista_archi_p = arco_p;
            }
            vertice_p = vertice_p->vertice_succ_p;
        }
        fclose(fptr);
    }

    return (grafo_p);
}

/* definizione della funzione di ricerca per liste */
vertice_grafo_t *cerca_in_lista(vertice_grafo_t *testa_p,
                                int valore)
{
    vertice_grafo_t *elem_p;

    for (elem_p = testa_p;
         ((elem_p != NULL) && (elem_p->valore != valore));
         elem_p = elem_p->vertice_succ_p);
    return (elem_p);
}

/* definizione della funzione per visita in profondità e stampa*/
void visita_prof(vertice_grafo_t *grafo_p,
                 int n)
{
    int tasks[n];
    int posizione[0];
    int i;

    avvia_visita_grafo_prof(grafo_p,
                            n);

    posizione[0] = 0;
    visita_grafo_prof(grafo_p,
                      tasks,
                      posizione);

    printf("Per rispettare le dipendenze è possibile eseguire i task nel seguente ordine:\n");

    for (i = n - 1; i >= 0; i--)
    {
        printf("TASK%d\n", tasks[i]);
    }
}

/* definizione della funzione di inizializzazione per la visita in profondità */
void avvia_visita_grafo_prof(vertice_grafo_t *grafo_p,
                             int n)
{
    vertice_grafo_t *vertice_p;

    for (vertice_p = grafo_p;
         (vertice_p != NULL);
         vertice_p = vertice_p->vertice_succ_p)
    {
        vertice_p->colore = bianco;
        vertice_p->padre_p = NULL;
    }
}

/* definizione della funzione per la visita in profondità */
void visita_grafo_prof(vertice_grafo_t *vertice_p,
                       int *tasks,
                       int *posizione)
{
    arco_grafo_t *arco_p;

    vertice_p->colore = grigio;

    for (arco_p = vertice_p->lista_archi_p;
         (arco_p != NULL);
         arco_p = arco_p->arco_succ_p)
        if (arco_p->vertice_adiac_p->colore == bianco)
        {
            arco_p->vertice_adiac_p->padre_p = vertice_p;
            visita_grafo_prof(arco_p->vertice_adiac_p,
                              tasks,
                              posizione);
        }

    tasks[posizione[0]] = vertice_p->valore;
    posizione[0] = posizione[0] + 1;
    vertice_p->colore = nero;
}
