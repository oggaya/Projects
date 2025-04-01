#include "Objet.h"
using namespace std;

// Constructeur qui initialise les attributs
Objet::Objet(const Image& image, int x, int y, int skin_x, int skin_y, const string& propriete)
    : _image(image), _x(x), _y(y), _skin_x(skin_x), _skin_y(skin_y), _propriete(propriete)
{
    // Sélectionner la portion de l'image à dessiner
    _image.selectionnerRectangle(_skin_x * 16, _skin_y * 16, 16, 16);
}

// Nouveau constructeur qui prend un Dictionnaire
Objet::Objet(const Image& image, const string& nom, const Dictionnaire& dictionnaire, int x, int y)
    : _image(image), _x(x), _y(y)
{
    // Récupérer les informations sur l’objet en recherchant dans le dictionnaire
    Tuile resultat("", 0, 0, "");
    if (dictionnaire.recherche(nom, resultat))
    {
        _skin_x = resultat.getX();
        _skin_y = resultat.getY();
        _propriete = resultat.getPropriete();

        // Sélectionner la portion de l'image à dessiner
        _image.selectionnerRectangle(_skin_x * 16, _skin_y * 16, 16, 16);
    }
    else
    {
        throw runtime_error("Objet non trouvé dans le dictionnaire: " + nom);
    }
}

// Accesseurs
int Objet::getX() const
{
    return _x;
}

int Objet::getY() const
{
    return _y;
}

string Objet::getPropriete() const
{
    return _propriete;
}

// Méthode pour dessiner l'objet
void Objet::dessiner() const
{
    if (_propriete != "cache")
    {
        _image.dessiner(_x, _y);
    }
}

// Méthode pour cacher l'objet
void Objet::cacher()
{
    _propriete = "cache";
}
