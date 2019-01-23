//
// Created by Maxime on 14/01/2019.
//

#include "SaveManager.h"
#include <iostream>
#include <fstream>
using namespace std;


void SaveManager::save(Network network, string path) {
    ofstream file;
    file.open (path + string(network.getName()) + string(".txt"), std::fstream::trunc);

    file <<  "<Network>\nname:" <<  network.getName() << ";\n</Network>" << endl;

    map<int, Library> libraryMap = network.getLibraryList();
    for (map<int, Library>::iterator it=libraryMap.begin(); it!=libraryMap.end(); ++it) {
        try {
            Library current = it->second;
            if (current.getId() != 0) {
                file << "<Library>\nid:" << current.getId() << ";\nname:" << current.getName() << ";\naddress:" << current.getAddress();
                file << ";\n</Library>" << endl;
            }
        }
        catch (error_code) {
            cout << "error in saving network" << endl;
            return;
        }
    }

    map<int, Member> memberMap = network.getMemberList();
    for (map<int, Member>::iterator it=memberMap.begin(); it!=memberMap.end(); ++it) {
        try {
            Member current = it->second;
            if (current.getId() != 0) {
                file << "<Member>\nid:" << current.getId() << ";\nname:" << current.getName() << ";\nsurname:" << current.getSurname();
                file << ";\naddress:" << current.getAddress() << ";\nphone:" << current.getPhone() << ";\nregistered:";
                if (current.getRegistered()) {
                    file << current.getRegistered()->getId();
                }
                file << ";\nmaxBorrowing:" << current.getMaxBorrowing() << ";\n</Member>"<<endl;
            }

        } catch (error_code) {
            cout << "error in saving member" << endl;
            return;
        }
    }

    map<int, Book> bookMap = network.getBookList();
    for (map<int,Book>::iterator it=bookMap.begin(); it != bookMap.end(); ++it) {
        try {
            Book current = it->second;
            if (current.getId() != 0) {
                if (current.getType() == "Album") {
                    file << "<Album>\nid:" << current.getId() << ";\ntitle:" << current.getTitle() << ";\nISBN:"
                         << current.getISBN();
                    file << ";\nauthor:" << current.getAuthor() << ";\neditor:" << current.getEditor() << ";\naudiance:"
                         << current.getAudience();
                    file << ";\nowner:";
                    if (current.getOwner()) {
                        file << current.getOwner()->getId();
                    }
                    file << ";;\nlocation:";
                    if (current.getLocation()) {
                        if (current.getLocation()->getType() == "Library") {
                            file << "Library;" << current.getLocation()->getId();
                        } else {
                            file << "Member;" << current.getLocation()->getId();
                        }
                    } else {
                        file << ";;";
                    }
                    file << "\n</Album>" << endl;
                }
                if (current.getType() == "Comic") {
                    file << "<Comic>\nid:" << current.getId() << ";\ntitle:" << current.getTitle() << ";\nISBN:"
                         << current.getISBN();
                    file << ";\nauthor:" << current.getAuthor() << ";\neditor:" << current.getEditor() << ";\naudiance:"
                         << current.getAudience();
                    file << ";\nowner:";
                    if (current.getOwner()) {
                        file << current.getOwner()->getId();
                    }
                    file << ";;\nlocation:";
                    if (current.getLocation()) {
                        if (current.getLocation()->getType() == "Library") {
                            file << "Library;" << current.getLocation()->getId();
                        } else {
                            file << "Member;" << current.getLocation()->getId();
                        }
                    } else {
                        file << ";;";
                    }
                    file << "\n</Comic>" << endl;
                }
                if (current.getType() == "Novel") {
                    file << "<Novel>\nid:" << current.getId() << ";\ntitle:" << current.getTitle() << ";\nISBN:"
                         << current.getISBN();
                    file << ";\nauthor:" << current.getAuthor() << ";\neditor:" << current.getEditor() << ";\naudiance:"
                         << current.getAudience();
                    file << ";\nowner:";
                    if (current.getOwner()) {
                        file << current.getOwner()->getId();
                    }
                    file << ";;\nlocation:";
                    if (current.getLocation()) {
                        if (current.getLocation()->getType() == "Library") {
                            file << "Library;" << current.getLocation()->getId();
                        } else {
                            file << "Member;" << current.getLocation()->getId();
                        }
                    } else {
                        file << ";;";
                    }
                    file << "\n</Novel>" << endl;
                }
                if (current.getType() == "Play") {
                    file << "<Play>\nid:" << current.getId() << ";\ntitle:" << current.getTitle() << ";\nISBN:"
                         << current.getISBN();
                    file << ";\nauthor:" << current.getAuthor() << ";\neditor:" << current.getEditor() << ";\naudiance:"
                         << current.getAudience();
                    file << ";\nowner:";
                    if (current.getOwner()) {
                        file << current.getOwner()->getId();
                    }
                    file << ";;\nlocation:";
                    if (current.getLocation()) {
                        if (current.getLocation()->getType() == "Library") {
                            file << "Library;" << current.getLocation()->getId();
                        } else {
                            file << "Member;" << current.getLocation()->getId();
                        }
                    } else {
                        file << ";;";
                    }
                    file << "\n</Play>" << endl;
                }
                if (current.getType() == "Poetry") {
                    file << "<Poetry>\nid:" << current.getId() << ";\ntitle:" << current.getTitle() << ";\nISBN:"
                         << current.getISBN();
                    file << ";\nauthor:" << current.getAuthor() << ";\neditor:" << current.getEditor() << ";\naudiance:"
                         << current.getAudience();
                    file << ";\nowner:";
                    if (current.getOwner()) {
                        file << current.getOwner()->getId();
                    }
                    file << ";;\nlocation:";
                    if (current.getLocation()) {
                        if (current.getLocation()->getType() == "Library") {
                            file << "Library;" << current.getLocation()->getId();
                        } else {
                            file << "Member;" << current.getLocation()->getId();
                        }
                    } else {
                        file << ";;";
                    }
                    file << "\n</Poetry>" << endl;
                }
                if (current.getType() == "Book") {
                    file << "<Book>\nid:" << current.getId() << ";\ntitle:" << current.getTitle() << ";\nISBN:"
                         << current.getISBN();
                    file << ";\nauthor:" << current.getAuthor() << ";\neditor:" << current.getEditor() << ";\naudiance:"
                         << current.getAudience();
                    file << ";\nowner:";
                    if (current.getOwner()) {
                        file << current.getOwner()->getId();
                    }
                    file << ";;\nlocation:";
                    if (current.getLocation()) {
                        if (current.getLocation()->getType() == "Library") {
                            file << "Library;" << current.getLocation()->getId();
                        } else {
                            file << "Member;" << current.getLocation()->getId();
                        }
                    } else {
                        file << ";;";
                    }
                    file << "\n</Book>" << endl;
                }
            }
        } catch (error_code) {
            cout << "error in saving book" << endl;
            return;
        }
    }
    file.close();
    cout << "Save Finish" << endl;
}

