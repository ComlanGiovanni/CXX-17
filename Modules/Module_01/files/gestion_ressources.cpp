/*
 * Exercice 7.3: Gestion Automatique de Ressources
 *
 * Ce programme démontre comment les objets à portée automatique gèrent
 * leurs ressources via les constructeurs et destructeurs (RAII).
 */

#include <iostream>
#include <string>
#include <memory>
#include <vector>

// Classe qui simule une ressource
class Ressource {
private:
    std::string nom;
    int taille;

public:
    // Constructeur - acquiert la ressource
    Ressource(const std::string& n, int t) : nom(n), taille(t) {
        std::cout << "Acquisition de la ressource '" << nom << "' (" << taille << " octets)" << std::endl;
    }

    // Destructeur - libère la ressource
    ~Ressource() {
        std::cout << "Libération de la ressource '" << nom << "'" << std::endl;
    }

    // Accesseurs
    std::string getNom() const { return nom; }
    int getTaille() const { return taille; }
};

// Classe gestionnaire qui utilise la ressource
class GestionnaireRessource {
private:
    Ressource* ressource;  // Pointeur vers la ressource

public:
    // Constructeur - acquiert la ressource dynamiquement
    GestionnaireRessource(const std::string& nom, int taille) {
        std::cout << "Création du gestionnaire..." << std::endl;
        ressource = new Ressource(nom, taille);
    }

    // Destructeur - libère la ressource
    ~GestionnaireRessource() {
        std::cout << "Destruction du gestionnaire..." << std::endl;
        delete ressource;  // Libération de la ressource
    }

    // Interdit la copie pour éviter les doubles suppressions
    GestionnaireRessource(const GestionnaireRessource&) = delete;
    GestionnaireRessource& operator=(const GestionnaireRessource&) = delete;

    // Accesseur à la ressource
    const Ressource* getRessource() const { return ressource; }
};

// Démonstration sans gestion automatique - risque de fuites
void demoSansGestionAutomatique(bool provoquerFuite) {
    std::cout << "\n--- Démonstration sans gestion automatique ---" << std::endl;

    // Allocation de ressource
    Ressource* res = new Ressource("Ressource non gérée", 1024);

    // Traitement qui peut lever une exception ou avoir des branches de retour multiples
    std::cout << "Utilisation de la ressource '" << res->getNom() << "'" << std::endl;

    if (provoquerFuite) {
        std::cout << "!!! Oups, on quitte la fonction sans libérer la ressource !!!" << std::endl;
        return;  // Fuite mémoire! La ressource n'est jamais libérée
    }

    // Libération manuelle (n'est exécutée que si provoquerFuite est false)
    delete res;
    std::cout << "Ressource libérée manuellement" << std::endl;
}

// Démonstration avec gestion automatique via RAII
void demoAvecGestionAutomatique(bool simulerException) {
    std::cout << "\n--- Démonstration avec gestion automatique (RAII) ---" << std::endl;

    try {
        // Création d'un objet avec durée de vie automatique
        GestionnaireRessource gestionnaire("Ressource gérée", 2048);

        // Utilisation de la ressource
        std::cout << "Utilisation de la ressource '"
                  << gestionnaire.getRessource()->getNom() << "'" << std::endl;

        if (simulerException) {
            std::cout << "Simulation d'une exception..." << std::endl;
            throw std::runtime_error("Exception simulée!");
        }

        std::cout << "Traitement normal terminé" << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Exception attrapée: " << e.what() << std::endl;
    }

    // La ressource est automatiquement libérée ici, que l'exception soit levée ou non
    std::cout << "Fin de la fonction - la ressource a été libérée automatiquement" << std::endl;
}

