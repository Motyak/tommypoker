all: a.out

clean:
	rm -rf a.out

.PHONY: all clean

a.out: main.cpp Deck.cpp
	g++ -o $@ $^ --std=c++20 -Wall -Wextra -I . -I ..
