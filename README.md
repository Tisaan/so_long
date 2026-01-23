# so_long
>this project has been created as part of the 42 curriculum by <tseche>

**so_long** est un projet de l'école 42 qui consiste à créer un petit jeu 2D en utilisant la bibliothèque graphique **MLX42** (ou **minilibx** selon la version). Le but est de récupérer tous les collectibles sur une carte avant de sortir, en évitant les ennemis.

---

## Table des matières
- [so\_long](#so_long)
	- [Table des matières](#table-des-matières)
	- [Description](#description)
	- [Fonctionnalités](#fonctionnalités)
	- [Ressource](#ressource)
	- [Instuction](#instuction)
		- [Installation](#installation)

---

## Description
Ce projet permet de découvrir les bases de la gestion de fenêtres graphiques, des événements clavier et de la manipulation d'images en C. Le jeu se déroule sur une carte 2D où le joueur (représenté par un personnage) doit collecter tous les objets avant de pouvoir sortir.

---

## Fonctionnalités
- **Gestion des mouvements** : Déplacement du personnage avec les touches directionnelles (WASD ou flèches).
- **Collisions** : Détection des murs et des limites de la carte.
- **Collectibles** : Le joueur doit récupérer tous les collectibles pour débloquer la sortie.
- **Sortie** : La sortie n'est accessible que si tous les collectibles sont récupérés.
- **Ennemis** : (Optionnel) Déplacement aléatoire ou suivi du joueur.
- **Affichage du nombre de mouvements** : Compteur de pas affiché en temps réel.

---
## Ressource
- avoir un cerveau

## Instuction
### Installation
```bash
	make
```