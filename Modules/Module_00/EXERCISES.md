# Exercices du Module 0: Bases Fondamentales du C++

## Exercice 1: Premier Pas en C++

### 1.1 Hello, World!
Créez un programme qui affiche "Hello, World!" à l'écran.

```cpp
// Exemple de sortie attendue:
// Hello, World!
```

### 1.2 Compilation et Exécution
Compilez et exécutez le programme en utilisant les options suivantes:
- Sans options
- Avec l'option `-std=c++17`
- Avec les options `-Wall -Wextra -Werror`
- Avec toutes les options combinées

Documentez les différences observées, s'il y en a.

### 1.3 Commentaires et Documentation
Modifiez votre programme "Hello, World!" pour inclure:
- Des commentaires sur une ligne (`//`)
- Des commentaires sur plusieurs lignes (`/* */`)
- Une brève documentation expliquant ce que fait le programme

## Exercice 2: Variables et Types de Données

### 2.1 Déclaration et Initialisation
Écrivez un programme qui:
1. Déclare et initialise des variables de différents types (int, double, char, bool)
2. Affiche leurs valeurs
3. Affiche leur taille en mémoire (utilisez `sizeof()`)
4. Utilise les trois styles d'initialisation (=, (), {})

```cpp
// Exemple de sortie attendue:
// Variable: age, Type: int, Valeur: 25, Taille: 4 bytes
// Variable: pi, Type: double, Valeur: 3.14159, Taille: 8 bytes
// ...
```

### 2.2 Constantes
Créez un programme qui utilise:
1. Des constantes littérales (nombres, caractères, chaînes)
2. Des variables constantes (`const`)
3. Des expressions constantes (`constexpr` si disponible)

### 2.3 Conversion de Types
Écrivez un programme démontrant:
1. Les conversions implicites entre types numériques
2. Les conversions explicites (casts) entre différents types
3. Les problèmes potentiels liés aux conversions (perte de précision, dépassement)

## Exercice 3: Opérateurs et Expressions

### 3.1 Calculatrice Simple
Créez une calculatrice en ligne de commande qui:
1. Demande à l'utilisateur deux nombres
2. Effectue les opérations de base (+, -, *, /, %)
3. Affiche les résultats

```cpp
// Exemple d'interaction:
// Entrez le premier nombre: 10
// Entrez le deuxième nombre: 3
// Addition: 13
// Soustraction: 7
// Multiplication: 30
// Division: 3.333
// Modulo: 1
```

### 3.2 Opérateurs de Comparaison
Écrivez un programme qui:
1. Compare deux valeurs en utilisant différents opérateurs (==, !=, >, <, >=, <=)
2. Affiche les résultats des comparaisons
3. Utilise des expressions composées avec les opérateurs logiques (&&, ||, !)

### 3.3 Opérateurs Bit à Bit
Créez un programme qui démontre l'utilisation des opérateurs bit à bit:
1. AND (&), OR (|), XOR (^), NOT (~)
2. Décalages à gauche (<<) et à droite (>>)
3. Affichez les résultats en binaire et en décimal

## Exercice 4: Structures de Contrôle

### 4.1 Conditionnelles
Écrivez un programme qui:
1. Demande l'âge de l'utilisateur
2. Utilise des structures if-else pour déterminer la catégorie d'âge
3. Affiche un message personnalisé selon la catégorie

```cpp
// Exemple d'interaction:
// Entrez votre âge: 17
// Vous êtes un adolescent.
```

### 4.2 Switch
Créez un programme de conversion de notes qui:
1. Demande une note numérique (0-100)
2. Utilise switch pour convertir en note alphabétique (A, B, C, D, F)
3. Affiche la note alphabétique

