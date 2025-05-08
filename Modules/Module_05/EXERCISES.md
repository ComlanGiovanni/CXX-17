# Exercices du Module 5: Bibliothèque Standard C++

## Exercice 1: Conteneurs Séquentiels

### 1.1 Manipulation de `std::vector`
Implémentez un programme qui:
1. Crée un vecteur d'entiers avec des valeurs initiales
2. Ajoute des éléments à la fin et supprime le dernier élément
3. Accède aux éléments avec `operator[]` et `at()`
4. Mesure l'impact de `reserve()` sur les réallocations lors de l'ajout d'éléments
5. Utilise les différentes façons d'itérer à travers le vecteur

```cpp
// Exemple de sortie attendue:
// Vector initial: 1 2 3 4 5
// Après push_back: 1 2 3 4 5 10
// Après pop_back: 1 2 3 4 5
// Élément à l'index 2: 3
// Nombre de réallocations sans reserve: 5
// Nombre de réallocations avec reserve: 1
```

### 1.2 Comparaison de Performance des Conteneurs
Écrivez un programme qui compare les performances de:
1. `std::vector` pour l'ajout à la fin et l'accès aléatoire
2. `std::list` pour l'insertion/suppression au milieu
3. `std::deque` pour l'ajout au début et à la fin

Mesurez le temps d'exécution pour chaque opération avec un grand nombre d'éléments et présentez les résultats sous forme de tableau.

### 1.3 Array vs Vector
Créez un exemple qui:
1. Démontre les différences entre `std::array` et `std::vector`
2. Compare les performances pour des opérations courantes
3. Illustre les cas d'utilisation appropriés pour chacun

## Exercice 2: Conteneurs Associatifs

### 2.1 Dictionnaire Simple
Implémentez un dictionnaire simple qui:
1. Utilise `std::map` pour stocker des paires mot-définition
2. Permet d'ajouter, rechercher, modifier et supprimer des entrées
3. Offre une fonction pour afficher tous les mots par ordre alphabétique
4. Gère correctement les cas où un mot n'existe pas

```cpp
// Exemple d'utilisation:
Dictionnaire dict;
dict.ajouter("algorithme", "Suite d'instructions pour résoudre un problème");
dict.ajouter("conteneur", "Structure de données qui stocke des objets");
dict.rechercher("algorithme"); // Affiche la définition
dict.modifier("algorithme", "Méthode de résolution de problème");
dict.afficherTous(); // Affiche tous les mots par ordre alphabétique
```

### 2.2 Analyse de Fréquence de Mots
Écrivez un programme qui:
1. Lit un fichier texte et compte la fréquence de chaque mot
2. Utilise `std::map` ou `std::unordered_map` pour stocker les compteurs
3. Permet d'afficher les N mots les plus fréquents
4. Compare les performances entre `map` et `unordered_map` pour cette tâche

### 2.3 Multi-index Container
Implémentez une base de données simple d'étudiants qui:
1. Stocke des informations sur les étudiants (nom, ID, âge, etc.)
2. Permet de rechercher des étudiants par différents critères
3. Utilise `std::map` et/ou `std::multimap` pour maintenir plusieurs index
4. Offre un accès efficace quelle que soit la clé de recherche

```cpp
// Exemple d'utilisation:
EtudiantDB db;
db.ajouter({"Alice", 12345, 20, "Informatique"});
db.ajouter({"Bob", 23456, 22, "Mathématiques"});
db.rechercherParNom("Alice");
db.rechercherParID(23456);
db.rechercherParDepartement("Informatique");
```

## Exercice 3: Itérateurs et Algorithmes

### 3.1 Implémentation d'Itérateurs Personnalisés
Créez une classe `CircularBuffer` qui:
1. Implémente un tampon circulaire de taille fixe
2. Fournit des itérateurs personnalisés pour parcourir le tampon
3. Assure que les itérateurs fonctionnent correctement avec les algorithmes STL
4. Gère correctement le débordement et le cas du tampon vide

```cpp
// Exemple d'utilisation:
CircularBuffer<int, 5> buffer;
buffer.push(1);
buffer.push(2);
buffer.push(3);

// Itération manuelle
for (auto it = buffer.begin(); it != buffer.end(); ++it) {
    std::cout << *it << " ";
}

// Utilisation avec des algorithmes STL
auto sum = std::accumulate(buffer.begin(), buffer.end(), 0);
auto found = std::find(buffer.begin(), buffer.end(), 2);
```

### 3.2 Algorithmes STL
Implémentez des solutions aux problèmes suivants en utilisant les algorithmes STL:
1. Filtrer un vecteur pour ne garder que les nombres pairs
2. Trouver tous les anagrammes dans une liste de mots
3. Fusionner deux séquences triées en éliminant les doublons
4. Calculer des statistiques (min, max, moyenne, médiane) sur un ensemble de données
5. Partitionner un vecteur autour d'une valeur pivot

```cpp
// Exemple pour le filtrage:
std::vector<int> nombres = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
std::vector<int> pairs;

// Solution avec algorithmes STL (pas de boucles explicites)
std::copy_if(nombres.begin(), nombres.end(), std::back_inserter(pairs),
             [](int n) { return n % 2 == 0; });
```

### 3.3 Comparaison avec Méthodes Traditionnelles
Pour chaque problème de l'exercice 3.2:
1. Implémentez également une solution traditionnelle avec des boucles
2. Comparez la lisibilité, la concision et les performances
3. Discutez des avantages et inconvénients de l'approche STL

## Exercice 4: Foncteurs et Lambdas

