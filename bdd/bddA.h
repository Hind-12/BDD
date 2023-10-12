#ifndef BDDA_H
#define BDD_H
#define DROIT_COMPLET 1
#define DROIT_LIMITÉ 2
#define AUCUN_DROIT 0


struct Element {
    int type;  // 1 pour contact, 2 pour produit
    char nom[50];
    char prenom[50];
    char numero[15];
    char typeProduit[50];
    char couleur[50];
    char taille[15];
};


void ajouterElement(struct Element elements[], int* nbElements);
void supprimerElement(struct Element elements[], int* nbElements);
void afficherElements(struct Element elements[], int nbElements);


/*
struct Contact
{
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
void ajouterContact(struct Contact contacts[], int* nbContacts);
void afficherContacts(struct Contact contacts[], int nbContacts);
void supprimerContact(struct Contact contacts[], int* nbContacts);
void mettreAJourContact(struct Contact contacts[], int nbContacts);
void ajouterProduct(struct Product products[], int* nbProducts);
void afficherProducts(struct Product products[], int nbProducts);
void supprimerProduct(struct Product products[], int* nbProducts);
void mettreAJourProduct(struct Product products[], int nbProducts);

*/




#endif BDDA_H

