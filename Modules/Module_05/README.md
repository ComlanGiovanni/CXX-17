# Module 5: Bibliothèque Standard C++

Ce module explore la bibliothèque standard C++ (STL), une collection riche de conteneurs, algorithmes, itérateurs et utilitaires qui sont essentiels pour le développement efficace en C++, notamment pour les jeux vidéo.

## 1. Introduction à la STL

### Composants Principaux
```cpp
// La STL est constituée de quatre composants principaux:
// 1. Conteneurs: Collection d'objets (vector, map, set, etc.)
// 2. Algorithmes: Opérations sur les données (sort, find, transform, etc.)
// 3. Itérateurs: Pointeurs généralisés pour parcourir les conteneurs
// 4. Foncteurs et fonctions: Personnalisation du comportement des algorithmes

#include <vector>   // Conteneur dynamique
#include <algorithm> // Algorithmes standard
#include <functional> // Foncteurs et fonctions

std::vector<int> nombres = {5, 2, 9, 1, 7};
std::sort(nombres.begin(), nombres.end()); // Utilisation d'un algorithme avec itérateurs
// nombres contient maintenant {1, 2, 5, 7, 9}

// Utilisation d'un foncteur avec un algorithme
std::sort(nombres.begin(), nombres.end(), std::greater<int>());
// nombres contient maintenant {9, 7, 5, 2, 1}
```

### Avantages de la STL
```cpp
// 1. Réutilisabilité: Code déjà écrit, testé et optimisé
// 2. Généricité: Fonctionne avec vos propres types
// 3. Efficacité: Implémentations optimisées pour les performances
// 4. Standardisation: Garantie de disponibilité sur toutes les plateformes C++

// Sans la STL, vous pourriez écrire:
int* tab = new int[5];
tab[0] = 5; tab[1] = 2; tab[2] = 9; tab[3] = 1; tab[4] = 7;
// ... code de tri manuel ...
delete[] tab;

// Avec la STL:
std::vector<int> nombres = {5, 2, 9, 1, 7};
std::sort(nombres.begin(), nombres.end());
// Pas besoin de gérer manuellement la mémoire
```

## 2. Conteneurs Séquentiels

### vector: Tableau Dynamique
```cpp
#include <vector>
#include <iostream>

// Déclaration et initialisation
std::vector<int> nombres;              // Vecteur vide
std::vector<int> nombres2(5);          // 5 éléments initialisés à 0
std::vector<int> nombres3(5, 10);      // 5 éléments initialisés à 10
std::vector<int> nombres4 = {1, 2, 3}; // Initialisation avec liste (C++11)

// Opérations de base
nombres.push_back(42);    // Ajoute à la fin
nombres.pop_back();       // Supprime le dernier élément
nombres[0] = 100;         // Accès direct (sans vérification de bornes)
nombres.at(1) = 200;      // Accès avec vérification de bornes (exception si hors limites)
nombres.front();          // Premier élément
nombres.back();           // Dernier élément
nombres.size();           // Nombre d'éléments
nombres.empty();          // Test si vide
nombres.clear();          // Vide le vecteur
nombres.resize(10);       // Redimensionne (ajoute ou supprime des éléments)

// Capacité et allocation
nombres.reserve(100);     // Réserve de la mémoire (sans changer la taille)
nombres.capacity();       // Capacité actuelle (mémoire allouée)
nombres.shrink_to_fit();  // Réduit la capacité à la taille actuelle

// Itération
for (size_t i = 0; i < nombres.size(); ++i) {
    std::cout << nombres[i] << " ";
}

// Itération avec itérateurs
for (auto it = nombres.begin(); it != nombres.end(); ++it) {
    std::cout << *it << " ";
}

// Itération avec for-each (C++11)
for (const auto& valeur : nombres) {
    std::cout << valeur << " ";
}

// Insertion et suppression
nombres.insert(nombres.begin() + 1, 99); // Insère 99 à l'index 1
nombres.erase(nombres.begin() + 2);      // Supprime l'élément à l'index 2
```

