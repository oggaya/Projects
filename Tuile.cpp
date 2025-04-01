#include "Tuile.h"

using namespace std;

// Constructeur qui initialise les attributs
Tuile::Tuile(const string& nom, int x, int y, const string& propriete)
    : nom(nom), x(x), y(y), propriete(propriete) {}

// Accesseurs
string Tuile::getNom() const
{
    return nom;
}

int Tuile::getX() const
{
    return x;
}

int Tuile::getY() const
{
    return y;
}

string Tuile::getPropriete() const
{
    return propriete;
}

// Fonction pour afficher les attributs
void Tuile::afficher() const
{
    cout << nom << ": x=" << x << ", y=" << y << ", " << propriete << std::endl;
}
