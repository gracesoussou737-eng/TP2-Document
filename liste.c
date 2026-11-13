/* liste.c - TP2 : question 1, 2, 3 */
#include <stdio.h>
#include <stdlib.h>
#include "liste.h"
void liste_init(Liste *l) {
    l->tete = NULL;
    l->taille = 0;
}
void liste_inserer_tete(Liste *l, int val) {
    Noeud *nouveau = malloc(sizeof(Noeud));
    nouveau->valeur = val;
    nouveau->suivant = l->tete;
    l->tete = nouveau;
    l->taille++;
}
void liste_inserer_queue(Liste *l, int val) {
    Noeud *nouveau = malloc(sizeof(Noeud));
    nouveau->valeur = val;
    nouveau->suivant = NULL;
    if (l->tete == NULL) {
        l->tete = nouveau;
    } else {
        Noeud *cour = l->tete;
        while (cour->suivant != NULL) {
            cour = cour->suivant;
        }
        cour->suivant = nouveau;
    }
    l->taille++;
}
int liste_supprimer(Liste *l, int val) {
    if (l->tete == NULL) return 0;
    Noeud *cour = l->tete;
    Noeud *prec = NULL;
    while (cour != NULL && cour->valeur != val) {
        prec = cour;
        cour = cour->suivant;
    }
    if (cour == NULL) return 0;
    if (prec == NULL) {
        l->tete = cour->suivant;
    } else {
        prec->suivant = cour->suivant;
    }
    free(cour);
    l->taille--;
    return 1;
}
int liste_contient(Liste *l, int val) {
    Noeud *cour = l->tete;
    while (cour != NULL) {
        if (cour->valeur == val) return 1;
        cour = cour->suivant;
    }
    return 0;
}
void liste_afficher(Liste *l) {
    if (l->tete == NULL) {
        printf("Liste vide\n");
        return;
    }
    Noeud *cour = l->tete;
    while (cour != NULL) {
        printf("%d -> ", cour->valeur);
        cour = cour->suivant;
    }
    printf("NULL\n");
}
void liste_detruire(Liste *l) {
    Noeud *cour = l->tete;
    while (cour != NULL) {
        Noeud *tmp = cour;
        cour = cour->suivant;
        free(tmp);
    }
    l->tete = NULL;
    l->taille = 0;
}
void liste_inverser(Liste *l) {
    Noeud *prec = NULL;
    Noeud *cour = l->tete;
    while (cour != NULL) {
        Noeud *suiv = cour->suivant;
        cour->suivant = prec;
        prec = cour;
        cour = suiv;
    }
    l->tete = prec;
}
int liste_milieu(Liste *l) {
    if (l->tete == NULL) return -1;
    Noeud *lent = l->tete;
    Noeud *rapide = l->tete;
    while (rapide != NULL && rapide->suivant != NULL) {
        lent = lent->suivant;
        rapide = rapide->suivant->suivant;
    }
    return lent->valeur;
}
