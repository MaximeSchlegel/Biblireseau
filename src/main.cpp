#include "Book/Book.h"
#include "User/Library.h"
#include "User/Member.h"

#include <iostream>
using namespace std;


int main() {
    User user1 = User(false);
	Library library1 = Library("MyFirstLibrary", "Ici");
	Member mem1 = Member ("Michel");
	cout << user1 << library1 << mem1;
	return 0;
}
