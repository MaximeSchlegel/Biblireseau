#ifndef BIBLIRESEAU_USER_H
#define BIBLIRESEAU_USER_H

#include <vector>
using namespace std;

class User {
private:
    static int created;
    int id;
    vector<int> bookList;

public:
    User(bool isEmpty);
    int getId();
};


#endif //BIBLIRESEAU_USER_H
