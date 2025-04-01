#include "Personnage.h"

Personnage::Personnage(Image image, int skinX, int skinY, int x, int y,
                       Direction direction)
{
  _image = image;
  _skinX = skinX;
  _skinY = skinY;
  _x = x;
  _y = y;
  mettreAJourDirection(direction);
}

int Personnage::getX() const
{
  return _x;
}

int Personnage::getY() const
{
  return _y;
}

void Personnage::dessiner() const
{
  _image.dessiner(_x, _y);
}

void Personnage::allerDroite(const Niveau& niveau)
{
  mettreAJourDirection(DROITE);
  if (!bordAtteint(niveau, _x + TAILLE_CASE, _y))
    _x += TAILLE_CASE;
}

void Personnage::allerGauche(const Niveau& niveau)
{
  mettreAJourDirection(GAUCHE);
  if (!bordAtteint(niveau, _x - TAILLE_CASE, _y))
    _x -= TAILLE_CASE;
}

void Personnage::allerHaut(const Niveau& niveau)
{
  mettreAJourDirection(HAUT);
  if (!bordAtteint(niveau, _x, _y - TAILLE_CASE))
    _y -= TAILLE_CASE;
}

void Personnage::allerBas(const Niveau& niveau)
{
  mettreAJourDirection(BAS);
  if (!bordAtteint(niveau, _x, _y + TAILLE_CASE))
    _y += TAILLE_CASE;
}

bool Personnage::bordAtteint(const Niveau& niveau, int x, int y) const
{
  if (!niveau.caseEstLibre(x, y))
    return true;

  return (x < 0 || x >= LARGEUR_FENETRE ||
          y < 0 || y >= HAUTEUR_FENETRE);
}

void Personnage::mettreAJourDirection(Direction direction)
{
  _direction = direction;
   switch (_direction)
  {
    case GAUCHE:
      _image.selectionnerRectangle((_skinX + 1) * TAILLE_CASE, (_skinY + 1) * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
      break;
    case DROITE:
      _image.selectionnerRectangle((_skinX + 1) * TAILLE_CASE, (_skinY + 2) * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
     break;
    case HAUT:
      _image.selectionnerRectangle((_skinX + 1) * TAILLE_CASE, (_skinY + 3) * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
      break;
    case BAS:
      _image.selectionnerRectangle((_skinX + 1) * TAILLE_CASE, _skinY * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
      break;
  }
}

void Personnage::avancer(const Niveau& niveau)
{
  if (_direction == GAUCHE && (bordAtteint(niveau, _x - TAILLE_CASE, _y)))
      _direction = DROITE;
  if (_direction == DROITE && (bordAtteint(niveau, _x + TAILLE_CASE, _y)))
      _direction = GAUCHE;
  if (_direction == HAUT && (bordAtteint(niveau, _x, _y - TAILLE_CASE)))
      _direction = BAS;
  if (_direction == BAS && (bordAtteint(niveau, _x, _y + TAILLE_CASE)))
      _direction = HAUT;
  switch (_direction)
  {
    case GAUCHE:
      allerGauche(niveau);
      break;
    case DROITE:
      allerDroite(niveau);
      break;
    case HAUT:
      allerHaut(niveau);
      break;
    case BAS:
      allerBas(niveau);
      break;
  }
}


bool Personnage::touche(const Personnage& autre) const
{
  return _x == autre._x && _y == autre._y;
}
