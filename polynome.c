#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "polynome.h"

void affichage(Polynome *p)
{
    if (p == NULL || p->debut == NULL) {
        printf("0\n");
        return;
    }

    element_polynome *element = p->debut;
    int premier = 1; // drapeau pour le premier terme

    while (element != NULL)
    {
        int coeff = element->coefficient;
        int exp = element->exposant;

        // Gérer le signe
        if (coeff < 0) {
            printf(" - ");
            coeff = -coeff;  // on travaille avec la valeur absolue
        } else if (!premier) {
            printf(" + ");
        }

        // Afficher le terme selon les cas
        if (exp == 0) {
            printf("%d", coeff);
        } else if (exp == 1) {
            if (coeff == 1)
                printf("X");
            else
                printf("%dX", coeff);
        } else { // exp >= 2
            if (coeff == 1)
                printf("X^%d", exp);
            else
                printf("%dX^%d", coeff, exp);
        }

        premier = 0;
        element = element->suivant;
    }

    printf("\n");
}

void initialiser_polynome(Polynome *p)
{
    if (p == NULL) {
        printf("Erreur: le polynome est NULL.\n");
        return;
    }
    p->degree = 0;
    p->debut = NULL;
    p->fin = NULL;
}

char *entrer_polynome()
{
    char *copie = malloc(151);
    char *polynome = malloc(151);
    if (!copie || !polynome) {
        free(copie); free(polynome);
        return NULL;
    }

    printf("Entrez le polynome sous la forme aX^n +bX^m .... : ");
    fgets(polynome, 151, stdin);
    polynome[strcspn(polynome, "\n")] = '\0';

    // Si la ligne est trop longue, vider le buffer
    if (strlen(polynome) == 150 && polynome[149] != '\0') {
        while (getchar() != '\n');
    }

    // Supprimer les espaces
    int j = 0;
    for (int i = 0; polynome[i]; i++) {
        if (polynome[i] != ' ') copie[j++] = polynome[i];
    }
    copie[j] = '\0';

    free(polynome);
    return copie;
}

void verifier_polynome(char *polynome , Polynome *p)
{
    if (polynome == NULL || p == NULL) {
        printf("Le polynome ou le polynome struct est NULL.\n");
        return;
    }

    if (polynome[0] == '\0') {
        printf("Le polynome est vide.\n");
        return;
    }


    if (strstr(polynome , "+-") || strstr(polynome , "*/") || strstr(polynome , "%%") || strstr(polynome , "^^")  || strstr(polynome , "++") || strstr(polynome , "--"))
    {
        printf("Le polynome contient des operateurs consecutifs.\n");
        return;
    }


    if (polynome == NULL || polynome[0] == '\0') {
        printf("Le polynome est NULL ou vide.\n");
        return;
    }


    if (strstr(polynome , "+-") || strstr(polynome , "*/") || strstr(polynome , "%%") || strstr(polynome , "^^")  || strstr(polynome , "++") || strstr(polynome , "--"))
    {
        printf("Le polynome contient des operateurs consecutifs.\n");
    }


}

void extraire_coeff_exp(char *terme, int *coeff, int *exp)
{
    // Supprimer les espaces éventuels
    char *p = terme;
    while (*p == ' ' || *p == '\t') p++;

    // Détecter le signe (déjà présent)
    int signe = 1;
    if (*p == '+') p++;
    else if (*p == '-') { signe = -1; p++; }

    // Chercher 'x' ou 'X'
    char *x_pos = strchr(p, 'x');
    if (!x_pos) x_pos = strchr(p, 'X');

    if (x_pos == NULL) {
        // Constante
        *coeff = atoi(p) * signe;
        *exp = 0;
        return;
    }

    // Coefficient (partie avant x)
    char coeff_str[20];
    int len_coeff = x_pos - p;
    if (len_coeff == 0) {
        *coeff = 1 * signe; // cas "x" ou "-x"
    } else {
        strncpy(coeff_str, p, len_coeff);
        coeff_str[len_coeff] = '\0';
        *coeff = atoi(coeff_str) * signe;
    }

    // Exposant (après ^)
    char *hat = strchr(x_pos, '^');
    if (hat == NULL) {
        *exp = 1; // cas "x" ou "-x"
    } else {
        *exp = atoi(hat + 1);
        if (*exp == 0) *exp = 1; // sécurité
    }
}



