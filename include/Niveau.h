#ifndef NIVEAU_H
#define NIVEAU_H

#include "Objet.h"
#include "Dictionnaire.h"

#include <vector>

using namespace std;

class Niveau
{
  vector<Objet> _objets;
  int _nbPieces;

public:

  Niveau (Image image, const string& nomDuFichier, const Dictionnaire& dictionnaire);

  void dessiner() const;

  // Retourne `true` si la case n'est pas occupee par un objet "solide"
  bool caseEstLibre(int x, int y) const;

  void testerBonusEtPrendre(int x, int y);

  // S'il y a un objet de propriete "propriete" à la case (x,y), cette
  // fonction retourne son indice dans le vecteur _objets. Sinon, elle
  // retourne -1.
  int indiceObjet(int x, int y, const string& propriete) const;

  bool gagne() const;
};

#endif // NIVEAU_H
