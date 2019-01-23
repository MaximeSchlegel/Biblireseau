//
// Created by mimmo on 11/12/2018.
//

#include "Novel.h"

const std::vector<string> validGenre = {"Littérature", "Roman noir", "Roman policier", "Roman animalier", "Roman d'amour", "Roman de mœurs", "Roman gothique", "Roman courtois", "Roman épistolaire", "Roman-feuilleton", "Roman graphique",
                                         "Roman historique", "Roman-photo", "Roman picaresque", "Roman-mémoires", "Roman populaire", "Roman d'aventures", "Roman d'anticipation", "Roman d'espionnage", "Roman d'apprentissage", "Roman de chevalerie",
                                         "Roman autobiographique", "Nouveau roman", "Roman chevaleresque", "Conte", "Nouvelle", ""};

Novel::Novel()
      :Book() {
    this->genre = "";
}

Novel::Novel(string name, string ISBN, string author, string editor, string audiance, string genre)
      :Book(name, ISBN, author, editor, audiance) {
    bool isValid = false;
    for (int i=0; i < validGenre.size(); i++) {
        if (validGenre[i] == genre) {
            isValid = true;
        }
    }
    if (isValid) {
        this->genre = genre;
    }
    else {
        cout << genre << " is not a valid genre for a Novel" << endl;
        throw 11;
    }
}

const vector<string> &Novel::getValidGenre() {
    return validGenre;
}

const string &Novel::getGenre() const {
    return genre;
}

string Novel::getType() const {
    return "Novel";
}