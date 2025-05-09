/*
 * Exercice 5.1: Traitement de Chaînes Style C
 *
 * Ce programme démontre la manipulation de chaînes de caractères style C (char[]),
 * y compris l'inversion de chaînes, le comptage d'occurrences, la conversion en
 * majuscules/minuscules, et la concaténation sécurisée.
 */

#include <iostream>
#include <cstring>
#include <cctype>

// Fonction pour inverser une chaîne de caractères
void inverserChaine(char* chaine) {
    size_t longueur = strlen(chaine);
    for (size_t i = 0; i < longueur / 2; i++) {
        char temp = chaine[i];
        chaine[i] = chaine[longueur - i - 1];
        chaine[longueur - i - 1] = temp;
    }
}

// Fonction pour compter les occurrences d'un caractère
int compterOccurrences(const char* chaine, char caractere) {
    int compteur = 0;
    for (size_t i = 0; i < strlen(chaine); i++) {
        if (chaine[i] == caractere) {
            compteur++;
        }
    }
    return compteur;
}

// Fonction pour convertir en majuscules
void convertirMajuscules(char* chaine) {
    for (size_t i = 0; i < strlen(chaine); i++) {
        chaine[i] = toupper(chaine[i]);
    }
}

// Fonction pour convertir en minuscules
void convertirMinuscules(char* chaine) {
    for (size_t i = 0; i < strlen(chaine); i++) {
        chaine[i] = tolower(chaine[i]);
    }
}

// Fonction pour concaténer des chaînes de manière sécurisée
bool concatenerSecurise(char* dest, size_t tailleMax, const char* src) {
    size_t longueurDest = strlen(dest);
    size_t longueurSrc = strlen(src);

    // Vérifier si l'espace est suffisant
    if (longueurDest + longueurSrc >= tailleMax - 1) {
        return false; // Pas assez d'espace
    }

    // Concaténer de manière sécurisée
    strcat(dest, src);
    return true;
}

int main() {
    const size_t TAILLE_MAX = 100;
    char texte[TAILLE_MAX] = "Bonjour, monde!";
    char copie[TAILLE_MAX];
    char destination[TAILLE_MAX] = "Hello, ";

    std::cout << "Chaîne originale: " << texte << std::endl;

    // Test d'inversion
    strcpy(copie, texte);
    inverserChaine(copie);
    std::cout << "Chaîne inversée: " << copie << std::endl;

    // Test de comptage d'occurrences
    char caractereRecherche = 'o';
    int occurrences = compterOccurrences(texte, caractereRecherche);
    std::cout << "Nombre d'occurrences de '" << caractereRecherche << "': " << occurrences << std::endl;

    // Test de conversion en majuscules
    strcpy(copie, texte);
    convertirMajuscules(copie);
    std::cout << "En majuscules: " << copie << std::endl;

    // Test de conversion en minuscules
    strcpy(copie, texte);
    convertirMinuscules(copie);
    std::cout << "En minuscules: " << copie << std::endl;

    // Test de concaténation sécurisée
    const char* aAjouter = "World!";
    if (concatenerSecurise(destination, TAILLE_MAX, aAjouter)) {
        std::cout << "Concaténation réussie: " << destination << std::endl;
    } else {
        std::cout << "Échec de la concaténation: pas assez d'espace." << std::endl;
    }

    // Test d'échec de concaténation (simulé avec une petite taille)
    char petitBuffer[5] = "A";
    if (concatenerSecurise(petitBuffer, 5, "BCDEF")) {
        std::cout << "Concaténation réussie: " << petitBuffer << std::endl;
    } else {
        std::cout << "Échec de la concaténation: pas assez d'espace (attendu)." << std::endl;
    }

    return 0;
}
