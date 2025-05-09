#include <iostream>
#include <string>

// Énumération classique pour les jours de la semaine
enum Jour {
    LUNDI,
    MARDI,
    MERCREDI,
    JEUDI,
    VENDREDI,
    SAMEDI,
    DIMANCHE
};

// Énumération fortement typée pour les mois de l'année
enum class Mois {
    JANVIER,
    FEVRIER,
    MARS,
    AVRIL,
    MAI,
    JUIN,
    JUILLET,
    AOUT,
    SEPTEMBRE,
    OCTOBRE,
    NOVEMBRE,
    DECEMBRE
};

// Fonction pour convertir un jour en chaîne de caractères
std::string jourToString(Jour jour) {
    switch (jour) {
        case LUNDI:     return "Lundi";
        case MARDI:     return "Mardi";
        case MERCREDI:  return "Mercredi";
        case JEUDI:     return "Jeudi";
        case VENDREDI:  return "Vendredi";
        case SAMEDI:    return "Samedi";
        case DIMANCHE:  return "Dimanche";
        default:        return "Jour inconnu";
    }
}

// Fonction pour convertir un mois en chaîne de caractères
std::string moisToString(Mois mois) {
    switch (mois) {
        case Mois::JANVIER:    return "Janvier";
        case Mois::FEVRIER:    return "Février";
        case Mois::MARS:       return "Mars";
        case Mois::AVRIL:      return "Avril";
        case Mois::MAI:        return "Mai";
        case Mois::JUIN:       return "Juin";
        case Mois::JUILLET:    return "Juillet";
        case Mois::AOUT:       return "Août";
        case Mois::SEPTEMBRE:  return "Septembre";
        case Mois::OCTOBRE:    return "Octobre";
        case Mois::NOVEMBRE:   return "Novembre";
        case Mois::DECEMBRE:   return "Décembre";
        default:               return "Mois inconnu";
    }
}

// Fonction qui retourne un message selon le jour
std::string messageDuJour(Jour jour) {
    switch (jour) {
        case LUNDI:
            return "Début de semaine, courage!";
        case MARDI:
        case MERCREDI:
        case JEUDI:
            return "Semaine en cours, continuez vos efforts!";
        case VENDREDI:
            return "Bientôt le week-end!";
        case SAMEDI:
        case DIMANCHE:
            return "Bon week-end!";
        default:
            return "Jour non reconnu.";
    }
}

// Fonction qui retourne la saison selon le mois
std::string saisonDuMois(Mois mois) {
    switch (mois) {
        case Mois::DECEMBRE:
        case Mois::JANVIER:
        case Mois::FEVRIER:
            return "Hiver";

        case Mois::MARS:
        case Mois::AVRIL:
        case Mois::MAI:
            return "Printemps";

        case Mois::JUIN:
        case Mois::JUILLET:
        case Mois::AOUT:
            return "Été";

        case Mois::SEPTEMBRE:
        case Mois::OCTOBRE:
        case Mois::NOVEMBRE:
            return "Automne";

        default:
            return "Saison inconnue";
    }
}

int main() {
    std::cout << "Démonstration des énumérations en C++" << std::endl;
    std::cout << "----------------------------------" << std::endl;

    // Utilisation de l'énumération classique
    std::cout << "\n1. Énumération classique (Jour):" << std::endl;

    Jour j1 = LUNDI;
    Jour j2 = SAMEDI;

    std::cout << "j1 = " << jourToString(j1) << std::endl;
    std::cout << "j2 = " << jourToString(j2) << std::endl;

    // Conversion implicite avec une énumération classique
    int jourValue = j1;  // Fonctionne car conversion implicite permise
    std::cout << "Valeur numérique de j1: " << jourValue << std::endl;

    // On peut également faire des comparaisons directes avec des entiers
    if (j1 < 3) {
        std::cout << j1 << " est inférieur à 3" << std::endl;
    }

    // Utilisation de l'énumération fortement typée
    std::cout << "\n2. Énumération fortement typée (Mois):" << std::endl;

    Mois m1 = Mois::JANVIER;
    Mois m2 = Mois::JUILLET;

    std::cout << "m1 = " << moisToString(m1) << std::endl;
    std::cout << "m2 = " << moisToString(m2) << std::endl;

    // Avec enum class, la conversion implicite n'est pas permise
    // int moisValue = m1;  // Erreur de compilation

    // Conversion explicite nécessaire
    int moisValue = static_cast<int>(m1);
    std::cout << "Valeur numérique de m1: " << moisValue << std::endl;

    // Comparaison directe avec des entiers impossible
    // if (m1 < 3) {  // Erreur de compilation
    //     std::cout << "m1 est inférieur à 3" << std::endl;
    // }

    // Mais on peut comparer avec d'autres valeurs de l'énumération
    if (m1 < Mois::FEVRIER) {
        std::cout << moisToString(m1) << " vient avant " << moisToString(Mois::FEVRIER) << std::endl;
    }

    // Utilisation dans un switch
    std::cout << "\n3. Utilisation dans un switch:" << std::endl;

    std::cout << "Message pour " << jourToString(j1) << ": " << messageDuJour(j1) << std::endl;
    std::cout << "Message pour " << jourToString(j2) << ": " << messageDuJour(j2) << std::endl;

    std::cout << "Saison pour " << moisToString(m1) << ": " << saisonDuMois(m1) << std::endl;
    std::cout << "Saison pour " << moisToString(m2) << ": " << saisonDuMois(m2) << std::endl;

    return 0;
}