### array: Tableau à Taille Fixe (C++11)
```cpp
#include <array>

// Déclaration et initialisation
std::array<int, 5> nombres = {1, 2, 3, 4, 5};  // La taille est partie du type

// Opérations de base (similaires à vector, mais sans redimensionnement)
nombres[0] = 10;
nombres.at(1) = 20;
nombres.front();
nombres.back();
nombres.size();  // Toujours 5 dans ce cas
nombres.empty();

// Conversion vers un tableau C brut
int* ptr = nombres.data();

// Caractéristiques uniques
constexpr size_t taille = nombres.size(); // Connu à la compilation
nombres.fill(0); // Remplit tout le tableau avec 0
```

### deque: Double-Ended Queue
```cpp
#include <deque>

// Déclaration et initialisation
std::deque<int> nombres = {1, 2, 3};

// Opérations de base (similaires à vector)
nombres.push_back(4);     // Ajoute à la fin
nombres.push_front(0);    // Ajoute au début (efficace, contrairement à vector)
nombres.pop_back();       // Supprime à la fin
nombres.pop_front();      // Supprime au début
nombres[0] = 100;
nombres.at(1) = 200;
nombres.size();
nombres.empty();

// Avantages par rapport à vector
// 1. Insertion/suppression efficace aux deux extrémités
// 2. Pas de réallocation complète lors de l'expansion
// 3. Les références/itérateurs restent valides après insertion/suppression
//    (sauf aux points d'insertion/suppression)
```

### list: Liste Doublement Chaînée
```cpp
#include <list>

// Déclaration et initialisation
std::list<int> nombres = {1, 2, 3};

// Opérations de base
nombres.push_back(4);
nombres.push_front(0);
nombres.pop_back();
nombres.pop_front();
nombres.front();
nombres.back();
nombres.size();
nombres.empty();

// Pas d'accès direct par index, doit utiliser des itérateurs
auto it = nombres.begin();
std::advance(it, 2); // Déplace l'itérateur de 2 positions
int troisieme = *it;

// Caractéristiques uniques
nombres.splice(it, autreList); // Déplace les éléments d'une autre liste
nombres.sort();                // Tri intégré (souvent plus efficace que std::sort pour les listes)
nombres.unique();              // Supprime les doublons adjacents
nombres.merge(autreList);      // Fusionne avec une autre liste (les deux doivent être triées)
nombres.reverse();             // Inverse l'ordre des éléments
```

### forward_list: Liste Simplement Chaînée (C++11)
```cpp
#include <forward_list>

// Déclaration et initialisation
std::forward_list<int> nombres = {1, 2, 3};

// Opérations de base
nombres.push_front(0);
nombres.pop_front();
nombres.front();
// Pas de back() ou size() (pour maximiser l'efficacité)

// Navigation simplifiée, uniquement vers l'avant
auto it = nombres.begin();
it = nombres.insert_after(it, 42);  // Insère après l'élément et retourne le nouvel itérateur
nombres.erase_after(it);            // Supprime l'élément suivant

// Avantages
// 1. Plus compact que list (un pointeur par nœud au lieu de deux)
// 2. Meilleure localité de cache potentielle
// 3. Parfois plus efficace si vous n'avez besoin que d'aller dans une direction
```

## 3. Conteneurs Associatifs

### set: Ensemble Trié
```cpp
#include <set>

// Déclaration et initialisation
std::set<int> nombres = {5, 2, 9, 1, 5}; // Notez que 5 n'apparaîtra qu'une fois

// Opérations de base
nombres.insert(7);
auto it = nombres.find(9);  // Retourne un itérateur vers 9, ou end() s'il n'existe pas
nombres.erase(2);           // Supprime par valeur
nombres.erase(it);          // Supprime par itérateur
nombres.count(5);           // Retourne 1 si présent, 0 sinon
nombres.contains(7);        // C++20: Retourne true si présent
nombres.size();
nombres.empty();

// Caractéristiques clés
// 1. Éléments automatiquement triés
// 2. Pas de doublons
// 3. Recherche, insertion et suppression en O(log n)
// 4. Les itérateurs retournent les éléments dans l'ordre trié
```

