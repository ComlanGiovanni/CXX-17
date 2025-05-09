/*
 * Solutions pour Module 0: Bases Fondamentales du C++
 * Ces solutions implémentent tous les exercices du module
 */

/******************************************
 * Exercice 1: Premier Pas en C++
 ******************************************/

// Exercice 1.1: Hello, World!
/*
 * Fichier: hello.cpp
 */
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

// Exercice 6.3: Manipulation de Chaînes
/*
 * Fichier: chaines.cpp
 */
#include <iostream>
#include <cstring>  // Pour les fonctions de chaînes de style C
#include <string>   // Pour les chaînes de style C++

int main() {
    // 1. Chaînes de style C (char[])
    std::cout << "Chaînes de style C (char[]):" << std::endl;

    // Déclaration et initialisation
    char chaine1[20] = "Hello";
    char chaine2[20] = "World";
    char resultat[40];

    std::cout << "chaine1: " << chaine1 << std::endl;
    std::cout << "chaine2: " << chaine2 << std::endl;

    // Longueur de la chaîne
    std::cout << "Longueur de chaine1: " << strlen(chaine1) << std::endl;

    // Copie de chaîne
    strcpy(resultat, chaine1);
    std::cout << "Après strcpy(resultat, chaine1): " << resultat << std::endl;

    // Concaténation
    strcat(resultat, " ");
    strcat(resultat, chaine2);
    std::cout << "Après strcat: " << resultat << std::endl;

    // Comparaison
    int comp = strcmp(chaine1, chaine2);
    std::cout << "Comparaison de chaine1 et chaine2: " << comp << std::endl;

    // Recherche
    char* position = strstr(resultat, "World");
    if (position != nullptr) {
        std::cout << "Le mot 'World' commence à la position: "
                  << (position - resultat) << std::endl;
    }

    // 2. Chaînes de style C++ (std::string)
    std::cout << "\nChaînes de style C++ (std::string):" << std::endl;

    // Déclaration et initialisation
    std::string str1 = "Hello";
    std::string str2 = "World";

    std::cout << "str1: " << str1 << std::endl;
    std::cout << "str2: " << str2 << std::endl;

    // Longueur de la chaîne
    std::cout << "Longueur de str1: " << str1.length() << std::endl;

    // Concaténation
    std::string strResultat = str1 + " " + str2;
    std::cout << "Concaténation: " << strResultat << std::endl;

    // Comparaison
    if (str1 == str2) {
        std::cout << "str1 est égal à str2" << std::endl;
    } else {
        std::cout << "str1 est différent de str2" << std::endl;
    }

    // Sous-chaîne
    std::string subStr = strResultat.substr(6, 5);  // Commence à l'index 6, longueur 5
    std::cout << "Sous-chaîne: " << subStr << std::endl;

    // Recherche
    size_t pos = strResultat.find("World");
    if (pos != std::string::npos) {
        std::cout << "Position de 'World': " << pos << std::endl;
    }

    // Remplacement
    std::string str3 = strResultat;
    str3.replace(str3.find("World"), 5, "C++");
    std::cout << "Après remplacement: " << str3 << std::endl;

    // Insertion
    str3.insert(5, " beautiful");
    std::cout << "Après insertion: " << str3 << std::endl;

    // Conversion entre std::string et char*
    const char* cStr = str3.c_str();
    std::cout << "std::string converti en char*: " << cStr << std::endl;

    return 0;
}

/******************************************
 * Exercice 7: Entrées/Sorties
 ******************************************/

// Exercice 7.1: Lecture/Écriture Console
/*
 * Fichier: entrees_sorties.cpp
 */
#include <iostream>
#include <limits>  // Pour std::numeric_limits

int main() {
    std::string nom;
    int age;
    double hauteur;

    // Demande les informations à l'utilisateur
    std::cout << "Entrez votre nom: ";
    std::getline(std::cin, nom);

    // Validation de l'âge
    bool ageValide = false;
    while (!ageValide) {
        std::cout << "Entrez votre âge: ";
        if (std::cin >> age) {
            if (age >= 0 && age <= 150) {
                ageValide = true;
            } else {
                std::cout << "L'âge doit être compris entre 0 et 150. Veuillez réessayer." << std::endl;
            }
        } else {
            std::cout << "Entrée invalide. Veuillez entrer un nombre entier." << std::endl;
            std::cin.clear();  // Réinitialise l'état du flux
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Vide le tampon
        }
    }

    // Vide le tampon après la lecture de l'âge
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Validation de la hauteur
    bool hauteurValide = false;
    while (!hauteurValide) {
        std::cout << "Entrez votre hauteur en mètres (ex: 1.75): ";
        if (std::cin >> hauteur) {
            if (hauteur > 0 && hauteur < 3) {
                hauteurValide = true;
            } else {
                std::cout << "La hauteur doit être comprise entre 0 et 3 mètres. Veuillez réessayer." << std::endl;
            }
        } else {
            std::cout << "Entrée invalide. Veuillez entrer un nombre réel." << std::endl;
            std::cin.clear();  // Réinitialise l'état du flux
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Vide le tampon
        }
    }

    // Affiche un résumé formaté des informations
    std::cout << "\nRésumé des informations:" << std::endl;
    std::cout << "Nom: " << nom << std::endl;
    std::cout << "Âge: " << age << " ans" << std::endl;
    std::cout << "Hauteur: " << hauteur << " mètres" << std::endl;

    // Classification selon l'âge
    std::cout << "\nClassification selon l'âge:" << std::endl;
    if (age < 18) {
        std::cout << "Vous êtes mineur(e)." << std::endl;
    } else if (age < 65) {
        std::cout << "Vous êtes adulte." << std::endl;
    } else {
        std::cout << "Vous êtes senior." << std::endl;
    }

    // Classification selon la hauteur
    std::cout << "\nClassification selon la hauteur:" << std::endl;
    if (hauteur < 1.50) {
        std::cout << "Vous êtes de petite taille." << std::endl;
    } else if (hauteur < 1.80) {
        std::cout << "Vous êtes de taille moyenne." << std::endl;
    } else {
        std::cout << "Vous êtes de grande taille." << std::endl;
    }

    return 0;
}

