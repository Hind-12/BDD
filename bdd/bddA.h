#ifndef BDDA_H
#define BDD_H

/*************** BEGIN ENUM ****************/
enum ACTION {
    LOGIN = 1,
    SIGNUP,
    EXIT
};

enum GESTION_MENU {
    GESTION_ETUDIANT = 1,
    GESTION_MATIERE,
    GESTION_NOTE,
    GESTION_SALLE
};

enum ACTION_ETUDIANT {
    AJOUTER_ETUDIANT = 1,
    MODIFIER_ETUDIANT = 2,
    SUPPRIMER_ETUDIANT = 3,
    RECHERCHER_ETUDIANT = 4,
    AFFICHER_TOUS_ETUDIANT = 5,
};

enum Niveau { 
    licence, 
    master 
};
/*************** END ENUM ****************/

/*************** BEGIN STRUCT ****************/
struct User {
    char name[50];
    char password[50];
};

struct Etudiant
{
    int num;
    char nom[100];
    char prenom[100];
    char email[100];
    char dateNaiss[100];
};

struct Note
{
    int numero;
    char matiere[100];
    char niveau[100];
    int note;
};

struct Matiere
{
    int references;
    char libelle[100];
    int coefficient;
};

struct Classe
{
    int code;
    char nom[100];
    enum Niveau niveau;
};
/*************** END STRUCT ****************/


/*------DEBUT FONCTION CONNEXION------*/
void startApp();
int  DisplayLoginMenu();
void signup(struct User *user);
void login(struct User *user);
/*------ FIN FONCTION CONNEXION ------*/


/*------DEBUT FONCTION ACTION------*/
void AjouterEtudiant();
int rech(int num);
void RechercherEtudiant();
void AfficherTousEtudiant();
void SupprimerEtudiant();
void ModifierEtudiant();

/*------ FIN FONCTION ACTION ------*/


/*------DEBUT FONCTION MENU------*/
void MenuAcceuil();
void MenuGestion();
void MenuEtudiant();
void MenuMatiere();
void MenuNote();
void MenuSalle();
/*------ FIN FONCTION MENU ------*/

#endif BDDA_H

