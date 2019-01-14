#include "Network.h"


Network::Network() {
    this->libraryList.emplace(0,Library());
    this->memberList.emplace(0,Member());
    this->bookList.emplace(0,Book());
}

void Network::clear() {
    cout << "\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n" ;
}

void Network::main_menu() {
    int choice ;
    this->clear();
    cout << "Bienvenue dans le logiciel de gestion du réseau nationnnal des Bilbliothèques \n \n" ;
    cout << "Appuyez sur 1 si vous êtes un adhérent \n";
    cout << "Appuyez sur 2 si vous êtes une bibliothèque \n";
    cout << "Appuyez sur 3 pour quitter \n \n";
    cout << "Puis validez avec la touche Entrée \n";
    cin >> choice ;
    while (not (choice == 1 or choice == 2 or choice == 3)){
        cout << "\n \n Appuyez sur 1,2 ou 3, puis validez avec la touche Entrée \n";
        cin >> choice;
    }
    if (choice == 1) {
        this->member_menu();
    }
    if (choice == 2) {
        this->library_menu();
    }
}

void Network::member_menu() {
    this->clear();
    int id;
    Member member;
    cout << "Entrez votre numéro adhérent pour vous connecter \n ou entrez 0 pour retourner au menu principal: ";
    cin >> id;
    cout << "\n \n";
    while (id >= memberList.size() - 1 or id < 0) {
        cout << "Ce numéro d'adhérent n'existe pas. \n \n";
        cout << "Entrez votre numéro adhérent pour vous connecter ou entrez 0 pour retourner au menu principal: ";
        cin >> id;
    }
    if (id == 0 ){
        this->main_menu();
    }
    cout << "Identifiant correct. Connexion en cours. \n";
    member = memberList[id];
    this -> member_authentificated_menu(member);
}

void Network::member_authentificated_menu(Member member) {
    this->clear();
    int choice;
    cout << member.getName() << " ,bienvenue sur votre espace adhérent. \n \n";
    cout << "Appuyez sur 1 pour emprunter un livre \n";
    cout << "Appuyez sur 2 pour rendre un livre \n";
    cout << "Appuyer sur 3 pour vous déconnecter \n \n";
    cout << "Puis validez avec la touche Entrée \n";
    cin >> choice;
    while (not (choice == 1 or choice == 2 or choice == 3)){
        cout << "\n \n Appuyez sur 1,2 ou 3, puis validez avec la touche Entrée \n";
        cin >> choice;
    }
    if (choice == 1){
        this->member_borrow_menu(member);
    }
    if (choice == 2) {
        this->member_return_menu(member);
    }
    this->main_menu();
}

void Network::member_borrow_menu(Member member) {
    this->clear();
    int id;
    Book book;
    char choice;
    cout << "Espace " << member.getName() << "\n \n";
    cout << "Veuillez entrer le code du livre que vous voulez emprunter \n ou entrez 0 pour vous revenir dans votre espace personnel: ";
    cin >> id;
    cout << "\n \n";
    while (id >= bookList.size() - 1 or id < 0) {
        cout << "Ce code livre est inexistant. \n ";
        cout << "Entrez un code de livre correct pour continuer ou entrer 0 pour retourner à votre espace : ";
        cin >> id;
    }
    cout << "Code correct. \n";
    book = bookList[id];
    cout << "Vous avez sélectionnné le livre suivant : \n \n ";
    cout << book ;
    cout << "Confirmez-vous l'emprunt de ce livre ? \n";
    cout << "Entrez O pour oui ou N pour non";




}