// Exercice 7.2: Formatage des Sorties
/*
 * Fichier: formatage.cpp
 */
#include <iostream>
#include <iomanip>  // Pour les manipulateurs de flux

int main() {
    int nombre = 42;
    double pi = 3.14159265359;

    // Affichage de nombres dans différentes bases
    std::cout << "Affichage de nombres dans différentes bases:" << std::endl;
    std::cout << "Décimal: " << nombre << ", ";
    std::cout << "Hexadécimal: 0x" << std::hex << nombre << ", ";
    std::cout << "Octal: 0" << std::oct << nombre << std::dec << std::endl;  // std::dec réinitialise en base 10

    // Affichage avec différentes précisions
    std::cout << "\nAffichage avec différentes précisions:" << std::endl;
    std::cout << "Pi (valeur par défaut): " << pi << std::endl;
    std::cout << "Pi (2 décimales): " << std::fixed << std::setprecision(2) << pi << std::endl;
    std::cout << "Pi (5 décimales): " << std::fixed << std::setprecision(5) << pi << std::endl;
    std::cout << "Pi (10 décimales): " << std::fixed << std::setprecision(10) << pi << std::endl;

    // Réinitialisation du formatage
    std::cout.unsetf(std::ios::fixed);
    std::cout << std::setprecision(6);  // Valeur par défaut

    // Affichage avec champs de largeur fixe
    std::cout << "\nTableau formaté avec des champs de largeur fixe:" << std::endl;
    std::cout << "+------------+-------+----------+" << std::endl;
    std::cout << "|" << std::setw(12) << "Nom" << "|"
              << std::setw(7) << "Age" << "|"
              << std::setw(10) << "Taille" << "|" << std::endl;
    std::cout << "+------------+-------+----------+" << std::endl;

    // Alignement à gauche
    std::cout << "|" << std::left << std::setw(12) << "Alice" << "|"
              << std::right << std::setw(7) << 25 << "|"
              << std::fixed << std::setprecision(2) << std::setw(10) << 1.65 << "|" << std::endl;

    std::cout << "|" << std::left << std::setw(12) << "Bob" << "|"
              << std::right << std::setw(7) << 30 << "|"
              << std::fixed << std::setprecision(2) << std::setw(10) << 1.80 << "|" << std::endl;

    std::cout << "|" << std::left << std::setw(12) << "Charlie" << "|"
              << std::right << std::setw(7) << 22 << "|"
              << std::fixed << std::setprecision(2) << std::setw(10) << 1.75 << "|" << std::endl;

    std::cout << "+------------+-------+----------+" << std::endl;

    // Formatage de nombres avec séparateurs
    double grandNombre = 1234567.89;
    std::cout << "\nFormatage de grands nombres:" << std::endl;
    std::cout << "Nombre sans formatage: " << grandNombre << std::endl;
    std::cout << "Nombre avec formatage: " << std::fixed << std::setprecision(2);

    // Note: Les séparateurs de milliers ne sont pas directement supportés dans tous les compilateurs
    // Implémentation manuelle:
    std::string nombreStr = std::to_string(static_cast<long long>(grandNombre));
    std::string partieEntiere;
    for (size_t i = 0; i < nombreStr.length(); i++) {
        partieEntiere += nombreStr[i];
        if ((nombreStr.length() - i - 1) % 3 == 0 && i != nombreStr.length() - 1) {
            partieEntiere += " ";  // Espace comme séparateur de milliers
        }
    }
    std::cout << partieEntiere << ".89" << std::endl;

    return 0;
}

