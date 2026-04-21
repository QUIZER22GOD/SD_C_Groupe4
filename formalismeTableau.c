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

Description : Ce programme permet de savoir
si les étudiants ont validé un unité d'enseignement.
*/
#include <stdio.h>
#include <stdlib.h>

/*Ce programme gère les résultats académiques des étudiants d'une Unité
d'Enseignement (UE)en calculant leurs moyennes selon un système de notation
précis,puis en les validant par rapport à la moyenne générale de la promotion.*/

/*la structure étudiant*/
typedef struct
{
    int numero;
    char nom[30];
    char prenom[30];
    float dst;
    float exam;
    float moy_brute;
    float bonus;
    float moy_def;
} Etudiant;

/*fonction de saisi du nombre d'étudiant*/
int saisirNombreEtudiants()
{
    int n;

    do
    {
        printf("Donnez le nombre d'etudiants : ");
        scanf("%d", &n);

        if (n <= 0)
        {
            printf("Erreur : le nombre d'etudiants doit etre superieur a 0 !\n");
        }

    } while (n <= 0);

    return n;
}
/*27) Définition de la fonction qui ne reçoit rien
en paramètre et retourne les données d'un nouvel étudiant*/
Etudiant saisirEtudiant()
{
    Etudiant e;

    printf("Numero de carte: ");
    scanf("%d", &e.numero);

    printf("Nom :");
    scanf(" %s", e.nom);

    printf("Prenoms :");
    scanf(" %s", e.prenom);

    // Note DST
    do
    {
        printf("La note du DST : ");
        scanf("%f", &e.dst);

        if (e.dst < 0 || e.dst > 20)
            printf("Erreur : la note doit etre comprise entre 0 et 20 !\n");

    } while (e.dst < 0 || e.dst > 20);

    // Note Examen
    do
    {
        printf("Note d'examen : ");
        scanf("%f", &e.exam);

        if (e.exam < 0 || e.exam > 20)
            printf("Erreur : la note doit etre comprise entre 0 et 20 !\n");

    } while (e.exam < 0 || e.exam > 20);

    return e; // On renvoie les informations de l'étudiant
}

// Fonction de calcul de la moyenne brute
void calculerMoyBrute(Etudiant liste[], int n)
{
    for (int i = 0; i < n; i++)
    {
        liste[i].moy_brute = 0.45 * liste[i].dst + 0.55 * liste[i].exam;
    }
}

// Fonction de calcul du bonus
float calculerBonus(float moy_Brute)
{
    float bonus;

    if (moy_Brute < 10)
        bonus = 1;
    else if (moy_Brute <= 15)
        bonus = 0.5;
    else
        bonus = 0;

    return bonus;
}

/*Utilisation de la fonction calculerBonus
pour accorder les bonus aux étudiants*/
void calculerBonusEtudiants(Etudiant liste[], int n)
{
    for (int i = 0; i < n; i++)
    {
        liste[i].bonus = calculerBonus(liste[i].moy_brute);
    }
}

/*Fonction de calcul de la moyenne définitive*/
float calculerMoyenneDefinitive(float moy_brute, float bonus)
{
    return moy_brute + bonus;
}

/*Application de la fonction de calcul de moyenne définitive
aux étudiants*/
void calculerMoyennesDefinitives(Etudiant liste[], int n)
{
    for (int i = 0; i < n; i++)
    {
        liste[i].moy_def = calculerMoyenneDefinitive(liste[i].moy_brute, liste[i].bonus);
    }
}

/*Calcul de la moyenne générale à dépasser avant de valider*/
float calculerMoyenneGenerale(Etudiant liste[], int n)
{
    float somme = 0;

    for (int i = 0; i < n; i++)
    {
        somme += liste[i].moy_def;
    }

    return somme / n;
}

/*Fonction de validation*/
void afficherValidation(Etudiant liste[], int n)
{
    float moyenne_generale = calculerMoyenneGenerale(liste, n);

    printf("\n========================================\n");
    printf("       RESULTATS DE L'UE                \n");
    printf("========================================\n");
    printf("Moyenne generale de l'UE : %.2f\n", moyenne_generale);
    printf("========================================\n\n");

    for (int i = 0; i < n; i++)
    {
        printf("\n-----Etudiant %d-----\n", i + 1);
        printf("Numero de carte  : %d\n", liste[i].numero);
        printf("Nom et prenoms   : %s %s\n", liste[i].nom, liste[i].prenom);
        printf("Note DST         : %.2f\n", liste[i].dst);
        printf("Note Examen      : %.2f\n", liste[i].exam);
        printf("Moyenne brute    : %.2f\n", liste[i].moy_brute);
        printf("Bonus            : %.2f\n", liste[i].bonus);
        printf("Moyenne definitive: %.2f\n", liste[i].moy_def);

        if (liste[i].moy_def >= moyenne_generale)
            printf("Resultat         : VALIDE\n");
        else
            printf("Resultat         : NON VALIDE\n");

        printf("----------------------------------------\n");
    }
}

int main()
{
    //--1. Demande du nombre d'étudiants
    int n = saisirNombreEtudiants();
    //--2. Allocation du tableau liste
    Etudiant *liste;
    liste = (Etudiant *)malloc(n * sizeof(Etudiant));

    if (liste == NULL)
    {
        printf("Erreur memoire\n");
        return 1;
    }

    //--3. Saisir les informations des étudiants
    for (int i = 0; i < n; i++)
    {
        printf("\n-----Etudiant %d-----\n", i + 1);
        liste[i] = saisirEtudiant(); // On stocke chaque étudiant
    }

    //--4. Calcul des moyennes brutes
    calculerMoyBrute(liste, n);

    //--5. Calcul des bonus
    calculerBonusEtudiants(liste, n);

    //--6. Calcul des moyennes définitives
    calculerMoyennesDefinitives(liste, n);

    //--7. Affichage des résultats et de la validation
    afficherValidation(liste, n);

    //--8. Libérer la mémoire
    free(liste);
    liste = NULL;

    return 0;
}