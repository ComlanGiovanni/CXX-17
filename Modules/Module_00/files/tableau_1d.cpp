#include <iostream>
#include <climits>  // Pour INT_MIN, INT_MAX

int main() {
    // Déclaration et initialisation d'un tableau d'entiers
    int tableau[] = {8, 4, 12, 16, 5, 9, 7, 11};
    int taille = sizeof(tableau) / sizeof(tableau[0]);

    std::cout << "Tableau: ";
    for (int i = 0; i < taille; i++) {
        std::cout << tableau[i];
        if (i < taille - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;

    // Calcul de la somme
    int somme = 0;
    for (int i = 0; i < taille; i++) {
        somme += tableau[i];
    }

    // Calcul de la moyenne
    double moyenne = static_cast<double>(somme) / taille;

    // Recherche du minimum et du maximum
    int minimum = INT_MAX;
    int maximum = INT_MIN;

    for (int i = 0; i < taille; i++) {
        if (tableau[i] < minimum) {
            minimum = tableau[i];
        }
        if (tableau[i] > maximum) {
            maximum = tableau[i];
        }
    }

    // Affichage des résultats
    std::cout << "Somme: " << somme << std::endl;
    std::cout << "Moyenne: " << moyenne << std::endl;
    std::cout << "Minimum: " << minimum << std::endl;
    std::cout << "Maximum: " << maximum << std::endl;

    // Recherche d'un élément spécifique
    int elementRecherche;
    std::cout << "\nEntrez un élément à rechercher: ";
    std::cin >> elementRecherche;

    bool trouve = false;
    int position = -1;

    for (int i = 0; i < taille; i++) {
        if (tableau[i] == elementRecherche) {
            trouve = true;
            position = i;
            break;
        }
    }

    if (trouve) {
        std::cout << "L'élément " << elementRecherche << " a été trouvé à la position " << position << std::endl;
    } else {
        std::cout << "L'élément " << elementRecherche << " n'a pas été trouvé dans le tableau." << std::endl;
    }

    return 0;
}
