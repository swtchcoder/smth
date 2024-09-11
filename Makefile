GCC=gcc 
SRC=$(wildcard ./*.c)
CFLAGS=-Wall -Wextra

main: ${SRC}
	${GCC} ${CFLAGS} ${SRC} -o main