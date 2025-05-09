# Solutions pour Module 1: Fondamentaux des Structures de Données

Toutes les solutions sont disponibles dans le dossier `files/`. Consultez le [README du dossier files](files/README.md) pour plus d'informations sur chaque fichier et comment les compiler.

## Liste des exercices et solutions

### Exercice 1: Pointeurs et Références
- [Exercice 1.1: Manipulation de Pointeurs](files/pointeurs.cpp)
- [Exercice 1.2: Arithmétique des Pointeurs](files/arith_pointeurs.cpp)
- [Exercice 1.3: Références](files/references.cpp)

### Exercice 2: Gestion de la Mémoire
- [Exercice 2.1: Allocation Dynamique](files/allocation.cpp)
- [Exercice 2.2: Détection de Fuites Mémoire](files/fuites_memoire.cpp)
- [Exercice 2.3: Gestion des Erreurs d'Allocation](files/erreurs_allocation.cpp)

### Exercice 3: Structures et Énumérations
- [Exercice 3.1: Système de Gestion d'Étudiants](files/gestion_etudiants.cpp)
- [Exercice 3.2: Énumérations](files/enumerations.cpp)
- [Exercice 3.3: Organisation du Code avec des Structures](files/inventaire.cpp)

### Exercice 4: Conteneurs STL
- [Exercice 4.1: std::vector](files/vector.cpp)
- [Exercice 4.2: std::array](files/array.cpp)
- [Exercice 4.3: Migration de Tableaux C vers Conteneurs STL](files/migration_tableaux.cpp)

### Exercice 5: Manipulation de Chaînes
- [Exercice 5.1: Traitement de Chaînes Style C](files/chaines_c.cpp)
- [Exercice 5.2: Traitement avec std::string](files/string.cpp)
- [Exercice 5.3: Parseur de Texte Simple](files/parseur_texte.cpp)

### Exercice 6: Passage de Paramètres
- [Exercice 6.1: Efficacité des Méthodes de Passage](files/efficacite_passage.cpp)
- [Exercice 6.2: Passage Constant et Non Constant](files/passage_const.cpp)
- [Exercice 6.3: Chaînage de Fonctions](files/chainage_fonctions.cpp)

### Exercice 7: Portée et Durée de Vie
- [Exercice 7.1: Variables Statiques](files/variables_statiques.cpp)
- [Exercice 7.2: Variables Globales vs Locales](files/portee_variables.cpp)
- [Exercice 7.3: Gestion Automatique de Ressources](files/gestion_ressources.cpp)

### Projet Mini: Éditeur de Texte Simple
- [Implémentation de l'éditeur de texte](files/editeur_texte.cpp)

## Compilation et exécution

Un Makefile est fourni dans le dossier `files/` pour faciliter la compilation de tous les programmes. Pour compiler tous les programmes, naviguez vers le dossier `files/` et exécutez:

```bash
cd files/
make
```

Pour compiler un programme spécifique:

```bash
make pointeurs
```

Pour nettoyer tous les fichiers compilés:

```bash
make clean
```
