#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include "head.h"

// ======================== Variables globales ========================
ordinateur *ordi[300];   // tableau de pointeurs 

// ======================== Fonctions utilitaires ========================

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int outils_navigation(int nbOptions, char *options[])
{
    int choisi = 0;
    int touche;

    system("cls");
    printf("Utilisez les fleches haut/bas, Entree pour valider.\n\n");

    while (1) {
        gotoxy(0, 2);
        for (int i = 0; i < nbOptions; i++) {
            printf("                                        \r");
            gotoxy(0, 2 + i);
            if (i == choisi)
                printf("> %s <", options[i]);
            else
                printf("  %s  ", options[i]);
        }

        touche = getch();
        if (touche == 224) {
            touche = getch();
            if (touche == 72 && choisi > 0) choisi--;
            else if (touche == 80 && choisi < nbOptions - 1) choisi++;
        } else if (touche == 13) break;
    }

    system("cls");
    return choisi;
}

// ======================== Fonctions d'affichage ========================

void Bienvenue()
{
    printf("\n****************************************************************************************************************************************************");
    printf("\n **************      ****    ***********   ***            *   *                        *   **********     ***            *   *            *  ******* ");
    printf("\n *             *      **     *             * **           *    *                      *    *              * **           *   *            *  *            ");
    printf("\n *              *     **     *             *  **          *     *                    *     *              *  **          *   *            *  *            ");
    printf("\n *               *    **     *             *   **         *      *                  *      *              *   **         *   *            *  *            ");
    printf("\n *              *     **     *             *    **        *       *                *       *              *    **        *   *            *  *            ");
    printf("\n *             *      **     *             *     **       *        *              *        *              *     **       *   *            *  *            ");
    printf("\n **************       **     **********    *      **      *         *            *         **********     *      **      *   *            *  *******     ");
    printf("\n *             *      **     *             *       **     *          *          *          *              *       **     *   *            *  *            ");
    printf("\n *              *     **     *             *        **    *           *        *           *              *        **    *   *            *  *            ");
    printf("\n *               *    **     *             *         **   *            *      *            *              *         **   *   *            *  *            ");
    printf("\n *              *     **     *             *          **  *             *    *             *              *          **  *    *          *   *            ");
    printf("\n *             *      **     *             *           ** *              *  *              *              *           ** *     *        *    *            ");
    printf("\n **************      ****    ***********   *            ***               **               ***********    *            ***      ********     ******* ");
    printf("\n****************************************************************************************************************************************************");
    printf("\nAppuyez sur une touche pour continuer...");
    getch();
}

void afficher(ordinateur ordi)
{
    if (ordi.numero_carte != 0) {
        printf("----------------------------------------------------------\n");
        printf("| NUMERO CARTE ETUDIANT :           %d          \n", ordi.numero_carte);
        printf("| RAM(Go) :                         %d            \n", ordi.ram);
        printf("| TAILLE DU DISQUE DUR (Go) :       %d        \n", ordi.disque_dur);
        printf("| PRIX DE L'ORDINATEUR (FCFA) :     %d        \n", ordi.prix_ordinateur);
        printf("| VITESSE DU CPU (GHz) :            %.2f          \n", ordi.vitesse_cpu);
        printf("| SPECIALITE DE L'ETUDIANT :        %s    \n", ordi.specialite);
        printf("| MARQUE DE L'ORDINATEUR     :      %s     \n", ordi.marque);
        printf("-----------------------------------------------------------\n");
    }
    
}

// ======================== Gestion des ordinateurs ========================

void ajouter()
{
    int place_disponible = 0;
    int nbr_rempli = 0;

    for (ordinateur **i = ordi; i < ordi + 300; i++)
        if (*i == NULL) place_disponible++;

    if (place_disponible == 0) {
        printf("La liste est pleine\n");
        return;
    }

    printf("ENTREZ LE NOMBRE D'ORDINATEUR\n");
    int n;
    while (1) {
        scanf("%d", &n);
        if (n > 0 && n <= place_disponible) {
            system("cls");
            break;
        } else {
            printf("ENTREZ UN NOMBRE POSITIF ET INFERIEUR A %d\n", place_disponible);
        }
    }

    for (ordinateur **i = ordi; i < ordi + 300; i++) {
        if (*i == NULL) {
            *i = (ordinateur *)malloc(sizeof(ordinateur));
            if (*i == NULL) {
                printf("Erreur de malloc\n");
                exit(1);
            }

            printf("-------------------ORDINATEUR %d-----------------\n", nbr_rempli + 1);
            printf("| entrez le numero de la carte         |");
            gotoxy(40, 1); scanf("%d", &(*i)->numero_carte);
            printf("| entrez la capacite de la ram         |");
            gotoxy(40, 2); scanf("%d", &(*i)->ram);
            printf("| entrez la taille du disque dur       |");
            gotoxy(40, 3); scanf("%d", &(*i)->disque_dur);
            printf("| entrez le prix de l'ordinateur       |");
            gotoxy(40, 4); scanf("%d", &(*i)->prix_ordinateur);
            printf("| entrez la vitesse du cpu             |");
            gotoxy(40, 5); scanf("%f", &(*i)->vitesse_cpu);
            printf("| entrez la specialite de l'etudiant   |");
            gotoxy(40, 6); scanf("%s", (*i)->specialite);
            printf("| entrez la marque de l'ordinateur     |");
            gotoxy(40, 7); scanf("%s", (*i)->marque);
            printf("-----------------------------------------------------\n\n");

            nbr_rempli++;
            Sleep(2000);
            system("cls");
        }
        if (nbr_rempli == n) break;
    }
    printf("%d ordinateur(s) ajoute(s)\n", nbr_rempli);
}

