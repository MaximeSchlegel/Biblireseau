#include "Network.h"


Network::Network(string name) {
    this->name = name;
    this->libraryList.emplace(0,Library());
    this->memberList.emplace(0,Member());
    this->bookList.emplace(0,Book());
}


const string &Network::getName() const {
    return name;
}

const map<int, Library> &Network::getLibraryList() const {
    return libraryList;
}

const map<int, Member> &Network::getMemberList() const {
    return memberList;
}

const map<int, Book> &Network::getBookList() const {
    return bookList;
}

void Network::addLibrary(Library library) {
    this->libraryList.insert(pair<int,Library>(library.getId(),library));
}

void Network::addMember(Member member) {
    this->memberList.insert(pair<int,Member>(member.getId(),member));
}

void Network::addBook(Book book) {
    this->bookList.insert(pair<int,Book>(book.getId(),book));
}

pair<bool, int> Network::search_book(string ISBN){
    bool founded;
    int n = bookList.size();
    int id = -1;
    while (!founded and id<n){
        id++;
        founded = (bookList[id].getISBN() == ISBN);
    }
    return pair<bool,int>(founded,id);
}

pair<bool, int> Network::search_book_for_borrow(string ISBN){
    bool founded;
    int n = bookList.size();
    int id = -1;
    while (!founded and id<n){
        id++;
        founded = (bookList[id].getISBN() == ISBN and bookList[id].getLocation() == bookList[id].getOwner());
    }
    return pair<bool,int>(founded,id);
}

pair<bool, int> Network::search_book_for_return(string ISBN, Library* library) {
    bool founded;
    int n = bookList.size();
    int id = -1;
    while (!founded and id < n) {
        id++;
        founded = (bookList[id].getISBN() == ISBN and bookList[id].getLocation() == library);
    }
    return pair<bool, int>(founded, id);
}

void Network::main_menu() {
    int choice ;
    cout << "\n \nBienvenue dans le logiciel de gestion du r\202seau nationnnal des Bilblioth\212ques \n \n" ;
    cout << "Appuyez sur 1 si vous \210tes un adh\202rent \n";
    cout << "Appuyez sur 2 si vous \210tes une biblioth\212que \n";
    cout << "Appuyez sur 3 pour quitter \n \n";
    cout << "Puis validez avec la touche Entr\202e \n";
    cin >> choice ;
    while (not (choice == 1 or choice == 2 or choice == 3 or choice == 1997)){
        cout << "\n \nAppuyez sur 1,2 ou 3, puis validez avec la touche Entr\202e \n";
        cin >> choice;
    }
    if (choice == 1) {
        this->member_menu();
    }
    if (choice == 2) {
        this->library_menu();
    }
    if (choice == 1997){
//        this-> admin_menu();
    }
}

void Network::member_menu() {
    int id;
    cout << "Entrez votre num\202ro adh\202rent pour vous connecter \n ou entrez 0 pour retourner au menu principal: ";
    cin >> id;
    while (id >= memberList.size() or id < 0) {
        cout << "\n \nCe num\202ro d'adh\202rent n'existe pas. \n";
        cout << "Entrez votre num\202ro adh\202rent pour vous connecter ou entrez 0 pour retourner au menu principal: ";
        cin >> id;
    }
    if (id == 0 ){
        this->main_menu();
        exit(0);
    }
    cout << "Identifiant correct. Connexion en cours. \n";
    this -> member_authentificated_menu(&memberList[id]);
}

void Network::member_authentificated_menu(Member* member) {
    int choice;
    cout << "Bonjour " << member->getName() << " ,bienvenue sur votre espace adh\202rent. \n \n";
    cout << "Appuyez sur 1 pour emprunter un livre \n";
    cout << "Appuyez sur 2 pour rendre un livre \n";
    cout << "Appuyer sur 3 pour vous d\202connecter \n \n";
    cout << "Puis validez avec la touche Entr\202e \n";
    cin >> choice;
    while (not (choice == 1 or choice == 2 or choice == 3)){
        cout << "\n \nAppuyez sur 1,2 ou 3, puis validez avec la touche Entr\202e \n";
        cin >> choice;
    }
    if (choice == 1){
        this->member_borrow_menu(member);
    }
    if (choice == 2) {
        this->member_return_menu(member);
    }
    if (choice == 3) {
        this->main_menu();
    }
}

