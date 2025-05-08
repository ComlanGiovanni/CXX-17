# Module 3: Héritage et Polymorphisme

Ce module explore les concepts fondamentaux de l'héritage et du polymorphisme en C++, qui permettent de créer des hiérarchies de classes flexibles et extensibles, essentielles pour le développement de jeux.

## 1. Héritage Simple

### Principe et Syntaxe de Base
```cpp
// Classe de base (ou classe parente)
class Animal {
protected:
    std::string nom;
    int age;

public:
    Animal(const std::string& n, int a) : nom(n), age(a) {}

    void manger() const {
        std::cout << nom << " mange." << std::endl;
    }

    void dormir() const {
        std::cout << nom << " dort." << std::endl;
    }
};

// Classe dérivée (ou classe enfant)
class Chat : public Animal {
private:
    bool griffesSorties;

public:
    Chat(const std::string& n, int a)
        : Animal(n, a), griffesSorties(false) {}

    void miauler() const {
        std::cout << nom << " miaule." << std::endl;
    }

    void sortirGriffes() {
        griffesSorties = true;
        std::cout << nom << " sort ses griffes!" << std::endl;
    }
};

// Utilisation
Chat felix("Felix", 3);
felix.manger();      // Méthode héritée de Animal
felix.dormir();      // Méthode héritée de Animal
felix.miauler();     // Méthode spécifique à Chat
felix.sortirGriffes(); // Méthode spécifique à Chat
```

### Spécificateurs d'Accès et Héritage
```cpp
class Base {
public:
    int publicMembre;      // Accessible partout
protected:
    int protectedMembre;   // Accessible dans Base et ses classes dérivées
private:
    int privateMembre;     // Accessible uniquement dans Base
};

// Héritage public: le plus courant
class DerivePublic : public Base {
    void test() {
        publicMembre = 1;      // OK: reste public dans la classe dérivée
        protectedMembre = 2;   // OK: reste protected dans la classe dérivée
        // privateMembre = 3;  // Erreur: inaccessible, même dans la classe dérivée
    }
};

// Héritage protected: moins courant
class DeriveProtected : protected Base {
    void test() {
        publicMembre = 1;      // OK: devient protected dans la classe dérivée
        protectedMembre = 2;   // OK: reste protected dans la classe dérivée
        // privateMembre = 3;  // Erreur: inaccessible, même dans la classe dérivée
    }
};

// Héritage private: rare
class DerivePrivate : private Base {
    void test() {
        publicMembre = 1;      // OK: devient private dans la classe dérivée
        protectedMembre = 2;   // OK: devient private dans la classe dérivée
        // privateMembre = 3;  // Erreur: inaccessible, même dans la classe dérivée
    }
};

// Démonstration d'accessibilité
void demo() {
    DerivePublic dp;
    dp.publicMembre = 10;     // OK: public reste accessible
    // dp.protectedMembre = 20; // Erreur: protected n'est pas accessible de l'extérieur

    DeriveProtected dpr;
    // dpr.publicMembre = 10;   // Erreur: devenu protected, n'est plus accessible

    DerivePrivate dpv;
    // dpv.publicMembre = 10;   // Erreur: devenu private, n'est plus accessible
}
```

### Constructeurs et Destructeurs dans l'Héritage
```cpp
class Parent {
protected:
    std::string nom;

public:
    // Constructeur
    Parent(const std::string& n) : nom(n) {
        std::cout << "Construction de Parent: " << nom << std::endl;
    }

    // Destructeur
    ~Parent() {
        std::cout << "Destruction de Parent: " << nom << std::endl;
    }
};

class Enfant : public Parent {
private:
    int age;

public:
    // Constructeur qui appelle explicitement celui du parent
    Enfant(const std::string& n, int a) : Parent(n), age(a) {
        std::cout << "Construction de Enfant: " << nom << ", " << age << " ans" << std::endl;
    }

    // Destructeur
    ~Enfant() {
        std::cout << "Destruction de Enfant: " << nom << ", " << age << " ans" << std::endl;
    }
};

// Ordre d'appel des constructeurs et destructeurs
void test() {
    Enfant e("Alice", 10);
    // Sortie:
    // Construction de Parent: Alice
    // Construction de Enfant: Alice, 10 ans

    // À la fin du bloc:
    // Destruction de Enfant: Alice, 10 ans
    // Destruction de Parent: Alice
}
```

