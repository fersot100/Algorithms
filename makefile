OBJS = LinkedList.o dataStructures.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
VERSION = -std=c++14
LFLAGS = -Wall $(DEBUG)

dataStructures : $(OBJS)
		$(CC) $(VERSION) $(LFLAGS) $(OBJS) -o dataStructures

dataStructures.o : dataStructures.cpp LinkedList.cpp
		$(CC) $(VERSION) $(CFLAGS) dataStructures.cpp

linkedList.o : LinkedList.cpp
		$(CC) $(VERSION) $(CFLAGS) LinkedList.cpp
clean:
		\rm *.o dataStructures 