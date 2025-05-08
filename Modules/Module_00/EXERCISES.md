# Exercices du Module 0: Fondamentaux C++ Revisités

## Exercice 1: Manipulation de Types et Variables

### 1.1 Exploration des Types
Créez un programme qui:
1. Déclare et initialise des variables de différents types (int, double, char, bool)
2. Affiche leur valeur, taille en mémoire et adresse
3. Utilise les littéraux numériques avec séparateurs de C++17

```cpp
// Exemple de sortie attendue:
// Variable: x, Type: int, Valeur: 42, Taille: 4 bytes, Adresse: 0x7ffd5fbff8ac
```

### 1.2 Inférence de Type avec auto
Modifiez le programme précédent pour utiliser `auto` pour déclarer certaines variables.
Créez des exemples où `auto` est utile et d'autres où il peut être problématique.

### 1.3 Structured Binding
Écrivez un programme qui utilise la fonctionnalité de structured binding pour:
1. Extraire les éléments d'un `std::pair`
2. Parcourir et afficher les clés et valeurs d'un `std::map`
3. Manipuler un tableau ou une structure personnalisée

## Exercice 2: Références et Pointeurs

### 2.1 Comparaison de Références et Pointeurs
Créez un programme démontrant:
1. La différence entre passage par valeur, référence et pointeur
2. Les bonnes pratiques pour le choix entre référence et pointeur
3. L'utilisation de `nullptr` plutôt que `NULL`

### 2.2 Références rvalue
Écrivez une fonction qui accepte une référence rvalue et une autre qui accepte une référence lvalue.
Démontrez quand chacune d'elles est appelée avec différents types d'arguments.

## Exercice 3: Expressions et Opérateurs

### 3.1 Utilisation de if constexpr
Créez une fonction template qui se comporte différemment selon le type:
1. Pour les types entiers, effectue une opération arithmétique
2. Pour les types à virgule flottante, effectue une opération différente
3. Pour les chaînes, effectue une concaténation

Utilisez `if constexpr` pour la sélection conditionnelle à la compilation.

### 3.2 Fold Expressions
Écrivez des fonctions templates variadiques utilisant les fold expressions pour:
1. Calculer la somme de tous les arguments
2. Concaténer toutes les chaînes passées en argument
3. Trouver le minimum ou maximum de tous les arguments

## Exercice 4: Structures de Contrôle Modernes

### 4.1 Range-Based For Loop
Implémentez une classe qui stocke une collection et fournit:
1. Des méthodes `begin()` et `end()` pour permettre l'itération avec range-based for loop
2. Une démonstration d'utilisation avec différents types de conteneurs

### 4.2 If et Switch avec Initialisation
Réécrivez des blocs conditionnels existants en utilisant les nouvelles syntaxes C++17:
1. Convertissez des blocs if classiques en if avec initialisation
2. Convertissez des blocs switch classiques en switch avec initialisation

## Exercice 5: Fonctions et Lambda

### 5.1 Surcharge de Fonctions
Créez un ensemble de fonctions surchargées `print` qui:
1. Gèrent différents types (entiers, flottants, chaînes, etc.)
2. Formatent différemment selon le type
3. Acceptent un paramètre optionnel pour personnaliser l'affichage

### 5.2 Lambdas Avancées
Écrivez un programme qui:
1. Utilise des lambdas simples, avec capture, et génériques
2. Implémente un algorithme de tri personnalisé avec une lambda comme prédicat
3. Utilise `std::function` pour stocker des lambdas et les utiliser plus tard

## Exercice 6: Namespaces

### 6.1 Organisation du Code
Créez une petite bibliothèque avec:
1. Namespaces imbriqués pour organiser le code (par exemple: Game::Graphics, Game::Audio)
2. Démonstration de la nouvelle syntaxe C++17 pour les namespaces imbriqués
3. Utilisation appropriée de using declaration vs. using directive

## Exercice 7: Gestion des Erreurs Moderne

### 7.1 std::optional
Implémentez des fonctions qui utilisent `std::optional` pour:
1. Rechercher un élément dans un conteneur
2. Analyser une entrée qui pourrait être invalide
3. Enchaîner des opérations qui peuvent échouer

### 7.2 std::variant
Créez une classe qui utilise `std::variant` pour:
1. Stocker différents types de données dans un même champ
2. Utiliser `std::visit` pour traiter les différentes variantes
3. Implémenter un petit système de messages polymorphes sans héritage

## Projet Mini: Gestionnaire de Tâches Moderne

Créez un gestionnaire de tâches simple qui combine plusieurs concepts du module:

1. **Modèle de données**:
   - Définir une structure `Task` avec id, titre, description, priorité, date limite, etc.
   - Utiliser `std::optional` pour les champs optionnels
   - Utiliser `std::variant` pour permettre différents types de tâches

2. **Stockage**:
   - Utiliser des conteneurs modernes pour stocker les tâches
   - Implémenter des méthodes pour ajouter, supprimer, rechercher des tâches

3. **Interface**:
   - Créer une interface en ligne de commande simple
   - Utiliser des lambdas pour les callbacks et le traitement
   - Implémenter une fonction de recherche flexible

4. **Outils**:
   - Fournir des outils pour filtrer/trier les tâches
   - Permettre l'export/import des tâches (format texte simple)

5. **Organisation**:
   - Organiser le code en namespaces appropriés
   - Utiliser des bonnes pratiques modernes C++17

Ce projet vous permettra d'appliquer tous les concepts du module dans un contexte pratique et de vous préparer pour les modules suivants qui exploreront la POO et d'autres fonctionnalités avancées.
