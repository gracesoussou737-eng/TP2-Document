/* test_liste.c - TP2 : question 3 et 4, tests des cas limites */
#include <stdio.h>
#include "liste.h"
int main(void) {
    Liste l;
    liste_init(&l);
    printf("1. Liste vide :\n");
    liste_afficher(&l);
    printf("Contient 10 ? %s\n", liste_contient(&l, 10) ? "oui" : "non");
    printf("Milieu liste vide : %d (on attend -1)\n", liste_milieu(&l));
    printf("Supprimer 99 dans vide : %s\n", liste_supprimer(&l, 99) ? "oui" : "non, pas trouve");
    liste_inverser(&l);
    printf("Inverser vide : pas de crash, OK\n\n");
    printf("2. Un seul element :\n");
    liste_inserer_tete(&l, 42);
    liste_afficher(&l);
    printf("Milieu : %d\n", liste_milieu(&l));
    liste_inverser(&l);
    liste_afficher(&l);
    printf("Supprimer l absent 99 : %s\n", liste_supprimer(&l, 99) ? "oui" : "non, pas trouve");
    liste_afficher(&l);
    printf("\n");
    printf("3. Cas normal :\n");
    liste_detruire(&l);
    liste_inserer_queue(&l, 1);
    liste_inserer_queue(&l, 2);
    liste_inserer_queue(&l, 3);
    liste_inserer_queue(&l, 4);
    liste_inserer_queue(&l, 5);
    liste_inserer_tete(&l, 0);
    liste_afficher(&l);
    printf("Taille : %d\n", l.taille);
    printf("Contient 3 ? %s\n", liste_contient(&l, 3) ? "oui" : "non");
    printf("Contient 99 ? %s\n", liste_contient(&l, 99) ? "oui" : "non");
    printf("Milieu : %d\n", liste_milieu(&l));
    printf("Supprimer 0 (tete) : %s\n", liste_supprimer(&l, 0) ? "OK" : "echec");
    liste_afficher(&l);
    printf("Supprimer 5 (queue) : %s\n", liste_supprimer(&l, 5) ? "OK" : "echec");
    liste_afficher(&l);
    printf("Supprimer 99 (absent) : %s\n", liste_supprimer(&l, 99) ? "OK" : "non, pas trouve, liste inchangee");
    liste_afficher(&l);
    printf("\n");
    printf("4. Inverser :\n");
    liste_inverser(&l);
    liste_afficher(&l);
    printf("Milieu apres inversion : %d\n", liste_milieu(&l));
    liste_detruire(&l);
    printf("\nApres detruire : ");
    liste_afficher(&l);
    printf("Taille : %d\n", l.taille);
    printf("\nTous les tests TP2 : OK\n");
    return 0;
}
