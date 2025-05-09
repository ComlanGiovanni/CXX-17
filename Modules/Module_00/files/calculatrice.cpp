#include <iostream>

int main() {
    double num1, num2;

    // Demande les nombres à l'utilisateur
    std::cout << "Entrez le premier nombre: ";
    std::cin >> num1;

    std::cout << "Entrez le deuxième nombre: ";
    std::cin >> num2;

    // Effectue les opérations de base
    std::cout << "Addition: " << num1 + num2 << std::endl;
    std::cout << "Soustraction: " << num1 - num2 << std::endl;
    std::cout << "Multiplication: " << num1 * num2 << std::endl;

    // Vérification de division par zéro
    if (num2 != 0) {
        std::cout << "Division: " << num1 / num2 << std::endl;
    } else {
        std::cout << "Division: Impossible (division par zéro)" << std::endl;
    }

    // Modulo uniquement pour les entiers
    if (num2 != 0) {
        // Conversion en entier pour le modulo
        int iNum1 = static_cast<int>(num1);
        int iNum2 = static_cast<int>(num2);
        std::cout << "Modulo (entiers): " << iNum1 % iNum2 << std::endl;

        // Avertissement si la conversion a perdu des données
        if (static_cast<double>(iNum1) != num1 || static_cast<double>(iNum2) != num2) {
            std::cout << "Note: les nombres ont été convertis en entiers pour le modulo." << std::endl;
        }
    } else {
        std::cout << "Modulo: Impossible (division par zéro)" << std::endl;
    }

    return 0;
}
