.PHONY: run 
SFML_FLAGS=-ISFML-2.5.1/include -LSFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system
CPP_FLAGS=-std=c++17 -Wall -Wextra

run:
	clang++ ${CPP_FLAGS} ${SFML_FLAGS} main.cpp -o main 
	LD_LIBRARY_PATH=SFML-2.5.1/lib ./main

clean:
	rm -f main