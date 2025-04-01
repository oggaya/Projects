#include <vector>

#include "Moteur.h"
#include "Image.h"
#include "Personnage.h"
#include "Dictionnaire.h"
#include "Niveau.h"

using namespace std;

int main(int, char**) // Version special du main, ne pas modifier
{
  // Initialisation du jeu
  Moteur moteur("Mon super jeu vidéo");

  // TODO: charger images, creer personnages, etc.
  Image fond;
  try
  {
    fond = Image(moteur, "assets/fond.png");
  }
  catch (runtime_error& e)
  {
    cout << "Erreur : " << e.what() << std::endl;
  }

  Image image_personnage(moteur, "assets/personnages.png");
  Personnage personnage(image_personnage, 3, 0, TAILLE_CASE, 2*TAILLE_CASE);
  Personnage ennemi1(image_personnage, 9, 0, 5*TAILLE_CASE, TAILLE_CASE);
  Personnage ennemi2(image_personnage, 7, 4, TAILLE_CASE, 5*TAILLE_CASE, DROITE);

  Image bravo(moteur, "assets/bravo.png");
  Image gameover(moteur, "assets/gameover.png");

  Dictionnaire dictionnaire("assets/dictionnaire.txt");
  dictionnaire.afficher();

  Image image_niveau(moteur, "assets/objets.png");
  Niveau niveau(image_niveau, "assets/niveau1.txt", dictionnaire);

  bool quitter = false;
  bool perdu = false;
  bool gagne = false;

  // Boucle de jeu, appelee a chaque fois que l'ecran doit etre mis a jour
  // (en general, 60 fois par seconde)
  while (!quitter)
  {
    bool bouge = false;

    // I. Gestion des evenements
    Evenement evenement = moteur.evenementRecu();
    while (evenement != AUCUN)
    {
      switch (evenement)
      {
        // QUITTER = croix de la fenetre ou Echap
        case QUITTER_APPUYE:
          quitter = true;
          break;
        // TODO: gerer les autres evenements
        case DROITE_APPUYE:
          personnage.allerDroite(niveau);
          bouge = true;
          break;
        case GAUCHE_APPUYE:
          personnage.allerGauche(niveau);
          bouge = true;
          break;
        case HAUT_APPUYE:
          personnage.allerHaut(niveau);
          bouge = true;
          break;
        case BAS_APPUYE:
          personnage.allerBas(niveau);
          bouge = true;
          break;
        default:
          break;
      }

      evenement = moteur.evenementRecu();
    }

    // II. Mise à jour de l'état du jeu

    // TODO: faire bouger vos personnages, etc.
    if (moteur.animationsAmettreAjour())
    {
      ennemi1.avancer(niveau);
      ennemi2.avancer(niveau);
    }

    if (personnage.touche(ennemi1) || personnage.touche(ennemi2))
    {
      quitter = true;
      perdu = true;
    }

    if (bouge)
    {
      niveau.testerBonusEtPrendre(personnage.getX(), personnage.getY());
      if (niveau.gagne())
      {
        quitter = true;
        gagne = true;
      }
    }

    // III. Generation de l'image à afficher

    moteur.initialiserRendu(); // efface ce qui avait ete affiche precedemment et reinitalise en ecran noir

    // TODO: afficher vos personnages, objets, etc.
    fond.dessiner(0, 0);
    niveau.dessiner();
    personnage.dessiner();
    ennemi1.dessiner();
    ennemi2.dessiner();

    if (perdu)
      gameover.dessiner(LARGEUR_FENETRE / 2 - gameover.getLargeur() / 2,
                        HAUTEUR_FENETRE / 2 - gameover.getHauteur() / 2);
    else if (gagne)
      bravo.dessiner(LARGEUR_FENETRE / 2 - gameover.getLargeur() / 2,
                     HAUTEUR_FENETRE / 2 - gameover.getHauteur() / 2);


    /*
      Affiche l'image en se cadencant sur la frequence de
      rafraichissement de l'ecran (donc va en general mettre le
      programme en pause jusqu'a ce que l'ecran soit rafraichi). En
      general, 60 images fois par seconde, mais ca peut dependre du
      materiel
    */
    moteur.finaliserRendu();

  }

  if (perdu || gagne) // Si ni perdu ni gagne, jeu ferme par la croix, on n'attend pas
    moteur.attendre(2);

  return 0;
}
