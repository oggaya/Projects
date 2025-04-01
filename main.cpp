#include "Moteur.h"
#include "Personnage.h"
#include "Image.h"
#include "Dictionnaire.h"
#include "Objet.h"
#include "Niveau.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int, char**)
{
    // Initialisation du moteur avec le nom du jeu
    Moteur moteur("Mon super jeu vidéo");

    // Chargement des ressources
    Image fond(moteur, "assets/fond.png");
    Image personnageImage(moteur, "assets/personnages.png");
    Image objetsImage(moteur, "assets/objets.png");
    Dictionnaire dictionnaire("assets/dictionnaire.txt");
    Niveau niveau(objetsImage, "assets/niveau1.txt", dictionnaire);
    Image gameoverImage(moteur, "assets/gameover.png");
    Image bravoImage(moteur, "assets/bravo.png");

    // Création des personnages
    ///PERSONNAGE HOMME A COMMENTE SI SOUHAITE JOUER AVEC LE FEMININ
    Personnage personnage(personnageImage, TAILLE_CASE, 2 * TAILLE_CASE, 3, 0, BAS);
    ///PERSONNAGE FEMININ A DECOMMENTE SI SOUHAITE JOUER AVEC :
    //Personnage personnage(personnageImage, TAILLE_CASE, 2 * TAILLE_CASE, 6, 0, BAS);

    ///ENNEMIES A COMMENTE ET DECOMMENTE POUR JOUER AVEC QUE VOUS VOULEZ
    //ENNEMIES DE BASE : SLIM & FANTOME

    ///SQUELETTE ENNEMI 1 PUIS 2
    //Personnage ennemi1(personnageImage, 4 * TAILLE_CASE, TAILLE_CASE, 9, 0, BAS);
    //Personnage ennemi2(personnageImage, TAILLE_CASE, 4*TAILLE_CASE, 9, 0, BAS);
    ///ARAIGNEE ENNEMI 1 PUIS 2
    //Personnage ennemi1(personnageImage, 4 * TAILLE_CASE, TAILLE_CASE, 9, 4, DROITE);
    //Personnage ennemi2(personnageImage, TAILLE_CASE, 4 * TAILLE_CASE, 9, 4, DROITE);
    ///SLIME ENNEMI 1 PUIS 2
    Personnage ennemi1(personnageImage, 4 * TAILLE_CASE, TAILLE_CASE, 0, 4, DROITE);
    //Personnage ennemi2(personnageImage, TAILLE_CASE, 4 * TAILLE_CASE, 0, 4, DROITE);
    ///FANTOME ENNEMI 1 PUIS 2
    //Personnage ennemi1(personnageImage, 5 * TAILLE_CASE, TAILLE_CASE, 6, 4, DROITE);
    Personnage ennemi2(personnageImage, TAILLE_CASE, 4 * TAILLE_CASE, 6, 4, DROITE);
    ///CHAUVE-SOURIS ENNEMI 1 PUIS 2
    //Personnage ennemi1(personnageImage, 4 * TAILLE_CASE, TAILLE_CASE, 3, 4, DROITE);
    //Personnage ennemi2(personnageImage, TAILLE_CASE, 4 * TAILLE_CASE, 3, 4, DROITE);

    bool quitter = false;
    bool perdu = false;
    bool gagne = false;

    while (!quitter)
    {

        // Initialiser l'écran avec un fond noir
        moteur.initialiserRendu();

        // Dessiner le fond sur la fenêtre
        fond.dessiner(0, 0);

        // Dessiner le niveau
        niveau.dessiner();

        // Dessiner le personnage principal
        personnage.dessiner();

        // Dessiner les ennemis
        ennemi1.dessiner();
        ennemi2.dessiner();

        // Finaliser le rendu pour afficher à l'écran
        moteur.finaliserRendu();

        // Si la partie est perdue ou gagnée, ajouter une pause avant de quitter
        if (perdu || gagne)
        {
            moteur.attendre(1.0); // Pause de 1 seconde

            if (perdu)
            {
                gameoverImage.dessiner(30, 40);
            }
            else
            {
                bravoImage.dessiner(30, 40);
            }
            moteur.finaliserRendu();
            moteur.attendre(2.0); // Pause de 2 secondes avant de quitter
            quitter = true;
            continue;
        }

        // Gestion des événements
        Evenement evenement = moteur.evenementRecu();
        while (evenement != AUCUN)
        {
            switch (evenement)
            {
            case QUITTER_APPUYE:
                quitter = true;
                break;
            case DROITE_APPUYE:
                personnage.allerDroite(niveau);
                niveau.testerBonusEtPrendre(personnage.getX(), personnage.getY());
                break;
            case BAS_APPUYE:
                personnage.allerBas(niveau);
                niveau.testerBonusEtPrendre(personnage.getX(), personnage.getY());
                break;
            case GAUCHE_APPUYE:
                personnage.allerGauche(niveau);
                niveau.testerBonusEtPrendre(personnage.getX(), personnage.getY());
                break;
            case HAUT_APPUYE:
                personnage.allerHaut(niveau);
                niveau.testerBonusEtPrendre(personnage.getX(), personnage.getY());
                break;
            default:
                break;
            }
            evenement = moteur.evenementRecu();
        }

        // Tester si le joueur a gagné
        if (niveau.gagne())
        {
            cout << "Felicitations ! Vous avez collecte tous les bonus !" << endl;
            gagne = true;
        }

        // Déplacement des ennemis et mise à jour des animations
        if (moteur.animationsAmettreAjour())
        {
            personnage.mettreAJourAnimation(); // Mettre à jour l'animation du personnage principal

            ennemi1.mettreAJourAnimation();    // Mettre à jour l'animation du premier ennemi
            ennemi2.mettreAJourAnimation();    // Mettre à jour l'animation du deuxième ennemi

            ennemi1.avancer(niveau);           // Déplacement du premier ennemi
            ennemi2.avancer(niveau);           // Déplacement du deuxième ennemi
        }

        // Vérifier si le personnage touche un ennemi
        if (personnage.touche(ennemi1) || personnage.touche(ennemi2))
        {
            cout << "Vous avez perdu !" << endl;
            perdu = true; // Marquer la partie comme perdue
        }
    }
    return 0;
}
