#include <iostream>

int main() {
    // Création d'un tableau d'entiers
    int tableau[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int taille = sizeof(tableau) / sizeof(tableau[0]);

    std::cout << "Tableau original:" << std::endl;
    for (int i = 0; i < taille; ++i) {
        std::cout << tableau[i] << " ";
    }
    std::cout << std::endl << std::endl;

    // Utilisation d'un pointeur pour parcourir le tableau
    std::cout << "Parcours avec un pointeur:" << std::endl;
    int* ptr = tableau;  // ptr pointe vers le premier élément

    std::cout << "Adresse de début du tableau: " << ptr << std::endl;
    std::cout << "Contenu du tableau:" << std::endl;

    for (int i = 0; i < taille; ++i) {
        std::cout << "tableau[" << i << "] = " << *ptr << " (adresse: " << ptr << ")" << std::endl;
        ptr++;  // Avancer à l'élément suivant
    }

    // Démonstration de l'arithmétique des pointeurs
    std::cout << "\nDémonstration de l'arithmétique des pointeurs:" << std::endl;
    ptr = tableau;  // Réinitialiser le pointeur au début du tableau

    std::cout << "ptr = tableau   : *ptr = " << *ptr << std::endl;

    // Avancer le pointeur
    ptr++;
    std::cout << "Après ptr++    : *ptr = " << *ptr << std::endl;

    // Avancer de 2 positions
    ptr += 2;
    std::cout << "Après ptr += 2 : *ptr = " << *ptr << std::endl;

    // Reculer de 1 position
    ptr--;
    std::cout << "Après ptr--    : *ptr = " << *ptr << std::endl;

    // Accès avec un décalage sans modifier le pointeur
    std::cout << "ptr[2]         : " << ptr[2] << " (équivalent à *(ptr + 2))" << std::endl;

    // Calcul de différence entre pointeurs
    int* debut = tableau;
    int* fin = &tableau[taille - 1];

    std::cout << "\nDifférence entre pointeurs:" << std::endl;
    std::cout << "Adresse du premier élément : " << debut << std::endl;
    std::cout << "Adresse du dernier élément : " << fin << std::endl;
    std::cout << "Différence (en éléments)   : " << fin - debut << std::endl;

    return 0;
}
