
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "head.h"

void sortir()
{
    const char *options[] = {"OUI", "NON"};
    int choisi = 0;
    const int nbOptions = 2;
    int touche;

    system("cls");

    printf("Utilisez les fleches haut/bas, Entree pour valider.\n\n");

    while (1) {
        
        gotoxy(0, 2);

        
        for (int i = 0; i < nbOptions; i++) {
            
            printf("                                        \r"); 
            gotoxy(0, 2 + i); 
            if (i == choisi) {
                printf("> %s <", options[i]);
            } else {
                printf("  %s  ", options[i]);
            }
        }

        touche = getch();
        if (touche == 224) { 
            touche = getch();
            if (touche == 72 && choisi > 0) {        
                choisi--;
            } else if (touche == 80 && choisi < nbOptions - 1) { 
                choisi++;
            }
        } else if (touche == 13) { 
            break;
        }
    }

    if (choisi == 0) 
    {
        for (ordinateur **i = ordi; i < ordi + 300; i++)
        {
            free((*i)->disque_dur);
            free((*i)->ram);
            free((*i)->vitesse_cpu);
            free((*i)->prix_ordinateur);
            free((*i)->marque);
            free((*i)->specialite);
            free((*i)->numero_carte);
            free((*i)->marque);
            free(*i);
        }
        exit(0);
    }


}
