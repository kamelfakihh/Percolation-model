SRC = ./src
OBJS =  ${SRC}/main.cpp ${SRC}/Percolation.cpp ${SRC}/PercolationStats.cpp
CFLAG = -Wall -g
CC = g++
INCLUDE =
LIBS = -lm

build:
   ${CC} ${CFLAGS} ${INCLUDES} -o main ${OBJS} ${LIBS}

clean:
	-rm -f *.o core *.core main

.cpp.o:
	${CC} ${CFLAGS} ${INCLUDES} -c $<
