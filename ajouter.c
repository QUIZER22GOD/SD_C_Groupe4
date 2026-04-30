#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "head.h"



void ajouter()
{
    int place_disponible = 0;
    int nbr_rempli = 0;
    
    for (ordinateur **i = ordi; i < ordi+300; i++)
    {
        if (*i == NULL)
        {
            place_disponible++;

        }
            
    } 
    if (place_disponible == 0)
    {
        printf("La liste est pleine\n");
        return;
    }
    
    printf("ENTREZ LE NOMBRE D'ORDINATEUR\n");
    int n;
    while (1)
    {
        scanf("%d", &n);
        if (n > 0 && n <= place_disponible)
        {
            break;
        }
        else
        {
            printf("ENTREZ UN NOMBRE POSITIF ET INFERIEUR A %d\n", place_disponible);
        }
    }
    
    for (ordinateur **i = ordi; i < ordi+300; i++)
    {
        if (*i == NULL)
        {
            *i = (ordinateur *)malloc(sizeof(ordinateur));
            if (*i == NULL)
            {
                printf("Erreur de malloc\n");
                exit(1);
            }
                
                (*i)->ram = (int *)malloc(sizeof(int));
                if ((*i)->ram == NULL)
                {
                    printf("Erreur de malloc\n");
                    exit(1);
                }
                
                (*i)->disque_dur = (int *)malloc(sizeof(int));
                if ((*i)->disque_dur == NULL)
                {
                    printf("Erreur de malloc\n");
                    exit(1);
                }
                
                (*i)->prix_ordinateur = (int *)malloc(sizeof(int));
                if ((*i)->prix_ordinateur == NULL)
                {
                    printf("Erreur de malloc\n");
                    exit(1);
                }
            
                (*i)->numero_carte = (int *)malloc(sizeof(int));
                if ((*i)->numero_carte == NULL)
                {
                    printf("Erreur de malloc\n");
                    exit(1);
                }
            
                (*i)->vitesse_cpu = (float *)malloc(sizeof(float));
                if ((*i)->vitesse_cpu == NULL)
                {
                    printf("Erreur de malloc\n");
                    exit(1);
                }

                printf("-----------------------------------------------------\n");
                printf("| entrez le numero de la carte         |");
                gotoxy(40, 1); scanf("%d", (*i)->numero_carte);
            
                printf("| entrez la capacite de la ram         |");
                gotoxy(40, 2); scanf("%d", (*i)->ram);
            
                printf("| entrez la taille du disque dur       |");
                gotoxy(40, 3); scanf("%d", (*i)->disque_dur);
            
                printf("| entrez le prix de l'ordinateur       |");
                gotoxy(40, 4); scanf("%d", (*i)->prix_ordinateur);
            
                printf("| entrez la vitesse du cpu             |");
                gotoxy(40, 5); scanf("%f", (*i)->vitesse_cpu);
            
                printf("| entrez la specialite de l'etudiant   |");
                gotoxy(40, 6); scanf("%s", (*i)->specialite);
            
                printf("| entrez la marque de l'ordinateur     |");
                gotoxy(40, 7);  scanf("%s", (*i)->marque);
            
                printf("-----------------------------------------------------\n\n");

                nbr_rempli++;
                Sleep(2000);
                
            }
            if (nbr_rempli == n)
                break;
    
            
    }
    printf("%d ordinateur(s) ajouté(s)\n", nbr_rempli);
    
}
    
    

    
