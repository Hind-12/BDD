#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bddA.h"

/*************** BEGIN FONCTIONS IMPLEMENTATION ***************/
void startApp() {
    printf("\n\n\n\n\n\n \t\t\t\t ******************************************************************");
    printf("\n\n \t\t\t\t\t\t WELCOME TO STUDENT DATABASE APP \n\n");
    printf("\t\t\t\t ****************************************************************** \n\n\n\n");
    MenuAcceuil();
};

int DisplayLoginMenu() {
    int item;

    do {
        printf("\t\t\t [1]. Login\n");
        printf("\t\t\t [2]. Signup\n");
        printf("\t\t\t [3]. Exit\n\n");
        printf("\t\t\t Enter your choice between (1,2 and 3): ");
        scanf_s("%d", &item);

        if (item != 1 && item != 2 && item != 3) {
            printf("\n\n \t\t\t Invalid option. Please select 1, 2 and 3. \n\n");
        }

    } while (!(item == 1 || item == 2 || item == 3));

    return item;
}

void signup(struct User *user) {
    struct User userCreated;
   // printf("************************************");
    printf("\n \t\t\t\t\t\t Welcome to signup page \n\n");
    //printf("************************************");
    const char *FILENAME = "./DB_FILE/User.txt";
    FILE *F = fopen(FILENAME, "a+");

    if (F == NULL) {
        printf("\t\t\t Error: Cannot open User.txt for writing.\n");
        return;
    }

    printf("\t\t\t [1]. Enter your name: ");
    scanf("%s", user->name);
    printf("\t\t\t [2]. Enter your password: ");
    scanf("%s", user->password);
    fprintf(F, "%s %s\n", user->name, user->password);
    printf("\n\n \t\t\t ---- User created successfull --- \n");
    fclose(F);
    login(&userCreated);

    /*-----------------LOG SIGNUP-------------------*/
    //printf("Name : %s\n", user->name);
    //printf("Password : %s\n", user->password);
    //printf("Signup  ok \n");
    /*------------------------------------*/
}

void login(struct User *user) {
    char username[50], password[50];
    printf("\n \t\t\t\t\t\t ********* Welcome to login page ********* \n\n");
    const char* FILENAME = "./DB_FILE/User.txt";
    FILE* F = fopen(FILENAME, "a+");

    /* printf("\t\t\t [1]. Enter your name: ");
    scanf_s("%s", user->name, (sizeof user->name));
    printf("\t\t\t [2]. Enter your password: ");
    scanf_s("%s", user->password, sizeof(user->password));*/
   

    int authentifier = 0;

    do {
        printf("\t\t\t [1]. Enter your name: ");
        scanf_s("%s", user->name, (sizeof user->name));
        printf("\t\t\t [2]. Enter your password: ");
        scanf_s("%s", user->password, sizeof(user->password));

        rewind(F);

        while (fscanf(F, "%s %s", username, password) == 2) {
            if (strcmp(username, user->name) == 0 && strcmp(password, user->password) == 0) {
                authentifier = 1;
                break;
            }
        }

        if (authentifier) {
            printf("\n\n \t\t\t --- Authentication successful, welcome %s --- \n\n", user->name);
            fclose(F);
            MenuGestion();
        }else {
            printf("\n\n \t\t\t user doesn't exit or password incorrect \n\n");
        }

    } while (!authentifier);

    /*----------------LOG LOGIN --------------------*/
    //printf("Name : %s\n", user->name);
    //printf("Password : %s\n", user->password);
    //printf("Login ok \n");
    /*------------------------------------*/
}

void MenuAcceuil() {
    enum ACTION item;
    struct User user;
    item = DisplayLoginMenu();
    switch (item) {
    case LOGIN:
        login(&user);
        break;
    case SIGNUP:
        signup(&user);
        break;
    case EXIT:
        exit(1);
        break;
    default:
        printf("Erreur !!! \n");

    }
};

