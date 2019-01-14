//
// Created by Maxime on 14/01/2019.
//

#include "SaveManager.h"
#include <iostream>
#include <fstream>
using namespace std;


void SaveManager::save(Network network) {
    ofstream myfile;
    myfile.open (network.getName() + ".txt");
    myfile << network.getName() << "\n";
    map<int, Library> libraryMap = network.getLibraryList();
    for (int id=1; id<Library().getCreated(); id++) {
        try {
            Library current = libraryMap[id];
            myfile << "{\nLibrary\nid:" << id << "\n name:" << current.getName() << "\naddress:" << current.getAddress() << "\n}\n";
        }
        catch (error_code) {}
        myfile.close();
        return 0;
    }
}