void Network::member_borrow_menu(Member *member) {
    int id;
    cout << "Espace de " << member->getName() << "\n \n";
    cout << "Veuillez entrer le code du livre que vous voulez emprunter \n ou entrez 0 pour vous revenir dans votre espace personnel: ";
    cin >> id;
    while (id >= bookList.size() or id < 0) {
        cout << "\n \nCe code livre est inexistant. \n ";
        cout << "Entrez un code de livre correct pour continuer ou entrer 0 pour retourner à votre espace : ";
        cin >> id;
    }
    cout << "Code correct. \n";
    this->member_confirm_borrow_menu(member, &bookList[id]);
}

void Network::member_confirm_borrow_menu(Member* member, Book* book){
    char choice;
    cout << member->getName() << ",vous avez s\202lectionnn\202 le livre suivant : \n \n ";
    cout << book ;
    cout << "Confirmez-vous l'emprunt de ce livre ? \n";
    cout << "Entrez O pour oui ou N pour non : ";
    cin >> choice;
    while (not (choice == 'O' or choice == 'N')) {
        cout << "\n \nCette commande est inexistante. \n ";
        cout << "Appuyez sur O pour confirmer l'emprunt ou N pour l'annuler : ";
        cin >> choice;
    }
    if (choice == 'O'){
        member->borrowBook(book->getId());
        cout << "\n \nLe livre a bien été emprunté";
    }
    this->member_borrow_menu(member);
}

void Network::member_return_menu(Member *member) {
    int id;
    cout << "Espace " << member->getName() << "\n \n";
    cout << "Veuillez entrer le code du livre que vous voulez rendre \n ou entrez 0 pour vous revenir dans votre espace personnel: ";
    cin >> id;
    while (id >= bookList.size() or id < 0) {
        cout << "\n \nCe code livre est inexistant. \n ";
        cout << "Entrez un code de livre correct pour continuer ou entrer 0 pour retourner à votre espace : ";
        cin >> id;
    }
    cout << "Code correct. \n";
    member_confirm_return_menu(member,&bookList[id]);
}

void Network::member_confirm_return_menu(Member* member, Book* book){
    char choice;
    cout << member->getName() << ",vous avez s\202lectionnn\202 le livre suivant : \n \n ";
    cout << book ;
    cout << "Confirmez-vous le retour de ce livre ? \n";
    cout << "Entrez O pour oui ou N pour non : ";
    cin >> choice;
    while (not (choice == 'O' or choice == 'N')) {
        cout << "\n \nCette commande est inexistante. \n ";
        cout << "Appuyez sur O pour confirmer l'emprunt ou N pour l'annuler : ";
        cin >> choice;
    }
    if (choice == 'O'){
        member->returnBook(book->getId());
        cout << "\n \nLe livre a bien été retourné";
    }
    this->member_return_menu(member);
}

void Network::library_menu() {
    int id;
    Library library;
    cout << "Entrez votre num\202ro de bibliothèque pour vous connecter \n ou entrez 0 pour retourner au menu principal: ";
    cin >> id;
    while (id >= libraryList.size() or id < 0) {
        cout << "\n \nCe num\202ro de bibliothèque n'existe pas. \n";
        cout << "Entrez votre num\202ro adh\202rent pour vous connecter ou entrez 0 pour retourner au menu principal: ";
        cin >> id;
    }
    if (id == 0 ){
        this->main_menu();
        exit(0);
    }
    cout << "Identifiant correct. Connexion en cours. \n";
    this -> library_authentificated_menu(&libraryList[id]);
}

void Network::library_authentificated_menu(Library* library) {
    int choice;
    cout << "Bonjour" << library->getName() << " ,bienvenue sur votre espace bibliothèque. \n \n";
    cout << "Appuyez sur 1 pour emprunter un livre \n";
    cout << "Appuyez sur 2 pour rendre un livre \n";
    cout << "Appuyer sur 3 pour acheter un livre \n" ;
    cout << "Appuyer sur 4 pour vendre un livre \n" ;
    cout << "Appuyer sur 5 pour vous d\202connecter \n \n";
    cout << "Puis validez avec la touche Entr\202e \n";
    cin >> choice;
    while (not (choice == 1 or choice == 2 or choice == 3 or choice == 4 or choice == 5)){
        cout << "\n \nAppuyez sur 1, 2, 3, 4 ou 5 puis validez avec la touche Entr\202e \n";
        cin >> choice;
    }
    if (choice == 1){
        this->library_borrow_menu(library);
    }
    if (choice == 2) {
        this->library_return_menu(library);
    }
    if (choice == 3) {
        this->library_buy_book_menu(library);
    }
    if (choice == 4) {
        this->library_sell_book_menu(library);
    }
    if (choice == 5){
        this->main_menu();
    }
}

