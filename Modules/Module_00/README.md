# Module 0: Bases Fondamentales du C++

Ce module introductif couvre les concepts fondamentaux de la programmation en C++ nécessaires pour établir une base solide avant d'aborder les caractéristiques avancées et spécifiques de C++17.

## 1. Introduction à la Programmation C++

### Historique et Évolution
```cpp
// Le C++ a été créé par Bjarne Stroustrup dans les années 1980
// comme une extension orientée objet du langage C
// C++98, C++03, C++11, C++14, C++17...
```

### Processus de Compilation
```cpp
// Source (.cpp) → Préprocesseur → Compilation → Édition de liens → Exécutable
// g++ -std=c++17 -Wall -Wextra -Werror main.cpp -o program
```

### Premier Programme
```cpp
// hello.cpp
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```

## 2. Types de Données et Variables

### Types Primitifs
```cpp
int entier = 42;                 // Entier signé
unsigned int nonSigne = 42u;     // Entier non signé
float decimal = 3.14f;           // Nombre à virgule flottante simple précision
double precision = 3.141592;     // Nombre à virgule flottante double précision
char caractere = 'A';            // Caractère unique
bool booleen = true;             // Valeur booléenne (true/false)
```

### Modificateurs
```cpp
short int petitEntier = 42;      // Entier court (généralement 2 octets)
long int grandEntier = 42L;      // Entier long (généralement 4 octets)
long long treGrandEntier = 42LL; // Entier très long (généralement 8 octets)
const int CONSTANTE = 100;       // Valeur qui ne peut pas être modifiée
```

### Déclaration et Initialisation
```cpp
// Différentes façons d'initialiser des variables
int a = 10;              // Initialisation par copie
int b(20);               // Initialisation directe
int c{30};               // Initialisation uniforme (préférée en C++ moderne)

// Variables non initialisées (à éviter)
int nonInitialise;       // Valeur indéterminée!
```

## 3. Opérateurs

### Opérateurs Arithmétiques
```cpp
int a = 10, b = 3;
int somme = a + b;       // 13
int difference = a - b;  // 7
int produit = a * b;     // 30
int quotient = a / b;    // 3 (division entière)
int reste = a % b;       // 1 (modulo)

// Incrémentation et décrémentation
int x = 5;
x++;                     // x devient 6 (post-incrémentation)
++x;                     // x devient 7 (pré-incrémentation)
x--;                     // x devient 6 (post-décrémentation)
--x;                     // x devient 5 (pré-décrémentation)
```

### Opérateurs de Comparaison
```cpp
bool estEgal = (a == b);        // false
bool estDifferent = (a != b);   // true
bool estPlusGrand = (a > b);    // true
bool estPlusPetit = (a < b);    // false
bool estSupEgal = (a >= b);     // true
bool estInfEgal = (a <= b);     // false
```

### Opérateurs Logiques
```cpp
bool condition1 = true;
bool condition2 = false;

bool etLogique = condition1 && condition2;  // false (ET logique)
bool ouLogique = condition1 || condition2;  // true (OU logique)
bool negation = !condition1;                // false (NON logique)
```

### Opérateurs d'Affectation
```cpp
int x = 10;
x += 5;      // x = x + 5 (x devient 15)
x -= 3;      // x = x - 3 (x devient 12)
x *= 2;      // x = x * 2 (x devient 24)
x /= 4;      // x = x / 4 (x devient 6)
x %= 4;      // x = x % 4 (x devient 2)
```

## 4. Structures de Contrôle

### Conditionnelles
```cpp
int age = 18;

// if simple
if (age >= 18) {
    std::cout << "Majeur" << std::endl;
}

// if-else
if (age >= 18) {
    std::cout << "Majeur" << std::endl;
} else {
    std::cout << "Mineur" << std::endl;
}

// if-else if-else
if (age < 13) {
    std::cout << "Enfant" << std::endl;
} else if (age < 18) {
    std::cout << "Adolescent" << std::endl;
} else if (age < 65) {
    std::cout << "Adulte" << std::endl;
} else {
    std::cout << "Senior" << std::endl;
}

// Opérateur ternaire
std::string statut = (age >= 18) ? "Majeur" : "Mineur";
```

### Switch
```cpp
int jour = 2;
switch (jour) {
    case 1:
        std::cout << "Lundi" << std::endl;
        break;
    case 2:
        std::cout << "Mardi" << std::endl;
        break;
    // ...
    case 7:
        std::cout << "Dimanche" << std::endl;
        break;
    default:
        std::cout << "Jour invalide" << std::endl;
}
```

### Boucles
```cpp
// Boucle for
for (int i = 0; i < 5; i++) {
    std::cout << i << " ";  // Affiche: 0 1 2 3 4
}

// Boucle while
int j = 0;
while (j < 5) {
    std::cout << j << " ";  // Affiche: 0 1 2 3 4
    j++;
}

// Boucle do-while (exécutée au moins une fois)
int k = 0;
do {
    std::cout << k << " ";  // Affiche: 0 1 2 3 4
    k++;
} while (k < 5);

// Instructions de contrôle de boucle
for (int i = 0; i < 10; i++) {
    if (i == 3) continue;  // Saute à l'itération suivante
    if (i == 7) break;     // Sort de la boucle
    std::cout << i << " ";  // Affiche: 0 1 2 4 5 6
}
```

