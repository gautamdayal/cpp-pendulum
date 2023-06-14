main:
	clang++ -std=c++11 main.cpp -o bin/exec

plot:
	./bin/exec
	python3.11 scripts/plotter.py