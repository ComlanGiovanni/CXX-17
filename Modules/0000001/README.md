# Module 0: Fondamentaux C++ Revisités

Ce module couvre les bases fondamentales de C++ avec un focus particulier sur les améliorations apportées dans C++17 par rapport à C++98.

## 1. Types de données et variables améliorés

### Types de base
```cpp
// Types numériques
int a = 42;                  // 4 bytes (généralement)
long long b = 1234567890LL;  // 8 bytes
float c = 3.14f;             // 4 bytes
double d = 3.141592;         // 8 bytes

// C++17: littéraux numériques avec séparateurs pour plus de lisibilité
int million = 1'000'000;     // Plus lisible que 1000000
```

### auto
```cpp
// C++98: typage explicite obligatoire
std::vector<std::string>::iterator it = v.begin();

// C++11/17: inférence de type avec auto
auto it = v.begin();  // Beaucoup plus lisible
```

### Initialisation uniforme
```cpp
// C++98
int arr[] = {1, 2, 3};
std::vector<int> vec;
vec.push_back(1);
vec.push_back(2);

// C++11/17
std::vector<int> vec = {1, 2, 3};  // Liste d'initialisation
std::map<std::string, int> scores = {{"Alice", 100}, {"Bob", 90}};
```

### Type Deduction avec decltype
```cpp
auto x = 42;
decltype(x) y = 23;  // y est de type int
```

### Structured Binding (C++17)
```cpp
// Accès aux éléments d'une paire
std::pair<std::string, int> person = {"Alice", 30};
auto [name, age] = person;
std::cout << name << " is " << age << " years old\n";

// Avec map
std::map<std::string, int> scores = {{"Alice", 100}, {"Bob", 90}};
for (const auto& [name, score] : scores) {
    std::cout << name << ": " << score << "\n";
}
```

## 2. Références et Pointeurs Modernes

### Références vs Pointeurs
```cpp
void incrementByRef(int& num) {
    num++;  // Modifie directement la variable originale
}

void incrementByPtr(int* num) {
    (*num)++;  // Déréférencement nécessaire
}

int x = 10;
incrementByRef(x);   // x vaut maintenant 11
incrementByPtr(&x);  // x vaut maintenant 12
```

### nullptr (C++11)
```cpp
// C++98
int* oldPtr = NULL;  // ou int* oldPtr = 0;

// C++11/17
int* modernPtr = nullptr;  // Type sûr, évite les conversions ambiguës
```

### Références rvalue et lvalue
```cpp
// lvalue reference - référence à une valeur stockée
int x = 10;
int& rx = x;  // rx est une référence à x

// rvalue reference - référence à une valeur temporaire (C++11)
int&& rr = 42;  // rr est une référence à une valeur temporaire (42)
```

## 3. Expressions et Opérateurs

### Opérateurs Classiques
```cpp
// Arithmétiques: +, -, *, /, %
int sum = 5 + 3;       // 8
int quotient = 10 / 3; // 3 (division entière)
int remainder = 10 % 3; // 1 (reste)

// Comparaison: ==, !=, >, <, >=, <=
bool isEqual = (5 == 5);  // true

// Logiques: &&, ||, !
bool condition = (true && false);  // false (ET logique)
```

### Nouveautés C++17
```cpp
// Expressions constantes if
if constexpr (std::is_integral<T>::value) {
    // Ce code n'est compilé que si T est un type entier
} else {
    // Ce code n'est compilé que si T n'est pas un type entier
}

// Opérateur de repli (fold expressions) pour les templates variadiques
template<typename... Args>
auto sum(Args... args) {
    return (... + args);  // (a + b + c + ...)
}
```

## 4. Structures de Contrôle

### Structures Classiques
```cpp
// if-else
if (condition) {
    // code
} else if (otherCondition) {
    // code
} else {
    // code
}

// switch
switch (value) {
    case 1:
        // code pour value == 1
        break;
    case 2:
        // code pour value == 2
        break;
    default:
        // code par défaut
}

// boucles
for (int i = 0; i < 10; i++) { /* code */ }
while (condition) { /* code */ }
do { /* code */ } while (condition);
```

### Boucle For Moderne (C++11/17)
```cpp
std::vector<int> numbers = {1, 2, 3, 4, 5};

// C++98
for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
    std::cout << *it << " ";
}

// C++11/17
for (const auto& num : numbers) {
    std::cout << num << " ";
}
```

### if avec initialisation (C++17)
```cpp
// C++98
std::map<std::string, int> scores = {{"Alice", 95}, {"Bob", 87}};
auto it = scores.find("Alice");
if (it != scores.end()) {
    use_score(it->second);
}

// C++17
if (auto it = scores.find("Alice"); it != scores.end()) {
    use_score(it->second);
}
```

