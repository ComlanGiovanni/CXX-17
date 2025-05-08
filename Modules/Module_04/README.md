# Module 4: Templates et Programmation Générique

Ce module explore les templates et la programmation générique en C++, des outils puissants permettant d'écrire du code réutilisable qui fonctionne avec différents types de données, essentiels pour le développement de bibliothèques et moteurs de jeux efficaces.

## 1. Fonctions Templates

### Principe et Syntaxe de Base
```cpp
// Fonction template simple
template<typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

// Utilisation avec différents types
int a = 5, b = 7;
std::cout << "Max int: " << maximum(a, b) << std::endl;      // 7

double c = 3.14, d = 2.71;
std::cout << "Max double: " << maximum(c, d) << std::endl;   // 3.14

std::string s1 = "abc", s2 = "xyz";
std::cout << "Max string: " << maximum(s1, s2) << std::endl; // "xyz"

// Le compilateur génère automatiquement trois versions de la fonction
```

### Déduction de Type
```cpp
template<typename T>
void afficher(const T& valeur) {
    std::cout << valeur << std::endl;
}

// Le compilateur déduit le type automatiquement
afficher(42);        // T est int
afficher(3.14159);   // T est double
afficher("Bonjour"); // T est const char*
afficher(std::string("Hello")); // T est std::string

// Déduction pour les littéraux
auto i = 42;         // int
auto d = 42.0;       // double
auto s = "hello";    // const char*
```

### Templates avec Plusieurs Paramètres
```cpp
// Template avec deux types différents
template<typename T, typename U>
auto addition(T a, U b) -> decltype(a + b) {
    return a + b;
}

// Utilisation
int entier = 5;
double decimal = 3.14;
auto resultat = addition(entier, decimal); // resultat est double (8.14)
std::cout << "Type de resultat: " << typeid(resultat).name() << std::endl;

// Template avec paramètres de type et de valeur
template<typename T, int Taille>
void afficherTableau(const T (&tableau)[Taille]) {
    for (int i = 0; i < Taille; i++) {
        std::cout << tableau[i] << " ";
    }
    std::cout << std::endl;
}

// Utilisation
int nombres[5] = {1, 2, 3, 4, 5};
afficherTableau(nombres); // Déduit T=int, Taille=5
```

### Spécialisation de Fonctions Templates
```cpp
// Template général
template<typename T>
void traiter(T valeur) {
    std::cout << "Traitement générique: " << valeur << std::endl;
}

// Spécialisation pour le type int
template<>
void traiter<int>(int valeur) {
    std::cout << "Traitement spécialisé pour int: " << valeur << std::endl;
}

// Spécialisation pour le type char*
template<>
void traiter<const char*>(const char* valeur) {
    std::cout << "Traitement spécialisé pour chaîne: " << valeur << std::endl;
}

// Utilisation
traiter(42);           // "Traitement spécialisé pour int: 42"
traiter(3.14);         // "Traitement générique: 3.14"
traiter("bonjour");    // "Traitement spécialisé pour chaîne: bonjour"
```

## 2. Classes Templates

### Définition et Utilisation
```cpp
// Classe template simple: une pile
template<typename T>
class Pile {
private:
    std::vector<T> elements;

public:
    void empiler(const T& element) {
        elements.push_back(element);
    }

    T depiler() {
        if (elements.empty()) {
            throw std::out_of_range("Pile vide");
        }
        T element = elements.back();
        elements.pop_back();
        return element;
    }

    bool estVide() const {
        return elements.empty();
    }

    size_t taille() const {
        return elements.size();
    }
};

// Utilisation avec différents types
Pile<int> pileEntiers;
pileEntiers.empiler(1);
pileEntiers.empiler(2);
pileEntiers.empiler(3);
std::cout << pileEntiers.depiler() << std::endl; // 3

Pile<std::string> pileChaines;
pileChaines.empiler("un");
pileChaines.empiler("deux");
std::cout << pileChaines.depiler() << std::endl; // "deux"
```

