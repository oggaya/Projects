#ifndef TUILE_H_INCLUDED
#define TUILE_H_INCLUDED
#include <string>
#include <iostream>

using namespace std;

class Tuile
{
    string nom;
    int x;
    int y;
    string propriete;

public:
    // Constructeur qui initialise les attributs
    Tuile(const string& nom, int x, int y, const string& propriete);

    // Accesseurs
    string getNom() const;
    int getX() const;
    int getY() const;
    string getPropriete() const;

    // Fonction pour afficher les attributs
    void afficher() const;
};



#endif // TUILE_H_INCLUDED
