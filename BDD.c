#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#include "bdd/bddA.h"



int main() {
    struct Contact contacts[100]; // Tableau pour stocker les contacts
    int nbContacts = 0; // Nombre actuel de contacts dans la base de données
    int choix;

    do {
        // Affichage du menu
        printf("Menu :\n");
        printf("1. Ajouter un contact\n");
        printf("2. Supprimer un contact\n");
        printf("3. Afficher tous les contacts\n");
        printf("4. Mettre a jour un contact\n");
        printf("5. Quitter\n");
        printf("Choisissez une option : ");
        scanf_s("%d", &choix);

        switch (choix) {
        case 1:
            ajouterContact(contacts, &nbContacts);
            break;
        case 2:
            supprimerContact(contacts, &nbContacts);
            break;
        case 3:
            afficherContacts(contacts, nbContacts);
            break;
        case 4:
            mettreAJourContact(contacts, nbContacts);
            break;
        case 5:
            printf("Au revoir !\n");
            break;
        default:
            printf("Option invalide. Réessayez.\n");
        }
    } while (choix != 5);

    return 0;
}
