#include "Poetry.h"
#include "Book.h"
#include <string>
using namespace std;

Poetry::Poetry()
       :Book() {
    this->verse = false;
    this->prose = false;
}

Poetry::Poetry(string name, string ISBN, string author, string editor, string audiance, bool verse, bool prose)
       :Book(name, ISBN, author, editor, audiance) {
    this->prose = prose;
    this->verse = verse;

}

bool Poetry::isVerse() const {
    return verse;
}

bool Poetry::isProse() const {
    return prose;
}