/*
 * Projet Mini: Éditeur de Texte Simple
 *
 * Ce programme implémente un éditeur de texte en ligne de commande
 * qui combine plusieurs concepts du module 1 (structures de données,
 * gestion de mémoire, passage de paramètres, etc.)
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <memory>

// Structure représentant une action pour l'historique (undo/redo)
struct Action {
    enum Type { AJOUT, SUPPRESSION, MODIFICATION };

    Type type;
    size_t ligne;
    std::string contenuPrecedent;
    std::string contenuNouveau;

    Action(Type t, size_t l, const std::string& ancien, const std::string& nouveau)
        : type(t), ligne(l), contenuPrecedent(ancien), contenuNouveau(nouveau) {}
};

// Classe principale de l'éditeur de texte
class EditeurTexte {
private:
    std::vector<std::string> lignes;  // Contenu du texte
    std::string nomFichier;          // Nom du fichier ouvert
    bool modifie;                    // Flag indiquant si le texte a été modifié

    // Historique pour undo/redo
    std::vector<Action> historique;
    size_t positionHistorique;

    // Statistiques
    struct Stats {
        size_t nombreLignes;
        size_t nombreMots;
        size_t nombreCaracteres;
    };

public:
    // Constructeur
    EditeurTexte() : modifie(false), positionHistorique(0) {}

    // Ouvrir un fichier
    bool ouvrirFichier(const std::string& fichier) {
        std::ifstream flux(fichier);
        if (!flux) {
            return false;
        }

        // Vider le contenu actuel
        lignes.clear();
        historique.clear();
        positionHistorique = 0;

        // Lire le fichier ligne par ligne
        std::string ligne;
        while (std::getline(flux, ligne)) {
            lignes.push_back(ligne);
        }

        nomFichier = fichier;
        modifie = false;
        return true;
    }

    // Sauvegarder le fichier
    bool sauvegarderFichier(const std::string& fichier = "") {
        std::string nomFichierSauvegarde = fichier.empty() ? nomFichier : fichier;
        if (nomFichierSauvegarde.empty()) {
            return false;
        }

        std::ofstream flux(nomFichierSauvegarde);
        if (!flux) {
            return false;
        }

        // Écrire chaque ligne dans le fichier
        for (const auto& ligne : lignes) {
            flux << ligne << std::endl;
        }

        if (fichier.empty() || fichier == nomFichier) {
            modifie = false;
        }

        if (!fichier.empty() && fichier != nomFichier) {
            nomFichier = fichier;
        }

        return true;
    }

    // Créer un nouveau document
    void nouveauDocument() {
        lignes.clear();
        historique.clear();
        positionHistorique = 0;
        nomFichier.clear();
        modifie = false;
    }

    // Ajouter une ligne à une position donnée
    void ajouterLigne(size_t position, const std::string& texte) {
        if (position > lignes.size()) {
            position = lignes.size(); // Ajouter à la fin si hors limites
        }

        // Enregistrer l'action dans l'historique
        Action action(Action::AJOUT, position, "", texte);
        ajouterHistorique(action);

        // Ajouter la ligne
        lignes.insert(lignes.begin() + position, texte);
        modifie = true;
    }

    // Supprimer une ligne
    bool supprimerLigne(size_t position) {
        if (position >= lignes.size()) {
            return false;
        }

        // Enregistrer l'action dans l'historique
        Action action(Action::SUPPRESSION, position, lignes[position], "");
        ajouterHistorique(action);

        // Supprimer la ligne
        lignes.erase(lignes.begin() + position);
        modifie = true;
        return true;
    }

    // Modifier une ligne
    bool modifierLigne(size_t position, const std::string& texte) {
        if (position >= lignes.size()) {
            return false;
        }

        // Enregistrer l'action dans l'historique
        Action action(Action::MODIFICATION, position, lignes[position], texte);
        ajouterHistorique(action);

        // Modifier la ligne
        lignes[position] = texte;
        modifie = true;
        return true;
    }

    // Rechercher du texte
    std::vector<size_t> rechercher(const std::string& texte) const {
        std::vector<size_t> resultats;

        for (size_t i = 0; i < lignes.size(); ++i) {
            if (lignes[i].find(texte) != std::string::npos) {
                resultats.push_back(i);
            }
        }

        return resultats;
    }

    // Remplacer du texte
    int remplacerTexte(const std::string& recherche, const std::string& remplacement) {
        int compteur = 0;

        for (size_t i = 0; i < lignes.size(); ++i) {
            std::string& ligne = lignes[i];

            size_t pos = 0;
            bool modifiee = false;
            std::string lignePrecedente = ligne;

            while ((pos = ligne.find(recherche, pos)) != std::string::npos) {
                ligne.replace(pos, recherche.length(), remplacement);
                pos += remplacement.length();
                compteur++;
                modifiee = true;
            }

            if (modifiee) {
                // Enregistrer l'action dans l'historique
                Action action(Action::MODIFICATION, i, lignePrecedente, ligne);
                ajouterHistorique(action);
                modifie = true;
            }
        }

        return compteur;
    }

    // Calculer les statistiques du texte
    Stats calculerStatistiques() const {
        Stats stats = {0, 0, 0};

        stats.nombreLignes = lignes.size();

        for (const auto& ligne : lignes) {
            stats.nombreCaracteres += ligne.length();

            // Compter les mots (séparés par des espaces)
            std::istringstream iss(ligne);
            std::string mot;
            while (iss >> mot) {
                stats.nombreMots++;
            }
        }

        return stats;
    }

    // Annuler la dernière action (undo)
    bool annuler() {
        if (positionHistorique == 0) {
            return false;  // Rien à annuler
        }

        positionHistorique--;
        const Action& action = historique[positionHistorique];

        switch (action.type) {
            case Action::AJOUT:
                lignes.erase(lignes.begin() + action.ligne);
                break;

            case Action::SUPPRESSION:
                lignes.insert(lignes.begin() + action.ligne, action.contenuPrecedent);
                break;

            case Action::MODIFICATION:
                lignes[action.ligne] = action.contenuPrecedent;
                break;
        }

        modifie = true;
        return true;
    }

    // Refaire la dernière action annulée (redo)
    bool refaire() {
        if (positionHistorique >= historique.size()) {
            return false;  // Rien à refaire
        }

        const Action& action = historique[positionHistorique];

        switch (action.type) {
            case Action::AJOUT:
                lignes.insert(lignes.begin() + action.ligne, action.contenuNouveau);
                break;

            case Action::SUPPRESSION:
                lignes.erase(lignes.begin() + action.ligne);
                break;

            case Action::MODIFICATION:
                lignes[action.ligne] = action.contenuNouveau;
                break;
        }

        positionHistorique++;
        modifie = true;
        return true;
    }

    // Afficher le contenu
    void afficherContenu(size_t debut = 0, size_t fin = std::numeric_limits<size_t>::max()) const {
        if (lignes.empty()) {
            std::cout << "<Document vide>" << std::endl;
            return;
        }

        if (fin > lignes.size() - 1) {
            fin = lignes.size() - 1;
        }

        for (size_t i = debut; i <= fin; ++i) {
            std::cout << i + 1 << ": " << lignes[i] << std::endl;
        }
    }

    // Accesseurs
    size_t getNombreLignes() const { return lignes.size(); }
    std::string getNomFichier() const { return nomFichier; }
    bool estModifie() const { return modifie; }

private:
    // Ajouter une action à l'historique
    void ajouterHistorique(const Action& action) {
        // Si nous avons annulé des actions et ajoutons une nouvelle action,
        // nous devons supprimer tout l'historique après la position actuelle
        if (positionHistorique < historique.size()) {
            historique.resize(positionHistorique);
        }

        historique.push_back(action);
        positionHistorique++;
    }
};

// Interface utilisateur en ligne de commande
class InterfaceConsole {
private:
    EditeurTexte editeur;
    bool continuer;

public:
    InterfaceConsole() : continuer(true) {}

    // Démarrer l'interface
    void demarrer() {
        afficherAide();

        while (continuer) {
            std::string commande;
            std::cout << "> ";
            std::getline(std::cin, commande);
            traiterCommande(commande);
        }
    }

private:
    // Afficher l'aide
    void afficherAide() const {
        std::cout << "Éditeur de Texte Simple - Commandes disponibles:" << std::endl;
        std::cout << "  nouveau                 - Créer un nouveau document" << std::endl;
        std::cout << "  ouvrir <fichier>        - Ouvrir un fichier" << std::endl;
        std::cout << "  sauvegarder [fichier]   - Sauvegarder le document" << std::endl;
        std::cout << "  ajouter <texte>         - Ajouter une ligne à la fin" << std::endl;
        std::cout << "  inserer <numero> <texte> - Insérer une ligne à une position donnée" << std::endl;
        std::cout << "  modifier <numero> <texte> - Modifier une ligne" << std::endl;
        std::cout << "  supprimer <numero>      - Supprimer une ligne" << std::endl;
        std::cout << "  afficher [debut] [fin]  - Afficher le contenu" << std::endl;
        std::cout << "  rechercher <texte>      - Rechercher du texte" << std::endl;
        std::cout << "  remplacer <ancien> <nouveau> - Remplacer du texte" << std::endl;
        std::cout << "  stats                   - Afficher les statistiques" << std::endl;
        std::cout << "  annuler                 - Annuler la dernière action" << std::endl;
        std::cout << "  refaire                 - Refaire la dernière action annulée" << std::endl;
        std::cout << "  aide                    - Afficher cette aide" << std::endl;
        std::cout << "  quitter                 - Quitter l'éditeur" << std::endl;
    }

    // Traiter une commande
    void traiterCommande(const std::string& commande) {
        std::istringstream iss(commande);
        std::string operation;

        iss >> operation;

        if (operation == "nouveau") {
            editeur.nouveauDocument();
            std::cout << "Nouveau document créé." << std::endl;
        }
        else if (operation == "ouvrir") {
            std::string fichier;
            iss >> fichier;

            if (fichier.empty()) {
                std::cout << "Syntaxe: ouvrir <fichier>" << std::endl;
                return;
            }

            if (editeur.ouvrirFichier(fichier)) {
                std::cout << "Fichier ouvert: " << fichier << std::endl;
            } else {
                std::cout << "Impossible d'ouvrir le fichier: " << fichier << std::endl;
            }
        }
        else if (operation == "sauvegarder") {
            std::string fichier;
            iss >> fichier;

            if (editeur.sauvegarderFichier(fichier)) {
                std::cout << "Document sauvegardé dans: " <<
                    (fichier.empty() ? editeur.getNomFichier() : fichier) << std::endl;
            } else {
                std::cout << "Erreur lors de la sauvegarde." << std::endl;
            }
        }
        else if (operation == "ajouter") {
            std::string texte;
            std::getline(iss >> std::ws, texte);

            editeur.ajouterLigne(editeur.getNombreLignes(), texte);
            std::cout << "Ligne ajoutée à la fin." << std::endl;
        }
        else if (operation == "inserer") {
            size_t position;
            std::string texte;

            if (!(iss >> position)) {
                std::cout << "Syntaxe: inserer <numero> <texte>" << std::endl;
                return;
            }

            std::getline(iss >> std::ws, texte);

            if (position > 0) position--; // Convertir numéro affiché (1-based) en index (0-based)
            editeur.ajouterLigne(position, texte);
            std::cout << "Ligne insérée à la position " << position + 1 << "." << std::endl;
        }
        else if (operation == "modifier") {
            size_t position;
            std::string texte;

            if (!(iss >> position)) {
                std::cout << "Syntaxe: modifier <numero> <texte>" << std::endl;
                return;
            }

            std::getline(iss >> std::ws, texte);

            if (position > 0) position--; // Convertir numéro affiché en index
            if (editeur.modifierLigne(position, texte)) {
                std::cout << "Ligne " << position + 1 << " modifiée." << std::endl;
            } else {
                std::cout << "Numéro de ligne invalide." << std::endl;
            }
        }
        else if (operation == "supprimer") {
            size_t position;

            if (!(iss >> position)) {
                std::cout << "Syntaxe: supprimer <numero>" << std::endl;
                return;
            }

            if (position > 0) position--; // Convertir numéro affiché en index
            if (editeur.supprimerLigne(position)) {
                std::cout << "Ligne " << position + 1 << " supprimée." << std::endl;
            } else {
                std::cout << "Numéro de ligne invalide." << std::endl;
            }
        }
        else if (operation == "afficher") {
            size_t debut = 0, fin = std::numeric_limits<size_t>::max();

            iss >> debut;
            iss >> fin;

            if (debut > 0) debut--; // Convertir numéro affiché en index
            if (fin > 0) fin--; // Convertir numéro affiché en index

            editeur.afficherContenu(debut, fin);
        }
        else if (operation == "rechercher") {
            std::string texte;
            std::getline(iss >> std::ws, texte);

            if (texte.empty()) {
                std::cout << "Syntaxe: rechercher <texte>" << std::endl;
                return;
            }

            auto resultats = editeur.rechercher(texte);

            if (resultats.empty()) {
                std::cout << "Aucune occurrence trouvée." << std::endl;
            } else {
                std::cout << resultats.size() << " occurrence(s) trouvée(s) aux lignes: ";
                for (size_t i = 0; i < resultats.size(); ++i) {
                    std::cout << resultats[i] + 1;
                    if (i < resultats.size() - 1) {
                        std::cout << ", ";
                    }
                }
                std::cout << std::endl;
            }
        }
        else if (operation == "remplacer") {
            std::string recherche, remplacement;

            iss >> recherche >> remplacement;

            if (recherche.empty() || remplacement.empty()) {
                std::cout << "Syntaxe: remplacer <ancien> <nouveau>" << std::endl;
                return;
            }

            int nbRemplacements = editeur.remplacerTexte(recherche, remplacement);
            std::cout << nbRemplacements << " remplacement(s) effectué(s)." << std::endl;
        }
        else if (operation == "stats") {
            auto stats = editeur.calculerStatistiques();
            std::cout << "Statistiques du document:" << std::endl;
            std::cout << "- Nombre de lignes: " << stats.nombreLignes << std::endl;
            std::cout << "- Nombre de mots: " << stats.nombreMots << std::endl;
            std::cout << "- Nombre de caractères: " << stats.nombreCaracteres << std::endl;
        }
        else if (operation == "annuler") {
            if (editeur.annuler()) {
                std::cout << "Action annulée." << std::endl;
            } else {
                std::cout << "Aucune action à annuler." << std::endl;
            }
        }
        else if (operation == "refaire") {
            if (editeur.refaire()) {
                std::cout << "Action refaite." << std::endl;
            } else {
                std::cout << "Aucune action à refaire." << std::endl;
            }
        }
        else if (operation == "aide") {
            afficherAide();
        }
        else if (operation == "quitter") {
            if (editeur.estModifie()) {
                std::cout << "Document modifié. Sauvegarder avant de quitter? (o/n): ";
                std::string reponse;
                std::getline(std::cin, reponse);

                if (reponse == "o" || reponse == "O") {
                    std::string fichier = editeur.getNomFichier();
                    if (fichier.empty()) {
                        std::cout << "Nom du fichier: ";
                        std::getline(std::cin, fichier);
                    }

                    if (!fichier.empty()) {
                        editeur.sauvegarderFichier(fichier);
                        std::cout << "Document sauvegardé dans: " << fichier << std::endl;
                    }
                }
            }

            continuer = false;
            std::cout << "Au revoir!" << std::endl;
        }
        else {
            std::cout << "Commande inconnue. Tapez 'aide' pour la liste des commandes." << std::endl;
        }
    }
};

int main() {
    std::cout << "=== Éditeur de Texte Simple ===" << std::endl;

    InterfaceConsole interface;
    interface.demarrer();

    return 0;
}
