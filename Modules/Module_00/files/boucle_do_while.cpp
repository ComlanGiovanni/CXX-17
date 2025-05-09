#include <iostream>

int main() {
    int choix;

    do {
        // Affiche le menu
        std::cout << "\nMenu Principal:" << std::endl;
        std::cout << "1. Afficher un message" << std::endl;
        std::cout << "2. Calculer le carré d'un nombre" << std::endl;
        std::cout << "3. Dire bonjour" << std::endl;
        std::cout << "0. Quitter" << std::endl;
        std::cout << "Votre choix: ";
        std::cin >> choix;

        // Traite le choix de l'utilisateur
        switch (choix) {
            case 1:
                std::cout << "Message important: La programmation C++ est puissante!" << std::endl;
                break;
            case 2: {
                double nombre;
                std::cout << "Entrez un nombre: ";
                std::cin >> nombre;
                std::cout << "Le carré de " << nombre << " est " << nombre * nombre << std::endl;
                break;
            }
            case 3:
                std::cout << "Bonjour, comment allez-vous aujourd'hui?" << std::endl;
                break;
            case 0:
                std::cout << "Au revoir!" << std::endl;
                break;
            default:
                std::cout << "Choix invalide. Veuillez réessayer." << std::endl;
                break;
        }

    } while (choix != 0);  // Continue jusqu'à ce que l'utilisateur choisisse de quitter

    return 0;
}
