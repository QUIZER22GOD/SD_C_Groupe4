#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "polynome.h"


int main() 
{
    // Déclaration des deux polynômes (alloués sur la pile)
    Polynome p1, p2;
    initialiser_polynome(&p1);
    initialiser_polynome(&p2);

    int choix;
    do {
        afficher_menu();
        printf("Votre choix : ");
        scanf("%d", &choix);
        while (getchar() != '\n'); // vider le buffer après le scanf

        switch (choix) {
            case 1:
                saisir_polynome(&p1, "P1");
                break;
            case 2:
                saisir_polynome(&p2, "P2");
                break;
            case 3:
                afficher_polynome(&p1, "P1");
                break;
            case 4:
                afficher_polynome(&p2, "P2");
                break;
            case 5:
                operation_addition(&p1, &p2);
                break;
            case 6:
                operation_soustraction(&p1, &p2);
                break;
            case 7:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 7);

    // Libération propre avant de quitter
    sortie_propre(&p1, &p2);
    return 0;
}

void afficher_menu() {
    printf("\n========== MENU POLYNOMES ==========\n");
    printf("1. Saisir le polynome P1\n");
    printf("2. Saisir le polynome P2\n");
    printf("3. Afficher P1\n");
    printf("4. Afficher P2\n");
    printf("5. Additionner P1 + P2\n");
    printf("6. Soustraire P1 - P2\n");
    printf("7. Quitter\n");
    printf("====================================\n");
}

void saisir_polynome(Polynome *p, const char *nom) {
    // Libérer l'ancien polynôme s'il existe
    liberer_polynome(p);
    initialiser_polynome(p);

    char *chaine = entrer_polynome();
    if (chaine == NULL) {
        printf("Erreur de saisie.\n");
        return;
    }
    // Vérification simplifiée (vous pouvez appeler verifier_polynome si vous voulez)
    if (strlen(chaine) == 0) {
        printf("Chaîne vide, polynôme mis à 0.\n");
        free(chaine);
        return;
    }
    creation_polynome(p, chaine);
    free(chaine);
    printf("Polynome %s enregistre.\n", nom);
}

void afficher_polynome(Polynome *p, const char *nom) {
    printf("%s = ", nom);
    affichage(p);
}

void operation_addition(Polynome *p1, Polynome *p2) {
    if (p1->debut == NULL || p2->debut == NULL) {
        printf("L'un des polynômes est vide. Impossible de faire l'addition.\n");
        return;
    }
    Polynome *resultat = addition_polynome(p1, p2);
    if (resultat == NULL) {
        printf("Erreur lors de l'addition.\n");
        return;
    }
    printf("Résultat (P1 + P2) = ");
    affichage(resultat);
    liberer_polynome(resultat);
    free(resultat);
}

void operation_soustraction(Polynome *p1, Polynome *p2) {
    if (p1->debut == NULL || p2->debut == NULL) {
        printf("L'un des polynômes est vide. Impossible de faire la soustraction.\n");
        return;
    }
    Polynome *resultat = soustraction_polynome(p1, p2);
    if (resultat == NULL) {
        printf("Erreur lors de la soustraction.\n");
        return;
    }
    printf("Résultat (P1 - P2) = ");
    affichage(resultat);
    liberer_polynome(resultat);
    free(resultat);
}

void sortie_propre(Polynome *p1, Polynome *p2)
{
    liberer_polynome(p1);
    liberer_polynome(p2);
    printf("Mémoire libérée. Fin du programme.\n");
}
