#include "fonctions_fichiers.h"

char** allouer_tab_2D(int n, int m) {
    char** tab = (char**)malloc(n * sizeof(char*));
    if (tab == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire pour les lignes du tableau\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) {
        tab[i] = (char*)malloc(m * sizeof(char));
        if (tab[i] == NULL) {
            fprintf(stderr, "Erreur d'allocation de mémoire pour les colonnes du tableau\n");
            exit(EXIT_FAILURE);
        }

        for (int j = 0; j < m; j++) {
            tab[i][j] = ' ';
        }
    }

    return tab;
}

void desallouer_tab_2D(char** tab, int n) {
    for (int i = 0; i < n; i++) {
        free(tab[i]);
    }
    free(tab);
}

void afficher_tab_2D(char** tab, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c ", tab[i][j]);
        }
        printf("\n");
    }
}

void taille_fichier(const char* nomFichier, int* nbLig, int* nbCol) {
    char taille[2000];

    int ligne = 0;
    int colonne = 0;
    int compter = 0;

    FILE* file = fopen(nomFichier, "r");

    if (file == NULL) {
        printf("Entrer un nom de fichier valide !\n");
    } else {
        while (fgets(taille, sizeof taille, file) != NULL) {
            compter = strlen(taille);
            if (compter > colonne) {
                colonne = compter;
            }
            ligne++;
        }

        *nbCol = colonne - 1;
        *nbLig = ligne;
    }

    fclose(file);
}

char** lire_fichier(const char* nomFichier) {
    int nbLig, nbCol;
    taille_fichier(nomFichier, &nbLig, &nbCol);

    FILE* fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        fprintf(stderr, "Erreur d'ouverture du fichier %s\n", nomFichier);
        exit(EXIT_FAILURE);
    }

    char** tab = allouer_tab_2D(nbLig, nbCol);

    for (int i = 0; i < nbLig; i++) {
        for (int j = 0; j < nbCol; j++) {
            int c = fgetc(fichier);
            if (c != EOF && c != '\n') {
                tab[i][j] = (char)c;
            }
        }
    }

    fclose(fichier);
    return tab;
}

char** modifier_caractere(char** tab, int n, int m, char ancien, char nouveau) {
    char** nouveauTab = allouer_tab_2D(n, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            nouveauTab[i][j] = (tab[i][j] == ancien) ? nouveau : tab[i][j];
        }
    }

    return nouveauTab;
}

void ecrire_fichier(const char* nomFichier, char** tab, int n, int m) {
    FILE* fichier = fopen(nomFichier, "w");
    if (fichier == NULL) {
        fprintf(stderr, "Erreur d'ouverture du fichier %s\n", nomFichier);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fputc(tab[i][j], fichier);
        }
        fputc('\n', fichier);
    }

    fclose(fichier);
}