// Exercice 7.3: Lecture/Écriture Fichiers (optionnel)
/*
 * Fichier: fichiers.cpp
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Structure pour stocker les données
struct Personne {
    std::string nom;
    int age;
    double hauteur;
};

int main() {
    // 1. Écriture dans un fichier
    std::ofstream fichierSortie("personnes.txt");

    if (!fichierSortie) {
        std::cerr << "Erreur: Impossible d'ouvrir le fichier en écriture." << std::endl;
        return 1;
    }

    // Écriture de l'en-tête
    fichierSortie << "Nom,Age,Hauteur" << std::endl;

    // Écriture des données
    fichierSortie << "Alice,25,1.65" << std::endl;
    fichierSortie << "Bob,30,1.80" << std::endl;
    fichierSortie << "Charlie,22,1.75" << std::endl;

    fichierSortie.close();
    std::cout << "Données écrites dans le fichier 'personnes.txt'" << std::endl;

    // 2. Lecture depuis un fichier
    std::ifstream fichierEntree("personnes.txt");

    if (!fichierEntree) {
        std::cerr << "Erreur: Impossible d'ouvrir le fichier en lecture." << std::endl;
        return 1;
    }

    // Ignorer la première ligne (en-tête)
    std::string ligne;
    std::getline(fichierEntree, ligne);

    // Lecture des données
    std::vector<Personne> personnes;

    while (std::getline(fichierEntree, ligne)) {
        Personne p;

        // Recherche de la première virgule
        size_t pos1 = ligne.find(',');
        if (pos1 != std::string::npos) {
            p.nom = ligne.substr(0, pos1);

            // Recherche de la deuxième virgule
            size_t pos2 = ligne.find(',', pos1 + 1);
            if (pos2 != std::string::npos) {
                // Extraction de l'âge
                std::string ageStr = ligne.substr(pos1 + 1, pos2 - pos1 - 1);
                p.age = std::stoi(ageStr);

                // Extraction de la hauteur
                std::string hauteurStr = ligne.substr(pos2 + 1);
                p.hauteur = std::stod(hauteurStr);

                // Ajout à la liste
                personnes.push_back(p);
            }
        }
    }

    fichierEntree.close();

    // Affichage des données lues
    std::cout << "\nDonnées lues depuis le fichier:" << std::endl;
    std::cout << "+----------+-----+--------+" << std::endl;
    std::cout << "| Nom      | Age | Hauteur |" << std::endl;
    std::cout << "+----------+-----+--------+" << std::endl;

    double sommeAges = 0, sommeHauteurs = 0;

    for (const auto& p : personnes) {
        std::cout << "| " << std::left << std::setw(8) << p.nom << " | "
                  << std::right << std::setw(3) << p.age << " | "
                  << std::fixed << std::setprecision(2) << std::setw(6) << p.hauteur << " |" << std::endl;

        sommeAges += p.age;
        sommeHauteurs += p.hauteur;
    }

    std::cout << "+----------+-----+--------+" << std::endl;

    // Calcul et affichage des moyennes
    if (!personnes.empty()) {
        double moyenneAges = sommeAges / personnes.size();
        double moyenneHauteurs = sommeHauteurs / personnes.size();

        std::cout << "\nStatistiques:" << std::endl;
        std::cout << "Nombre de personnes: " << personnes.size() << std::endl;
        std::cout << "Âge moyen: " << std::fixed << std::setprecision(1) << moyenneAges << " ans" << std::endl;
        std::cout << "Hauteur moyenne: " << std::fixed << std::setprecision(2) << moyenneHauteurs << " mètres" << std::endl;
    }

    return 0;
}

// Exercice 1.2: Compilation et Exécution
/*
 * Commandes de compilation:
 *
 * Sans options:
 * g++ hello.cpp -o hello
 *
 * Avec l'option -std=c++17:
 * g++ -std=c++17 hello.cpp -o hello
 *
 * Avec les options -Wall -Wextra -Werror:
 * g++ -Wall -Wextra -Werror hello.cpp -o hello
 *
 * Avec toutes les options combinées:
 * g++ -std=c++17 -Wall -Wextra -Werror hello.cpp -o hello
 *
 * Différences possibles:
 * - L'option -std=c++17 active les fonctionnalités du standard C++17
 * - Les options -Wall -Wextra activent des avertissements supplémentaires
 * - L'option -Werror transforme tous les avertissements en erreurs
 */

// Exercice 1.3: Commentaires et Documentation
/*
 * Fichier: hello_comments.cpp
 */
#include <iostream>

/**
 * Programme simple qui affiche "Hello, World!" à l'écran.
 * Ce programme démontre les bases de l'affichage en C++
 * en utilisant la bibliothèque iostream standard.
 */
int main() {
    // Affiche le message "Hello, World!" suivi d'une nouvelle ligne
    std::cout << "Hello, World!" << std::endl; // Utilise l'objet cout du namespace std

    return 0; // Retourne 0 pour indiquer que le programme s'est terminé avec succès
}

/******************************************
 * Exercice 2: Variables et Types de Données
 ******************************************/

// Exercice 2.1: Déclaration et Initialisation
/*
 * Fichier: variables.cpp
 */
#include <iostream>
#include <string>

