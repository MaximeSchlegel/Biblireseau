#include "Book/Book.h"
#include "User/Library.h"
#include "User/Member.h"

#include <iostream>
using namespace std;


int main() {
	Library library1 = Library("MyFirstLibrary", "Ici");
	cout << library1.getId() << endl;
	cout << library1.getName() << endl;
	cout << library1.getAddress() << endl;
	return 0;
}
