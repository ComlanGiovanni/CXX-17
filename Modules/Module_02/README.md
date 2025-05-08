# Module 2: POO Fondamentale

Ce module couvre les principes fondamentaux de la Programmation Orientée Objet (POO) en C++, vous permettant de structurer votre code de manière modulaire et réutilisable.

## 1. Classes et Objets

### Définition d'une Classe
```cpp
// Déclaration d'une classe
class Personne {
public:
    // Attributs (données membres)
    std::string nom;
    int age;

    // Méthodes (fonctions membres)
    void afficher() {
        std::cout << "Nom: " << nom << ", Age: " << age << " ans" << std::endl;
    }

    void vieillir(int annees) {
        age += annees;
    }
};

// Utilisation de la classe
int main() {
    // Création d'un objet (instance de la classe)
    Personne p1;

    // Accès aux attributs
    p1.nom = "Alice";
    p1.age = 30;

    // Appel de méthodes
    p1.afficher();  // Affiche: Nom: Alice, Age: 30 ans
    p1.vieillir(1);
    p1.afficher();  // Affiche: Nom: Alice, Age: 31 ans

    return 0;
}
```

### Différence entre Classe et Structure
```cpp
// Structure : membres publics par défaut
struct Point {
    double x;  // public par défaut
    double y;  // public par défaut
};

// Classe : membres privés par défaut
class Cercle {
private:  // explicite mais facultatif (privé par défaut)
    double rayon;
    Point centre;

public:
    // Méthodes pour accéder aux membres privés
    void setRayon(double r) {
        if (r >= 0) {  // Validation possible
            rayon = r;
        }
    }

    double getRayon() const {
        return rayon;
    }
};
```

### Création et Manipulation d'Objets
```cpp
// Création d'objets
Personne p1;           // Sur la pile
Personne* p2 = new Personne();  // Sur le tas (heap)

// Manipulation
p1.nom = "Bob";
p2->nom = "Charlie";   // Opérateur flèche pour les pointeurs

// N'oubliez pas de libérer la mémoire
delete p2;
```

## 2. Encapsulation et Accesseurs

### Principe et Mise en Œuvre
```cpp
class CompteBancaire {
private:
    // Données encapsulées (non accessibles directement)
    std::string proprietaire;
    double solde;
    int numeroCompte;

public:
    // Accesseurs (getters) - donnent un accès en lecture
    std::string getProprietaire() const {
        return proprietaire;
    }

    double getSolde() const {
        return solde;
    }

    int getNumeroCompte() const {
        return numeroCompte;
    }

    // Mutateurs (setters) - permettent la modification contrôlée
    void setProprietaire(const std::string& nom) {
        proprietaire = nom;
    }

    // Pas de setter pour numeroCompte (non modifiable)

    // Méthodes métier qui modifient l'état de façon contrôlée
    bool deposer(double montant) {
        if (montant > 0) {
            solde += montant;
            return true;
        }
        return false;
    }

    bool retirer(double montant) {
        if (montant > 0 && solde >= montant) {
            solde -= montant;
            return true;
        }
        return false;
    }
};

// Utilisation
CompteBancaire compte;
compte.setProprietaire("Alice");
compte.deposer(1000);
compte.retirer(200);
std::cout << "Solde: " << compte.getSolde() << std::endl;  // 800
```

### Avantages de l'Encapsulation
- **Contrôle d'accès**: Validation des données avant modification
- **Flexibilité**: L'implémentation interne peut changer sans affecter le code client
- **Maintenance**: Les dépendances sont limitées à l'interface publique
- **Débogage**: Les problèmes sont isolés dans des unités plus petites

## 3. Constructeurs et Destructeurs