void Network::library_borrow_menu(Library* library) {
    string ISBN;
    cout << "Veuillez entrer l'ISBN du livre que vous voulez emprunter \n ou entrez 0 pour revenir dans votre espace bibliothèque:\n ";
    cin >> ISBN;
    pair<bool,int> search = this->search_book(ISBN);
    if (!search.first){
        cout << "\n \nCe  livre est inexistant. \n ";
        cout << "Entrez un code de livre correct pour continuer ou entrer 0 pour retourner à votre espace : ";
        cin >> ISBN;
    }else{
        search = this->search_book_for_borrow(ISBN);
        if (!search.first){
            cout << "\n \nCe  livre n'est pas disponible. \n ";
            cout << "Entrez un code de livre disponible pour continuer ou entrer 0 pour retourner à votre espace : ";
            cin >> ISBN;
        }else{
            cout << "Code correct. \n";
            this->library_confirm_borrow_menu((&bookList[search.second])->getOwner(), &bookList[search.second]);
        }
    }
}

void Network::library_confirm_borrow_menu(Library *library, Book* book) {
    char choice;
    cout << library->getName() << ",vous avez s\202lectionnn\202 le livre suivant : \n \n ";
    cout << book ;
    cout << "Confirmez-vous l'emprunt de ce livre ? \n";
    cout << "Entrez O pour oui ou N pour non : ";
    cin >> choice;
    while (not (choice == 'O' or choice == 'N')) {
        cout << "\n \nCette commande est inexistante. \n ";
        cout << "Appuyez sur O pour confirmer l'emprunt ou N pour l'annuler : ";
        cin >> choice;
    }
    if (choice == 'O'){
        library->askBook(book->getISBN(),book->getOwner());
    }
    this->library_borrow_menu(library);
}

void Network::library_return_menu(Library* library) { //pas fini
    string ISBN;
    cout << "Veuillez entrer l'ISBN du livre que vous voulez rendre \n ou entrez 0 pour revenir dans votre espace bibliothèque:\n ";
    cin >> ISBN;
    pair<bool,int> search = this->search_book(ISBN);
    if (!search.first){
        cout << "\n \nCe  livre est inexistant. \n ";
        cout << "Entrez un code de livre correct pour continuer ou entrer 0 pour retourner à votre espace : ";
        cin >> ISBN;
    }else{
        search = this->search_book_for_return(ISBN,library);
        if (!search.first){
            cout << "\n \nCe  livre n'est pas chez vous. \n ";
            cout << "Entrez un code de livre en votre possession pour continuer ou entrer 0 pour retourner à votre espace : ";
            cin >> ISBN;
        }else{
            cout << "Code correct. \n";
            this->library_confirm_return_menu((&bookList[search.second])->getOwner(), &bookList[search.second]);
        }
    }
}

void Network::library_confirm_return_menu(Library *library, Book *book) {
    char choice;
    cout << library->getName() << ",vous avez s\202lectionnn\202 le livre suivant : \n \n ";
    cout << book ;
    cout << "Confirmez-vous le retour de ce livre ? \n";
    cout << "Entrez O pour oui ou N pour non : ";
    cin >> choice;
    while (not (choice == 'O' or choice == 'N')) {
        cout << "\n \nCette commande est inexistante. \n ";
        cout << "Appuyez sur O pour confirmer l'emprunt ou N pour l'annuler : ";
        cin >> choice;
    }
    if (choice == 'O'){
        library->returnBook(book->getId());
    }
    this->library_borrow_menu(library);
}

void Network::library_sell_book_menu(Library* library) { //pas fini

}

