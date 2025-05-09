#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <string>
#include <chrono>

// Version avec tableaux C classiques
namespace TableauxC {
    // Structure pour stocker les données d'un étudiant
    struct Etudiant {
        char nom[50];
        int notes[5];
        double moyenne;
    };

    // Calcul de la moyenne des notes d'un étudiant
    void calculerMoyenne(Etudiant& etudiant) {
        int somme = 0;
        for (int i = 0; i < 5; ++i) {
            somme += etudiant.notes[i];
        }
        etudiant.moyenne = static_cast<double>(somme) / 5.0;
    }

    // Afficher les informations d'un étudiant
    void afficherEtudiant(const Etudiant& etudiant) {
        std::cout << "Nom: " << etudiant.nom << std::endl;
        std::cout << "Notes: ";
        for (int i = 0; i < 5; ++i) {
            std::cout << etudiant.notes[i];
            if (i < 4) std::cout << ", ";
        }
        std::cout << std::endl;
        std::cout << "Moyenne: " << std::fixed << std::setprecision(2) << etudiant.moyenne << std::endl;
    }

    // Fonction principale pour le système avec tableaux C
    void executeSystemeTableauxC() {
        const int MAX_ETUDIANTS = 100;
        Etudiant etudiants[MAX_ETUDIANTS];
        int nbEtudiants = 0;

        // Ajouter quelques étudiants pour l'exemple
        strcpy(etudiants[0].nom, "Alice");
        etudiants[0].notes[0] = 15;
        etudiants[0].notes[1] = 17;
        etudiants[0].notes[2] = 14;
        etudiants[0].notes[3] = 16;
        etudiants[0].notes[4] = 18;
        calculerMoyenne(etudiants[0]);
        nbEtudiants++;

        strcpy(etudiants[1].nom, "Bob");
        etudiants[1].notes[0] = 12;
        etudiants[1].notes[1] = 13;
        etudiants[1].notes[2] = 10;
        etudiants[1].notes[3] = 14;
        etudiants[1].notes[4] = 11;
        calculerMoyenne(etudiants[1]);
        nbEtudiants++;

        strcpy(etudiants[2].nom, "Charlie");
        etudiants[2].notes[0] = 9;
        etudiants[2].notes[1] = 11;
        etudiants[2].notes[2] = 10;
        etudiants[2].notes[3] = 8;
        etudiants[2].notes[4] = 7;
        calculerMoyenne(etudiants[2]);
        nbEtudiants++;

        // Afficher tous les étudiants
        std::cout << "\nListe des étudiants (Tableaux C):" << std::endl;
        std::cout << "-----------------------------" << std::endl;
        for (int i = 0; i < nbEtudiants; ++i) {
            std::cout << "\nÉtudiant " << i + 1 << ":" << std::endl;
            afficherEtudiant(etudiants[i]);
        }

        // Calculer la moyenne générale
        double sommeGenerale = 0.0;
        for (int i = 0; i < nbEtudiants; ++i) {
            sommeGenerale += etudiants[i].moyenne;
        }
        double moyenneGenerale = sommeGenerale / nbEtudiants;

        std::cout << "\nMoyenne générale: " << std::fixed << std::setprecision(2) << moyenneGenerale << std::endl;

        // Problèmes avec cette approche:
        // 1. Taille fixe (MAX_ETUDIANTS)
        // 2. Gestion manuelle du compteur (nbEtudiants)
        // 3. Pas de vérification des limites du tableau
        // 4. Risque de débordement avec les chaînes de caractères
        // 5. Difficulté pour trier, rechercher, etc.
    }
}

// Version avec conteneurs STL
namespace ConteneurSTL {
    // Structure pour stocker les données d'un étudiant
    struct Etudiant {
        std::string nom;
        std::array<int, 5> notes;
        double moyenne;
    };

    // Calcul de la moyenne des notes d'un étudiant
    void calculerMoyenne(Etudiant& etudiant) {
        int somme = std::accumulate(etudiant.notes.begin(), etudiant.notes.end(), 0);
        etudiant.moyenne = static_cast<double>(somme) / etudiant.notes.size();
    }

    // Afficher les informations d'un étudiant
    void afficherEtudiant(const Etudiant& etudiant) {
        std::cout << "Nom: " << etudiant.nom << std::endl;
        std::cout << "Notes: ";
        for (size_t i = 0; i < etudiant.notes.size(); ++i) {
            std::cout << etudiant.notes[i];
            if (i < etudiant.notes.size() - 1) std::cout << ", ";
        }
        std::cout << std::endl;
        std::cout << "Moyenne: " << std::fixed << std::setprecision(2) << etudiant.moyenne << std::endl;
    }

