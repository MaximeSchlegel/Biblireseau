//
// Created by Maxime on 14/01/2019.
//

#include "SaveManager.h"
#include <iostream>
#include <fstream>
using namespace std;


void SaveManager::save(Network network) {
    ofstream myfile;
    myfile.open (string(network.getName()) + string(".txt"), std::fstream::trunc);
    cout << network.getName() << endl;
    myfile << network.getName() << "  " << Library().getCreated() << endl;

    map<int, Library> libraryMap = network.getLibraryList();
    for (int id=1; id<Library().getCreated(); id++) {
        try {

            Library current = libraryMap[id];
            myfile << "{\nLibrary\nid:" << id << "\n name:" << current.getName() << "\naddress:" << current.getAddress() << "\n}" << endl;
            cout << "coucou";
        }
        catch (error_code) {
            cout << "error" << endl;
        }
    }
    myfile.close();
    cout << "Save finish" << endl;
}