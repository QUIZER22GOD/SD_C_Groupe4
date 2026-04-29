
#include "head.h"

void trier(void)
{
    const char *options[] = {"Trie par marque (ordre alphabetique)", "Trie par prix", "Trie par vitesse CPU", "Trie par specialite", "Trie par capacite disque dur", "Trie par capacite RAM"};
    int choisi = 0;
    const int nbOptions = 6;
    int touche;

    system("cls");

    printf("Quelle categorie de trie voulez-vous effectuer ?\n\n");

    while (1) {
        
        gotoxy(0, 2);

        
        for (int i = 0; i < nbOptions; i++) {
            
            printf("                                        \r"); 
            gotoxy(0, 2 + i); 
            if (i == choisi) {
                printf("> %s <", options[i]);
            } else {
                printf("  %s  ", options[i]);
            }
        }

        touche = getch();
        if (touche == 224) { 
            touche = getch();
            if (touche == 72 && choisi > 0) {        
                choisi--;
            } else if (touche == 80 && choisi < nbOptions - 1) { 
                choisi++;
            }
        } else if (touche == 13) { 
            break;
        }
    }

     ordinateur *temp[300];
    int count = 0;
    for (int i = 0; i < 300; i++) {
        if (ordi[i] != 0) {
            temp[count] = ordi[i];
            count++;
        }
    }

    if (count == 0) {
        printf("Aucun ordinateur en mémoire.\n");
        Sleep(2000);
        return;
    }

    // 2. Tri à bulles sur le tableau temp
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            int echanger = 0;
            // comparaison selon le critère (exemple pour prix)
            switch (choisi) {
                case 0: // marque
                    if (strcmp(temp[i]->marque, temp[j]->marque) > 0) echanger = 1;
                    break;
                case 1: // prix
                    if (*(temp[i]->prix_ordinateur) > *(temp[j]->prix_ordinateur)) echanger = 1;
                    break;
                case 2: // vitesse CPU
                    if (*(temp[i]->vitesse_cpu) > *(temp[j]->vitesse_cpu)) echanger = 1;
                    break;
                // ... autres critères ...
                default: break;
            }
            if (echanger) {
                ordinateur *tmp = temp[i];
                temp[i] = temp[j];
                temp[j] = tmp;
            }
        }
    }

    // 3. Affichage en boucle
    system("cls");
    printf("Liste triee selon le critere choisi :\n\n");
    for (int i = 0; i < count; i++) {
        afficher(*temp[i]);   // si afficher attend une structure par valeur
        // Si afficher attend une structure par valeur : afficher(*temp[i]);
    }
    printf("\nAppuyez sur une touche...");
    getch();
    system("cls");

}
