/*
 * Exercice 6.3: Chaînage de Fonctions
 *
 * Ce programme démontre le chaînage de fonctions grâce à des retours par référence,
 * en implémentant un système de traitement de données inspiré du style de
 * programmation fonctionnelle.
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>

// Classe qui encapsule une liste de nombres
class ListeNombres {
private:
    std::vector<int> donnees;

public:
    // Constructeur à partir d'un vecteur
    ListeNombres(const std::vector<int>& data) : donnees(data) {}

    // Constructeur à partir d'initializer list
    ListeNombres(std::initializer_list<int> list) : donnees(list) {}

    // Filtre les éléments selon un prédicat, retourne une référence pour permettre le chaînage
    ListeNombres& filtrer(std::function<bool(int)> predicat) {
        std::vector<int> resultat;
        for (int valeur : donnees) {
            if (predicat(valeur)) {
                resultat.push_back(valeur);
            }
        }
        donnees = resultat;
        return *this;
    }

    // Applique une transformation à chaque élément
    ListeNombres& transformer(std::function<int(int)> transformation) {
        for (int& valeur : donnees) {
            valeur = transformation(valeur);
        }
        return *this;
    }

    // Applique une opération de réduction et retourne le résultat
    int reduire(int valeurInitiale, std::function<int(int, int)> operation) const {
        int resultat = valeurInitiale;
        for (int valeur : donnees) {
            resultat = operation(resultat, valeur);
        }
        return resultat;
    }

    // Retourne une nouvelle liste triée (ne modifie pas l'original)
    ListeNombres triee() const {
        ListeNombres resultat = *this;
        std::sort(resultat.donnees.begin(), resultat.donnees.end());
        return resultat;
    }

    // Accesseur pour la taille
    size_t taille() const {
        return donnees.size();
    }

    // Accesseur pour les éléments
    const std::vector<int>& obtenirDonnees() const {
        return donnees;
    }

    // Affiche le contenu de la liste
    void afficher(const std::string& message = "") const {
        if (!message.empty()) {
            std::cout << message << ": ";
        }
        std::cout << "[ ";
        for (size_t i = 0; i < donnees.size(); ++i) {
            std::cout << donnees[i];
            if (i < donnees.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << " ]" << std::endl;
    }
};

// Démonstrateur de filtrage (prédicats)
class Filtres {
public:
    static bool estPair(int n) {
        return n % 2 == 0;
    }

    static bool estImpair(int n) {
        return n % 2 != 0;
    }

    static bool estPositif(int n) {
        return n > 0;
    }

    static std::function<bool(int)> estSuperieurA(int limite) {
        return [limite](int n) { return n > limite; };
    }

    static std::function<bool(int)> estDivisiblePar(int diviseur) {
        return [diviseur](int n) { return diviseur != 0 && n % diviseur == 0; };
    }
};

// Démonstrateur de transformations
class Transformations {
public:
    static int carre(int n) {
        return n * n;
    }

    static int cube(int n) {
        return n * n * n;
    }

    static std::function<int(int)> multiplierPar(int facteur) {
        return [facteur](int n) { return n * facteur; };
    }

    static std::function<int(int)> ajouterConstante(int constante) {
        return [constante](int n) { return n + constante; };
    }
};

// Démonstrateur d'opérations de réduction
class Operations {
public:
    static int somme(int acc, int n) {
        return acc + n;
    }

    static int produit(int acc, int n) {
        return acc * n;
    }

    static int maximum(int acc, int n) {
        return std::max(acc, n);
    }

    static int minimum(int acc, int n) {
        return std::min(acc, n);
    }
};

int main() {
    // Créer une liste de nombres
    ListeNombres nombres = {1, -2, 3, -4, 5, 6, -7, 8, 9, 10};
    nombres.afficher("Liste initiale");

    // Exemple 1: Filtrer les nombres positifs, puis calculer leurs carrés
    ListeNombres resultat1 = ListeNombres(nombres.obtenirDonnees())
        .filtrer(Filtres::estPositif)
        .transformer(Transformations::carre);
    resultat1.afficher("Nombres positifs au carré");

    // Exemple 2: Filtrer les nombres pairs, les tripler, puis les trier
    ListeNombres resultat2 = ListeNombres(nombres.obtenirDonnees())
        .filtrer(Filtres::estPair)
        .transformer(Transformations::multiplierPar(3))
        .triee();
    resultat2.afficher("Nombres pairs triplés et triés");

    // Exemple 3: Filtrer les nombres supérieurs à 5, puis calculer leur somme
    int sommeSupA5 = ListeNombres(nombres.obtenirDonnees())
        .filtrer(Filtres::estSuperieurA(5))
        .reduire(0, Operations::somme);
    std::cout << "Somme des nombres supérieurs à 5: " << sommeSupA5 << std::endl;

    // Exemple 4: Calculer le produit des nombres impairs
    int produitImpairs = ListeNombres(nombres.obtenirDonnees())
        .filtrer(Filtres::estImpair)
        .reduire(1, Operations::produit);
    std::cout << "Produit des nombres impairs: " << produitImpairs << std::endl;

    // Exemple 5: Chaînage complexe avec plusieurs opérations
    ListeNombres resultatComplexe = ListeNombres(nombres.obtenirDonnees())
        .filtrer(Filtres::estDivisiblePar(2))          // Nombres divisibles par 2
        .transformer(Transformations::ajouterConstante(5))  // Ajouter 5 à chaque nombre
        .filtrer(Filtres::estSuperieurA(10))           // Filtrer ceux > 10
        .transformer(Transformations::multiplierPar(2))  // Multiplier par 2
        .triee();                                      // Trier le résultat
    resultatComplexe.afficher("Résultat de l'opération complexe");

    // Démonstration de l'utilisation correcte de const
    const ListeNombres listeConstante = {1, 2, 3, 4, 5};
    listeConstante.afficher("Liste constante");

    // On peut appeler des méthodes const sur un objet const
    int sommeConstante = listeConstante.reduire(0, Operations::somme);
    std::cout << "Somme de la liste constante: " << sommeConstante << std::endl;

    // On peut créer une nouvelle liste à partir d'une constante
    ListeNombres listeSortedFromConst = listeConstante.triee();
    listeSortedFromConst.afficher("Liste triée à partir d'une constante");

    // Mais on ne peut pas modifier la liste constante directement
    // (ce code générerait une erreur de compilation):
    // listeConstante.transformer(Transformations::carre);

    std::cout << "\nAvantages du chaînage de fonctions:" << std::endl;
    std::cout << "1. Code plus lisible et concis" << std::endl;
    std::cout << "2. Évite les variables temporaires intermédiaires" << std::endl;
    std::cout << "3. Permet de composer des opérations complexes à partir d'opérations simples" << std::endl;
    std::cout << "4. Facilite la réutilisation des transformations et filtres" << std::endl;

    return 0;
}
