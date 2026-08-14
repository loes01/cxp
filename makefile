CC = "g++"

build:
	$(CC) main.cpp -o a.out -lncurses -I"/handlers/" -std=C++20

clean:
	rm a.out