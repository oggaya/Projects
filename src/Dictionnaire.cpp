#include "Dictionnaire.h"

#include <fstream>
#include <iostream>

using namespace std;

Dictionnaire::Dictionnaire(const string& nomDuFichier)
{
  ifstream fichier(nomDuFichier);
  if (!fichier)
    throw std::runtime_error("Impossible de charger " + nomDuFichier);

  int nbLignes;
  fichier >> nbLignes;

  for (int i = 0; i < nbLignes; i ++)
  {
    string nom, propriete;
    int x, y;
    fichier >> nom >> x >> y >> propriete;
    _tuiles.push_back(Tuile(nom, x, y, propriete));
  }
}

void Dictionnaire::afficher() const
{
  cout << "Le dictionnaire contient:" << endl;
  for (int i = 0; i < _tuiles.size(); i ++)
    _tuiles[i].afficher();
}

bool Dictionnaire::recherche(const string& nomTuile, Tuile& tuile) const
{
  // Recherche dichotomique
  bool trouve = false;
  int debut = 0, fin = _tuiles.size() - 1;
  while (!trouve && debut <= fin)
  {
    int milieu = (debut + fin) / 2;

    if (_tuiles[milieu].getNom() == nomTuile)
    {
      tuile = _tuiles[milieu];
      trouve = true;
    }
    else if (_tuiles[milieu].getNom() < nomTuile)
      debut = milieu + 1;
    else
      fin = milieu - 1;
  }
  return trouve;
}
