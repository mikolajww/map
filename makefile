map: Employee.h Employee.cpp Map.h Map.cpp list.h
	g++ -g -Wall -pedantic -std=c++11 -Werror *.cpp -o map 
clean:
	-rm map