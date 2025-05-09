/*
 * Exercice 7.1: Variables Statiques
 *
 * Ce programme démontre l'utilisation des variables statiques dans des fonctions
 * pour maintenir des états entre les appels.
 */

#include <iostream>
#include <string>
#include <vector>

// Fonction qui compte ses propres appels
int compteurAppels() {
    // Variable statique initialisée une seule fois, conserve sa valeur entre les appels
    static int compteur = 0;
    return ++compteur;
}

// Fonction qui mémorise la plus grande valeur rencontrée
int miseAJourMaximum(int valeur) {
    static int maximum = INT_MIN; // Initialisé avec la plus petite valeur possible
    if (valeur > maximum) {
        maximum = valeur;
    }
    return maximum;
}

// Fonction qui garde l'historique des valeurs
std::vector<int> obtenirHistorique(int nouvelleValeur) {
    static std::vector<int> historique;
    historique.push_back(nouvelleValeur);
    return historique;
}

// Générateur de nombres de Fibonacci utilisant des variables statiques
int fibonacci() {
    static int a = 0;
    static int b = 1;

    int resultat = a;
    int temp = a + b;
    a = b;
    b = temp;

    return resultat;
}

// Compteur personnalisé avec valeur initiale configurable
int compteurPersonnalise(int increment = 1) {
    // La valeur initiale est spécifiée seulement à la première utilisation
    static int valeur = 0;
    static bool initialise = false;

    if (!initialise) {
        valeur = increment; // Utiliser increment comme valeur initiale
        initialise = true;
        return valeur;
    }

    valeur += increment;
    return valeur;
}

// Classe utilisant des membres statiques
class Utilisateur {
private:
    std::string nom;
    int id;

    static int prochainId; // Variable statique partagée par tous les objets
    static int nombreUtilisateurs;

public:
    Utilisateur(const std::string& n) : nom(n) {
        id = prochainId++;
        nombreUtilisateurs++;
    }

    ~Utilisateur() {
        nombreUtilisateurs--;
    }

    std::string getNom() const {
        return nom;
    }

    int getId() const {
        return id;
    }

    // Méthode statique pour obtenir le nombre d'utilisateurs
    static int getNombreUtilisateurs() {
        return nombreUtilisateurs;
    }

    // Méthode statique pour réinitialiser le compteur d'ID
    static void reinitialiserCompteur() {
        prochainId = 1;
    }
};

// Initialisation des membres statiques
int Utilisateur::prochainId = 1;
int Utilisateur::nombreUtilisateurs = 0;

int main() {
    // Démonstration du compteur d'appels
    std::cout << "Démonstration du compteur d'appels:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "Appel #" << compteurAppels() << std::endl;
    }

    // Démonstration du suivi du maximum
    std::cout << "\nDémonstration du suivi du maximum:" << std::endl;
    std::cout << "Maximum actuel: " << miseAJourMaximum(10) << std::endl;
    std::cout << "Maximum actuel: " << miseAJourMaximum(5) << std::endl;
    std::cout << "Maximum actuel: " << miseAJourMaximum(15) << std::endl;
    std::cout << "Maximum actuel: " << miseAJourMaximum(12) << std::endl;

    // Démonstration de l'historique
    std::cout << "\nDémonstration de l'historique:" << std::endl;
    obtenirHistorique(100);
    obtenirHistorique(200);
    std::vector<int> historique = obtenirHistorique(300);
    std::cout << "Historique: ";
    for (int val : historique) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Démonstration du générateur Fibonacci
    std::cout << "\nDémonstration du générateur Fibonacci:" << std::endl;
    std::cout << "Suite de Fibonacci: ";
    for (int i = 0; i < 10; i++) {
        std::cout << fibonacci() << " ";
    }
    std::cout << std::endl;

    // Démonstration du compteur personnalisé
    std::cout << "\nDémonstration du compteur personnalisé:" << std::endl;
    std::cout << "Valeur initiale: " << compteurPersonnalise(5) << std::endl;
    std::cout << "Incrémentation: " << compteurPersonnalise() << std::endl;
    std::cout << "Incrémentation: " << compteurPersonnalise() << std::endl;
    std::cout << "Incrémentation de 10: " << compteurPersonnalise(10) << std::endl;

    // Démonstration des membres statiques de classe
    std::cout << "\nDémonstration des membres statiques de classe:" << std::endl;

    // Réinitialiser le compteur pour la démonstration
    Utilisateur::reinitialiserCompteur();

    std::cout << "Nombre d'utilisateurs initial: " << Utilisateur::getNombreUtilisateurs() << std::endl;

    // Créer quelques utilisateurs
    Utilisateur user1("Alice");
    Utilisateur user2("Bob");

    std::cout << "Utilisateur: " << user1.getNom() << ", ID: " << user1.getId() << std::endl;
    std::cout << "Utilisateur: " << user2.getNom() << ", ID: " << user2.getId() << std::endl;
    std::cout << "Nombre d'utilisateurs: " << Utilisateur::getNombreUtilisateurs() << std::endl;

    // Créer un bloc pour démontrer la destruction
    {
        Utilisateur user3("Charlie");
        std::cout << "Utilisateur: " << user3.getNom() << ", ID: " << user3.getId() << std::endl;
        std::cout << "Nombre d'utilisateurs (bloc interne): " << Utilisateur::getNombreUtilisateurs() << std::endl;
    }

    std::cout << "Nombre d'utilisateurs après le bloc: " << Utilisateur::getNombreUtilisateurs() << std::endl;

    std::cout << "\nAvantages des variables statiques:" << std::endl;
    std::cout << "1. Persistance des données entre les appels de fonction" << std::endl;
    std::cout << "2. Possibilité de créer des compteurs et des historiques" << std::endl;
    std::cout << "3. Partage d'état entre plusieurs instances d'une classe" << std::endl;
    std::cout << "4. Économie de mémoire pour les valeurs partagées" << std::endl;

    std::cout << "\nMises en garde:" << std::endl;
    std::cout << "1. Les variables statiques rendent le code moins prévisible" << std::endl;
    std::cout << "2. Difficultés pour les tests unitaires (état partagé)" << std::endl;
    std::cout << "3. Problèmes potentiels dans les applications multi-threads" << std::endl;

    return 0;
}
