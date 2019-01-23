#include "Book/Book.h"
#include "Book/Album.h"
#include "Book/Comic.h"
#include "Book/Novel.h"
#include "Book/Play.h"
#include "Book/Poetry.h"
#include "User/Library.h"
#include "User/Member.h"
#include "Network/Network.h"
#include "Network/SaveManager.h"
#include <iostream>
#include <fstream>

using namespace std;


int main() {
//	Library library1 = Library("MyFirstLibrary", "Ici");
//	Library library2 = Library("La bilbliotheque d Alexandrie");
//	Member mem1 = Member ("Toi");
//	Member mem2 = Member ("Moi");
//	Novel book1 = Novel("D'un monde a l'autre", "01");
//	Novel book2 = Novel("Les frontieres de glaces", "02");
//	Novel book3 = Novel("L'ile du destin", "03");
//    Novel book4 = Novel("La foret des captifs", "04");
//    Novel book5 = Novel("L'oeil d'otolep", "05");
//    Novel book6 = Novel("Les tentacules du mal", "06");
//    Novel book7 = Novel("Ellana", "07");
//    Novel book8 = Novel("L'envol", "08");
//    Novel book9 = Novel("La prophetie", "09");
//
//	library1.buyBook(&book1);
//	library1.buyBook(&book2);
//	library1.buyBook(&book3);
//	library1.buyBook(&book4);
//	library1.buyBook(&book5);
////    cout << library1 << endl;
//
//    library2.buyBook(&book6);
////    cout << library2 << endl;
//
//	mem1.setRegister(&library1);
//	mem1.borrowBook(1);
//	mem1.borrowBook(2);
//	mem1.borrowBook(3);
////    cout << mem1 << endl;
////    cout << library1 << endl;
////    cout << book1 << endl;
//
//    mem1.returnBook(1);
////    cout<<book1 << endl;
//
//    library1.askBook("06", &library2);
////    cout << library1 << endl;
////    cout << library2 << endl;
//
//    Poetry p1 = Poetry();
//    Poetry p2 = Poetry("Les fleurs du mal", "11");
////    library2.askBook("09", &library1);
//
//    library2.buyBook(&p2);
////    cout << library2 << endl;
////    library2.showBook();
////    library2.showBook(&p1);
//
//    Network network1 = Network("MyNetwork");
//    network1.addLibrary(library1);
//    network1.addLibrary(library2);
//    network1.addMember(mem1);
//    network1.addMember(mem2);
//    network1.addBook(book1);
//    network1.addBook(book2);
//    network1.addBook(book3);
//    network1.addBook(book4);
//    network1.addBook(book5);
//    network1.addBook(book6);
//    network1.addBook(book7);
//    network1.addBook(book8);
//    network1.addBook(book9);
//    SaveManager save = SaveManager();
//    save.save(network1, """C:/Users/Altar FrozenLight/CLionProjects/Biblireseau/db/""");

    SaveManager save = SaveManager();
    Network copie = save.load("""C:/Users/Altar FrozenLight/CLionProjects/Biblireseau/db/MyNetwork.txt""");
    cout << "Type: Network\nName :" << copie.getName() << endl << endl;

    map<int,Library> maplib = copie.getLibraryList();
    for (map<int,Library>::iterator it = maplib.begin(); it!=maplib.end(); ++it) {
        cout << it->second << endl;
    }
    cout << endl;

    map<int,Member> mapmem = copie.getMemberList();
    for (map<int,Member>::iterator it = mapmem.begin(); it!=mapmem.end(); ++it) {
        cout << it->second << endl;
    }
    cout << endl;
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