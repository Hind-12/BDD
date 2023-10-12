#include <stdio.h>





struct Element {
    int type;  // 1 pour contact, 2 pour produit
    char nom[50];
    char prenom[50];
    char numero[15];
    char typeProduit[50];
    char couleur[50];
    char taille[15];
};



//ok
void ajouterElement(struct Element elements[], int* nbElements) {
    if (*nbElements < 100) {
        struct Element nouvelElement;
        



        printf("Entrez le type de l'�l�ment (1 pour contact, 2 pour produit) : ");
        scanf_s("%d", &nouvelElement.type);

        if (nouvelElement.type == 1) {
            printf("Entrez le nom : ");
            scanf_s("%s", nouvelElement.nom, sizeof(nouvelElement.nom));
            printf("Entrez le pr�nom : ");
            scanf_s("%s", nouvelElement.prenom, sizeof(nouvelElement.prenom));
            printf("Entrez le num�ro de t�l�phone : ");
            scanf_s("%s", nouvelElement.numero, sizeof(nouvelElement.numero));
        }
        else if (nouvelElement.type == 2) {
            printf("Entrez le type : ");
            scanf_s("%s", nouvelElement.typeProduit, sizeof(nouvelElement.typeProduit));
            printf("Entrez la couleur : ");
            scanf_s("%s", nouvelElement.couleur, sizeof(nouvelElement.couleur));
            printf("Entrez la taille : ");
            scanf_s("%s", nouvelElement.taille, sizeof(nouvelElement.taille));
        }
        else {
            printf("Type d'�l�ment non valide.\n");
            return;
        }

        elements[*nbElements] = nouvelElement;
        (*nbElements)++;

        printf("�l�ment ajout� avec succ�s.\n");
    }
    else {
        printf("La base de donn�es est pleine. Supprimez des �l�ments pour en ajouter de nouveaux.\n");
    }
}

void afficherElements(struct Element elements[], int nbElements) {
    if (nbElements == 0) {
        printf("La base de donn�es est vide.\n");
        return;
    }

    printf("Liste des �l�ments :\n");

    for (int i = 0; i < nbElements; i++) {
      
        if (elements[i].type == 1) {
            printf("Nom : %s\n", elements[i].nom);
            printf("Pr�nom : %s\n", elements[i].prenom);
            printf("Num�ro de t�l�phone : %s\n", elements[i].numero);
        }
        else if (elements[i].type == 2) {
            printf("Type de produit : %s\n", elements[i].typeProduit);
            printf("Couleur : %s\n", elements[i].couleur);
            printf("Taille : %s\n", elements[i].taille);
        }
        printf("----------------------\n");
    }
}


//OK$$
void supprimerElement(struct Element elements[], int* nbElements) {
    if (*nbElements == 0) {
        printf("La base de donn�es est vide. Impossible de supprimer un �l�ment.\n");
        return;
    }

    int choixSuppression;
    printf("Entrez le type de l'�l�ment � supprimer (1 pour contact, 2 pour produit) : ");
    scanf_s("%d", &choixSuppression);

    if (choixSuppression != 1 && choixSuppression != 2) {
        printf("Type d'�l�ment non valide.\n");
        return;
    }

    if (choixSuppression == 1) {
        char nomASupprimer[50];
        char prenomASupprimer[50];

        printf("Entrez le nom du contact � supprimer : ");
        scanf_s("%s", nomASupprimer, sizeof(nomASupprimer));
        printf("Entrez le pr�nom du contact � supprimer : ");
        scanf_s("%s", prenomASupprimer, sizeof(prenomASupprimer));

        int indexASupprimer = -1;

        // Recherche du contact � supprimer dans la base de donn�es
        for (int i = 0; i < *nbElements; i++) {
            if (elements[i].type == 1 &&
                strcmp(elements[i].nom, nomASupprimer) == 0 &&
                strcmp(elements[i].prenom, prenomASupprimer) == 0) {
                indexASupprimer = i;
                break;
            }
        }

        if (indexASupprimer != -1) {
            // D�placer les �l�ments suivants pour remplir l'emplacement supprim�
            for (int i = indexASupprimer; i < *nbElements - 1; i++) {
                elements[i] = elements[i + 1];
            }
            (*nbElements)--;
            printf("Contact supprim� avec succ�s.\n");
        }
        else {
            printf("Le contact n'a pas �t� trouv� dans la base de donn�es.\n");
        }
    }
    else if (choixSuppression == 2) {
        char typeProduitASupprimer[50];
        char couleurASupprimer[50];

        printf("Entrez le type du produit � supprimer : ");
        scanf_s("%s", typeProduitASupprimer, sizeof(typeProduitASupprimer));
        printf("Entrez la couleur du produit � supprimer : ");
        scanf_s("%s", couleurASupprimer, sizeof(couleurASupprimer));

        int indexASupprimer = -1;

        // Recherche du produit � supprimer dans la base de donn�es
        for (int i = 0; i < *nbElements; i++) {
            if (elements[i].type == 2 &&
                strcmp(elements[i].typeProduit, typeProduitASupprimer) == 0 &&
                strcmp(elements[i].couleur, couleurASupprimer) == 0) {
                indexASupprimer = i;
                break;
            }
        }

        if (indexASupprimer != -1) {
            // D�placer les �l�ments suivants pour remplir l'emplacement supprim�
            for (int i = indexASupprimer; i < *nbElements - 1; i++) {
                elements[i] = elements[i + 1];
            }
            (*nbElements)--;
            printf("Produit supprim� avec succ�s.\n");
        }
        else {
            printf("Le produit n'a pas �t� trouv� dans la base de donn�es.\n");
        }
    }
}