### Types de Constructeurs
```cpp
class Rectangle {
private:
    double longueur;
    double largeur;

public:
    // Constructeur par défaut
    Rectangle() {
        longueur = 0.0;
        largeur = 0.0;
        std::cout << "Constructeur par défaut appelé" << std::endl;
    }

    // Constructeur avec paramètres
    Rectangle(double l, double L) {
        longueur = l;
        largeur = L;
        std::cout << "Constructeur paramétré appelé" << std::endl;
    }

    // Constructeur de copie
    Rectangle(const Rectangle& autre) {
        longueur = autre.longueur;
        largeur = autre.largeur;
        std::cout << "Constructeur de copie appelé" << std::endl;
    }

    // Destructeur
    ~Rectangle() {
        std::cout << "Destructeur appelé" << std::endl;
    }

    // Méthodes
    double aire() const {
        return longueur * largeur;
    }
};

// Utilisation
void test() {
    Rectangle r1;                 // Constructeur par défaut
    Rectangle r2(5.0, 3.0);       // Constructeur paramétré
    Rectangle r3 = r2;            // Constructeur de copie

    std::cout << "Aire de r2: " << r2.aire() << std::endl;  // 15.0

    // Destructeurs appelés automatiquement à la fin de la portée
}  // Les destructeurs de r1, r2 et r3 sont appelés ici
```

### Liste d'Initialisation
```cpp
class Personne {
private:
    std::string nom;
    int age;
    const int anneeNaissance;  // Membre constant, doit être initialisé

public:
    // Mauvaise approche: initialisation dans le corps
    Personne(const std::string& n, int a, int an) {
        nom = n;      // Assignation, pas initialisation
        age = a;      // Assignation, pas initialisation
        // anneeNaissance = an;  // ERREUR: membre constant non modifiable
    }

    // Bonne approche: liste d'initialisation
    Personne(const std::string& n, int a, int an)
        : nom(n),                // Initialisation, plus efficace
          age(a),                // Initialisation, plus efficace
          anneeNaissance(an)     // Initialisation d'un membre constant
    {
        // Corps du constructeur (généralement vide ou avec des validations)
    }
};
```

### Constructeur Délégué (C++11)
```cpp
class Cercle {
private:
    double rayon;
    std::string couleur;

public:
    // Constructeur principal
    Cercle(double r, const std::string& c) : rayon(r), couleur(c) {
        std::cout << "Constructeur principal" << std::endl;
    }

    // Constructeur délégué qui appelle le constructeur principal
    Cercle() : Cercle(1.0, "noir") {
        std::cout << "Constructeur délégué" << std::endl;
    }

    // Autre constructeur délégué
    explicit Cercle(double r) : Cercle(r, "noir") {
        std::cout << "Constructeur avec rayon uniquement" << std::endl;
    }
};
```

### Destructeurs et Gestion de Ressources
```cpp
class GestionnaireRessource {
private:
    int* donnees;

public:
    GestionnaireRessource(int taille) {
        donnees = new int[taille];
        std::cout << "Ressource allouée" << std::endl;
    }

    // Destructeur: nettoie les ressources
    ~GestionnaireRessource() {
        delete[] donnees;
        std::cout << "Ressource libérée" << std::endl;
    }
};

// Utilisation
void fonction() {
    GestionnaireRessource res(100);
    // Utilisation de res...
    // Pas besoin de libérer explicitement
}  // Le destructeur est appelé automatiquement ici
```

## 4. Membres Statiques

### Variables Statiques de Classe
```cpp
class Compteur {
private:
    static int nombreInstances;  // Déclaration (partagée entre toutes les instances)
    int id;

public:
    Compteur() : id(++nombreInstances) {
        std::cout << "Nouvelle instance créée, ID: " << id << std::endl;
    }

    ~Compteur() {
        std::cout << "Instance détruite, ID: " << id << std::endl;
        nombreInstances--;
    }

    static int getNombreInstances() {
        return nombreInstances;
    }

    int getId() const {
        return id;
    }
};

// Définition (obligatoire) de la variable statique en dehors de la classe
int Compteur::nombreInstances = 0;

// Utilisation
int main() {
    std::cout << "Nombre initial: " << Compteur::getNombreInstances() << std::endl;  // 0

    Compteur c1;
    Compteur c2;

    std::cout << "Après création: " << Compteur::getNombreInstances() << std::endl;  // 2

    {
        Compteur c3;
        std::cout << "Bloc interne: " << Compteur::getNombreInstances() << std::endl;  // 3
    }  // c3 est détruit ici

    std::cout << "Après bloc: " << Compteur::getNombreInstances() << std::endl;  // 2

    return 0;
}  // c1 et c2 sont détruits ici
```

