#include <iostream>
#include <string>

int main() {
    // Style d'initialisation avec =
    int age = 25;
    double pi = 3.14159;
    char grade = 'A';
    bool estVrai = true;

    // Style d'initialisation avec ()
    int compteur(100);
    double temperature(36.6);

    // Style d'initialisation avec {}
    int nombre{42};
    double distance{123.45};

    // Affichage des valeurs et tailles
    std::cout << "Variable: age, Type: int, Valeur: " << age
              << ", Taille: " << sizeof(age) << " bytes" << std::endl;

    std::cout << "Variable: pi, Type: double, Valeur: " << pi
              << ", Taille: " << sizeof(pi) << " bytes" << std::endl;

    std::cout << "Variable: grade, Type: char, Valeur: " << grade
              << ", Taille: " << sizeof(grade) << " bytes" << std::endl;

    std::cout << "Variable: estVrai, Type: bool, Valeur: " << estVrai
              << ", Taille: " << sizeof(estVrai) << " bytes" << std::endl;

    std::cout << "Variable: compteur, Type: int, Valeur: " << compteur
              << ", Taille: " << sizeof(compteur) << " bytes" << std::endl;

    std::cout << "Variable: temperature, Type: double, Valeur: " << temperature
              << ", Taille: " << sizeof(temperature) << " bytes" << std::endl;

    std::cout << "Variable: nombre, Type: int, Valeur: " << nombre
              << ", Taille: " << sizeof(nombre) << " bytes" << std::endl;

    std::cout << "Variable: distance, Type: double, Valeur: " << distance
              << ", Taille: " << sizeof(distance) << " bytes" << std::endl;

    return 0;
}
