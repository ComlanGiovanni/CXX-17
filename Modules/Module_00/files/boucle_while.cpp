#include <iostream>

int main() {
    int n;

    // Demande un nombre à l'utilisateur
    std::cout << "Entrez un nombre entier positif: ";
    std::cin >> n;

    // Vérifie que le nombre est positif
    if (n <= 0) {
        std::cout << "Veuillez entrer un nombre positif." << std::endl;
        return 1;  // Retourne une erreur
    }

    // Calcule la somme des nombres de 1 à n avec une boucle while
    int i = 1;
    int somme = 0;

    while (i <= n) {
        somme += i;
        i++;
    }

    std::cout << "La somme des nombres de 1 à " << n << " est: " << somme << std::endl;

    return 0;
}
