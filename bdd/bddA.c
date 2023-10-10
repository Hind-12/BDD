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
        scanf_s("%s", nouveauContact.nom, sizeof(nouveauContact.nom));
        printf("Entrez le prénom : ");
        scanf_s("%s", nouveauContact.prenom, sizeof(nouveauContact.prenom));
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


