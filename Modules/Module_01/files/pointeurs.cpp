#include <iostream>

int main() {
    // Déclaration de variables de différents types
    int x = 10;
    double y = 3.14159;
    char z = 'A';

    // Création de pointeurs vers ces variables
    int* ptr_x = &x;
    double* ptr_y = &y;
    char* ptr_z = &z;

    // Affichage des adresses et valeurs originales
    std::cout << "Valeurs et adresses originales:" << std::endl;
    std::cout << "----------------------------" << std::endl;

    std::cout << "Variable: x, Valeur: " << x << ", Adresse: " << &x << std::endl;
    std::cout << "Pointeur: ptr_x, Adresse pointée: " << ptr_x << ", Valeur pointée: " << *ptr_x << std::endl;
    std::cout << std::endl;

    std::cout << "Variable: y, Valeur: " << y << ", Adresse: " << &y << std::endl;
    std::cout << "Pointeur: ptr_y, Adresse pointée: " << ptr_y << ", Valeur pointée: " << *ptr_y << std::endl;
    std::cout << std::endl;

    std::cout << "Variable: z, Valeur: " << z << ", Adresse: " << static_cast<void*>(&z) << std::endl;
    std::cout << "Pointeur: ptr_z, Adresse pointée: " << static_cast<void*>(ptr_z) << ", Valeur pointée: " << *ptr_z << std::endl;

    // Modification des valeurs via les pointeurs
    *ptr_x = 20;
    *ptr_y = 2.71828;
    *ptr_z = 'B';

    // Affichage des valeurs modifiées
    std::cout << "\nValeurs après modification via les pointeurs:" << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    std::cout << "Variable: x = " << x << std::endl;
    std::cout << "Variable: y = " << y << std::endl;
    std::cout << "Variable: z = " << z << std::endl;

    return 0;
}