### Relation "est un" vs "a un"
```cpp
// Relation "est un" (héritage)
class Vehicule {
public:
    void rouler() { std::cout << "Le véhicule roule" << std::endl; }
};

class Voiture : public Vehicule {  // Une voiture EST UN véhicule
public:
    void klaxonner() { std::cout << "La voiture klaxonne" << std::endl; }
};

// Relation "a un" (composition)
class Moteur {
public:
    void demarrer() { std::cout << "Le moteur démarre" << std::endl; }
};

class Avion {  // Un avion A UN moteur
private:
    Moteur moteur;  // Composition
public:
    void voler() {
        moteur.demarrer();
        std::cout << "L'avion vole" << std::endl;
    }
};
```

## 2. Fonctions Membres Virtuelles

### Principe et Mécanisme
```cpp
class Animal {
public:
    void manger() {
        std::cout << "L'animal mange" << std::endl;
    }

    // Méthode virtuelle
    virtual void emettreSon() {
        std::cout << "L'animal émet un son" << std::endl;
    }
};

class Chien : public Animal {
public:
    // Masque la méthode non-virtuelle du parent
    void manger() {
        std::cout << "Le chien mange des croquettes" << std::endl;
    }

    // Redéfinit la méthode virtuelle du parent
    void emettreSon() override {
        std::cout << "Le chien aboie" << std::endl;
    }
};

void tester(Animal& animal) {
    animal.manger();     // Appelle la méthode de Animal, pas de polymorphisme
    animal.emettreSon(); // Appelle la méthode de la classe dérivée (polymorphisme)
}

// Test
Chien fido;
tester(fido);  // Sortie: "L'animal mange" puis "Le chien aboie"
```

### Table des Fonctions Virtuelles (vtable)
```cpp
// Explication de la vtable (pas de code exécutable)
/*
Lorsqu'une classe contient des fonctions virtuelles:
1. Le compilateur crée une table de fonctions virtuelles (vtable) pour cette classe
2. Chaque instance de la classe contient un pointeur caché vers cette vtable
3. Lors d'un appel à une fonction virtuelle, le système utilise ce pointeur
   pour trouver la bonne implémentation à exécuter

Classe     | vtable
-----------|-----------
Animal     | emettreSon() -> Animal::emettreSon()
Chien      | emettreSon() -> Chien::emettreSon()

Ce mécanisme permet la liaison dynamique (résolution à l'exécution)
plutôt que la liaison statique (résolution à la compilation).
*/
```

### Redéfinition vs Masquage
```cpp
class Base {
public:
    void methodeNormale() {
        std::cout << "Base::methodeNormale()" << std::endl;
    }

    virtual void methodeVirtuelle() {
        std::cout << "Base::methodeVirtuelle()" << std::endl;
    }
};

class Derivee : public Base {
public:
    // Masquage (hiding): pas de polymorphisme
    void methodeNormale() {
        std::cout << "Derivee::methodeNormale()" << std::endl;
    }

    // Redéfinition (overriding): avec polymorphisme
    void methodeVirtuelle() override {
        std::cout << "Derivee::methodeVirtuelle()" << std::endl;
    }
};

// Test
void test() {
    Derivee d;
    d.methodeNormale();    // Appelle Derivee::methodeNormale()
    d.methodeVirtuelle();  // Appelle Derivee::methodeVirtuelle()

    Base& b = d;
    b.methodeNormale();    // Appelle Base::methodeNormale() (pas de polymorphisme)
    b.methodeVirtuelle();  // Appelle Derivee::methodeVirtuelle() (polymorphisme)
}
```

