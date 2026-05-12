
/*
Nom du programme : Deliberation_UE

GROUPE 4

Auteurs:

AKAKPO-NUMADO manuely IA&BD
NAM Moussah Yedouboime  GC
NIKABOU Kondi Chérif   GC
SEDALO Kokou Egnon Nathalien  GC
ABALO Kokou Mawussé Godfroy GC
ADEGUE Komi Emile GM
SAPKANI Paguiyedou IA&BD
LAMANALA Di-bahome Timothée GM
KADJOU Sokoum Paul  GC

Date : 21 Avril 2026

Description : Adds core structure for student computer management app

Introduces initial implementation of a console-based application to manage student computers, including modular source files for adding, displaying, modifying, deleting, searching, sorting, and navigating computer records.
*/


#include <stdio.h>
#include <stdlib.h>
#include "head.h"





int main()
{
    Bienvenue();
    while (1)
    {
        naviguer(menu());
    }
    return 0;
}
