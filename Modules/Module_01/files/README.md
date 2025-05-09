# Solutions du Module 1: Fondamentaux des Structures de Données

Ce dossier contient toutes les solutions des exercices du Module 1.

## Compilation des programmes

Un Makefile est inclus pour faciliter la compilation. Vous pouvez l'utiliser de plusieurs façons:

### Compiler tous les programmes
```
make
```

### Compiler un programme spécifique
```
make pointeurs
```

### Nettoyer les fichiers compilés
```
make clean
```

## Liste des programmes

| Fichier | Description |
|---------|-------------|
| pointeurs.cpp | Solution de l'exercice 1.1: Manipulation de Pointeurs |
| arithmetique_pointeurs.cpp | Solution de l'exercice 1.2: Arithmétique des Pointeurs |
| references.cpp | Solution de l'exercice 1.3: Références vs Pointeurs |
| allocation_dynamique.cpp | Solution de l'exercice 2.1: Allocation Dynamique |
| detection_fuites.cpp | Solution de l'exercice 2.2: Détection de Fuites Mémoire |
| gestion_erreurs_allocation.cpp | Solution de l'exercice 2.3: Gestion des Erreurs d'Allocation |
| gestion_etudiants.cpp | Solution de l'exercice 3.1: Système de Gestion d'Étudiants |
| enumerations.cpp | Solution de l'exercice 3.2: Énumérations |
| gestion_inventaire.cpp | Solution de l'exercice 3.3: Organisation du Code avec des Structures |
| vector_demo.cpp | Solution de l'exercice 4.1: std::vector |
| array_demo.cpp | Solution de l'exercice 4.2: std::array |
| migration_tableaux.cpp | Solution de l'exercice 4.3: Migration de Tableaux C vers Conteneurs STL |

## Remarques importantes

Ces programmes démontrent les concepts fondamentaux des structures de données en C++, notamment:

1. **Pointeurs et références**: Manipulation de la mémoire, arithmétique des pointeurs et utilisation des références.
2. **Gestion de la mémoire**: Allocation dynamique, détection et prévention des fuites mémoire.
3. **Structures et énumérations**: Organisation des données et utilisation des énumérations.
4. **Conteneurs STL**: Utilisation des conteneurs modernes (vector, array) et migration des tableaux C vers la STL.

Chaque programme contient des commentaires détaillés pour faciliter la compréhension des concepts.