Polynome *creation_polynome(Polynome *p, char *polynome)
{
    // Découpage en termes (comme avant)
    char **element = malloc(50 * sizeof(char*));
    for (int i = 0; i < 50; i++) element[i] = malloc(50 * sizeof(char));

    int nb_elements = 0;
    int debut = 0;
    int len = strlen(polynome);
    for (int i = 0; i <= len; i++) {
        if (i == len || polynome[i] == '+' || polynome[i] == '-') {
            if (i > debut) {
                int k = 0;
                for (int j = debut; j < i; j++) {
                        element[nb_elements][k++] = polynome[j];
                }
                element[nb_elements][k] = '\0';
                nb_elements++;
            }
            debut = i;
        }
    }

    // Traiter chaque terme avec ajouter_terme_polynome
    for (int i = 0; i < nb_elements; i++) {
        int coeff, exp;
        extraire_coeff_exp(element[i], &coeff, &exp);
        ajouter_terme_polynome(p, coeff, exp);
    }

    // Libération
    for (int i = 0; i < 50; i++) free(element[i]);
    free(element);

    return p;
}

// Ajoute un terme (coeff, exp) à la fin du polynôme p
void ajouter_terme(Polynome *p, int coeff, int exp)
{
    if (coeff == 0) return; // on ignore les termes nuls

    element_polynome *nouveau = (element_polynome*)malloc(sizeof(element_polynome));
    if (!nouveau) {
        printf("Erreur d'allocation mémoire\n");
        return;
    }
    nouveau->coefficient = coeff;
    nouveau->exposant = exp;
    nouveau->suivant = NULL;

    if (p->debut == NULL) {
        p->debut = p->fin = nouveau;
    } else {
        p->fin->suivant = nouveau;
        p->fin = nouveau;
    }
}

// Crée une copie de p complétée avec des zéros pour les exposants manquants jusqu'à degre_max
Polynome* copier_polynome_avec_zeros(Polynome *p, int degre_max)
{
    Polynome *copie = (Polynome*)malloc(sizeof(Polynome));
    if (!copie) return NULL;
    initialiser_polynome(copie);

    element_polynome *courant = p->debut;

    for (int exp = 0; exp <= degre_max; exp++) {
        int coeff = 0;
        if (courant != NULL && courant->exposant == exp) {
            coeff = courant->coefficient;
            courant = courant->suivant;
        }

        // Créer un nœud même si coeff = 0 (pour garder l'exposant)
        element_polynome *nouveau = (element_polynome*)malloc(sizeof(element_polynome));
        if (!nouveau) {
            liberer_polynome(copie);
            free(copie);
            return NULL;
        }
        nouveau->coefficient = coeff;
        nouveau->exposant = exp;
        nouveau->suivant = NULL;

        if (copie->debut == NULL) {
            copie->debut = copie->fin = nouveau;
        } else {
            copie->fin->suivant = nouveau;
            copie->fin = nouveau;
        }
    }

    copie->degree = degre_max;
    return copie;
}
// Additionne p1 et p2, retourne un nouveau polynôme
Polynome* addition_polynome(Polynome *p1, Polynome *p2)
{
    if (!p1 || !p2) return NULL;

    // Déterminer le degré maximal
    int deg_max = (p1->degree > p2->degree) ? p1->degree : p2->degree;

    // Créer les copies complétées avec des zéros
    Polynome *copie1 = copier_polynome_avec_zeros(p1, deg_max);
    Polynome *copie2 = copier_polynome_avec_zeros(p2, deg_max);
    if (!copie1 || !copie2) {
        free(copie1); free(copie2);
        return NULL;
    }

    // Créer le polynôme résultat
    Polynome *somme = (Polynome*)malloc(sizeof(Polynome));
    if (!somme) {
        free(copie1); free(copie2);
        return NULL;
    }
    initialiser_polynome(somme);

    // Parcourir les deux copies (elles ont le même nombre de termes)
    element_polynome *c1 = copie1->debut;
    element_polynome *c2 = copie2->debut;

    while (c1 != NULL && c2 != NULL) {
        int coeff_somme = c1->coefficient + c2->coefficient;
        if (coeff_somme != 0) {
            ajouter_terme(somme, coeff_somme, c1->exposant);
        }
        c1 = c1->suivant;
        c2 = c2->suivant;
    }

    // Mettre à jour le degré du résultat (dernier terme non nul)
    // Pour simplifier, on garde deg_max (même si certains coefficients sont nuls)
    // On pourrait recalculer en parcourant la liste, mais c'est suffisant.
    somme->degree = deg_max;

    // Libérer les copies
    liberer_polynome(copie1);
    liberer_polynome(copie2);
    free(copie1); free(copie2); // libérer les structures elles-mêmes

    return somme;
}