### 4.3 Boucles
Écrivez des programmes distincts qui utilisent:
1. Une boucle for pour afficher les nombres de 1 à 10
2. Une boucle while pour calculer la somme des nombres de 1 à n (saisi par l'utilisateur)
3. Une boucle do-while pour créer un menu simple qui s'exécute jusqu'à ce que l'utilisateur choisisse de quitter

## Exercice 5: Fonctions

### 5.1 Définition et Appel de Fonctions
Créez un programme avec:
1. Une fonction qui calcule le carré d'un nombre
2. Une fonction qui calcule le cube d'un nombre
3. Une fonction qui calcule la puissance n d'un nombre
4. Une fonction principale qui appelle les autres fonctions et affiche les résultats

### 5.2 Surcharge de Fonctions
Écrivez un programme qui:
1. Définit plusieurs fonctions `max` pour différents types (int, double, char)
2. Démontre comment le compilateur choisit la fonction appropriée selon les arguments
3. Utilise ces fonctions pour trouver le maximum de différentes paires de valeurs

### 5.3 Portée et Durée de Vie
Créez un programme démontrant:
1. Variables locales et globales
2. Variables statiques dans les fonctions
3. Comment la portée affecte l'accès aux variables

```cpp
// Exemple:
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

int main() {
    for (int i = 0; i < 3; i++) {
        incrementer();
    }
    return 0;
}
// Sortie attendue:
// Global: 1, Statique: 1, Local: 1
// Global: 2, Statique: 2, Local: 1
// Global: 3, Statique: 3, Local: 1
```

## Exercice 6: Tableaux et Chaînes

### 6.1 Tableaux à Une Dimension
Écrivez un programme qui:
1. Déclare et initialise un tableau d'entiers
2. Calcule la somme, la moyenne, le minimum et le maximum des éléments
3. Recherche un élément spécifique dans le tableau

### 6.2 Tableaux à Deux Dimensions
Créez un programme qui:
1. Définit une matrice 3x3
2. Calcule la somme de chaque ligne et colonne
3. Affiche la matrice sous forme de tableau

### 6.3 Manipulation de Chaînes
Écrivez un programme qui:
1. Utilise des chaînes de style C (char[])
2. Utilise des chaînes de style C++ (std::string)
3. Implémente des opérations comme la concaténation, l'extraction de sous-chaînes, la recherche

## Exercice 7: Entrées/Sorties

### 7.1 Lecture/Écriture Console
Créez un programme qui:
1. Demande des informations à l'utilisateur (nom, âge, hauteur)
2. Valide les entrées (âge doit être positif, etc.)
3. Affiche un résumé formaté des informations

### 7.2 Formatage des Sorties
Écrivez un programme qui:
1. Affiche des nombres avec différentes précisions
2. Utilise des champs de largeur fixe pour aligner les sorties
3. Affiche des nombres dans différentes bases (décimal, hexadécimal, octal)

```cpp
// Exemple de sortie:
// Décimal: 42, Hexadécimal: 0x2A, Octal: 052
// Pi (2 décimales): 3.14
// Pi (5 décimales): 3.14159
// |    Nom    |  Age  |  Taille  |
// |-----------|-------|----------|
// |   Alice   |   25  |  1.65m   |
// |    Bob    |   30  |  1.80m   |
```

### 7.3 Lecture/Écriture Fichiers (optionnel)
Créez un programme qui:
1. Écrit des données dans un fichier texte
2. Lit des données depuis un fichier texte
3. Analyse et affiche les données lues

## Projet Mini: Carnet d'Adresses Console

Créez un carnet d'adresses simple en console qui combine plusieurs concepts du module:

1. **Modèle de données**:
   - Définir une structure `Contact` avec nom, téléphone, email, etc.
   - Utiliser un tableau pour stocker plusieurs contacts (max 100)

2. **Interface utilisateur**:
   - Menu interactif en console
   - Options pour ajouter, rechercher, afficher, modifier et supprimer des contacts

3. **Fonctionnalités**:
   - Validation des entrées utilisateur
   - Recherche par nom ou téléphone
   - Affichage formaté des contacts
   - Gestion des erreurs basique

4. **Organisation du code**:
   - Diviser le programme en fonctions
   - Utiliser des commentaires explicatifs
   - Structurer le code de manière claire et lisible

Ce projet vous permettra d'appliquer tous les concepts fondamentaux du C++ abordés dans ce module, en créant une application console complète et utile.