int main() {
    // Style d'initialisation avec =
    int age = 25;
    double pi = 3.14159;
    char grade = 'A';
    bool estVrai = true;

    // Style d'initialisation avec ()
    int compteur(100);
    double temperature(36.6);

    // Style d'initialisation avec {}
    int nombre{42};
    double distance{123.45};

    // Affichage des valeurs et tailles
    std::cout << "Variable: age, Type: int, Valeur: " << age
              << ", Taille: " << sizeof(age) << " bytes" << std::endl;

    std::cout << "Variable: pi, Type: double, Valeur: " << pi
              << ", Taille: " << sizeof(pi) << " bytes" << std::endl;

    std::cout << "Variable: grade, Type: char, Valeur: " << grade
              << ", Taille: " << sizeof(grade) << " bytes" << std::endl;

    std::cout << "Variable: estVrai, Type: bool, Valeur: " << estVrai
              << ", Taille: " << sizeof(estVrai) << " bytes" << std::endl;

    std::cout << "Variable: compteur, Type: int, Valeur: " << compteur
              << ", Taille: " << sizeof(compteur) << " bytes" << std::endl;

    std::cout << "Variable: temperature, Type: double, Valeur: " << temperature
              << ", Taille: " << sizeof(temperature) << " bytes" << std::endl;

    std::cout << "Variable: nombre, Type: int, Valeur: " << nombre
              << ", Taille: " << sizeof(nombre) << " bytes" << std::endl;

    std::cout << "Variable: distance, Type: double, Valeur: " << distance
              << ", Taille: " << sizeof(distance) << " bytes" << std::endl;

    return 0;
}

// Exercice 2.2: Constantes
/*
 * Fichier: constantes.cpp
 */
#include <iostream>

int main() {
    // Constantes littérales
    std::cout << "Constantes littérales:" << std::endl;
    std::cout << "Entier: " << 42 << std::endl;
    std::cout << "Réel: " << 3.14159 << std::endl;
    std::cout << "Caractère: " << 'A' << std::endl;
    std::cout << "Chaîne: " << "Hello" << std::endl;

    // Variables constantes
    const int MAX_USERS = 100;
    const double PI = 3.14159265359;
    const char NEWLINE = '\n';

    std::cout << "\nVariables constantes:" << std::endl;
    std::cout << "MAX_USERS: " << MAX_USERS << std::endl;
    std::cout << "PI: " << PI << std::endl;
    std::cout << "NEWLINE: " << NEWLINE << "Après nouvelle ligne" << std::endl;

    // Expressions constantes avec constexpr
    constexpr int ARRAY_SIZE = 10;
    constexpr double LIGHT_SPEED = 299792458.0;
    constexpr int SQUARE_OF_FIVE = 5 * 5;

    std::cout << "\nExpressions constantes (constexpr):" << std::endl;
    std::cout << "ARRAY_SIZE: " << ARRAY_SIZE << std::endl;
    std::cout << "LIGHT_SPEED: " << LIGHT_SPEED << " m/s" << std::endl;
    std::cout << "SQUARE_OF_FIVE: " << SQUARE_OF_FIVE << std::endl;

    return 0;
}

// Exercice 2.3: Conversion de Types
/*
 * Fichier: conversions.cpp
 */
#include <iostream>
#include <climits>  // Pour INT_MAX, INT_MIN

int main() {
    // Conversions implicites
    std::cout << "Conversions implicites:" << std::endl;

    int i = 42;
    double d = i;    // int vers double (pas de perte de données)
    std::cout << "int i = " << i << " -> double d = " << d << std::endl;

    double pi = 3.14159;
    int iPi = pi;    // double vers int (perte de précision)
    std::cout << "double pi = " << pi << " -> int iPi = " << iPi << " (perte de précision)" << std::endl;

    char c = 'A';
    int iChar = c;   // char vers int (conversion en code ASCII)
    std::cout << "char c = '" << c << "' -> int iChar = " << iChar << " (code ASCII)" << std::endl;

    // Conversions explicites (casts)
    std::cout << "\nConversions explicites (casts):" << std::endl;

    double largeValue = 1234.5678;

    // C-style cast
    int iLarge = (int)largeValue;
    std::cout << "C-style cast: double " << largeValue << " -> int " << iLarge << std::endl;

    // static_cast (recommandé en C++ moderne)
    int iLarge2 = static_cast<int>(largeValue);
    std::cout << "static_cast: double " << largeValue << " -> int " << iLarge2 << std::endl;

    // Problèmes potentiels
    std::cout << "\nProblèmes potentiels de conversion:" << std::endl;

    // Perte de précision
    double precise = 3.999999;
    int imprecise = static_cast<int>(precise);
    std::cout << "Perte de précision: double " << precise << " -> int " << imprecise << std::endl;

    // Dépassement
    int maxInt = INT_MAX;
    std::cout << "INT_MAX = " << maxInt << std::endl;

    // Problème de dépassement
    int willOverflow = maxInt + 1;
    std::cout << "Dépassement: INT_MAX + 1 = " << willOverflow << " (résultat incorrect)" << std::endl;

    // Conversion char <-> int
    int largeChar = 130;
    char smallChar = static_cast<char>(largeChar);
    std::cout << "Conversion potentiellement problématique: int " << largeChar
              << " -> char code " << static_cast<int>(smallChar)
              << " (la valeur peut changer selon l'implémentation)" << std::endl;

    return 0;
}