### multiset: Ensemble Trié avec Doublons
```cpp
#include <set>

// Déclaration et initialisation
std::multiset<int> nombres = {5, 2, 9, 1, 5}; // 5 apparaît deux fois

// Opérations de base (similaires à set)
nombres.insert(5);          // Maintenant 5 apparaît trois fois
nombres.count(5);           // Retourne 3
auto range = nombres.equal_range(5); // Paire d'itérateurs englobant tous les 5
nombres.erase(5);           // Supprime TOUS les 5

// Pour supprimer une seule occurrence
auto it = nombres.find(5);
if (it != nombres.end()) {
    nombres.erase(it);      // Supprime une seule occurrence
}
```

### map: Dictionnaire Trié
```cpp
#include <map>
#include <string>

// Déclaration et initialisation
std::map<std::string, int> ages = {
    {"Alice", 30},
    {"Bob", 25},
    {"Charlie", 35}
};

// Accès et modification
ages["David"] = 40;         // Ajoute une nouvelle entrée ou modifie une existante
int age = ages["Alice"];    // Accès, crée l'entrée avec valeur par défaut si inexistante
int age2 = ages.at("Bob");  // Accès avec vérification (exception si clé inexistante)

// Vérification d'existence
if (ages.count("Eve") > 0) {
    // Eve existe
}

if (ages.contains("Eve")) { // C++20
    // Eve existe
}

auto it = ages.find("Charlie");
if (it != ages.end()) {
    // Charlie existe
    std::cout << it->first << ": " << it->second << std::endl;
}

// Itération
for (const auto& paire : ages) {
    std::cout << paire.first << ": " << paire.second << std::endl;
}

// C++17 structured binding
for (const auto& [nom, age] : ages) {
    std::cout << nom << ": " << age << std::endl;
}

// Insertion et suppression
ages.insert({"Eve", 28});
ages.insert(std::make_pair("Frank", 45));
ages.erase("Bob");
```

### multimap: Dictionnaire Trié avec Clés Dupliquées
```cpp
#include <map>
#include <string>

// Déclaration et initialisation
std::multimap<std::string, int> scores = {
    {"Alice", 95},
    {"Bob", 80},
    {"Alice", 92}  // Même clé, valeur différente
};

// Insertion
scores.insert({"Alice", 88});

// Accès (plus complexe que map)
auto range = scores.equal_range("Alice");
for (auto it = range.first; it != range.second; ++it) {
    std::cout << it->first << ": " << it->second << std::endl;
}

// Nombre d'occurrences d'une clé
int alice_count = scores.count("Alice"); // 3

// Suppression
scores.erase("Alice");  // Supprime toutes les entrées "Alice"
```

## 4. Conteneurs Associatifs Non Ordonnés (C++11)

### unordered_set: Ensemble Non Trié
```cpp
#include <unordered_set>

// Déclaration et initialisation
std::unordered_set<int> nombres = {5, 2, 9, 1, 5}; // 5 n'apparaîtra qu'une fois

// Opérations de base (similaires à set)
nombres.insert(7);
auto it = nombres.find(9);
nombres.erase(2);
nombres.count(5);
nombres.contains(7);  // C++20
nombres.size();
nombres.empty();

// Caractéristiques spécifiques
nombres.load_factor();      // Rapport entre taille et nombre de buckets
nombres.bucket_count();     // Nombre de buckets dans la table de hachage
nombres.bucket(7);          // Bucket contenant 7
nombres.rehash(100);        // Réorganise avec au moins 100 buckets
nombres.reserve(50);        // Réserve pour au moins 50 éléments

// Avantages par rapport à set
// 1. Opérations en O(1) en moyenne (vs O(log n) pour set)
// 2. Pas de tri automatique (l'ordre d'itération est imprévisible)
```

### unordered_multiset: Ensemble Non Trié avec Doublons
```cpp
#include <unordered_set>

// Similaire à unordered_set mais permet les doublons
std::unordered_multiset<int> nombres = {5, 2, 9, 1, 5};  // 5 apparaît deux fois
nombres.count(5);  // Retourne 2
```