### Destructeurs Virtuels
```cpp
class Base {
public:
    Base() { std::cout << "Construction de Base" << std::endl; }

    // Destructeur non-virtuel (risqué)
    ~Base() { std::cout << "Destruction de Base" << std::endl; }
};

class Derivee : public Base {
private:
    int* ressource;

public:
    Derivee() {
        std::cout << "Construction de Derivee" << std::endl;
        ressource = new int[100];
    }

    ~Derivee() {
        std::cout << "Destruction de Derivee" << std::endl;
        delete[] ressource;  // Libération des ressources
    }
};

// Problème sans destructeur virtuel
void probleme() {
    Base* ptr = new Derivee();  // Une Derivee est aussi une Base
    delete ptr;  // Appelle uniquement ~Base(), pas ~Derivee() => fuite mémoire!
}

// Solution: rendre le destructeur virtuel
class BaseCorrigee {
public:
    BaseCorrigee() { std::cout << "Construction de BaseCorrigee" << std::endl; }

    // Destructeur virtuel (bonne pratique)
    virtual ~BaseCorrigee() { std::cout << "Destruction de BaseCorrigee" << std::endl; }
};

class DeriveeCorrigee : public BaseCorrigee {
private:
    int* ressource;

public:
    DeriveeCorrigee() {
        std::cout << "Construction de DeriveeCorrigee" << std::endl;
        ressource = new int[100];
    }

    ~DeriveeCorrigee() override {
        std::cout << "Destruction de DeriveeCorrigee" << std::endl;
        delete[] ressource;  // Sera bien appelé maintenant
    }
};

// Solution correcte
void solution() {
    BaseCorrigee* ptr = new DeriveeCorrigee();
    delete ptr;  // Appelle d'abord ~DeriveeCorrigee() puis ~BaseCorrigee()
}
```

## 3. Polymorphisme

### Pointeurs et Références vers la Classe de Base
```cpp
class Forme {
public:
    virtual ~Forme() {}
    virtual double aire() const = 0;
    virtual void dessiner() const = 0;
};

class Rectangle : public Forme {
private:
    double largeur, hauteur;

public:
    Rectangle(double l, double h) : largeur(l), hauteur(h) {}

    double aire() const override {
        return largeur * hauteur;
    }

    void dessiner() const override {
        std::cout << "Dessin d'un rectangle " << largeur << "x" << hauteur << std::endl;
    }
};

class Cercle : public Forme {
private:
    double rayon;

public:
    Cercle(double r) : rayon(r) {}

    double aire() const override {
        return 3.14159 * rayon * rayon;
    }

    void dessiner() const override {
        std::cout << "Dessin d'un cercle de rayon " << rayon << std::endl;
    }
};

// Utilisation polymorphique
void manipulerForme(const Forme& forme) {
    std::cout << "Aire: " << forme.aire() << std::endl;
    forme.dessiner();
}

// Test
Rectangle rect(5, 3);
Cercle cercle(2);

manipulerForme(rect);    // Polymorphisme via référence
manipulerForme(cercle);  // Polymorphisme via référence

// Tableau polymorphique
std::vector<Forme*> formes;
formes.push_back(new Rectangle(4, 2));
formes.push_back(new Cercle(3));

for (Forme* f : formes) {
    manipulerForme(*f);
    delete f;  // N'oubliez pas de libérer la mémoire
}
```

### Liaison Dynamique vs Liaison Statique
```cpp
class Base {
public:
    // Liaison statique (résolution à la compilation)
    void methodeStatique() {
        std::cout << "Base::methodeStatique()" << std::endl;
    }

    // Liaison dynamique (résolution à l'exécution)
    virtual void methodeDynamique() {
        std::cout << "Base::methodeDynamique()" << std::endl;
    }
};

class Derivee : public Base {
public:
    void methodeStatique() {
        std::cout << "Derivee::methodeStatique()" << std::endl;
    }

    void methodeDynamique() override {
        std::cout << "Derivee::methodeDynamique()" << std::endl;
    }
};

// Comportement différent selon le type de liaison
void test() {
    Derivee d;
    Base& ref = d;

    // Liaison statique: le type apparent (Base) détermine la méthode appelée
    ref.methodeStatique();  // Appelle Base::methodeStatique()

    // Liaison dynamique: le type réel (Derivee) détermine la méthode appelée
    ref.methodeDynamique(); // Appelle Derivee::methodeDynamique()
}
```

