#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <ctime>

// Structure pour représenter un produit
struct Produit {
    int id;
    std::string nom;
    double prix;
    std::string categorie;
};

// Structure pour représenter le stock d'un produit
struct Stock {
    int idProduit;
    int quantite;
};

// Structure pour représenter une transaction
struct Transaction {
    enum Type { ENTREE, SORTIE };

    int id;
    int idProduit;
    Type type;
    int quantite;
    time_t date;
    std::string description;
};

// Structure pour gérer l'inventaire complet
struct Inventaire {
    std::vector<Produit> produits;
    std::vector<Stock> stocks;
    std::vector<Transaction> transactions;
    int dernierIdTransaction;

    // Initialisation
    Inventaire() : dernierIdTransaction(0) {}

    // Méthodes pour gérer les produits
    void ajouterProduit(const Produit& produit) {
        produits.push_back(produit);

        // Initialiser le stock à zéro
        Stock nouveauStock = {produit.id, 0};
        stocks.push_back(nouveauStock);

        std::cout << "Produit '" << produit.nom << "' ajouté avec l'ID " << produit.id << std::endl;
    }

    // Trouver un produit par ID
    Produit* trouverProduit(int id) {
        for (auto& produit : produits) {
            if (produit.id == id) {
                return &produit;
            }
        }
        return nullptr;
    }

    // Trouver un stock par ID du produit
    Stock* trouverStock(int idProduit) {
        for (auto& stock : stocks) {
            if (stock.idProduit == idProduit) {
                return &stock;
            }
        }
        return nullptr;
    }

    // Ajouter des produits au stock
    bool ajouterAuStock(int idProduit, int quantite, const std::string& description) {
        if (quantite <= 0) {
            std::cout << "La quantité doit être positive." << std::endl;
            return false;
        }

        Stock* stock = trouverStock(idProduit);
        if (!stock) {
            std::cout << "Produit avec ID " << idProduit << " non trouvé." << std::endl;
            return false;
        }

        // Mettre à jour le stock
        stock->quantite += quantite;

        // Enregistrer la transaction
        enregistrerTransaction(idProduit, Transaction::ENTREE, quantite, description);

        std::cout << quantite << " unités ajoutées au stock du produit ID " << idProduit << std::endl;
        return true;
    }

    // Retirer des produits du stock
    bool retirerDuStock(int idProduit, int quantite, const std::string& description) {
        if (quantite <= 0) {
            std::cout << "La quantité doit être positive." << std::endl;
            return false;
        }

        Stock* stock = trouverStock(idProduit);
        if (!stock) {
            std::cout << "Produit avec ID " << idProduit << " non trouvé." << std::endl;
            return false;
        }

        if (stock->quantite < quantite) {
            std::cout << "Stock insuffisant. Disponible: " << stock->quantite << std::endl;
            return false;
        }

        // Mettre à jour le stock
        stock->quantite -= quantite;

        // Enregistrer la transaction
        enregistrerTransaction(idProduit, Transaction::SORTIE, quantite, description);

        std::cout << quantite << " unités retirées du stock du produit ID " << idProduit << std::endl;
        return true;
    }

    // Enregistrer une transaction
    void enregistrerTransaction(int idProduit, Transaction::Type type, int quantite, const std::string& description) {
        Transaction transaction;
        transaction.id = ++dernierIdTransaction;
        transaction.idProduit = idProduit;
        transaction.type = type;
        transaction.quantite = quantite;
        transaction.date = time(nullptr);
        transaction.description = description;

        transactions.push_back(transaction);
    }

    // Générer un rapport d'inventaire
    void genererRapport() const {
        std::cout << "\nRAPPORT D'INVENTAIRE" << std::endl;
        std::cout << "===================" << std::endl;

        std::cout << std::left << std::setw(5) << "ID"
                  << std::setw(20) << "Produit"
                  << std::setw(10) << "Prix"
                  << std::setw(15) << "Catégorie"
                  << std::setw(10) << "Stock" << std::endl;

        std::cout << std::string(60, '-') << std::endl;

        for (const auto& produit : produits) {
            // Trouver le stock correspondant
            int quantite = 0;
            for (const auto& stock : stocks) {
                if (stock.idProduit == produit.id) {
                    quantite = stock.quantite;
                    break;
                }
            }

            std::cout << std::left << std::setw(5) << produit.id
                      << std::setw(20) << produit.nom
                      << std::setw(10) << std::fixed << std::setprecision(2) << produit.prix
                      << std::setw(15) << produit.categorie
                      << std::setw(10) << quantite << std::endl;
        }

        std::cout << "\nDERNIÈRES TRANSACTIONS" << std::endl;
        std::cout << "====================" << std::endl;

        if (transactions.empty()) {
            std::cout << "Aucune transaction enregistrée." << std::endl;
            return;
        }

        std::cout << std::left << std::setw(5) << "ID"
                  << std::setw(10) << "Produit"
                  << std::setw(10) << "Type"
                  << std::setw(10) << "Quantité"
                  << std::setw(25) << "Description" << std::endl;

        std::cout << std::string(60, '-') << std::endl;

        // Afficher les 5 dernières transactions (ou moins s'il y en a moins)
        size_t start = transactions.size() > 5 ? transactions.size() - 5 : 0;
        for (size_t i = start; i < transactions.size(); ++i) {
            const auto& transaction = transactions[i];
            std::string type = transaction.type == Transaction::ENTREE ? "Entrée" : "Sortie";

            // Trouver le nom du produit
            std::string nomProduit = "Inconnu";
            for (const auto& produit : produits) {
                if (produit.id == transaction.idProduit) {
                    nomProduit = produit.nom;
                    break;
                }
            }

            std::cout << std::left << std::setw(5) << transaction.id
                      << std::setw(10) << nomProduit.substr(0, 7) + (nomProduit.length() > 7 ? "..." : "")
                      << std::setw(10) << type
                      << std::setw(10) << transaction.quantite
                      << std::setw(25) << transaction.description.substr(0, 22) + (transaction.description.length() > 22 ? "..." : "") << std::endl;
        }
    }
};

int main() {
    Inventaire inventaire;

    // Ajout de quelques produits
    inventaire.ajouterProduit({1, "Ordinateur portable", 999.99, "Électronique"});
    inventaire.ajouterProduit({2, "Smartphone", 599.99, "Électronique"});
    inventaire.ajouterProduit({3, "Livre C++", 49.99, "Livres"});

    // Ajout de stock
    inventaire.ajouterAuStock(1, 10, "Livraison initiale");
    inventaire.ajouterAuStock(2, 20, "Livraison initiale");
    inventaire.ajouterAuStock(3, 50, "Livraison initiale");

    // Quelques transactions
    inventaire.retirerDuStock(1, 2, "Vente client");
    inventaire.retirerDuStock(3, 5, "Vente en ligne");
    inventaire.ajouterAuStock(2, 5, "Retour fournisseur");

    // Générer le rapport
    inventaire.genererRapport();

    return 0;
}
