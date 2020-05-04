all: ./Source/main.cpp
	g++ ./Source/main.cpp -o lab3
test: all test.py
	python test.py lab3 Tests test answer result 6
clean:
	rm -f lab3