### unordered_map: Dictionnaire Non Trié
```cpp
#include <unordered_map>
#include <string>

// Déclaration et initialisation
std::unordered_map<std::string, int> ages = {
    {"Alice", 30},
    {"Bob", 25},
    {"Charlie", 35}
};

// Utilisation similaire à map, avec les mêmes méthodes
// Mais avec les avantages spécifiques du hachage:
// 1. Accès, insertion et suppression en O(1) en moyenne
// 2. Pas d'ordre spécifique lors de l'itération
```

### unordered_multimap: Dictionnaire Non Trié avec Clés Dupliquées
```cpp
#include <unordered_map>

// Similaire à unordered_map mais permet des clés dupliquées
std::unordered_multimap<std::string, int> scores = {
    {"Alice", 95},
    {"Bob", 80},
    {"Alice", 92}
};
```

## 5. Conteneurs Adaptateurs

### stack: Pile LIFO
```cpp
#include <stack>

// Déclaration et initialisation
std::stack<int> pile;

// Opérations de base
pile.push(10);         // Ajoute un élément au sommet
pile.push(20);
pile.push(30);
int sommet = pile.top(); // Accède au sommet sans retirer (30)
pile.pop();            // Retire le sommet
pile.size();           // Nombre d'éléments (2)
pile.empty();          // Test si vide

// Utilisation typique
while (!pile.empty()) {
    std::cout << pile.top() << " ";
    pile.pop();
}  // Affiche: 20 10
```

### queue: File FIFO
```cpp
#include <queue>

// Déclaration et initialisation
std::queue<int> file;

// Opérations de base
file.push(10);         // Ajoute à la fin
file.push(20);
file.push(30);
int premier = file.front(); // Premier élément (10)
int dernier = file.back();  // Dernier élément (30)
file.pop();            // Retire le premier élément
file.size();           // Nombre d'éléments (2)
file.empty();          // Test si vide

// Utilisation typique
while (!file.empty()) {
    std::cout << file.front() << " ";
    file.pop();
}  // Affiche: 20 30
```

### priority_queue: File à Priorité
```cpp
#include <queue>

// Déclaration et initialisation
std::priority_queue<int> pq;                  // Max heap par défaut
std::priority_queue<int, std::vector<int>, std::greater<int>> pq_min; // Min heap

// Opérations de base
pq.push(30);           // Ajoute des éléments
pq.push(10);
pq.push(20);
int max = pq.top();    // Élément avec la plus haute priorité (30)
pq.pop();              // Retire l'élément avec la plus haute priorité
pq.size();             // Nombre d'éléments
pq.empty();            // Test si vide

// Utilisation typique
while (!pq.empty()) {
    std::cout << pq.top() << " ";
    pq.pop();
}  // Affiche: 20 10 (décroissant)

// Avec un type personnalisé
struct Tâche {
    int priorité;
    std::string description;

    // Opérateur de comparaison
    bool operator<(const Tâche& autre) const {
        return priorité < autre.priorité; // Notez: inversé pour une priority_queue
    }
};

std::priority_queue<Tâche> tâches;
tâches.push({5, "Urgent"});
tâches.push({2, "Normal"});
tâches.push({7, "Critique"});

// La tâche "Critique" sera en haut
```

## 6. Itérateurs

### Types d'Itérateurs
```cpp
// La STL définit une hiérarchie d'itérateurs, du moins au plus puissant:
// 1. Input Iterator: Lecture unique, avancement en avant
// 2. Output Iterator: Écriture unique, avancement en avant
// 3. Forward Iterator: Lecture/écriture multiple, avancement en avant
// 4. Bidirectional Iterator: Forward + avancement en arrière
// 5. Random Access Iterator: Bidirectional + accès direct à n'importe quel élément

// Exemple de récupération d'itérateurs
std::vector<int> v = {1, 2, 3, 4, 5};
auto it_begin = v.begin();  // Pointeur sur le premier élément
auto it_end = v.end();      // Pointeur sur la position après le dernier élément

// Types d'itérateurs spécifiques
auto it_rbegin = v.rbegin();  // Itérateur inverse (commence à la fin)
auto it_rend = v.rend();      // Fin de l'itérateur inverse (avant le début)
auto it_cbegin = v.cbegin();  // Itérateur constant (ne peut pas modifier)
auto it_cend = v.cend();      // Fin de l'itérateur constant
```

