#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

// Fonction pour afficher un vecteur
template <typename T>
void afficherVecteur(const std::vector<T>& vec, const std::string& message) {
    std::cout << message << " [";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i < vec.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

int main() {
    std::cout << "Démonstration de std::vector" << std::endl;
    std::cout << "=========================" << std::endl;

    // 1. Différentes façons de créer et initialiser un vecteur
    std::cout << "\n1. Création et initialisation de vecteurs:" << std::endl;

    // Vecteur vide
    std::vector<int> vec1;
    afficherVecteur(vec1, "Vecteur vide:");

    // Vecteur avec un nombre spécifique d'éléments initialisés à la valeur par défaut
    std::vector<int> vec2(5);
    afficherVecteur(vec2, "Vecteur avec 5 éléments (par défaut à 0):");

    // Vecteur avec un nombre spécifique d'éléments initialisés à une valeur donnée
    std::vector<int> vec3(5, 10);
    afficherVecteur(vec3, "Vecteur avec 5 éléments (valeur 10):");

    // Vecteur initialisé avec une liste d'initialisation
    std::vector<int> vec4 = {1, 2, 3, 4, 5};
    afficherVecteur(vec4, "Vecteur initialisé avec une liste:");

    // Vecteur créé à partir d'un autre vecteur
    std::vector<int> vec5(vec4);
    afficherVecteur(vec5, "Vecteur copié de vec4:");

    // 2. Ajout d'éléments à un vecteur
    std::cout << "\n2. Ajout d'éléments à un vecteur:" << std::endl;

    std::vector<int> vec6;

    // push_back: ajoute un élément à la fin
    vec6.push_back(10);
    vec6.push_back(20);
    vec6.push_back(30);
    afficherVecteur(vec6, "Après push_back:");

    // insert: insère un élément à une position spécifique
    vec6.insert(vec6.begin() + 1, 15);
    afficherVecteur(vec6, "Après insert à la position 1:");

    // insert avec plusieurs éléments
    vec6.insert(vec6.begin() + 3, 2, 25);
    afficherVecteur(vec6, "Après insert de 2 éléments à la position 3:");

    // emplace_back: construit un élément directement à la fin
    vec6.emplace_back(40);
    afficherVecteur(vec6, "Après emplace_back:");

    // 3. Parcours d'un vecteur
    std::cout << "\n3. Différentes façons de parcourir un vecteur:" << std::endl;

    std::vector<int> vec7 = {1, 2, 3, 4, 5};

    // Utilisation d'indices
    std::cout << "Parcours avec indices: ";
    for (size_t i = 0; i < vec7.size(); ++i) {
        std::cout << vec7[i] << " ";
    }
    std::cout << std::endl;

    // Utilisation d'itérateurs
    std::cout << "Parcours avec itérateurs: ";
    for (auto it = vec7.begin(); it != vec7.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Utilisation de la boucle basée sur plage (range-based for)
    std::cout << "Parcours avec range-based for: ";
    for (const auto& elem : vec7) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // 4. Opérations communes sur les vecteurs
    std::cout << "\n4. Opérations communes sur les vecteurs:" << std::endl;

    std::vector<int> vec8 = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    afficherVecteur(vec8, "Vecteur original:");

    // Tri
    std::sort(vec8.begin(), vec8.end());
    afficherVecteur(vec8, "Après tri:");

    // Recherche
    auto it = std::find(vec8.begin(), vec8.end(), 7);
    if (it != vec8.end()) {
        std::cout << "Élément 7 trouvé à la position: " << std::distance(vec8.begin(), it) << std::endl;
    } else {
        std::cout << "Élément 7 non trouvé" << std::endl;
    }

    // Minimum et maximum
    auto minmax = std::minmax_element(vec8.begin(), vec8.end());
    std::cout << "Minimum: " << *minmax.first << ", Maximum: " << *minmax.second << std::endl;

    // Somme
    int somme = std::accumulate(vec8.begin(), vec8.end(), 0);
    std::cout << "Somme des éléments: " << somme << std::endl;

    // Suppression d'éléments
    vec8.erase(vec8.begin() + 2);
    afficherVecteur(vec8, "Après suppression à l'index 2:");

    // Suppression d'une plage d'éléments
    vec8.erase(vec8.begin() + 1, vec8.begin() + 4);
    afficherVecteur(vec8, "Après suppression des éléments de l'index 1 à 3:");

    // Vider le vecteur
    vec8.clear();
    afficherVecteur(vec8, "Après clear():");

    // 5. Capacité et redimensionnement
    std::cout << "\n5. Capacité et redimensionnement:" << std::endl;

    std::vector<int> vec9;

    std::cout << "Taille: " << vec9.size() << ", Capacité: " << vec9.capacity() << std::endl;

    // Réservation d'espace
    vec9.reserve(20);
    std::cout << "Après reserve(20) - Taille: " << vec9.size() << ", Capacité: " << vec9.capacity() << std::endl;

    // Ajout d'éléments
    for (int i = 1; i <= 10; ++i) {
        vec9.push_back(i);
    }

    std::cout << "Après ajout de 10 éléments - Taille: " << vec9.size() << ", Capacité: " << vec9.capacity() << std::endl;

    // Redimensionnement
    vec9.resize(5);
    std::cout << "Après resize(5) - Taille: " << vec9.size() << ", Capacité: " << vec9.capacity() << std::endl;
    afficherVecteur(vec9, "Contenu après resize(5):");

    vec9.resize(8, 100);
    std::cout << "Après resize(8, 100) - Taille: " << vec9.size() << ", Capacité: " << vec9.capacity() << std::endl;
    afficherVecteur(vec9, "Contenu après resize(8, 100):");

    // Shrink to fit
    vec9.shrink_to_fit();
    std::cout << "Après shrink_to_fit() - Taille: " << vec9.size() << ", Capacité: " << vec9.capacity() << std::endl;

    return 0;
}
