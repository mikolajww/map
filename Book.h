#include <iostream>
using namespace std;

class Book {
public:
	string author;
	string category;
	unsigned n_of_pages;
	bool borrowed;
	Book(string a, string c, unsigned n, bool b): author(a), category(c), n_of_pages(n), borrowed(b) {};
	friend ostream& operator<< (ostream& o, const Book& e) {
		o << "Book by " << e.author << ", category: " << e.category << ", " << e.n_of_pages << " pages,";
		if(e.borrowed) {
			o << " currently borrowed";
		}
		else o << " currently on shelf";
		return o;
	}
};