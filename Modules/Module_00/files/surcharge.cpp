#include <iostream>

// Fonction max pour les entiers
int max(int a, int b) {
    std::cout << "Appel de max(int, int)" << std::endl;
    return (a > b) ? a : b;
}

// Fonction max pour les doubles
double max(double a, double b) {
    std::cout << "Appel de max(double, double)" << std::endl;
    return (a > b) ? a : b;
}

// Fonction max pour les caractères
char max(char a, char b) {
    std::cout << "Appel de max(char, char)" << std::endl;
    return (a > b) ? a : b;
}

// Fonction max pour trois entiers (surcharge par nombre de paramètres)
int max(int a, int b, int c) {
    std::cout << "Appel de max(int, int, int)" << std::endl;
    return max(max(a, b), c);
}

int main() {
    // Test avec des entiers
    int i1 = 42, i2 = 73;
    std::cout << "Le maximum entre " << i1 << " et " << i2 << " est " << max(i1, i2) << std::endl;

    // Test avec des doubles
    double d1 = 3.14, d2 = 2.71;
    std::cout << "Le maximum entre " << d1 << " et " << d2 << " est " << max(d1, d2) << std::endl;

    // Test avec des caractères
    char c1 = 'A', c2 = 'Z';
    std::cout << "Le maximum entre '" << c1 << "' et '" << c2 << "' est '" << max(c1, c2) << "'" << std::endl;

    // Test avec trois entiers
    int i3 = 100;
    std::cout << "Le maximum entre " << i1 << ", " << i2 << " et " << i3 << " est " << max(i1, i2, i3) << std::endl;

    // Test avec des types mixtes (conversion implicite)
    int i4 = 10;
    double d3 = 10.5;
    // Ceci appelle max(double, double) car i4 est converti en double
    std::cout << "Le maximum entre " << i4 << " et " << d3 << " est " << max(i4, d3) << std::endl;

    return 0;
}
