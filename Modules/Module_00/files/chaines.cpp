#include <iostream>
#include <cstring>  // Pour les fonctions de chaînes de style C
#include <string>   // Pour les chaînes de style C++

int main() {
    // 1. Chaînes de style C (char[])
    std::cout << "Chaînes de style C (char[]):" << std::endl;

    // Déclaration et initialisation
    char chaine1[20] = "Hello";
    char chaine2[20] = "World";
    char resultat[40];

    std::cout << "chaine1: " << chaine1 << std::endl;
    std::cout << "chaine2: " << chaine2 << std::endl;

    // Longueur de la chaîne
    std::cout << "Longueur de chaine1: " << strlen(chaine1) << std::endl;

    // Copie de chaîne
    strcpy(resultat, chaine1);
    std::cout << "Après strcpy(resultat, chaine1): " << resultat << std::endl;

    // Concaténation
    strcat(resultat, " ");
    strcat(resultat, chaine2);
    std::cout << "Après strcat: " << resultat << std::endl;

    // Comparaison
    int comp = strcmp(chaine1, chaine2);
    std::cout << "Comparaison de chaine1 et chaine2: " << comp << std::endl;

    // Recherche
    char* position = strstr(resultat, "World");
    if (position != nullptr) {
        std::cout << "Le mot 'World' commence à la position: "
                  << (position - resultat) << std::endl;
    }

    // 2. Chaînes de style C++ (std::string)
    std::cout << "\nChaînes de style C++ (std::string):" << std::endl;

    // Déclaration et initialisation
    std::string str1 = "Hello";
    std::string str2 = "World";

    std::cout << "str1: " << str1 << std::endl;
    std::cout << "str2: " << str2 << std::endl;

    // Longueur de la chaîne
    std::cout << "Longueur de str1: " << str1.length() << std::endl;

    // Concaténation
    std::string strResultat = str1 + " " + str2;
    std::cout << "Concaténation: " << strResultat << std::endl;

    // Comparaison
    if (str1 == str2) {
        std::cout << "str1 est égal à str2" << std::endl;
    } else {
        std::cout << "str1 est différent de str2" << std::endl;
    }

    // Sous-chaîne
    std::string subStr = strResultat.substr(6, 5);  // Commence à l'index 6, longueur 5
    std::cout << "Sous-chaîne: " << subStr << std::endl;

    // Recherche
    size_t pos = strResultat.find("World");
    if (pos != std::string::npos) {
        std::cout << "Position de 'World': " << pos << std::endl;
    }

    // Remplacement
    std::string str3 = strResultat;
    str3.replace(str3.find("World"), 5, "C++");
    std::cout << "Après remplacement: " << str3 << std::endl;

    // Insertion
    str3.insert(5, " beautiful");
    std::cout << "Après insertion: " << str3 << std::endl;

    // Conversion entre std::string et char*
    const char* cStr = str3.c_str();
    std::cout << "std::string converti en char*: " << cStr << std::endl;

    return 0;
}
