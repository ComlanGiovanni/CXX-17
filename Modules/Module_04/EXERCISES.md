# Exercices du Module 4: Templates et Programmation Générique

## Exercice 1: Fonctions Templates

### 1.1 Fonctions Mathématiques Génériques
Implémentez des fonctions templates pour les opérations mathématiques suivantes:
1. `min` et `max` qui fonctionnent avec n'importe quel type comparable
2. `clamp` qui limite une valeur entre un minimum et un maximum
3. `abs` qui retourne la valeur absolue (avec spécialisation pour les types signés)
4. `isPrime` qui vérifie si un nombre est premier (pour les types entiers)

```cpp
// Exemple d'utilisation:
int a = 5, b = 10;
double c = 3.14, d = 2.71;
std::string s1 = "abc", s2 = "xyz";

std::cout << "Min(5, 10): " << min(a, b) << std::endl;
std::cout << "Max(3.14, 2.71): " << max(c, d) << std::endl;
std::cout << "Min(abc, xyz): " << min(s1, s2) << std::endl;
std::cout << "Clamp(15, 0, 10): " << clamp(15, 0, 10) << std::endl;
std::cout << "Abs(-3.14): " << abs(-c) << std::endl;
std::cout << "IsPrime(7): " << isPrime(7) << std::endl;
```

### 1.2 Manipulations de Tableaux Génériques
Créez des fonctions templates qui manipulent des tableaux de n'importe quel type:
1. `sum` qui calcule la somme des éléments
2. `average` qui calcule la moyenne des éléments
3. `find` qui trouve la première occurrence d'une valeur
4. `count` qui compte les occurrences d'une valeur
5. `filter` qui retourne un nouveau tableau avec les éléments qui respectent un prédicat

```cpp
// Exemples de signatures:
template<typename T, size_t N>
T sum(const T (&array)[N]);

template<typename T, size_t N>
auto average(const T (&array)[N]) -> decltype(sum(array) / N);

template<typename T, size_t N>
int find(const T (&array)[N], const T& value);

template<typename T, size_t N, typename Predicate>
std::vector<T> filter(const T (&array)[N], Predicate pred);
```

### 1.3 Déduction de Type et SFINAE
Explorez la déduction de type et SFINAE (Substitution Failure Is Not An Error):
1. Créez une fonction template qui n'accepte que les types numériques
2. Écrivez une fonction qui n'accepte que les types qui ont un opérateur `<<`
3. Implémentez une fonction qui se comporte différemment pour les types pointeurs
4. Démontrez comment utiliser `std::enable_if` pour sélectionner des implémentations

```cpp
// Exemple avec enable_if:
template<typename T>
typename std::enable_if<std::is_arithmetic<T>::value, T>::type
square(T x) {
    return x * x;
}

// Cette version ne sera pas compilée avec des types non-arithmétiques
// square("hello"); // Erreur!
```

## Exercice 2: Classes Templates

### 2.1 Pile Générique
Implémentez une classe template `Stack` qui:
1. Stocke des éléments de n'importe quel type
2. Fournit des méthodes `push`, `pop`, `top`, `empty` et `size`
3. Permet de spécifier une taille maximale comme paramètre template non-type
4. Inclut une méthode template pour trouver un élément

```cpp
// Exemple d'utilisation:
Stack<int, 10> intStack;
intStack.push(1);
intStack.push(2);
intStack.push(3);

std::cout << "Top: " << intStack.top() << std::endl;
std::cout << "Size: " << intStack.size() << std::endl;

intStack.pop();
std::cout << "After pop: " << intStack.top() << std::endl;
```

### 2.2 Classe Conteneur avec Plusieurs Paramètres
Créez une classe template `Pair` qui:
1. Stocke deux valeurs de types potentiellement différents
2. Fournit des accesseurs et des mutateurs pour les deux valeurs
3. Surcharge les opérateurs de comparaison
4. Implémente une spécialisation pour les paires de même type

```cpp
// Exemple d'utilisation:
Pair<int, double> p1(1, 2.5);
Pair<std::string, int> p2("Hello", 42);
Pair<int, int> p3(10, 20);

std::cout << "p1: " << p1.first() << ", " << p1.second() << std::endl;
std::cout << "p2: " << p2.first() << ", " << p2.second() << std::endl;
std::cout << "p3 sum: " << p3.sum() << std::endl; // Disponible seulement pour types identiques
```

### 2.3 Spécialisation de Classes Templates
Implémentez une classe template `TypeTraits` qui fournit des informations sur différents types:
1. La classe de base doit fournir des informations génériques
2. Créez des spécialisations complètes pour `int`, `double`, `char`, `bool`
3. Ajoutez une spécialisation partielle pour les pointeurs
4. Fournissez des informations comme le nom du type, la taille, et des propriétés

