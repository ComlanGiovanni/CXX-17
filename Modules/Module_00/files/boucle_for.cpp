#include <iostream>

int main() {
    std::cout << "Affichage des nombres de 1 à 10 avec une boucle for:" << std::endl;

    for (int i = 1; i <= 10; i++) {
        std::cout << i;

        // Ajoute une virgule sauf pour le dernier nombre
        if (i < 10) {
            std::cout << ", ";
        }
    }

    std::cout << std::endl;
    return 0;
}
