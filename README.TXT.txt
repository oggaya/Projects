README.TXT  

ATTENTION : SI VOUS SOUHAITEZ JOUER AVEC LE PERSONNAGE FÉMININ, IL FAUT DÉCOMMENTER LA LIGNE 32 ET COMMENTER LA LIGNE 30.  
ÉGALEMENT : VOUS POUVEZ CHANGER LES ENNEMIS EN COMMENTANT ET DÉCOMMENTANT CEUX QUE VOUS SOUHAITEZ AFFRONTER.  

Compilation :  

Pour compiler le programme, utilisez un compilateur C++ (Code::Blocks, par exemple, ou VSCode). Lancez-le dans n'importe quel mode (Debug/Release) : cela fonctionnera.  

Description du projet :  

Ce projet est un programme en C++ qui utilise des modules prédéfinis (moteur et image) pour réaliser un traitement spécifique sur des images ou des données graphiques. Le code implémente des fonctionnalités basées sur ces modules en mettant en œuvre diverses méthodes et structures pour manipuler et traiter les données de manière efficace. Tout cela nous a permis de créer un mini jeu vidéo en 2D avec un niveau et la possibilité de gagner une partie en récoltant toutes les pièces d'or du niveau.  

Points d'intérêt :  

1 - Structure des fichiers .h :  

Niveau.h  
Ce fichier contient la déclaration de la classe Niveau, qui gère les objets du niveau, leur création à partir d'un fichier, et les opérations sur ces objets. La classe inclut des méthodes pour dessiner les objets, tester si une case est libre, tester et prendre des bonus, et vérifier si le joueur a gagné. Elle interagit avec la classe Objet pour manipuler les objets dans le niveau.  

Objet.h  
La classe Objet est définie dans ce fichier et représente un objet dans le jeu (comme un bonus, un bloc solide, etc.). Elle contient des méthodes pour récupérer les informations liées à l'objet (coordonnées, propriété), pour dessiner l'objet à l'écran, et pour le cacher (par exemple, lorsqu'un bonus est collecté). La classe utilise une image pour représenter visuellement l'objet et manipule des portions de cette image à l'aide de coordonnées skin_x et skin_y.  

Dictionnaire.h  
Ce fichier contient la déclaration de la classe Dictionnaire, qui permet de gérer un dictionnaire d'objets dans le jeu. La classe permet de charger les objets à partir d'un fichier, de les rechercher par nom, et de récupérer leurs propriétés associées. Elle utilise un vecteur de Tuile pour stocker les objets et leurs informations.  

Personnage.h  
La classe Personnage est définie ici et représente un personnage du jeu, qu'il soit joueur ou ennemi. Ce fichier contient les méthodes de déplacement du personnage (allerDroite, allerGauche, allerHaut, allerBas), ainsi que les méthodes pour mettre à jour sa direction et son animation. Il gère également la détection de collisions entre personnages et leurs interactions avec le niveau (par exemple, vérifier si le personnage touche un autre personnage ou un objet).  

FICHIERS DÉJÀ FOURNIS :  

Image.h  
Ce fichier contient la déclaration de la classe Image, qui est responsable de la gestion des images et de leur affichage à l'écran. La classe permet de charger une image, de sélectionner une portion de cette image à afficher (par exemple, pour un sprite), et de dessiner cette image à des coordonnées spécifiques sur l'écran. Elle est utilisée pour afficher les personnages et les objets dans le jeu.  

Moteur.h  
Le fichier Moteur.h contient la déclaration de la classe Moteur, qui est responsable de l'initialisation du moteur de rendu du jeu, de la gestion des événements (comme les pressions de touches), et de la boucle principale du jeu. Elle interagit avec les autres classes pour mettre à jour l'affichage et gérer les différentes étapes du jeu (animation, gestion des événements, etc.).  

2 - Gestion des erreurs :  
Des vérifications ont été ajoutées pour détecter les erreurs lors du chargement des données, l'ouverture des fichiers ou la manipulation des images, grâce aux : `throw`, `cerr` et à l'`include <stdexcept>`.  

Fonctionnalités clés réalisées :  

SÉANCES 2 ET 3 :  

- Questions 1 à 19 obligatoires ont été réalisées et sont toutes fonctionnelles.  
- Questions 20 et 21 optionnelles ont été réalisées.  
- La question 22 a été réalisée, mais à notre manière. Nous avons préféré ajouter aussi des éléments "non obligatoires" pour nos ennemis, avec un compteur pour que cela paraisse plus réaliste tout en gardant l'esprit IA.  

SÉANCES 4 ET 5 :  

- Questions 1 à 24 obligatoires ont été réalisées et sont toutes fonctionnelles.  
- La question 19 optionnelle a été réalisée avec succès.  
- La question 25 optionnelle a été réalisée avec succès.  

Améliorations possibles :  

- Ajouter des tests unitaires pour chaque fonction clé dans un fichier `mainTest.cpp`.  
- Améliorer l’interface utilisateur pour offrir une meilleure expérience : on pourrait créer un menu avec la sélection de niveau. Il suffirait de charger une image de fond et des images "Niveau 1" et "Niveau 2", par exemple, et d'écrire dans `Moteur.h` une ligne de code permettant de prendre en compte le clic gauche de la souris. Cela permettrait de charger le niveau 1 ou le niveau 2 selon la préférence du joueur. Il faudrait également créer `Niveau2.txt` et le personnaliser à notre façon.  
