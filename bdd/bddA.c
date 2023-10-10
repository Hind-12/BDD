#include <stdio.h>




// Structure de données pour un contact
struct Contact {
    char nom[50];
    char prenom[50];
    char numero[15];
};

// Fonction pour ajouter un contact à la base de données
void ajouterContact(struct Contact contacts[], int* nbContacts) {
    if (*nbContacts < 100) {
        struct Contact nouveauContact;
        printf("Entrez le nom : ");
        scanf_s("%s", nouveauContact.nom, sizeof(nouveauContact.numero));
        printf("Entrez le prénom : ");
        scanf_s("%s", nouveauContact.prenom, sizeof(nouveauContact.numero));
        printf("Entrez le numéro de téléphone : ");
        scanf_s("%s", nouveauContact.numero, sizeof(nouveauContact.numero));

        contacts[*nbContacts] = nouveauContact;
        (*nbContacts)++;

        printf("Contact ajouté avec succès.\n");
    }
    else {
        printf("La base de données est pleine. Supprimez des contacts pour en ajouter de nouveaux.\n");
    }
}

// Fonction pour afficher tous les contacts
void afficherContacts(struct Contact contacts[], int nbContacts) {
    printf("Liste des contacts :\n");
    for (int i = 0; i < nbContacts; i++) {
        printf("Nom : %s\n", contacts[i].nom);
        printf("Prénom : %s\n", contacts[i].prenom);
        printf("Numéro de téléphone : %s\n", contacts[i].numero);
        printf("----------------------\n");
    }
}

// Fonction pour supprimer un contact de la base de données
void supprimerContact(struct Contact contacts[], int* nbContacts) {
    char nomASupprimer[50];
    char prenomASupprimer[50];

    printf("Entrez le nom du contact à supprimer : ");
    scanf_s("%s", nomASupprimer, sizeof(nomASupprimer));
    printf("Entrez le prénom du contact à supprimer : ");
    scanf_s("%s", prenomASupprimer, sizeof(prenomASupprimer));

    int indexASupprimer = -1;

    // Recherche du contact à supprimer dans la base de données
    for (int i = 0; i < *nbContacts; i++) {
        if (strcmp(contacts[i].nom, nomASupprimer) == 0 && strcmp(contacts[i].prenom, prenomASupprimer) == 0) {
            indexASupprimer = i;
            break;
        }
    }

    if (indexASupprimer != -1) {
        // Déplacer les contacts suivants vers l'arrière pour remplir l'emplacement supprimé
        for (int i = indexASupprimer; i < *nbContacts - 1; i++) {
            contacts[i] = contacts[i + 1];
        }
        (*nbContacts)--;
        printf("Contact supprimé avec succès.\n");
    }
    else {
        printf("Le contact n'a pas été trouvé dans la base de données.\n");
    }
}


// Fonction pour mettre à jour un contact dans la base de données
void mettreAJourContact(struct Contact contacts[], int nbContacts) {
    char nomAMettreAJour[50];
    char prenomAMettreAJour[50];

    printf("Entrez le nom du contact à mettre à jour : ");
    scanf_s("%s", nomAMettreAJour, sizeof(nomAMettreAJour));
    printf("Entrez le prénom du contact à mettre à jour : ");
    scanf_s("%s", prenomAMettreAJour, sizeof(prenomAMettreAJour));

    int indexAMettreAJour = -1;

    // Recherche du contact à mettre à jour dans la base de données
    for (int i = 0; i < nbContacts; i++) {
        if (strcmp(contacts[i].nom, nomAMettreAJour) == 0 && strcmp(contacts[i].prenom, prenomAMettreAJour) == 0) {
            indexAMettreAJour = i;
            break;
        }
    }

    if (indexAMettreAJour != -1) {
        // Demandez le nouveau numéro de téléphone
        printf("Entrez le nouveau numéro de téléphone : ");
        scanf_s("%s", contacts[indexAMettreAJour].numero, sizeof(contacts[indexAMettreAJour].numero));
        printf("Contact mis à jour avec succès.\n");
    }
    else {
        printf("Le contact n'a pas été trouvé dans la base de données.\n");
    }
}


// deux fonction update,
// FAIRE EN SORT COMME SI IL Y A DEUX BASE DE  DONNéES : genre deux liste liste 1; BDD1 et liste2;BDD2.
// on fait des droit pour rentrer ou pas dans une base de donnée. 

