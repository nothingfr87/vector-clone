all: build clean

build:
	gcc src/main.c -o main

clean:
	rm -rf main 2>/dev/null
