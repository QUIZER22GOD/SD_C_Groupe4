#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

typedef struct
{
    int numero_carte,ram,disque_dur,prix_ordinateur;
    char specialite[20];
    char marque[20];
    float vitesse_cpu;

}ordinateur;


void naviguer(int choix);
void Bienvenue();
int menu();
void gotoxy(int x, int y);
void ajouter();
void afficher(ordinateur ordi);
void modifier();
void supprimer();
void rechercher();
int outils_navigation(int nbOptions,  char *options[]);
void trier();
void sortir();
void naviguer();


#endif // HEAD_H_INCLUDED
