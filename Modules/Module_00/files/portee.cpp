#include <iostream>

int compteurGlobal = 0;  // Variable globale

void incrementer() {
    static int compteurStatique = 0;  // Variable statique locale
    int compteurLocal = 0;  // Variable locale

    compteurGlobal++;
    compteurStatique++;
    compteurLocal++;

    std::cout << "Global: " << compteurGlobal << ", Statique: " << compteurStatique
              << ", Local: " << compteurLocal << std::endl;
}

// Fonction pour démontrer la portée des variables
void demontrerPortee() {
    int x = 10;  // Variable locale à demontrerPortee

    std::cout << "Dans demontrerPortee, x = " << x << std::endl;

    {  // Nouveau bloc
        int x = 20;  // Variable locale au bloc, masque la variable précédente
        int y = 30;  // Variable locale au bloc

        std::cout << "  Dans le bloc interne, x = " << x << ", y = " << y << std::endl;
    }

    // y n'est plus accessible ici
    std::cout << "  Après le bloc, x = " << x << std::endl;

    // Accès à la variable globale
    std::cout << "  La variable globale compteurGlobal = " << compteurGlobal << std::endl;
}

int main() {
    for (int i = 0; i < 3; i++) {
        incrementer();
    }

    std::cout << "\nDémonstration de la portée des variables:" << std::endl;
    demontrerPortee();

    // Démonstration de la durée de vie
    std::cout << "\nDémonstration de la durée de vie des variables:" << std::endl;
    {
        int variableTemporaire = 100;
        std::cout << "variableTemporaire créée avec la valeur " << variableTemporaire << std::endl;
    }
    // variableTemporaire n'existe plus ici

    // Démonstration des variables globales
    std::cout << "\nValeur finale de compteurGlobal: " << compteurGlobal << std::endl;

    return 0;
}
