# Module 1: Fondamentaux des Structures de Données

Ce module couvre les fondamentaux des structures de données en C++, incluant les pointeurs, les références, les tableaux et les structures, qui constituent la base nécessaire avant d'aborder la programmation orientée objet.

## 1. Pointeurs et Références Basiques

### Pointeurs : Principe et Syntaxe
```cpp
int valeur = 42;
int* ptr = &valeur;  // Pointeur vers valeur

std::cout << "Valeur: " << valeur << std::endl;   // 42
std::cout << "Adresse: " << &valeur << std::endl; // 0x...
std::cout << "Pointeur: " << ptr << std::endl;    // 0x... (même adresse)
std::cout << "Déréférencement: " << *ptr << std::endl; // 42 (contenu)
```

### Opérations sur les Pointeurs
```cpp
int nombre = 10;
int* ptr = &nombre;

*ptr = 20;          // Modifie la valeur pointée
std::cout << nombre << std::endl;  // 20

ptr++;              // Avance à l'adresse suivante (attention!)
std::cout << ptr << std::endl;     // Adresse + sizeof(int)
```

### Pointeur Null et Sécurité
```cpp
int* ptr = nullptr;  // Pointeur null (à préférer à NULL)

// Vérification de sécurité
if (ptr != nullptr) {
    // Utilisation sûre
    *ptr = 10;
} else {
    std::cout << "Pointeur null, impossible de déréférencer" << std::endl;
}
```

### Références : Principe et Syntaxe
```cpp
int valeur = 42;
int& ref = valeur;  // Référence à valeur (alias)

std::cout << "Valeur: " << valeur << std::endl;   // 42
std::cout << "Référence: " << ref << std::endl;    // 42

ref = 100;          // Modifie la valeur référencée
std::cout << "Valeur après modification: " << valeur << std::endl;  // 100
```

### Différences entre Pointeurs et Références
```cpp
// Une référence doit être initialisée à la déclaration
int& refNonInitialisee;  // Erreur de compilation

// Une référence ne peut pas être réassignée
int a = 5, b = 10;
int& ref = a;       // ref fait référence à a
ref = b;            // Modifie a avec la valeur de b, ne change pas la référence

// Un pointeur peut être null, une référence non
int* ptrNull = nullptr;  // Valide
// int& refNull = nullptr;  // Invalide
```

## 2. Tableaux Dynamiques

### Tableaux Statiques vs Dynamiques
```cpp
// Tableau statique (taille fixe à la compilation)
int tableauStatique[5] = {1, 2, 3, 4, 5};

// Tableau dynamique (taille déterminée à l'exécution)
int taille;
std::cout << "Entrez la taille du tableau: ";
std::cin >> taille;
int* tableauDynamique = new int[taille];

// Remplir le tableau
for (int i = 0; i < taille; i++) {
    tableauDynamique[i] = i * 10;
}

// IMPORTANT: Libérer la mémoire
delete[] tableauDynamique;  // Évite les fuites de mémoire
```

### Allocation et Libération de Mémoire
```cpp
// Allocation pour un seul élément
int* nombre = new int;
*nombre = 42;
delete nombre;  // Libération de la mémoire

// Allocation pour un tableau
double* tableau = new double[100];
// Utilisation du tableau
delete[] tableau;  // Libération de la mémoire du tableau

// ATTENTION: Oublier de libérer cause des "memory leaks"
```

### Gestion des Erreurs d'Allocation
```cpp
try {
    // Tentative d'allocation d'une grande quantité de mémoire
    int* grandTableau = new int[1000000000];

    // Utilisation du tableau...

    delete[] grandTableau;
} catch (const std::bad_alloc& e) {
    std::cerr << "Erreur d'allocation: " << e.what() << std::endl;
}
```

## 3. Structures et Énumérations