## 5. Fonctions et Procédures

### Déclaration et Définition
```cpp
// Déclaration de fonction (prototype)
int additionner(int a, int b);

// Définition de fonction
int additionner(int a, int b) {
    return a + b;
}

// Fonction sans valeur de retour (procédure)
void afficherMessage(const std::string& message) {
    std::cout << message << std::endl;
}

// Utilisation
int somme = additionner(5, 3);  // somme = 8
afficherMessage("Bonjour!");    // Affiche: Bonjour!
```

### Paramètres par Défaut
```cpp
void saluer(const std::string& nom = "Monde") {
    std::cout << "Bonjour, " << nom << "!" << std::endl;
}

saluer();            // Affiche: Bonjour, Monde!
saluer("Alice");     // Affiche: Bonjour, Alice!
```

### Surcharge de Fonctions
```cpp
// Même nom, différents paramètres
int multiplier(int a, int b) {
    return a * b;
}

double multiplier(double a, double b) {
    return a * b;
}

int resultat1 = multiplier(5, 3);        // Appelle la première version
double resultat2 = multiplier(2.5, 1.5);  // Appelle la deuxième version
```

## 6. Arguments et Valeurs de Retour

### Passage par Valeur
```cpp
void incrementer(int n) {
    n++;  // Modifie la copie locale
}

int x = 5;
incrementer(x);  // x reste 5
```

### Passage par Référence
```cpp
void incrementer(int& n) {
    n++;  // Modifie directement la variable passée
}

int x = 5;
incrementer(x);  // x devient 6
```

### Retour de Valeurs
```cpp
// Retour simple
int carre(int n) {
    return n * n;
}

// Retour par référence (avancé)
int& obtenirElement(std::vector<int>& v, size_t index) {
    return v[index];  // Retourne une référence à l'élément
}
```

## 7. Tableaux et Chaînes de Caractères

### Tableaux Statiques
```cpp
// Déclaration et initialisation
int nombres[5] = {10, 20, 30, 40, 50};

// Accès aux éléments
int deuxieme = nombres[1];  // 20 (les indices commencent à 0)

// Modification d'un élément
nombres[2] = 35;  // Le tableau devient {10, 20, 35, 40, 50}

// Tableaux multidimensionnels
int matrice[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```

### Chaînes de Caractères Style C
```cpp
// Chaîne terminée par le caractère nul '\0'
char nom[10] = "Alice";

// Fonctions de manipulation (de la bibliothèque <cstring>)
#include <cstring>
char destination[20];
strcpy(destination, nom);        // Copie
strcat(destination, " Bob");     // Concaténation
size_t longueur = strlen(nom);   // Calcul de la longueur
```

### Chaînes de Caractères C++ (std::string)
```cpp
#include <string>

std::string prenom = "Alice";
std::string nom = "Smith";

// Concaténation
std::string nomComplet = prenom + " " + nom;  // "Alice Smith"

// Méthodes utiles
size_t taille = prenom.length();  // 5
prenom.append(" Junior");         // "Alice Junior"
bool contient = nom.find("mi") != std::string::npos;  // true
```

## 8. Entrées/Sorties Console

### Sorties Console
```cpp
#include <iostream>

// Affichage simple
std::cout << "Bonjour" << std::endl;

// Affichage de variables
int age = 25;
std::cout << "J'ai " << age << " ans." << std::endl;

// Formatage (basique)
std::cout << "Prix: " << 19.99 << " euros" << std::endl;
```

### Entrées Console
```cpp
#include <iostream>
#include <string>

// Lecture d'un entier
int nombre;
std::cout << "Entrez un nombre: ";
std::cin >> nombre;

// Lecture d'une chaîne
std::string nom;
std::cout << "Entrez votre nom: ";
std::cin >> nom;  // Attention: s'arrête au premier espace

// Lecture d'une ligne complète
std::string ligne;
std::cin.ignore();  // Pour éviter les problèmes après un std::cin
std::cout << "Entrez une phrase: ";
std::getline(std::cin, ligne);
```

### Manipulation des Flux
```cpp
#include <iostream>
#include <iomanip>

// Précision des nombres à virgule
double pi = 3.14159265358979;
std::cout << std::fixed << std::setprecision(2) << pi << std::endl;  // 3.14

// Largeur de champ et alignement
std::cout << std::setw(10) << std::right << 42 << std::endl;  // "        42"

// Bases numériques
int n = 42;
std::cout << std::dec << n << std::endl;  // 42 (décimal)
std::cout << std::hex << n << std::endl;  // 2a (hexadécimal)
std::cout << std::oct << n << std::endl;  // 52 (octal)
```

## Conclusion

Ce module vous a présenté les concepts fondamentaux de la programmation en C++. La maîtrise de ces bases est essentielle avant d'explorer les fonctionnalités plus avancées et les spécificités de C++17 que nous aborderons dans les modules suivants.

## Ressources Complémentaires

- [C++ Reference](https://en.cppreference.com/) - Documentation officielle
- [Learn C++](https://www.learncpp.com/) - Tutoriels détaillés pour débutants
- [C++ Primer](http://www.informit.com/store/c-plus-plus-primer-9780321714114) par Stanley Lippman, Josée Lajoie, et Barbara E. Moo
- [Programming: Principles and Practice Using C++](http://www.stroustrup.com/programming.html) par Bjarne Stroustrup
