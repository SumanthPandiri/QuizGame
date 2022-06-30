all: main.out

run: main.out
	./main.out

main.out: main.cpp Quiz.cpp printResult.cpp
	g++ -std=c++11 -Wall main.cpp Quiz.cpp printResult.cpp -o main.out

clean:
	rm -f main.out