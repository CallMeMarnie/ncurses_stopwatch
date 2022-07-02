CC = gcc
name = stopwatch

all: comp

comp:

	${CC} ${name}.c -lncurses -o ${name}

bin:
	sudo cp ${name} /bin
	sudo cp ${name} /usr/bin
