
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
