#include <iostream>
#include <new>      // Pour std::bad_alloc
#include <cstdlib>  // Pour std::exit
#include <limits>   // Pour std::numeric_limits

// Fonction qui tente d'allouer une grande quantité de mémoire
void allocaterMemoireSecurisee(size_t taille) {
    std::cout << "Tentative d'allocation de " << taille << " octets..." << std::endl;

    try {
        // Tente l'allocation
        int* tableau = new int[taille];

        // Si nous arrivons ici, l'allocation a réussi
        std::cout << "Allocation réussie à l'adresse: " << tableau << std::endl;

        // Libère la mémoire
        delete[] tableau;
        std::cout << "Mémoire libérée avec succès." << std::endl;
    }
    catch (const std::bad_alloc& e) {
        // Capture l'exception en cas d'échec d'allocation
        std::cerr << "Erreur d'allocation: " << e.what() << std::endl;
        std::cerr << "Impossible d'allouer la quantité de mémoire demandée." << std::endl;
    }
}

// Fonction alternative utilisant nothrow
void allocaterMemoireNothrow(size_t taille) {
    std::cout << "Tentative d'allocation de " << taille << " octets avec nothrow..." << std::endl;

    // new(nothrow) retourne nullptr en cas d'échec au lieu de lancer une exception
    int* tableau = new(std::nothrow) int[taille];

    if (tableau == nullptr) {
        std::cerr << "Échec de l'allocation (nullptr retourné)." << std::endl;
    } else {
        std::cout << "Allocation réussie à l'adresse: " << tableau << std::endl;
        delete[] tableau;
        std::cout << "Mémoire libérée avec succès." << std::endl;
    }
}

int main() {
    std::cout << "Démonstration de la gestion des erreurs d'allocation mémoire" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;

    // Tester avec différentes tailles
    size_t taillesPetites[] = {
        1000,               // 4 Ko (avec sizeof(int) = 4)
        250000,             // ~1 Mo
        2500000             // ~10 Mo
    };

    std::cout << "\n1. Allocation de petites quantités (devrait réussir):" << std::endl;
    for (size_t taille : taillesPetites) {
        allocaterMemoireSecurisee(taille);
        std::cout << std::endl;
    }

    // Tenter d'allouer une quantité excessive de mémoire
    // Note: Cette valeur peut ne pas être suffisante pour provoquer une erreur
    // sur les systèmes avec beaucoup de RAM et/ou de swap
    size_t taillesExcessives[] = {
        1000000000,         // ~4 Go
        std::numeric_limits<size_t>::max() / sizeof(int) / 2,  // Moitié de la mémoire maximum adressable
    };

    std::cout << "\n2. Allocation de grandes quantités (peut échouer):" << std::endl;
    for (size_t taille : taillesExcessives) {
        allocaterMemoireSecurisee(taille);
        std::cout << std::endl;
    }

    std::cout << "\n3. Utilisation de nothrow:" << std::endl;
    for (size_t taille : taillesExcessives) {
        allocaterMemoireNothrow(taille);
        std::cout << std::endl;
    }

    return 0;
}
