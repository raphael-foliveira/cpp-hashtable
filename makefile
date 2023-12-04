run: build
	./main
	rm -f main

build:
	clang++ ./src/main.cpp ./src/hash_table.cpp ./src/node.cpp -o main
