/*
 * Exercice 7.2: Variables Globales vs Locales
 *
 * Ce programme démontre la portée des variables, le masquage, et l'utilisation
 * de l'opérateur de résolution de portée (::).
 */

#include <iostream>
#include <string>

// Variables globales
int compteur = 0;  // Variable globale
std::string message = "Message global";  // Variable globale

// Espace de noms pour regrouper des variables globales
namespace Configuration {
    int largeur = 800;
    int hauteur = 600;
    std::string titre = "Mon Application";

    // Espace de noms imbriqué
    namespace Defaut {
        int largeur = 1024;
        int hauteur = 768;
    }
}

// Démonstration du masquage de variables
void demoMasquage() {
    int compteur = 100;  // Variable locale qui masque la variable globale

    std::cout << "Variable locale compteur: " << compteur << std::endl;
    std::cout << "Variable globale compteur: " << ::compteur << std::endl;  // Utilisation de ::

    // Modification de la variable locale
    compteur++;
    std::cout << "Variable locale compteur après incrémentation: " << compteur << std::endl;

    // Modification de la variable globale
    ::compteur++;
    std::cout << "Variable globale compteur après incrémentation: " << ::compteur << std::endl;
}

// Démonstration des variables locales dans différents blocs
void demoPorteeBloc() {
    int x = 10;  // Variable de la portée de fonction

    std::cout << "Valeur de x dans la fonction: " << x << std::endl;

    {  // Début d'un nouveau bloc
        int x = 20;  // Nouvelle variable locale au bloc qui masque la précédente
        int y = 5;   // Variable locale au bloc

        std::cout << "Valeur de x dans le bloc interne: " << x << std::endl;
        std::cout << "Valeur de y dans le bloc interne: " << y << std::endl;

        {  // Bloc imbriqué
            int z = 30;
            std::cout << "Valeur de z dans le bloc imbriqué: " << z << std::endl;
            std::cout << "Valeur de x accessible depuis le bloc imbriqué: " << x << std::endl;
        }

        // z n'est plus accessible ici
        // std::cout << "z: " << z << std::endl;  // Erreur de compilation
    }

    // y n'est plus accessible ici
    // std::cout << "y: " << y << std::endl;  // Erreur de compilation

    std::cout << "Valeur de x après le bloc: " << x << std::endl;  // Affiche 10, pas 20
}

// Démonstration des variables locales statiques
void demoVariablesStatiques() {
    static int appel = 0;  // Variable locale statique
    int nonStatique = 0;   // Variable locale ordinaire

    appel++;
    nonStatique++;

    std::cout << "Nombre d'appels (statique): " << appel << std::endl;
    std::cout << "Compteur non statique: " << nonStatique << std::endl;
}

// Démonstration des paramètres de fonction
void demoParametres(int valeur, std::string &reference) {
    std::cout << "Valeur du paramètre: " << valeur << std::endl;
    std::cout << "Référence du paramètre: " << reference << std::endl;

    // Modification des paramètres
    valeur = 999;        // Modification locale uniquement
    reference = "Modifié";  // Modifie la variable originale

    std::cout << "Après modification - valeur: " << valeur << std::endl;
    std::cout << "Après modification - référence: " << reference << std::endl;
}

// Classe démontrant les portées de variables membres
class Compteur {
private:
    int valeur;  // Variable membre (instance)

public:
    static int nombreInstances;  // Variable de classe (partagée)

    Compteur(int v) : valeur(v) {
        nombreInstances++;
    }

    void incrementer() {
        int valeur = this->valeur + 1;  // Variable locale masquant la variable membre
        std::cout << "Variable locale valeur: " << valeur << std::endl;
        std::cout << "Variable membre valeur (via this): " << this->valeur << std::endl;

        // Modification de la variable membre
        this->valeur++;
    }

    int getValeur() const {
        return valeur;  // Accès à la variable membre
    }
};

// Initialisation de la variable statique
int Compteur::nombreInstances = 0;

int main() {
    std::cout << "--- Démonstration du masquage de variables ---" << std::endl;
    demoMasquage();

    std::cout << "\n--- Démonstration de la portée des blocs ---" << std::endl;
    demoPorteeBloc();

    std::cout << "\n--- Démonstration des variables statiques ---" << std::endl;
    demoVariablesStatiques();
    demoVariablesStatiques();
    demoVariablesStatiques();

    std::cout << "\n--- Démonstration des paramètres de fonction ---" << std::endl;
    int nombre = 42;
    std::string texte = "Original";
    std::cout << "Avant l'appel - nombre: " << nombre << ", texte: " << texte << std::endl;
    demoParametres(nombre, texte);
    std::cout << "Après l'appel - nombre: " << nombre << ", texte: " << texte << std::endl;

    std::cout << "\n--- Démonstration des espaces de noms ---" << std::endl;
    std::cout << "Configuration::largeur: " << Configuration::largeur << std::endl;
    std::cout << "Configuration::hauteur: " << Configuration::hauteur << std::endl;
    std::cout << "Configuration::Defaut::largeur: " << Configuration::Defaut::largeur << std::endl;

    // Utilisation de using
    using namespace Configuration;
    std::cout << "Après using - largeur: " << largeur << std::endl;
    std::cout << "Après using - Defaut::hauteur: " << Defaut::hauteur << std::endl;

    std::cout << "\n--- Démonstration des variables membres vs locales ---" << std::endl;
    Compteur c1(5);
    Compteur c2(10);

    std::cout << "Nombre d'instances: " << Compteur::nombreInstances << std::endl;
    std::cout << "Valeur initiale c1: " << c1.getValeur() << std::endl;

    c1.incrementer();
    std::cout << "Valeur de c1 après incrémentation: " << c1.getValeur() << std::endl;

    std::cout << "\n--- Résumé des concepts de portée ---" << std::endl;
    std::cout << "1. Variables globales: accessibles partout, durée de vie = programme entier" << std::endl;
    std::cout << "2. Variables locales: accessibles dans leur bloc, durée de vie = bloc" << std::endl;
    std::cout << "3. Variables locales statiques: accessibles dans leur bloc, durée de vie = programme" << std::endl;
    std::cout << "4. Membres de classe: accessibles selon visibilité, durée de vie = instance" << std::endl;
    std::cout << "5. Membres statiques de classe: partagés entre instances, durée de vie = programme" << std::endl;

    return 0;
}