### Méthodes Statiques
```cpp
class Math {
public:
    // Méthode statique (sans accès aux membres non-statiques)
    static double carre(double x) {
        return x * x;
    }

    static double racineCarree(double x) {
        return std::sqrt(x);
    }

    // Constante statique
    static constexpr double PI = 3.14159265358979323846;
};

// Utilisation
double aire = Math::PI * Math::carre(5.0);
double racine = Math::racineCarree(16.0);  // 4.0
```

### Avantages et Utilisation
- Variables partagées entre toutes les instances
- Compteurs globaux, paramètres de configuration
- Méthodes utilitaires qui n'ont pas besoin d'état d'instance
- Implémentation du pattern Singleton

## 5. L'Opérateur This

### Comprendre le Pointeur This
```cpp
class Rectangle {
private:
    double longueur;
    double largeur;

public:
    Rectangle(double longueur, double largeur) {
        // Ambiguïté: paramètre et membre ont le même nom
        // this->longueur fait référence au membre de la classe
        this->longueur = longueur;
        this->largeur = largeur;
    }

    // Alternative avec liste d'initialisation (préférée)
    // Rectangle(double longueur, double largeur)
    //     : longueur(longueur), largeur(largeur) {}

    void afficher() const {
        std::cout << "Rectangle: " << this->longueur << " x " << this->largeur << std::endl;
    }

    // this est implicite dans toutes les méthodes non-statiques
    double aire() const {
        return longueur * largeur;  // this->longueur * this->largeur implicite
    }
};
```

### Retourner l'Objet Courant
```cpp
class Chaine {
private:
    std::string texte;

public:
    Chaine(const std::string& t) : texte(t) {}

    // Retourne une référence à l'objet courant pour permettre le chaînage
    Chaine& ajouter(const std::string& t) {
        texte += t;
        return *this;  // Retourne l'objet courant (déréférencé)
    }

    Chaine& mettreEnMajuscules() {
        for (char& c : texte) {
            c = std::toupper(c);
        }
        return *this;
    }

    const std::string& getTexte() const {
        return texte;
    }
};

// Utilisation avec chaînage d'appels
Chaine message("bonjour");
message.ajouter(" tout").ajouter(" le").ajouter(" monde").mettreEnMajuscules();
std::cout << message.getTexte() << std::endl;  // "BONJOUR TOUT LE MONDE"
```

## 6. Surcharge d'Opérateurs

### Opérateurs Membres vs Non-Membres
```cpp
class Vecteur2D {
private:
    double x, y;

public:
    Vecteur2D(double x = 0, double y = 0) : x(x), y(y) {}

    // Accesseurs
    double getX() const { return x; }
    double getY() const { return y; }

    // Opérateur membre (v1 + v2)
    Vecteur2D operator+(const Vecteur2D& autre) const {
        return Vecteur2D(x + autre.x, y + autre.y);
    }

    // Opérateur membre d'incrémentation préfixe (++v)
    Vecteur2D& operator++() {
        ++x;
        ++y;
        return *this;
    }

    // Opérateur membre d'incrémentation postfixe (v++)
    Vecteur2D operator++(int) {
        Vecteur2D temp(*this);
        ++(*this);  // Utilise l'opérateur préfixe
        return temp;
    }

    // Opérateur d'indexation
    double& operator[](int index) {
        if (index == 0) return x;
        if (index == 1) return y;
        throw std::out_of_range("Index hors limites");
    }

    // Opérateur de conversion (cast)
    explicit operator double() const {
        return std::sqrt(x*x + y*y);  // Norme du vecteur
    }
};

// Opérateur non-membre (pour la multiplication par un scalaire)
Vecteur2D operator*(double scalaire, const Vecteur2D& vecteur) {
    return Vecteur2D(scalaire * vecteur.getX(), scalaire * vecteur.getY());
}

// Opérateur non-membre de sortie
std::ostream& operator<<(std::ostream& os, const Vecteur2D& vecteur) {
    os << "(" << vecteur.getX() << ", " << vecteur.getY() << ")";
    return os;
}

// Utilisation
Vecteur2D v1(1, 2);
Vecteur2D v2(3, 4);
Vecteur2D v3 = v1 + v2;  // (4, 6)
Vecteur2D v4 = 2.5 * v1;  // (2.5, 5)
std::cout << v3 << std::endl;  // "(4, 6)"
double norme = static_cast<double>(v2);  // 5.0
```