/******************************************
 * Exercice 3: Opérateurs et Expressions
 ******************************************/

// Exercice 3.1: Calculatrice Simple
/*
 * Fichier: calculatrice.cpp
 */
#include <iostream>

int main() {
    double num1, num2;

    // Demande les nombres à l'utilisateur
    std::cout << "Entrez le premier nombre: ";
    std::cin >> num1;

    std::cout << "Entrez le deuxième nombre: ";
    std::cin >> num2;

    // Effectue les opérations de base
    std::cout << "Addition: " << num1 + num2 << std::endl;
    std::cout << "Soustraction: " << num1 - num2 << std::endl;
    std::cout << "Multiplication: " << num1 * num2 << std::endl;

    // Vérification de division par zéro
    if (num2 != 0) {
        std::cout << "Division: " << num1 / num2 << std::endl;
    } else {
        std::cout << "Division: Impossible (division par zéro)" << std::endl;
    }

    // Modulo uniquement pour les entiers
    if (num2 != 0) {
        // Conversion en entier pour le modulo
        int iNum1 = static_cast<int>(num1);
        int iNum2 = static_cast<int>(num2);
        std::cout << "Modulo (entiers): " << iNum1 % iNum2 << std::endl;

        // Avertissement si la conversion a perdu des données
        if (static_cast<double>(iNum1) != num1 || static_cast<double>(iNum2) != num2) {
            std::cout << "Note: les nombres ont été convertis en entiers pour le modulo." << std::endl;
        }
    } else {
        std::cout << "Modulo: Impossible (division par zéro)" << std::endl;
    }

    return 0;
}

// Exercice 3.2: Opérateurs de Comparaison
/*
 * Fichier: comparaisons.cpp
 */
#include <iostream>

int main() {
    int a = 10;
    int b = 20;

    std::cout << "a = " << a << ", b = " << b << std::endl;

    // Opérateurs de comparaison
    std::cout << "\nOpérateurs de comparaison:" << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;

    // Opérateurs logiques
    bool condition1 = (a > 5);  // true
    bool condition2 = (b < 15); // false

    std::cout << "\nOpérateurs logiques:" << std::endl;
    std::cout << "condition1 (a > 5): " << condition1 << std::endl;
    std::cout << "condition2 (b < 15): " << condition2 << std::endl;

    std::cout << "condition1 && condition2: " << (condition1 && condition2) << std::endl;
    std::cout << "condition1 || condition2: " << (condition1 || condition2) << std::endl;
    std::cout << "!condition1: " << (!condition1) << std::endl;
    std::cout << "!condition2: " << (!condition2) << std::endl;

    // Expressions composées
    std::cout << "\nExpressions composées:" << std::endl;
    std::cout << "(a > 5) && (b > 15): " << ((a > 5) && (b > 15)) << std::endl;
    std::cout << "(a > 5) || (b > 15): " << ((a > 5) || (b > 15)) << std::endl;
    std::cout << "!(a > 5) || !(b > 15): " << (!(a > 5) || !(b > 15)) << std::endl;
    std::cout << "((a + b) > 25) && ((b - a) < 15): " << (((a + b) > 25) && ((b - a) < 15)) << std::endl;

    return 0;
}

// Exercice 3.3: Opérateurs Bit à Bit
/*
 * Fichier: bitwise.cpp
 */
#include <iostream>
#include <bitset>  // Pour l'affichage binaire

int main() {
    unsigned int a = 60;  // 00111100 en binaire
    unsigned int b = 13;  // 00001101 en binaire

    std::cout << "a = " << a << " (" << std::bitset<8>(a) << " en binaire)" << std::endl;
    std::cout << "b = " << b << " (" << std::bitset<8>(b) << " en binaire)" << std::endl;

    // Opérateurs bit à bit
    std::cout << "\nOpérateurs bit à bit:" << std::endl;

    // AND
    unsigned int resultAND = a & b;
    std::cout << "a & b = " << resultAND << " (" << std::bitset<8>(resultAND) << " en binaire)" << std::endl;

    // OR
    unsigned int resultOR = a | b;
    std::cout << "a | b = " << resultOR << " (" << std::bitset<8>(resultOR) << " en binaire)" << std::endl;

    // XOR
    unsigned int resultXOR = a ^ b;
    std::cout << "a ^ b = " << resultXOR << " (" << std::bitset<8>(resultXOR) << " en binaire)" << std::endl;

    // NOT
    unsigned int resultNOT_A = ~a;
    std::cout << "~a = " << resultNOT_A << " (" << std::bitset<8>(resultNOT_A) << " en binaire)" << std::endl;

    // Décalage à gauche
    unsigned int resultLeftShift = a << 2;
    std::cout << "a << 2 = " << resultLeftShift << " (" << std::bitset<8>(resultLeftShift) << " en binaire)" << std::endl;

    // Décalage à droite
    unsigned int resultRightShift = a >> 2;
    std::cout << "a >> 2 = " << resultRightShift << " (" << std::bitset<8>(resultRightShift) << " en binaire)" << std::endl;

    return 0;
}

