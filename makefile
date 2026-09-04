CC = "g++"

build:
	$(CC) main.cpp -o a.out -lncurses -llua5.4 -I"handlers/" -std=c++20

clean:
	rm a.out