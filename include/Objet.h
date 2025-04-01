#ifndef OBJET_H_INCLUDED
#define OBJET_H_INCLUDED
#include "Image.h"
#include "Dictionnaire.h"
#include <string>

using namespace std;

class Objet
{
    Image _image;
    int _x, _y;         // Coordonnées dans le niveau
    int _skin_x, _skin_y; // Coordonnées dans la feuille de sprites
    string _propriete;

public:
    // Constructeur qui initialise les attributs
    Objet(const Image& image, int x, int y, int skin_x, int skin_y, const string& propriete);
    // Nouveau constructeur qui prend un Dictionnaire
    Objet(const Image& image, const string& nom, const Dictionnaire& dictionnaire, int x, int y);
    // Accesseurs
    int getX() const;
    int getY() const;
    string getPropriete() const;
    // Méthode pour dessiner l'objet
    void dessiner() const;
    // Méthode pour cacher l'objet
    void cacher();
};

#endif // OBJET_H_INCLUDED
