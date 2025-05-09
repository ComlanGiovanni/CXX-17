#include <iostream>

// Fonction avec fuite mémoire
void fuiteMemoire1() {
    int* ptr = new int[10];  // Allocation non libérée
    std::cout << "Tableau d'entiers alloué à l'adresse: " << ptr << std::endl;
    // Pas de delete[] ptr; ici => FUITE
}

// Fonction avec fuite mémoire plus subtile
void fuiteMemoire2() {
    int* ptr = new int[5];
    std::cout << "Tableau de 5 entiers alloué à l'adresse: " << ptr << std::endl;

    // Situation d'erreur simulée
    if (true) {
        std::cout << "Condition rencontrée, sortie prématurée de la fonction" << std::endl;
        return;  // Sortie prématurée sans libération => FUITE
    }

    delete[] ptr;  // Cette ligne n'est jamais atteinte
}

// Version corrigée de fuiteMemoire1
void sansFuite1() {
    int* ptr = new int[10];
    std::cout << "Tableau d'entiers alloué à l'adresse: " << ptr << std::endl;
    delete[] ptr;  // Libération correcte
    std::cout << "Mémoire libérée correctement" << std::endl;
}

// Version corrigée de fuiteMemoire2
void sansFuite2() {
    int* ptr = new int[5];
    std::cout << "Tableau de 5 entiers alloué à l'adresse: " << ptr << std::endl;

    try {
        // Situation d'erreur simulée
        if (true) {
            std::cout << "Condition rencontrée, mais libération effectuée avant la sortie" << std::endl;
            delete[] ptr;  // Libération avant de sortir
            return;
        }
    } catch (...) {
        // Assure que la mémoire est libérée même en cas d'exception
        delete[] ptr;
        throw;  // Re-lance l'exception
    }

    delete[] ptr;  // Libération pour le cas normal
}

int main() {
    std::cout << "Programme de démonstration des fuites mémoire" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;

    // Version avec fuites
    std::cout << "\n1. Appel de fonctions avec fuites:" << std::endl;
    fuiteMemoire1();
    fuiteMemoire2();

    // Version corrigée
    std::cout << "\n2. Appel de fonctions sans fuites:" << std::endl;
    sansFuite1();
    sansFuite2();

    std::cout << "\nPour vérifier les fuites mémoire:" << std::endl;
    std::cout << "- Sous Linux: 'valgrind --leak-check=full ./detection_fuites'" << std::endl;
    std::cout << "- Avec GCC: compilez avec '-fsanitize=address'" << std::endl;

    return 0;
}
