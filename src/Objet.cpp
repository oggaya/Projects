#include "Objet.h"

Objet::Objet (Image image, int x, int y, const string& nom, const Dictionnaire& dictionnaire)
{
  _image = image;
  _x = x;
  _y = y;
  mettreAJour(nom, dictionnaire);
}

string Objet::getPropriete() const
{
  return _propriete;
}

string Objet::getNom() const
{
  return _nom;
}

int Objet::getX() const
{
  return _x;
}

int Objet::getY() const
{
  return _y;
}

void Objet::mettreAJour (const string& nom, const Dictionnaire& dictionnaire)
{
  _nom = nom;
  Tuile tuile;
  if (!dictionnaire.recherche(nom, tuile))
    throw invalid_argument("Objet introuvable : " + nom);

  _image.selectionnerRectangle(tuile.getX() * TAILLE_CASE, tuile.getY() * TAILLE_CASE,
                               TAILLE_CASE, TAILLE_CASE);
  _propriete = tuile.getPropriete();
}

void Objet::dessiner() const
{
  _image.dessiner(_x, _y);
}

void Objet::cacher()
{
  _propriete = "cache";
}
