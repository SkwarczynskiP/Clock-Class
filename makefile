all: main

main: main.o Clock.o
	g++ main.o Clock.o -o main

main.o: main.cpp
	g++ -c main.cpp

Clock.o: Clock.cpp
	g++ -c Clock.cpp

clean:
	del Clock.o
	del main.o
	del main.exe

run: main
	./main