#include <iostream>
#include <limits>

int main() {
    int taille;

    // Demande la taille du tableau à l'utilisateur
    std::cout << "Entrez la taille du tableau: ";
    std::cin >> taille;

    // Vérifie que la taille est valide
    if (taille <= 0) {
        std::cout << "La taille doit être un entier positif." << std::endl;
        return 1;
    }

    // Allocation dynamique du tableau
    int* tableau = new int[taille];

    // Remplissage du tableau avec des valeurs saisies par l'utilisateur
    std::cout << "Entrez " << taille << " valeurs entières:" << std::endl;

    for (int i = 0; i < taille; ++i) {
        std::cout << "Élément " << i + 1 << ": ";
        std::cin >> tableau[i];

        // En cas d'erreur de saisie, réinitialise le flux et redemande
        if (std::cin.fail()) {
            std::cin.clear();  // Réinitialise l'état du flux
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Vide le tampon
            std::cout << "Entrée invalide. Veuillez entrer un nombre entier." << std::endl;
            --i;  // Pour refaire la saisie du même élément
        }
    }

    // Calcul de la somme
    int somme = 0;
    for (int i = 0; i < taille; ++i) {
        somme += tableau[i];
    }

    // Calcul de la moyenne
    double moyenne = static_cast<double>(somme) / taille;

    // Recherche du minimum et du maximum
    int minimum = tableau[0];
    int maximum = tableau[0];

    for (int i = 1; i < taille; ++i) {
        if (tableau[i] < minimum) {
            minimum = tableau[i];
        }
        if (tableau[i] > maximum) {
            maximum = tableau[i];
        }
    }

    // Affichage des résultats
    std::cout << "\nStatistiques:" << std::endl;
    std::cout << "Somme: " << somme << std::endl;
    std::cout << "Moyenne: " << moyenne << std::endl;
    std::cout << "Minimum: " << minimum << std::endl;
    std::cout << "Maximum: " << maximum << std::endl;

    // Libération de la mémoire
    delete[] tableau;
    std::cout << "\nLa mémoire a été libérée." << std::endl;

    return 0;
}
