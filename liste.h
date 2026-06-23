#ifndef LISTE_H
#define LISTE_H


typedef struct ElementListe ElementListe;
struct ElementListe

{
    char *donnee;
    ElementListe *suivant;
};

typedef struct ListeRepere Liste;

struct ListeRepere
{
    ElementListe *debut;
    ElementListe *fin;
    int taille;
};

/*initialisation de la liste*/
void initialisation(Liste *liste);

/*Prototypes des fonction d'insertion*/

void ins_dans_liste_vide(Liste * liste, char *donnee);

void ins_debut_liste(Liste *liste,char *donnee);

void ins_fin_liste(Liste *liste,char *donnee);

void affiche(Liste *liste);

void etat_liste(Liste *liste);

int menu(Liste *liste);

#endif // LISTE_H

/*--------------fin de liste.h-------*/
