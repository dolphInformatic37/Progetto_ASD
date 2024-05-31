ordina_task: ordina_task.o operazioni_task.o makefile
	gcc -o ordina_task ordina_task.o operazioni_task.o

debug:     
	gcc -ansi -Wall -g ordina_task.c operazioni_task.c -o ordina_task      

ordina_task.o: ordina_task.c makefile     
	gcc -ansi -Wall -g -c ordina_task.c      

operazioni_task.o: operazioni_task.c operazioni_task.h makefile     
	gcc -ansi -Wall -g -c operazioni_task.c      
	
pulisci:     rm -f .o  

pulisci_tutto:     rm -f ordina_task.o