void rechercher()
{
    char *options[] = {"NUMERO DE CARTE", "MARQUE", "RAM", "DISQUE DUR", "PRIX", "SPECIALITE", "VITESSE DU CPU"};
    int n_options = 7;

    printf("CHOISISSEZ LE CRITERE DE RECHERCHE :\n");
    printf("Appuyez sur une touche pour continuer...\n");
    getch();
    int choisi = outils_navigation(n_options, options);

   if (choisi == 0)
    {
        int num;
        printf("ENTREZ LE NUMERO DE CARTE A RECHERCHER : ");
        scanf("%d", &num);
        int trouve = 0;
        for (ordinateur **i = ordi; i < ordi + 300; i++)
        {
            if (*i != NULL && (*i)->numero_carte == num)
            {
                afficher(**i);
                trouve =1;
            
            }
        }
        if (!trouve) printf("Numero de carte inexistant.\n");
    }

    else if (choisi == 1)
    {
        char marque[20];
        printf("ENTREZ LA MARQUE : ");
        scanf("%s", marque);
        int trouve = 0;
        for (ordinateur **i = ordi; i < ordi + 300; i++)
        {
            if (*i != NULL && strcmp((*i)->marque, marque) == 0)
            {
                afficher(**i);
                trouve = 1;
            }
        }
        if (!trouve) printf("Aucun ordinateur avec cette marque.\n");
    }

        else if (choisi == 2)
    {
        int ram;
        printf("ENTREZ LA CAPACITE DE LA RAM A RECHERCHER : ");
        scanf("%d", &ram);
        int trouve = 0;
        for (ordinateur **i = ordi; i < ordi + 300; i++)
        {
            if (*i != NULL && (*i)->ram == ram)
            {
               afficher(**i); 
               trouve =1;
            }
                
            
        }
        if (!trouve) printf("Aucun ordinateur avec cette marque.\n");
    }


    else if (choisi == 3)
    { 
        int disque_dur;
        printf("ENTREZ LA TAILLE DU DISQUE DUR A RECHERCHER : ");
        scanf("%d", &disque_dur);
        int trouve;
        for (ordinateur **i = ordi; i < ordi + 300; i++)
        {
            if (*i != NULL && (*i)->disque_dur == disque_dur)
            {
               afficher(**i);
               trouve = 1;
 
            }
        }
        if (!trouve) printf("Aucun ordinateur avec cette marque.\n");
    }
    
    else if (choisi == 4)
    {
        int prix_ordinateur;
        printf("ENTREZ LE PRIX DE L'ORDINATEUR A RECHERCHER : ");
        scanf("%d", &prix_ordinateur);
        int trouve = 0;
        for (ordinateur **i = ordi; i < ordi + 300; i++)
        {
            if (*i != NULL && (*i)->prix_ordinateur == prix_ordinateur)
            {
                afficher(**i);
                trouve = 1;
            }
                
        }
        if (!trouve) printf("Aucun ordinateur avec cette marque.\n");
    }

    else if (choisi == 5)
    {
        char specialite[20];
        printf("ENTREZ LA SPECIALITE DE L'ETUDIANT A RECHERCHER : ");
        scanf("%s", specialite);
        int trouve = 0;
        for (ordinateur **i = ordi; i < ordi + 300; i++)
        {
            if (*i != NULL && strcmp((*i)->specialite, specialite) == 0)
            {
                afficher(**i);
                trouve = 1;
            }
                
        }
        if (!trouve) printf("Aucun ordinateur avec cette marque.\n");
    }
    
    else if (choisi == 6)
    {
        float vitesse_cpu;
        printf("ENTREZ LA VITESSE DU CPU A RECHERCHER : ");
        scanf("%f", &vitesse_cpu);
        int trouve = 0;
        for (ordinateur **i = ordi; i < ordi + 300; i++)
        {
            if (*i != NULL && (*i)->vitesse_cpu == vitesse_cpu)
            {
                afficher(**i);
                trouve = 1 ;
            }
                

        }
        if (!trouve) printf("Aucun ordinateur avec cette marque.\n");
    }

    return ;
}

