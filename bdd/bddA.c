#include <stdio.h>




// Structure de donn�es pour un contact
struct Contact {
    char nom[50];
    char prenom[50];
    char numero[15];
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


