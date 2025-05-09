#include <iostream>

int main() {
    int note;

    // Demande la note à l'utilisateur
    std::cout << "Entrez une note numérique (0-100): ";
    std::cin >> note;

    // Vérifie la validité de la note
    if (note < 0 || note > 100) {
        std::cout << "Note invalide. Veuillez entrer une note entre 0 et 100." << std::endl;
        return 1;  // Retourne une erreur
    }

    // Convertit la note numérique en note alphabétique
    char noteAlpha;
    switch (note / 10) {
        case 10:
        case 9:
            noteAlpha = 'A';
            break;
        case 8:
            noteAlpha = 'B';
            break;
        case 7:
            noteAlpha = 'C';
            break;
        case 6:
            noteAlpha = 'D';
            break;
        default:
            noteAlpha = 'F';
            break;
    }

    // Affiche la note alphabétique
    std::cout << "Note alphabétique: " << noteAlpha << std::endl;

    // Affiche un message selon la note
    switch (noteAlpha) {
        case 'A':
            std::cout << "Excellent travail!" << std::endl;
            break;
        case 'B':
            std::cout << "Bon travail!" << std::endl;
            break;
        case 'C':
            std::cout << "Travail satisfaisant." << std::endl;
            break;
        case 'D':
            std::cout << "Vous avez tout juste réussi." << std::endl;
            break;
        case 'F':
            std::cout << "Vous n'avez pas réussi. Veuillez retravailler." << std::endl;
            break;
        default:
            std::cout << "Erreur dans la conversion." << std::endl;
            break;
    }

    return 0;
}