### Classes Templates avec Plusieurs Paramètres
```cpp
// Classe template avec plusieurs paramètres de type
template<typename Cle, typename Valeur>
class Dictionnaire {
private:
    std::map<Cle, Valeur> donnees;

public:
    void ajouter(const Cle& cle, const Valeur& valeur) {
        donnees[cle] = valeur;
    }

    Valeur obtenir(const Cle& cle) const {
        auto it = donnees.find(cle);
        if (it == donnees.end()) {
            throw std::out_of_range("Clé non trouvée");
        }
        return it->second;
    }

    bool contient(const Cle& cle) const {
        return donnees.find(cle) != donnees.end();
    }
};

// Utilisation
Dictionnaire<std::string, int> ages;
ages.ajouter("Alice", 30);
ages.ajouter("Bob", 25);
std::cout << "Âge de Bob: " << ages.obtenir("Bob") << std::endl; // 25

// Classe template avec paramètre de type et valeur
template<typename T, size_t Capacite>
class TableauFixe {
private:
    T donnees[Capacite];
    size_t taille_actuelle = 0;

public:
    bool ajouter(const T& element) {
        if (taille_actuelle >= Capacite) {
            return false;
        }
        donnees[taille_actuelle++] = element;
        return true;
    }

    T& operator[](size_t index) {
        if (index >= taille_actuelle) {
            throw std::out_of_range("Index hors limites");
        }
        return donnees[index];
    }

    size_t taille() const {
        return taille_actuelle;
    }

    size_t capacite() const {
        return Capacite;
    }
};

// Utilisation
TableauFixe<int, 5> tableau;
tableau.ajouter(1);
tableau.ajouter(2);
tableau.ajouter(3);
std::cout << "Élément 1: " << tableau[1] << std::endl; // 2
std::cout << "Taille: " << tableau.taille() << std::endl; // 3
std::cout << "Capacité: " << tableau.capacite() << std::endl; // 5
```

### Spécialisation de Classes Templates
```cpp
// Template général
template<typename T>
class Conteneur {
private:
    T donnee;

public:
    Conteneur(const T& val) : donnee(val) {}

    void afficher() const {
        std::cout << "Conteneur générique: " << donnee << std::endl;
    }

    T obtenir() const {
        return donnee;
    }
};

// Spécialisation complète pour bool
template<>
class Conteneur<bool> {
private:
    bool donnee;

public:
    Conteneur(bool val) : donnee(val) {}

    void afficher() const {
        std::cout << "Conteneur booléen: " << (donnee ? "vrai" : "faux") << std::endl;
    }

    bool obtenir() const {
        return donnee;
    }
};

// Spécialisation partielle pour les pointeurs
template<typename T>
class Conteneur<T*> {
private:
    T* donnee;

public:
    Conteneur(T* val) : donnee(val) {}

    void afficher() const {
        if (donnee) {
            std::cout << "Conteneur de pointeur: " << *donnee << std::endl;
        } else {
            std::cout << "Conteneur de pointeur: nullptr" << std::endl;
        }
    }

    T* obtenir() const {
        return donnee;
    }

    ~Conteneur() {
        // Ne libère pas la mémoire automatiquement
    }
};

// Utilisation
Conteneur<int> c1(42);
c1.afficher(); // "Conteneur générique: 42"

Conteneur<bool> c2(true);
c2.afficher(); // "Conteneur booléen: vrai"

int* p = new int(10);
Conteneur<int*> c3(p);
c3.afficher(); // "Conteneur de pointeur: 10"
delete p;
```

### Templates de Méthodes
```cpp
class Utilitaire {
public:
    // Méthode template dans une classe non-template
    template<typename T>
    static T minimum(const T& a, const T& b) {
        return (a < b) ? a : b;
    }

    // Méthode template avec plusieurs paramètres
    template<typename T, typename U>
    static auto multiplie(const T& a, const U& b) -> decltype(a * b) {
        return a * b;
    }
};

// Utilisation
int min_int = Utilitaire::minimum(10, 5);
double min_double = Utilitaire::minimum(3.14, 2.71);
auto produit = Utilitaire::multiplie(2, 3.5); // 7.0
```

