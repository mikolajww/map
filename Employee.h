#include <iostream>
using namespace std;

class Employee {
public:
	string name;
	string position;
	unsigned age;
	Employee(string n, string p, unsigned a) : name(n), position(p), age(a) {};
	friend ostream& operator<< (ostream& o, const Employee& e) {
		return o << "Employee " << e.name << ", working as " << e.position << ", aged " << e.age;
	};
};