/*

// Structure de donn�es pour un contact
struct Contact {
    char nom[50];
    char prenom[50];
    char numero[15];
};

struct Product
{
    char type[50];
    char couleur[50];
    char taille[15];
};


// Fonction pour ajouter un contact � la base de donn�es
void ajouterContact(struct Contact contacts[], int* nbContacts) {
        if (*nbContacts < 100) {
            struct Contact nouveauContact;
            printf("Entrez le nom : ");
            scanf_s("%s", nouveauContact.nom, sizeof(nouveauContact.nom));
            printf("Entrez le pr�nom : ");
            scanf_s("%s", nouveauContact.prenom, sizeof(nouveauContact.prenom));
            printf("Entrez le num�ro de t�l�phone : ");
            scanf_s("%s", nouveauContact.numero, sizeof(nouveauContact.numero));

            contacts[*nbContacts] = nouveauContact;
            (*nbContacts)++;

            printf("Contact ajout� avec succ�s.\n");
        }
        else {
            printf("La base de donn�es est pleine. Supprimez des contacts pour en ajouter de nouveaux.\n");
    }
}

void ajouterProduct(struct Product products[], int* nbProducts) {
    if (*nbProducts < 100) {
        struct Product nouveauProduct;
        printf("Entrez le type : ");
        scanf_s("%s", nouveauProduct.type, sizeof(nouveauProduct.type));
        printf("Entrez le couleur : ");
        scanf_s("%s", nouveauProduct.couleur, sizeof(nouveauProduct.couleur));
        printf("Entrez la taille : ");
        scanf_s("%s", nouveauProduct.taille, sizeof(nouveauProduct.taille));

        products[*nbProducts] = nouveauProduct;
        (*nbProducts)++;

        printf("Product ajout� avec succ�s.\n");
    }
    else {
        printf("La base de donn�es est pleine. Supprimez des products pour en ajouter de nouveaux.\n");
    }
}




// Fonction pour afficher tous les contacts
void afficherContacts(struct Contact contacts[], int nbContacts) {
    printf("Liste des contacts :\n");
    for (int i = 0; i < nbContacts; i++) {
        printf("Nom : %s\n", contacts[i].nom);
        printf("Pr�nom : %s\n", contacts[i].prenom);
        printf("Num�ro de t�l�phone : %s\n", contacts[i].numero);
        printf("----------------------\n");
    }
}


void afficherProducts(struct Product products[], int nbProducts) {
    printf("Liste des products :\n");
    for (int i = 0; i < nbProducts; i++) {
        printf("type : %s\n", products[i].type);
        printf("couleur : %s\n", products[i].couleur);
        printf("taille : %s\n", products[i].taille);
        printf("----------------------\n");
    }
}





// Fonction pour supprimer un contact de la base de donn�es
void supprimerContact(struct Contact contacts[], int* nbContacts) {
    char nomASupprimer[50];
    char prenomASupprimer[50];

    printf("Entrez le nom du contact � supprimer : ");
    scanf_s("%s", nomASupprimer, sizeof(nomASupprimer));
    printf("Entrez le pr�nom du contact � supprimer : ");
    scanf_s("%s", prenomASupprimer, sizeof(prenomASupprimer));

    int indexASupprimer = -1;

    // Recherche du contact � supprimer dans la base de donn�es
    for (int i = 0; i < *nbContacts; i++) {
        if (strcmp(contacts[i].nom, nomASupprimer) == 0 && strcmp(contacts[i].prenom, prenomASupprimer) == 0) {
            indexASupprimer = i;
            break;
        }
    }

    if (indexASupprimer != -1) {
        // D�placer les contacts suivants vers l'arri�re pour remplir l'emplacement supprim�
        for (int i = indexASupprimer; i < *nbContacts - 1; i++) {
            contacts[i] = contacts[i + 1];
        }
        (*nbContacts)--;
        printf("Contact supprim� avec succ�s.\n");
    }
    else {
        printf("Le contact n'a pas �t� trouv� dans la base de donn�es.\n");
    }
}


void supprimerProduct(struct Product products[], int* nbProducts) {
    char nomASupprime2r[50];
    char prenomASupprime2r[50];

    printf("Entrez le type du produit � supprimer : ");
    scanf_s("%s", nomASupprime2r, sizeof(nomASupprime2r));
    printf("Entrez la couleur du produit � supprimer : ");
    scanf_s("%s", prenomASupprime2r, sizeof(prenomASupprime2r));

    int indexASupprime2r = -1;

    // Recherche du contact � supprimer dans la base de donn�es
    for (int i = 0; i < *nbProducts; i++) {
        if (strcmp(products[i].type, nomASupprime2r) == 0 && strcmp(products[i].couleur, prenomASupprime2r) == 0) {
            indexASupprime2r = i;
            break;
        }
    }

    if (indexASupprime2r != -1) {
        // D�placer les contacts suivants vers l'arri�re pour remplir l'emplacement supprim�
        for (int i = indexASupprime2r; i < *nbProducts - 1; i++) {
            products[i] = products[i + 1];
        }
        (*nbProducts)--;
        printf("Product supprim� avec succ�s.\n");
    }
    else {
        printf("Le products n'a pas �t� trouv� dans la base de donn�es.\n");
    }
}




// Fonction pour mettre � jour un contact dans la base de donn�es
void mettreAJourContact(struct Contact contacts[], int nbContacts) {
    char nomAMettreAJour[50];
    char prenomAMettreAJour[50];

    printf("Entrez le nom du contact � mettre � jour : ");
    scanf_s("%s", nomAMettreAJour, sizeof(nomAMettreAJour));
    printf("Entrez le pr�nom du contact � mettre � jour : ");
    scanf_s("%s", prenomAMettreAJour, sizeof(prenomAMettreAJour));

    int indexAMettreAJour = -1;

    // Recherche du contact � mettre � jour dans la base de donn�es
    for (int i = 0; i < nbContacts; i++) {
        if (strcmp(contacts[i].nom, nomAMettreAJour) == 0 && strcmp(contacts[i].prenom, prenomAMettreAJour) == 0) {
            indexAMettreAJour = i;
            break;
        }
    }

    if (indexAMettreAJour != -1) {
        // Demandez le nouveau num�ro de t�l�phone
        printf("Entrez le nouveau num�ro de t�l�phone : ");
        scanf_s("%s", contacts[indexAMettreAJour].numero, sizeof(contacts[indexAMettreAJour].numero));
        printf("Contact mis � jour avec succ�s.\n");
    }
    else {
        printf("Le contact n'a pas �t� trouv� dans la base de donn�es.\n");
    }
}


void mettreAJourProduct(struct Product products[], int nbProducts) {
    char nomAMettreAJou2r[50];
    char prenomAMettreAJou2r[50];

    printf("Entrez le type de produit � mettre � jour : ");
    scanf_s("%s", nomAMettreAJou2r, sizeof(nomAMettreAJou2r));
    printf("Entrez la couleur de produit � mettre � jour : ");
    scanf_s("%s", prenomAMettreAJou2r, sizeof(prenomAMettreAJou2r));

    int indexAMettreAJou2r = -1;

    // Recherche du contact � mettre � jour dans la base de donn�es
    for (int i = 0; i < nbProducts; i++) {
        if (strcmp(products[i].type, nomAMettreAJou2r) == 0 && strcmp(products[i].couleur, prenomAMettreAJou2r) == 0) {
            indexAMettreAJou2r = i;
            break;
        }
    }

    if (indexAMettreAJou2r != -1) {
        // Demandez le nouveau num�ro de t�l�phone
        printf("Entrez le nouveau taille : ");
        scanf_s("%s", products[indexAMettreAJou2r].taille, sizeof(products[indexAMettreAJou2r].taille));
        printf("Product mis � jour avec succ�s.\n");
    }
    else {
        printf("Le product n'a pas �t� trouv� dans la base de donn�es.\n");
    }
}

*/


// deux fonction update, OK
// FAIRE EN SORT COMME SI IL Y A DEUX BASE DE  DONN�ES : genre deux liste liste 1; BDD1 et liste2;BDD2.   (a analyser le code demain, essayer de trouver l'error.)
// on fait des droit pour rentrer ou pas dans une base de donn�e. OK
// organisation logique: 1. les droit( 3 sont droit complet, meduim, zero).      2.essayer de mettre une deuxieme couche de choisir le type de base de donn�e (bddA, bddB).OK 