### Avantages du Polymorphisme dans l'Architecture Logicielle
```cpp
// Sans polymorphisme (code rigide et répétitif)
void traiterFormesSansPolymorphisme(const std::vector<std::string>& typeFormes) {
    for (const auto& type : typeFormes) {
        if (type == "rectangle") {
            // Code spécifique au rectangle
        } else if (type == "cercle") {
            // Code spécifique au cercle
        } else if (type == "triangle") {
            // Code spécifique au triangle
        }
        // Ajout d'un nouveau type = modification de cette méthode
    }
}

// Avec polymorphisme (code extensible)
void traiterFormesAvecPolymorphisme(const std::vector<Forme*>& formes) {
    for (const auto& forme : formes) {
        forme->dessiner();  // Appel polymorphique
        // Ajout d'un nouveau type = pas de modification ici
    }
}

// Extension du système: ajout d'un nouveau type sans modifier le code existant
class Triangle : public Forme {
private:
    double base, hauteur;

public:
    Triangle(double b, double h) : base(b), hauteur(h) {}

    double aire() const override {
        return (base * hauteur) / 2;
    }

    void dessiner() const override {
        std::cout << "Dessin d'un triangle de base " << base
                  << " et de hauteur " << hauteur << std::endl;
    }
};

// Le code utilisant Forme fonctionne automatiquement avec Triangle
```

## 4. Classes Abstraites et Interfaces

### Classes Abstraites avec Fonctions Virtuelles Pures
```cpp
// Classe abstraite: au moins une méthode virtuelle pure (=0)
class FormeAbstraite {
public:
    virtual ~FormeAbstraite() {}

    // Méthode virtuelle pure (pas d'implémentation)
    virtual double aire() const = 0;

    // Méthode virtuelle pure
    virtual void dessiner() const = 0;

    // Méthode concrète (avec implémentation)
    void afficherAire() const {
        std::cout << "Aire: " << aire() << std::endl;
    }
};

// FormeAbstraite f;  // Erreur: impossible d'instancier une classe abstraite

// Classe concrète qui implémente toutes les méthodes virtuelles pures
class TriangleConcret : public FormeAbstraite {
private:
    double base, hauteur;

public:
    TriangleConcret(double b, double h) : base(b), hauteur(h) {}

    double aire() const override {
        return (base * hauteur) / 2;
    }

    void dessiner() const override {
        std::cout << "Dessin d'un triangle de base " << base
                  << " et de hauteur " << hauteur << std::endl;
    }
};

// TriangleConcret peut être instancié
TriangleConcret t(10, 5);
t.dessiner();
t.afficherAire();
```

### Conception d'Interfaces en C++
```cpp
// Interface (classe abstraite pure sans données membres)
class Drawable {
public:
    virtual ~Drawable() = default;

    virtual void draw() const = 0;
    virtual void resize(double factor) = 0;
};

// Autre interface
class Persistable {
public:
    virtual ~Persistable() = default;

    virtual void save(const std::string& filename) const = 0;
    virtual void load(const std::string& filename) = 0;
};

// Implémentation de plusieurs interfaces (héritage multiple)
class Image : public Drawable, public Persistable {
private:
    std::string filename;
    double width, height;

public:
    Image(const std::string& fn, double w, double h)
        : filename(fn), width(w), height(h) {}

    // Implémentation de l'interface Drawable
    void draw() const override {
        std::cout << "Dessin de l'image " << filename << std::endl;
    }

    void resize(double factor) override {
        width *= factor;
        height *= factor;
    }

    // Implémentation de l'interface Persistable
    void save(const std::string& fn) const override {
        std::cout << "Sauvegarde de l'image dans " << fn << std::endl;
    }

    void load(const std::string& fn) override {
        filename = fn;
        std::cout << "Chargement de l'image depuis " << fn << std::endl;
    }
};

// Utilisation polymorphique des interfaces
void renderDrawable(const Drawable& d) {
    d.draw();
}

void storeObject(const Persistable& p, const std::string& filename) {
    p.save(filename);
}

// Test
Image img("photo.jpg", 800, 600);
renderDrawable(img);  // Utilise l'interface Drawable
storeObject(img, "backup.jpg");  // Utilise l'interface Persistable
```