/******************************************
 * Exercice 4: Structures de Contrôle
 ******************************************/

// Exercice 4.1: Conditionnelles
/*
 * Fichier: conditionnelles.cpp
 */
#include <iostream>

int main() {
    int age;

    // Demande l'âge à l'utilisateur
    std::cout << "Entrez votre âge: ";
    std::cin >> age;

    // Vérifie la validité de l'âge
    if (age < 0 || age > 150) {
        std::cout << "Âge invalide. Veuillez entrer un âge réaliste." << std::endl;
    }
    // Détermine la catégorie d'âge
    else if (age < 12) {
        std::cout << "Vous êtes un enfant." << std::endl;
    }
    else if (age < 18) {
        std::cout << "Vous êtes un adolescent." << std::endl;
    }
    else if (age < 65) {
        std::cout << "Vous êtes un adulte." << std::endl;
    }
    else {
        std::cout << "Vous êtes un senior." << std::endl;
    }

    return 0;
}

// Exercice 4.2: Switch
/*
 * Fichier: switch.cpp
 */
#include <iostream>

int main() {
    int note;

    // Demande la note à l'utilisateur
    std::cout << "Entrez une note numérique (0-100): ";
    std::cin >> note;

    // Vérifie la validité de la note
    if (note < 0 || note > 100) {
        std::cout << "Note invalide. Veuillez entrer une note entre 0 et 100." << std::endl;
        return 1;  // Retourne une erreur
    }

    // Convertit la note numérique en note alphabétique
    char noteAlpha;
    switch (note / 10) {
        case 10:
        case 9:
            noteAlpha = 'A';
            break;
        case 8:
            noteAlpha = 'B';
            break;
        case 7:
            noteAlpha = 'C';
            break;
        case 6:
            noteAlpha = 'D';
            break;
        default:
            noteAlpha = 'F';
            break;
    }

    // Affiche la note alphabétique
    std::cout << "Note alphabétique: " << noteAlpha << std::endl;

    // Affiche un message selon la note
    switch (noteAlpha) {
        case 'A':
            std::cout << "Excellent travail!" << std::endl;
            break;
        case 'B':
            std::cout << "Bon travail!" << std::endl;
            break;
        case 'C':
            std::cout << "Travail satisfaisant." << std::endl;
            break;
        case 'D':
            std::cout << "Vous avez tout juste réussi." << std::endl;
            break;
        case 'F':
            std::cout << "Vous n'avez pas réussi. Veuillez retravailler." << std::endl;
            break;
        default:
            std::cout << "Erreur dans la conversion." << std::endl;
            break;
    }

    return 0;
}

// Exercice 4.3: Boucles
// Exercice 4.3.1: Boucle for
/*
 * Fichier: boucle_for.cpp
 */
#include <iostream>

int main() {
    std::cout << "Affichage des nombres de 1 à 10 avec une boucle for:" << std::endl;

    for (int i = 1; i <= 10; i++) {
        std::cout << i;

        // Ajoute une virgule sauf pour le dernier nombre
        if (i < 10) {
            std::cout << ", ";
        }
    }

    std::cout << std::endl;
    return 0;
}

// Exercice 4.3.2: Boucle while
/*
 * Fichier: boucle_while.cpp
 */
#include <iostream>

int main() {
    int n;

    // Demande un nombre à l'utilisateur
    std::cout << "Entrez un nombre entier positif: ";
    std::cin >> n;

    // Vérifie que le nombre est positif
    if (n <= 0) {
        std::cout << "Veuillez entrer un nombre positif." << std::endl;
        return 1;  // Retourne une erreur
    }

    // Calcule la somme des nombres de 1 à n avec une boucle while
    int i = 1;
    int somme = 0;

    while (i <= n) {
        somme += i;
        i++;
    }

    std::cout << "La somme des nombres de 1 à " << n << " est: " << somme << std::endl;

    return 0;
}

// Exercice 4.3.3: Boucle do-while
/*
 * Fichier: boucle_do_while.cpp
 */
#include <iostream>

int main() {
    int choix;

    do {
        // Affiche le menu
        std::cout << "\nMenu Principal:" << std::endl;
        std::cout << "1. Afficher un message" << std::endl;
        std::cout << "2. Calculer le carré d'un nombre" << std::endl;
        std::cout << "3. Dire bonjour" << std::endl;
        std::cout << "0. Quitter" << std::endl;
        std::cout << "Votre choix: ";
        std::cin >> choix;

        // Traite le choix de l'utilisateur
        switch (choix) {
            case 1:
                std::cout << "Message important: La programmation C++ est puissante!" << std::endl;
                break;
            case 2: {
                double nombre;
                std::cout << "Entrez un nombre: ";
                std::cin >> nombre;
                std::cout << "Le carré de " << nombre << " est " << nombre * nombre << std::endl;
                break;
            }
            case 3:
                std::cout << "Bonjour, comment allez-vous aujourd'hui?" << std::endl;
                break;
            case 0:
                std::cout << "Au revoir!" << std::endl;
                break;
            default:
                std::cout << "Choix invalide. Veuillez réessayer." << std::endl;
                break;
        }

    } while (choix != 0);  // Continue jusqu'à ce que l'utilisateur choisisse de quitter

    return 0;
}

