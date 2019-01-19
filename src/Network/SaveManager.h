//
// Created by Maxime on 14/01/2019.
//

#ifndef TARGET_NAME_SAVEMANAGER_H
#define TARGET_NAME_SAVEMANAGER_H

#include "Network.h"
#include <string>

class SaveManager {
    public:
        void save(Network network, string path="");
        Network load(string path);
        vector<string> split (string, char);
};


#endif //TARGET_NAME_SAVEMANAGER_H
