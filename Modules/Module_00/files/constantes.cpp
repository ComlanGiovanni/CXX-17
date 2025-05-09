#include <iostream>

int main() {
    // Constantes littérales
    std::cout << "Constantes littérales:" << std::endl;
    std::cout << "Entier: " << 42 << std::endl;
    std::cout << "Réel: " << 3.14159 << std::endl;
    std::cout << "Caractère: " << 'A' << std::endl;
    std::cout << "Chaîne: " << "Hello" << std::endl;

    // Variables constantes
    const int MAX_USERS = 100;
    const double PI = 3.14159265359;
    const char NEWLINE = '\n';

    std::cout << "\nVariables constantes:" << std::endl;
    std::cout << "MAX_USERS: " << MAX_USERS << std::endl;
    std::cout << "PI: " << PI << std::endl;
    std::cout << "NEWLINE: " << NEWLINE << "Après nouvelle ligne" << std::endl;

    // Expressions constantes avec constexpr
    constexpr int ARRAY_SIZE = 10;
    constexpr double LIGHT_SPEED = 299792458.0;
    constexpr int SQUARE_OF_FIVE = 5 * 5;

    std::cout << "\nExpressions constantes (constexpr):" << std::endl;
    std::cout << "ARRAY_SIZE: " << ARRAY_SIZE << std::endl;
    std::cout << "LIGHT_SPEED: " << LIGHT_SPEED << " m/s" << std::endl;
    std::cout << "SQUARE_OF_FIVE: " << SQUARE_OF_FIVE << std::endl;

    return 0;
}