/******************************************
 * Exercice 5: Fonctions
 ******************************************/

// Exercice 5.1: Définition et Appel de Fonctions
/*
 * Fichier: fonctions.cpp
 */
#include <iostream>

// Fonction qui calcule le carré d'un nombre
double carre(double x) {
    return x * x;
}

// Fonction qui calcule le cube d'un nombre
double cube(double x) {
    return x * x * x;
}

// Fonction qui calcule la puissance n d'un nombre
double puissance(double base, int exposant) {
    if (exposant == 0) {
        return 1;
    }

    double resultat = 1.0;
    bool exposantNegatif = exposant < 0;

    // Convertit l'exposant négatif en positif pour le calcul
    if (exposantNegatif) {
        exposant = -exposant;
    }

    // Calcule la puissance avec un exposant positif
    for (int i = 0; i < exposant; i++) {
        resultat *= base;
    }

    // Si l'exposant était négatif, prend l'inverse du résultat
    if (exposantNegatif) {
        resultat = 1.0 / resultat;
    }

    return resultat;
}

int main() {
    double nombre;
    int exposant;

    // Demande un nombre à l'utilisateur
    std::cout << "Entrez un nombre: ";
    std::cin >> nombre;

    // Calcule et affiche le carré
    std::cout << "Le carré de " << nombre << " est " << carre(nombre) << std::endl;

    // Calcule et affiche le cube
    std::cout << "Le cube de " << nombre << " est " << cube(nombre) << std::endl;

    // Demande un exposant à l'utilisateur
    std::cout << "Entrez un exposant: ";
    std::cin >> exposant;

    // Calcule et affiche la puissance n
    std::cout << nombre << " à la puissance " << exposant << " est " << puissance(nombre, exposant) << std::endl;

    return 0;
}

// Exercice 5.2: Surcharge de Fonctions
/*
 * Fichier: surcharge.cpp
 */
#include <iostream>

// Fonction max pour les entiers
int max(int a, int b) {
    std::cout << "Appel de max(int, int)" << std::endl;
    return (a > b) ? a : b;
}

// Fonction max pour les doubles
double max(double a, double b) {
    std::cout << "Appel de max(double, double)" << std::endl;
    return (a > b) ? a : b;
}

// Fonction max pour les caractères
char max(char a, char b) {
    std::cout << "Appel de max(char, char)" << std::endl;
    return (a > b) ? a : b;
}

// Fonction max pour trois entiers (surcharge par nombre de paramètres)
int max(int a, int b, int c) {
    std::cout << "Appel de max(int, int, int)" << std::endl;
    return max(max(a, b), c);
}

int main() {
    // Test avec des entiers
    int i1 = 42, i2 = 73;
    std::cout << "Le maximum entre " << i1 << " et " << i2 << " est " << max(i1, i2) << std::endl;

    // Test avec des doubles
    double d1 = 3.14, d2 = 2.71;
    std::cout << "Le maximum entre " << d1 << " et " << d2 << " est " << max(d1, d2) << std::endl;

    // Test avec des caractères
    char c1 = 'A', c2 = 'Z';
    std::cout << "Le maximum entre '" << c1 << "' et '" << c2 << "' est '" << max(c1, c2) << "'" << std::endl;

    // Test avec trois entiers
    int i3 = 100;
    std::cout << "Le maximum entre " << i1 << ", " << i2 << " et " << i3 << " est " << max(i1, i2, i3) << std::endl;

    // Test avec des types mixtes (conversion implicite)
    int i4 = 10;
    double d3 = 10.5;
    // Ceci appelle max(double, double) car i4 est converti en double
    std::cout << "Le maximum entre " << i4 << " et " << d3 << " est " << max(i4, d3) << std::endl;

    return 0;
}

// Exercice 5.3: Portée et Durée de Vie
/*
 * Fichier: portee.cpp
 */
#include <iostream>

int compteurGlobal = 0;  // Variable globale

void incrementer() {
    static int compteurStatique = 0;  // Variable statique locale
    int compteurLocal = 0;  // Variable locale

    compteurGlobal++;
    compteurStatique++;
    compteurLocal++;

    std::cout << "Global: " << compteurGlobal << ", Statique: " << compteurStatique
              << ", Local: " << compteurLocal << std::endl;
}

// Fonction pour démontrer la portée des variables
void demontrerPortee() {
    int x = 10;  // Variable locale à demontrerPortee

    std::cout << "Dans demontrerPortee, x = " << x << std::endl;

    {  // Nouveau bloc
        int x = 20;  // Variable locale au bloc, masque la variable précédente
        int y = 30;  // Variable locale au bloc

        std::cout << "  Dans le bloc interne, x = " << x << ", y = " << y << std::endl;
    }

    // y n'est plus accessible ici
    std::cout << "  Après le bloc, x = " << x << std::endl;

    // Accès à la variable globale
    std::cout << "  La variable globale compteurGlobal = " << compteurGlobal << std::endl;
}

