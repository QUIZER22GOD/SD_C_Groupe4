#include<stdio.h>
#include<string.h>
#include <conio.h>
#include <windows.h>




int menu() {

    const char *options[] = {"AFFICHER TOUS LES ORDINATEURS", "SAISIR", "MODIFIER", "SUPPRIMER", "RECHERCHE", "TRIER", "EXIT"};
    int choisi = 0;
    const int nbOptions = 7;
    int touche;

    system("cls");

    printf("Utilisez les fleches haut/bas, Entree pour valider.\n\n");

    // Boucle principale de navigation
    while (1) {
        // On positionne le curseur juste apres la banniere (ligne 2, colonne 0)
        gotoxy(0, 2);

        // Affichage des options : on efface chaque ancienne ligne puis on reecrit
        for (int i = 0; i < nbOptions; i++) {
            // On efface la ligne actuelle en ecrivant des espaces
            printf("                                        \r"); // retour chariot
            gotoxy(0, 2 + i); // positionne au debut de la ligne de l'option i
            if (i == choisi) {
                printf("> %s <", options[i]);
            } else {
                printf("  %s  ", options[i]);
            }
        }

        // On cache le curseur clignotant pendant la saisie (optionnel)
        // On attend une touche
        touche = getch();
        if (touche == 224) { // fleche directionnelle
            touche = getch();
            if (touche == 72 && choisi > 0) {        // fleche haut
                choisi--;
            } else if (touche == 80 && choisi < nbOptions - 1) { // fleche bas
                choisi++;
            }
        } else if (touche == 13) { // Entree
            break;
        }
    }

    system("cls");

    return choisi ;

}
