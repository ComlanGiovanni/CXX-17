# Exercices du Module 3: Héritage et Polymorphisme

## Exercice 1: Héritage Simple

### 1.1 Hiérarchie d'Animaux
Créez une hiérarchie de classes représentant différents animaux:
1. Une classe de base `Animal` avec des attributs comme nom, âge, et des méthodes communes
2. Plusieurs classes dérivées comme `Chien`, `Chat`, `Oiseau` avec des comportements spécifiques
3. Testez l'héritage des attributs et méthodes
4. Ajoutez des méthodes spécifiques à chaque type d'animal

```cpp
// Exemple de sortie attendue:
// Rex le chien mange.
// Rex aboie.
// Minou le chat dort.
// Minou miaule.
```

### 1.2 Types d'Héritage
Créez trois hiérarchies de classes pour expérimenter les différents types d'héritage:
1. Utilisez l'héritage public, protected et private dans différentes hiérarchies
2. Démontrez l'impact sur l'accessibilité des membres à travers des tests
3. Documentez les différences observées et les cas d'utilisation appropriés

## Exercice 2: Fonctions Membres Virtuelles

### 2.1 Système de Formes Géométriques
Implémentez un système de formes géométriques qui:
1. Utilise une classe de base `Forme` avec des méthodes virtuelles `aire()` et `perimetre()`
2. Crée des classes dérivées comme `Cercle`, `Rectangle` et `Triangle`
3. Démontre le comportement polymorphique en appelant ces méthodes virtuelles
4. Affiche les résultats pour comprendre le mécanisme de liaison dynamique

```cpp
// Exemple d'utilisation:
std::vector<Forme*> formes;
formes.push_back(new Cercle(5));
formes.push_back(new Rectangle(4, 6));
formes.push_back(new Triangle(3, 4, 5));

for (auto forme : formes) {
    std::cout << "Aire: " << forme->aire() << ", Périmètre: " << forme->perimetre() << std::endl;
}
```

### 2.2 Destructeurs Virtuels
Créez un exemple qui:
1. Démontre le problème de la fuite mémoire avec les destructeurs non-virtuels
2. Corrige le problème en utilisant des destructeurs virtuels
3. Utilise Valgrind ou un autre outil pour confirmer les fuites mémoire avant/après correction
4. Discute de l'importance des destructeurs virtuels dans les hiérarchies de classes

## Exercice 3: Polymorphisme

### 3.1 Système de Personnages de Jeu
Concevez un système de personnages pour un jeu simple:
1. Une classe de base `Personnage` avec des attributs comme santé, position, et méthodes virtuelles
2. Des classes dérivées comme `Joueur`, `Ennemi`, `PNJ` (Personnage Non Joueur)
3. Implémentez des méthodes polymorphiques comme `attaquer()`, `deplacer()`, `afficher()`
4. Utilisez un gestionnaire de personnages qui manipule tous les personnages de manière uniforme

```cpp
// Exemple de code:
class GestionnaireJeu {
public:
    void mettreAJour(const std::vector<Personnage*>& personnages) {
        for (auto p : personnages) {
            p->mettreAJour();  // Appel polymorphique
        }
    }

    void dessiner(const std::vector<Personnage*>& personnages) {
        for (auto p : personnages) {
            p->dessiner();  // Appel polymorphique
        }
    }
};
```

### 3.2 Liaison Dynamique vs Statique
Créez un exemple didactique qui:
1. Illustre clairement la différence entre la liaison statique et dynamique
2. Démontre les conséquences sur le comportement du programme
3. Inclut des méthodes non-virtuelles (masquées) et virtuelles (redéfinies)
4. Discute des implications en termes de performance et de flexibilité

## Exercice 4: Classes Abstraites et Interfaces

### 4.1 Interface Drawable
Implémentez une interface (classe abstraite pure) `Drawable`:
1. Définissez des méthodes virtuelles pures comme `draw()` et `getBounds()`
2. Créez plusieurs classes concrètes implémentant cette interface
3. Utilisez un système de rendu qui accepte des objets `Drawable`
4. Explorez l'extension du système sans modifier le code existant

```cpp
// Exemple d'interface:
class Drawable {
public:
    virtual ~Drawable() = default;
    virtual void draw(Screen& screen) const = 0;
    virtual Rect getBounds() const = 0;
};
```