void modifier()
{
    int num;
    printf("Numero de carte a modifier : ");
    scanf("%d", &num);
    ordinateur *trouver = NULL;
    for (int i = 0; i < 300; i++)
    {
        if (ordi[i] != NULL && ordi[i]->numero_carte == num)
        {
            trouver = ordi[i];
            break;
        }
    }
    if (trouver == NULL) {
        printf("Ordinateur non trouve.\n");
        printf("Appuyez sur une touche pour continuer...");
        getch();
        system("cls");
        return;
    }

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
    printf("Appuyez sur une touche pour continuer...");
    getch();

    printf("QUEL INFORMATION VOULEZ VOUS MODIFIER ?\n");
    char *options[] = {"NUMERO DE CARTE", "MARQUE", "RAM", "DISQUE DUR", "PRIX", "SPECIALITE", "VITESSE DU CPU", "TOUS LES INFORMATION"};
    int nbOptions = 8;
    int choisi = outils_navigation(nbOptions, options);

    switch (choisi) {
        case 0:
            printf("-----------------------------------------------------\n");
            printf("| entrez le nouveau numero de la carte |");
            gotoxy(40, 1); scanf("%d", &trouver->numero_carte);
            break;
        case 1:
            printf("-----------------------------------------------------\n");
            printf("| entrez la nouvelle marque de l'ordinateur |");
            gotoxy(45, 1); scanf("%s", trouver->marque);
            break;
        case 2:
            printf("-----------------------------------------------------\n");
            printf("| entrez la nouvelle capacite de la RAM |");
            gotoxy(40, 1); scanf("%d", &trouver->ram);
            break;
        case 3:
            printf("-----------------------------------------------------\n");
            printf("| entrez la nouvelle taille du disque dur |");
            gotoxy(43, 1); scanf("%d", &trouver->disque_dur);
            break;
        case 4:
            printf("-----------------------------------------------------\n");
            printf("| entrez le nouveau prix de l'ordinateur |");
            gotoxy(42, 1); scanf("%d", &trouver->prix_ordinateur);
            break;
        case 5:
            printf("-----------------------------------------------------\n");
            printf("| entrez la nouvelle specialite |");
            gotoxy(34, 1); scanf("%s", trouver->specialite);
            break;
        case 6:
            printf("-----------------------------------------------------\n");
            printf("| entrez la nouvelle vitesse du cpu |");
            gotoxy(37, 1); scanf("%f", &trouver->vitesse_cpu);
            break;
        case 7:
            printf("-----------------------------------------------------\n");
            printf("| entrez le nouveau numero de la carte |");
            gotoxy(40, 1); scanf("%d", &trouver->numero_carte);
            printf("| entrez la nouvelle marque |");
            gotoxy(40, 2); scanf("%s", trouver->marque);
            printf("| entrez la nouvelle RAM |");
            gotoxy(40, 3); scanf("%d", &trouver->ram);
            printf("| entrez le nouveau disque dur |");
            gotoxy(40, 4); scanf("%d", &trouver->disque_dur);
            printf("| entrez le nouveau prix |");
            gotoxy(40, 5); scanf("%d", &trouver->prix_ordinateur);
            printf("| entrez la nouvelle vitesse CPU |");
            gotoxy(40, 6); scanf("%f", &trouver->vitesse_cpu);
            printf("| entrez la nouvelle specialite |");
            gotoxy(40, 7); scanf("%s", trouver->specialite);
            break;
        default:
            break;
    }
    printf("-----------------------------------------------------\n");
    printf("Modification effectuee.\n");
    printf("Appuyez sur une touche pour continuer...");
    getch();
}

