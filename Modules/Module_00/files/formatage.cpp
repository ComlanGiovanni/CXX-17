#include <iostream>
#include <iomanip>  // Pour les manipulateurs de flux

int main() {
    int nombre = 42;
    double pi = 3.14159265359;

    // Affichage de nombres dans différentes bases
    std::cout << "Affichage de nombres dans différentes bases:" << std::endl;
    std::cout << "Décimal: " << nombre << ", ";
    std::cout << "Hexadécimal: 0x" << std::hex << nombre << ", ";
    std::cout << "Octal: 0" << std::oct << nombre << std::dec << std::endl;  // std::dec réinitialise en base 10

    // Affichage avec différentes précisions
    std::cout << "\nAffichage avec différentes précisions:" << std::endl;
    std::cout << "Pi (valeur par défaut): " << pi << std::endl;
    std::cout << "Pi (2 décimales): " << std::fixed << std::setprecision(2) << pi << std::endl;
    std::cout << "Pi (5 décimales): " << std::fixed << std::setprecision(5) << pi << std::endl;
    std::cout << "Pi (10 décimales): " << std::fixed << std::setprecision(10) << pi << std::endl;

    // Réinitialisation du formatage
    std::cout.unsetf(std::ios::fixed);
    std::cout << std::setprecision(6);  // Valeur par défaut

    // Affichage avec champs de largeur fixe
    std::cout << "\nTableau formaté avec des champs de largeur fixe:" << std::endl;
    std::cout << "+------------+-------+----------+" << std::endl;
    std::cout << "|" << std::setw(12) << "Nom" << "|"
              << std::setw(7) << "Age" << "|"
              << std::setw(10) << "Taille" << "|" << std::endl;
    std::cout << "+------------+-------+----------+" << std::endl;

    // Alignement à gauche
    std::cout << "|" << std::left << std::setw(12) << "Alice" << "|"
              << std::right << std::setw(7) << 25 << "|"
              << std::fixed << std::setprecision(2) << std::setw(10) << 1.65 << "|" << std::endl;

    std::cout << "|" << std::left << std::setw(12) << "Bob" << "|"
              << std::right << std::setw(7) << 30 << "|"
              << std::fixed << std::setprecision(2) << std::setw(10) << 1.80 << "|" << std::endl;

    std::cout << "|" << std::left << std::setw(12) << "Charlie" << "|"
              << std::right << std::setw(7) << 22 << "|"
              << std::fixed << std::setprecision(2) << std::setw(10) << 1.75 << "|" << std::endl;

    std::cout << "+------------+-------+----------+" << std::endl;

    // Formatage de nombres avec séparateurs
    double grandNombre = 1234567.89;
    std::cout << "\nFormatage de grands nombres:" << std::endl;
    std::cout << "Nombre sans formatage: " << grandNombre << std::endl;
    std::cout << "Nombre avec formatage: " << std::fixed << std::setprecision(2);

    // Note: Les séparateurs de milliers ne sont pas directement supportés dans tous les compilateurs
    // Implémentation manuelle:
    std::string nombreStr = std::to_string(static_cast<long long>(grandNombre));
    std::string partieEntiere;
    for (size_t i = 0; i < nombreStr.length(); i++) {
        partieEntiere += nombreStr[i];
        if ((nombreStr.length() - i - 1) % 3 == 0 && i != nombreStr.length() - 1) {
            partieEntiere += " ";  // Espace comme séparateur de milliers
        }
    }
    std::cout << partieEntiere << ".89" << std::endl;

    return 0;
}
