# TP2 - Construire sa liste chainee
L2 IIRT - ESGIS - Semestre 3
## Fichiers
- liste.c / liste.h : question 1 - init, insertion tete, insertion queue, suppression, contient, afficher, detruire
- test_liste.c : question 3 - tests avec assert courant : liste vide, un seul element, suppression d un absent
- liste_inverser + liste_milieu : question 2, vues en TD 2
- rapport_valgrind.txt : question 4 - 0 fuite
## Compiler
gcc -std=c17 -Wall -Wextra -g liste.c test_liste.c -o test_liste
./test_liste
## Valgrind
valgrind --leak-check=full ./test_liste
