#include "Niveau.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

// Constructeur qui initialise les objets à partir d'un fichier
Niveau::Niveau(const Image& image, const string& fichier, const Dictionnaire& dictionnaire)
    : nombreBonus(0)
{
    ifstream infile(fichier);
    if (!infile)
    {
        throw runtime_error("Erreur d'ouverture du fichier: " + fichier);
    }

    int nombreObjets;
    infile >> nombreObjets;
    infile.ignore(); // Pour ignorer le retour à la ligne après le nombre

    string ligne;
    while (getline(infile, ligne))
    {
        istringstream iss(ligne);
        string nom;
        int x, y;
        if (!(iss >> nom >> x >> y))
        {
            throw runtime_error("Erreur de lecture du fichier: " + fichier);
        }
        Objet objet(image, nom, dictionnaire, x * 16, y * 16);
        if (objet.getPropriete() == "bonus")
        {
            nombreBonus++;
        }
        objets.push_back(objet);
    }
}

// Méthode pour dessiner le niveau
void Niveau::dessiner() const
{
    for (const auto& objet : objets)
    {
        if (objet.getPropriete() != "cache")
        {
            objet.dessiner();
        }
    }
}

// Sous-fonction pour trouver l'indice d'un objet par coordonnées et propriété
int Niveau::indiceObjet(int x, int y, const string& propriete) const
{
    for (size_t i = 0; i < objets.size(); ++i)
    {
        if (objets[i].getX() == x && objets[i].getY() == y && objets[i].getPropriete() == propriete)
        {
            return static_cast<int>(i);
        }
    }
    return -1;
}

// Méthode pour vérifier si une case est libre
bool Niveau::caseEstLibre(int x, int y) const
{
    return indiceObjet(x, y, "solide") == -1;
}

// Méthode pour tester et prendre un bonus
void Niveau::testerBonusEtPrendre(int x, int y)
{
    int indice = indiceObjet(x, y, "bonus");
    if (indice != -1)
    {
        objets[indice].cacher();
        nombreBonus--;
    }
}

// Méthode pour vérifier si le joueur a gagné
bool Niveau::gagne() const
{
    return nombreBonus == 0;
}
