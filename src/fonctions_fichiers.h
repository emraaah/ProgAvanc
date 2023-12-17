#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Alloue un tableau de caractere de taille n*m, qui correspond au ligne & colonne
char** allouer_tab_2D(int n, int m);

//Libère un tableau à 2 dimensions de n lignes
void desallouer_tab_2D(char** tab, int n);

//Affiche le contenu du tableau de taille n*m
void afficher_tab_2D(char** tab, int n, int m);

//Compte le nombre de ligne et colonne dont le nom du fichier est nomFichier
void taille_fichier(const char* nomFichier, int* nbLig, int* nbCol);

// Lire le fichier et retourne le tableau qui contient les caracteres du fichier
char** lire_fichier(const char* nomFichier);

//Retourne un nouveau tableau
char** modifier_caractere(char** tab, int n, int m, char ancien, char nouveau);

//Ecrit le tableau tab de taille n*m dans un fichier dont le nom est nomFichier
void ecrire_fichier(const char* nomFichier, char** tab, int n, int m);