### 4.1 Foncteurs Personnalisés
Implémentez des foncteurs pour:
1. Comparer des objets personnalisés (par différents critères)
2. Transformer des données (comme convertir des unités)
3. Valider des entrées selon des règles complexes
4. Accumuler des statistiques pendant le traitement

```cpp
// Exemple de foncteur de comparaison:
struct ComparePersonneParAge {
    bool operator()(const Personne& a, const Personne& b) const {
        return a.age < b.age;
    }
};

std::set<Personne, ComparePersonneParAge> personnes;
```

### 4.2 Expressions Lambda
Réimplémentez l'exercice 4.1 en utilisant des expressions lambda et comparez:
1. La syntaxe et la lisibilité
2. Les possibilités de capture d'état
3. Les performances dans différents contextes

```cpp
// Exemple avec lambda:
auto compareParAge = [](const Personne& a, const Personne& b) {
    return a.age < b.age;
};

std::set<Personne, decltype(compareParAge)> personnes(compareParAge);
```

### 4.3 Composition d'Algorithmes
Résolvez un problème complexe en:
1. Décomposant la solution en plusieurs étapes algorithmiques
2. Utilisant des lambdas pour personnaliser le comportement à chaque étape
3. Composant les algorithmes de manière fonctionnelle
4. Évitant les boucles explicites et les variables temporaires inutiles

```cpp
// Exemple: trouver la somme des carrés des nombres premiers dans un vecteur
std::vector<int> nombres = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
auto estPremier = [](int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
};

int sommeCarresPremiers = std::accumulate(nombres.begin(), nombres.end(), 0,
    [&estPremier](int acc, int n) {
        return estPremier(n) ? acc + n * n : acc;
    });
```

## Exercice 5: Nouvelles Fonctionnalités C++17

### 5.1 std::optional
Implémentez un système de traitement d'entrées qui:
1. Utilise `std::optional` pour gérer les valeurs potentiellement manquantes
2. Parse différents types d'entrées (entier, flottant, texte)
3. Propage correctement les erreurs de parsing
4. Fournit des valeurs par défaut quand nécessaire

```cpp
// Exemple:
std::optional<int> parseEntier(const std::string& input);
std::optional<double> parseFlottant(const std::string& input);

void traiterEntree(const std::string& input) {
    auto entier = parseEntier(input);
    if (entier) {
        std::cout << "Entier: " << *entier << std::endl;
    } else {
        auto flottant = parseFlottant(input);
        std::cout << "Flottant: " << flottant.value_or(0.0) << std::endl;
    }
}
```

### 5.2 std::variant
Créez un système de types de données polymorphes qui:
1. Utilise `std::variant` pour stocker différents types de valeurs
2. Implémente des opérations comme l'addition sur ces types hétérogènes
3. Utilise `std::visit` pour traiter tous les cas possibles
4. Évite l'utilisation de l'héritage et du polymorphisme dynamique

```cpp
// Exemple:
using Valeur = std::variant<int, double, std::string>;

Valeur add(const Valeur& a, const Valeur& b) {
    return std::visit([](auto&& arg1, auto&& arg2) -> Valeur {
        using T1 = std::decay_t<decltype(arg1)>;
        using T2 = std::decay_t<decltype(arg2)>;

        if constexpr (std::is_same_v<T1, T2>) {
            return arg1 + arg2;
        } else if constexpr (std::is_arithmetic_v<T1> && std::is_arithmetic_v<T2>) {
            return static_cast<double>(arg1) + static_cast<double>(arg2);
        } else {
            return std::to_string(arg1) + std::to_string(arg2);
        }
    }, a, b);
}
```

### 5.3 std::filesystem
Écrivez un utilitaire de gestion de fichiers qui:
1. Utilise `std::filesystem` pour naviguer dans l'arborescence de fichiers
2. Trouve des fichiers selon certains critères (extension, taille, date)
3. Organise les fichiers en créant des répertoires et déplaçant les fichiers
4. Calcule des statistiques sur l'utilisation de l'espace disque

```cpp
// Exemple:
namespace fs = std::filesystem;

std::vector<fs::path> trouverParExtension(const fs::path& dossier, const std::string& extension) {
    std::vector<fs::path> resultats;
    for (const auto& entry : fs::recursive_directory_iterator(dossier)) {
        if (entry.is_regular_file() && entry.path().extension() == extension) {
            resultats.push_back(entry.path());
        }
    }
    return resultats;
}
```

## Projet Mini: Gestionnaire de Bibliothèque

Développez un système de gestion de bibliothèque qui utilise différentes fonctionnalités de la STL:

1. **Modèle de Données**:
   - Classes pour représenter les livres, les membres, les emprunts
   - Utilisation appropriée de conteneurs (vector, map, set, etc.)
   - Structures de données efficaces pour les différentes opérations

2. **Fonctionnalités**:
   - Ajouter/supprimer des livres et des membres
   - Emprunter et retourner des livres
   - Rechercher des livres par différents critères
   - Gérer les dates d'échéance et les amendes

3. **Algorithmes**:
   - Tri et filtrage des livres et des membres
   - Génération de rapports et statistiques
   - Optimisation des recherches fréquentes

4. **Techniques Avancées**:
   - Utilisation de `std::optional` pour les résultats de recherche
   - `std::variant` pour gérer différents types de contenu
   - Filesystem pour importer/exporter des données
   - Foncteurs/lambdas pour personnaliser les opérations

5. **Interface**:
   - Interface console avec menus
   - Persistance des données dans des fichiers
   - Gestion robuste des erreurs

Ce projet vous permettra d'appliquer une grande variété de fonctionnalités de la STL dans un contexte réaliste, et de comprendre comment les différentes parties de la bibliothèque standard peuvent être combinées pour créer des applications robustes et efficaces.
