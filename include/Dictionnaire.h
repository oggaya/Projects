#ifndef DICTIONNAIRE_H_INCLUDED
#define DICTIONNAIRE_H_INCLUDED
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
#include "Tuile.h"

using namespace std;

class Dictionnaire
{
    std::vector<Tuile> tuiles;

public:
    // Constructeur qui initialise les tuiles à partir d'un fichier
    Dictionnaire(const string& fichier);

    // Méthode pour afficher les tuiles
    void afficher() const;

    // Méthode pour rechercher une tuile par nom
    bool recherche(const string& nom, Tuile& resultat) const;
};

#endif // DICTIONNAIRE_H_INCLUDED
