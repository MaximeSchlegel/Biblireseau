#include "Book/Book.h"
#include "Book/Poetry.h"
#include "User/Library.h"
#include "User/Member.h"
#include "Network/Network.h"
#include <iostream>
// for convenience

using namespace std;


int main() {
	Library library1 = Library("MyFirstLibrary", "Ici");
	Library library2 = Library("La bilbliotheque d Alexandrie");
	Member mem1 = Member ("Toi");
	Member mem2 = Member ("Moi");
	Book book1 = Book("D'un monde a l'autre", "01");
	Book book2 = Book("Les frontieres de glaces", "02");
	Book book3 = Book("L'ile du destin", "03");
    Book book4 = Book("La foret des captifs", "04");
    Book book5 = Book("L'oeil d'otolep", "05");
    Book book6 = Book("Les tentacules du mal", "06");
    Book book7 = Book("Ellana", "07");
    Book book8 = Book("L'envol", "08");
    Book book9 = Book("La prophetie", "09");

	library1.buyBook(&book1);
	library1.buyBook(&book2);
	library1.buyBook(&book3);
	library1.buyBook(&book4);
	library1.buyBook(&book5);
    cout << library1 << endl;

    library2.buyBook(&book6);
    cout << library2 << endl;

	mem1.setRegister(&library1);
	mem1.borrowBook(1);
	mem1.borrowBook(2);
	mem1.borrowBook(3);
    cout << mem1 << endl;
    cout << library1 << endl;
    cout << book1 << endl;

    mem1.returnBook(1);
    cout<<book1 << endl;

    library1.askBook("06", &library2);
    cout << library1 << endl;
    cout << library2 << endl;

    Poetry p1 = Poetry();
    Poetry p2 = Poetry("Les fleurs du mal", "11");
//    library2.askBook("09", &library1);

    library2.buyBook(&p2);
    library2.showBook("Poetry");

    Network network1 = Network("My Network");
    network1.main_menu();

	return 0;
}

/*lecture de fichiers :
 * ifstream ifs("path.csv")
 * string ch1,ch2, ch3;
 * char c
 *
 * ch1 << ifs
 * c << ifs
 * ch2 << ifs
 * c << ifs
 * ch3 << ifs*/