#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <algorithm>

// Structure pour représenter un étudiant
struct Etudiant {
    std::string nom;
    int id;
    double notes[5];
    double moyenne;
};

// Fonction pour calculer la moyenne des notes d'un étudiant
void calculerMoyenne(Etudiant& etudiant) {
    double somme = 0.0;
    for (int i = 0; i < 5; ++i) {
        somme += etudiant.notes[i];
    }
    etudiant.moyenne = somme / 5.0;
}

// Fonction pour afficher les informations d'un étudiant
void afficherEtudiant(const Etudiant& etudiant) {
    std::cout << "ID: " << etudiant.id << std::endl;
    std::cout << "Nom: " << etudiant.nom << std::endl;
    std::cout << "Notes: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << etudiant.notes[i];
        if (i < 4) std::cout << ", ";
    }
    std::cout << std::endl;
    std::cout << "Moyenne: " << std::fixed << std::setprecision(2) << etudiant.moyenne << std::endl;
}

// Fonction pour ajouter un nouvel étudiant
void ajouterEtudiant(Etudiant* etudiants, int& nbEtudiants, int capacite) {
    if (nbEtudiants >= capacite) {
        std::cout << "La capacité maximale est atteinte. Impossible d'ajouter un nouvel étudiant." << std::endl;
        return;
    }

    Etudiant& nouvelEtudiant = etudiants[nbEtudiants];

    std::cout << "Entrez le nom de l'étudiant: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, nouvelEtudiant.nom);

    std::cout << "Entrez l'ID de l'étudiant: ";
    std::cin >> nouvelEtudiant.id;

    std::cout << "Entrez les 5 notes de l'étudiant:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        while (true) {
            std::cout << "Note " << i + 1 << " (0-20): ";
            std::cin >> nouvelEtudiant.notes[i];

            if (std::cin.fail() || nouvelEtudiant.notes[i] < 0 || nouvelEtudiant.notes[i] > 20) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Erreur: veuillez entrer une note valide entre 0 et 20." << std::endl;
            } else {
                break;
            }
        }
    }

    calculerMoyenne(nouvelEtudiant);
    nbEtudiants++;

    std::cout << "Étudiant ajouté avec succès." << std::endl;
}

// Fonction pour rechercher un étudiant par ID
int rechercherEtudiant(const Etudiant* etudiants, int nbEtudiants, int id) {
    for (int i = 0; i < nbEtudiants; ++i) {
        if (etudiants[i].id == id) {
            return i;
        }
    }
    return -1;  // Étudiant non trouvé
}

// Fonction pour afficher tous les étudiants
void afficherTousEtudiants(const Etudiant* etudiants, int nbEtudiants) {
    if (nbEtudiants == 0) {
        std::cout << "Aucun étudiant enregistré." << std::endl;
        return;
    }

    std::cout << "\nListe des étudiants:" << std::endl;
    std::cout << "-------------------" << std::endl;

    for (int i = 0; i < nbEtudiants; ++i) {
        std::cout << "\nÉtudiant " << i + 1 << ":" << std::endl;
        afficherEtudiant(etudiants[i]);
    }
}

// Fonction pour calculer la moyenne générale de tous les étudiants
double calculerMoyenneGenerale(const Etudiant* etudiants, int nbEtudiants) {
    if (nbEtudiants == 0) {
        return 0.0;
    }

    double somme = 0.0;
    for (int i = 0; i < nbEtudiants; ++i) {
        somme += etudiants[i].moyenne;
    }

    return somme / nbEtudiants;
}

int main() {
    const int CAPACITE_MAX = 100;
    Etudiant* etudiants = new Etudiant[CAPACITE_MAX];
    int nbEtudiants = 0;
    int choix;

    do {
        std::cout << "\nSystème de Gestion d'Étudiants" << std::endl;
        std::cout << "----------------------------" << std::endl;
        std::cout << "1. Ajouter un étudiant" << std::endl;
        std::cout << "2. Rechercher un étudiant par ID" << std::endl;
        std::cout << "3. Afficher tous les étudiants" << std::endl;
        std::cout << "4. Calculer la moyenne générale" << std::endl;
        std::cout << "0. Quitter" << std::endl;
        std::cout << "Votre choix: ";
        std::cin >> choix;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrée invalide. Veuillez entrer un nombre." << std::endl;
            continue;
        }

        switch (choix) {
            case 1:
                ajouterEtudiant(etudiants, nbEtudiants, CAPACITE_MAX);
                break;

            case 2: {
                int id;
                std::cout << "Entrez l'ID de l'étudiant à rechercher: ";
                std::cin >> id;

                int index = rechercherEtudiant(etudiants, nbEtudiants, id);
                if (index != -1) {
                    std::cout << "\nÉtudiant trouvé:" << std::endl;
                    afficherEtudiant(etudiants[index]);
                } else {
                    std::cout << "Aucun étudiant trouvé avec l'ID " << id << std::endl;
                }
                break;
            }

            case 3:
                afficherTousEtudiants(etudiants, nbEtudiants);
                break;

            case 4: {
                double moyenneGenerale = calculerMoyenneGenerale(etudiants, nbEtudiants);
                std::cout << "Moyenne générale de tous les étudiants: "
                          << std::fixed << std::setprecision(2) << moyenneGenerale << std::endl;
                break;
            }

            case 0:
                std::cout << "Au revoir!" << std::endl;
                break;

            default:
                std::cout << "Choix invalide. Veuillez réessayer." << std::endl;
        }

    } while (choix != 0);

    // Libération de la mémoire
    delete[] etudiants;

    return 0;
}
