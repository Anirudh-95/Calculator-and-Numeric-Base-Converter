CC = gcc
CCFLAGS = -Wall -lm -g -Werror 

all : calc format 

calc : calc.o 
	$(CC) $(CCFLAGS) -o calc calc.o

calc.o : calc.c  
	$(CC) $(CCFLAGS) -c calc.c 

format : format.o
	$(CC) $(CCFLAGS) -o format format.o

format.o : format.c
	$(CC) $(CCFLAGS) -c format.c

clean: 
	rm -f calc calc.o
	rm -f format format.o