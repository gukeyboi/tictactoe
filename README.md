Projet TicTacToe IMAC - Laïn KOWALIK

----------
Indications :
- Système d'exploitation : projet testé sur MacOS
- Compilateur : Clang 16.0.0
- Aucune librairie externe n'a été ajoutée
----------

Organisation : 

- Player.cpp / Player.hpp : contient la fonction int main qui gère le lancement du jeu / le choix du mode etc... Contient également la structure Player utilisée dans toutes les fonctions relatives au jeu telles que la création et le nommage des joueurs, l'initialisation de l'IA, la gestion des tours, et la gestion des modes de jeu.

- GameBoard.cpp / GameBoard.hpp : contient toutes les fonctions relatives à la board de jeu : la création, le refresh, la vérification des cases et la vérification des conditions de victoire.

----------

Amélioration :

- IA avancée : dans le mode vsIA, elle bloquera les coups du joueur dans le cas où il est sur le point de gagner grâce à la fonction findBlockMove qui compare toutes les combinaisons possibles pour gagner.

----------

Bilan :

Difficulté principale : l'amélioration de l'IA, elle a nécessité de modifier la fonction iaTurn et d'en implémenter d'autres pour bloquer les coups du joueur.