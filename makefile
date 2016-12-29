CC = gcc
PARAMS = -o
PROG = arvo_bin.c

# Nome do executável
EXEC = arvo_bin	

all:
	$(CC) $(PROG) $(PARAMS) $(EXEC)
	
clear:
	rm -rf *.o $(EXEC)
