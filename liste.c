#include <stdio.h>
#include <stdlib.h>
#include "liste.h"
#include "liste_function.h"

int main()
{
    Liste liste;
    initialisation(&liste);
    etat_liste(&liste);
    menu(&liste);
    return 0;
}
