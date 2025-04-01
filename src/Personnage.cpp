#include "Personnage.h"
#include "Niveau.h"
#include <cstdlib>
#include <ctime>

// Constructeur
Personnage::Personnage(const Image& image, int x, int y, int skin_x, int skin_y, Direction direction)
    : _image(image), _x(x), _y(y), _skin_x(skin_x), _skin_y(skin_y), _direction(direction), _indexAnimation(0)
{
    mettreAJourDirection(direction); // Initialisation de la direction
}


int Personnage::getX() const
{
    return _x;
}

int Personnage::getY() const
{
    return _y;
}

void Personnage::setX(int x)
{
    _x = x;
}

void Personnage::setY(int y)
{
    _y = y;
}

void Personnage::dessiner() const
{
    _image.dessiner(_x, _y);
}

void Personnage::mettreAJourDirection(Direction direction)
{
    _direction = direction;
    switch (_direction)
    {
    case HAUT:
        _image.selectionnerRectangle((_skin_x + 1) * TAILLE_PERSONNAGE, (_skin_y + 3) * TAILLE_PERSONNAGE, TAILLE_PERSONNAGE, TAILLE_PERSONNAGE);
        break;
    case BAS:
        _image.selectionnerRectangle((_skin_x + 1) * TAILLE_PERSONNAGE, _skin_y * TAILLE_PERSONNAGE, TAILLE_PERSONNAGE, TAILLE_PERSONNAGE);
        break;
    case GAUCHE:
        _image.selectionnerRectangle((_skin_x + 1) * TAILLE_PERSONNAGE, (_skin_y + 1) * TAILLE_PERSONNAGE, TAILLE_PERSONNAGE, TAILLE_PERSONNAGE);
        break;
    case DROITE:
        _image.selectionnerRectangle((_skin_x + 1) * TAILLE_PERSONNAGE, (_skin_y + 2) * TAILLE_PERSONNAGE, TAILLE_PERSONNAGE, TAILLE_PERSONNAGE);
        break;
    }
}


void Personnage::mettreAJourAnimation()
{
    _indexAnimation = (_indexAnimation + 1) % 4;  // Boucler entre 0 et 3 pour l'animation
    int imageIndices[4][4] =
    {
        {_skin_x, _skin_x+1, _skin_x+2, _skin_x+1}, // BAS : indices des images pour la direction BAS
        {_skin_x, _skin_x+1, _skin_x+2, _skin_x+1}, // HAUT : indices des images pour la direction HAUT
        {_skin_x, _skin_x+1, _skin_x+2, _skin_x+1}, // GAUCHE : indices des images pour la direction GAUCHE
        {_skin_x, _skin_x+1, _skin_x+2, _skin_x+1}  // DROITE : indices des images pour la direction DROITE
    };

    switch (_direction)
    {
    case HAUT:
        _image.selectionnerRectangle(imageIndices[1][_indexAnimation] * TAILLE_PERSONNAGE, (_skin_y + 3) * TAILLE_PERSONNAGE, TAILLE_PERSONNAGE, TAILLE_PERSONNAGE);
        break;
    case BAS:
        _image.selectionnerRectangle(imageIndices[0][_indexAnimation] * TAILLE_PERSONNAGE, _skin_y * TAILLE_PERSONNAGE, TAILLE_PERSONNAGE, TAILLE_PERSONNAGE);
        break;
    case GAUCHE:
        _image.selectionnerRectangle(imageIndices[2][_indexAnimation] * TAILLE_PERSONNAGE, (_skin_y + 1) * TAILLE_PERSONNAGE, TAILLE_PERSONNAGE, TAILLE_PERSONNAGE);
        break;
    case DROITE:
        _image.selectionnerRectangle(imageIndices[3][_indexAnimation] * TAILLE_PERSONNAGE, (_skin_y + 2) * TAILLE_PERSONNAGE, TAILLE_PERSONNAGE, TAILLE_PERSONNAGE);
        break;
    }
}

// Méthodes de mouvement
void Personnage::allerDroite(const Niveau& niveau)
{
    int nouvelle_x = _x + TAILLE_PERSONNAGE;
    if (nouvelle_x < 16 * 10 && niveau.caseEstLibre(nouvelle_x, _y))
    {
        _x = nouvelle_x;
        mettreAJourDirection(DROITE);  // Mise à jour de la direction
    }
}
// Méthodes de mouvement
void Personnage::allerGauche(const Niveau& niveau)
{
    int nouvelle_x = _x - TAILLE_PERSONNAGE;
    if (nouvelle_x >= 0 && niveau.caseEstLibre(nouvelle_x, _y))
    {
        _x = nouvelle_x;
        mettreAJourDirection(GAUCHE);  // Mise à jour de la direction
    }
}

// Méthodes de mouvement
void Personnage::allerHaut(const Niveau& niveau)
{
    int nouvelle_y = _y - TAILLE_PERSONNAGE;
    if (nouvelle_y >= 0 && niveau.caseEstLibre(_x, nouvelle_y))
    {
        _y = nouvelle_y;
        mettreAJourDirection(HAUT);  // Mise à jour de la direction
    }
}

// Méthodes de mouvement
void Personnage::allerBas(const Niveau& niveau)
{
    int nouvelle_y = _y + TAILLE_PERSONNAGE;
    if (nouvelle_y < 16 * 8 && niveau.caseEstLibre(_x, nouvelle_y))
    {
        _y = nouvelle_y;
        mettreAJourDirection(BAS);  // Mise à jour de la direction
    }
}

void Personnage::avancer(const Niveau& niveau)
{
    static int pas_restants = 0;

    if (pas_restants == 0) // Si pas_restants est nul, on choisit une nouvelle direction aléatoire
    {
        _direction = static_cast<Direction>(rand() % 4);
        pas_restants = rand() % 5 + 1; // Définir un nombre de pas aléatoire entre 1 et 5
    }

    int nouvelle_x = _x, nouvelle_y = _y;

    switch (_direction)
    {
    case HAUT:
        nouvelle_y -= TAILLE_PERSONNAGE;
        break;
    case BAS:
        nouvelle_y += TAILLE_PERSONNAGE;
        break;
    case GAUCHE:
        nouvelle_x -= TAILLE_PERSONNAGE;
        break;
    case DROITE:
        nouvelle_x += TAILLE_PERSONNAGE;
        break;
    }

    // Vérifie si la nouvelle position est libre avant de mettre à jour
    if (niveau.caseEstLibre(nouvelle_x, nouvelle_y))
    {
        _x = nouvelle_x;
        _y = nouvelle_y;
        pas_restants--;
    }
    else
    {
        pas_restants = 0; // Réinitialise le compteur de pas restants si le chemin est bloqué
    }

    mettreAJourDirection(_direction); // Mise à jour de la direction et de l'animation
}

bool Personnage::touche(const Personnage& autre) const
{
    return _x == autre.getX() && _y == autre.getY();
}