### Structures : Regrouper des Données
```cpp
// Définition d'une structure
struct Personne {
    std::string nom;
    int age;
    double taille;
};

// Utilisation
Personne p1;
p1.nom = "Alice";
p1.age = 30;
p1.taille = 1.75;

// Initialisation lors de la déclaration
Personne p2 = {"Bob", 25, 1.80};

// Avec initialisation uniforme (style C++11)
Personne p3 = {"Charlie", 35, 1.70};
Personne p4{"Dave", 40, 1.85};  // Équivalent
```

### Fonctions et Structures
```cpp
// Passage par valeur (copie)
void vieillir(Personne p) {
    p.age++;  // Modifie la copie locale
}

// Passage par référence (modifie l'original)
void vieillirRef(Personne& p) {
    p.age++;
}

// Fonction qui retourne une structure
Personne creerPersonne(const std::string& nom, int age, double taille) {
    Personne p;
    p.nom = nom;
    p.age = age;
    p.taille = taille;
    return p;
}
```

### Énumérations Classiques
```cpp
// Définition d'une énumération classique
enum Couleur {
    ROUGE,    // 0 par défaut
    VERT,     // 1
    BLEU,     // 2
    JAUNE = 10,
    VIOLET,   // 11
    ORANGE    // 12
};

// Utilisation
Couleur c = VERT;
if (c == VERT) {
    std::cout << "La couleur est verte" << std::endl;
}

// Conversion implicite vers int
int valeur = c;  // valeur = 1
```

### Énumérations Fortement Typées (C++11)
```cpp
// Énumération avec type spécifié
enum class JourSemaine : uint8_t {
    LUNDI,
    MARDI,
    MERCREDI,
    JEUDI,
    VENDREDI,
    SAMEDI,
    DIMANCHE
};

// Utilisation
JourSemaine jour = JourSemaine::MERCREDI;

// Pas de conversion implicite vers int
// int numero = jour;  // Erreur
int numero = static_cast<int>(jour);  // OK
```

## 4. Introduction aux Conteneurs (vector, array)

### std::vector : Tableau Dynamique Géré
```cpp
#include <vector>

// Déclaration et initialisation
std::vector<int> nombres;              // Vecteur vide
std::vector<int> serie = {1, 2, 3, 4}; // Avec valeurs initiales
std::vector<std::string> noms(5);      // 5 chaînes vides
std::vector<double> valeurs(3, 1.5);   // 3 éléments initialisés à 1.5

// Ajout d'éléments
nombres.push_back(10);                 // Ajoute à la fin
nombres.push_back(20);
nombres.push_back(30);

// Accès aux éléments
std::cout << nombres[1] << std::endl;  // 20
std::cout << nombres.at(0) << std::endl; // 10 (avec vérification de limites)
std::cout << nombres.front() << std::endl; // 10 (premier élément)
std::cout << nombres.back() << std::endl;  // 30 (dernier élément)

// Taille et capacité
std::cout << "Taille: " << nombres.size() << std::endl;
std::cout << "Capacité: " << nombres.capacity() << std::endl;

// Parcours avec un index
for (size_t i = 0; i < nombres.size(); i++) {
    std::cout << nombres[i] << " ";
}

// Parcours avec un itérateur (style classique)
for (std::vector<int>::iterator it = nombres.begin(); it != nombres.end(); ++it) {
    std::cout << *it << " ";
}

// Parcours avec auto et range-based for loop (C++11)
for (const auto& num : nombres) {
    std::cout << num << " ";
}
```

### std::array : Tableau Statique Sécurisé
```cpp
#include <array>

// Déclaration et initialisation
std::array<int, 5> nombres = {1, 2, 3, 4, 5};

// Accès aux éléments (similaire à vector)
std::cout << nombres[2] << std::endl;      // 3
std::cout << nombres.at(4) << std::endl;   // 5 (avec vérification)

// Taille (fixe à la compilation)
std::cout << "Taille: " << nombres.size() << std::endl;  // 5

// Parcours (comme pour vector)
for (const auto& num : nombres) {
    std::cout << num << " ";
}
```

