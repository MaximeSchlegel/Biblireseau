//
// Created by Maxime on 14/01/2019.
//

#ifndef TARGET_NAME_SAVEMANAGER_H
#define TARGET_NAME_SAVEMANAGER_H

#include "Network.h"
#include <string>

class SaveManager {
    public:
        void save(Network network);
        Network load(string path);
};


#endif //TARGET_NAME_SAVEMANAGER_H
