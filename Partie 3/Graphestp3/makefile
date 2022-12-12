SRC=graph_basic.c graph_print.c graph_algos.c graphaux.c dijkstra.c
OBJ=graph_basic.o graph_print.o graph_algos.o graphaux.o dijkstra.o

# version LINUX:
CC = g++
CCFLAGS = -g -DLINUX

# version HP-UX: 
#CC = cc
#CCFLAGS = -g -DHP -Aa -DDEFTIMEVAL

obj:	$(OBJ)

doc:	graphes.dox $(SRC)
	doxygen graphes.dox; mv doc/html/* Html/doc

clean:
	rm -f $(OBJ); rm -f *.exe

.SUFFIXES:	.exe

.c.exe:	
	$(CC) $(CCFLAGS) $< $(OBJ) -lm -o $@

dijkstra: dijkstra.c graphaux.h graphes.h
	gcc dijkstra.c graphaux.c graph_basic.c graph_print.c graph_algos.c -o dijkstra

graphaux.o:	graphes.h graphaux.h graphaux.c
	$(CC) $(CCFLAGS) -c graphaux.c

graph_basic.o:	graphes.h graphaux.h graph_basic.c
	$(CC) $(CCFLAGS) -c graph_basic.c

graph_print.o:	graphes.h graphaux.h graph_print.c
	$(CC) $(CCFLAGS) -c graph_print.c

graph_algos.o:	graphes.h graphaux.h graph_algos.c
	$(CC) $(CCFLAGS) -c graph_algos.c




