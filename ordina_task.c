/* Programma che acquisisce i dati realtivi alle attività (task) da
un file di testo, ne crea un grafo e ne stampa l'ordine rispettando
le dipendenze fra di essi in termini di precendenza all'esecuzione */

/* Inclusione delle librerie */
#include <stdlib.h>
#include <stdio.h>
#include "operazioni_task.h"

/* definizione della funzione main */
int main(int argc, char **argv)
{

    int n;                    /*numero vertici del grafo*/
    vertice_grafo_t *grafo_p; /*puntatore al grafo (primo vertice nella lista primaria ????????)*/
    FILE *fptr;               /*puntatore al file di testo*/
    char *fname;              /*stringa contenente il nome del file di testo*/

    /* verificare il corretto lancio del programma */
    if (argc < 2)
    {
        printf("Il programma ottiene i dati da file di testo.\n");
        printf("Aggiungere il nome del file al rilancio del programma.\n");
    }else{
        /* verificare la corretta apertura del programma */
        fname = argv[1];
        if (!(fptr = fopen(fname, "r")))
        {
            printf("Errore nell'apertura o mancanza del file di testo '%s'\n",
                fname);
        }else{
            /* stampare del messaggio di conferma della corretta apertura del programma */
            printf("Il file %s contenente i task è in elaborazione... \n\n",
                fname);

            /* estrazione dei dati dal file e generazione del grafo */
            grafo_p = acquisisci_grafo(&n,
                                       fptr);

            /* stampa dei vari task secondo le dipendenze */
            visita_prof(grafo_p,
                        n);
        }
    }

    return (0);
}
