# Exercices du Module 2: POO Fondamentale

## Exercice 1: Classes et Objets

### 1.1 Création d'une Classe Personne
Créez une classe `Personne` qui:
1. Possède des attributs pour le nom, l'âge et l'adresse
2. Inclut des méthodes pour afficher les informations et modifier l'âge
3. Démontre l'instanciation et l'utilisation d'objets

```cpp
// Exemple de sortie attendue:
// Nom: Alice Dupont, Âge: 30 ans, Adresse: 123 Rue Principale
// Après anniversaire: Alice Dupont, Âge: 31 ans, Adresse: 123 Rue Principale
```

### 1.2 Comparaison entre Classe et Structure
Réimplémentez l'exercice précédent en utilisant une structure au lieu d'une classe, puis:
1. Comparez les différences syntaxiques et conceptuelles
2. Expliquez quand utiliser une classe vs une structure
3. Démontrez l'impact des modificateurs d'accès par défaut différents

## Exercice 2: Encapsulation et Accesseurs

### 2.1 Classe CompteBancaire
Implémentez une classe `CompteBancaire` qui:
1. Encapsule les données (solde, numéro de compte, propriétaire)
2. Fournit des accesseurs et mutateurs appropriés
3. Inclut des méthodes pour dépôt et retrait avec validation

```cpp
// Exemple d'utilisation:
CompteBancaire compte("Jean Martin", 12345);
compte.deposer(1000);
if (compte.retirer(500)) {
    std::cout << "Retrait réussi, nouveau solde: " << compte.getSolde() << std::endl;
}
```

### 2.2 Validation des Données
Étendez la classe `CompteBancaire` pour:
1. Valider le montant des dépôts et retraits (positifs, limites quotidiennes)
2. Vérifier le solde avant retrait
3. Enregistrer l'historique des transactions
4. Implémenter un système de notification pour les opérations importantes

## Exercice 3: Constructeurs et Destructeurs

### 3.1 Classe Rectangle avec Constructeurs Multiples
Créez une classe `Rectangle` avec:
1. Un constructeur par défaut (rectangle unité)
2. Un constructeur avec paramètres pour longueur et largeur
3. Un constructeur de copie
4. Un destructeur qui affiche un message
5. Une méthode pour calculer l'aire

Testez tous les constructeurs et observez l'ordre d'appel des constructeurs et destructeurs.

### 3.2 Gestion de Ressources
Implémentez une classe `GestionnaireFichier` qui:
1. Ouvre un fichier dans son constructeur
2. Ferme le fichier dans son destructeur
3. Fournit des méthodes pour lire et écrire dans le fichier
4. Démontre le concept RAII (Resource Acquisition Is Initialization)

## Exercice 4: Membres Statiques

### 4.1 Compteur d'Objets
Créez une classe `Compteur` qui:
1. Utilise un membre statique pour suivre le nombre d'instances créées
2. Incrémente ce compteur dans le constructeur
3. Décrémente ce compteur dans le destructeur
4. Fournit une méthode statique pour obtenir le nombre d'instances

```cpp
// Exemple de sortie:
// Nombre d'instances: 3
// Après destruction: Nombre d'instances: 1
```

### 4.2 Classe Utilitaire
Implémentez une classe `MathUtils` qui:
1. Contient uniquement des méthodes et constantes statiques
2. Inclut des fonctions comme factorielle, puissance, pgcd, etc.
3. Définit des constantes mathématiques (PI, E, etc.)
4. Ne peut pas être instanciée (constructeur privé)

## Exercice 5: L'Opérateur This

### 5.1 Chaînage de Méthodes
Créez une classe `TextFormatter` qui:
1. Stocke et manipule une chaîne de caractères
2. Possède des méthodes pour mettre en majuscules, en minuscules, inverser, etc.
3. Utilise l'opérateur `this` pour permettre le chaînage des appels de méthodes

```cpp
// Exemple d'utilisation:
TextFormatter text("Hello");
text.append(" World").toUpperCase().reverse();
std::cout << text.getText() << std::endl;  // "DLROW OLLEH"
```

### 5.2 Résolution d'Ambiguïté
Écrivez une classe où les noms de paramètres sont identiques aux noms d'attributs:
1. Utilisez l'opérateur `this` pour résoudre l'ambiguïté
2. Implémentez également une version avec liste d'initialisation
3. Comparez les deux approches et discutez des avantages/inconvénients

## Exercice 6: Surcharge d'Opérateurs

