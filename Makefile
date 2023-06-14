main:
	clang++ -std=c++11 main.cpp -o bin/exec

plot:
	python3.11 scripts/plotter.py