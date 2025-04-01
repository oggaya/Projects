#ifndef OBJET_H
#define OBJET_H

#include "Image.h"
#include "Dictionnaire.h"

class Objet
{
  Image _image;
  int _x;
  int _y;
  string _nom;
  string _propriete;

public:

  Objet (Image image, int x, int y, const string& nom, const Dictionnaire& dictionnaire);

  void dessiner() const;

  // Accesseurs
  string getPropriete() const;
  string getNom() const;
  int getX() const;
  int getY() const;

  // Permet de remplacer un objet par un autre en selectionnant un autre nom
  void mettreAJour (const string& nom, const Dictionnaire& dictionnaire);

  // Remplace la propriete par "cache"
  void cacher();
};

#endif // OBJET_H
