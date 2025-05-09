#include <iostream>
#include <iomanip>  // Pour std::setw

int main() {
    // Définition d'une matrice 3x3
    int matrice[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Affichage de la matrice
    std::cout << "Matrice 3x3:" << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << std::setw(4) << matrice[i][j];
        }
        std::cout << std::endl;
    }

    // Calcul de la somme de chaque ligne
    int sommeLignes[3] = {0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sommeLignes[i] += matrice[i][j];
        }
    }

    // Calcul de la somme de chaque colonne
    int sommeColonnes[3] = {0};
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 3; i++) {
            sommeColonnes[j] += matrice[i][j];
        }
    }

    // Affichage des sommes
    std::cout << "\nSomme des lignes:" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << "Ligne " << i + 1 << ": " << sommeLignes[i] << std::endl;
    }

    std::cout << "\nSomme des colonnes:" << std::endl;
    for (int j = 0; j < 3; j++) {
        std::cout << "Colonne " << j + 1 << ": " << sommeColonnes[j] << std::endl;
    }

    // Affichage de la matrice sous forme de tableau avec les sommes
    std::cout << "\nTableau avec sommes:" << std::endl;
    std::cout << "+------+------+------+-------+" << std::endl;
    std::cout << "|      |   1  |   2  |   3   | Somme |" << std::endl;
    std::cout << "+------+------+------+-------+" << std::endl;

    for (int i = 0; i < 3; i++) {
        std::cout << "|   " << i + 1 << "  |";
        for (int j = 0; j < 3; j++) {
            std::cout << std::setw(4) << matrice[i][j] << "  |";
        }
        std::cout << std::setw(5) << sommeLignes[i] << " |" << std::endl;
    }

    std::cout << "+------+------+------+-------+" << std::endl;
    std::cout << "| Somme|";
    for (int j = 0; j < 3; j++) {
        std::cout << std::setw(4) << sommeColonnes[j] << "  |";
    }

    // Calcul de la somme totale
    int sommeTotal = 0;
    for (int i = 0; i < 3; i++) {
        sommeTotal += sommeLignes[i];
    }

    std::cout << std::setw(5) << sommeTotal << " |" << std::endl;
    std::cout << "+------+------+------+-------+" << std::endl;

    return 0;
}
