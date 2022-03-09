OBJS	= main.o sha256.o
SOURCE	= main.cpp sha256.cpp
HEADER	= sha256.h
OUT	= mining_sim
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

sha256.o: sha256.cpp
	$(CC) $(FLAGS) sha256.cpp 


clean:
	rm -f $(OBJS) $(OUT)