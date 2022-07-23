CC = g++
FLAGS = -std=c++14 -Wall -g
OBJS = hw13.o
FILES = hw13.cpp TQueue.h ExceptionQueueIsFull.h ExceptionQueueIsEmpty.h

all: hw13

hw13: $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o hw13

hw13.o: $(FILES)
	$(CC) $(FLAGS) -c hw13.cpp

tar:
	tar -cf hw13.tar hw13.scr Makefile $(FILES)

clean:
	rm *.o *.tar *.scr hw13

sudoClean:
	rm *.o *.scr hw13