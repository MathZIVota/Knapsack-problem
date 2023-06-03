all: output main.o 

output: main.o Solver.o Input.o
	g++ main.o Solver.o Input.o -o run.exe

main.o: main.cpp
	g++ -c main.cpp

Solver.o: Solver.cpp
	g++ -c Solver.cpp

Input.o: Input.cpp
	g++ -c Input.cpp

clean:
	rm *.o output