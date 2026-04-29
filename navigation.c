
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "head.h"

ordinateur* rechercher(int numero_carte)
{
    for (ordinateur **i = ordi; i < ordi + 300; i++)
    {
        if (*i != NULL && *((*i)->numero_carte) == numero_carte)
        {
            return *i;  
        }
    }
    printf("Ordinateur non trouve.\n");
    return NULL;
}






void naviguer(int choix)
{
    if (choix == 0)
    {
        for (ordinateur **i = ordi; i < ordi + 300; i++)
        {
            if (*i != NULL)
                afficher(**i);
        }
        
        
    }
    else if (choix == 1)
    {
        ajouter();
    }
    else if (choix == 2)
    {
        modifier();
    }
    else if (choix == 3)
    {
        supprimer();
    }
    else if (choix == 4)
    {
        printf("Rechercher un ordinateur par le numero de carte du detenteur : \n");
        int numero_carte;
        scanf("%d", &numero_carte);
        ordinateur* p = rechercher(numero_carte);
        if (p == NULL)
            printf("Ordinateur non trouve.\n");
        else
            afficher(*p);
        

        
    }
    else if (choix == 5)
    {
        trier();
    }

    else if (choix == 6)
    {
        sortir();
    }
}