### Opérateurs Couramment Surchargés
- **Arithmétiques**: `+`, `-`, `*`, `/`, `%`
- **Affectation**: `=`, `+=`, `-=`, `*=`, `/=`
- **Comparaison**: `==`, `!=`, `<`, `>`, `<=`, `>=`
- **Indexation**: `[]`
- **Appel de fonction**: `()`
- **Incrémentation/Décrémentation**: `++`, `--`
- **Entrée/Sortie**: `<<`, `>>`
- **Dereferencing**: `*`, `->`
- **Allocation mémoire**: `new`, `delete`

### Bonnes Pratiques
```cpp
class Nombre {
private:
    int valeur;

public:
    Nombre(int v = 0) : valeur(v) {}

    // Opérateur += membre (modifie l'objet)
    Nombre& operator+=(const Nombre& autre) {
        valeur += autre.valeur;
        return *this;
    }

    // Opérateur + non-membre (retourne un nouvel objet)
    // Défini en termes de +=
    friend Nombre operator+(Nombre gauche, const Nombre& droite) {
        gauche += droite;  // Utilise l'opérateur += déjà défini
        return gauche;
    }

    // Opérateurs de comparaison (C++20 préfère l'opérateur <=>)
    bool operator==(const Nombre& autre) const {
        return valeur == autre.valeur;
    }

    bool operator<(const Nombre& autre) const {
        return valeur < autre.valeur;
    }

    // Autres opérateurs de comparaison peuvent être dérivés
    bool operator!=(const Nombre& autre) const {
        return !(*this == autre);
    }

    // ...
};
```

## 7. Héritage Simple

### Concepts de Base
```cpp
// Classe de base (ou classe parente)
class Forme {
protected:  // Accessible par les classes dérivées, mais pas de l'extérieur
    double x, y;  // Position

public:
    Forme(double x = 0, double y = 0) : x(x), y(y) {}

    // Destructeur virtuel (important pour l'héritage)
    virtual ~Forme() {
        std::cout << "Destructeur de Forme appelé" << std::endl;
    }

    void deplacer(double dx, double dy) {
        x += dx;
        y += dy;
    }

    // Méthode virtuelle (peut être redéfinie par les classes dérivées)
    virtual double aire() const {
        return 0.0;  // Par défaut, une forme abstraite n'a pas d'aire
    }

    virtual void afficher() const {
        std::cout << "Forme à la position (" << x << ", " << y << ")" << std::endl;
    }
};

// Classe dérivée (ou classe enfant)
class Rectangle : public Forme {
private:
    double largeur, hauteur;

public:
    Rectangle(double x = 0, double y = 0, double l = 0, double h = 0)
        : Forme(x, y), largeur(l), hauteur(h) {}

    ~Rectangle() {
        std::cout << "Destructeur de Rectangle appelé" << std::endl;
    }

    // Redéfinition de la méthode virtuelle
    double aire() const override {
        return largeur * hauteur;
    }

    void afficher() const override {
        std::cout << "Rectangle à la position (" << x << ", " << y << ") "
                  << "de dimensions " << largeur << " x " << hauteur
                  << " (aire: " << aire() << ")" << std::endl;
    }
};

// Autre classe dérivée
class Cercle : public Forme {
private:
    double rayon;

public:
    Cercle(double x = 0, double y = 0, double r = 0)
        : Forme(x, y), rayon(r) {}

    ~Cercle() {
        std::cout << "Destructeur de Cercle appelé" << std::endl;
    }

    double aire() const override {
        return 3.14159 * rayon * rayon;
    }

    void afficher() const override {
        std::cout << "Cercle à la position (" << x << ", " << y << ") "
                  << "de rayon " << rayon
                  << " (aire: " << aire() << ")" << std::endl;
    }
};
```

