#ifndef DICTIONNAIRE_H
#define DICTIONNAIRE_H

#include <vector>

#include "Tuile.h"

using namespace std;

class Dictionnaire
{
  vector<Tuile> _tuiles;

public:

  Dictionnaire(const string& nomDuFichier);

  void afficher() const;

  bool recherche(const string& nomTuile, Tuile& tuile) const;

};

#endif // DICTIONNAIRE_H
