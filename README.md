# Gestione delle Attività in un'Industria

## Specifica del Problema
Si vuole sviluppare un programma in ANSI C per la gestione delle attività di lavorazione di un'industria. Il programma deve:
1. Acquisire un file di testo contenente le indicazioni dei task.
2. Inserire i dati in una struttura dati di tipo grafo in memoria.
3. Stampare a monitor l'elenco delle attività, ordinato in modo che siano rispettate le dipendenze.

## Analisi del Problema
### Dati di Ingresso del Problema
Il file di testo contiene il numero totale dei "TASK" da eseguire, seguito dall'elenco dei task e delle loro dipendenze.
### Dati di Uscita del Problema
L'output del programma è l'elenco delle attività, ordinato rispettando le dipendenze.
### Relazioni Intercorrenti tra i Dati del Problema
Ogni task ha una lista di task dipendenti che devono essere eseguiti prima di lui.

## Progettazione dell'Algoritmo
### Passi dell'Algoritmo
1. Apertura del file di testo.
2. Lettura del contenuto del file e costruzione del grafo.
3. Stampa ordinata dei task.
### Scelte di Progetto
- Implementazione del grafo tramite liste di adiacenza per gestire grafi sparsi.
- Utilizzo di una visita in profondità ricorsiva per stampare i task ordinati rispettando le dipendenze.

## Implementazione dell'Algoritmo
### Apertura del File di Testo
Il programma verifica se il file esiste e ha il formato richiesto, altrimenti termina l'esecuzione.
### Lettura del Contenuto del File e Costruzione del Grafo
- Implementazione della lista primaria per allocare i vertici e collegarli.
- Implementazione della lista secondaria per allocare gli archi e collegarli ai vertici.
### Stampa Ordinata dei Task
Si effettua una visita in profondità per stampare i task ordinati rispettando le dipendenze.

## Analisi della complessità del programma
### Algoritmo di visita in profondità:
L'algoritmo di visita in profondità del grafo è implementato attraverso due funzioni principali: avvia_visita_grafo_prof e visita_grafo_prof.

La complessità della funzione avvia_visita_grafo_prof è lineare rispetto al numero di vertici del grafo, ed è quindi O(n), dove n rappresenta il numero di vertici. Questa complessità deriva principalmente dal fatto che ogni vertice viene visitato una sola volta durante l'inizializzazione.

La funzione visita_grafo_prof è ricorsiva e visita ciascun vertice e arco del grafo. La complessità di questa visita dipende dal numero di vertici e archi e nel caso peggiore è O(n + m), dove n è il numero di vertici e m è il numero di archi.

### Istruzione Iterativa (for):
La complessità dell'istruzione iterativa (for) dipende dal numero di iterazioni e dalla complessità delle istruzioni all'interno del ciclo. In questo caso, supponiamo che il numero di iterazioni sia proporzionale al numero di vertici (n) del grafo. Quindi, se f(n) rappresenta la complessità delle istruzioni eseguite all'interno del ciclo, la complessità complessiva del ciclo sarà O(n * f(n)).

## Complessità totale della stampa ordinata:
Considerando la complessità dell'algoritmo di visita in profondità e dell'istruzione iterativa (for), la complessità totale per la stampa ordinata dei task è O(n + m) + O(n * f(n)) nel caso peggiore e O(n) nel caso ottimo.

Per un'analisi più dettagliata e specifica, consultare il codice sorgente e l'implementazione delle funzioni coinvolte.

## Utilizzo
Per compilare il programma, esegui il seguente comando nel terminale:

```bash
make
```
Per eseguire il programma, digita il seguente comando nel terminale:

```bash
./ordina_task
```
Segui le istruzioni a schermo per inserire il file contenente le indicazioni dei task.
