run: build
	./main

build:
	clang++ ./src/main.cpp ./src/hash_table.cpp ./src/node.cpp -o main

clean:
	rm -f main
