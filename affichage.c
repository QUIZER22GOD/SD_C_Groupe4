#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "head.h"



void afficher(ordinateur ordi)
{
    
        if (ordi.numero_carte != 0)
        {
            printf("----------------------------------------------------------\n");
            printf("| NUMERO CARTE ETUDIANT :           %d          |\n", ordi.numero_carte);
            printf("| RAM(Go) :                         %d            |\n", ordi.ram);
            printf("| TAILLE DU DISQUE DUR (Go) :       %d        |\n", ordi.disque_dur);
            printf("| PRIX DE L'ORDINATEUR (FCFA) :     %d        |\n", ordi.prix_ordinateur);
            printf("| VITESSE DU CPU (GHz) :            %f          |\n", ordi.vitesse_cpu);
            printf("| SPECIALITE DE L'ETUDIANT :        %s |\n", ordi.specialite);
            printf("| MARQUE DE L'ORDINATEUR     :      %s     |\n", ordi.marque);
            printf("-----------------------------------------------------------\n");
        }
  
        printf("AUCUN ORDINATEUR TROUVER.\n");
        printf("Appuyez sur une touche pour continuer...\n");
        getch();
        return;
}

