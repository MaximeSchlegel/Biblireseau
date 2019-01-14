#include "Network.h"


Network::Network(string name) {
    this->name = name;
    this->libraryList.emplace(0,Library());
    this->memberList.emplace(0,Member());
    this->bookList.emplace(0,Book());
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
        this-> admin_menu();
    }
}

void Network::member_menu() {
    int id;
    Member member;
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
    member = memberList[id];
    this -> member_authentificated_menu(member);
}

void Network::member_authentificated_menu(Member member) {
    int choice;
    cout << member.getName() << " ,bienvenue sur votre espace adh\202rent. \n \n";
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

void Network::member_borrow_menu(Member member) {
    int id;
    Book book;
    cout << "Espace " << member.getName() << "\n \n";
    cout << "Veuillez entrer le code du livre que vous voulez emprunter \n ou entrez 0 pour vous revenir dans votre espace personnel: ";
    cin >> id;
    while (id >= bookList.size() or id < 0) {
        cout << "\n \nCe code livre est inexistant. \n ";
        cout << "Entrez un code de livre correct pour continuer ou entrer 0 pour retourner à votre espace : ";
        cin >> id;
    }
    cout << "Code correct. \n";
    book = bookList[id];
    this->member_confirm_borrow_menu(member, book);
}

void Network::member_confirm_borrow_menu(Member member, Book book){
    char choice;
    cout << member.getName() << ",vous avez s\202lectionnn\202 le livre suivant : \n \n ";
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
        member.borrowBook(book.getId());
    }
    if (choice == 'N'){
        this->member_borrow_menu(member);
    }
}

void Network::member_return_menu(Member member) {
    int id;
    Book book;
    cout << "Espace " << member.getName() << "\n \n";
    cout << "Veuillez entrer le code du livre que vous voulez rendre \n ou entrez 0 pour vous revenir dans votre espace personnel: ";
    cin >> id;
    while (id >= bookList.size() or id < 0) {
        cout << "\n \nCe code livre est inexistant. \n ";
        cout << "Entrez un code de livre correct pour continuer ou entrer 0 pour retourner à votre espace : ";
        cin >> id;
    }
    cout << "Code correct. \n";
    book = bookList[id];
    member_confirm_return_menu(member,book);
}

void Network::member_confirm_return_menu(Member member, Book book){
    char choice;
    cout << member.getName() << ",vous avez s\202lectionnn\202 le livre suivant : \n \n ";
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
        member.borrowBook(book.getId());
    }
    if (choice == 'N'){
        this->member_borrow_menu(member);
    }
}

void Network::admin_menu(){
    int choice;
    cout << "\n \nBienvenue sur l'interface administrateur du logiciel du r\202seau nationnal des bibliothèques";
    cout << "Appuyez sur 1 pour créer un livre,";
    cout << "Appuyez sur 2 pour créer une biblioth\212que,";
    cout << "Appuyez sur 3 pour créer un adh\202rent,";
    cout << "Appuyez sur 4 pour vous déconnecter\n \n";
    cout << "Puis validez avec la touche Entr\202e \n";
    cin >> choice ;
    while (not (choice == 1 or choice == 2 or choice == 3 or choice == 4)){
        cout << "\n \nAppuyez sur 1,2,3 ou 4, puis validez avec la touche Entr\202e \n";
        cin >> choice;
    }
    if (choice == 1) {
        this->admin_create_book();
    }
    if (choice == 2) {
        this->admin_create_library();
    }
    if (choice == 3){
        this-> admin_create_member();
    }
    if (choice == 4){
        this->main_menu();
    }
}

void Network::admin_create_book() {
    int choice;
    cout << "\n \nBienvenue sur l'interface de cr\202ation de livres.";
    //cout << "\n \nEntrez les donn\202es du livre que vous voulez créer : ";
    cout << "Apuuyez sur 1 pour créer un album,\n";
    cout << "Appuyez sur 2 pour créer une bande dssinnée,\n";
    cout << "Appuyez sur 3 pour créer un roman,\n";
    cout << "Appuyer sur 4 pour créer une pièce de théâtre,\n";
    cout << "Appuyez sur 5 pour créer un recueil de poésie,\n";
    cout << "Appuyez sur 6 pour retourner au menu principal.";
    cout << "\n \nPuis validez avec la touche Entrée : \n \n";
    cin >> choice;
    while (not (choice == 1 or choice == 2 or choice == 3 or choice == 4 or choice == 5 or choice == 6)){
        cout << "\n \nAppuyez sur une touche entre 1 et 6, puis validez avec la touche Entr\202e \n";
        cin >> choice;
    }
}

void Network::admin_create_library() {
    cout << "Pas encore cod\202";
}

void Network::admin_create_member() {
    cout << "Pas encore cod\202";
}

void Network::library_menu() {
    cout << "Pas encore cod\202";
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
