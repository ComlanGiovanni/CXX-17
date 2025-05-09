/*
 * Exercice 6.1: Efficacité des Méthodes de Passage
 *
 * Ce programme démontre les différentes méthodes de passage de paramètres
 * (par valeur, par pointeur et par référence) et mesure leurs performances.
 */

#include <iostream>
#include <chrono>
#include <vector>
#include <string>

// Structure volumineuse pour tester l'efficacité des méthodes de passage
struct GrosseStructure {
    int donnees[1000];

    // Constructeur qui initialise les données
    GrosseStructure() {
        for (int i = 0; i < 1000; i++) {
            donnees[i] = i;
        }
    }

    // Opérateur d'affectation nécessaire pour les tests
    GrosseStructure& operator=(const GrosseStructure& autre) {
        if (this != &autre) {
            for (int i = 0; i < 1000; i++) {
                donnees[i] = autre.donnees[i];
            }
        }
        return *this;
    }
};

// Fonctions qui manipulent la structure de différentes façons

// Par valeur (copie complète)
void manipulerParValeur(GrosseStructure s) {
    // Modification de quelques valeurs
    s.donnees[0] = 9999;
    s.donnees[999] = 9999;
}

// Par pointeur
void manipulerParPointeur(GrosseStructure* s) {
    // Modification de quelques valeurs
    s->donnees[0] = 9999;
    s->donnees[999] = 9999;
}

// Par référence
void manipulerParReference(GrosseStructure& s) {
    // Modification de quelques valeurs
    s.donnees[0] = 9999;
    s.donnees[999] = 9999;
}

// Fonction pour mesurer le temps d'exécution d'une fonction
template<typename Func, typename... Args>
double mesurerTemps(Func f, Args&&... args) {
    auto debut = std::chrono::high_resolution_clock::now();
    f(std::forward<Args>(args)...);
    auto fin = std::chrono::high_resolution_clock::now();

    return std::chrono::duration<double, std::milli>(fin - debut).count();
}

int main() {
    const int NOMBRE_ITERATIONS = 100000;

    // Préparer les données pour le test
    GrosseStructure structure;
    GrosseStructure structureCopie;

    // Mesurer le temps pour la méthode par valeur
    double tempsParValeur = mesurerTemps([&]() {
        for (int i = 0; i < NOMBRE_ITERATIONS; i++) {
            structureCopie = structure; // Réinitialiser avant chaque appel
            manipulerParValeur(structureCopie);
        }
    });

    // Mesurer le temps pour la méthode par pointeur
    double tempsParPointeur = mesurerTemps([&]() {
        for (int i = 0; i < NOMBRE_ITERATIONS; i++) {
            structureCopie = structure; // Réinitialiser avant chaque appel
            manipulerParPointeur(&structureCopie);
        }
    });

    // Mesurer le temps pour la méthode par référence
    double tempsParReference = mesurerTemps([&]() {
        for (int i = 0; i < NOMBRE_ITERATIONS; i++) {
            structureCopie = structure; // Réinitialiser avant chaque appel
            manipulerParReference(structureCopie);
        }
    });

    // Afficher les résultats
    std::cout << "Temps d'exécution pour " << NOMBRE_ITERATIONS << " appels:" << std::endl;
    std::cout << "Par valeur:     " << tempsParValeur << " ms" << std::endl;
    std::cout << "Par pointeur:   " << tempsParPointeur << " ms" << std::endl;
    std::cout << "Par référence:  " << tempsParReference << " ms" << std::endl;

    // Calculer les ratios pour une meilleure comparaison
    double ratioValeurPointeur = tempsParValeur / tempsParPointeur;
    double ratioValeurReference = tempsParValeur / tempsParReference;

    std::cout << "\nRatios de performance:" << std::endl;
    std::cout << "Valeur / Pointeur:   " << ratioValeurPointeur << "x plus lent" << std::endl;
    std::cout << "Valeur / Référence:  " << ratioValeurReference << "x plus lent" << std::endl;

    // Expliquer les résultats
    std::cout << "\nExplication des résultats:" << std::endl;
    std::cout << "1. Passage par valeur: Une copie complète de la structure est créée, "
              << "ce qui est coûteux pour des objets volumineux." << std::endl;
    std::cout << "2. Passage par pointeur: Seule l'adresse de la structure est passée, "
              << "pas de copie, donc très efficace." << std::endl;
    std::cout << "3. Passage par référence: Similaire au pointeur en termes de performance, "
              << "mais avec une syntaxe plus propre." << std::endl;

    std::cout << "\nConclusions:" << std::endl;
    std::cout << "- Pour les petits objets (quelques octets), le passage par valeur peut être suffisant." << std::endl;
    std::cout << "- Pour les objets volumineux, préférez le passage par référence." << std::endl;
    std::cout << "- Utilisez les références constantes (const &) pour les paramètres que vous ne modifiez pas." << std::endl;

    return 0;
}