## 3. Templates de Variables (C++14)

### Syntaxe et Exemples
```cpp
template<typename T>
constexpr T PI = T(3.1415926535897932385);

// Utilisation avec différents types
float rayon_f = 2.0f;
double rayon_d = 2.0;

float aire_f = PI<float> * rayon_f * rayon_f;
double aire_d = PI<double> * rayon_d * rayon_d;

std::cout << "Aire (float): " << aire_f << std::endl;
std::cout << "Aire (double): " << aire_d << std::endl;

// Template de variable avec plusieurs paramètres
template<typename T, size_t N>
std::array<T, N> zeros = {};  // Tableau initialisé à zéro

// Utilisation
auto zeros_int5 = zeros<int, 5>; // array<int, 5> initialisé à zéro
auto zeros_double3 = zeros<double, 3>; // array<double, 3> initialisé à zéro
```

### Cas d'Utilisation
```cpp
// Constantes typées
template<typename T>
constexpr T EPSILON = std::numeric_limits<T>::epsilon();

// Valeurs par défaut adaptées au type
template<typename T>
constexpr T DEFAULT_VALUE = T();

template<>
constexpr int DEFAULT_VALUE<int> = -1;

template<>
constexpr std::string DEFAULT_VALUE<std::string> = "undefined";

// Utilisation
double epsilon_double = EPSILON<double>;
float epsilon_float = EPSILON<float>;

int default_int = DEFAULT_VALUE<int>; // -1
std::string default_str = DEFAULT_VALUE<std::string>; // "undefined"
double default_double = DEFAULT_VALUE<double>; // 0.0
```

## 4. Spécialisation de Templates

### Spécialisation Complète
```cpp
// Template général
template<typename T>
class TypeInfo {
public:
    static std::string name() {
        return "Type inconnu";
    }
};

// Spécialisation complète pour int
template<>
class TypeInfo<int> {
public:
    static std::string name() {
        return "int";
    }
};

// Spécialisation complète pour double
template<>
class TypeInfo<double> {
public:
    static std::string name() {
        return "double";
    }
};

// Spécialisation complète pour std::string
template<>
class TypeInfo<std::string> {
public:
    static std::string name() {
        return "std::string";
    }
};

// Utilisation
std::cout << TypeInfo<int>::name() << std::endl;         // "int"
std::cout << TypeInfo<double>::name() << std::endl;      // "double"
std::cout << TypeInfo<std::string>::name() << std::endl; // "std::string"
std::cout << TypeInfo<float>::name() << std::endl;       // "Type inconnu"
```

### Spécialisation Partielle
```cpp
// Template général
template<typename T, typename U>
class Paire {
private:
    T premier;
    U second;

public:
    Paire(const T& p, const U& s) : premier(p), second(s) {}

    void afficher() const {
        std::cout << "Paire générique: (" << premier << ", " << second << ")" << std::endl;
    }
};

// Spécialisation partielle quand les deux types sont identiques
template<typename T>
class Paire<T, T> {
private:
    T premier;
    T second;

public:
    Paire(const T& p, const T& s) : premier(p), second(s) {}

    void afficher() const {
        std::cout << "Paire homogène: (" << premier << ", " << second << ")" << std::endl;
    }

    T somme() const {
        return premier + second;
    }
};

// Spécialisation partielle pour les pointeurs
template<typename T, typename U>
class Paire<T*, U*> {
private:
    T* premier;
    U* second;

public:
    Paire(T* p, U* s) : premier(p), second(s) {}

    void afficher() const {
        std::cout << "Paire de pointeurs: (";
        if (premier) std::cout << *premier; else std::cout << "nullptr";
        std::cout << ", ";
        if (second) std::cout << *second; else std::cout << "nullptr";
        std::cout << ")" << std::endl;
    }
};

// Utilisation
Paire<int, std::string> p1(42, "test");
p1.afficher(); // "Paire générique: (42, test)"

Paire<double, double> p2(3.14, 2.71);
p2.afficher(); // "Paire homogène: (3.14, 2.71)"
std::cout << "Somme: " << p2.somme() << std::endl; // 5.85

int a = 10, b = 20;
Paire<int*, int*> p3(&a, &b);
p3.afficher(); // "Paire de pointeurs: (10, 20)"
```