```cpp
// Exemple d'utilisation:
std::cout << "Int: " << TypeTraits<int>::name() << ", "
          << TypeTraits<int>::size() << " bytes" << std::endl;
std::cout << "Double: " << TypeTraits<double>::name() << ", "
          << TypeTraits<double>::size() << " bytes" << std::endl;
std::cout << "Int*: " << TypeTraits<int*>::name() << ", "
          << TypeTraits<int*>::size() << " bytes" << std::endl;
```

## Exercice 3: Templates de Variables et Méta-fonctions

### 3.1 Constantes Typées
Définissez des templates de variables pour des constantes mathématiques:
1. `PI` pour différents types de précision
2. `E` (nombre d'Euler)
3. `GOLDEN_RATIO`
4. `EPSILON` adapté au type

```cpp
// Exemple d'utilisation:
std::cout << "PI<float>: " << PI<float> << std::endl;
std::cout << "PI<double>: " << PI<double> << std::endl;
std::cout << "E<float>: " << E<float> << std::endl;
std::cout << "GOLDEN_RATIO<double>: " << GOLDEN_RATIO<double> << std::endl;
std::cout << "EPSILON<float>: " << EPSILON<float> << std::endl;
```

### 3.2 Séquences de Nombres à la Compilation
Utilisez la méta-programmation template pour calculer:
1. La factorielle d'un nombre à la compilation
2. Le n-ième nombre de la suite de Fibonacci
3. Le PGCD de deux nombres
4. La puissance d'un nombre

```cpp
// Exemple d'utilisation:
constexpr int fact5 = Factorial<5>::value;  // 120
constexpr int fib7 = Fibonacci<7>::value;   // 13
constexpr int gcd_result = GCD<24, 18>::value;  // 6
constexpr int pow_result = Power<2, 8>::value;  // 256

std::cout << "5! = " << fact5 << std::endl;
std::cout << "Fibonacci(7) = " << fib7 << std::endl;
std::cout << "GCD(24, 18) = " << gcd_result << std::endl;
std::cout << "2^8 = " << pow_result << std::endl;
```

### 3.3 Méta-fonctions sur les Types
Implémentez des méta-fonctions pour manipuler des types:
1. `RemovePointer` qui supprime un niveau de pointeur du type
2. `IsConvertible` qui vérifie si un type est convertible en un autre
3. `LargerType` qui retourne le type avec la plus grande taille
4. `CommonType` qui trouve un type commun entre deux types

```cpp
// Exemple d'utilisation:
using NonPointerType = RemovePointer<int*>::type;  // int
constexpr bool convertible = IsConvertible<int, double>::value;  // true
using Larger = LargerType<int, double>::type;  // double
using Common = CommonType<int, float>::type;  // float

std::cout << "sizeof(NonPointerType): " << sizeof(NonPointerType) << std::endl;
std::cout << "Int convertible to double: " << convertible << std::endl;
std::cout << "Larger between int and double: " << sizeof(Larger) << " bytes" << std::endl;
std::cout << "Common type size: " << sizeof(Common) << " bytes" << std::endl;
```

## Exercice 4: Applications Pratiques

### 4.1 Conteneurs Génériques
Implémentez deux conteneurs génériques:
1. `CircularBuffer<T, Size>` - un buffer circulaire à taille fixe
2. `SparseArray<T>` - un tableau clairsemé (efficace pour les grandes tailles avec peu d'éléments non-nuls)

```cpp
// Exemple pour CircularBuffer:
CircularBuffer<int, 5> buffer;
for (int i = 0; i < 7; i++) {
    buffer.push(i);  // Après 5 éléments, commence à écraser les plus anciens
}
buffer.print();  // Affiche: 2 3 4 5 6

// Exemple pour SparseArray:
SparseArray<double> array(1000);  // Peut stocker 1000 éléments
array[500] = 3.14;
array[999] = 2.71;
std::cout << "Memory usage: " << array.memory_usage() << " bytes" << std::endl;
```

### 4.2 Algorithmes Génériques
Implémentez des versions génériques des algorithmes suivants:
1. Tri par fusion (Merge Sort)
2. Recherche binaire
3. Transformation Map/Reduce
4. Génération de permutations

Assurez-vous que vos implémentations fonctionnent avec différents types et respectent les contraintes appropriées.

```cpp
// Exemple:
std::vector<int> numbers = {5, 2, 9, 1, 7, 6, 3};
merge_sort(numbers);
print(numbers);  // Sorted

std::vector<std::string> words = {"apple", "orange", "banana", "grape"};
merge_sort(words);
print(words);  // Sorted alphabetically

auto doubled = map(numbers, [](int x) { return x * 2; });
print(doubled);

int sum = reduce(numbers, 0, [](int acc, int x) { return acc + x; });
std::cout << "Sum: " << sum << std::endl;
```

### 4.3 Factory Design Pattern avec Templates
Implémentez un système de Factory générique:
1. Une interface de base `Product`
2. Plusieurs classes dérivées
3. Une classe Factory template qui crée des objets du type spécifié
4. Un registre de factory permettant l'instanciation par chaîne de caractères

```cpp
// Exemple:
// Enregistrer des types
FactoryRegistry::register<Circle>("circle");
FactoryRegistry::register<Rectangle>("rectangle");
FactoryRegistry::register<Triangle>("triangle");

// Créer des objets
Shape* circle = FactoryRegistry::create("circle");
Shape* rectangle = FactoryRegistry::create("rectangle");

// Utiliser le polymorphisme
circle->draw();
rectangle->draw();

// Nettoyage
delete circle;
delete rectangle;
```

## Exercice 5: Concepts (C++20)

### 5.1 Définition de Concepts
Définissez les concepts suivants:
1. `Sortable` - un type qui peut être trié (a les opérateurs < et ==)
2. `Hashable` - un type qui peut être utilisé comme clé dans une map (peut être haché)
3. `Serializable` - un type qui peut être sérialisé (a les méthodes to_string et from_string)
4. `Drawable` - un type qui peut être dessiné (a une méthode draw)

```cpp
// Exemple:
template <typename T>
concept Sortable = requires(T a, T b) {
    { a < b } -> std::convertible_to<bool>;
    { a == b } -> std::convertible_to<bool>;
};

template <Sortable T>
void sort(std::vector<T>& collection) {
    // Implémentation qui utilise < et ==
}

// Ne compilera pas si T ne respecte pas le concept
sort(std::vector<int>{3, 1, 2});  // OK
// sort(std::vector<std::mutex>{});  // Erreur: std::mutex n'est pas Sortable
```

### 5.2 Utilisation des Concepts Standard
Utilisez les concepts standard de C++20 pour:
1. Écrire une fonction qui n'accepte que des types numériques
2. Créer une classe template qui nécessite des types comparables
3. Implémenter un algorithme qui exige des types copiables et assignables
4. Développer une fonction qui prend des itérateurs

```cpp
// Exemple:
template <std::integral T>
bool is_even(T value) {
    return value % 2 == 0;
}

template <std::floating_point T>
T round_to_precision(T value, int precision) {
    // Implémentation
}

template <std::equality_comparable T>
class UniqueContainer {
    // Implémentation
};
```

### 5.3 Composition de Concepts
Créez des concepts composés:
1. `NumericType` - soit un entier soit un flottant
2. `Container` - a une taille, est itérable, et a des méthodes d'accès
3. `StringLike` - peut être converti en std::string et a des opérations de chaîne
4. `MathObject` - a des opérations mathématiques de base

```cpp
// Exemple:
template <typename T>
concept NumericType = std::integral<T> || std::floating_point<T>;

template <typename T>
concept Container = requires(T container) {
    { container.size() } -> std::convertible_to<std::size_t>;
    { container.begin() };
    { container.end() };
    { container[0] };  // Accès par indice
};

template <NumericType T>
T square_root(T value) {
    if constexpr (std::integral<T>) {
        return static_cast<T>(std::sqrt(static_cast<double>(value)));
    } else {
        return std::sqrt(value);
    }
}
```

## Projet Mini: Bibliothèque de Mathématiques Génériques

Développez une bibliothèque de mathématiques génériques qui démontre les concepts du module:

1. **Classes de Vecteurs et Matrices**:
   - Template `Vector<T, N>` pour les vecteurs N-dimensionnels
   - Template `Matrix<T, Rows, Cols>` pour les matrices
   - Opérations appropriées (addition, multiplication, produit scalaire, etc.)

2. **Algorithmes Mathématiques**:
   - Méthodes numériques génériques (Newton-Raphson, intégration, etc.)
   - Fonctionnalités statistiques (moyenne, médiane, écart-type)
   - Transformations géométriques

3. **Spécialisations Optimisées**:
   - Spécialisations pour les cas courants (Vector<float, 3>, Matrix<double, 4, 4>)
   - Optimisations SIMD pour les types flottants quand c'est possible

4. **Contraintes et Concepts**:
   - Utilisation de concepts (C++20) ou SFINAE pour garantir la validité des opérations
   - Messages d'erreur clairs lorsque les contraintes ne sont pas respectées

5. **Application de Démonstration**:
   - Un petit programme qui utilise la bibliothèque pour résoudre un problème réel
   - Documentation des performances et comparaison avec d'autres solutions

Ce projet vous permettra d'appliquer en profondeur la programmation générique et de comprendre comment les templates peuvent être utilisés pour créer des bibliothèques performantes et type-safe.
