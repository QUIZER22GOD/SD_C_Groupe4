#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "head.h"

void modifier()
{
    int numero_carte;
    printf("Donner le numero de carte : ");
    scanf("%d", &numero_carte);
    ordinateur *trouver = rechercher(numero_carte);
    if (trouver != NULL)
    {
        if (trouver->numero_carte != 0)
        {
            printf("----------------------------------------\n");
            printf("| Ordinateur trouve : \n");
            printf("| Numero de carte :       %d\n", trouver->numero_carte);
            printf("| Marque :                %s\n", trouver->marque);
            printf("| RAM :                   %d\n", trouver->ram);
            printf("| Disque dur :            %d\n", trouver->disque_dur);
            printf("| Prix :                  %d\n", trouver->prix_ordinateur);
            printf("| Specialite :            %s\n", trouver->specialite);
            printf("| Vitesse CPU :           %.2f\n", trouver->vitesse_cpu);
            printf("----------------------------------------\n");

        }
    
       
    }
    else
    {
        printf("Ordinateur non trouve.\n");
        system("cls");
    }

     printf("QUEL INFORMATION VOULEZ VOUS MODIFIER ?");
        
        const char *options[] = {"NUMERO DE CARTE", "MARQUE","RAM","DISQUE DUR","PRIX","SPECIALITÉ","VITESSE DU CPU","TOUS LES INFORMATION"};
        int choisi = 0;
        const int nbOptions = 8;
        int touche;


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

        if (choisi == 0) {
            exit(0);
        }

        
        system("cls");

        if (choisi == 0)
        {
            printf("-----------------------------------------------------\n");
            printf("| entre le nouveau numero de la carte |");
            gotoxy(40, 1); scanf("%d", (*ordi)->numero_carte);
            printf("-----------------------------------------------------\n");
        }
        if (choisi == 1)
        {
            printf("-----------------------------------------------------\n");
            printf("| entre la nouvelle marque de l'ordinateur |");
            gotoxy(45, 1); scanf("%d", (*ordi)->marque);
            printf("-----------------------------------------------------\n");
        }
        if (choisi == 2)
        {
            printf("-----------------------------------------------------\n");
            printf("| entre la nouvelle capacité de la RAM |");
            gotoxy(40, 1); scanf("%d", (*ordi)->ram);
            printf("-----------------------------------------------------\n");
        }
        if (choisi == 3)
        {
            printf("-----------------------------------------------------\n");
            printf("| entre la nouvelle taille du disque dur |");
            gotoxy(43, 1); scanf("%d", (*ordi)->disque_dur);
            printf("-----------------------------------------------------\n");
        }
        if (choisi == 4)
        {
            printf("-----------------------------------------------------\n");
            printf("| entre le nouveau prix de l'ordinateur |");
            gotoxy(42, 1); scanf("%d", (*ordi)->prix_ordinateur);
            printf("-----------------------------------------------------\n");
        }
        if (choisi == 5)
        {
            printf("-----------------------------------------------------\n");
            printf("| entre la nouvelle specialité |");
            gotoxy(34, 1); scanf("%d", (*ordi)->specialite);
            printf("-----------------------------------------------------\n");
        }
        if (choisi == 6)
        {
            printf("-----------------------------------------------------\n");
            printf("| entre le nouvelle vitesse du cpu |");
            gotoxy(37, 1); scanf("%d", (*ordi)->vitesse_cpu);
            printf("-----------------------------------------------------\n");
        }
        if (choisi == 7)
        {
            printf("-----------------------------------------------------\n");
            printf("| entre le nouveau numero de la carte |");
            gotoxy(40, 1); scanf("%d", (*ordi)->numero_carte);
            printf("-----------------------------------------------------\n");
        }
        
        if (choisi == 8)
        {
            printf("-----------------------------------------------------\n");
            printf("| entre le numero de la carte         |");
            gotoxy(40, 1); scanf("%d", (*ordi)->numero_carte);
            
            printf("| entre la capacite de la ram         |");
            gotoxy(40, 2); scanf("%d", (*ordi)->ram);
        
            printf("| entre la taille du disque dur       |");
            gotoxy(40, 3); scanf("%d", (*ordi)->disque_dur);
            
            printf("| entre le prix de l'ordinateur       |");
            gotoxy(40, 4); scanf("%d", (*ordi)->prix_ordinateur);
            
        
            printf("| entre la vitesse du cpu             |");
            gotoxy(40, 5); scanf("%f", (*ordi)->vitesse_cpu);
            
            printf("| entre la specialite de l'etudiant   |");
            gotoxy(40, 6); scanf("%s", (*ordi)->specialite);
            
            printf("| entre la marque de l'ordinateur     |");
            gotoxy(40, 7);  scanf("%s", (*ordi)->marque);
            printf("-----------------------------------------------------\n");
        }


    




}
