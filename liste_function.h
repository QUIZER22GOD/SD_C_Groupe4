#ifndef LISTE_FONCTION_H
#define LISTE_FONCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "liste.h"

/*-----------liste_function.h-------*/
void initialisation(Liste *liste)
{
    liste->debut = NULL;
    liste->fin = NULL;
    liste->taille = 0;
}

/*insertion dans une liste vide*/

void ins_dans_liste_vide(Liste * liste, char *donnee)
{
    /*1. Créer un nouvel élément (malloc)
    2. Vérifier si malloc a réussi → sinon retourner -1
    3. Allouer de la mémoire pour la donnée (malloc)
    4. Vérifier si malloc a réussi → sinon retourner -1
    5. Copier la donnee dans le nouvel élément (strcpy)
    6. Le suivant du nouvel élément = NULL
    7. debut et fin pointent vers ce nouvel élément
    8. taille++
    9. retourner 0*/
    ElementListe *nouveau_element;
    nouveau_element=(ElementListe*)malloc(sizeof(ElementListe));

    if(nouveau_element==NULL)
    {
        printf("Erreur d'allocation memoire\n");
        return;
    }
    nouveau_element->donnee=(char*)malloc(50*sizeof(char));
    if(nouveau_element->donnee==NULL)
    {
        printf("Erreur d'allocation memoire\n");
        return;
    }
    strcpy(nouveau_element->donnee, donnee);
    nouveau_element->suivant = NULL;
    liste->debut = nouveau_element;
    liste->fin = nouveau_element;
    liste->taille++;

}

void ins_debut_liste(Liste *liste,char *donnee)
{
    /*1. Créer un nouvel élément (malloc)
    2. Vérifier si malloc a réussi → sinon afficher erreur et return
    3. Allouer mémoire pour la donnée (malloc)
    4. Vérifier si malloc a réussi → sinon afficher erreur et return
    5. Copier la donnee dans le nouvel élément (strcpy)
    6. Le suivant du nouvel élément = debut (l'ancien premier)
    7. debut pointe vers le nouvel élément
    8. taille++*/
    ElementListe *nouveau_element;
    nouveau_element=(ElementListe*)malloc(sizeof(ElementListe));
    if(nouveau_element==NULL)
    {
        printf("Erreur d'allocation memoire\n");
        return;
    }
    nouveau_element->donnee=(char*)malloc(50*sizeof(char));
    if(nouveau_element->donnee==NULL)
    {
        printf("Erreur d'allocation memoire\n");
        return;
    }
    strcpy(nouveau_element->donnee, donnee);
    nouveau_element->suivant = liste->debut;
    liste->debut = nouveau_element;
    liste->taille++;

}

void ins_fin_liste(Liste *liste,char *donnee)
{
    /*1. Créer un nouvel élément (malloc)
    2. Vérifier si malloc a réussi → sinon afficher erreur et return
    3. Allouer mémoire pour la donnée (malloc)
    4. Vérifier si malloc a réussi → sinon afficher erreur et return
    5. Copier la donnee dans le nouvel élément (strcpy)
    6. Le suivant du nouvel élément = NULL
    7. Le suivant de l'ancien fin = nouveau_element
    8. fin pointe vers le nouvel élément
    9. taille++*/
    ElementListe *nouveau_element;

    nouveau_element=(ElementListe*)malloc(sizeof(ElementListe));
    if(nouveau_element==NULL)
    {
        printf("Erreur d'allocation memoire\n");
        return;
    }
    nouveau_element->donnee=(char*)malloc(50*sizeof(char));
    if(nouveau_element->donnee==NULL)
    {
        printf("Erreur d'allocation memoire\n");
        return;
    }
    strcpy(nouveau_element->donnee, donnee);
    nouveau_element->suivant = NULL;
    liste->fin->suivant = nouveau_element;
    liste->fin = nouveau_element;
    liste->taille++;

}

/*Affichage*/
void affiche(Liste *liste)
{
    ElementListe *courant;
    courant = liste->debut;

    while (courant != NULL)
    {
        printf("donnee : %s\n", courant->donnee);
        printf("adresse suivant : %p\n", courant->suivant);
        courant = courant->suivant;
    }
}

void etat_liste(Liste *liste)
{
    printf("\n--- Etat de la liste ---\n");
    printf("Taille : %d\n", liste->taille);
    if (liste->taille == 0)
    {
        printf("Liste vide\n");
    }
    else
    {
        printf("Element au debut : %s\n", liste->debut->donnee);
        printf("Element a la fin : %s\n", liste->fin->donnee);
    }
    printf("------------------------\n");
}

int menu(Liste *liste)
{
    int choix;
    char donnee[50];
    do
    {

        printf("\n");
        if (liste->taille == 0)
            printf("1 - Inserer dans liste vide\n");
        else
        {
            printf("2 - Inserer au debut\n");
            printf("3 - Inserer a la fin\n");
        }
        printf("4 - Afficher la liste\n");
        printf("0 - Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        switch (choix)

        {
        case 1 :
            printf("Donnee : ");
            scanf("%s", donnee);
            ins_dans_liste_vide(liste, donnee);
            break;
        case 2 :
            printf("Donnee : ");
            scanf("%s", donnee);
            ins_debut_liste(liste, donnee);
            break;
        case 3 :
            printf("Donnee : ");
            scanf("%s", donnee);
            ins_fin_liste(liste, donnee);
            break;
        case 4 :
            affiche(liste);
            break;
        case 0 :
            printf("Au revoir\n");
            break;
        default :
            printf("Choix invalide\n");
        }
        if (choix != 0)
            etat_liste(liste);
    }
    while (choix != 0);
    return 0;
}

#endif
