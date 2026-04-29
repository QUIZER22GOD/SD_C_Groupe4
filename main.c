#include <stdio.h>
#include <stdlib.h>
#include "head.h"



ordinateur *ordi[300] = {NULL};
int main()
{
    Bienvenue();
    while (1)
    {
        naviguer(menu());
    }
    return 0;
}
