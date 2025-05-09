#include <iostream>
#include <limits>  // Pour std::numeric_limits

int main() {
    std::string nom;
    int age;
    double hauteur;

    // Demande les informations à l'utilisateur
    std::cout << "Entrez votre nom: ";
    std::getline(std::cin, nom);

    // Validation de l'âge
    bool ageValide = false;
    while (!ageValide) {
        std::cout << "Entrez votre âge: ";
        if (std::cin >> age) {
            if (age >= 0 && age <= 150) {
                ageValide = true;
            } else {
                std::cout << "L'âge doit être compris entre 0 et 150. Veuillez réessayer." << std::endl;
            }
        } else {
            std::cout << "Entrée invalide. Veuillez entrer un nombre entier." << std::endl;
            std::cin.clear();  // Réinitialise l'état du flux
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Vide le tampon
        }
    }

    // Vide le tampon après la lecture de l'âge
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Validation de la hauteur
    bool hauteurValide = false;
    while (!hauteurValide) {
        std::cout << "Entrez votre hauteur en mètres (ex: 1.75): ";
        if (std::cin >> hauteur) {
            if (hauteur > 0 && hauteur < 3) {
                hauteurValide = true;
            } else {
                std::cout << "La hauteur doit être comprise entre 0 et 3 mètres. Veuillez réessayer." << std::endl;
            }
        } else {
            std::cout << "Entrée invalide. Veuillez entrer un nombre réel." << std::endl;
            std::cin.clear();  // Réinitialise l'état du flux
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Vide le tampon
        }
    }

    // Affiche un résumé formaté des informations
    std::cout << "\nRésumé des informations:" << std::endl;
    std::cout << "Nom: " << nom << std::endl;
    std::cout << "Âge: " << age << " ans" << std::endl;
    std::cout << "Hauteur: " << hauteur << " mètres" << std::endl;

    // Classification selon l'âge
    std::cout << "\nClassification selon l'âge:" << std::endl;
    if (age < 18) {
        std::cout << "Vous êtes mineur(e)." << std::endl;
    } else if (age < 65) {
        std::cout << "Vous êtes adulte." << std::endl;
    } else {
        std::cout << "Vous êtes senior." << std::endl;
    }

    // Classification selon la hauteur
    std::cout << "\nClassification selon la hauteur:" << std::endl;
    if (hauteur < 1.50) {
        std::cout << "Vous êtes de petite taille." << std::endl;
    } else if (hauteur < 1.80) {
        std::cout << "Vous êtes de taille moyenne." << std::endl;
    } else {
        std::cout << "Vous êtes de grande taille." << std::endl;
    }

    return 0;
}
