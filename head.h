#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

typedef struct
{
    int *numero_carte,*ram,*disque_dur,*prix_ordinateur;
    char specialite[5];
    char marque[20];
    float *vitesse_cpu;

}ordinateur;

extern ordinateur *ordi[300];


void Bienvenue(void);
int menu(void);
void gotoxy(int x, int y);
void ajouter();
void afficher(ordinateur ordi);
void modifier();
void supprimer();
ordinateur* rechercher(int numero_carte);
void trier();
void sortir();
void naviguer();


#endif // HEAD_H_INCLUDED
