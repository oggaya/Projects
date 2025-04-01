#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#include "Image.h"
#include "Niveau.h"

enum Direction { HAUT, BAS, GAUCHE, DROITE };

class Personnage
{
    Image _image;
    int _x, _y;
    int _skin_x, _skin_y;
    static const int TAILLE_PERSONNAGE = 16;
    Direction _direction;
    int _indexAnimation;  // Index de l'animation pour alterner les images

public:
    // Constructeur
    Personnage(const Image& image, int x, int y, int skin_x, int skin_y, Direction direction = BAS);

    // Accesseurs
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);

    // M�thodes de mouvement
    void allerDroite(const Niveau& niveau);
    void allerGauche(const Niveau& niveau);
    void allerHaut(const Niveau& niveau);
    void allerBas(const Niveau& niveau);
    // M�thode de dessin
    void dessiner() const;
    // M�thode pour mettre � jour la direction et l'animation
    void mettreAJourDirection(Direction direction);
    void mettreAJourAnimation();  // Pour mettre � jour l'animation
    // M�thodes pour avancer et d�tecter des collisions
    void avancer(const Niveau& niveau);  // D�claration de la m�thode
    //M�thode permettant de savoir si le personnage touche un ennemi
    bool touche(const Personnage& autre) const;
};

#endif // PERSONNAGE_H