### Opérations sur les Itérateurs
```cpp
std::vector<int> v = {10, 20, 30, 40, 50};
auto it = v.begin();

// Avancement
++it;             // Avance à l'élément suivant (maintenant sur 20)
it++;             // Post-incrémentation (moins efficace, éviter si possible)
it += 2;          // Avance de 2 positions (maintenant sur 40)
                  // Note: += disponible uniquement pour les Random Access Iterators

// Recul (pour Bidirectional et Random Access Iterators)
--it;             // Recule à l'élément précédent (maintenant sur 30)
it--;             // Post-décrémentation
it -= 2;          // Recule de 2 positions (maintenant sur 10)
                  // Note: -= disponible uniquement pour les Random Access Iterators

// Accès
int valeur = *it;  // Accès à la valeur (déréférencement)
it[2];             // Accès à it+2 (uniquement pour Random Access Iterators)

// Comparaison
if (it == v.begin()) { /* ... */ }
if (it != v.end()) { /* ... */ }
if (it < v.end()) { /* ... */ }  // Uniquement pour Random Access Iterators
```

### Itérateurs avec les Algorithmes
```cpp
#include <vector>
#include <algorithm>
#include <iterator>

std::vector<int> v = {5, 2, 9, 1, 7};

// Tri avec itérateurs
std::sort(v.begin(), v.end());

// Recherche avec itérateurs
auto it = std::find(v.begin(), v.end(), 7);
if (it != v.end()) {
    std::cout << "Trouvé à la position: " << std::distance(v.begin(), it) << std::endl;
}

// Copie avec itérateurs
std::vector<int> destination(v.size());
std::copy(v.begin(), v.end(), destination.begin());

// Stream iterators
std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
// Affiche: 1 2 5 7 9

std::vector<int> input;
std::copy(std::istream_iterator<int>(std::cin), std::istream_iterator<int>(),
          std::back_inserter(input));
// Lit des entiers depuis l'entrée standard jusqu'à EOF
```

### Adaptateurs d'Itérateurs
```cpp
#include <vector>
#include <algorithm>
#include <iterator>

std::vector<int> v;

// back_inserter: ajoute automatiquement des éléments à la fin
std::fill_n(std::back_inserter(v), 5, 10);
// v contient maintenant {10, 10, 10, 10, 10}

// front_inserter: ajoute automatiquement des éléments au début
std::list<int> l = {1, 2, 3};
std::copy(v.begin(), v.end(), std::front_inserter(l));
// l contient maintenant {10, 10, 10, 10, 10, 1, 2, 3}

// inserter: ajoute des éléments à une position spécifique
std::vector<int> v2 = {100, 200};
std::copy(v.begin(), v.end(), std::inserter(v2, v2.begin() + 1));
// v2 contient maintenant {100, 10, 10, 10, 10, 10, 200}

// move_iterator: déplace plutôt que copier
std::vector<std::string> src = {"hello", "world"};
std::vector<std::string> dest;
std::copy(std::make_move_iterator(src.begin()),
          std::make_move_iterator(src.end()),
          std::back_inserter(dest));
// dest contient maintenant les chaînes, src contient des chaînes vides
```

## 7. Algorithmes

