#ifndef NIVEAU_H_INCLUDED
#define NIVEAU_H_INCLUDED
#include "Objet.h"
#include "Dictionnaire.h"
#include <vector>
#include <string>

using namespace std;

class Niveau
{
    vector<Objet> objets;
    int nombreBonus;

public:
    Niveau(const Image& image, const std::string& fichier, const Dictionnaire& dictionnaire);
    void dessiner() const;
    bool caseEstLibre(int x, int y) const;
    void testerBonusEtPrendre(int x, int y);
    bool gagne() const;
    int indiceObjet(int x, int y, const std::string& propriete) const; // Déclaration de la fonction
};

#endif // NIVEAU_H_INCLUDED
