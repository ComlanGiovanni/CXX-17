#include <iostream> // for std::cout endl;
#include <climits>  // Pour INT_MIN, INT_MAX
#include <iomanip>  // Pour std::setw
#include <string>  // Pour les chaînes de style C++

int main(void)
{

	std::string ft_my_string_one = "hello";
	std::string ft_my_string_two = "world";

	std::cout << "ft_my_string_one : " << ft_my_string_one << " " << ft_my_string_one.length() << std::endl;
	std::cout << "ft_my_string_two : " << ft_my_string_two << " " << ft_my_string_two.length() << std::endl;

	std::cout << "ft_my_string_one_plus_two : " << ft_my_string_one + ", " + ft_my_string_two << std::endl;

	if (ft_my_string_one == "hello")
		std::cout << "hello my friend" << std::endl;

	std::cout << "looking for : " << ft_my_string_one.substr(2, 3) << std::endl;
	std::cout << "ll pos : " << ft_my_string_one.find("ll") << std::endl;

	size_t pos = ft_my_string_two.find("world");
	if (pos != std::string::npos) {
		std::cout << "Position de 'World': " << pos << std::endl;
	}

	std::cout << ft_my_string_two.replace(ft_my_string_two.find("rl"), 2, "RR");
	std::cout << ft_my_string_two.insert(4,"pppppppppppppp");

	std::cout << ft_my_string_one.c_str();

	std::cout << "------------------------------------------------------" << std::endl;
	std::cout << "------------------------------------------------------" << std::endl;
	std::cout << "------------------------------------------------------" << std::endl;

	std::cout << "Hexadécimal: 0x" << std::hex << 42 << std::endl;
	std::cout << "Octal: 0" << std::oct << 42 << std::endl;

	std::cout << std::dec; // pour reinitiliser en base 10
	double pi = 3.14159265359;
	std::cout << "\nAffichage avec différentes précisions:" << std::endl;
    std::cout << "Pi (valeur par défaut): " << pi << std::endl;
    std::cout << "Pi (2 décimales): " << std::fixed << std::setprecision(2) << pi << std::endl;
    std::cout << "Pi (5 décimales): " << std::fixed << std::setprecision(5) << pi << std::endl;
    std::cout << "Pi (10 décimales): " << std::fixed << std::setprecision(10) << pi << std::endl;

	// Réinitialisation du formatage
    std::cout.unsetf(std::ios::fixed);
    std::cout << std::setprecision(6);  // Valeur par défaut

    // Formatage de nombres avec séparateurs
    double grandNombre = 1234567.89;
    std::cout << "\nFormatage de grands nombres:" << std::endl;
    std::cout << "Nombre sans formatage: " << grandNombre << std::endl;
    std::cout << "Nombre avec formatage: " << std::fixed << std::setprecision(2);


    std::string nombreStr = std::to_string(static_cast<long long>(grandNombre));
    std::string partieEntiere;
    for (size_t i = 0; i < nombreStr.length(); i++) {
        partieEntiere += nombreStr[i];
        if ((nombreStr.length() - i - 1) % 3 == 0 && i != nombreStr.length() - 1) {
            partieEntiere += " ";  // Espace comme séparateur de milliers
        }
    }
    std::cout << partieEntiere << ".89" << std::endl;

	//static_cast bitset NOT ~ std::cin int number(42);
	//double distance{2.5}; #include <bitset> #include <climits>
	//switch(note){case 1: std::cout << "lol" << std::endl; break; default: std << break; }

	//for (/**/;/**/;/**/)
	//for(int index = 0; index <= 10; index++)
	//for(j = 0; j <= 10; j++)
	//	int jindex = 1;
	// do
	// {
	// 	std::cout << "do while" << std::endl;
	// 	jindex++;
	// }while (jindex >= 3);
	//object cout of namespace std
	// can surcharge with type and number of parameter

	// // Démonstration de la durée de vie
	// std::cout << "\nDémonstration de la durée de vie des variables:" << std::endl;
	// {
	// 	int variableTemporaire = 100;
	// 	std::cout << "variableTemporaire créée avec la valeur " << variableTemporaire << std::endl;
	// }
	// static inside a function
	// g_global
	//int tableau[] = {8, 4, 12, 16, 5, 9, 7, 11};
	//int taille = sizeof(tableau) / sizeof(tableau[0]); n elemtn of 4 octet
	//std::setw(4) set wigth
	//std::cin.clear();  // Réinitialise l'état du flux
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Vide le tampon
	//std::getline(std::cin, nom);
	return (EXIT_SUCCESS);
}