### Spécialisation pour les Tableaux
```cpp
// Template général
template<typename T>
class Tableau {
private:
    T* elements;
    size_t taille_;

public:
    Tableau(size_t n) : taille_(n) {
        elements = new T[n]();
    }

    ~Tableau() {
        delete[] elements;
    }

    T& operator[](size_t index) {
        return elements[index];
    }

    size_t taille() const {
        return taille_;
    }

    void afficher() const {
        std::cout << "Tableau de " << taille_ << " éléments: ";
        for (size_t i = 0; i < taille_; i++) {
            std::cout << elements[i] << " ";
        }
        std::cout << std::endl;
    }
};

// Spécialisation pour les tableaux de bool (optimisation de l'espace)
template<>
class Tableau<bool> {
private:
    std::vector<uint8_t> bits;
    size_t taille_;

public:
    Tableau(size_t n) : taille_(n) {
        bits.resize((n + 7) / 8, 0); // 8 booléens par octet
    }

    // Classe proxy pour simuler une référence à un bit
    class BitReference {
    private:
        uint8_t& byte;
        uint8_t mask;

    public:
        BitReference(uint8_t& b, uint8_t m) : byte(b), mask(m) {}

        BitReference& operator=(bool value) {
            if (value) {
                byte |= mask;
            } else {
                byte &= ~mask;
            }
            return *this;
        }

        operator bool() const {
            return (byte & mask) != 0;
        }
    };

    BitReference operator[](size_t index) {
        return BitReference(bits[index / 8], (1 << (index % 8)));
    }

    size_t taille() const {
        return taille_;
    }

    void afficher() const {
        std::cout << "Tableau optimisé de " << taille_ << " booléens: ";
        for (size_t i = 0; i < taille_; i++) {
            std::cout << ((*this)[i] ? "1" : "0") << " ";
        }
        std::cout << std::endl;
    }
};

// Utilisation
Tableau<int> tab1(5);
tab1[0] = 10;
tab1[1] = 20;
tab1.afficher(); // "Tableau de 5 éléments: 10 20 0 0 0"

Tableau<bool> tab2(10);
tab2[1] = true;
tab2[4] = true;
tab2[7] = true;
tab2.afficher(); // "Tableau optimisé de 10 booléens: 0 1 0 0 1 0 0 1 0 0"
```

## 5. Introduction aux Concepts (C++20)

### Problématique des Contraintes Templates
```cpp
// Template sans contrainte
template<typename T>
T ajouter(T a, T b) {
    return a + b;  // Requiert que T supporte l'opérateur +
}

// Problème: erreur cryptique si T ne supporte pas +
struct Point { int x, y; };  // Pas d'opérateur + défini

// ajouter(Point{1, 2}, Point{3, 4});  // Erreur de compilation obscure

// Solution pré-C++20: SFINAE (Substitution Failure Is Not An Error)
template<typename T>
typename std::enable_if<std::is_arithmetic<T>::value, T>::type
ajouter_sfinae(T a, T b) {
    return a + b;
}

// ajouter_sfinae(Point{1, 2}, Point{3, 4});  // Erreur: pas de correspondance de fonction
```

