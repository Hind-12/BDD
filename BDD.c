#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#include "bdd/bddA.h"

// cr�ation d'une base de donn�e pour stocker une liste des contacts.

int main() {
    int niveauDroits = AUCUN_DROIT;
    struct Contact contacts[100]; // Tableau pour stocker les contacts
    int nbContacts = 0; // Nombre actuel de contacts dans la base de donn�es
    int choix;
    printf("Entrez votre niveau de droits (0 = aucun, 1 = complet, 2 = limit�) : ");
    scanf("%d", &niveauDroits);

    if (niveauDroits == DROIT_COMPLET || niveauDroits == DROIT_LIMIT�) {
        do {
            // Affichage du menu 
            printf("Menu :\n");
            if (niveauDroits == DROIT_COMPLET) {
                printf("1. Ajouter un contact\n");
                printf("2. Supprimer un contact\n");
                printf("3. Mettre a jour un contact\n");
            }
            if (niveauDroits == DROIT_COMPLET || niveauDroits == DROIT_LIMIT�) {
                printf("4. Afficher tous les contacts\n");
            }
            printf("5. Quitter\n");
            printf("Choisissez une option : ");
            scanf_s("%d", &choix);

            switch (choix) {
            case 1:
                if (niveauDroits == DROIT_COMPLET) {
                    ajouterContact(contacts, &nbContacts);
                }
                else {
                    printf("D�sol�, vous n'avez pas les droits pour ajouter un contact.\n");
                }
                break;
            case 2:
                if (niveauDroits == DROIT_COMPLET) {
                    supprimerContact(contacts, &nbContacts);
                }
                else {
                    printf("D�sol�, vous n'avez pas les droits pour ajouter un contact.\n");
                }
                break;
            case 3:
                if (niveauDroits == DROIT_COMPLET) {
                    mettreAJourContact(contacts, nbContacts);
                }
                else {
                    printf("D�sol�, vous n'avez pas les droits pour ajouter un contact.\n");
                }
                break;
            case 4:
                if (niveauDroits == DROIT_COMPLET || niveauDroits == DROIT_LIMIT�) {
                    afficherContacts(contacts, nbContacts);
                }
                else {
                    printf("D�sol�, vous n'avez pas les droits pour acceder � la liste des contacts!.\n");
                }
                break;
            case 5:
                printf("Au revoir !\n");
                break;
            default:
                printf("Option invalide. R�essayez.\n");
            }
        } while (choix != 5);
    }
    printf("Desol�e, vous n'avez pas le droit d'acc�der � la BDD!");
    return 0;
}
