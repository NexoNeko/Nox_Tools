OBJS	= main.o Nox_Aux_Functions.o Nox_Aux_Rand.o Nox_Random.o
SOURCE	= main.c Nox_Aux_Functions.c Nox_Aux_Rand.c Nox_Random.c
HEADER	= nox.h
OUT	= Nox_RSG
CC	 = gcc
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.c
	$(CC) $(FLAGS) main.c 

Nox_Aux_Functions.o: Nox_Aux_Functions.c
	$(CC) $(FLAGS) Nox_Aux_Functions.c 

Nox_Aux_Rand.o: Nox_Aux_Rand.c
	$(CC) $(FLAGS) Nox_Aux_Rand.c 

Nox_Random.o: Nox_Random.c
	$(CC) $(FLAGS) Nox_Random.c 


clean:
	rm -f $(OBJS) $(OUT)