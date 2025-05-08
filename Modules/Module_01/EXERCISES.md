# Exercices du Module 1: Fondamentaux des Structures de Données

## Exercice 1: Pointeurs et Références

### 1.1 Manipulation de Pointeurs
Écrivez un programme qui:
1. Déclare plusieurs variables de différents types (int, double, char)
2. Crée des pointeurs vers ces variables
3. Affiche les adresses et les valeurs pointées
4. Modifie les valeurs via les pointeurs et affiche les résultats

```cpp
// Exemple de sortie attendue:
// Variable: x, Valeur: 10, Adresse: 0x7ffd5fbff8ac
// Pointeur: ptr_x, Adresse pointée: 0x7ffd5fbff8ac, Valeur pointée: 10
// Après modification via pointeur: x = 20
```

### 1.2 Arithmétique des Pointeurs
Écrivez un programme qui:
1. Crée un tableau d'entiers
2. Utilise un pointeur pour parcourir le tableau et afficher ses éléments
3. Démontre l'arithmétique des pointeurs (++, --, +n, -n)
4. Calcule la différence entre deux pointeurs

### 1.3 Références
Créez un programme qui compare l'utilisation des références et des pointeurs:
1. Écrivez une fonction qui prend un entier par valeur et le modifie
2. Écrivez une fonction qui prend un entier par pointeur et le modifie
3. Écrivez une fonction qui prend un entier par référence et le modifie
4. Démontrez les différences dans l'appel et l'effet de ces fonctions

## Exercice 2: Gestion de la Mémoire

### 2.1 Allocation Dynamique
Écrivez un programme qui:
1. Alloue dynamiquement un tableau d'entiers dont la taille est spécifiée par l'utilisateur
2. Remplit le tableau avec des valeurs saisies par l'utilisateur
3. Calcule la somme, la moyenne, le minimum et le maximum des valeurs
4. Libère correctement la mémoire allouée

### 2.2 Détection de Fuites Mémoire
Écrivez un programme avec des fuites mémoire délibérées, puis corrigez-les:
1. Créez plusieurs allocations sans libération
2. Utilisez un outil comme Valgrind ou AddressSanitizer pour détecter les fuites
3. Corrigez les fuites et vérifiez que tout est bien libéré

### 2.3 Gestion des Erreurs d'Allocation
Écrivez un programme qui:
1. Essaie d'allouer une grande quantité de mémoire (par exemple, plusieurs gigaoctets)
2. Utilise try/catch pour gérer les erreurs d'allocation
3. Affiche un message d'erreur approprié en cas d'échec

## Exercice 3: Structures et Énumérations

### 3.1 Système de Gestion d'Étudiants
Créez un programme de gestion d'étudiants qui:
1. Définit une structure `Etudiant` avec des champs pour le nom, l'ID, et les notes
2. Alloue dynamiquement un tableau d'étudiants
3. Permet d'ajouter, d'afficher et de rechercher des étudiants
4. Calcule la moyenne des notes de tous les étudiants

```cpp
// Structure suggérée
struct Etudiant {
    std::string nom;
    int id;
    double notes[5];
    double moyenne;
};
```

### 3.2 Énumérations
Écrivez un programme qui:
1. Définit une énumération classique pour les jours de la semaine
2. Définit une énumération fortement typée (enum class) pour les mois de l'année
3. Démontre les différences d'utilisation entre les deux types d'énumérations
4. Utilise une énumération dans un switch pour afficher des messages différents

### 3.3 Organisation du Code avec des Structures
Créez un programme simple de gestion d'inventaire qui:
1. Définit des structures pour `Produit`, `Stock` et `Transaction`
2. Implémente des fonctions pour ajouter/retirer des produits du stock
3. Enregistre les transactions et génère un rapport simple
4. Organise le code de manière modulaire avec des structures appropriées

## Exercice 4: Conteneurs STL