int main() {
    for (int i = 0; i < 3; i++) {
        incrementer();
    }

    std::cout << "\nDémonstration de la portée des variables:" << std::endl;
    demontrerPortee();

    // Démonstration de la durée de vie
    std::cout << "\nDémonstration de la durée de vie des variables:" << std::endl;
    {
        int variableTemporaire = 100;
        std::cout << "variableTemporaire créée avec la valeur " << variableTemporaire << std::endl;
    }
    // variableTemporaire n'existe plus ici

    // Démonstration des variables globales
    std::cout << "\nValeur finale de compteurGlobal: " << compteurGlobal << std::endl;

    return 0;
}

/******************************************
 * Exercice 6: Tableaux et Chaînes
 ******************************************/

// Exercice 6.1: Tableaux à Une Dimension
/*
 * Fichier: tableau_1d.cpp
 */
#include <iostream>
#include <climits>  // Pour INT_MIN, INT_MAX

int main() {
    // Déclaration et initialisation d'un tableau d'entiers
    int tableau[] = {8, 4, 12, 16, 5, 9, 7, 11};
    int taille = sizeof(tableau) / sizeof(tableau[0]);

    std::cout << "Tableau: ";
    for (int i = 0; i < taille; i++) {
        std::cout << tableau[i];
        if (i < taille - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;

    // Calcul de la somme
    int somme = 0;
    for (int i = 0; i < taille; i++) {
        somme += tableau[i];
    }

    // Calcul de la moyenne
    double moyenne = static_cast<double>(somme) / taille;

    // Recherche du minimum et du maximum
    int minimum = INT_MAX;
    int maximum = INT_MIN;

    for (int i = 0; i < taille; i++) {
        if (tableau[i] < minimum) {
            minimum = tableau[i];
        }
        if (tableau[i] > maximum) {
            maximum = tableau[i];
        }
    }

    // Affichage des résultats
    std::cout << "Somme: " << somme << std::endl;
    std::cout << "Moyenne: " << moyenne << std::endl;
    std::cout << "Minimum: " << minimum << std::endl;
    std::cout << "Maximum: " << maximum << std::endl;

    // Recherche d'un élément spécifique
    int elementRecherche;
    std::cout << "\nEntrez un élément à rechercher: ";
    std::cin >> elementRecherche;

    bool trouve = false;
    int position = -1;

    for (int i = 0; i < taille; i++) {
        if (tableau[i] == elementRecherche) {
            trouve = true;
            position = i;
            break;
        }
    }

    if (trouve) {
        std::cout << "L'élément " << elementRecherche << " a été trouvé à la position " << position << std::endl;
    } else {
        std::cout << "L'élément " << elementRecherche << " n'a pas été trouvé dans le tableau." << std::endl;
    }

    return 0;
}

// Exercice 6.2: Tableaux à Deux Dimensions
/*
 * Fichier: tableau_2d.cpp
 */
#include <iostream>
#include <iomanip>  // Pour std::setw

int main() {
    // Définition d'une matrice 3x3
    int matrice[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Affichage de la matrice
    std::cout << "Matrice 3x3:" << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << std::setw(4) << matrice[i][j];
        }
        std::cout << std::endl;
    }

    // Calcul de la somme de chaque ligne
    int sommeLignes[3] = {0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sommeLignes[i] += matrice[i][j];
        }
    }

    // Calcul de la somme de chaque colonne
    int sommeColonnes[3] = {0};
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 3; i++) {
            sommeColonnes[j] += matrice[i][j];
        }
    }

    // Affichage des sommes
    std::cout << "\nSomme des lignes:" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << "Ligne " << i + 1 << ": " << sommeLignes[i] << std::endl;
    }

    std::cout << "\nSomme des colonnes:" << std::endl;
    for (int j = 0; j < 3; j++) {
        std::cout << "Colonne " << j + 1 << ": " << sommeColonnes[j] << std::endl;
    }

    // Affichage de la matrice sous forme de tableau avec les sommes
    std::cout << "\nTableau avec sommes:" << std::endl;
    std::cout << "+------+------+------+-------+" << std::endl;
    std::cout << "|      |   1  |   2  |   3   | Somme |" << std::endl;
    std::cout << "+------+------+------+-------+" << std::endl;

    for (int i = 0; i < 3; i++) {
        std::cout << "|   " << i + 1 << "  |";
        for (int j = 0; j < 3; j++) {
            std::cout << std::setw(4) << matrice[i][j] << "  |";
        }
        std::cout << std::setw(5) << sommeLignes[i] << " |" << std::endl;
    }

    std::cout << "+------+------+------+-------+" << std::endl;
    std::cout << "| Somme|";
    for (int j = 0; j < 3; j++) {
        std::cout << std::setw(4) << sommeColonnes[j] << "  |";
    }

    // Calcul de la somme totale
    int sommeTotal = 0;
    for (int i = 0; i < 3; i++) {
        sommeTotal += sommeLignes[i];
    }

    std::cout << std::setw(5) << sommeTotal << " |" << std::endl;
    std::cout << "+------+------+------+-------+" << std::endl;

    return 0;
}