### Utilisation des Classes Abstraites comme Contrats
```cpp
// Interface (contrat)
class AudioComponent {
public:
    virtual ~AudioComponent() = default;

    // Contrat: ces méthodes doivent être implémentées
    virtual void initialize() = 0;
    virtual void play(const std::string& sound) = 0;
    virtual void stop() = 0;
    virtual void setVolume(float volume) = 0;
};

// Implémentation pour Windows
class WindowsAudio : public AudioComponent {
public:
    void initialize() override {
        std::cout << "Initialisation du système audio Windows" << std::endl;
    }

    void play(const std::string& sound) override {
        std::cout << "Lecture de " << sound << " via Windows API" << std::endl;
    }

    void stop() override {
        std::cout << "Arrêt de la lecture via Windows API" << std::endl;
    }

    void setVolume(float volume) override {
        std::cout << "Volume réglé à " << volume << " via Windows API" << std::endl;
    }
};

// Implémentation pour Linux
class LinuxAudio : public AudioComponent {
public:
    void initialize() override {
        std::cout << "Initialisation du système audio Linux (ALSA)" << std::endl;
    }

    void play(const std::string& sound) override {
        std::cout << "Lecture de " << sound << " via ALSA" << std::endl;
    }

    void stop() override {
        std::cout << "Arrêt de la lecture via ALSA" << std::endl;
    }

    void setVolume(float volume) override {
        std::cout << "Volume réglé à " << volume << " via ALSA" << std::endl;
    }
};

// Utilisation dans un moteur de jeu
class GameEngine {
private:
    AudioComponent* audio;

public:
    GameEngine(AudioComponent* audioSystem) : audio(audioSystem) {
        audio->initialize();
    }

    void playSoundEffect(const std::string& effect) {
        audio->play(effect);
    }

    void stopAllSounds() {
        audio->stop();
    }
};

// Le moteur fonctionne avec n'importe quelle implémentation de AudioComponent
#ifdef _WIN32
    GameEngine engine(new WindowsAudio());
#else
    GameEngine engine(new LinuxAudio());
#endif

engine.playSoundEffect("explosion.wav");
```

## 5. Override et Final

### Mot-clé override (C++11)
```cpp
class Base {
public:
    virtual void methode1() { std::cout << "Base::methode1()" << std::endl; }
    virtual void methode2(int x) { std::cout << "Base::methode2(" << x << ")" << std::endl; }
    void methode3() { std::cout << "Base::methode3()" << std::endl; }
};

class Derivee : public Base {
public:
    // Utilisation correcte de override
    void methode1() override { std::cout << "Derivee::methode1()" << std::endl; }

    // Erreur de compilation: signature incorrecte
    // void methode2(double x) override { std::cout << "Derivee::methode2(" << x << ")" << std::endl; }

    // Erreur de compilation: la méthode n'est pas virtuelle dans la classe de base
    // void methode3() override { std::cout << "Derivee::methode3()" << std::endl; }
};

// Avantages de override:
// 1. Prévention des erreurs: détecte les méthodes qui ne redéfinissent pas correctement
// 2. Documentation: indique clairement l'intention de redéfinir
// 3. Maintenance: facilite le repérage des redéfinitions
```

### Mot-clé final (C++11)
```cpp
class Base {
public:
    virtual void methode1() { std::cout << "Base::methode1()" << std::endl; }

    // Méthode qui ne peut plus être redéfinie dans les classes dérivées
    virtual void methode2() final { std::cout << "Base::methode2()" << std::endl; }
};

class Derivee : public Base {
public:
    void methode1() override { std::cout << "Derivee::methode1()" << std::endl; }

    // Erreur de compilation: ne peut pas redéfinir une méthode marquée final
    // void methode2() override { std::cout << "Derivee::methode2()" << std::endl; }
};

// Classe qui ne peut plus être dérivée
class ClasseFinale final {
public:
    void methode() { std::cout << "ClasseFinale::methode()" << std::endl; }
};

// Erreur de compilation: ne peut pas dériver d'une classe marquée final
// class DeriveDeFinale : public ClasseFinale { };

// Avantages de final:
// 1. Sémantique: indique qu'une méthode ne doit plus être redéfinie
// 2. Optimisation: permet au compilateur d'effectuer certaines optimisations
// 3. Sécurité: empêche les redéfinitions non désirées
```