### Utilisation du Polymorphisme
```cpp
void afficherForme(const Forme& forme) {
    forme.afficher();  // Appelle la méthode appropriée selon le type réel
}

int main() {
    Rectangle rect(1, 2, 5, 3);
    Cercle cercle(4, 5, 2);

    // Appels directs
    rect.afficher();
    cercle.afficher();

    // Polymorphisme
    afficherForme(rect);    // Appelle Rectangle::afficher()
    afficherForme(cercle);  // Appelle Cercle::afficher()

    // Tableau polymorphique
    Forme* formes[2];
    formes[0] = new Rectangle(0, 0, 4, 2);
    formes[1] = new Cercle(3, 3, 3);

    for (int i = 0; i < 2; i++) {
        formes[i]->afficher();  // Appelle la méthode appropriée
        std::cout << "Aire: " << formes[i]->aire() << std::endl;
    }

    // Nettoyage (important!)
    for (int i = 0; i < 2; i++) {
        delete formes[i];  // Appelle le destructeur approprié grâce au destructeur virtuel
    }

    return 0;
}
```

### Modificateurs d'Accès dans l'Héritage
```cpp
class Base {
public:
    int publicMembre;
protected:
    int protectedMembre;
private:
    int privateMembre;
};

// Héritage public: conserve la visibilité d'origine
class DerivePublic : public Base {
    void test() {
        publicMembre = 1;      // OK: public reste public
        protectedMembre = 2;   // OK: protected reste protected
        // privateMembre = 3;  // Erreur: private n'est pas accessible
    }
};

// Héritage protected: public devient protected
class DeriveProtected : protected Base {
    void test() {
        publicMembre = 1;      // OK: public devient protected
        protectedMembre = 2;   // OK: protected reste protected
        // privateMembre = 3;  // Erreur: private n'est pas accessible
    }
};

// Héritage private: public et protected deviennent private
class DerivePrivate : private Base {
    void test() {
        publicMembre = 1;      // OK: public devient private
        protectedMembre = 2;   // OK: protected devient private
        // privateMembre = 3;  // Erreur: private n'est pas accessible
    }
};

// Utilisation
void fonction() {
    DerivePublic dp;
    dp.publicMembre = 1;      // OK: public
    // dp.protectedMembre = 2;  // Erreur: protected
    // dp.privateMembre = 3;    // Erreur: private

    DeriveProtected dpr;
    // dpr.publicMembre = 1;    // Erreur: devenu protected
    // dpr.protectedMembre = 2; // Erreur: protected
    // dpr.privateMembre = 3;   // Erreur: private

    DerivePrivate dpriv;
    // dpriv.publicMembre = 1;   // Erreur: devenu private
    // dpriv.protectedMembre = 2;// Erreur: devenu private
    // dpriv.privateMembre = 3;  // Erreur: private
}
```

## 8. Polymorphisme et Fonctions Virtuelles

### Mécanisme des Fonctions Virtuelles
```cpp
class Animal {
public:
    virtual ~Animal() {}

    // Méthode virtuelle: peut être redéfinie
    virtual void emettreSon() const {
        std::cout << "..." << std::endl;
    }

    // Méthode non-virtuelle: ne peut pas être redéfinie polymorphiquement
    void manger() const {
        std::cout << "L'animal mange" << std::endl;
    }
};

class Chat : public Animal {
public:
    // Redéfinition (override)
    void emettreSon() const override {
        std::cout << "Miaou!" << std::endl;
    }

    // Masquage (hiding), pas de polymorphisme
    void manger() const {
        std::cout << "Le chat mange des croquettes" << std::endl;
    }
};

void faireCommuniquer(const Animal& animal) {
    animal.emettreSon();  // Polymorphique: appelle la méthode de la classe dérivée
    animal.manger();      // Non polymorphique: appelle toujours Animal::manger()
}

// Utilisation
Chat chat;
chat.emettreSon();  // "Miaou!"
chat.manger();      // "Le chat mange des croquettes"

Animal& ref = chat;
ref.emettreSon();   // "Miaou!" (polymorphisme)
ref.manger();       // "L'animal mange" (pas de polymorphisme)

faireCommuniquer(chat);  // "Miaou!" puis "L'animal mange"
```

