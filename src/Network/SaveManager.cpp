//
// Created by Maxime on 14/01/2019.
//

#include "SaveManager.h"
#include <iostream>
#include <fstream>
using namespace std;


void SaveManager::save(Network network) {
    ofstream myfile;
    myfile.open (network.name + ".txt");
    for (int i=0; i<Library::)
}