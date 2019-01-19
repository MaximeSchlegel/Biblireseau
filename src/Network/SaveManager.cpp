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
    file <<  "<Network>\nname:" <<  network.getName() << "\n</Network>" << endl;

    map<int, Library> libraryMap = network.getLibraryList();
    for (int id=1; id<libraryMap.size(); id++) {
        try {
            Library current = libraryMap[id];
            cout << current << endl;
            file << "<Library>\nid:" << id << "\nname:" << current.getName() << "\naddress:" << current.getAddress() << "\n</Library>" << endl;
            cout << "coucou";
        }
        catch (error_code) {
            cout << "error" << endl;
        }
    }
    file.close();
    cout << "Save finish" << endl;
}

Network SaveManager::load(string path) {
    ifstream file;
    try {
        file.open(path, fstream::in);
    } catch(error_code) {
        cout << "file doesn't exist" << endl;
        throw 12;
    }

    vector<string> networkProp;
    vector<vector<string>> library;

    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            cout << line << endl;
            if (line=="<Network>") {
                if (!networkProp.empty()) {
                    cout << "Save corrupted : Two Network in the file" << endl;
                    throw 13;
                }
                string networkName;
                getline(file, networkName, ':');
                getline(file, networkName);
                networkProp.push_back(string(networkName);
                cout << networkName << endl;
                getline(file, line);
                cout << "Hello   " << line << endl;
                if (line != "</Network>") {
                    cout << "Save corrupted : Unable to load network properties" << endl;
                    throw 14;
                }
            }
        }
        file.close();
    }
    cout << "readfinish" << endl;
    Network result = Network(networkProp[1]);
    return result;
}

vector<string> SaveManager::split(string, char) {}