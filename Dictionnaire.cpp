#include "Dictionnaire.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;

// Constructeur qui initialise les tuiles à partir d'un fichier
Dictionnaire::Dictionnaire(const string& fichier)
{
    cerr << "Ouverture du fichier dictionnaire: " << fichier << endl;
    ifstream infile(fichier);
    if (!infile)
    {
        throw runtime_error("Erreur d'ouverture du fichier: " + fichier);
    }

    int nombreTuiles;
    infile >> nombreTuiles;
    cerr << "Nombre de tuiles : " << nombreTuiles << endl;
    infile.ignore(); // Pour ignorer le retour à la ligne après le nombre

    string ligne;
    while (getline(infile, ligne))
    {
        cerr << "Lecture de la ligne: " << ligne << endl;
        istringstream iss(ligne);
        string nom, propriete;
        int x, y;
        if (!(iss >> nom >> x >> y >> propriete))
        {
            throw runtime_error("Erreur de lecture du fichier: " + fichier);
        }
        cerr << "Lecture de l'objet: " << nom << " " << x << " " << y << " " << propriete << endl;
        tuiles.emplace_back(nom, x, y, propriete);
    }
    cerr << "Lecture du fichier dictionnaire terminee avec succes." << endl;
}

// Méthode pour afficher les tuiles
void Dictionnaire::afficher() const
{
    for (const auto& tuile : tuiles)
    {
        tuile.afficher();
    }
}

// Méthode pour rechercher une tuile par nom
bool Dictionnaire::recherche(const string& nom, Tuile& resultat) const
{
    for (const auto& tuile : tuiles)
    {
        if (tuile.getNom() == nom)
        {
            resultat = tuile;  // Copier l'objet trouvé dans le paramètre resultat
            return true;
        }
    }
    return false;
}