void MenuGestion() {
    int item;
    do {
        printf("\n\n \t\t\t ********** GESTION ********** \n\n");
        printf("\t\t\t [1]. GESTION DES ETUDIANTS\n");
        printf("\t\t\t [2]. GESTION DES MATIERES\n");
        printf("\t\t\t [3]. GESTION DES NOTES\n");
        printf("\t\t\t [4]. GESTION DES SALLES\n");
        printf("\t\t\t [5]. QUITER\n\n");
        printf("\t\t\t Entrer votre choix: ");
        scanf("%d", &item);
    } while (item < 1 || item > 5);
   
    if (item == 5) {
        MenuAcceuil();
    }
    switch (item) {
    case GESTION_ETUDIANT:
        MenuEtudiant();
        break;
    case GESTION_MATIERE:
        MenuMatiere();
        break;
    case GESTION_NOTE:
        MenuNote();
        break;
    case GESTION_SALLE:
        MenuSalle();
        break;
    default:
        printf("Erreur !!! \n");

    }
};

void MenuEtudiant() {
    enum ACTION_ETUDIANT item;
    do {
        printf("\n\n \t\t\t ********** Bienvenu sur le menu etudiant **********\n\n");
        printf("\t\t\t [1]. Ajouter un etudiant\n");
        printf("\t\t\t [2]. Modifier un etudiant\n");
        printf("\t\t\t [3]. Supprimer un etudiant\n");
        printf("\t\t\t [4]. Rechercher un etudiant \n");
        printf("\t\t\t [5]. Afficher tous etudiants \n");
        printf("\t\t\t [6]. Retour\n\n");
        printf("\t\t\t Entrer votre choix: ");
        scanf("%d", &item);
    } while (item < 1 ||  item > 6);
    
    if (item == 6) {
        MenuGestion();
    };
    
    switch (item) {
    case AJOUTER_ETUDIANT:
        AjouterEtudiant();
        break;
    case RECHERCHER_ETUDIANT:
        RechercherEtudiant();
        break;
    case AFFICHER_TOUS_ETUDIANT:
        AfficherTousEtudiant(); 
        break;
    case SUPPRIMER_ETUDIANT:
        SupprimerEtudiant(); 
            break;
    case MODIFIER_ETUDIANT:
        ModifierEtudiant();
        break;
    default:
        printf("Erreur !!! \n");

    }
};

void MenuMatiere() {
    int item;
    printf("\n\n \t\t\t ********** Bienvenu sur le menu matiere **********\n\n");
    printf("\t\t\t [1]. Ajouter une matiere\n");
    printf("\t\t\t [2]. Modifier une matiere\n");
    printf("\t\t\t [3]. Supprimer une matiere\n");
    printf("\t\t\t [4]. Rechercher une matiere \n");
    printf("\t\t\t [5]. Retour\n\n");
    printf("\t\t\t Entrer votre choix: ");
    scanf("%d", &item);
};

void MenuNote(){
    int item;
    printf("\n\n \t\t\t ********** Bienvenu sur le menu note **********\n\n");
    printf("\t\t\t [1]. Ajouter une note\n");
    printf("\t\t\t [2]. Modifier une note\n");
    printf("\t\t\t [3]. Supprimer une note\n");
    printf("\t\t\t [4]. Rechercher une note \n");
    printf("\t\t\t [5]. Retour\n\n");
    printf("\t\t\t Entrer votre choix: ");
    scanf("%d", &item);
};

void MenuSalle() {
    int item;
    printf("\n\n \t\t\t ********** Bienvenu sur le menu salle **********\n\n");
    printf("\t\t\t [1]. Ajouter une salle\n");
    printf("\t\t\t [2]. Modifier une salle\n");
    printf("\t\t\t [3]. SUpprimer une salle\n");
    printf("\t\t\t [4]. Rechercher une salle \n");
    printf("\t\t\t [5]. Retour\n\n");
    printf("\t\t\t Entrer votre choix: ");
    scanf("%d", &item);
};