### Concepts de Base (C++20)
```cpp
#include <concepts>

// Définition d'un concept simple
template<typename T>
concept Addable = requires(T a, T b) {
    { a + b } -> std::convertible_to<T>;  // Vérifie que a + b retourne quelque chose convertible en T
};

// Utilisation du concept dans une fonction template
template<Addable T>
T ajouter_avec_concept(T a, T b) {
    return a + b;
}

// Maintenant l'erreur sera plus claire si T ne respecte pas le concept
// ajouter_avec_concept(Point{1, 2}, Point{3, 4});  // Erreur: 'Point' ne satisfait pas le concept 'Addable'

// Concept plus complexe
template<typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;

template<Numeric T>
T carre(T x) {
    return x * x;
}

// carre(Point{1, 2});  // Erreur: 'Point' ne satisfait pas le concept 'Numeric'
```

### Concepts Prédéfinis en C++20
```cpp
#include <concepts>

// Utilisation de concepts standard
template<std::integral T>
bool est_pair(T n) {
    return n % 2 == 0;
}

template<std::floating_point T>
T arrondi(T x) {
    return std::round(x);
}

// Composition de concepts
template<typename T>
concept ComparableEtAffichable = std::equality_comparable<T> && requires(T a, std::ostream& os) {
    { os << a } -> std::same_as<std::ostream&>;
};

template<ComparableEtAffichable T>
void afficher_si_egal(const T& a, const T& b) {
    if (a == b) {
        std::cout << a << " est égal à " << b << std::endl;
    } else {
        std::cout << a << " n'est pas égal à " << b << std::endl;
    }
}
```

### Syntaxes Alternatives (C++20)
```cpp
// Syntaxe avec requires clause
template<typename T>
requires std::integral<T>
T increment(T x) {
    return x + 1;
}

// Syntaxe avec contrainte en ligne
template<typename T>
T decrement(T x) requires std::integral<T> {
    return x - 1;
}

// Syntaxe abrégée (auto)
auto multiply(std::integral auto x, std::integral auto y) {
    return x * y;
}

// Syntaxe abrégée avec requires
auto divide(auto x, auto y) requires std::floating_point<decltype(x)> && std::floating_point<decltype(y)> {
    return x / y;
}
```

## 6. Méta-programmation Basique

### Calculs à la Compilation
```cpp
// Factorielle à la compilation
template<unsigned int N>
struct Factorielle {
    static constexpr unsigned int valeur = N * Factorielle<N - 1>::valeur;
};

// Cas de base (spécialisation)
template<>
struct Factorielle<0> {
    static constexpr unsigned int valeur = 1;
};

// Utilisation
constexpr unsigned int fact5 = Factorielle<5>::valeur;  // 120, calculé à la compilation
std::cout << "5! = " << fact5 << std::endl;

// Version moderne avec constexpr (C++14)
constexpr unsigned int factorielle(unsigned int n) {
    return (n <= 1) ? 1 : (n * factorielle(n - 1));
}

constexpr unsigned int fact6 = factorielle(6);  // 720, calculé à la compilation
std::cout << "6! = " << fact6 << std::endl;
```

### Méta-fonctions sur les Types
```cpp
// Vérifier si un type est un pointeur
template<typename T>
struct EstPointeur {
    static constexpr bool valeur = false;
};

template<typename T>
struct EstPointeur<T*> {
    static constexpr bool valeur = true;
};

// Vérifier si deux types sont identiques
template<typename T, typename U>
struct SontMemeType {
    static constexpr bool valeur = false;
};

template<typename T>
struct SontMemeType<T, T> {
    static constexpr bool valeur = true;
};

// Obtenir le type sous-jacent d'un pointeur
template<typename T>
struct TypeSousJacent {
    using type = T;
};

template<typename T>
struct TypeSousJacent<T*> {
    using type = T;
};

// Utilisation
std::cout << "int* est un pointeur: " << EstPointeur<int*>::valeur << std::endl;      // true
std::cout << "int est un pointeur: " << EstPointeur<int>::valeur << std::endl;        // false

std::cout << "int et int sont identiques: " << SontMemeType<int, int>::valeur << std::endl;      // true
std::cout << "int et double sont identiques: " << SontMemeType<int, double>::valeur << std::endl; // false

using Type1 = TypeSousJacent<int*>::type;  // int
using Type2 = TypeSousJacent<int>::type;   // int
```

