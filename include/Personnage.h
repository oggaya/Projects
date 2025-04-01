#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include "Image.h"
#include "Niveau.h"

enum Direction { GAUCHE, DROITE, HAUT, BAS };

class Personnage
{
  Image _image;
  int _skinX;
  int _skinY;
  int _x;
  int _y;
  Direction _direction;

public:

  Personnage(Image image, int skinX, int skinY, int x, int y,
             Direction direction = BAS);
  int getX() const;
  int getY() const;
  void dessiner() const;
  void allerDroite(const Niveau& niveau);
  void allerGauche(const Niveau& niveau);
  void allerHaut(const Niveau& niveau);
  void allerBas(const Niveau& niveau);
  bool bordAtteint(const Niveau& niveau, int x, int y) const;
  void mettreAJourDirection(Direction direction);
  void avancer(const Niveau& niveau);
  bool touche(const Personnage& autre) const;
};

#endif // PERSONNAGE_H
