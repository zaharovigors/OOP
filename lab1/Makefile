FLAGS=-pedantic -Wall -Werror -Wno-sign-compare -Wno-long-long -std=c++11 -lm
COMPILLER=g++

all: start

start: triangle.o square.o octagon.o main.o
	$(COMPILLER) $(FLAGS) -o lab1 triangle.o square.o octagon.o main.o

main.o: main.cpp
	$(COMPILLER) -c $(FLAGS) main.cpp

triangle.o: triangle.cpp
	$(COMPILLER) -c $(FLAGS) triangle.cpp

square.o: square.cpp
	$(COMPILLER) -c $(FLAGS) square.cpp

octagon.o: octagon.cpp
	$(COMPILLER) -c $(FLAGS) octagon.cpp

clear:
	-rm -f *.o *.gch lab1