### Algorithmes Non-Modifiants
```cpp
#include <algorithm>
#include <vector>

std::vector<int> v = {5, 2, 9, 1, 9, 4, 7};

// Recherche
auto it = std::find(v.begin(), v.end(), 9);  // Premier 9
auto it2 = std::find_if(v.begin(), v.end(), [](int n) { return n % 2 == 0; });  // Premier pair
auto it3 = std::find_if_not(v.begin(), v.end(), [](int n) { return n < 5; });  // Premier >= 5

// Comptage
int count9 = std::count(v.begin(), v.end(), 9);  // Nombre de 9
int countEven = std::count_if(v.begin(), v.end(), [](int n) { return n % 2 == 0; });  // Nombre de pairs

// Min/Max
auto minElem = std::min_element(v.begin(), v.end());  // Itérateur vers le minimum
auto maxElem = std::max_element(v.begin(), v.end());  // Itérateur vers le maximum
auto minMaxElem = std::minmax_element(v.begin(), v.end());  // Paire d'itérateurs (min, max)

// Comparaison
bool allLessThan10 = std::all_of(v.begin(), v.end(), [](int n) { return n < 10; });
bool anyEven = std::any_of(v.begin(), v.end(), [](int n) { return n % 2 == 0; });
bool noneNegative = std::none_of(v.begin(), v.end(), [](int n) { return n < 0; });

// Recherche de sous-séquence
std::vector<int> sub = {9, 4};
auto it4 = std::search(v.begin(), v.end(), sub.begin(), sub.end());
```

### Algorithmes Modifiants
```cpp
#include <algorithm>
#include <vector>

std::vector<int> v = {5, 2, 9, 1, 9, 4, 7};
std::vector<int> dest(v.size());

// Copie
std::copy(v.begin(), v.end(), dest.begin());
std::copy_if(v.begin(), v.end(), dest.begin(), [](int n) { return n % 2 == 0; });  // Copie si pair
std::copy_n(v.begin(), 3, dest.begin());  // Copie les 3 premiers éléments

// Transformation
std::transform(v.begin(), v.end(), dest.begin(), [](int n) { return n * 2; });  // Double chaque élément

// Remplissage
std::fill(dest.begin(), dest.end(), 0);  // Remplit avec des zéros
std::fill_n(dest.begin(), 3, 42);  // Remplit les 3 premiers avec 42
std::generate(dest.begin(), dest.end(), []() { return rand() % 100; });  // Remplit avec des valeurs aléatoires

// Remplacement
std::replace(v.begin(), v.end(), 9, 99);  // Remplace tous les 9 par 99
std::replace_if(v.begin(), v.end(), [](int n) { return n < 5; }, 0);  // Remplace les < 5 par 0

// Suppression
auto newEnd = std::remove(v.begin(), v.end(), 9);  // "Supprime" les 9 (déplace à la fin)
v.erase(newEnd, v.end());  // Supprime réellement les éléments

auto newEnd2 = std::remove_if(v.begin(), v.end(), [](int n) { return n % 2 == 0; });  // "Supprime" les pairs
v.erase(newEnd2, v.end());  // Supprime réellement les éléments

// Réorganisation
std::reverse(v.begin(), v.end());  // Inverse l'ordre
std::rotate(v.begin(), v.begin() + 2, v.end());  // Rotation (éléments à partir de l'index 2 vont au début)
std::shuffle(v.begin(), v.end(), std::mt19937{std::random_device{}()});  // Mélange aléatoire
```

### Algorithmes de Tri et Recherche Binaire
```cpp
#include <algorithm>
#include <vector>

std::vector<int> v = {5, 2, 9, 1, 9, 4, 7};

// Tri
std::sort(v.begin(), v.end());  // Tri croissant
std::sort(v.begin(), v.end(), std::greater<int>());  // Tri décroissant
std::sort(v.begin(), v.end(), [](int a, int b) { return abs(a) < abs(b); });  // Tri par valeur absolue

// Tri partiel
std::partial_sort(v.begin(), v.begin() + 3, v.end());  // Trie juste pour avoir les 3 plus petits au début
std::nth_element(v.begin(), v.begin() + 3, v.end());  // Place le 4e élément à sa position et partitionne autour

// Recherche binaire (sur une plage triée)
bool found = std::binary_search(v.begin(), v.end(), 4);  // true si 4 est présent

// Bornes
auto lower = std::lower_bound(v.begin(), v.end(), 5);  // Premier élément >= 5
auto upper = std::upper_bound(v.begin(), v.end(), 5);  // Premier élément > 5
auto range = std::equal_range(v.begin(), v.end(), 5);  // Paire d'itérateurs {lower, upper}

// Fusion
std::vector<int> v1 = {1, 3, 5, 7};
std::vector<int> v2 = {2, 4, 6, 8};
std::vector<int> merged(v1.size() + v2.size());
std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), merged.begin());
// merged contient {1, 2, 3, 4, 5, 6, 7, 8}
```

