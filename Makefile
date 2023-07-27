main:
	clang++ -std=c++20 main.cpp Graph.cpp -lstdc++  -framework IOKit -framework Cocoa -framework OpenGL `pkg-config --libs --cflags raylib` -o bin/exec


plot:
	./bin/exec
	python3.11 scripts/plotter.py

all:
	make main && make plot