### Prévention des Erreurs de Surcharge/Redéfinition
```cpp
class A {
public:
    void methode(int x) { std::cout << "A::methode(int)" << std::endl; }
};

class B : public A {
public:
    // Masquage: nouvelle méthode qui masque celle de A
    void methode(double x) { std::cout << "B::methode(double)" << std::endl; }
};

// Problème: confusion sur les méthodes disponibles
void probleme() {
    B b;
    b.methode(5);    // Appelle B::methode(double), pas A::methode(int)
    b.methode(5.0);  // Appelle B::methode(double)
    // b.methode(int) est masquée, mais toujours accessible avec:
    b.A::methode(5); // Appel explicite à la méthode de la classe de base
}

// Solution: using declaration pour éviter le masquage
class C : public A {
public:
    // Importe la méthode de A dans l'espace de noms de C
    using A::methode;

    // Surcharge supplémentaire, ne masque pas A::methode(int)
    void methode(double x) { std::cout << "C::methode(double)" << std::endl; }
};

// Maintenant les deux méthodes sont disponibles
void solution() {
    C c;
    c.methode(5);    // Appelle A::methode(int)
    c.methode(5.0);  // Appelle C::methode(double)
}
```

## 6. Composition vs Héritage

### Comparaison des Approches
```cpp
// Approche par héritage: relation "est un"
class Vehicule {
protected:
    std::string marque;
    int annee;

public:
    Vehicule(const std::string& m, int a) : marque(m), annee(a) {}

    void demarrer() {
        std::cout << "Le véhicule démarre" << std::endl;
    }

    void arreter() {
        std::cout << "Le véhicule s'arrête" << std::endl;
    }
};

class Voiture : public Vehicule {
private:
    int nombrePortes;

public:
    Voiture(const std::string& m, int a, int p)
        : Vehicule(m, a), nombrePortes(p) {}

    void klaxonner() {
        std::cout << "La voiture klaxonne" << std::endl;
    }
};

// Approche par composition: relation "a un"
class Moteur {
public:
    void demarrer() {
        std::cout << "Le moteur démarre" << std::endl;
    }

    void arreter() {
        std::cout << "Le moteur s'arrête" << std::endl;
    }
};

class VoitureComposition {
private:
    std::string marque;
    int annee;
    int nombrePortes;
    Moteur moteur;  // Composition: une voiture "a un" moteur

public:
    VoitureComposition(const std::string& m, int a, int p)
        : marque(m), annee(a), nombrePortes(p) {}

    void demarrer() {
        moteur.demarrer();
        std::cout << "La voiture démarre" << std::endl;
    }

    void arreter() {
        moteur.arreter();
        std::cout << "La voiture s'arrête" << std::endl;
    }

    void klaxonner() {
        std::cout << "La voiture klaxonne" << std::endl;
    }
};

// Avantages et inconvénients
/*
Héritage:
+ Réutilisation naturelle du comportement parent
+ Polymorphisme via la classe de base
- Couplage fort entre parent et enfant
- Problèmes avec l'héritage profond

Composition:
+ Couplage plus faible, meilleure encapsulation
+ Plus flexible pour changer l'implémentation
+ Peut combiner plusieurs comportements
- Nécessite plus de code pour déléguer aux composants
- Pas de polymorphisme naturel (besoin d'interfaces)
*/
```