// Démonstration avec smart pointers (approche moderne)
void demoAvecSmartPointers() {
    std::cout << "\n--- Démonstration avec smart pointers ---" << std::endl;

    // unique_ptr - propriété exclusive
    {
        std::cout << "Bloc avec unique_ptr:" << std::endl;
        std::unique_ptr<Ressource> ressUniquePtr =
            std::make_unique<Ressource>("Ressource unique_ptr", 512);

        std::cout << "Utilisation de la ressource unique: "
                  << ressUniquePtr->getNom() << std::endl;

        // Pas besoin de delete - le unique_ptr s'en charge automatiquement
    }
    std::cout << "Fin du bloc - unique_ptr a libéré la ressource" << std::endl;

    // shared_ptr - propriété partagée
    std::cout << "\nDémonstration de shared_ptr:" << std::endl;

    std::shared_ptr<Ressource> ressSharedPtr1 =
        std::make_shared<Ressource>("Ressource shared_ptr", 1024);

    {
        std::cout << "Entrée dans un sous-bloc" << std::endl;
        std::shared_ptr<Ressource> ressSharedPtr2 = ressSharedPtr1;  // Partage la ressource
        std::cout << "Nombre de références: " << ressSharedPtr1.use_count() << std::endl;

        std::cout << "Utilisation des deux pointeurs partagés:" << std::endl;
        std::cout << "Via ptr1: " << ressSharedPtr1->getNom() << std::endl;
        std::cout << "Via ptr2: " << ressSharedPtr2->getNom() << std::endl;
    }

    std::cout << "Après le sous-bloc - ressSharedPtr2 est détruit" << std::endl;
    std::cout << "Nombre de références restant: " << ressSharedPtr1.use_count() << std::endl;

    // La ressource sera libérée quand le dernier shared_ptr sera détruit
}

// Classe qui implémente le modèle RAII pour un tableau dynamique
template<typename T>
class TableauAutomatique {
private:
    T* donnees;
    size_t taille;

public:
    // Constructeur - alloue la ressource
    explicit TableauAutomatique(size_t n) : taille(n) {
        std::cout << "Allocation d'un tableau de " << taille << " éléments" << std::endl;
        donnees = new T[taille]();  // Allocation et initialisation
    }

    // Destructeur - libère la ressource
    ~TableauAutomatique() {
        std::cout << "Libération du tableau de " << taille << " éléments" << std::endl;
        delete[] donnees;
    }

    // Interdire la copie (pour simplifier)
    TableauAutomatique(const TableauAutomatique&) = delete;
    TableauAutomatique& operator=(const TableauAutomatique&) = delete;

    // Opérateur d'accès
    T& operator[](size_t index) {
        if (index >= taille) {
            throw std::out_of_range("Index hors limites");
        }
        return donnees[index];
    }

    // Taille du tableau
    size_t getTaille() const { return taille; }
};

int main() {
    std::cout << "=== Gestion Automatique de Ressources (RAII) ===" << std::endl;

    // Démonstration sans RAII (potentielle fuite mémoire)
    demoSansGestionAutomatique(true);

    // Démonstration avec RAII
    demoAvecGestionAutomatique(false);  // Exécution normale
    demoAvecGestionAutomatique(true);   // Avec exception

    // Démonstration avec smart pointers
    demoAvecSmartPointers();

    // Démonstration de la classe personnalisée RAII
    std::cout << "\n--- Démonstration de TableauAutomatique ---" << std::endl;

    try {
        TableauAutomatique<int> tableau(5);

        // Initialiser les valeurs
        for (size_t i = 0; i < tableau.getTaille(); ++i) {
            tableau[i] = i * 10;
        }

        // Afficher les valeurs
        std::cout << "Contenu du tableau: ";
        for (size_t i = 0; i < tableau.getTaille(); ++i) {
            std::cout << tableau[i] << " ";
        }
        std::cout << std::endl;

        // Provoquer une exception
        std::cout << "Tentative d'accès hors limites..." << std::endl;
        tableau[10] = 100;  // Provoque une exception
    }
    catch (const std::exception& e) {
        std::cout << "Exception attrapée: " << e.what() << std::endl;
    }

    std::cout << "\n--- Résumé des concepts ---" << std::endl;
    std::cout << "1. RAII (Resource Acquisition Is Initialization):" << std::endl;
    std::cout << "   - Acquisition des ressources dans le constructeur" << std::endl;
    std::cout << "   - Libération des ressources dans le destructeur" << std::endl;
    std::cout << "   - Garantit la libération même en cas d'exception" << std::endl;

    std::cout << "2. Smart pointers (C++ moderne):" << std::endl;
    std::cout << "   - unique_ptr: propriété exclusive" << std::endl;
    std::cout << "   - shared_ptr: propriété partagée avec comptage de références" << std::endl;
    std::cout << "   - weak_ptr: référence non-propriétaire vers un shared_ptr" << std::endl;

    std::cout << "3. Avantages de la gestion automatique:" << std::endl;
    std::cout << "   - Évite les fuites mémoire" << std::endl;
    std::cout << "   - Code plus sûr et plus clair" << std::endl;
    std::cout << "   - Gestion robuste des exceptions" << std::endl;

    return 0;
}
