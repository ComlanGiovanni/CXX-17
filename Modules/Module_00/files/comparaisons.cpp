#include <iostream>

int main() {
    int a = 10;
    int b = 20;

    std::cout << "a = " << a << ", b = " << b << std::endl;

    // Opérateurs de comparaison
    std::cout << "\nOpérateurs de comparaison:" << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;

    // Opérateurs logiques
    bool condition1 = (a > 5);  // true
    bool condition2 = (b < 15); // false

    std::cout << "\nOpérateurs logiques:" << std::endl;
    std::cout << "condition1 (a > 5): " << condition1 << std::endl;
    std::cout << "condition2 (b < 15): " << condition2 << std::endl;

    std::cout << "condition1 && condition2: " << (condition1 && condition2) << std::endl;
    std::cout << "condition1 || condition2: " << (condition1 || condition2) << std::endl;
    std::cout << "!condition1: " << (!condition1) << std::endl;
    std::cout << "!condition2: " << (!condition2) << std::endl;

    // Expressions composées
    std::cout << "\nExpressions composées:" << std::endl;
    std::cout << "(a > 5) && (b > 15): " << ((a > 5) && (b > 15)) << std::endl;
    std::cout << "(a > 5) || (b > 15): " << ((a > 5) || (b > 15)) << std::endl;
    std::cout << "!(a > 5) || !(b > 15): " << (!(a > 5) || !(b > 15)) << std::endl;
    std::cout << "((a + b) > 25) && ((b - a) < 15): " << (((a + b) > 25) && ((b - a) < 15)) << std::endl;

    return 0;
}
