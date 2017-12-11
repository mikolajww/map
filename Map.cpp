#include <iostream>
#include "Employee.h"													//Defines class Employee
#include "Map.h"
#include "Book.h"													//Defines template Map<Key, Value>

using namespace std;

int main() {
	typedef unsigned int ID; 											//Identification number of Employee
	Map<ID, Employee> database;											//Database of employees

	database.add(761028073,  Employee("Jan Kowalski", "salesman", 28)); 	//Add first employee: name: Jan Kowalski, position: salseman, age: 28,
	database.add(510212881,  Employee("Adam Nowak", "storekeeper", 54));	//Add second employee: name: Adam Nowak, position: storekeeper, age: 54
	database.add(730505129,  Employee("Anna Zaradna", "secretary", 32));
	database.add(730505129,  Employee("JOAnna Zaradna", "secretary", 32));	//Add third employee: name: Anna Zaradna, position: secretary, age: 32
	database.add(730505129,  Employee("Anna Zaradna", "secretary", 32));
	
	cout << database << endl;											//Print database

	Map<ID, Employee> newDatabase = database;							//Make a copy of database

	Employee* pE;
	pE = newDatabase.find(510212881);									//Find employee using its ID
	pE->position = "salesman";											//Modify the position of employee
	pE = newDatabase.find(761028073);									//Find employee using its ID
	pE->age = 29;														//Modify the age of employee

	database = newDatabase;												//Update original database

	cout << database << endl;  

	Map<string,Book> library;
	library.add("Pan Tadeusz", Book("Adam Mickiewicz", "epopeja narodowa", 800, true));
	library.add("Lokomotywa", Book("Jan Brzechwa", "dla dzieci", 30, false));
	library.add("Gra o tron", Book("George RR Martin", "fantastyka", 500, true));

	cout << library << endl;                                         //Print original database

}