void supprimer()
{
    int numero_carte;
    printf("ENTRE LE NUMERO DE LA CARTE DE L'ETUDIANT A SUPPRIMER : ");
    scanf("%d", &numero_carte);

    int indice = -1;
    for (int k = 0; k < 300; k++) {
        if (ordi[k] != NULL && ordi[k]->numero_carte == numero_carte) {
            indice = k;
            break;
        }
    }

    if (indice == -1) {
        printf("NUMERO DE CARTE INEXISTANT\n\n");
        printf("Appuyez sur une touche pour continuer...");
        getch();
        return;
    }
    afficher(*ordi[indice]);

    printf("ETES VOUS SUR DE VOULOIR SUPPRIMER CETTE INFORMATION ?\n\n");
    printf("Appuyez sur une touche pour continuer...");
    getch();
    char *option[] = {"OUI", "NON"};
    int choisi = outils_navigation(2, option);

    if (choisi == 0) {
        free(ordi[indice]);
        ordi[indice] = NULL;
        printf("SUPPRESSION EFFECTUEE\n");
    } else {
        printf("SUPPRESSION ANNULEE\n");
    }
    printf("Appuyez sur une touche pour continuer...");
    getch();
}

// ======================== Tri ========================

void trier(void)
{
    const char *options[] = {"Trie par marque (ordre alphabetique)", "Trie par prix", "Trie par vitesse CPU", "Trie par specialite", "Trie par capacite disque dur", "Trie par capacite RAM"};
    int nbOptions = 6;

    system("cls");
    printf("Quelle categorie de trie voulez-vous effectuer ?\n\n");
    int choisi = outils_navigation(nbOptions, (char**)options);  

    // Remplir un tableau temporaire des pointeurs non NULL
    ordinateur *temp[300];
    int count = 0;
    for (int i = 0; i < 300; i++) {
        if (ordi[i] != NULL) {
            temp[count] = ordi[i];
            count++;
        }
    }

    if (count == 0) {
        printf("Aucun ordinateur en memoire.\n");
        Sleep(2000);
        return;
    }

    // Tri à bulles
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            int echanger = 0;
            switch (choisi) {
                case 0: // marque
                    if (strcmp(temp[i]->marque, temp[j]->marque) > 0) echanger = 1;
                    break;
                case 1: // prix
                    if (temp[i]->prix_ordinateur > temp[j]->prix_ordinateur) echanger = 1;
                    break;
                case 2: // vitesse CPU
                    if (temp[i]->vitesse_cpu > temp[j]->vitesse_cpu) echanger = 1;
                    break;
                case 3: // specialite
                    if (strcmp(temp[i]->specialite, temp[j]->specialite) > 0) echanger = 1;
                    break;
                case 4: // disque dur
                    if (temp[i]->disque_dur > temp[j]->disque_dur) echanger = 1;
                    break;
                case 5: // RAM
                    if (temp[i]->ram > temp[j]->ram) echanger = 1;
                    break;
                default: break;
            }
            if (echanger) {
                ordinateur *tmp = temp[i];
                temp[i] = temp[j];
                temp[j] = tmp;
            }
        }
    }

    system("cls");
    printf("Liste triee selon le critere choisi :\n\n");
    for (int i = 0; i < count; i++) {
        afficher(*temp[i]);
    }
    printf("\nAppuyez sur une touche...");
    getch();
    system("cls");
}

// ======================== Sortie ========================

void sortir()
{
    const char *options[] = {"OUI", "NON"};
    int nbOptions = 2;
    int choisi = outils_navigation(nbOptions, (char**)options);

    if (choisi == 0) {
        for (int i = 0; i < 300; i++)
            if (ordi[i] != NULL) free(ordi[i]);
        exit(0);
    }
}

// ======================== Menu et navigation ========================

int menu()
{
    const char *options[] = {"AFFICHER TOUS LES ORDINATEURS", "SAISIR", "MODIFIER", "SUPPRIMER", "RECHERCHE", "TRIER", "EXIT"};
    int nbOptions = 7;
    return outils_navigation(nbOptions, (char**)options);
}

void naviguer(int choix)
{
    if (choix == 0) {   // AFFICHER
        int n_affichage = 0;
        for (int i = 0; i < 300; i++) {
            if (ordi[i] != NULL) {
                printf("ORDINATEUR %d :\n", i + 1);
                afficher(*ordi[i]);
                n_affichage++;   
            }
            if (i == 299 && n_affichage != 0)
            {
                printf("Appuyez sur une touche pour continuer...\n");
                getch();
            }
            
            
        }
        if (n_affichage == 0) {
            printf("Aucun ordinateur en memoire.\n");
            printf("Appuyez sur une touche pour continuer...");
            getch();
        }
    } else if (choix == 1) {
        ajouter();
    } else if (choix == 2) {
        modifier();
    } else if (choix == 3) {
        supprimer();
    } 
    else if (choix == 4) 
    {
        rechercher();   
        printf("Appuyez sur une touche pour continuer...");
        getch();
        
    }       
     else if (choix == 5) {
        trier();
    } else if (choix == 6) {
        sortir();
    }
}


