/*
 * Exercice 5.2: Traitement avec std::string
 *
 * Ce programme réimplémente l'exercice 5.1 avec std::string et démontre
 * les avantages en termes de facilité d'implémentation, sécurité et lisibilité.
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

// Fonction pour inverser une chaîne
std::string inverserChaine(const std::string& chaine) {
    std::string resultat = chaine;
    std::reverse(resultat.begin(), resultat.end());
    return resultat;
}

// Fonction pour compter les occurrences d'un caractère
int compterOccurrences(const std::string& chaine, char caractere) {
    return std::count(chaine.begin(), chaine.end(), caractere);
}

// Fonction pour convertir en majuscules
std::string convertirMajuscules(const std::string& chaine) {
    std::string resultat = chaine;
    std::transform(resultat.begin(), resultat.end(), resultat.begin(),
                   [](unsigned char c) { return std::toupper(c); });
    return resultat;
}

// Fonction pour convertir en minuscules
std::string convertirMinuscules(const std::string& chaine) {
    std::string resultat = chaine;
    std::transform(resultat.begin(), resultat.end(), resultat.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return resultat;
}

// Fonction pour concaténer des chaînes (avec std::string, c'est naturellement sécurisé)
std::string concatener(const std::string& s1, const std::string& s2) {
    return s1 + s2;
}

int main() {
    std::string texte = "Bonjour, monde!";
    std::string destination = "Hello, ";

    std::cout << "Chaîne originale: " << texte << std::endl;

    // Test d'inversion
    std::string inverse = inverserChaine(texte);
    std::cout << "Chaîne inversée: " << inverse << std::endl;

    // Test de comptage d'occurrences
    char caractereRecherche = 'o';
    int occurrences = compterOccurrences(texte, caractereRecherche);
    std::cout << "Nombre d'occurrences de '" << caractereRecherche << "': " << occurrences << std::endl;

    // Test de conversion en majuscules
    std::string majuscules = convertirMajuscules(texte);
    std::cout << "En majuscules: " << majuscules << std::endl;

    // Test de conversion en minuscules
    std::string minuscules = convertirMinuscules(texte);
    std::cout << "En minuscules: " << minuscules << std::endl;

    // Test de concaténation
    std::string concatenation = concatener(destination, "World!");
    std::cout << "Concaténation: " << concatenation << std::endl;

    // Démonstration des méthodes spécifiques à std::string
    std::cout << "\nMéthodes spécifiques à std::string:" << std::endl;

    // Recherche
    size_t position = texte.find("monde");
    if (position != std::string::npos) {
        std::cout << "Sous-chaîne 'monde' trouvée à la position: " << position << std::endl;
    }

    // Remplacement
    std::string texteModifie = texte;
    texteModifie.replace(texteModifie.find("monde"), 5, "world");
    std::cout << "Après remplacement: " << texteModifie << std::endl;

    // Sous-chaîne
    std::string sousChaine = texte.substr(0, 7);
    std::cout << "Sous-chaîne (0, 7): " << sousChaine << std::endl;

    // Comparaison avec les fonctions style C
    std::cout << "\nComparaison avec l'approche style C:" << std::endl;
    std::cout << "- Plus facile à implémenter (pas de gestion manuelle de la mémoire)" << std::endl;
    std::cout << "- Plus sécurisé (pas de risque de dépassement de tampon)" << std::endl;
    std::cout << "- Code plus lisible et plus concis" << std::endl;
    std::cout << "- Fonctionnalités avancées (find, replace, substr, etc.)" << std::endl;

    return 0;
}
