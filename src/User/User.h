#ifndef BIBLIRESEAU_USER_H
#define BIBLIRESEAU_USER_H

#include <vector>
#include <ostream>

using namespace std;

class User {
private:
    static int created;
    int id;
    vector<int> bookList;

public:
    User(bool isEmpty);

    int getId() const;
    vector<int> const &getBook() const;

    friend std::ostream &operator<<(std::ostream &os, const User &user);
};


#endif //BIBLIRESEAU_USER_H