### Design Patterns Associés
```cpp
// Pattern Composite (utilisant l'héritage pour le polymorphisme + composition)
class Component {
public:
    virtual ~Component() = default;

    virtual void operation() = 0;
    virtual void add(Component* component) { throw std::runtime_error("Opération non supportée"); }
    virtual void remove(Component* component) { throw std::runtime_error("Opération non supportée"); }
    virtual Component* getChild(int index) { throw std::runtime_error("Opération non supportée"); }
};

// Leaf (Feuille)
class Leaf : public Component {
private:
    std::string name;

public:
    Leaf(const std::string& n) : name(n) {}

    void operation() override {
        std::cout << "Opération sur la feuille " << name << std::endl;
    }
};

// Composite (utilise la composition)
class Composite : public Component {
private:
    std::string name;
    std::vector<Component*> children;

public:
    Composite(const std::string& n) : name(n) {}

    ~Composite() {
        for (auto child : children) {
            delete child;
        }
    }

    void operation() override {
        std::cout << "Opération sur le composite " << name << std::endl;
        for (auto child : children) {
            child->operation();
        }
    }

    void add(Component* component) override {
        children.push_back(component);
    }

    void remove(Component* component) override {
        // Code pour supprimer un composant
    }

    Component* getChild(int index) override {
        return children[index];
    }
};

// Pattern Decorator (combinant héritage et composition)
class Component {
public:
    virtual ~Component() = default;
    virtual void operation() = 0;
};

class ConcreteComponent : public Component {
public:
    void operation() override {
        std::cout << "Opération du composant concret" << std::endl;
    }
};

class Decorator : public Component {
protected:
    Component* component;  // Composition

public:
    Decorator(Component* c) : component(c) {}

    virtual void operation() override {
        component->operation();
    }
};

class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(Component* c) : Decorator(c) {}

    void operation() override {
        Decorator::operation();
        additionalOperation();
    }

private:
    void additionalOperation() {
        std::cout << "Opération supplémentaire du décorateur A" << std::endl;
    }
};
```

### Principes SOLID Appliqués
```cpp
// Principe de Substitution de Liskov (LSP)
class Rectangle {
protected:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    virtual void setWidth(double w) { width = w; }
    virtual void setHeight(double h) { height = h; }

    double getWidth() const { return width; }
    double getHeight() const { return height; }

    double area() const { return width * height; }
};

// Violation du LSP
class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side) {}

    // Un carré doit maintenir width == height
    void setWidth(double w) override {
        width = w;
        height = w;  // Change aussi la hauteur
    }

    void setHeight(double h) override {
        width = h;   // Change aussi la largeur
        height = h;
    }
};

// Problème avec LSP
void testRectangle(Rectangle& r) {
    r.setWidth(5);
    r.setHeight(4);
    assert(r.area() == 20);  // Échoue si r est un Square
}

// Meilleure solution: composition au lieu d'héritage
class Shape {
public:
    virtual ~Shape() = default;
    virtual double area() const = 0;
};

class Rectangle2 : public Shape {
private:
    double width;
    double height;

public:
    Rectangle2(double w, double h) : width(w), height(h) {}

    void setWidth(double w) { width = w; }
    void setHeight(double h) { height = h; }

    double getWidth() const { return width; }
    double getHeight() const { return height; }

    double area() const override { return width * height; }
};

class Square2 : public Shape {
private:
    double side;

public:
    Square2(double s) : side(s) {}

    void setSide(double s) { side = s; }
    double getSide() const { return side; }

    double area() const override { return side * side; }
};
```

## Conclusion

L'héritage et le polymorphisme sont des concepts fondamentaux en programmation orientée objet qui permettent de créer des hiérarchies de classes flexibles et extensibles. L'héritage permet la réutilisation du code et l'établissement de relations "est un", tandis que le polymorphisme permet à des objets de différentes classes d'être traités de manière uniforme à travers une interface commune.

Les fonctions virtuelles, les classes abstraites et les interfaces sont des outils puissants pour concevoir des systèmes modulaires et extensibles. Cependant, il est important de comprendre les compromis entre l'héritage et la composition, et de choisir l'approche la plus adaptée à chaque situation.

Dans le développement de jeux, ces concepts sont particulièrement utiles pour créer des systèmes d'entités, des hiérarchies d'objets de jeu, et des frameworks extensibles qui peuvent évoluer avec les besoins du projet.

## Ressources Complémentaires

- [C++ Reference: Inheritance](https://en.cppreference.com/w/cpp/language/derived_class) - Documentation officielle
- [C++ Reference: Virtual Functions](https://en.cppreference.com/w/cpp/language/virtual) - Documentation officielle
- [Design Patterns en C++](https://refactoring.guru/design-patterns/cpp) - Patterns de conception utilisant l'héritage et la composition
- [Game Programming Patterns](http://gameprogrammingpatterns.com/) par Bob Nystrom
- [Effective C++](https://www.amazon.com/Effective-Specific-Improve-Programs-Designs/dp/0321334876) par Scott Meyers - Contient d'excellents conseils sur l'héritage et le polymorphisme
