#!/usr/bin/python3.8

from sys import argv as args, exit as _exit
from os import system

def main(argc: int, argv) -> int:

	"""Main Function for Makefile.py"""

	c_compiler = "gcc"

	if argc == 1:

		name = "stopwatch"

	else:

		name = argv[1]

	code = system(f"{c_compiler} functions.c {name}.c -lncurses -o build/{name} -g")

	if code != 1:

		return code

	system(f"sudo cp ./build/{name} /bin/")
	system(f"sudo cp ./build/{name} /usr/bin/")
	return 0

if __name__ == "__main__":

	_exit(main(len(args), list(args)))
