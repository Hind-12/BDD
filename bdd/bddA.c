#include <stdio.h>




// Structure de données pour un contact
struct Contact {
    char nom[50];
    char prenom[50];
    char numero[15];
};


/*void createTable(char tableName) {

}*/

// Fonction pour ajouter un contact à la base de données
void ajouterContact(struct Contact contacts[], int* nbContacts) {
    if (*nbContacts < 100) {
        struct Contact nouveauContact;
        printf("Entrez le nom : ");
        scanf_s("%s", nouveauContact.nom, sizeof(nouveauContact.nom));
        printf("Entrez le prenom : ");
        scanf_s("%s", nouveauContact.prenom, sizeof(nouveauContact.prenom));
        printf("Entrez le numéro de telephone : ");
        scanf_s("%s", nouveauContact.numero, sizeof(nouveauContact.numero));

        contacts[*nbContacts] = nouveauContact;
        (*nbContacts)++;

        printf("Contact ajoute avec succes.\n");
    }
    else {
        printf("La base de donnees est pleine. Supprimez des contacts pour en ajouter de nouveaux.\n");
    }
}

// Fonction pour afficher tous les contacts
void afficherContacts(struct Contact contacts[], int nbContacts) {
    printf("Liste des contacts :\n");
    for (int i = 0; i < nbContacts; i++) {
        printf("Nom : %s\n", contacts[i].nom);
        printf("Prenom : %s\n", contacts[i].prenom);
        printf("Numero de telephone : %s\n", contacts[i].numero);
        printf("----------------------\n");
    }
}

// Fonction pour supprimer un contact de la base de données
void supprimerContact(struct Contact contacts[], int* nbContacts) {
    char numDel[50];

    printf("Entrez le numero du contact a supprimer : ");
    scanf_s("%s", numDel, sizeof(numDel));

    int index = -1;

    // Recherche du contact à supprimer dans la base de données
    for (int i = 0; i < *nbContacts; i++) {
        if (strcmp(contacts[i].numero, numDel) == 0) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        // Déplacer les contacts suivants vers l'arrière pour remplir l'emplacement supprimé
        for (int i = index; i < *nbContacts - 1; i++) {
            contacts[i] = contacts[i + 1];
        }
        (*nbContacts)--;
        printf("Contact supprime avec succes.\n");
    }
    else {
        printf("Contact introuvable dans la base de donnees.\n");
    }
}


// Fonction pour mettre à jour un contact dans la base de données
void mettreAJourContact(struct Contact contacts[], int nbContacts) {
    char numUpdated[50];

    printf("Entrez le numero du contact a mettre a jour : ");
    scanf_s("%s", numUpdated, sizeof(numUpdated));

    int index = -1;

    // Recherche du contact à mettre à jour dans la base de données
    for (int i = 0; i < nbContacts; i++) {
        if (strcmp(contacts[i].numero, numUpdated) == 0) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        // Demandez le nouveau numéro de téléphone
        printf("Entrez le nouveau  nom : ");
        scanf_s("%s", contacts[index].nom, sizeof(contacts[index].nom));
        printf("Entrez le nouveau prenom : ");
        scanf_s("%s", contacts[index].prenom, sizeof(contacts[index].prenom));
        printf("Contact mis a jour avec succes.\n");
    }
    else {
        printf("Le contact n'a pas ete trouve dans la base de donnees.\n");
    }

   /*
   
    */ 
}


// deux fonction update,
// FAIRE EN SORT COMME SI IL Y A DEUX BASE DE  DONNéES : genre deux liste liste 1; BDD1 et liste2;BDD2.
// on fait des droit pour rentrer ou pas dans une base de donnée. 