### Algorithmes sur les Ensembles
```cpp
#include <algorithm>
#include <vector>

std::vector<int> v1 = {1, 2, 3, 4, 5};
std::vector<int> v2 = {4, 5, 6, 7, 8};
std::vector<int> result(10);  // Assez de place pour les résultats

// Union
auto it_end = std::set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), result.begin());
result.resize(std::distance(result.begin(), it_end));  // Redimensionne au nombre d'éléments réels
// result contient {1, 2, 3, 4, 5, 6, 7, 8}

// Intersection
result.resize(10);  // Réinitialise la taille
it_end = std::set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), result.begin());
result.resize(std::distance(result.begin(), it_end));
// result contient {4, 5}

// Différence
result.resize(10);
it_end = std::set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), result.begin());
result.resize(std::distance(result.begin(), it_end));
// result contient {1, 2, 3}

// Différence symétrique
result.resize(10);
it_end = std::set_symmetric_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), result.begin());
result.resize(std::distance(result.begin(), it_end));
// result contient {1, 2, 3, 6, 7, 8}
```

### Algorithmes Numériques
```cpp
#include <numeric>
#include <vector>
#include <functional>

std::vector<int> v = {1, 2, 3, 4, 5};

// Somme cumulée
int sum = std::accumulate(v.begin(), v.end(), 0);  // 15
int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());  // 120

// Produit scalaire
std::vector<int> v2 = {10, 20, 30, 40, 50};
int dot_product = std::inner_product(v.begin(), v.end(), v2.begin(), 0);  // 550

// Sommes partielles
std::vector<int> partial_sums(v.size());
std::partial_sum(v.begin(), v.end(), partial_sums.begin());
// partial_sums contient {1, 3, 6, 10, 15}

// Différences adjacentes
std::vector<int> diffs(v.size() - 1);
std::adjacent_difference(v.begin(), v.end(), diffs.begin());
// diffs contient {1, 1, 1, 1, 1}

// Génération de séquence
std::vector<int> seq(10);
std::iota(seq.begin(), seq.end(), 1);  // Remplit avec des valeurs croissantes à partir de 1
// seq contient {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
```

## 8. Fonctionnalités C++17 de la STL

### std::optional
```cpp
#include <optional>
#include <string>

// Fonction qui peut ne pas retourner de valeur
std::optional<std::string> trouverUtilisateur(int id) {
    if (id == 1) {
        return "Alice";
    } else if (id == 2) {
        return "Bob";
    }
    return std::nullopt;  // Pas de résultat
}

// Utilisation
auto resultat = trouverUtilisateur(3);
if (resultat) {
    std::cout << "Utilisateur trouvé: " << *resultat << std::endl;
} else {
    std::cout << "Utilisateur non trouvé" << std::endl;
}

// Valeur par défaut
std::string nom = resultat.value_or("Inconnu");
```

### std::variant
```cpp
#include <variant>
#include <string>

// Type qui peut contenir soit un int, soit une string, soit un double
std::variant<int, std::string, double> data;

// Assigner différents types
data = 42;
data = "Hello";
data = 3.14;

// Vérifier le type actuellement stocké
if (std::holds_alternative<int>(data)) {
    std::cout << "C'est un int: " << std::get<int>(data) << std::endl;
} else if (std::holds_alternative<std::string>(data)) {
    std::cout << "C'est une string: " << std::get<std::string>(data) << std::endl;
} else {
    std::cout << "C'est un double: " << std::get<double>(data) << std::endl;
}

// Visiteur pour traiter tous les cas
struct Visiteur {
    void operator()(int i) { std::cout << "Int: " << i << std::endl; }
    void operator()(const std::string& s) { std::cout << "String: " << s << std::endl; }
    void operator()(double d) { std::cout << "Double: " << d << std::endl; }
};

std::visit(Visiteur{}, data);
```