### switch avec initialisation (C++17)
```cpp
switch (auto value = getValue(); value) {
    case 1: /* code */ break;
    case 2: /* code */ break;
    default: /* code */
}
```

## 5. Fonctions et Surcharge

### Surcharge de Fonctions
```cpp
void print(int value) {
    std::cout << "Integer: " << value << std::endl;
}

void print(double value) {
    std::cout << "Double: " << value << std::endl;
}

void print(const std::string& value) {
    std::cout << "String: " << value << std::endl;
}
```

### Paramètres par Défaut
```cpp
void greet(const std::string& name = "Guest") {
    std::cout << "Hello, " << name << "!" << std::endl;
}

greet();           // "Hello, Guest!"
greet("Alice");    // "Hello, Alice!"
```

### Fonctions Inline
```cpp
inline int square(int x) {
    return x * x;
}
```

### Fonctions Lambda (C++11/17)
```cpp
// Lambda simple
auto add = [](int a, int b) { return a + b; };
std::cout << add(2, 3) << std::endl;  // 5

// Capture de variables
int multiplier = 3;
auto times = [multiplier](int x) { return x * multiplier; };
std::cout << times(4) << std::endl;  // 12

// C++14/17: lambdas génériques
auto genericFunc = [](auto x, auto y) { return x + y; };
std::cout << genericFunc(2, 3) << std::endl;      // 5
std::cout << genericFunc(2.5, 3.5) << std::endl;  // 6.0
```

## 6. Espaces de Noms (Namespaces)

### Définition et Utilisation
```cpp
// Définition d'un namespace
namespace Math {
    const double PI = 3.14159265358979323846;

    double square(double x) {
        return x * x;
    }

    double cube(double x) {
        return x * x * x;
    }
}

// Utilisation
double area = Math::PI * Math::square(radius);
```

### Namespace Imbriqués
```cpp
namespace Game {
    namespace Graphics {
        class Renderer { /*...*/ };
    }

    namespace Audio {
        class SoundEngine { /*...*/ };
    }
}

// C++17: déclaration simplifiée des namespace imbriqués
namespace Game::Graphics::Utils {
    class TextureLoader { /*...*/ };
}
```

### Using Declaration et Directive
```cpp
// Using declaration (importe un seul élément)
using Math::PI;
double circumference = PI * 2 * radius;

// Using directive (importe tout le namespace)
using namespace Math;
double volume = cube(side);
```

## 7. Gestion des Erreurs Moderne

### Exceptions
```cpp
try {
    int* arr = new int[1000000000000];  // Peut provoquer std::bad_alloc
    // ...
} catch (const std::bad_alloc& e) {
    std::cerr << "Allocation failed: " << e.what() << std::endl;
} catch (const std::exception& e) {
    std::cerr << "Standard exception: " << e.what() << std::endl;
} catch (...) {
    std::cerr << "Unknown exception occurred" << std::endl;
}
```

### std::optional (C++17)
```cpp
#include <optional>

std::optional<std::string> getUserName(int id) {
    if (id == 1) {
        return "Alice";
    } else if (id == 2) {
        return "Bob";
    }
    return std::nullopt;  // Aucune valeur
}

auto name = getUserName(3);
if (name) {
    std::cout << "User name: " << *name << std::endl;
} else {
    std::cout << "User not found" << std::endl;
}
```

### std::variant (C++17)
```cpp
#include <variant>
#include <string>

std::variant<int, std::string, double> value;

value = 42;
std::cout << std::get<int>(value) << std::endl;

value = "hello";
std::cout << std::get<std::string>(value) << std::endl;

value = 3.14;
std::cout << std::get<double>(value) << std::endl;

// Visite par type
std::visit([](const auto& val) { std::cout << val << std::endl; }, value);
```

### Assertions
```cpp
#include <cassert>

void process(int* ptr, int size) {
    assert(ptr != nullptr && "Pointer cannot be null");
    assert(size > 0 && "Size must be positive");
    // ...
}
```

## Conclusion

Ce module vous a présenté les fondamentaux de C++ revisités avec les améliorations de C++17. Ces concepts forment la base solide nécessaire pour aborder les modules suivants qui exploreront la programmation orientée objet et d'autres fonctionnalités avancées de C++17.

## Ressources Complémentaires

- [cppreference.com](https://en.cppreference.com/) - Documentation complète et à jour
- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines) - Bonnes pratiques modernes
- [C++17 - The Complete Guide](https://www.cppstd17.com/) par Nicolai M. Josuttis