### 4.2 Architecture de Plugin
Concevez une architecture de plugin simple qui:
1. Définit une interface pour les plugins à travers une classe abstraite
2. Implémente plusieurs plugins concrets avec des fonctionnalités différentes
3. Crée un gestionnaire de plugins qui charge et utilise les plugins dynamiquement
4. Montre comment l'architecture permet d'ajouter des fonctionnalités sans modifier le code existant

## Exercice 5: Override et Final

### 5.1 Utilisation d'Override
Créez un exercice qui:
1. Implémente une hiérarchie de classes avec plusieurs niveaux d'héritage
2. Utilise le mot-clé `override` pour toutes les redéfinitions
3. Introduit délibérément des erreurs de signature pour démontrer la détection par le compilateur
4. Discute des avantages en termes de maintenance et de prévention des erreurs

```cpp
// Exemple de redéfinition correcte vs incorrecte:
class Base {
public:
    virtual void methode1(int x) const;
    virtual void methode2(double y);
};

class Derivee : public Base {
public:
    void methode1(int x) const override;  // Correct
    // void methode1(int x) override;      // Incorrect: manque 'const'
    // void methode2(float y) override;    // Incorrect: type différent
};
```

### 5.2 Utilisation de Final
Implémentez un exemple qui:
1. Utilise le mot-clé `final` sur certaines méthodes pour empêcher leur redéfinition
2. Crée une classe marquée comme `final` pour empêcher l'héritage
3. Tente délibérément de violer ces restrictions pour montrer les erreurs de compilation
4. Discute des cas d'utilisation appropriés pour `final`

## Exercice 6: Composition vs Héritage

### 6.1 Refactoring d'Héritage vers Composition
Prenez un exemple d'héritage et refactorisez-le pour utiliser la composition:
1. Commencez avec une hiérarchie d'héritage (par exemple, `Vehicule` -> `Voiture`, `Avion`)
2. Refactorisez en utilisant la composition (par exemple, `Voiture` contient un `Moteur`)
3. Comparez les deux implémentations en termes de flexibilité, réutilisabilité et couplage
4. Discutez des situations où chaque approche est préférable

```cpp
// Avant (héritage):
class Vehicule {
protected:
    void demarrerMoteur();
};

class Voiture : public Vehicule {
public:
    void conduire();
};

// Après (composition):
class Moteur {
public:
    void demarrer();
};

class Voiture {
private:
    Moteur moteur;
public:
    void conduire() {
        moteur.demarrer();
        // Conduite spécifique à la voiture
    }
};
```

### 6.2 Patterns de Conception
Implémentez deux patterns de conception qui utilisent l'héritage et la composition:
1. Le pattern Composite (utilisant à la fois l'héritage et la composition)
2. Le pattern Decorator (utilisant à la fois l'héritage et la composition)
3. Démontrez comment ces patterns résolvent des problèmes spécifiques
4. Analysez l'équilibre entre héritage et composition dans ces patterns

## Projet Mini: Système d'Entités pour Jeu 2D

Développez un système d'entités simple pour un jeu 2D qui combine les concepts d'héritage, de polymorphisme et de composition:

1. **Architecture du Système**:
   - Classe de base `Entity` avec position, vitesse, état
   - Classes dérivées comme `Player`, `Enemy`, `Projectile`, `Item`
   - Interfaces comme `Drawable`, `Collidable`, `Updatable`

2. **Hiérarchie de Composants**:
   - Système hybride utilisant l'héritage pour les types d'entités
   - Composition pour les capacités/comportements (comme `HealthComponent`, `CollisionComponent`)

3. **Fonctionnalités Minimales**:
   - Mouvement des entités
   - Détection de collisions basique
   - Rendu simple (console ou graphique simple)
   - Gestion de l'état du jeu

4. **Polymorphisme**:
   - Gestionnaire de jeu qui manipule toutes les entités uniformément
   - Boucle de jeu qui met à jour et dessine toutes les entités

5. **Bonus**:
   - Système d'événements/messages entre entités
   - Ajout d'une interface utilisateur simple
   - Niveau de jeu chargé depuis un fichier

Ce projet vous permettra d'appliquer tous les concepts d'héritage et de polymorphisme dans un contexte pratique de développement de jeu, tout en explorant les compromis entre l'héritage et la composition.