Network SaveManager::load(string path) {
    ifstream file;
    try {
        file.open(path, fstream::in);
    } catch(error_code) {
        cout << "file doesn't exist" << endl;
        throw 12;
    }

    if (file.is_open()) {
        std::string line;
        getline(file, line);

        string networkName;
        if (line=="<Network>") {
            getline(file, line, ':');         // name tag
            getline(file, networkName, ';');  // name
            getline(file, line);              // ;
            cout << networkName << endl << endl;
            getline(file, line);              // </Network> si tout est OK
            if (line != "</Network>") {
                cout << "Save corrupted : Unable to load properties (Network)" << endl;
                throw 14;
            }
        } else {
            cout << "Save corrupted : Unable to load properties (Network)" << endl;
            throw 14;
        }
        Network result = Network(networkName);

        while (getline(file, line)) {
            if (line=="<Network>") {
                cout << "Save corrupted : Two Network in the file" << endl;
                throw 13;
            }

            if (line=="<Library>") {
                if (networkName.empty()) {
                    cout << "Save corrupted : No network Found" << endl;
                    throw 14;
                }
                getline(file, line, ':');          // id tag
                getline(file, line, ';');          // real id
                int id = stoi(line);
//                cout << "id:" << id << "\ncreated:" << Library().getCreated() << endl;
                if (id < Library().getCreated()) {
                    cout << "Save corrupted : Unable to load properties (Library Id)" << endl;
                    throw 14;
                }
                getline(file, line, ':');          // name tag
                getline(file, line, ';');          // name
                string name = line;
                getline(file, line, ':');          // address tag
                getline(file, line, ';');          // address
                string address = line;
                getline(file,line);
                getline(file,line);
//                cout << line << endl;
                if (line != "</Library>") {
                    cout << "Save corrupted : Unable to load properties (Library)" << endl;
                    throw 14;
                }
                Library newLibrary = Library(name, address);
                while (newLibrary.getId() != id) {
                    Library newLibrary = Library(name, address);
                }
                result.addLibrary(newLibrary);
            }

            if (line=="<Member>") {
                if (networkName.empty()) {
                    cout << "Save corrupted : No network Found" << endl;
                    throw 14;
                }
                getline(file, line, ':');          // id tag
                getline(file, line, ';');          // id
                int id = stoi(line);
//                cout << "id:" << id << "\ncreated:" << Member().getCreated() << endl;
                if (id < Member().getCreated()) {
                    cout << "Save corrupted : Unable to load properties (Member Id)" << endl;
                    throw 14;
                }
                getline(file, line, ':');          // name tag
                getline(file, line, ';');          // name
                string name = line;
                getline(file, line, ':');          // surname tag
                getline(file, line, ';');          // surname
                string surname = line;
                getline(file, line, ':');          // address tag
                getline(file, line, ';');          // address
                string address = line;
                getline(file, line, ':');          // phone tag
                getline(file, line, ';');          // phone
                string phone = line;
                getline(file, line, ':');          // registered tag
                getline(file, line, ';');          // registered
                int registered = 0;
                if (line != "") {
                    registered = stoi(line);
                }
                getline(file, line, ':');          // maxBorrowing tag
                getline(file, line, ';');          // maxBorrowing
                int maxBorrowing = stoi(line);
                Member newMember = Member(name, surname, address, phone, maxBorrowing);
                while (newMember.getId() != id) {
                    Member newMember = Member(name, surname, address, phone, maxBorrowing);
                }
                if (registered != 0) {
//                    Library* target = result.getLibraryList().at(registered).getPointer();
//                    newMember.setRegister(target);

                }
                result.addMember(newMember);
            }
        }
        file.close();
        cout << "Load Finish" << endl;
        return result;
    } else {
        cout << "file doesn't exist" << endl;
        throw 12;
    }
}

vector<string> SaveManager::split(string, char) {}