### Fonctions Virtuelles Pures et Classes Abstraites
```cpp
// Classe abstraite (contient au moins une méthode virtuelle pure)
class FormeAbstraite {
protected:
    double x, y;

public:
    FormeAbstraite(double x = 0, double y = 0) : x(x), y(y) {}
    virtual ~FormeAbstraite() {}

    // Méthode virtuelle pure (déclarée = 0)
    virtual double aire() const = 0;

    // Méthode virtuelle pure
    virtual void dessiner() const = 0;

    // Méthode normale
    void deplacer(double dx, double dy) {
        x += dx;
        y += dy;
    }
};

// Classe concrète qui implémente la classe abstraite
class CarreConcret : public FormeAbstraite {
private:
    double cote;

public:
    CarreConcret(double x, double y, double c)
        : FormeAbstraite(x, y), cote(c) {}

    // Implémentation des méthodes virtuelles pures
    double aire() const override {
        return cote * cote;
    }

    void dessiner() const override {
        std::cout << "Dessin d'un carré de côté " << cote
                  << " à la position (" << x << ", " << y << ")" << std::endl;
    }
};

// Utilisation
// FormeAbstraite forme;  // Erreur: ne peut pas instancier une classe abstraite
CarreConcret carre(1, 1, 5);
carre.dessiner();  // OK

FormeAbstraite* forme = new CarreConcret(2, 3, 4);  // OK: pointer vers une classe concrète
forme->dessiner();  // Appelle CarreConcret::dessiner()
delete forme;
```

### Mot-clé override et Bonnes Pratiques
```cpp
class Base {
public:
    virtual void methode1() { std::cout << "Base::methode1" << std::endl; }
    virtual void methode2() const { std::cout << "Base::methode2" << std::endl; }
    void methode3() { std::cout << "Base::methode3" << std::endl; }
};

class Derive : public Base {
public:
    // Correct: redéfinit bien une méthode virtuelle
    void methode1() override { std::cout << "Derive::methode1" << std::endl; }

    // Erreur de signature: const manquant
    // void methode2() override { std::cout << "Derive::methode2" << std::endl; }

    // Correct: correspond exactement à la signature
    void methode2() const override { std::cout << "Derive::methode2" << std::endl; }

    // Pas d'override car la méthode n'est pas virtuelle dans Base
    // void methode3() override { std::cout << "Derive::methode3" << std::endl; }
};
```

## 9. Classes Abstraites et Interfaces

### Interfaces en C++
```cpp
// Interface (classe abstraite pure)
class Dessinable {
public:
    virtual ~Dessinable() {}

    // Méthodes virtuelles pures définissant l'interface
    virtual void dessiner() const = 0;
    virtual void redimensionner(double facteur) = 0;
};

// Autre interface
class Sauvegardable {
public:
    virtual ~Sauvegardable() {}

    virtual void sauvegarder(const std::string& nomFichier) const = 0;
    virtual void charger(const std::string& nomFichier) = 0;
};

// Classe qui implémente les deux interfaces
class Image : public Dessinable, public Sauvegardable {
private:
    std::string fichier;
    double largeur, hauteur;

public:
    Image(const std::string& f, double l, double h)
        : fichier(f), largeur(l), hauteur(h) {}

    // Implémentation de Dessinable
    void dessiner() const override {
        std::cout << "Dessin de l'image " << fichier
                  << " (" << largeur << "x" << hauteur << ")" << std::endl;
    }

    void redimensionner(double facteur) override {
        largeur *= facteur;
        hauteur *= facteur;
    }

    // Implémentation de Sauvegardable
    void sauvegarder(const std::string& nomFichier) const override {
        std::cout << "Sauvegarde de l'image dans " << nomFichier << std::endl;
    }

    void charger(const std::string& nomFichier) override {
        fichier = nomFichier;
        std::cout << "Chargement de l'image depuis " << nomFichier << std::endl;
    }
};

// Utilisation polymorphique
void afficher(const Dessinable& objet) {
    objet.dessiner();
}

void archiver(const Sauvegardable& objet) {
    objet.sauvegarder("archive.dat");
}

// Test
Image img("photo.jpg", 800, 600);
afficher(img);  // Utilise l'interface Dessinable
archiver(img);  // Utilise l'interface Sauvegardable
```

