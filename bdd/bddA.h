#ifndef BDDA_H
#define BDD_H

struct Contact
{
    char nom[50];
    char prenom[50];
    char numero[15];
};
void ajouterContact(struct Contact contacts[], int* nbContacts);
void afficherContacts(struct Contact contacts[], int nbContacts);
void supprimerContact(struct Contact contacts[], int* nbContacts);

#endif BDDA_H

