# Mini-Examen du Module 0: Fondamentaux C++ Revisités

## Instructions
- Durée: 2 heures
- Tous les exercices doivent être résolus en C++17
- Vous pouvez utiliser la documentation en ligne standard (cppreference.com)
- Compilez avec: `g++ -std=c++17 -Wall -Wextra -Werror votre_fichier.cpp`

## Exercice 1: Modernisation (30 points)

Vous avez le code C++98 suivant:

```cpp
#include <iostream>
#include <vector>
#include <map>
#include <string>

void printVector(const std::vector<int>& vec) {
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void findAndPrint(const std::map<std::string, int>& data, const std::string& key) {
    std::map<std::string, int>::const_iterator it = data.find(key);
    if (it != data.end()) {
        std::cout << "Found: " << key << " -> " << it->second << std::endl;
    } else {
        std::cout << "Not found: " << key << std::endl;
    }
}

int main() {
    // Initialisation
    std::vector<int> numbers;
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    numbers.push_back(40);

    std::map<std::string, int> scores;
    scores["Alice"] = 95;
    scores["Bob"] = 87;
    scores["Charlie"] = 92;

    // Utilisation
    printVector(numbers);
    findAndPrint(scores, "Alice");
    findAndPrint(scores, "Dave");

    return 0;
}
```

Votre tâche:
1. Modernisez ce code en utilisant les fonctionnalités de C++17
2. Utilisez auto, range-based for loops, initialisation uniforme, etc.
3. Ajoutez au moins deux exemples de structured binding
4. Utilisez if avec initialisation pour le bloc conditionnel

## Exercice 2: Fonctions Templates Variadiques (30 points)

Implémentez une fonction template variadique `print_all` qui:
1. Accepte un nombre variable d'arguments de n'importe quel type
2. Imprime chaque argument sur une nouvelle ligne
3. Affiche également le type de chaque argument (utilisez `typeid().name()` ou une autre méthode)
4. Utilise un fold expression pour calculer et afficher la somme des arguments numériques

Exemple d'utilisation:
```cpp
print_all(42, "hello", 3.14, 'a');
// Sortie attendue:
// Type: int, Value: 42
// Type: const char*, Value: hello
// Type: double, Value: 3.14
// Type: char, Value: a
// Sum of numeric values: 45.14
```

## Exercice 3: Gestion d'Erreurs Moderne (40 points)

Créez une application simple de carnet d'adresses avec:

1. Une structure `Contact` contenant:
   - Nom (obligatoire)
   - Email (obligatoire)
   - Téléphone (optionnel)
   - Adresse (optionnelle)

2. Une classe `AddressBook` qui:
   - Stocke les contacts dans un conteneur approprié
   - Fournit des méthodes pour ajouter, rechercher et supprimer des contacts
   - Utilise `std::optional` pour les méthodes de recherche
   - Utilise `std::variant` pour permettre plusieurs types de recherche (par nom, email, etc.)

3. Implémentez la gestion d'erreurs appropriée:
   - Validation des entrées
   - Retours appropriés pour les cas d'échec
   - Messages d'erreur informatifs

Votre programme doit:
- Être organisé en fichiers d'en-tête et d'implémentation appropriés
- Inclure un programme de test démontrant toutes les fonctionnalités
- Utiliser au moins deux lambdas pour des opérations de traitement ou de filtrage

## Bonus (10 points)

Ajoutez une fonctionnalité permettant de sérialiser et désérialiser le carnet d'adresses dans un fichier texte simple, en utilisant `std::filesystem` pour gérer les chemins de fichiers et vérifier l'existence du fichier.
