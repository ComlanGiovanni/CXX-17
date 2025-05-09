#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

// Structure pour stocker les données
struct Personne {
    std::string nom;
    int age;
    double hauteur;
};

int main() {
    // 1. Écriture dans un fichier
    std::ofstream fichierSortie("personnes.txt");

    if (!fichierSortie) {
        std::cerr << "Erreur: Impossible d'ouvrir le fichier en écriture." << std::endl;
        return 1;
    }

    // Écriture de l'en-tête
    fichierSortie << "Nom,Age,Hauteur" << std::endl;

    // Écriture des données
    fichierSortie << "Alice,25,1.65" << std::endl;
    fichierSortie << "Bob,30,1.80" << std::endl;
    fichierSortie << "Charlie,22,1.75" << std::endl;

    fichierSortie.close();
    std::cout << "Données écrites dans le fichier 'personnes.txt'" << std::endl;

    // 2. Lecture depuis un fichier
    std::ifstream fichierEntree("personnes.txt");

    if (!fichierEntree) {
        std::cerr << "Erreur: Impossible d'ouvrir le fichier en lecture." << std::endl;
        return 1;
    }

    // Ignorer la première ligne (en-tête)
    std::string ligne;
    std::getline(fichierEntree, ligne);

    // Lecture des données
    std::vector<Personne> personnes;

    while (std::getline(fichierEntree, ligne)) {
        Personne p;

        // Recherche de la première virgule
        size_t pos1 = ligne.find(',');
        if (pos1 != std::string::npos) {
            p.nom = ligne.substr(0, pos1);

            // Recherche de la deuxième virgule
            size_t pos2 = ligne.find(',', pos1 + 1);
            if (pos2 != std::string::npos) {
                // Extraction de l'âge
                std::string ageStr = ligne.substr(pos1 + 1, pos2 - pos1 - 1);
                p.age = std::stoi(ageStr);

                // Extraction de la hauteur
                std::string hauteurStr = ligne.substr(pos2 + 1);
                p.hauteur = std::stod(hauteurStr);

                // Ajout à la liste
                personnes.push_back(p);
            }
        }
    }

    fichierEntree.close();

    // Affichage des données lues
    std::cout << "\nDonnées lues depuis le fichier:" << std::endl;
    std::cout << "+----------+-----+--------+" << std::endl;
    std::cout << "| Nom      | Age | Hauteur |" << std::endl;
    std::cout << "+----------+-----+--------+" << std::endl;

    double sommeAges = 0, sommeHauteurs = 0;

    for (const auto& p : personnes) {
        std::cout << "| " << std::left << std::setw(8) << p.nom << " | "
                  << std::right << std::setw(3) << p.age << " | "
                  << std::fixed << std::setprecision(2) << std::setw(6) << p.hauteur << " |" << std::endl;

        sommeAges += p.age;
        sommeHauteurs += p.hauteur;
    }

    std::cout << "+----------+-----+--------+" << std::endl;

    // Calcul et affichage des moyennes
    if (!personnes.empty()) {
        double moyenneAges = sommeAges / personnes.size();
        double moyenneHauteurs = sommeHauteurs / personnes.size();

        std::cout << "\nStatistiques:" << std::endl;
        std::cout << "Nombre de personnes: " << personnes.size() << std::endl;
        std::cout << "Âge moyen: " << std::fixed << std::setprecision(1) << moyenneAges << " ans" << std::endl;
        std::cout << "Hauteur moyenne: " << std::fixed << std::setprecision(2) << moyenneHauteurs << " mètres" << std::endl;
    }

    return 0;
}
