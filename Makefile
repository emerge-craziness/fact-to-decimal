all: methods.o main.o
	g++ methods.o main.o -o fact

methods.o:
	g++ -c methods.cpp

main.o:
	g++ -c main.cpp