### std::any
```cpp
#include <any>
#include <string>

// Peut stocker n'importe quel type
std::any value;

// Assigner différentes valeurs
value = 42;
value = std::string("Hello");
value = 3.14;

// Récupérer la valeur (avec vérification de type)
try {
    std::cout << std::any_cast<int>(value) << std::endl;  // Lance une exception si pas un int
} catch (const std::bad_any_cast& e) {
    std::cout << "Mauvais type!" << std::endl;
}

// Vérifier si une valeur est stockée
if (value.has_value()) {
    std::cout << "Contient une valeur de type: " << value.type().name() << std::endl;
} else {
    std::cout << "Ne contient pas de valeur" << std::endl;
}
```

### std::string_view
```cpp
#include <string_view>
#include <string>

// Vue légère sur une chaîne existante (pas de copie)
std::string original = "Hello, world!";
std::string_view view = original;  // Pas de copie

// Opérations efficaces
std::string_view first_word = view.substr(0, 5);  // Pas de copie, juste une nouvelle vue
std::cout << first_word << std::endl;  // "Hello"

// Comparaison efficace
if (first_word == "Hello") {
    std::cout << "C'est Hello!" << std::endl;
}

// Utilisation avec des chaînes littérales
void process(std::string_view sv) {
    std::cout << "Traitement de: " << sv << std::endl;
}

process("Hello");  // Pas de conversion en std::string nécessaire
process(original); // Fonctionne aussi avec std::string
```

### std::filesystem
```cpp
#include <filesystem>
#include <iostream>
namespace fs = std::filesystem;

// Manipulation de chemins
fs::path p = "C:/Users/Alice/Documents/file.txt";
std::cout << "Extension: " << p.extension() << std::endl;
std::cout << "Filename: " << p.filename() << std::endl;
std::cout << "Parent: " << p.parent_path() << std::endl;

// Création de répertoires
fs::create_directories("temp/nested/dir");

// Vérification d'existence
if (fs::exists(p)) {
    std::cout << "Le fichier existe" << std::endl;
}

// Itération sur les fichiers d'un répertoire
for (const auto& entry : fs::directory_iterator("temp")) {
    std::cout << entry.path() << std::endl;
}

// Obtention d'informations sur les fichiers
fs::space_info si = fs::space("C:");
std::cout << "Espace libre: " << si.available / (1024*1024) << " MB" << std::endl;

// Copie et déplacement de fichiers
fs::copy_file("source.txt", "destination.txt", fs::copy_options::overwrite_existing);
fs::rename("old_name.txt", "new_name.txt");
```

## Conclusion

La bibliothèque standard C++ est un élément essentiel de l'écosystème C++, offrant une riche collection de structures de données, d'algorithmes et d'utilitaires. Sa maîtrise est indispensable pour écrire du code C++ efficace, maintenable et robuste.

Les conteneurs et les algorithmes de la STL ont été conçus pour offrir des performances optimales tout en garantissant la sûreté de type et la généricité. Les nouvelles fonctionnalités ajoutées en C++11, C++14 et C++17 rendent le code plus expressif et éliminent la nécessité d'implémenter des solutions personnalisées pour de nombreux problèmes courants.

Dans le développement de jeux, la STL offre des outils précieux pour gérer les collections d'objets, implementer des algorithmes complexes, et manipuler les ressources du système de manière efficace, contribuant ainsi à créer des jeux robustes et performants.

## Ressources Complémentaires

- [C++ Reference: Standard Library](https://en.cppreference.com/w/cpp/standard_library) - Documentation officielle
- [Effective STL](https://www.amazon.com/Effective-STL-Specific-Standard-Template/dp/0201749629) par Scott Meyers
- [The C++ Standard Library: A Tutorial and Reference](https://www.amazon.com/Standard-Library-Tutorial-Reference-2nd/dp/0321623215) par Nicolai Josuttis
- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines) - Section STL
- [STL Algorithms Cheat Sheet](https://github.com/mortennobel/cpp-cheatsheet) - Aide-mémoire pour les algorithmes STL
