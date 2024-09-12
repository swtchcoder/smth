GCC=gcc 
SRC=$(wildcard ./*.c)
CFLAGS=-Wall -Wextra

main.out: ${SRC}
	${GCC} ${CFLAGS} ${SRC} -o main.out