### Comparaison avec les Tableaux Classiques
```cpp
// Tableau C classique
int tableauC[5] = {1, 2, 3, 4, 5};
// Impossible de connaître sa taille facilement
// Pas de vérification de limites

// std::array
std::array<int, 5> tableauModerne = {1, 2, 3, 4, 5};
// Connaît sa taille: tableauModerne.size()
// Vérification de limites avec .at()

// std::vector
std::vector<int> tableauDynamique = {1, 2, 3, 4, 5};
// Peut changer de taille: tableauDynamique.push_back(6);
// Offre plus de fonctionnalités (insert, erase, etc.)
```

## 5. Manipulation des Chaînes de Caractères

### Les Chaînes en Style C (char[])
```cpp
// Déclaration et initialisation
char nom[20] = "John Doe";

// Taille d'une chaîne
size_t longueur = strlen(nom);  // 8 caractères

// Copie de chaînes
char destination[20];
strcpy(destination, nom);  // Copie "John Doe" dans destination

// Concaténation
strcat(destination, " Jr.");  // destination devient "John Doe Jr."

// Comparaison
if (strcmp(nom, "Jane Doe") == 0) {
    std::cout << "Les chaînes sont identiques" << std::endl;
} else {
    std::cout << "Les chaînes sont différentes" << std::endl;
}

// RISQUES: Dépassement de tampon!
char petit[5];
// strcpy(petit, "Texte trop long");  // DANGER! Écrit au-delà des limites
```

### Les Chaînes en Style C++ (std::string)
```cpp
#include <string>

// Déclaration et initialisation
std::string nom = "John Doe";

// Taille d'une chaîne
size_t longueur = nom.length();  // ou nom.size()

// Concaténation
nom += " Jr.";  // nom devient "John Doe Jr."
std::string nomComplet = nom + " III";  // Concaténation avec +

// Comparaison
if (nom == "Jane Doe") {
    std::cout << "Les chaînes sont identiques" << std::endl;
} else {
    std::cout << "Les chaînes sont différentes" << std::endl;
}

// Sous-chaînes
std::string prenom = nom.substr(0, 4);  // "John"
std::string partie = nom.substr(5);     // "Doe Jr."

// Recherche
size_t position = nom.find("Doe");
if (position != std::string::npos) {
    std::cout << "Trouvé à la position " << position << std::endl;
}

// Remplacement
nom.replace(5, 3, "Smith");  // Remplace "Doe" par "Smith"

// Conversion vers C-string si nécessaire
const char* cstr = nom.c_str();
```

### std::string_view (C++17, aperçu)
```cpp
#include <string_view>

void afficher(std::string_view sv) {
    std::cout << sv << std::endl;
}

std::string str = "Bonjour le monde";
afficher(str);                // Vue sur une string
afficher("Texte littéral");   // Pas de copie
afficher(str.substr(0, 7));   // Vue sur une sous-chaîne sans copie
```

## 6. Passage de Paramètres

### Passage par Valeur
```cpp
void incrementer(int x) {
    x++;  // Modifie la copie locale
    std::cout << "Dans la fonction: " << x << std::endl;
}

int nombre = 5;
incrementer(nombre);  // nombre reste 5
std::cout << "Après appel: " << nombre << std::endl;  // Affiche 5
```

### Passage par Pointeur
```cpp
void incrementer(int* x) {
    if (x) {  // Vérification de nullité
        (*x)++;  // Modifie la valeur pointée
    }
}

int nombre = 5;
incrementer(&nombre);  // nombre devient 6
std::cout << "Après appel: " << nombre << std::endl;

// Passage de tableau
void sommeTableau(int* tab, int taille, int* resultat) {
    *resultat = 0;
    for (int i = 0; i < taille; i++) {
        *resultat += tab[i];
    }
}
```

