CC = gcc
name = stopwatch

all: comp

comp:

	${CC} ${name}.c -lncurses -o build/${name}

bin:

	sudo cp build/${name} /bin
	sudo cp build/${name} /usr/bin
