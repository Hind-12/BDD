#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bddA.h"

/*************** BEGIN FONCTIONS IMPLEMENTATION ***************/
void startApp() {
    enum ACTION item;
    struct User user;
    printf("****************************************************************** \n");
    printf("\n\n\n\n\n\n\n\n\n\n \t\t\t\t\t\t WELCOME TO STUDENT DATABASE \n\n");
    printf("******************************************************************");
    /*------------------------------------*/
    item = DisplayLoginMenu();
    /*------------------------------------*/
    switch (item) {
    case LOGIN:
        login(&user);
        break;
    case SIGNUP:
        signup(&user);
        break;
    case EXIT:
        exitApp();
        break;
    default:
        printf("Erreur !!! \n");

    }

};

void exitApp() {
    return;
}

int DisplayLoginMenu() {
    int item;

    do {
        printf("\t\t\t [1]. Login\n");
        printf("\t\t\t [2]. Signup\n");
        printf("\t\t\t [3]. Exit\n\n");
        printf("\t\t\t Enter your choice (1,2 and 3): ");
        scanf_s("%d", &item);

        if (item != 1 && item != 2 && item != 3) {
            printf("\t\t\t Invalid option. Please select 1, 2 and 3. \n\n");
        }

    } while (!(item == 1 || item == 2 || item == 3));

    return item;
}

void signup(struct User* user) {
    // printf("************************************");
    printf("\n\n \t\t\t Welcome to signup page\n\n");
    //printf("************************************");
    const char* FILENAME = "./DB_FILE/User.txt";
    FILE* F = fopen(FILENAME, "a+");

    if (F == NULL) {
        printf("\t\t\t Error: Cannot open User.txt for writing.\n");
        return;
    }

    printf("\t\t\t [1]. Enter your name: ");
    scanf("%s", user->name);
    printf("\t\t\t [2]. Enter your password: ");
    scanf("%s", user->password);
    fprintf(F, "%s %s\n", user->name, user->password);
    printf("\t\t\t User created successfull \n");
    fclose(F);

    /*-----------------LOG SIGNUP-------------------*/
    //printf("Name : %s\n", user->name);
    //printf("Password : %s\n", user->password);
    //printf("Signup  ok \n");
    /*------------------------------------*/
}

void login(struct User* user) {
    char username[50], password[50];
    printf("************************************");
    printf("\n \t\t\t Welcome to login page\n\n");
    printf("************************************");
    const char* FILENAME = "./DB_FILE/User.txt";
    FILE* F = fopen(FILENAME, "a+");

    printf("\t\t\t [1]. Enter your name: ");
    scanf_s("%s", user->name, (sizeof user->name));
    printf("\t\t\t [2]. Enter your password: ");
    scanf_s("%s", user->password, sizeof(user->password));

    int authentifier = 0;

    while (fscanf(F, "%s %s", username, password) == 2) {
        if (strcmp(username, user->name) == 0 && strcmp(password, user->password) == 0) {
            authentifier = 1;
            break;
        }
    }

    if (authentifier) {
        int item;
        printf("\n\n \t\t\t Authentication successful, welcome %s \n\n", user->name);
        printf("\t\t\t [1]. GESTION DES ETUDIANTS\n");
        printf("\t\t\t [2]. GESTION DES NOTES\n");
        printf("\t\t\t [3]. Exit\n\n");
        scanf("%d", &item);
    }
    else {
        printf("\n\n \t\t\t user don't exitxit or password incorrect \n\n");
    }

    fclose(F);

    /*----------------LOG LOGIN --------------------*/
    //printf("Name : %s\n", user->name);
    //printf("Password : %s\n", user->password);
    //printf("Login ok \n");
    /*------------------------------------*/
}

/*************** END FONCTION IMPLEMENTATION ****************/


// Fonction pour ajouter un contact à la base de données
 /*void ajouterContact(struct Contact contacts[], int* nbContacts) {
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




}  */


// deux fonction update,
// FAIRE EN SORT COMME SI IL Y A DEUX BASE DE  DONNéES : genre deux liste liste 1; BDD1 et liste2;BDD2.
// on fait des droit pour rentrer ou pas dans une base de donnée. 

