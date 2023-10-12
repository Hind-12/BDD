#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#include "bdd/bddA.h"

// création d'une base de donnée pour stocker une liste des contacts.


int main() {
    struct Element elements[100];
    int niveauDroits = AUCUN_DROIT;
    int nbElements = 0;
    int choix;



    printf("Entrez votre niveau de droits (0 = aucun, 1 = complet, 2 = limité) : ");
    scanf_s("%d", &niveauDroits);

    if (niveauDroits != AUCUN_DROIT && niveauDroits != DROIT_COMPLET && niveauDroits != AUCUN_DROIT) {
        printf("Niveau de droits non valide.\n");
        return 1; // Quitte le programme si le niveau de droits est invalide.
    }

    if (niveauDroits == DROIT_COMPLET || niveauDroits == AUCUN_DROIT) {
        do {
            // Affichage du menu
            printf("Menu :\n");
            printf("1. Ajouter un élément\n");
            printf("2. Supprimer un élément\n");
            printf("3. Mettre à jour un élément\n");
            printf("4. Afficher tous les éléments\n");
            printf("5. Quitter\n");
            printf("Choisissez une option : ");
            scanf_s("%d", &choix);

            switch (choix) {
            case 1:
                ajouterElement(elements, &nbElements);
                break;
            case 2:
                supprimerElement(elements, &nbElements);
                break;
            case 3:
                // Ajoutez ici la logique pour mettre à jour un élément
                break;
            case 4:
                afficherElements(elements, &nbElements);
                break;
            case 5:
                printf("Au revoir !\n");
                break;
            default:
                printf("Option invalide. Réessayez.\n");
            }
        } while (choix != 5);
    }
    else {
        printf("Désolé, vous n'avez pas le droit d'accéder à la base de données.");
    }
    return 0;
}



/*
int main() {
    int niveauDroits = AUCUN_DROIT;
    struct Contact contacts[100]; // Tableau pour stocker les contacts
    struct Product products[100];
    int nbContacts = 0; // Nombre actuel de contacts dans la base de données
    int nbProducts = 0;
    int choixListe;
    int choix;

    printf("Choisissez la liste a gerer (1 pour contacts, 2 pour produits) : ");
    scanf_s("%d", &choixListe);

    if (choixListe != 1 && choixListe != 2) {
        printf("Choix de liste non valide.\n");
        return 1; // Quitte le programme si le choix de liste est invalide.
    }

    printf("Entrez votre niveau de droits (0 = aucun, 1 = complet, 2 = limité) : ");
    scanf_s("%d", &niveauDroits);

    if (niveauDroits != AUCUN_DROIT && niveauDroits != DROIT_COMPLET && niveauDroits != DROIT_LIMITÉ) {
        printf("Niveau de droits non valide.\n");
        return 1; // Quitte le programme si le niveau de droits est invalide.
    }

    if (niveauDroits == DROIT_COMPLET || niveauDroits == DROIT_LIMITÉ) {
        do {
            // Affichage du menu 
            printf("Menu :\n");
            printf("Remarque: a chaque fois que vous choisisi une option, vous deviez choisir si 1:contact ou 0: produit.\n");
            if ((choixListe == 1 && niveauDroits == DROIT_COMPLET) || (choixListe == 2 && niveauDroits == DROIT_COMPLET)) {
                printf("1. Ajouter un elementt\n");
                printf("2. Supprimer un element\n");
                printf("3. Mettre a jour un element\n");
            }
            if ((choixListe == 1 && niveauDroits == DROIT_COMPLET || niveauDroits == DROIT_LIMITÉ) || (choixListe == 2 && niveauDroits == DROIT_COMPLET || niveauDroits == DROIT_LIMITÉ)) {
                printf("4. Afficher tous les elements\n");
            }
            printf("5. Quitter\n");
            printf("Choisissez une option : ");
            scanf_s("%d", &choix);

            switch (choix) {
                case 1:
                    if (choixListe == 1 &&  niveauDroits == DROIT_COMPLET) {
                        ajouterContact(contacts, &nbContacts); // ajouter un switch case (case1 contact, case2 products
                    }
                    else if (choixListe == 2 && niveauDroits == DROIT_COMPLET) {
                        ajouterProduct(products, &nbProducts);
                    }
                    else {
                        printf("Desole, vous n'avez pas les droits pour ajouter un element.\n");
                    }
                    break;
                case 2:
                    if (choixListe == 1 && niveauDroits == DROIT_COMPLET) {
                        supprimerContact(contacts, &nbContacts);
                    }
                    else if (choixListe == 2 && niveauDroits == DROIT_COMPLET) {
                        supprimerProduct(products, &nbProducts);
                    }
                    else {
                        printf("Desole, vous navez pas les droits pour ajouter un element.\n");
                    }
                    break;
                case 3:
                    if (choixListe == 1 &&  niveauDroits == DROIT_COMPLET) {
                        mettreAJourContact(contacts, nbContacts);
                    }
                    else if (choixListe == 2 && niveauDroits == DROIT_COMPLET) {
                        mettreAJourProduct(products, &nbProducts);
                    }
                    else {
                        printf("Desole, vous navez pas les droits pour ajouter un element.\n");
                    }
                    break;
                case 4:
                    if (choixListe == 1 && (niveauDroits == DROIT_COMPLET || niveauDroits == DROIT_LIMITÉ)) {
                        afficherContacts(contacts, nbContacts);                       
                    }
                    else if (choixListe == 2 && (niveauDroits == DROIT_COMPLET || niveauDroits == DROIT_LIMITÉ)) {
                        afficherProducts(products, &nbProducts);
                    }
                    else {
                        printf("Desole, vous navez pas les droits pour acceder a la liste des elements!.\n");
                    }
                    break;
                case 5:
                    printf("Au revoir !\n");
                    break;
                default:
                    printf("Option invalide. Reessayez.\n");
            }
        } while (choix != 5);
    }
    printf("Desolee, vous navez pas le droit dacceder a la BDD!");
    return 0;
}
*/