### 6.1 Classe Fraction
Implémentez une classe `Fraction` qui:
1. Représente une fraction avec numérateur et dénominateur
2. Surcharge les opérateurs arithmétiques (+, -, *, /)
3. Surcharge les opérateurs de comparaison (==, !=, <, >, <=, >=)
4. Surcharge l'opérateur d'affectation (=)
5. Surcharge l'opérateur de sortie (<<)

```cpp
// Exemple d'utilisation:
Fraction f1(1, 2);  // 1/2
Fraction f2(1, 3);  // 1/3
Fraction f3 = f1 + f2;  // 5/6
std::cout << f3 << std::endl;  // "5/6"
```

### 6.2 Classe Vecteur
Créez une classe `Vecteur3D` qui:
1. Représente un vecteur dans l'espace 3D (x, y, z)
2. Surcharge les opérateurs appropriés (+, -, *, produit scalaire, etc.)
3. Implémente l'opérateur d'indexation ([]) pour accéder aux composantes
4. Surcharge l'opérateur de cast pour obtenir la norme du vecteur

## Exercice 7: Héritage Simple

### 7.1 Hiérarchie de Formes
Créez une hiérarchie de classes pour représenter des formes géométriques:
1. Une classe de base `Forme` avec position et méthodes communes
2. Des classes dérivées pour `Rectangle`, `Cercle`, et `Triangle`
3. Implémentez des méthodes spécifiques pour chaque forme
4. Utilisez correctement les spécificateurs d'accès (public, protected, private)

### 7.2 Types d'Héritage
Expérimentez avec différents types d'héritage:
1. Créez des classes avec héritage public, protected et private
2. Démontrez l'impact sur l'accessibilité des membres
3. Discutez des cas d'utilisation appropriés pour chaque type

## Exercice 8: Polymorphisme et Fonctions Virtuelles

### 8.1 Système d'Objets de Jeu
Implémentez un système simple pour un jeu:
1. Une classe de base `GameObject` avec des méthodes virtuelles
2. Des classes dérivées pour `Player`, `Enemy`, `Item`, etc.
3. Une méthode `update()` polymorphique
4. Testez le polymorphisme avec un tableau d'objets hétérogènes

```cpp
// Exemple d'utilisation:
std::vector<GameObject*> gameObjects;
gameObjects.push_back(new Player("Hero"));
gameObjects.push_back(new Enemy("Goblin"));
gameObjects.push_back(new Item("Potion"));

for (auto obj : gameObjects) {
    obj->update();  // Appelle la méthode appropriée selon le type
}
```

### 8.2 Redéfinition vs Masquage
Créez un exemple qui démontre:
1. La différence entre redéfinition (avec virtual) et masquage (sans virtual)
2. L'importance du mot-clé `override`
3. Les erreurs courantes lors de la redéfinition de méthodes

## Exercice 9: Classes Abstraites et Interfaces

### 9.1 Interface Dessinable
Créez une interface (classe abstraite pure) `Dessinable`:
1. Définissez des méthodes pures virtuelles comme `dessiner()`, `redimensionner()`
2. Implémentez plusieurs classes qui réalisent cette interface
3. Utilisez le polymorphisme pour manipuler des objets via l'interface

### 9.2 Héritage Multiple avec Interfaces
Implémentez un système avec héritage multiple:
1. Créez plusieurs interfaces (`Sauvegardable`, `Animable`, etc.)
2. Implémentez une classe qui hérite de plusieurs interfaces
3. Résolvez les problèmes potentiels comme les méthodes en conflit
4. Discutez des avantages et inconvénients de l'héritage multiple

## Projet Mini: Jeu de Cartes

Concevez et implémentez un jeu de cartes simple qui utilise les concepts de POO:

1. **Hiérarchie de Classes**:
   - Classes pour `Carte`, `Main`, `Jeu`, `Joueur`
   - Différents types de cartes (héritage)

2. **Encapsulation et Protection**:
   - Données membres privées avec accesseurs appropriés
   - Validation des actions de jeu

3. **Polymorphisme**:
   - Différentes stratégies de jeu (IA vs Humain)
   - Actions polymorphiques sur les cartes

4. **Bonnes Pratiques**:
   - Utilisation appropriée de const
   - Gestion correcte de la mémoire
   - Organisation claire du code

5. **Bonus**:
   - Interface utilisateur textuelle
   - Sauvegarde/chargement de parties
   - Statistiques de jeu

Ce projet vous permettra d'appliquer tous les concepts de POO vus dans ce module et de créer une application complète et fonctionnelle.
