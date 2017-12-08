#include <iostream>
#include "Employee.h"													//Defines class Employee
#include "Map.h"														//Defines template Map<Key, Value>

using namespace std;

int main() {
    /*
    Map<int, int> db;
    db.add(1,1);
    int* xd;
    xd = db.find(2);
    if(xd != nullptr) {
        cout << *xd << endl;
    }
    else {
        cout << "no element found" << endl;
    }
    db.add(2,4);
    db.add(3,5);
    cout << db << endl;
    Map<int, int> db1 = db;
    db1.add(49,0);
    cout << db1 << endl;
    cout << db << endl;
    Map<int,int> db2;
    db2 = db1;
    db2.add(13,37);
    cout << db2 << endl;
     */
    typedef unsigned int ID; 											//Identification number of Employee
    Map<ID, Employee> database;											//Database of employees

    database.add(761028073,  Employee("Jan Kowalski", "salesman", 28)); 	//Add first employee: name: Jan Kowalski, position: salseman, age: 28,
    database.add(510212881,  Employee("Adam Nowak", "storekeeper", 54));	//Add second employee: name: Adam Nowak, position: storekeeper, age: 54
    database.add(730505129,  Employee("Anna Zaradna", "secretary", 32));	//Add third employee: name: Anna Zaradna, position: secretary, age: 32

    cout << database << endl;											//Print database

    Map<ID, Employee> newDatabase = database;							//Make a copy of database

    Employee* pE;
    pE = newDatabase.find(510212881);									//Find employee using its ID
    pE->position = "salesman";											//Modify the position of employee
    pE = newDatabase.find(761028073);									//Find employee using its ID
    pE->age = 29;														//Modify the age of employee

    database = newDatabase;												//Update original database

    cout << database << endl;                                           //Print original database

}
