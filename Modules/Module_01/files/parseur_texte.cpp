/*
 * Exercice 5.3: Parseur de Texte Simple
 *
 * Ce programme crée un parseur de texte qui compte les mots, les lignes et les caractères,
 * et identifie les mots les plus fréquents. Il démontre les différences entre
 * la manipulation avec char[] et std::string.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <cctype>

// Structure pour stocker les statistiques du texte
struct TextStats {
    int characterCount;
    int wordCount;
    int lineCount;
    std::map<std::string, int> wordFrequency;
};

// Implémentation avec char[] (style C)
TextStats parseTextWithCStyle(const char* text) {
    TextStats stats = {0, 0, 0, {}};

    // Copier le texte pour ne pas modifier l'original
    size_t textLength = strlen(text);
    char* textCopy = new char[textLength + 1];
    strcpy(textCopy, text);

    // Compter les caractères
    stats.characterCount = textLength;

    // Compter les lignes
    for (size_t i = 0; i < textLength; i++) {
        if (textCopy[i] == '\n') {
            stats.lineCount++;
        }
    }
    // Si le texte ne se termine pas par \n, ajouter une ligne
    if (textLength > 0 && textCopy[textLength - 1] != '\n') {
        stats.lineCount++;
    }

    // Compter les mots et leur fréquence
    char* token = strtok(textCopy, " \t\n,.:;!?\"'()[]{}");
    while (token != nullptr) {
        stats.wordCount++;

        // Convertir en minuscules pour la fréquence
        char* word = new char[strlen(token) + 1];
        strcpy(word, token);
        for (size_t i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        // Incrémenter la fréquence
        std::string wordStr(word);
        stats.wordFrequency[wordStr]++;

        delete[] word;
        token = strtok(nullptr, " \t\n,.:;!?\"'()[]{}");
    }

    delete[] textCopy;
    return stats;
}

// Implémentation avec std::string (C++ moderne)
TextStats parseTextWithString(const std::string& text) {
    TextStats stats = {0, 0, 0, {}};

    // Compter les caractères
    stats.characterCount = text.length();

    // Compter les lignes
    stats.lineCount = std::count(text.begin(), text.end(), '\n') +
                      (text.empty() || text.back() == '\n' ? 0 : 1);

    // Compter les mots et leur fréquence
    std::string delimiters = " \t\n,.:;!?\"'()[]{}";
    std::string textCopy = text;
    size_t pos = 0;
    std::string token;

    while ((pos = textCopy.find_first_not_of(delimiters, pos)) != std::string::npos) {
        size_t endPos = textCopy.find_first_of(delimiters, pos);
        if (endPos == std::string::npos) {
            endPos = textCopy.length();
        }

        token = textCopy.substr(pos, endPos - pos);
        stats.wordCount++;

        // Convertir en minuscules pour la fréquence
        std::transform(token.begin(), token.end(), token.begin(),
                      [](unsigned char c) { return std::tolower(c); });

        // Incrémenter la fréquence
        stats.wordFrequency[token]++;

        pos = endPos;
    }

    return stats;
}

// Fonction pour obtenir les N mots les plus fréquents
std::vector<std::pair<std::string, int>> getTopWords(const TextStats& stats, int n) {
    std::vector<std::pair<std::string, int>> pairs;
    for (const auto& pair : stats.wordFrequency) {
        pairs.push_back(pair);
    }

    std::sort(pairs.begin(), pairs.end(),
              [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
                  return a.second > b.second;
              });

    if (pairs.size() > n) {
        pairs.resize(n);
    }
    return pairs;
}

// Fonction pour afficher les statistiques
void printStats(const TextStats& stats, const std::string& method) {
    std::cout << "Statistiques du texte (méthode: " << method << "):" << std::endl;
    std::cout << "- Nombre de caractères: " << stats.characterCount << std::endl;
    std::cout << "- Nombre de mots: " << stats.wordCount << std::endl;
    std::cout << "- Nombre de lignes: " << stats.lineCount << std::endl;

    std::cout << "- Mots les plus fréquents:" << std::endl;
    auto topWords = getTopWords(stats, 5);
    for (const auto& word : topWords) {
        std::cout << "  * " << word.first << " (" << word.second << " occurrences)" << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    // Exemple de texte (multilignes)
    const char* sampleText =
        "C++ est un langage de programmation compilé permettant\n"
        "la programmation sous de multiples paradigmes, dont la programmation procédurale,\n"
        "la programmation orientée objet et la programmation générique.\n"
        "Ses bonnes performances, et sa compatibilité avec le C en font\n"
        "un des langages de programmation les plus utilisés dans les applications\n"
        "où la performance est critique.\n";

    // Analyser avec l'approche style C
    TextStats statsC = parseTextWithCStyle(sampleText);
    printStats(statsC, "char[] (style C)");

    // Analyser avec l'approche std::string
    std::string textStr(sampleText);
    TextStats statsString = parseTextWithString(textStr);
    printStats(statsString, "std::string (C++ moderne)");

    // Comparaison des approches
    std::cout << "Comparaison des approches:" << std::endl;
    std::cout << "- char[] (style C):" << std::endl;
    std::cout << "  * Nécessite une gestion manuelle de la mémoire (new/delete)" << std::endl;
    std::cout << "  * Utilise des fonctions comme strtok qui modifient la chaîne originale" << std::endl;
    std::cout << "  * Plus complexe et propice aux erreurs (dépassements de tampon, fuites mémoire)" << std::endl;
    std::cout << std::endl;
    std::cout << "- std::string (C++ moderne):" << std::endl;
    std::cout << "  * Gestion automatique de la mémoire" << std::endl;
    std::cout << "  * Méthodes intégrées pour la manipulation des chaînes (substr, find, etc.)" << std::endl;
    std::cout << "  * Code plus concis, sûr et lisible" << std::endl;
    std::cout << "  * Intégration plus facile avec les algorithmes STL" << std::endl;

    return 0;
}