    // Fonction principale pour le système avec conteneurs STL
    void executeSystemeConteneurSTL() {
        std::vector<Etudiant> etudiants;

        // Ajouter quelques étudiants pour l'exemple
        Etudiant alice = {"Alice", {15, 17, 14, 16, 18}};
        calculerMoyenne(alice);
        etudiants.push_back(alice);

        Etudiant bob = {"Bob", {12, 13, 10, 14, 11}};
        calculerMoyenne(bob);
        etudiants.push_back(bob);

        Etudiant charlie = {"Charlie", {9, 11, 10, 8, 7}};
        calculerMoyenne(charlie);
        etudiants.push_back(charlie);

        // Afficher tous les étudiants
        std::cout << "\nListe des étudiants (Conteneurs STL):" << std::endl;
        std::cout << "--------------------------------" << std::endl;
        for (size_t i = 0; i < etudiants.size(); ++i) {
            std::cout << "\nÉtudiant " << i + 1 << ":" << std::endl;
            afficherEtudiant(etudiants[i]);
        }

        // Calculer la moyenne générale en utilisant les algorithmes STL
        double sommeGenerale = 0.0;
        for (const auto& etudiant : etudiants) {
            sommeGenerale += etudiant.moyenne;
        }
        double moyenneGenerale = sommeGenerale / etudiants.size();

        std::cout << "\nMoyenne générale: " << std::fixed << std::setprecision(2) << moyenneGenerale << std::endl;

        // Trier les étudiants par moyenne (du plus élevé au plus bas)
        std::sort(etudiants.begin(), etudiants.end(),
            [](const Etudiant& a, const Etudiant& b) {
                return a.moyenne > b.moyenne;
            });

        std::cout << "\nÉtudiants triés par moyenne (décroissante):" << std::endl;
        std::cout << "-------------------------------------" << std::endl;
        for (size_t i = 0; i < etudiants.size(); ++i) {
            std::cout << i + 1 << ". " << etudiants[i].nom << ": "
                      << std::fixed << std::setprecision(2) << etudiants[i].moyenne << std::endl;
        }

        // Recherche de l'étudiant avec la meilleure note en mathématiques (supposons notes[0])
        auto meilleurMath = std::max_element(etudiants.begin(), etudiants.end(),
            [](const Etudiant& a, const Etudiant& b) {
                return a.notes[0] < b.notes[0];
            });

        std::cout << "\nMeilleure note en mathématiques: " << meilleurMath->nom
                  << " (" << meilleurMath->notes[0] << ")" << std::endl;

        // Ajouter un nouvel étudiant (pas de limite fixe)
        Etudiant dave = {"Dave", {14, 16, 15, 13, 17}};
        calculerMoyenne(dave);
        etudiants.push_back(dave);

        std::cout << "\nNouvel étudiant ajouté: " << dave.nom << std::endl;
        std::cout << "Nombre total d'étudiants: " << etudiants.size() << std::endl;
    }
}

int main() {
    std::cout << "COMPARAISON ENTRE TABLEAUX C ET CONTENEURS STL" << std::endl;
    std::cout << "===========================================" << std::endl;

    // Exécution de la version avec tableaux C
    std::cout << "\nVERSION AVEC TABLEAUX C:" << std::endl;
    std::cout << "====================" << std::endl;
    TableauxC::executeSystemeTableauxC();

    // Exécution de la version avec conteneurs STL
    std::cout << "\n\nVERSION AVEC CONTENEURS STL:" << std::endl;
    std::cout << "========================" << std::endl;
    ConteneurSTL::executeSystemeConteneurSTL();

    // Comparaison des avantages
    std::cout << "\n\nAVANTAGES DES CONTENEURS STL:" << std::endl;
    std::cout << "=========================" << std::endl;
    std::cout << "1. Taille dynamique (std::vector)" << std::endl;
    std::cout << "2. Meilleure sécurité (pas de débordement de tableau)" << std::endl;
    std::cout << "3. Utilisation simplifiée des algorithmes (sort, find, etc.)" << std::endl;
    std::cout << "4. Gestion automatique de la mémoire" << std::endl;
    std::cout << "5. Interface plus riche (iterators, méthodes spécifiques)" << std::endl;
    std::cout << "6. Pas besoin de gérer manuellement le compteur d'éléments" << std::endl;
    std::cout << "7. Meilleure lisibilité et maintenabilité du code" << std::endl;

    return 0;
}
