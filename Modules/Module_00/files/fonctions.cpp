#include <iostream>

// Fonction qui calcule le carré d'un nombre
double carre(double x) {
    return x * x;
}

// Fonction qui calcule le cube d'un nombre
double cube(double x) {
    return x * x * x;
}

// Fonction qui calcule la puissance n d'un nombre
double puissance(double base, int exposant) {
    if (exposant == 0) {
        return 1;
    }

    double resultat = 1.0;
    bool exposantNegatif = exposant < 0;

    // Convertit l'exposant négatif en positif pour le calcul
    if (exposantNegatif) {
        exposant = -exposant;
    }

    // Calcule la puissance avec un exposant positif
    for (int i = 0; i < exposant; i++) {
        resultat *= base;
    }

    // Si l'exposant était négatif, prend l'inverse du résultat
    if (exposantNegatif) {
        resultat = 1.0 / resultat;
    }

    return resultat;
}

int main() {
    double nombre;
    int exposant;

    // Demande un nombre à l'utilisateur
    std::cout << "Entrez un nombre: ";
    std::cin >> nombre;

    // Calcule et affiche le carré
    std::cout << "Le carré de " << nombre << " est " << carre(nombre) << std::endl;

    // Calcule et affiche le cube
    std::cout << "Le cube de " << nombre << " est " << cube(nombre) << std::endl;

    // Demande un exposant à l'utilisateur
    std::cout << "Entrez un exposant: ";
    std::cin >> exposant;

    // Calcule et affiche la puissance n
    std::cout << nombre << " à la puissance " << exposant << " est " << puissance(nombre, exposant) << std::endl;

    return 0;
}
