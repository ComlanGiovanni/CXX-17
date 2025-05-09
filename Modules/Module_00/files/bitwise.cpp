#include <iostream>
#include <bitset>  // Pour l'affichage binaire

int main() {
    unsigned int a = 60;  // 00111100 en binaire
    unsigned int b = 13;  // 00001101 en binaire

    std::cout << "a = " << a << " (" << std::bitset<8>(a) << " en binaire)" << std::endl;
    std::cout << "b = " << b << " (" << std::bitset<8>(b) << " en binaire)" << std::endl;

    // Opérateurs bit à bit
    std::cout << "\nOpérateurs bit à bit:" << std::endl;

    // AND
    unsigned int resultAND = a & b;
    std::cout << "a & b = " << resultAND << " (" << std::bitset<8>(resultAND) << " en binaire)" << std::endl;

    // OR
    unsigned int resultOR = a | b;
    std::cout << "a | b = " << resultOR << " (" << std::bitset<8>(resultOR) << " en binaire)" << std::endl;

    // XOR
    unsigned int resultXOR = a ^ b;
    std::cout << "a ^ b = " << resultXOR << " (" << std::bitset<8>(resultXOR) << " en binaire)" << std::endl;

    // NOT
    unsigned int resultNOT_A = ~a;
    std::cout << "~a = " << resultNOT_A << " (" << std::bitset<8>(resultNOT_A) << " en binaire)" << std::endl;

    // Décalage à gauche
    unsigned int resultLeftShift = a << 2;
    std::cout << "a << 2 = " << resultLeftShift << " (" << std::bitset<8>(resultLeftShift) << " en binaire)" << std::endl;

    // Décalage à droite
    unsigned int resultRightShift = a >> 2;
    std::cout << "a >> 2 = " << resultRightShift << " (" << std::bitset<8>(resultRightShift) << " en binaire)" << std::endl;

    return 0;
}
