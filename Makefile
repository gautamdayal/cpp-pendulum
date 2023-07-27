main:
	clang++ -std=c++11 main.cpp -lstdc++ -framework IOKit -framework Cocoa -framework OpenGL `pkg-config --libs --cflags raylib` -o bin/exec


plot:
	./bin/exec
	python3.11 scripts/plotter.py

all:
	make main && make plot