### 4.1 std::vector
Écrivez un programme qui:
1. Crée un vecteur d'entiers
2. Ajoute des éléments au vecteur de différentes manières (`push_back`, initialisation, etc.)
3. Parcourt le vecteur avec différentes méthodes (index, itérateurs, boucle basée sur plage)
4. Effectue des opérations communes (tri, recherche, suppression d'éléments)

### 4.2 std::array
Écrivez un programme qui:
1. Utilise std::array pour stocker des données de température pour chaque mois
2. Calcule la température moyenne, minimale et maximale
3. Compare les performances avec un tableau C classique (facultatif)
4. Démontre les avantages de std::array par rapport aux tableaux classiques

### 4.3 Migration de Tableaux C vers Conteneurs STL
Prenez un programme existant (ou créez-en un) qui utilise des tableaux C, puis:
1. Convertissez-le pour utiliser std::vector ou std::array
2. Ajoutez des fonctionnalités qui seraient difficiles avec des tableaux C
3. Comparez le code avant et après pour identifier les améliorations

## Exercice 5: Manipulation de Chaînes

### 5.1 Traitement de Chaînes Style C
Écrivez un programme qui utilise des chaînes style C (char[]) pour:
1. Inverser une chaîne de caractères
2. Compter le nombre d'occurrences d'un caractère spécifique
3. Convertir une chaîne en majuscules ou minuscules
4. Concaténer plusieurs chaînes de manière sécurisée

### 5.2 Traitement avec std::string
Réimplémentez l'exercice précédent avec std::string et comparez:
1. La facilité d'implémentation
2. La sécurité du code
3. La lisibilité
4. Utilisez des méthodes spécifiques à std::string (find, replace, substr, etc.)

### 5.3 Parseur de Texte Simple
Créez un parseur de texte qui:
1. Lit un texte (à partir d'un fichier ou d'une chaîne)
2. Compte le nombre de mots, de lignes et de caractères
3. Identifie les mots les plus fréquents
4. Démontre les différences entre la manipulation avec char[] et std::string

## Exercice 6: Passage de Paramètres

### 6.1 Efficacité des Méthodes de Passage
Écrivez un programme qui:
1. Définit une structure volumineuse (par exemple, un tableau de 1000 entiers)
2. Implémente des fonctions qui acceptent cette structure par valeur, par pointeur et par référence
3. Mesure le temps d'exécution de chaque méthode sur de nombreux appels
4. Analyse et explique les différences de performances

### 6.2 Passage Constant et Non Constant
Écrivez une classe ou une fonction qui:
1. Accepte un paramètre de différentes manières (const et non-const)
2. Démontre quand utiliser const références vs références non-const
3. Illustre les erreurs de compilation qui se produisent lors de modifications de valeurs const

### 6.3 Chaînage de Fonctions
Créez un ensemble de fonctions qui:
1. Transforment des données de différentes manières (par exemple, filtrer, mapper, réduire)
2. Peuvent être chaînées ensemble grâce à des retours par référence
3. Utilisent correctement const pour les paramètres qui ne doivent pas être modifiés

## Exercice 7: Portée et Durée de Vie

### 7.1 Variables Statiques
Écrivez un programme qui:
1. Utilise des variables statiques dans des fonctions
2. Compte le nombre d'appels à différentes fonctions
3. Démontre la persistance des variables statiques entre les appels

### 7.2 Variables Globales vs Locales
Créez un programme qui:
1. Utilise des variables globales et locales de même nom
2. Démontre le masquage des variables (shadowing)
3. Utilise l'opérateur de résolution de portée (::) pour accéder aux variables globales

### 7.3 Gestion Automatique de Ressources
Écrivez une classe simple qui:
1. Alloue des ressources dans son constructeur (par exemple, mémoire dynamique)
2. Libère ces ressources dans son destructeur
3. Démontre comment les objets à portée automatique gèrent automatiquement leur durée de vie

## Projet Mini: Éditeur de Texte Simple

Créez un éditeur de texte en ligne de commande qui combine plusieurs concepts du module:

1. **Modèle de données**:
   - Structure pour représenter le texte (lignes, caractères)
   - Utilisation de std::vector et std::string pour stocker le contenu

2. **Fonctionnalités**:
   - Chargement et sauvegarde de fichiers texte
   - Ajout, suppression et modification de lignes
   - Recherche et remplacement de texte
   - Statistiques sur le texte (nombre de mots, lignes, etc.)

3. **Organisation**:
   - Séparation des données et des opérations
   - Gestion efficace de la mémoire
   - Passage approprié des paramètres entre fonctions

4. **Bonus**:
   - Implémentez un historique d'actions (undo/redo)
   - Ajoutez un mode d'édition visuelle simple
   - Gérez correctement les caractères spéciaux ou encodages

Ce projet vous permettra d'appliquer les concepts de structures de données, de gestion de mémoire et de passage de paramètres dans un contexte pratique et utile.