### Passage par Référence
```cpp
void incrementer(int& x) {
    x++;  // Modifie directement la variable originale
}

int nombre = 5;
incrementer(nombre);  // nombre devient 6
std::cout << "Après appel: " << nombre << std::endl;

// Passage de grands objets sans copie
void traiterPersonne(const Personne& p) {
    std::cout << "Traitement de " << p.nom << std::endl;
    // p.age++;  // Erreur: p est const
}
```

### Passage avec Modificateurs const
```cpp
// Pointeur vers constante (la valeur pointée ne peut être modifiée)
void afficher(const int* ptr) {
    std::cout << *ptr << std::endl;
    // *ptr = 10;  // Erreur: valeur pointée constante
}

// Référence constante (objet référencé ne peut être modifié)
void afficher(const std::string& texte) {
    std::cout << texte << std::endl;
    // texte += "!";  // Erreur: objet référencé constant
}
```

## 7. Portée et Durée de Vie des Variables

### Portée des Variables
```cpp
int global = 100;  // Variable globale (portée de fichier)

void fonction() {
    int local = 10;  // Variable locale à la fonction
    std::cout << local << ", " << global << std::endl;

    {  // Bloc interne
        int blocLocal = 20;  // Variable locale au bloc
        std::cout << local << ", " << blocLocal << ", " << global << std::endl;
    }

    // std::cout << blocLocal << std::endl;  // Erreur: hors de portée
}

// std::cout << local << std::endl;  // Erreur: hors de portée
```

### Durée de Vie
```cpp
void fonction() {
    int automatique = 10;   // Durée de vie automatique (détruite à la fin du bloc)
    static int statique = 20;  // Durée de vie statique (persiste entre les appels)

    automatique++;
    statique++;

    std::cout << "Auto: " << automatique << ", Static: " << statique << std::endl;
}

int main() {
    fonction();  // Affiche "Auto: 11, Static: 21"
    fonction();  // Affiche "Auto: 11, Static: 22"
    fonction();  // Affiche "Auto: 11, Static: 23"

    // Variables dynamiques
    int* dynamique = new int(30);  // Allocation dynamique
    std::cout << *dynamique << std::endl;
    delete dynamique;  // Libération manuelle, fin de la durée de vie

    return 0;
}
```

### Masquage de Variables
```cpp
int x = 10;  // Variable globale

void fonction() {
    int x = 20;  // Masque la variable globale
    std::cout << "Local x: " << x << std::endl;        // 20
    std::cout << "Global x: " << ::x << std::endl;     // 10 (opérateur ::)

    {
        int x = 30;  // Masque la variable de fonction
        std::cout << "Block x: " << x << std::endl;    // 30
        std::cout << "Outer x: " << fonction::x << std::endl;  // Erreur
    }
}
```

### Instruction static
```cpp
void compteur() {
    static int compte = 0;  // Initialisé une seule fois
    compte++;
    std::cout << "Appelé " << compte << " fois" << std::endl;
}

// Avec une classe (avancé)
class Compteur {
private:
    static int total;  // Déclaration
    int id;
public:
    Compteur() : id(++total) {
        std::cout << "Nouveau compteur: " << id << std::endl;
    }
    static int getTotal() { return total; }
};

int Compteur::total = 0;  // Définition (nécessaire pour les membres statiques)
```

## Conclusion

Ce module vous a présenté les fondamentaux des structures de données en C++. Vous avez appris à utiliser les pointeurs et références, à gérer la mémoire avec des tableaux dynamiques, à organiser vos données avec des structures et des énumérations, et à utiliser des conteneurs comme `std::vector` et `std::array`. Ces concepts sont essentiels pour la programmation en C++ et forment une base solide pour la programmation orientée objet que nous aborderons dans le prochain module.

## Ressources Complémentaires

- [C++ Reference](https://en.cppreference.com/w/) - Documentation complète
- [LearnCpp.com](https://www.learncpp.com/) - Tutoriels sur les pointeurs et références
- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines) - Bonnes pratiques C++
- [Effective Modern C++](https://www.oreilly.com/library/view/effective-modern-c/9781491908419/) par Scott Meyers
