#include <iostream>

int main() {
    int age;

    // Demande l'âge à l'utilisateur
    std::cout << "Entrez votre âge: ";
    std::cin >> age;

    // Vérifie la validité de l'âge
    if (age < 0 || age > 150) {
        std::cout << "Âge invalide. Veuillez entrer un âge réaliste." << std::endl;
    }
    // Détermine la catégorie d'âge
    else if (age < 12) {
        std::cout << "Vous êtes un enfant." << std::endl;
    }
    else if (age < 18) {
        std::cout << "Vous êtes un adolescent." << std::endl;
    }
    else if (age < 65) {
        std::cout << "Vous êtes un adulte." << std::endl;
    }
    else {
        std::cout << "Vous êtes un senior." << std::endl;
    }

    return 0;
}
