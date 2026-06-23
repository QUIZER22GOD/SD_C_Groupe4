#ifndef POLYNOME_H_INCLUDED
#define POLYNOME_H_INCLUDED

typedef struct element_polynome {
    int coefficient;
    int exposant;
    struct element_polynome* suivant;
} element_polynome;


typedef struct Polynome {
    int degree;
    element_polynome* debut;
    element_polynome* fin;
} Polynome;

void afficher_menu();
void saisir_polynome(Polynome *p, const char *nom);
void afficher_polynome(Polynome *p, const char *nom);
void operation_addition(Polynome *p1, Polynome *p2);
void operation_soustraction(Polynome *p1, Polynome *p2);
void sortie_propre(Polynome *p1, Polynome *p2);
void affichage(Polynome *p);
void initialiser_polynome(Polynome *p);
char *entrer_polynome();
void verifier_polynome(char *polynome , Polynome *p) ;
void extraire_coeff_exp(char *terme, int *coeff, int *exp);
Polynome *creation_polynome(Polynome *p, char *polynome) ;
void ajouter_terme(Polynome *p, int coeff, int exp);
Polynome* copier_polynome_avec_zeros(Polynome *p, int degre_max);
Polynome* addition_polynome(Polynome *p1, Polynome *p2) ;
Polynome *soustraction_polynome(Polynome *p1, Polynome *p2);
void ajouter_terme_polynome(Polynome *p, int coeff, int exp);
void liberer_polynome(Polynome *p);
void supprimer_polynome(Polynome *p);



#endif // POLYNOME_H_INCLUDED


