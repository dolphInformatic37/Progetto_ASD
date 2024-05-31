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