Polynome *soustraction_polynome(Polynome *p1, Polynome *p2)
{
    if (!p1 || !p2) return NULL;

    // Déterminer le degré maximal
    int deg_max = (p1->degree > p2->degree) ? p1->degree : p2->degree;

    // Créer les copies complétées avec des zéros
    Polynome *copie1 = copier_polynome_avec_zeros(p1, deg_max);
    Polynome *copie2 = copier_polynome_avec_zeros(p2, deg_max);
    if (!copie1 || !copie2) {
        free(copie1); free(copie2);
        return NULL;
    }

    // Créer le polynôme résultat
    Polynome *difference = (Polynome*)malloc(sizeof(Polynome));
    if (!difference) {
        free(copie1); free(copie2);
        return NULL;
    }
    initialiser_polynome(difference);

    // Parcourir les deux copies (elles ont le même nombre de termes)
    element_polynome *c1 = copie1->debut;
    element_polynome *c2 = copie2->debut;

    while (c1 != NULL && c2 != NULL) {
        int coeff_diff = c1->coefficient - c2->coefficient;
        if (coeff_diff != 0) {
            ajouter_terme(difference, coeff_diff, c1->exposant);
        }
        c1 = c1->suivant;
        c2 = c2->suivant;
    }

    // Mettre à jour le degré du résultat
    difference->degree = deg_max;

    // Libérer les copies
    liberer_polynome(copie1);
    liberer_polynome(copie2);
    free(copie1); free(copie2);

    return difference;
}

void ajouter_terme_polynome(Polynome *p, int coeff, int exp)
{
    if (coeff == 0) return;

    // Parcourir pour trouver la position d'insertion
    element_polynome *courant = p->debut;
    element_polynome *precedent = NULL;

    while (courant != NULL && courant->exposant < exp) {
        precedent = courant;
        courant = courant->suivant;
    }

    // Si l'exposant existe déjà, additionner les coefficients
    if (courant != NULL && courant->exposant == exp) {
        courant->coefficient += coeff;
        // Si le coefficient devient 0, on pourrait supprimer le terme (optionnel)
        return;
    }

    // Créer un nouveau nœud
    element_polynome *nouveau = (element_polynome*)malloc(sizeof(element_polynome));
    if (!nouveau) {
        printf("Erreur d'allocation mémoire\n");
        return;
    }
    nouveau->coefficient = coeff;
    nouveau->exposant = exp;
    nouveau->suivant = courant;

    // Insérer le nœud à la bonne place
    if (precedent == NULL) {
        // Insertion en tête
        p->debut = nouveau;
    } else {
        precedent->suivant = nouveau;
    }

    // Si on insère à la fin (courant == NULL), mettre à jour fin
    if (courant == NULL) {
        p->fin = nouveau;
    }

    // Mettre à jour le degré si nécessaire
    if (exp > p->degree) {
        p->degree = exp;
    }
    if (courant != NULL && courant->exposant == exp) {
    courant->coefficient += coeff;
    if (courant->coefficient == 0) {
        // Supprimer le nœud courant
        if (precedent == NULL) {
            p->debut = courant->suivant;
        } else {
            precedent->suivant = courant->suivant;
        }
        if (courant->suivant == NULL) {
            p->fin = precedent;
        }
        free(courant);
    }
    return;
}
}

void liberer_polynome(Polynome *p)
{
    if (p == NULL) return;
    element_polynome *courant = p->debut;
    while (courant != NULL) {
        element_polynome *suivant = courant->suivant;
        free(courant);
        courant = suivant;
    }
    p->debut = NULL;
    p->fin = NULL;
    p->degree = 0;
}

void supprimer_polynome(Polynome *p)
{
    liberer_polynome(p);
    free(p);
}




