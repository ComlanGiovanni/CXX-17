#include <iostream>

// Fonction qui prend un entier par valeur
void modifierValeur(int nombre) {
    nombre = nombre * 2;
    std::cout << "Dans modifierValeur: nombre = " << nombre << std::endl;
}

// Fonction qui prend un entier par pointeur
void modifierPointeur(int* nombre) {
    *nombre = *nombre * 2;
    std::cout << "Dans modifierPointeur: *nombre = " << *nombre << std::endl;
}

// Fonction qui prend un entier par référence
void modifierReference(int& nombre) {
    nombre = nombre * 2;
    std::cout << "Dans modifierReference: nombre = " << nombre << std::endl;
}

int main() {
    int a = 10;
    int b = 10;
    int c = 10;

    std::cout << "Valeurs initiales: a = " << a << ", b = " << b << ", c = " << c << std::endl;

    // Appel de la fonction avec passage par valeur
    std::cout << "\n1. Passage par valeur:" << std::endl;
    modifierValeur(a);
    std::cout << "Après modifierValeur: a = " << a << " (non modifié)" << std::endl;

    // Appel de la fonction avec passage par pointeur
    std::cout << "\n2. Passage par pointeur:" << std::endl;
    modifierPointeur(&b);
    std::cout << "Après modifierPointeur: b = " << b << " (modifié)" << std::endl;

    // Appel de la fonction avec passage par référence
    std::cout << "\n3. Passage par référence:" << std::endl;
    modifierReference(c);
    std::cout << "Après modifierReference: c = " << c << " (modifié)" << std::endl;

    // Comparaison des syntaxes
    std::cout << "\nComparaison des syntaxes:" << std::endl;
    std::cout << "Passage par valeur   : modifierValeur(a)" << std::endl;
    std::cout << "Passage par pointeur : modifierPointeur(&b)" << std::endl;
    std::cout << "Passage par référence: modifierReference(c)" << std::endl;

    // Démonstration de l'alias avec référence
    int original = 100;
    int& alias = original;

    std::cout << "\nDémonstration de l'alias avec référence:" << std::endl;
    std::cout << "original = " << original << ", alias = " << alias << std::endl;

    alias = 200;
    std::cout << "Après modification via alias:" << std::endl;
    std::cout << "original = " << original << ", alias = " << alias << std::endl;

    return 0;
}