void AjouterEtudiant()
{
    struct Etudiant Etud;
    FILE* F;
    int num;
    const char* FILENAME = "./DB_FILE/Etudiant.txt";
    F = fopen(FILENAME, "a+");
    printf("\n \t\t\t Entrer le numero du nouveau etudiant: ");
    scanf("%d", &num);
    fflush(stdin);
    while (rech(num) == 1)
    {
        printf("\n \t\t\t Ce numero existe deja: ");
        printf("\n \t\t\t Entrer le numero du nouveau  etudiant: ");
        scanf("%d", &num);
    }
    Etud.num = num;
    printf("\t\t\t Entrer le Nom :");
    scanf("%s", Etud.nom);
    printf("\t\t\t Entrer le Prenom:");
    scanf("%s", Etud.prenom);
    printf("\t\t\t Entrer votre email:");
    scanf("%s", Etud.email);
    printf("\t\t\t Entrer votre date de naissance:");
    scanf("%s", Etud.dateNaiss);
    fprintf(F, "%d %s %s %s %s\n", Etud.num, Etud.nom, Etud.prenom, Etud.email, Etud.dateNaiss);
    printf("\n\n \t\t\t ------- Etudiant ajoute avec succes ------- \n\n");
    fclose(F);
    MenuEtudiant();
}

void RechercherEtudiant()
{
    struct Etudiant Etud;
    int NumR;
    printf("\n \t\t\t Entrer le numero d'etudiant a rechercher: ");
    scanf("%d", &NumR);
    FILE* F;
    const char* FILENAME = "./DB_FILE/Etudiant.txt";
    F = fopen(FILENAME, "a+");
    do
    {
        fscanf(F, "%d %s %s %s %s\n", &Etud.num, Etud.nom, Etud.prenom, Etud.email, Etud.dateNaiss);
        //printf("\t\t\t Numero\t: %d \n", Etud.num);
            if (NumR == Etud.num)
            {
                printf("\t\t\t --------Information Sur l'Etudiant ----------- \n \n");
                printf("\t\t\t Numero: %d \n", Etud.num);
                printf("\t\t\t Nom: %s \n", Etud.nom);
                printf("\t\t\t Prenom: %s \n", Etud.prenom);
                printf("\t\t\t email: %s \n", Etud.email);
                printf("\t\t\t date de naissance: %s \n", Etud.dateNaiss);
            }
        
    } while (!feof(F));
    fclose(F);
    MenuEtudiant();
}


/*------Afficher la liste des etudiants ------*/
void AfficherTousEtudiant()
{
    struct Etudiant Etud;
    FILE* F;
    const char* FILENAME = "./DB_FILE/Etudiant.txt";
    F = fopen(FILENAME, "r");
    if (F == NULL)
    {
        printf("\t\t\t Error: Cannot open Etudiant.txt for writing.\n");
        return;
    }

    printf("\n\n \t\t\t  *************** Liste des Etudiants *************** \n\n");
    printf("\t\t\t Numero \t Nom \t Prenom \t Email \t Date de Naissance\n");

    while (fscanf(F, "%d %s %s %s %s", &Etud.num, Etud.nom, Etud.prenom, Etud.email, Etud.dateNaiss) == 5)
    {
        printf("\t\t\t\ %d \t %s \t %s \t %s \t %s\n", Etud.num, Etud.nom, Etud.prenom, Etud.email, Etud.dateNaiss);
    }

    fclose(F);
    MenuEtudiant();
}

/*------Fonction de recherche pour check un étudiant ------*/

int rech(int Numrech)
{
    struct Etudiant Etud;
    FILE* F;
    const char* FILENAME = "./DB_FILE/Etudiant.txt";
    F = fopen(FILENAME, "a+");
    do
    {
        fscanf(F, "%d %s %s %s %s\n", &Etud.num, Etud.nom, Etud.prenom, Etud.email, Etud.dateNaiss);
        fflush(stdin);
        if (Etud.num == Numrech)
        {
            fclose(F);
            return 1;
        }
    } while (!feof(F));
    fclose(F);
    return -1;
}