//void Network::admin_menu(){
//    int choice;
//    cout << "\n \nBienvenue sur l'interface administrateur du logiciel du r\202seau nationnal des bibliothèques";
//    cout << "Appuyez sur 1 pour supprimer un membre,";
//    cout << "Appuyez sur 4 pour vous déconnecter\n \n";
//    cout << "Puis validez avec la touche Entr\202e \n";
//    cin >> choice ;
//    while (not (choice == 1 or choice == 2 or choice == 3 or choice == 4)){
//        cout << "\n \nAppuyez sur 1,2,3 ou 4, puis validez avec la touche Entr\202e \n";
//        cin >> choice;
//    }
//    if (choice == 1) {
//        this->admin_create_book();
//    }
//    if (choice == 2) {
//        this->admin_create_library();
//    }
//    if (choice == 3){
//        this-> admin_create_member();
//    }
//    if (choice == 4){
//        this->main_menu();
//    }
//}

void Network::library_buy_book_menu(Library* library) { //pas fini
    int choice;
    string title;
    string ISBN;
    string author;
    string editor;
    string audiance;
    cout << "\n \nBienvenue sur l'interface de cr\202ation de livres.";
    cout << "\n \nEntrez les donn\202es du livre que vous voulez acheter : ";
    cout << "Apuuyez sur 1 pour acheter un album,\n";
    cout << "Appuyez sur 2 pour acheter une bande dssinnée,\n";
    cout << "Appuyez sur 3 pour acheter un roman,\n";
    cout << "Appuyer sur 4 pour acheter une pièce de théâtre,\n";
    cout << "Appuyez sur 5 pour acheter un recueil de poésie,\n";
    cout << "Appuyez sur 6 pour retourner au menu principal.";
    cout << "\n \nPuis validez avec la touche Entrée : \n \n";
    cin >> choice;
    while (not (choice == 1 or choice == 2 or choice == 3 or choice == 4 or choice == 5 or choice == 6)){
        cout << "\n \nAppuyez sur une touche entre 1 et 6, puis validez avec la touche Entr\202e \n";
        cin >> choice;
    }
    cout << "Entrez le titre du livre : ";
    cin >> title;
    cout << "\nEntrez l'ISBN du livre : ";
    cin >> ISBN;
    cout << "\nEntrez le nom de l'auteur du livre";
    cin >> author ;
    cout << "\nEntrez le nom de l'éditeur";
    cin >> editor;
    cout << "\nEntrez le public visé :";
    cin >> audiance;
    if (choice == 1){
        buy_Album_menu(title, ISBN, author, editor, audiance, library);
    }
    if (choice == 2){
        buy_Comic_menu(title, ISBN, author, editor, audiance, library);
    }
    if (choice == 3){
        buy_Novel_menu(title, ISBN, author, editor, audiance, library);
    }
    if (choice == 4){
        buy_Play_menu(title, ISBN, author, editor, audiance, library);
    }
    if (choice == 5){
        buy_Poetry_menu(title, ISBN, author, editor, audiance, library);
    }
}

void Network::buy_Album_menu(string title, string ISBN, string author, string editor, string audiance, Library *library) {
    bool picture = false;
    bool drawing = false;
    char choice;
    cout << "Est-ce que cet album contient des images ?" ;
    cout << "Entrez O pour oui ou N pour non : ";
    cin >> choice;
    while (not (choice == 'O' or choice == 'N')) {
        cout << "\n \nCette commande est inexistante. \n ";
        cout << "Appuyez sur O pour oui ou N pour non: ";
        cin >> choice;
    }
    if (choice == 'O'){
        picture = true;
    }
    cout << "Est-ce que cet album contient des dessins ?" ;
    cout << "Entrez O pour oui ou N pour non : ";
    cin >> choice;
    while (not (choice == 'O' or choice == 'N')) {
        cout << "\n \nCette commande est inexistante. \n ";
        cout << "Appuyez sur O pour oui ou N pour non: ";
        cin >> choice;
    }
    if (choice == 'O'){
        drawing = true;
    }
}

void Network::buy_Comic_menu(string title, string ISBN, string author, string editor, string audiance, Library *library) {

}

void Network::buy_Novel_menu(string title, string ISBN, string author, string editor, string audiance, Library *library) {

}

void Network::buy_Play_menu(string title, string ISBN, string author, string editor, string audiance, Library *library) {

}

void Network::buy_Poetry_menu(string title, string ISBN, string author, string editor, string audiance, Library *library) {

}

//void Network::admin_create_library() {
//    cout << "Pas encore cod\202";
//}
//
//void Network::admin_create_member() {
//    cout << "Pas encore cod\202";
//}




//*void test(int input, pair<int, void> {
// * if input == pair.first {
// * pair.second}}
// *
// * mes_test = veector pair [(1,album) , (2,bande dessiner)
// * for_each