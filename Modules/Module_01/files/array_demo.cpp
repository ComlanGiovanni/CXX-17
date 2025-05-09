#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>
#include <string>
#include <iomanip>
#include <chrono>

// Noms des mois pour référence
const std::array<std::string, 12> nomsMois = {
    "Janvier", "Février", "Mars", "Avril", "Mai", "Juin",
    "Juillet", "Août", "Septembre", "Octobre", "Novembre", "Décembre"
};

// Fonction pour afficher un tableau de type std::array
template <typename T, size_t N>
void afficherArray(const std::array<T, N>& arr, const std::string& message) {
    std::cout << message << " [";
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i];
        if (i < arr.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

// Fonction pour afficher un tableau C classique
template <typename T, size_t N>
void afficherTableauC(const T (&arr)[N], const std::string& message) {
    std::cout << message << " [";
    for (size_t i = 0; i < N; ++i) {
        std::cout << arr[i];
        if (i < N - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

int main() {
    std::cout << "Démonstration de std::array" << std::endl;
    std::cout << "=======================" << std::endl;

    // 1. Déclaration et initialisation
    std::cout << "\n1. Déclaration et initialisation:" << std::endl;

    // Initialisation avec une liste
    std::array<int, 5> arr1 = {1, 2, 3, 4, 5};
    afficherArray(arr1, "std::array initialisé avec une liste:");

    // Initialisation par défaut (valeurs indéterminées)
    std::array<int, 3> arr2;
    afficherArray(arr2, "std::array non initialisé (valeurs indéterminées):");

    // Initialisation à zéro
    std::array<int, 3> arr3 = {};
    afficherArray(arr3, "std::array initialisé à zéro:");

    // Initialisation avec fill
    std::array<int, 4> arr4;
    arr4.fill(10);
    afficherArray(arr4, "std::array initialisé avec fill(10):");

    // 2. Utilisation pour stocker des températures mensuelles
    std::cout << "\n2. Utilisation pour stocker des températures mensuelles:" << std::endl;

    std::array<double, 12> temperatures = {
        3.5, 4.2, 7.8, 11.3, 15.9, 20.1,
        23.5, 23.1, 18.7, 13.2, 7.8, 4.1
    };

    // Affichage des températures avec les noms des mois
    std::cout << "Températures mensuelles:" << std::endl;
    std::cout << "-------------------------" << std::endl;

    for (size_t i = 0; i < temperatures.size(); ++i) {
        std::cout << std::left << std::setw(10) << nomsMois[i] << ": "
                  << std::fixed << std::setprecision(1) << temperatures[i] << "°C" << std::endl;
    }

    // Calcul de statistiques
    auto minmax = std::minmax_element(temperatures.begin(), temperatures.end());
    double min = *minmax.first;
    double max = *minmax.second;

    size_t minIndex = std::distance(temperatures.begin(), minmax.first);
    size_t maxIndex = std::distance(temperatures.begin(), minmax.second);

    // Somme et moyenne
    double somme = std::accumulate(temperatures.begin(), temperatures.end(), 0.0);
    double moyenne = somme / temperatures.size();

    std::cout << "\nStatistiques:" << std::endl;
    std::cout << "Température minimale: " << min << "°C (" << nomsMois[minIndex] << ")" << std::endl;
    std::cout << "Température maximale: " << max << "°C (" << nomsMois[maxIndex] << ")" << std::endl;
    std::cout << "Température moyenne: " << std::fixed << std::setprecision(1) << moyenne << "°C" << std::endl;

    // 3. Comparaison avec des tableaux C classiques
    std::cout << "\n3. Comparaison avec des tableaux C classiques:" << std::endl;

    // Tableau C classique
    double tempC[12] = {
        3.5, 4.2, 7.8, 11.3, 15.9, 20.1,
        23.5, 23.1, 18.7, 13.2, 7.8, 4.1
    };

    // Tableau std::array
    std::array<double, 12> tempArray = {
        3.5, 4.2, 7.8, 11.3, 15.9, 20.1,
        23.5, 23.1, 18.7, 13.2, 7.8, 4.1
    };

    // Affichage
    afficherTableauC(tempC, "Tableau C:");
    afficherArray(tempArray, "std::array:");

    // Test de performance (simple)
    const int ITERATIONS = 10000000;

    std::cout << "\nTest de performance (" << ITERATIONS << " itérations):" << std::endl;

    // Test avec tableau C
    auto startC = std::chrono::high_resolution_clock::now();
    double sumC = 0.0;
    for (int i = 0; i < ITERATIONS; ++i) {
        sumC += tempC[i % 12];
    }
    auto endC = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durationC = endC - startC;

    // Test avec std::array
    auto startArray = std::chrono::high_resolution_clock::now();
    double sumArray = 0.0;
    for (int i = 0; i < ITERATIONS; ++i) {
        sumArray += tempArray[i % 12];
    }
    auto endArray = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durationArray = endArray - startArray;

    std::cout << "Tableau C:  " << durationC.count() << " ms (somme = " << sumC << ")" << std::endl;
    std::cout << "std::array: " << durationArray.count() << " ms (somme = " << sumArray << ")" << std::endl;

    // 4. Avantages de std::array
    std::cout << "\n4. Avantages de std::array par rapport aux tableaux C:" << std::endl;

    // a. Connaissance de sa taille
    std::cout << "a. Taille connue: arr1.size() = " << arr1.size() << std::endl;

    // b. Vérification des bornes (en mode debug)
    std::cout << "b. Accès sécurisé avec at(): arr1.at(2) = " << arr1.at(2) << std::endl;

    // c. Compatibilité avec les algorithmes de la STL
    std::cout << "c. Compatibilité avec les algorithmes STL:" << std::endl;
    std::array<int, 5> arrSort = {5, 3, 1, 4, 2};
    std::sort(arrSort.begin(), arrSort.end());
    afficherArray(arrSort, "   Après std::sort:");

    // d. Interface moderne
    std::cout << "d. Interface moderne:" << std::endl;
    std::cout << "   Premier élément: " << arr1.front() << std::endl;
    std::cout << "   Dernier élément: " << arr1.back() << std::endl;

    // e. Est-il vide?
    std::cout << "e. Test si vide: arr1.empty() = " << (arr1.empty() ? "vrai" : "faux") << std::endl;

    return 0;
}