void SupprimerEtudiant()
{
    char rep;
    int NumRech;
    struct Etudiant Etud;

    printf("\n\t\t\t Entrez le numero etudiant a supprimer : ");
    scanf("%d", &NumRech);
    fflush(stdin);

    if (rech(NumRech) == 1)
    {
        printf("\n\t\t\t Voulez-vous vraiment supprimer, entrez o/n : ");
        scanf(" %c", &rep);  // Agregué un espacio antes de %c para consumir el carácter de nueva línea anterior.
        fflush(stdin);

        if (rep == 'o' || rep == 'O')
        {
            FILE* FC, * F;
            const char* FILENAME = "./DB_FILE/Etudiant.txt";
            const char* FILENAME_COPY = "./DB_FILE/TempEtudiant.txt";
            F = fopen(FILENAME, "r"); 
            if (F == NULL)
            {
                printf("\n\t\t\t Erreur lors de lecture du fichier");
                return;
            }

            FC = fopen(FILENAME_COPY, "w"); 

            if (FC == NULL)
            {
                fclose(F);
                printf("\n\t\t\t Erreur lors de la creation du fichier temporaire");
                return;
            }

            while (fscanf(F, "%d %s %s %s %s", &Etud.num, Etud.nom, Etud.prenom, Etud.email, Etud.dateNaiss) == 5)
            {
                if (NumRech != Etud.num)
                {
                    fprintf(FC, "%d %s %s %s %s\n", Etud.num, Etud.nom, Etud.prenom, Etud.email, Etud.dateNaiss);
                }
            }

            fclose(FC);
            fclose(F);
            remove(FILENAME);
            rename(FILENAME_COPY, FILENAME);
            printf("\n\n\t\t\t -------------- Suppression reussie --------------");
            MenuEtudiant();
        }
        else
        {
            printf("\n\n\t\t\t -------------- Erreur lors de la suppression --------------");
        }
    }
    else
    {
        printf("\n\t\t\t -------------- Ce numero etudiant existe pas --------------");
    }
}


void ModifierEtudiant()
{
    struct Etudiant Etud;
    int num;
    char rep = 'n';

    printf("\n\t\t\t Entrez le numero etudiant a modifier: ");
    scanf("%d", &num);

    if (rech(num) == 1)
    {
        printf("\n\t\t\t Voulez-vous vraiment modifier, entrer o/n: ");
        scanf(" %c", &rep);

        if (rep == 'o' || rep == 'O')
        {
            FILE* FC, * F;
            const char* FILENAME = "./DB_FILE/Etudiant.txt";
            const char* FILENAME_COPY = "./DB_FILE/TempEtudiant.txt";
            F = fopen(FILENAME, "r"); 

            if (F == NULL)
            {
                printf("\n\t\t\t Error lors de l'ouverture du fichier");
                return;
            }

            FC = fopen(FILENAME_COPY, "w");
            if (FC == NULL)
            {
                fclose(F);
                printf("\n\t\t\t Erreur lors de la création du fichier temporaire");
                return;
            }

            while (fscanf(F, "%d %s %s %s %s", &Etud.num, Etud.nom, Etud.prenom, Etud.email, Etud.dateNaiss) == 5)
            {
                if (num == Etud.num)
                {
                    Etud.num = num;
                    printf("\t\t\t Entrer le Nom :");
                    scanf("%s", Etud.nom);
                    printf("\t\t\t Entrer le Prenom:");
                    scanf("%s", Etud.prenom);
                    printf("\t\t\t Entrer votre email:");
                    scanf("%s", Etud.email);
                    printf("\t\t\t Entrer votre date de naissance:");
                    scanf("%s", Etud.dateNaiss);
                }

                fprintf(FC, "%d %s %s %s %s\n", Etud.num, Etud.nom, Etud.prenom, Etud.email, Etud.dateNaiss);
            }

            fclose(FC);
            fclose(F);
            remove(FILENAME);
            rename(FILENAME_COPY, FILENAME);
            printf("\n\n\t\t\t -------------- Modification reussie --------------");
            MenuEtudiant();
        }
        else
        {
            printf("\n\n\t\t\t -------------- Modification annulée --------------");
        }
    }
    else
    {
        printf("\n\n\t\t\t -------------- Ce numéro n'existe pas --------------");
    }
}


/*************** END FONCTION IMPLEMENTATION ****************/