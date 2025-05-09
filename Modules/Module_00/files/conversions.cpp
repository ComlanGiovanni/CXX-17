#include <iostream>
#include <climits>  // Pour INT_MAX, INT_MIN

int main() {
    // Conversions implicites
    std::cout << "Conversions implicites:" << std::endl;

    int i = 42;
    double d = i;    // int vers double (pas de perte de données)
    std::cout << "int i = " << i << " -> double d = " << d << std::endl;

    double pi = 3.14159;
    int iPi = pi;    // double vers int (perte de précision)
    std::cout << "double pi = " << pi << " -> int iPi = " << iPi << " (perte de précision)" << std::endl;

    char c = 'A';
    int iChar = c;   // char vers int (conversion en code ASCII)
    std::cout << "char c = '" << c << "' -> int iChar = " << iChar << " (code ASCII)" << std::endl;

    // Conversions explicites (casts)
    std::cout << "\nConversions explicites (casts):" << std::endl;

    double largeValue = 1234.5678;

    // C-style cast
    int iLarge = (int)largeValue;
    std::cout << "C-style cast: double " << largeValue << " -> int " << iLarge << std::endl;

    // static_cast (recommandé en C++ moderne)
    int iLarge2 = static_cast<int>(largeValue);
    std::cout << "static_cast: double " << largeValue << " -> int " << iLarge2 << std::endl;

    // Problèmes potentiels
    std::cout << "\nProblèmes potentiels de conversion:" << std::endl;

    // Perte de précision
    double precise = 3.999999;
    int imprecise = static_cast<int>(precise);
    std::cout << "Perte de précision: double " << precise << " -> int " << imprecise << std::endl;

    // Dépassement
    int maxInt = INT_MAX;
    std::cout << "INT_MAX = " << maxInt << std::endl;

    // Problème de dépassement
    int willOverflow = maxInt + 1;
    std::cout << "Dépassement: INT_MAX + 1 = " << willOverflow << " (résultat incorrect)" << std::endl;

    // Conversion char <-> int
    int largeChar = 130;
    char smallChar = static_cast<char>(largeChar);
    std::cout << "Conversion potentiellement problématique: int " << largeChar
              << " -> char code " << static_cast<int>(smallChar)
              << " (la valeur peut changer selon l'implémentation)" << std::endl;

    return 0;
}
