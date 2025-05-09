/*
 * Exercice 6.2: Passage Constant et Non Constant
 *
 * Ce programme démontre l'utilisation des paramètres constants et non constants,
 * et illustre les erreurs de compilation qui se produisent lors de modifications
 * de valeurs constantes.
 */

#include <iostream>
#include <string>
#include <vector>

class Document {
private:
    std::string titre;
    std::vector<std::string> paragraphes;
    bool modifie;

public:
    // Constructeur
    Document(const std::string& t) : titre(t), modifie(false) {}

    // Ajouter un paragraphe (méthode qui modifie l'objet)
    void ajouterParagraphe(const std::string& texte) {
        paragraphes.push_back(texte);
        modifie = true;
    }

    // Obtenir le titre (méthode qui ne modifie pas l'objet)
    const std::string& getTitre() const {
        return titre;
    }

    // Marquer comme sauvegardé (méthode qui modifie l'objet)
    void marquerCommeSauvegarde() {
        modifie = false;
    }

    // Vérifier si modifié (méthode qui ne modifie pas l'objet)
    bool estModifie() const {
        return modifie;
    }

    // Obtenir le nombre de paragraphes (méthode qui ne modifie pas l'objet)
    size_t getNombreParagraphes() const {
        return paragraphes.size();
    }

    // Obtenir un paragraphe par index (version constante - ne modifie pas l'objet)
    const std::string& getParagraphe(size_t index) const {
        if (index >= paragraphes.size()) {
            throw std::out_of_range("Index de paragraphe invalide");
        }
        return paragraphes[index];
    }

    // Obtenir un paragraphe par index (version non constante - permet la modification)
    std::string& getParagraphe(size_t index) {
        if (index >= paragraphes.size()) {
            throw std::out_of_range("Index de paragraphe invalide");
        }
        modifie = true; // Marquer comme modifié car on donne un accès mutable
        return paragraphes[index];
    }
};

// Fonction qui accepte un document par référence constante (lecture seule)
void afficherDocument(const Document& doc) {
    std::cout << "Document: " << doc.getTitre() << std::endl;
    std::cout << "Nombre de paragraphes: " << doc.getNombreParagraphes() << std::endl;

    for (size_t i = 0; i < doc.getNombreParagraphes(); i++) {
        std::cout << "Paragraphe " << (i + 1) << ": " << doc.getParagraphe(i) << std::endl;
    }

    std::cout << "État: " << (doc.estModifie() ? "Modifié" : "Non modifié") << std::endl;

    // Les lignes suivantes génèreraient des erreurs de compilation
    // car on ne peut pas modifier un objet constant:

    // doc.ajouterParagraphe("Nouveau paragraphe");  // Erreur: appelle une méthode non-const
    // doc.marquerCommeSauvegarde();                // Erreur: appelle une méthode non-const
    // doc.getParagraphe(0) = "Texte modifié";      // Erreur: version non-const inaccessible
}

// Fonction qui accepte un document par référence non constante (permet modification)
void modifierDocument(Document& doc) {
    std::cout << "Modification du document: " << doc.getTitre() << std::endl;

    // Ces opérations sont autorisées car le document n'est pas constant
    doc.ajouterParagraphe("Nouveau paragraphe ajouté par la fonction modifierDocument");

    if (doc.getNombreParagraphes() > 1) {
        doc.getParagraphe(0) = "Premier paragraphe modifié";
    }
}

int main() {
    // Créer un document
    Document doc("Mon Document");
    doc.ajouterParagraphe("Premier paragraphe");
    doc.ajouterParagraphe("Deuxième paragraphe");

    // Afficher le document initial (lecture seule)
    std::cout << "--- Document initial ---" << std::endl;
    afficherDocument(doc);

    // Modifier le document
    std::cout << "\n--- Modification du document ---" << std::endl;
    modifierDocument(doc);

    // Afficher le document après modification
    std::cout << "\n--- Document après modification ---" << std::endl;
    afficherDocument(doc);

    // Démonstration de surcharge basée sur const
    std::cout << "\n--- Démonstration de surcharge avec const ---" << std::endl;

    // Version const (sans modification)
    const Document& docConst = doc;
    std::cout << "Accès via référence constante: " << docConst.getParagraphe(0) << std::endl;

    // Version non-const (avec modification possible)
    Document& docNonConst = doc;
    std::string& paragrapheModifiable = docNonConst.getParagraphe(0);
    std::cout << "Avant modification via référence non constante: " << paragrapheModifiable << std::endl;
    paragrapheModifiable = "Paragraphe modifié à nouveau";
    std::cout << "Après modification via référence non constante: " << docNonConst.getParagraphe(0) << std::endl;

    // Vérifier l'état modifié
    std::cout << "État du document: " << (doc.estModifie() ? "Modifié" : "Non modifié") << std::endl;

    // Marquer comme sauvegardé
    doc.marquerCommeSauvegarde();
    std::cout << "Après sauvegarde - État du document: " << (doc.estModifie() ? "Modifié" : "Non modifié") << std::endl;

    std::cout << "\n--- Conclusions ---" << std::endl;
    std::cout << "1. Utilisez 'const Type&' pour les paramètres que vous ne modifiez pas:" << std::endl;
    std::cout << "   - Empêche les modifications accidentelles" << std::endl;
    std::cout << "   - Permet de passer des objets constants et non constants" << std::endl;
    std::cout << "   - Améliore la lisibilité et la sécurité du code" << std::endl;

    std::cout << "2. Utilisez 'Type&' pour les paramètres que vous devez modifier:" << std::endl;
    std::cout << "   - Rend explicite l'intention de modifier l'objet" << std::endl;
    std::cout << "   - Plus efficace qu'un passage par valeur pour les grands objets" << std::endl;

    std::cout << "3. Marquez les méthodes de classe qui ne modifient pas l'objet avec 'const':" << std::endl;
    std::cout << "   - Permet d'appeler ces méthodes sur des objets constants" << std::endl;
    std::cout << "   - Documente le comportement de la méthode" << std::endl;

    return 0;
}
