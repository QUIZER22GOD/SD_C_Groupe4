
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "head.h"

void supprimer()
{
    int numero_carte;
    printf("ENTRE LE NUMERO DE LA CARTE DE L'ETUDIANT A SUPPRIMER : ");
    scanf("%d", &numero_carte);
    for (ordinateur **i = ordi; i < ordi+300; i++)
    {
        if (*i != NULL && *((*i)->numero_carte) == numero_carte)
        {
            free(*i);
            *i = NULL;
            printf("SUPPRESSION EFFECTUEE\n");
            return;
        }
    }
    printf("NUMERO DE CARTE INEXISTANT\n\n");
    printf("APPuyez sur une touche pour continuer...");
    getch();
}