### Sélection de Types Conditionnelle
```cpp
// Meta-fonction ternaire pour les types
template<bool Condition, typename T, typename U>
struct TypeSi {
    using type = T;
};

template<typename T, typename U>
struct TypeSi<false, T, U> {
    using type = U;
};

// Déterminer le type avec la plus grande précision
template<typename T, typename U>
struct TypePlusPrecis {
    using type = typename TypeSi<(sizeof(T) > sizeof(U)), T, U>::type;
};

// Version moderne avec using (C++14)
template<bool Condition, typename T, typename U>
using TypeSi_t = typename TypeSi<Condition, T, U>::type;

template<typename T, typename U>
using TypePlusPrecis_t = typename TypePlusPrecis<T, U>::type;

// Utilisation
using TypeMax1 = TypePlusPrecis<int, double>::type;  // double
using TypeMax2 = TypePlusPrecis_t<float, int>;      // float (même taille mais choisi par défaut)

// Avec std::conditional (STL)
#include <type_traits>
using TypeMax3 = std::conditional_t<(sizeof(long) > sizeof(int)), long, int>;
```

### Séquences de Types (Variadic Templates)
```cpp
// Récursivité pour les templates variadiques
template<typename... Types>
struct CompteurTypes;

template<>
struct CompteurTypes<> {
    static constexpr size_t valeur = 0;
};

template<typename T, typename... Rest>
struct CompteurTypes<T, Rest...> {
    static constexpr size_t valeur = 1 + CompteurTypes<Rest...>::valeur;
};

// Affichage des types d'un tuple
template<typename... Types>
void afficher_types() {
    std::cout << "Nombre de types: " << CompteurTypes<Types...>::valeur << std::endl;
}

// Expansion de fold (C++17)
template<typename... Types>
void afficher_tailles() {
    std::cout << "Somme des tailles: " << (0 + ... + sizeof(Types)) << " octets" << std::endl;
}

// Utilisation
afficher_types<int, double, char>();  // "Nombre de types: 3"
afficher_tailles<int, double, char>(); // "Somme des tailles: 13 octets"
```

## Conclusion

Les templates sont un outil essentiel de la programmation C++ moderne, permettant d'écrire du code générique qui fonctionne avec différents types de données. Ils sont largement utilisés dans la STL et sont fondamentaux pour le développement de bibliothèques et d'engines de jeux performants.

La programmation générique avec les templates permet de réduire la duplication de code, d'augmenter la réutilisabilité, et d'assurer la type-safety. Les concepts introduits en C++20 améliorent encore l'expérience en permettant d'exprimer des contraintes explicites sur les types.

Bien que les templates puissent sembler complexes au premier abord, leur maîtrise est essentielle pour exploiter pleinement la puissance du C++ dans le développement d'applications performantes, particulièrement dans le contexte du développement de jeux.

## Ressources Complémentaires

- [C++ Reference: Templates](https://en.cppreference.com/w/cpp/language/templates) - Documentation officielle
- [C++ Reference: Concepts](https://en.cppreference.com/w/cpp/language/constraints) - Documentation officielle
- [Modern C++ Design](https://www.amazon.com/Modern-Design-Generic-Programming-Patterns/dp/0201704315) par Andrei Alexandrescu
- [C++ Templates: The Complete Guide](https://www.amazon.com/C-Templates-Complete-Guide-2nd/dp/0321714121) par David Vandevoorde, Nicolai M. Josuttis et Douglas Gregor
- [C++ Template Metaprogramming](https://www.boost.org/doc/libs/release/libs/mpl/doc/index.html) - Documentation de Boost MPL