### Interfaces vs Classes Abstraites
```cpp
// Interface pure (seulement des méthodes virtuelles pures)
class Serialisable {
public:
    virtual ~Serialisable() {}
    virtual std::string toJson() const = 0;
    virtual void fromJson(const std::string& json) = 0;
};

// Classe abstraite (combine méthodes virtuelles pures et implémentations)
class Document {
protected:
    std::string titre;
    std::string auteur;

public:
    Document(const std::string& t, const std::string& a)
        : titre(t), auteur(a) {}

    virtual ~Document() {}

    // Méthodes concrètes
    std::string getTitre() const { return titre; }
    std::string getAuteur() const { return auteur; }

    void setTitre(const std::string& t) { titre = t; }
    void setAuteur(const std::string& a) { auteur = a; }

    // Méthode concrète qui utilise une méthode virtuelle (Template Method pattern)
    void imprimer() const {
        std::cout << "Document: " << titre << " par " << auteur << std::endl;
        imprimerContenu();  // Appelle la version spécifique
    }

    // Méthode virtuelle pure à implémenter par les classes dérivées
    virtual void imprimerContenu() const = 0;
};

// Classe concrète qui hérite d'une classe abstraite et d'une interface
class Rapport : public Document, public Serialisable {
private:
    std::string contenu;
    std::string departement;

public:
    Rapport(const std::string& titre, const std::string& auteur,
            const std::string& dept, const std::string& cont)
        : Document(titre, auteur), departement(dept), contenu(cont) {}

    // Implémentation de Document::imprimerContenu
    void imprimerContenu() const override {
        std::cout << "Rapport du département " << departement << std::endl;
        std::cout << "Contenu: " << contenu << std::endl;
    }

    // Implémentation de l'interface Serialisable
    std::string toJson() const override {
        return "{\"titre\":\"" + titre +
               "\",\"auteur\":\"" + auteur +
               "\",\"departement\":\"" + departement +
               "\",\"contenu\":\"" + contenu + "\"}";
    }

    void fromJson(const std::string& json) override {
        // Implémentation simplifiée
        std::cout << "Chargement du rapport depuis JSON" << std::endl;
    }
};
```

## Conclusion

Ce module vous a présenté les fondamentaux de la programmation orientée objet en C++. Vous avez appris à créer des classes, à encapsuler vos données, à utiliser des constructeurs et destructeurs, à exploiter les membres statiques, à surcharger des opérateurs, et à utiliser l'héritage, le polymorphisme et les interfaces.

Ces concepts constituent le cœur de la POO et vous permettront de structurer votre code de manière modulaire, réutilisable et maintenable. Ils forment la base nécessaire avant d'explorer les aspects plus avancés de la POO que nous aborderons dans le prochain module.

## Ressources Complémentaires

- [C++ Reference: Classes](https://en.cppreference.com/w/cpp/language/classes) - Documentation officielle
- [Principes SOLID](https://en.wikipedia.org/wiki/SOLID) - Principes de conception orientée objet
- [Design Patterns en C++](https://refactoring.guru/design-patterns/cpp) - Patterns de conception courants
- [Effective C++](https://www.amazon.com/Effective-Specific-Improve-Programs-Designs/dp/0321334876) par Scott Meyers
